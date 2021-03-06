#define RKAnalyzer_cxx
#include "../interface/RKAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
using namespace std;
void RKAnalyzer::Loop(TString output){
  bool debug=false;
  std::cout<<" output = "<<output<<std::endl;
  
  if(debug) std::cout<<" creating output file"<<std::endl;
  f = new TFile(output,"RECREATE");
  
  jetvalidator.GetInputs(f,"Jet_NoCut_");
  jetvalidator_selected.GetInputs(f,"Jet_PtEtaBTag_");
  metvalidator.GetInputs(f,"MET_NoCut_");
  diJetValidator.GetInputs(f,"DiJetNotCut");
  jetmetValidator.GetInputs(f,"JetMETNoCuts");
  dijetmetValidator.GetInputs(f,"DiJetMETNoCuts");
  cutflowobj.GetInputs(f,"CutFlowAndEachCut");
  nminusobj.GetInputs(f,"NMinusOne");
  histfac.GetInputs(f,"MonoH");
  abcd.GetInputs(f,"MonoH");
  if(debug) std::cout<<" Sending information to JetValidator "<<std::endl;
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     std::cout<<" ------------------- event number -----------------: = "<<jentry<<std::endl;
     // Clear all the collections
     ClearCollections();
     
     // Produce jet collection for analysis and validation of object variables.
     JetProducer();
     // Produce MET collection for analysis and validation of object.
     // this contain all raw PFMET, corrected PFMET and MVA PFMET.
     METProducer();
     MuonProducer();
     ElectronProducer();
     if(debug) std::cout<<" Jet collecttion produced "<<std::endl;
     // Fill Validation Histograms for Jets
     jetvalidator.Fill(RKJetCollection);
     jetvalidator_selected.Fill(RKJetCollection_selected);
     
     // Fill Validation histograms for MET
     metvalidator.Fill(met);
     
     // Dijet 
     std::cout<<" calling dijet maker "<<std::endl;
     RKdiJetCollection = dijet.ReconstructDiObject(RKJetCollection);
     std::cout<< " dijet collection size = ========== "<<RKdiJetCollection.size()<<std::endl;

     // DiJet Validation
     if(debug) std::cout<<" diJet mass = "<<RKdiJetCollection[0].ResonanceProp.p4.Mag()<<std::endl;
     diJetValidator.Fill(RKdiJetCollection);
     std::cout<<" dijet part done "<<std::endl;

     // Dijet Vector Sorting wrt pT of diJet candidate 
     std::sort(RKdiJetCollection.begin(), RKdiJetCollection.end(), DiJetpTSorting() );
     
     // Jet-MET
     RKjetMETCollection = jet_met.ReconstructDiObject(RKJetCollection_selected,met);
     if(RKjetMETCollection.size()>0) std::cout<<" transverse mass = "<<RKjetMETCollection[0].TransverseObjProp.TransMass <<std::endl;
     jetmetValidator.Fill(RKjetMETCollection);
     
     //DiJet-MET
     RKDiJetMETCollection = dijet_met.ReconstructDiObject(RKdiJetCollection,met);
     std::cout<<" size of DIJETMET collection is = "<<RKDiJetMETCollection.size()<<std::endl;
     
     // add electron to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].electrons = RKElectronCollection ;
     
     // add muon to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].muons = RKMuonCollection ;
     if(RKDiJetMETCollection.size()>0) std::cout<<" ----------------- muon size = "<<RKDiJetMETCollection[0].muons.size()<<std::endl;
     
     // add jets to the RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].jets  = RKJetCollection ;
     
     // add selection bits for baseline Analysis.
     RKDiJetMETCollectionWithStatus = selectionbits.SelectionBitsSaver(RKDiJetMETCollection, cuts.cutValueMap);
     
     // add selection bits for ttbar control region 
     RKDiJetMETCollectionTTBar = selectionbits.SelectionBitsSaver(RKDiJetMETCollection,cuts.cutValueMap);
     
     
     // --------------------------------//
     // ---------- Histograms -----------//
     // --------------------------------//
     // fill histograms for di-jet + met vaiables. very basic and common variables.
     dijetmetValidator.Fill(RKDiJetMETCollectionWithStatus,1); // Fill only one dijet+Met combo
     
     // fill histograms for di-jet + met vaiables. Mono-H Specific histograms. 
     histfac.Fill(RKDiJetMETCollectionWithStatus,1);
     
     if( RKDiJetMETCollectionWithStatus.size()>0)     std::cout<<" cut status main = "<<RKDiJetMETCollectionWithStatus[0].cutsStatus<<std::endl;
     
     std::cout<<" calling cutFlow "<<std::endl;
     cutflowobj.CutFlow(RKDiJetMETCollectionWithStatus);
     
     std::cout<<" calling nminus one"<<std::endl;
     nminusobj.Fill(RKDiJetMETCollectionWithStatus);
     
     std::cout<<" calling ABCD method "<<std::endl;
     abcd.Fill(RKDiJetMETCollectionWithStatus);
     if(debug) std::cout<<" pfMetCorrPt = "<<pfMetCorrPt
			<<" pfMetCorrPhi = "<<pfMetCorrPhi
			<<" pfMetCorrSumEt = "<<pfMetCorrSumEt
			<<" pfMetCorrSig = "<<pfMetCorrSig
			 <<" pfMetRawPt = "<<pfMetRawPt
			<<" pfMetRawPhi = "<<pfMetRawPhi
			<<" pfMetRawSumEt = "<<pfMetRawSumEt
			<<" pfmvaMetPt_ = "<<pfmvaMetPt_
			<<" pfmvaMetPhi_ = "<<pfmvaMetPhi_
			<<" pfmvaMetSumEt_ = "<<pfmvaMetSumEt_
			<<" pfmvaMetSig_ = "<<pfmvaMetSig_
			 <<" pfMetRawCov00 " <<pfMetRawCov00
			<<" pfMetRawCov01 = "<<pfMetRawCov01
			<<" pfMetRawCov10 = "<<pfMetRawCov10
			<<std::endl;     // if (Cut(ientry) < 0) continue;
   }
   
   // Write Histograms ;
   jetvalidator.Write();
   jetvalidator_selected.Write();
   metvalidator.Write();
   diJetValidator.Write();
   jetmetValidator.Write();
   dijetmetValidator.Write();
   cutflowobj.Write();
   nminusobj.Write();
   histfac.Write();
   abcd.Write();
}




void RKAnalyzer::JetProducer(){
  
  for(Int_t i=0;i<AK5nJet;i++){
    jets.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiE( (*AK5jetPt)[i],
			  (*AK5jetEta)[i],
			  (*AK5jetPhi)[i],
			  (*AK5jetEn)[i]);
    
    jets.nJets                          = AK5nJet;
    jets.p4                             = fourmom;
    jets.charge                         = (*AK5jetCharge)[i];
    jets.partonFlavor                   = (*AK5jetPartonFlavor)[i];
    jets.B_SSV                          = (*AK5jetSSV)[i];
    jets.B_CSV                          = (*AK5jetCSV)[i];
    jets.B_SSVHE                        = (*AK5jetSSVHE)[i];
    jets.B_CISVV2                       = (*AK5jetCISVV2)[i];
    jets.B_TCHP                         = (*AK5jetTCHP)[i];
    jets.B_TCHE                         = (*AK5jetTCHE)[i];
    jets.B_JP                           = (*AK5jetJP)[i];
    jets.B_JBP                          = (*AK5jetJBP)[i];
    jets.tau1                           = (*AK5jetTau1)[i];
    jets.tau2                           = (*AK5jetTau2)[i];
    jets.tau3                           = (*AK5jetTau3)[i];
    jets.jetMuEF                        = (*AK5jetMuEF)[i];
    jets.jetPhoEF                       = (*AK5jetPhoEF)[i];
    jets.jetCEmEF                       = (*AK5jetCEmEF)[i];
    jets.jetCHadEF                      = (*AK5jetCHadEF)[i];
    jets.jetNEmEF                       = (*AK5jetNEmEF)[i];
    jets.jetNHadEF                      = (*AK5jetNHadEF)[i];
    jets.jetCMulti                      = (*AK5jetCMulti)[i];
    jets.jetHFHadEF                     = (*AK5jetHFHadEF)[i];
    jets.jetHFEMEF                      = (*AK5jetHFEMEF)[i];
    jets.jetCHHadMultiplicity           = (*AK5jetCHHadMultiplicity)[i];
    jets.jetNHadMulplicity              = (*AK5jetNHadMulplicity)[i];
    jets.jetPhMultiplicity              = (*AK5jetPhMultiplicity)[i];
    jets.jetEleMultiplicity             = (*AK5jetEleMultiplicity)[i];
    jets.jetHFHadMultiplicity           = (*AK5jetHFHadMultiplicity)[i];
    jets.jetHFEMMultiplicity            = (*AK5jetHFEMMultiplicity)[i];
    jets.jetChMuEF                      = (*AK5jetChMuEF)[i];
    jets.jetNMultiplicity               = (*AK5jetNMultiplicity)[i];
    jets.jetHOEnergy                    = (*AK5jetHOEnergy)[i];
    jets.jetHOEF                        = (*AK5jetHOEF)[i];
    RKJetCollection_selected.push_back(jets);
    if(fabs(fourmom.Eta())<2.5 && jets.B_CISVV2 > 0.423 && fourmom.Pt() > 30. ) RKJetCollection.push_back(jets);

  }
}


void RKAnalyzer::METProducer(){
  met.CorrPt = pfMetCorrPt;
  met.CorrPhi = pfMetCorrPhi;
  met.CorrSumEt = pfMetCorrSumEt;
  met.CorrSig = pfMetCorrSig;
  met.RawPt = pfMetRawPt;
  met.RawPhi = pfMetRawPhi;
  met.RawSumEt = pfMetRawSumEt;
  met.RawCov00 = pfMetRawCov00;
  met.RawCov01 = pfMetRawCov01;
  met.RawCov10 = pfMetRawCov10;
  met.RawCov11 = pfMetRawCov11;
  met.mvaPt = pfmvaMetPt_;
  met.mvaPhi = pfmvaMetPhi_;
  met.mvaSumEt = pfmvaMetSumEt_;
  met.mvaSig = pfmvaMetSig_;

}

void RKAnalyzer::MuonProducer(){
  for(size_t i=0; i<nMu; i++){
    muons.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiM((*muPt)[i], 
			 (*muEta)[i], 
			 (*muPhi)[i], 
			 (*muM)[i] );
    muons.p4      = fourmom ;
    muons.charge  = (*muCharge)[i] ;
    if(fourmom.Pt() > 20 && fabs(fourmom.Eta())<2.4 ) RKMuonCollection.push_back(muons);
  }
}

void RKAnalyzer::ElectronProducer(){
  for(size_t i=0; i<nEle; i++){
    electrons.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiM((*elePt)[i], 
			 (*eleEta)[i], 
			 (*elePhi)[i], 
			 (*eleEnergy)[i] );
    electrons.p4      = fourmom ;
    //electrons.charge  = (*eleCharge)[i] ;
    if(fourmom.Pt() > 20 && fabs(fourmom.Eta())<2.5 )  RKElectronCollection.push_back(electrons);
  }
}



void RKAnalyzer::ClearCollections(){
  RKJetCollection.clear();
  RKJetCollection_selected.clear();
  RKMuonCollection.clear();
  RKElectronCollection.clear();
  RKdiJetCollection.clear();
  RKjetMETCollection.clear();
  RKDiJetMETCollection.clear();
  RKDiJetMETCollectionWithStatus.clear();
  RKDiJetMETCollectionTTBar.clear();
}
