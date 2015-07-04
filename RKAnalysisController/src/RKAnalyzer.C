#define RKAnalyzer_cxx
#include "../interface/RKAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TUrl.h>
using namespace std;
void RKAnalyzer::Loop(TString output){
  bool debug=false;
  std::cout<<" output = "<<output<<std::endl;
  //nEvents = dynamic_cast<TH1F*> (f->Get("allEventsCounter/totalEvents"));
  
  if(debug) std::cout<<" creating output file"<<std::endl;
  fout = new TFile(output,"RECREATE");
  //fout->cd();
  //nEvents->Write();

  
  jetvalidator.GetInputs(fout,"Jet_NoCut_");
  jetvalidator_selected.GetInputs(fout,"Jet_PtEtaBTag_");
  metvalidator.GetInputs(fout,"MET_NoCut_");
  diJetValidator.GetInputs(fout,"DiJetNotCut");
  jetmetValidator.GetInputs(fout,"JetMETNoCuts");
  dijetmetValidator.GetInputs(fout,"DiJetMETNoCuts");
  cutflowobj.GetInputs(fout,"CutFlowAndEachCut");
  nminusobj.GetInputs(fout,"NMinusOne");
  histfac.GetInputs(fout,"PreSelection");
  abcd.GetInputs(fout,"ABCD");
  
  if(debug) std::cout<<" Sending information to JetValidator "<<std::endl;
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  std::cout<<" nevents ====== "<<nentries<<std::endl;
  //nentries = 10;
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
     RKdiJetCollection = dijet.ReconstructDiObject(RKJetCollection_selected);
     std::cout<< " dijet collection size = ========== "<<RKdiJetCollection.size()<<std::endl;

     // DiJet Validation
     if(debug) std::cout<<" diJet mass = "<<RKdiJetCollection[0].ResonanceProp.p4.Mag()<<std::endl;
     diJetValidator.Fill(RKdiJetCollection);
     std::cout<<" dijet part done "<<std::endl;
     
     
     std::cout<<" before sorting "<<std::endl;
     // Dijet Vector Sorting wrt pT of diJet candidate 
     for(size_t idj=0; idj<RKdiJetCollection.size();idj++){
       std::cout<<" mass = "<<RKdiJetCollection[idj].ResonanceProp.p4.Pt()
		<<std::endl;;
     }
     std::sort(RKdiJetCollection.begin(), RKdiJetCollection.end(), DiJetpTSorting() );
     std::cout<<" after sorting "<<std::endl;
      
     
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
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].jets  = RKJetCollection_selected ;
     
     // add selection bits for baseline Analysis.
     RKDiJetMETCollectionWithStatus = selectionbits.SelectionBitsSaver(RKDiJetMETCollection, cuts.cutValueMap);
     
     // add selection bits for ttbar control region 
     RKDiJetMETCollectionTTBar = selectionbits.SelectionBitsSaver(RKDiJetMETCollection,cuts.cutValueMapTTBar);
     
     
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
  
  std::cout<<" inside JetProducer "<<THINnJet<<std::endl;
  for(Int_t i=0;i<THINnJet;i++){
    jets.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiE( (*THINjetPt)[i],
			  (*THINjetEta)[i],
			  (*THINjetPhi)[i],
			  (*THINjetEn)[i]);
    
    jets.nJets                          = THINnJet;
    jets.p4                             = fourmom;
    jets.charge                         = (*THINjetCharge)[i];
    jets.partonFlavor                   = (*THINjetPartonFlavor)[i];
    jets.B_SSV                          = (*THINjetSSV)[i];
    jets.B_CSV                          = (*THINjetCSV)[i];
    jets.B_SSVHE                        = (*THINjetSSVHE)[i];
    jets.B_CISVV2                       = (*THINjetCISVV2)[i];
    jets.B_TCHP                         = (*THINjetTCHP)[i];
    jets.B_TCHE                         = (*THINjetTCHE)[i];
    jets.B_JP                           = (*THINjetJP)[i];
    jets.B_JBP                          = (*THINjetJBP)[i];
    jets.tau1                           = (*THINjetTau1)[i];
    jets.tau2                           = (*THINjetTau2)[i];
    jets.tau3                           = (*THINjetTau3)[i];
    jets.jetMuEF                        = (*THINjetMuEF)[i];
    jets.jetPhoEF                       = (*THINjetPhoEF)[i];
    jets.jetCEmEF                       = (*THINjetCEmEF)[i];
    jets.jetCHadEF                      = (*THINjetCHadEF)[i];
    jets.jetNEmEF                       = (*THINjetNEmEF)[i];
    jets.jetNHadEF                      = (*THINjetNHadEF)[i];
    jets.jetCMulti                      = (*THINjetCMulti)[i];

    
    // not in NCU Global tuple right now
    /*
      jets.jetHFHadEF                     = (*THINjetHFHadEF)[i];
    jets.jetHFEMEF                      = (*THINjetHFEMEF)[i];
    jets.jetCHHadMultiplicity           = (*THINjetCHHadMultiplicity)[i];
    jets.jetNHadMulplicity              = (*THINjetNHadMulplicity)[i];
    jets.jetPhMultiplicity              = (*THINjetPhMultiplicity)[i];
    jets.jetEleMultiplicity             = (*THINjetEleMultiplicity)[i];
    jets.jetHFHadMultiplicity           = (*THINjetHFHadMultiplicity)[i];
    jets.jetHFEMMultiplicity            = (*THINjetHFEMMultiplicity)[i];
    jets.jetChMuEF                      = (*THINjetChMuEF)[i];
    jets.jetNMultiplicity               = (*THINjetNMultiplicity)[i];
    jets.jetHOEnergy                    = (*THINjetHOEnergy)[i];
    jets.jetHOEF                        = (*THINjetHOEF)[i];
    */
    RKJetCollection.push_back(jets);
    if(fabs(fourmom.Eta())<2.5 && jets.B_CISVV2 > 0.432 && fourmom.Pt() > 30. && RKJetCollection.size()<4 )     RKJetCollection_selected.push_back(jets);
    //if(fabs(fourmom.Eta())<2.5 && jets.B_CISVV2 > 0.2 && fourmom.Pt() > 30. )     RKJetCollection.push_back(jets);

  }
}


void RKAnalyzer::METProducer(){
  std::cout<<" inside MET Prodicer "<<std::endl;
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
  std::cout<< " inside muon producer "<<std::endl;
  for(size_t i=0; i<nMu; i++){
    muons.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiM((*muPt)[i], 
			 (*muEta)[i], 
			 (*muPhi)[i], 
			 (*muM)[i] );
    muons.p4      = fourmom ;
    muons.charge  = (*muCharge)[i] ;
    if(fourmom.Pt() > 20 && fabs(fourmom.Eta())<2.4 && (*isPFMuon)[i] == 1) RKMuonCollection.push_back(muons);
  }
}

void RKAnalyzer::ElectronProducer(){
  std::cout<< " inside electron producer "<<std::endl;
  for(size_t i=0; i<nEle; i++){
    electrons.Clear();
    //    if(nEle<1) continue;
    //    TLorentzVector fourmom;
    //std::cout<<" size = "<<patElecP4->IsEmpty()<<std::endl;
    //std::cout<<" before clone array "<<std::endl;
    TLorentzVector*  fourmom = (TLorentzVector*) patElecP4->At(i);
    //std::cout<<" after array = " <<std::endl;
    //TLorentzVector* fourmom = (TLorentzVector*) patElecP4->At(i); 
    //electrons.p4      = *fourmom ;
    //std::cout<<" ele pt = "<<fourmom->Pt()<<std::endl;
    //electrons.charge  = (*eleCharge)[i] ;
    if(fourmom->Pt() > 20 && fabs(fourmom->Eta())<2.5 && (*isPassVeto)[i]==1)  RKElectronCollection.push_back(electrons);
  }
  std::cout<<" electron collection filled " <<std::endl;
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


void RKAnalyzer::TotalEvent(std::vector<TString> FileList) {
  
  const int nfile=FileList.size();
  TFile* m_f[nfile];
  TH1F* dummyHist;
  TH1F* outHist;
  int ic=0;
  for (unsigned int iFile=0; iFile<FileList.size(); ++iFile)    {
    
    //TString name = "root://cmsxrootd.hep.wisc.edu/"+FileList[iFile];
    // Following is the trick to get the correct file name which can be used by farmoutAnalysis
    std::string name0 = "root:/";
    std::string name1 = "/cmsxrootd.hep.wisc.edu///";
    std::string name2 = (std::string) FileList[iFile];
    std::string name = name0 + name1 + name2;
    
    //TString name = "root:"+"/"+"/"+"cmsxrootd.hep.wisc.edu/"+"/"+FileList[iFile];
    std::cout<<" name = "<<name<<std::endl;
    std::cout<<" debug 1"<<iFile<<std::endl;
    m_f[iFile] = TFile::Open(name.c_str());
    std::cout<<" debug 2"<<iFile<<std::endl;
    //if(false){
    if(iFile==0){
      std::cout<<" debug 3"<<iFile<<std::endl;
      dummyHist = dynamic_cast<TH1F*> (m_f[iFile]->Get("allEventsCounter/totalEvents"));
      std::cout<<" debug 4"<<iFile<<std::endl;
      outHist = (TH1F*)dummyHist->Clone();
    }
    std::cout<<" debug 5"<<iFile<<std::endl;
    //if(false){
    if(iFile>0){
      dummyHist = dynamic_cast <TH1F*> (m_f[iFile]->Get("allEventsCounter/totalEvents"));
      std::cout<<" debug 6"<<iFile<<std::endl;
      outHist->Add(dummyHist);
      std::cout<<" debug 7"<<iFile<<std::endl;
    }
    
  }
  fout->cd();
  outHist->Write();
  
}
