#define RKAnalyzer_cxx
#include "../interface/RKAnalyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TUrl.h>
#include "../../RKUtilities/interface/EAElectron.h"
using namespace std;
void RKAnalyzer::Loop(TString output){
  bool debug=false;
  if(false) std::cout<<" output = "<<output<<std::endl;
  nEvents = new TH1F("nEvents","",2,0,2);
  //nEvents = dynamic_cast<TH1F*> (f->Get("allEventsCounter/totalEvents"));
  
  if(debug) std::cout<<" creating output file"<<std::endl;
  fout = new TFile(output,"RECREATE");
  //fout->cd();
  //nEvents->Write();


  // eaConstantsFile("EgammaAnalysis/ElectronTools/data/PHYS14/effAreaElectrons_cone03_pfNeuHadronsAndPhotons.txt");
  
  
  jetvalidator.GetInputs(fout,"Jet_NoCut_");
  jetvalidator_selected.GetInputs(fout,"Jet_PtEtaBTag_");
  electronvalidator.GetInputs(fout,"Electron_NoCut_");
  metvalidator.GetInputs(fout,"MET_NoCut_");
  diJetValidator.GetInputs(fout,"DiJetNotCut");
  diElectronValidator.GetInputs(fout,"DiElectronNoCut");
  jetmetValidator.GetInputs(fout,"JetMETNoCuts");
  dijetmetValidator.GetInputs(fout,"DiJetMETNoCuts");
  cutflowobj.GetInputs(fout,"CutFlowAndEachCut");
  nminusobj.GetInputs(fout,"NMinusOne");
  histfac.GetInputs(fout,"NoCut");
  histfacJetPreSel.GetInputs(fout,"JetPreSel");
  //histfacJetHardPreSel.GetInputs(fout,"JetHardPreSel");
  syncmonoh.GetInputs(fout,"syncSig");
  //abcd.GetInputs(fout,"ABCD");
  
  if(debug) std::cout<<" Sending information to JetValidator "<<std::endl;
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  if(false) std::cout<<" nevents ====== "<<nentries<<std::endl;
  //nentries = 1;
  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     nEvents->Fill(1);
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     if(!(info_lumiSection==2)) continue;
     if(!(info_eventId==108)) continue;
     events.run = info_runId;
     events.lumi = info_lumiSection;
     events.event = info_eventId;
     // Clear all the collections
     ClearCollections();
     
     //Trigger Status.
     bool eletrig1 = TriggerStatus("HLT_DoubleEle33");
     // Produce jet collection for analysis and validation of object variables.
     JetProducer();
     // Produce MET collection for analysis and validation of object.
     // this contain all raw PFMET, corrected PFMET and MVA PFMET.
     METProducer();
     MuonProducer();
     ElectronProducer();
     if(debug) std::cout<<" Jet collecttion produced "<<std::endl;
     // Fill Validation Histograms for Jets
     if(RKJetCollection.size()>0) jetvalidator.Fill(RKJetCollection);
     if(RKJetCollection_selected.size()>0) jetvalidator_selected.Fill(RKJetCollection_selected);
     
     // Fill the electron validation histograms 
     electronvalidator.Fill(RKElectronCollection);
     // Fill Validation histograms for MET
     metvalidator.Fill(met);
     
     // Dijet 
     // for validation 
     RKdiJetCollection_selected = dijet.ReconstructDiObject(RKJetCollection_selected);
     // For further processing 
     RKdiJetCollection = dijet.ReconstructDiObject(RKJetCollection);
     
     // DiElectron 
     RKdiElectronCollection = dielectron.ReconstructDiObject(RKElectronCollection);

     // DiJet Validation
     if(debug) std::cout<<" diJet mass = "<<RKdiJetCollection[0].ResonanceProp.p4.Mag()<<std::endl;
     if(RKdiJetCollection.size() > 0) diJetValidator.Fill(RKdiJetCollection_selected);
     if(debug) std::cout<<" dijet part done "<<std::endl;
     
     if(RKdiElectronCollection.size()>0)  diElectronValidator.Fill(RKdiElectronCollection);
     
     if(debug)      std::cout<<" before sorting "<<std::endl;
     // Dijet Vector Sorting wrt pT of diJet candidate 
     std::sort(RKdiJetCollection.begin(), RKdiJetCollection.end(), DiJetpTSorting() );
     if(debug) std::cout<<" after sorting "<<std::endl;
      
     
     // Jet-MET
     RKjetMETCollection = jet_met.ReconstructDiObject(RKJetCollection_selected,met);
     //     if(RKjetMETCollection.size()>0) std::cout<<" transverse mass = "<<RKjetMETCollection[0].TransverseObjProp.TransMass <<std::endl;
     jetmetValidator.Fill(RKjetMETCollection);
     
     //DiJet-MET
     RKDiJetMETCollection = dijet_met.ReconstructDiObject(RKdiJetCollection,met);
     if(debug) std::cout<<" size of DIJETMET collection is = "<<RKDiJetMETCollection.size()<<std::endl;
     
     // add electron to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].electrons = RKElectronCollection ;
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].events = events ;
     // add muon to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].muons = RKMuonCollection ;
     //if(RKDiJetMETCollection.size()>0) std::cout<<" ----------------- muon size = "<<RKDiJetMETCollection[0].muons.size()<<std::endl;
     
     // add jets to the RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].jets  = RKJetCollection_selected ;
     
     // add selection bits for baseline Analysis.
     RKDiJetMETCollectionWithStatus = selectionbits.SelectionBitsSaver(RKDiJetMETCollection, cuts.cutValueMap);
     
     // add selection bits for ttbar control region 
     RKDiJetMETCollectionTTBar = selectionbits.SelectionBitsSaver(RKDiJetMETCollection,cuts.cutValueMapTTBar);
     
     
     syncmonoh.Fill(RKDiJetMETCollectionWithStatus, RKJetCollection);
     // --------------------------------//
     // ---------- Histograms -----------//
     // --------------------------------//
     // fill histograms for di-jet + met vaiables. very basic and common variables.
     dijetmetValidator.Fill(RKDiJetMETCollectionWithStatus,1); // Fill only one dijet+Met combo
     
     // fill histograms for di-jet + met vaiables. Mono-H Specific histograms. 
     std::vector<int> bitVec; bitVec.clear();
     histfac.Fill(RKDiJetMETCollectionWithStatus,1, bitVec); // empty vector for no cuts
     // Following is pT,  Eta and CSV Loose
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); bitVec.push_back(3);
     histfacJetPreSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     bitVec.clear();
     // Call again with different bit pattern to measure efficiency. 
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); 
     bitVec.push_back(3); bitVec.push_back(4); bitVec.push_back(5); 
     bitVec.push_back(6); bitVec.push_back(7); // upto Mbb cut
     //histfacJetHardPreSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     bitVec.clear();
     
     //if( RKDiJetMETCollectionWithStatus.size()>0)     std::cout<<" cut status main = "<<RKDiJetMETCollectionWithStatus[0].cutsStatus<<std::endl;
     
     if(debug) std::cout<<" calling cutFlow "<<std::endl;
     cutflowobj.CutFlow(RKDiJetMETCollectionWithStatus);
     
     if(debug) std::cout<<" calling nminus one"<<std::endl;
     nminusobj.Fill(RKDiJetMETCollectionWithStatus);
     
     if(debug) std::cout<<" calling ABCD method "<<std::endl;
     //abcd.Fill(RKDiJetMETCollectionWithStatus);
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
   electronvalidator.Write();
   metvalidator.Write();
   diJetValidator.Write();
   diElectronValidator.Write();
   jetmetValidator.Write();
   dijetmetValidator.Write();
   cutflowobj.Write();
   nminusobj.Write();
   histfac.Write();
   histfacJetPreSel.Write();
   //histfacJetHardPreSel.Write();
   syncmonoh.Write();
   //abcd.Write();
   fout->cd();
   nEvents->Write();
}




void RKAnalyzer::JetProducer(){
  
  //std::cout<<" inside JetProducer "<<THINnJet<<std::endl;
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
    
    float pt  = (*THINjetPt )[i]                         ;
    float eta_ = (*THINjetEta)[i]                         ; 
    float csv = (*THINjetCISVV2)[i]                      ;
    jets.ispT30_         =   pt > 30.                         ;
    jets.ispT50_         =   pt > 50.                         ;
    jets.ispT80_         =   pt > 80.                         ;
    jets.ispT100_        =   pt > 100.                        ;
    jets.iseta25_        =   fabs(eta_) < 2.5                 ;
    jets.isCSVVL_        =   csv > 0.25                       ;//myself
    jets.isCSVL_         =   csv > 0.432                      ;
    jets.isCSVMed_       =   csv > 0.532                      ;// myself
    jets.isCSVT_         =   csv > 0.732                      ;

    // For loose Jet ID
    bool eta24    =  (fabs(eta_) < 2.5)
      && ((*THINjetNHadEF)[i] < 0.99)
      && ((*THINjetNEmEF)[i] < 0.99)
      && ((*THINjetMuEF)[i] < 0.8)
      && ((*THINjetCMulti)[i] > 0)
      && ((*THINjetCHadEF)[i] > 0.)
      && ((*THINjetCEmEF)[i] < 0.99);
    
    bool eta24_25 =  (fabs(eta_) > 2.4) && (fabs(eta_) < 2.5) && ((*THINjetNHadEF)[i] < 0.99) && ((*THINjetNEmEF)[i] < 0.99) && ((*THINjetMuEF)[i] < 0.8) && ((*THINjetCHadEF)[i] > 0.) && ((*THINjetCMulti)[i] > 0) && ((*THINjetCEmEF)[i] < 0.99) ;    

    jets.isLooseJet_     =  (*THINjetPassIDLoose)[i];
    
    jets.isPUJet_        = (*THINPUJetID)[i] > -0.63  ;
    jets.nVtx            = info_nVtx;
    //std::cout<<" ==============="<<info_nVtx<<std::endl;
    
    std::cout<<" run "<<info_runId
	     <<" lumi "<<info_lumiSection
	     <<" event "<<info_eventId
	     <<" ijet = "<<i
	     <<" pt "<<fourmom.Pt()
	     <<" eta "<<fourmom.Eta()
	     <<" phi "<<fourmom.Phi()
	     <<" lid "<<jets.isLooseJet_
	     <<" puid "<<jets.isPUJet_
	     <<" CHad "<<jets.jetCHadEF
	     <<" NHad "<<jets.jetNHadEF
	     <<" NEM "<<jets.jetNEmEF
	     <<" Mul "<<(*THINjetCMulti)[i]
	     <<std::endl;
    if(TMath::Abs(fourmom.Eta())<2.5  && fourmom.Pt() > 30. && jets.isPUJet_ && jets.isLooseJet_) RKJetCollection.push_back(jets);
    //if(fabs(fourmom.Eta())<2.5 && jets.B_CISVV2 > 0.432 && fourmom.Pt() > 30. && RKJetCollection.size()<4 )     RKJetCollection_selected.push_back(jets);
    if(fabs(fourmom.Eta())<2.5  && fourmom.Pt() > 30. && jets.isPUJet_ && jets.isLooseJet_)   RKJetCollection_selected.push_back(jets);
    //RKJetCollection_selected.push_back(jets);
    
  }
}


void RKAnalyzer::METProducer(){
  //std::cout<<" inside MET Prodicer "<<std::endl;
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
  //std::cout<< " inside muon producer "<<std::endl;
  for(size_t i=0; i<nMu; i++){
    muons.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiM((*muPt)[i], 
			 (*muEta)[i], 
			 (*muPhi)[i], 
			 (*muM)[i] );
    muons.p4      = fourmom ;
    muons.charge  = (*muCharge)[i] ;
    bool isloose = (*isPFMuon)[i] && ( (*isGlobalMuon)[i] ||(*isTrackerMuon)[i] );
    if(fourmom.Pt() > 10 && fabs(fourmom.Eta())<2.4 && isloose == 1) RKMuonCollection.push_back(muons);
  }
}



void RKAnalyzer::PhotonProducer(){
  //std::cout<< " inside photon producer "<<std::endl;
  for(size_t i=0; i<nPho; i++){
    photons.Clear();
    TLorentzVector fourmom;
    fourmom.SetPtEtaPhiE((*phoPt)[i], 
			 (*phoEta)[i], 
			 (*phoPhi)[i], 
			 (*phoE)[i] );
    photons.p4      = fourmom ;
    
    if(fourmom.Pt() > 15 && fabs(fourmom.Eta())<2.5 && (*phoisPassLoose)[i] == 1) RKPhotonCollection.push_back(photons);
  }
}


void RKAnalyzer::TauProducer(){
  //std::cout<<" inside tau producer "<<std::endl;

}
void RKAnalyzer::ElectronProducer(){

  //opening file for effective area 
  //  edm::FileInPath eaConstantsFile("EgammaAnalysis/ElectronTools/data/PHYS14/effAreaElectrons_cone03_pfNeuHadronsAndPhotons.txt");
  //EffectiveAreas effectiveAreas(eaConstantsFile.fullPath());


  if(false) std::cout<< " inside electron producer "<<nEle<<std::endl;
  for(size_t i=0; i<nEle; i++){
   
    if(false) std::cout<<" inside ele loop"<<std::endl;
    TLorentzVector*  fourmom = (TLorentzVector*) patElecP4->At(i);
    if(false) std::cout<<" after lorentzvec "<<std::endl;
    
    float eA =EAElectron::EA(fourmom->Eta());
    
    //float eA = effectiveAreas.getEffectiveArea(fabs((*eleScEta)[i])); // to get eArea of supercluster
    
    electrons.p4         = (*fourmom); 
    electrons.IsPassVeto  =  (*isPassVeto)[i]  ; 
    electrons.IsPassLoose  =  (*isPassLoose)[i]  ; 
    electrons.IsPassMedium  =  (*isPassMedium)[i]  ; 
    electrons.IsPassTight  =  (*isPassTight)[i]  ; 
    electrons.IsPassHEEP  =  (*isPassHEEP)[i]  ;  
    electrons.IsMVATrig  =  false  ;  //Add This
    electrons.IsMVANonTrig  =  -999  ;
    electrons.MVATrig  =  -999.;
    electrons.MVANonTrig  =  -999.  ;
    electrons.charge  =  (*eleCharge)[i]  ;
    electrons.r9  =  (*eleR9)[i]  ;
    electrons.etSC  =  (*eleScEt)[i]  ; //check this
    electrons.etaSC  =  (*eleScEta)[i]  ;
    electrons.energySC  =  (*eleScEn)[i]  ;
    electrons.preenergySC  =  (*eleScPreEn)[i]  ;
    electrons.phiSC  =  (*eleScPhi)[i]  ;
    electrons.dEtaIn  =  (*eledEtaAtVtx)[i]  ;
    electrons.dPhiIn  =  (*eledPhiAtVtx)[i]  ;
    electrons.hOverE  =  (*eleHoverE)[i]  ;
    electrons.full5x5_sigmaIetaIeta  =  (*eleSigmaIEtaIEtaFull5x5)[i]  ;
    electrons.eoverP  =  (*eleEoverP)[i]  ;
    electrons.eoverPInv  =  (*eleEoverPInv)[i]  ;
    electrons.brem  =  (*eleBrem)[i]  ;
    electrons.dEtaWidth  =  (*eleScEtaWidth)[i]  ;
    electrons.dPhiWidth  =  (*eleScPhiWidth)[i]  ;
    electrons.isoChargedHadrons  =  (*eleChHadIso)[i]  ;
    electrons.isoNeutralHadrons  =  (*eleNeHadIso)[i]  ;
    electrons.isoPhotons  =  (*eleGamIso)[i]  ;
    electrons.isoChargedFromPU  = (*elePUPt)[i]  ; //add in main code
    electrons.isoDeltaBeta  = ((*eleChHadIso)[i] + max<float>( 0.0, ((*eleNeHadIso)[i]+(*eleGamIso)[i]- 0.5 * (*elePUPt)[i])));
    electrons.isoRho  = ((*eleChHadIso)[i] + max<float>( 0.0, ((*eleNeHadIso)[i]+(*eleGamIso)[i]- (eleRho) * (eA)) ));
    //electrons.ooEmooP  =  -999.  ;
    //std::cout<<" electrons.ooEmooP "<<std::endl;
    electrons.d0  =  (*eleD0)[i]  ;     //fix it 
    electrons.dz  =  (*eleDz)[i]  ;
    electrons.expectedMissingInnerHits  =  (*eleMissHits)[i]  ;
    electrons.passConversionVeto  =  (*eleConvVeto)[i]  ;
    electrons.barrel  =  (*eleInBarrel)[i]  ; 
    electrons.endcap  =  (*eleInEndcap)[i]  ; 
    
    if(fourmom->Pt() > 10 && fabs(fourmom->Eta())<2.5 && (*isPassVeto)[i]==1)  RKElectronCollection.push_back(electrons);
  }
  
}



void RKAnalyzer::ClearCollections(){
  RKJetCollection.clear();
  RKJetCollection_selected.clear();
  RKMuonCollection.clear();
  RKElectronCollection.clear();
  RKPhotonCollection.clear();
  RKdiJetCollection.clear();
  RKdiJetCollection_selected.clear();
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
    
    m_f[iFile] = TFile::Open(name.c_str());
    //if(false){
    if(iFile==0){
      dummyHist = dynamic_cast<TH1F*> (m_f[iFile]->Get("allEventsCounter/totalEvents"));
      outHist = (TH1F*)dummyHist->Clone();
    }
    //if(false){
    if(iFile>0){
      dummyHist = dynamic_cast <TH1F*> (m_f[iFile]->Get("allEventsCounter/totalEvents"));
      outHist->Add(dummyHist);
    }
    
  }
  fout->cd();
  outHist->Write();
  
}


void RKAnalyzer::TotalEvent(TH1F* h){
  fout->cd();
  h->Write();

}




bool RKAnalyzer::TriggerStatus(std::string TRIGNAME){
  for(int i =0; i < (*hlt_trigResult).size() ; i++) {
      std::string trigname = (*trigName)[i];
      size_t foundEle00=trigname.find(TRIGNAME);//HLT_DoubleEle33
      if ( foundEle00==std::string::npos) continue;
  }
}	
    
	
