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
  nEvents_weight = new TH1F("nEvents_weight","",3,-1,2);
  
  if(debug) std::cout<<" creating output file"<<std::endl;
  fout = new TFile(output,"RECREATE");



  // eaConstantsFile("EgammaAnalysis/ElectronTools/data/PHYS14/effAreaElectrons_cone03_pfNeuHadronsAndPhotons.txt");
  
  
  jetvalidator.GetInputs(fout,"Jet_NoCut_");
  jetvalidator_selected.GetInputs(fout,"Jet_PtEtaBTag_");
  
  fatjetvalidator.GetInputs(fout,"FatJets");
  addjetvalidator.GetInputs(fout,"ADDJets");
  
  elenminusoneobjB.GetInputs(fout,"ElectronNMinus1B");
  elenminusoneobjE.GetInputs(fout,"ElectronNMinus1E");
  
  electronvalidator.GetInputs(fout,"Electron_NoCut_");
  electronvalidator_barrel.GetInputs(fout,"Electron_NoCut_Barrel_");
  electronvalidator_endcap.GetInputs(fout,"Electron_NoCut_Endcap_");
  
  metvalidator.GetInputs(fout,"MET_NoCut_");
  diJetValidator.GetInputs(fout,"DiJetNotCut");
  diJetValidator_selected.GetInputs(fout,"DiJetSelected");
  
  diElectronValidator.GetInputs(fout,"DiElectronMediumID");
  diElectronValidatorIso.GetInputs(fout,"DiElectronMediumIDIso");
  
  jetmetValidator.GetInputs(fout,"JetMETNoCuts");
  dijetmetValidator.GetInputs(fout,"DiJetMETNoCuts");
  cutflowobj.GetInputs(fout,"CutFlowAndEachCut");
  nminusobj.GetInputs(fout,"NMinusOne");
  histfac.GetInputs(fout,"MonoHNoCut");
  histfacJetPreSel.GetInputs(fout,"MonoHSoftSel");
  histfacJetHardPreSel.GetInputs(fout,"MonoHPreSel");
  histfacFullSel.GetInputs(fout,"MonoHFullSelection");
  //syncmonoh.GetInputs(fout,"syncSig");
  //abcd.GetInputs(fout,"ABCD");
  
  if(debug) std::cout<<" Sending information to JetValidator "<<std::endl;
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  std::cout<<" nevents ====== "<<nentries<<std::endl;
  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     nEvents->Fill(1);
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
     if( jentry%50 == 0) std::cout<<" ------------------- event number -----------------: = "<<jentry<<std::endl;
     
     
     bool met120 = TriggerStatus("HLT_PFMET120_PFMHT120_IDLoose_v");
     bool met170 = TriggerStatus("HLT_PFMET170_NoiseCleaned_v");
     triggerstatus = met120 || met170 ;

     // Clear all the collections
     ClearCollections();
     
     // Fill the event properties 
     EventProducer();
     nEvents_weight->Fill(1, events.mcweight);
     
     // Produce jet collection for analysis and validation of object variables.
     JetProducer();
     //FATJetProducer();
     //ADDJetProducer();
     
     // Produce MET collection for analysis and validation of object.
     // this contain all raw PFMET, corrected PFMET and MVA PFMET.
     METProducer();
     MuonProducer();
     ElectronProducer();
     
     // N-1 For Electron ID
     if(false) std::cout<<" N-1 for barrel with size "<<RKElectronCollection_barrel.size()<<std::endl;
     if(RKElectronCollection_barrel.size()>0) elenminusoneobjB.Fill(RKElectronCollection_barrel);
     if(false) std::cout<<" N-1 for endcap with size "<<RKElectronCollection_endcap.size()<<std::endl;
     if(RKElectronCollection_endcap.size()>0) elenminusoneobjE.Fill(RKElectronCollection_endcap);
     
     // Fill Validation Histograms for Jets

     if(false) std::cout<<" Jet Validator no sel"<<std::endl;
     if(RKJetCollection.size()>0) jetvalidator.Fill(RKJetCollection);
     if(false) std::cout<<" Jet Validator with sel"<<std::endl;
     if (RKJetCollection_selected.size()>0) jetvalidator_selected.Fill(RKJetCollection_selected);
     if (MH_FATJetCollection.size() > 0 ) fatjetvalidator.Fill(MH_FATJetCollection);
     if (MH_ADDJetCollection.size() > 0 ) addjetvalidator.Fill(MH_ADDJetCollection);
     
     
     if(false) std::cout<<" electron Validator no sel"<<std::endl;
     // Fill the electron validation histograms 
     if(RKElectronCollection.size()>0) electronvalidator.Fill(RKElectronCollection);
     if(false) std::cout<<" electron Validator no sel barrel with size "<<RKElectronCollection_barrel.size()<<std::endl;
     if(RKElectronCollection_barrel.size()>0) electronvalidator_barrel.Fill(RKElectronCollection_barrel);
     if(false) std::cout<<" electron Validator no sel endcap"<<RKElectronCollection_endcap.size()<<std::endl;
     if(RKElectronCollection_endcap.size()>0) electronvalidator_endcap.Fill(RKElectronCollection_endcap);
     // Fill Validation histograms for MET
     if(false) std::cout<<" MET Validator"<<std::endl;
     metvalidator.Fill(met);
     
     // Dijet 
     // for validation 
     if(RKJetCollection_selected.size()>0) RKdiJetCollection_selected = dijet_selected.ReconstructDiObject(RKJetCollection_selected);
     if(false) std::cout<<" made dijet selected "<<std::endl;
     // For further processing 

     if(RKJetCollection.size()>0) RKdiJetCollection = dijet.ReconstructDiObject(RKJetCollection);
     //RKdiJetCollection = RKdiJetCollection_selected;
     if(false) std::cout<< " dijet collection size = ========== "<<RKdiJetCollection.size()<<std::endl;


     // DiElectron 
     if(RKElectronCollection_allCutM.size()>0) RKdiElectronCollection = dielectron.ReconstructDiObject(RKElectronCollection_allCutM);
     if(RKElectronCollection_allCutMIso.size()>0) RKdiElectronCollectionIso = dielectron.ReconstructDiObject(RKElectronCollection_allCutMIso);

     // DiJet Validation
     if(RKdiJetCollection.size()>0) diJetValidator.Fill(RKdiJetCollection);
     if(RKdiJetCollection_selected.size() > 0) diJetValidator_selected.Fill(RKdiJetCollection_selected);
     
     
     // DiElectron Validation
     if(RKdiElectronCollection.size()>0)     diElectronValidator.Fill(RKdiElectronCollection);
     if(RKdiElectronCollectionIso.size()>0)  diElectronValidatorIso.Fill(RKdiElectronCollectionIso);
     
     // Dijet Vector Sorting wrt pT of diJet candidate 
     std::sort(RKdiJetCollection.begin(), RKdiJetCollection.end(), DiJetpTSorting() );
     if(debug) std::cout<<" after sorting "<<std::endl;
      
     
     // Jet-MET
     if(RKJetCollection_selected.size()>0) RKjetMETCollection = jet_met.ReconstructDiObject(RKJetCollection_selected,met);
     if(RKjetMETCollection.size()>0) std::cout<<" transverse mass = "<<RKjetMETCollection[0].TransverseObjProp.TransMass <<std::endl;
     if(RKjetMETCollection.size()>0) jetmetValidator.Fill(RKjetMETCollection);
     
     //DiJet-MET
     if(RKdiJetCollection.size()>0) RKDiJetMETCollection = dijet_met.ReconstructDiObject(RKdiJetCollection,met);
     if(false) std::cout<<" size of DIJETMET collection is = "<<RKDiJetMETCollection.size()<<std::endl;
     
     // add electron to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].electrons = RKElectronCollection ;
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].events = events ;
     // add muon to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].muons = RKMuonCollection ;
     //if(RKDiJetMETCollection.size()>0) std::cout<<" ----------------- muon size = "<<RKDiJetMETCollection[0].muons.size()<<std::endl;
     
     // add jets to the RKDiJetMETCollectionWithStatus
     // add with CSv Cuts
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].jets  = RKJetCollection_selected ;
     
     if(false) std::cout<<" objects added "<<std::endl;
     // add selection bits for baseline Analysis.
     if(RKDiJetMETCollection.size()>0)RKDiJetMETCollectionWithStatus = selectionbits.SelectionBitsSaver(RKDiJetMETCollection, cuts.cutValueMap);
     
     if(false) std::cout<<" added bits "<<std::endl;
     // add selection bits for ttbar control region 
     //if(RKDiJetMETCollection.size()>0) RKDiJetMETCollectionTTBar = selectionbits.SelectionBitsSaver(RKDiJetMETCollection,cuts.cutValueMapTTBar);
     
     
     // --------------------------------//
     // ---------- Histograms -----------//
     // --------------------------------//
     // fill histograms for di-jet + met vaiables. very basic and common variables.
     if(RKDiJetMETCollectionWithStatus.size()>0) dijetmetValidator.Fill(RKDiJetMETCollectionWithStatus,1); // Fill only one dijet+Met combo
     if(false) std::cout<<" dijetmet validator "<<std::endl;
     // fill histograms for di-jet + met vaiables. Mono-H Specific histograms. 
     std::vector<int> bitVec; bitVec.clear();
     if(RKDiJetMETCollectionWithStatus.size()>0) histfac.Fill(RKDiJetMETCollectionWithStatus,1, bitVec); // empty vector for no cuts
     if(false) std::cout<<" histfac 1"<<std::endl;
     // Following is pT,  Eta and CSV Loose
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); bitVec.push_back(3);
     if(RKDiJetMETCollectionWithStatus.size()>0) histfacJetPreSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     if(false) std::cout<<" histfac 1"<<std::endl;
     bitVec.clear();
     // Call again with different bit pattern to measure efficiency. 
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); 
     bitVec.push_back(3); bitVec.push_back(4); bitVec.push_back(5); 
     bitVec.push_back(6);  // upto Mbb cut
     if(RKDiJetMETCollectionWithStatus.size()>0) histfacJetHardPreSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     if(false) std::cout<<" histfac 1"<<std::endl;
     bitVec.clear();
     
     // Full Selection 
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); 
     bitVec.push_back(3); bitVec.push_back(4); bitVec.push_back(5); 
     bitVec.push_back(6); bitVec.push_back(7); bitVec.push_back(8);
     bitVec.push_back(9); bitVec.push_back(10);// upto Mbb cut
     if(RKDiJetMETCollectionWithStatus.size()>0) histfacFullSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     if(false) std::cout<<" histfac 1"<<std::endl;
     bitVec.clear();
     
     //if( RKDiJetMETCollectionWithStatus.size()>0)     std::cout<<" cut status main = "<<RKDiJetMETCollectionWithStatus[0].cutsStatus<<std::endl;
     

     if(false) std::cout<<" calling cutFlow "<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) cutflowobj.CutFlow(RKDiJetMETCollectionWithStatus);
     
     if(false) std::cout<<" calling nminus one"<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) nminusobj.Fill(RKDiJetMETCollectionWithStatus);
     
     //std::cout<<" calling ABCD method "<<std::endl;
     //if(RKDiJetMETCollectionWithStatus.size()>0) abcd.Fill(RKDiJetMETCollectionWithStatus);

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
   
   elenminusoneobjE.Write();
   elenminusoneobjB.Write();
   
   electronvalidator.Write();
   electronvalidator_barrel.Write();
   electronvalidator_endcap.Write();
   
   metvalidator.Write();
   diJetValidator.Write();
   
   diElectronValidator.Write();
   diElectronValidatorIso.Write();
   
   jetmetValidator.Write();
   dijetmetValidator.Write();
   cutflowobj.Write();
   nminusobj.Write();
   histfac.Write();
   histfacJetPreSel.Write();
   histfacJetHardPreSel.Write();
   histfacFullSel.Write();
   //syncmonoh.Write();
   //abcd.Write();
   fout->cd();
   nEvents->Write();
   nEvents_weight->Write();
}




void RKAnalyzer::JetProducer(){
  
  //std::cout<<" inside JetProducer "<<THINnJet<<std::endl;
  for(Int_t i=0;i<THINnJet;i++){
    jets.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) THINjetP4->At(i);
    if(false) std::cout<<" jet info = "<<fourmom->Pt()
		       <<"  :  "<<fourmom->Eta()
		       <<" : "<<(*THINjetCISVV2)[i]
		       <<"  :  "<<(*THINjetCHadEF)[i]
		       <<std::endl;
    jets.event                          = events;
    jets.nJets                          = THINnJet;
    jets.p4                             = *fourmom;
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
    jets.tau1                           = -1;
    jets.tau2                           = -1;
    jets.tau3                           = -1;
    jets.jetMuEF                        = (*THINjetMuEF)[i];
    jets.jetPhoEF                       = (*THINjetPhoEF)[i];
    jets.jetCEmEF                       = (*THINjetCEmEF)[i];
    jets.jetCHadEF                      = (*THINjetCHadEF)[i];
    jets.jetNEmEF                       = (*THINjetNEmEF)[i];
    jets.jetNHadEF                      = (*THINjetNHadEF)[i];
    jets.jetCMulti                      = (*THINjetCMulti)[i];
    
    float pt  = fourmom->Pt();
    float eta_ = fourmom->Eta();
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
    
    //bool eta24_25 =  (fabs(eta_) > 2.4) && (fabs(eta_) < 2.5) && ((*THINjetNHadEF)[i] < 0.99) && ((*THINjetNEmEF)[i] < 0.99) && ((*THINjetMuEF)[i] < 0.8) && ((*THINjetCHadEF)[i] > 0.) && ((*THINjetCMulti)[i] > 0) && ((*THINjetCEmEF)[i] < 0.99) ;    

    jets.isLooseJet_     =  (*THINjetPassIDLoose)[i];
    jets.isPUJet_        = (*THINPUJetID)[i] > -0.63  ;
    jets.nVtx            = nVtx;
    
    if(TMath::Abs(fourmom->Eta()) < 2.5 && 
       fourmom->Pt() > 30. &&
       (*THINjetPassIDLoose)[i] &&
       (*THINPUJetID)[i] > -0.63 &&
       triggerstatus)   RKJetCollection.push_back(jets);
    
    if(TMath::Abs(fourmom->Eta()) < 2.5 && 
       jets.B_CISVV2 > 0.4 && 
       fourmom->Pt() > 30. && 
       (*THINjetPassIDLoose)[i] && 
       (*THINPUJetID)[i] > -0.63 &&
       triggerstatus) RKJetCollection_selected.push_back(jets);
 

    
    
  }
}



void RKAnalyzer::FATJetProducer(){
  
  for(Int_t i=0;i<FATnJet;i++){
    fatjets.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) FATjetP4->At(i);
    fatjets.p4                             = *fourmom;
    fatjets.charge                         = (*FATjetCharge)[i];
    fatjets.partonFlavor                   = (*FATjetPartonFlavor)[i];

    fatjets.jetCEmEF                       = (*FATjetCEmEF)[i];
    fatjets.jetCHadEF                      = (*FATjetCHadEF)[i];
    fatjets.jetPhoEF                       = (*FATjetPhoEF)[i];
    fatjets.jetNEmEF                       = (*FATjetNEmEF)[i];
    fatjets.jetNHadEF                      = (*FATjetNHadEF)[i];
    fatjets.jetMuEF                        = (*FATjetMuEF)[i];
    fatjets.jetCMulti                      = (*FATjetCMulti)[i];

    fatjets.B_SSV                          = (*FATjetSSV)[i];
    fatjets.B_CSV                          = (*FATjetCSV)[i];
    fatjets.B_SSVHE                        = (*FATjetSSVHE)[i];
    fatjets.B_CISVV2                       = (*FATjetCISVV2)[i];
    fatjets.B_TCHP                         = (*FATjetTCHP)[i];
    fatjets.B_TCHE                         = (*FATjetTCHE)[i];
    fatjets.B_JP                           = (*FATjetJP)[i];
    fatjets.B_JBP                          = (*FATjetJBP)[i];
    
    fatjets.DMmass                         = (*FATjetSDmass)[i];
    fatjets.TRmass                         = (*FATjetTRmass)[i];
    fatjets.PRmass                         = (*FATjetPRmass)[i];
    fatjets.Fimass                         = (*FATjetFimass)[i];

    fatjets.tau1                           = (*FATjetTau1)[i];
    fatjets.tau2                           = (*FATjetTau2)[i];
    fatjets.tau3                           = (*FATjetTau3)[i];
    fatjets.tau4                           = (*FATjetTau4)[i];

    fatjets.nsubJets                       = (*FATnSubSDJet)[i];


    fatjets.SDPx                           = (*FATsubjetSDPx)[i];
    fatjets.SDPy                           = (*FATsubjetSDPy)[i];
    fatjets.SDPz                           = (*FATsubjetSDPz)[i];
    fatjets.SDEn                           = (*FATsubjetSDCE)[i];
    fatjets.SDCSV                          = (*FATsubjetSDCSV)[i];
    
    fatjets.isLooseJet_     =  (*FATjetPassIDLoose)[i];
    fatjets.isPUJet_        = (*FATPUJetID)[i] > -0.63  ;
    fatjets.nVtx            = nVtx;
    if(fourmom->Pt()>150.0) MH_FATJetCollection.push_back(fatjets);
  }
}





void RKAnalyzer::ADDJetProducer(){
  
  for(Int_t i=0;i<ADDnJet;i++){
    addjets.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) ADDjetP4->At(i);
    addjets.p4                             = *fourmom;
    addjets.charge                         = (*ADDjetCharge)[i];
    addjets.partonFlavor                   = (*ADDjetPartonFlavor)[i];

    addjets.jetCEmEF                       = (*ADDjetCEmEF)[i];
    addjets.jetCHadEF                      = (*ADDjetCHadEF)[i];
    addjets.jetPhoEF                       = (*ADDjetPhoEF)[i];
    addjets.jetNEmEF                       = (*ADDjetNEmEF)[i];
    addjets.jetNHadEF                      = (*ADDjetNHadEF)[i];
    addjets.jetMuEF                        = (*ADDjetMuEF)[i];
    addjets.jetCMulti                      = (*ADDjetCMulti)[i];

    addjets.B_SSV                          = (*ADDjetSSV)[i];
    addjets.B_CSV                          = (*ADDjetCSV)[i];
    addjets.B_SSVHE                        = (*ADDjetSSVHE)[i];
    addjets.B_CISVV2                       = (*ADDjetCISVV2)[i];
    addjets.B_TCHP                         = (*ADDjetTCHP)[i];
    addjets.B_TCHE                         = (*ADDjetTCHE)[i];
    addjets.B_JP                           = (*ADDjetJP)[i];
    addjets.B_JBP                          = (*ADDjetJBP)[i];
    
    //addjets.DMmass                         = (*ADDjetSDmass)[i];
    //addjets.TRmass                         = (*ADDjetTRmass)[i];
    //addjets.PRmass                         = (*ADDjetPRmass)[i];
    //addjets.Fimass                         = (*ADDjetFimass)[i];

    addjets.doubleSV                       = (*ADDjet_DoubleSV)[i];
    addjets.nSV                            = (*ADDjet_nSV)[i];
    addjets.SVMass                         = (*ADDjet_SVMass)[i];
    
    addjets.tau1                           = (*ADDjetTau1)[i];
    addjets.tau2                           = (*ADDjetTau2)[i];
    addjets.tau3                           = (*ADDjetTau3)[i];
    addjets.tau4                           = (*ADDjetTau4)[i];

    addjets.nsubJets                       = (*ADDnSubSDJet)[i];


    addjets.SDPx                           = (*ADDsubjetSDPx)[i];
    addjets.SDPy                           = (*ADDsubjetSDPy)[i];
    addjets.SDPz                           = (*ADDsubjetSDPz)[i];
    addjets.SDEn                           = (*ADDsubjetSDCE)[i];
    addjets.SDCSV                          = (*ADDsubjetSDCSV)[i];
    
    addjets.isLooseJet_     =  (*ADDjetPassIDLoose)[i];
    addjets.isPUJet_        = (*ADDPUJetID)[i] > -0.63  ;
    addjets.nVtx            = nVtx;
    if(fourmom->Pt()>150.0) MH_ADDJetCollection.push_back(addjets);
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
  if(false)  std::cout<< " inside muon producer "<<std::endl;
  for(size_t i=0; i<(size_t) nMu; i++){
    muons.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) muP4->At(i);
    muons.p4      = *fourmom ;
    std::cout<<" p4 filled "<<std::endl;
    muons.charge  = (*muCharge)[i] ;
    std::cout<<" charge filled "<<std::endl;
    bool isloose =  (*isLooseMuon)[i];;
    std::cout<<" looseid filled "<<std::endl;
    if(fourmom->Pt() > 10 && fabs(fourmom->Eta())<2.4 && isloose ) RKMuonCollection.push_back(muons);
  }
}



void RKAnalyzer::PhotonProducer(){
  //std::cout<< " inside photon producer "<<std::endl;
  for(size_t i=0; i<(size_t)nPho; i++){
    photons.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) phoP4->At(i);
    photons.p4      = *fourmom ;
    
    if(fourmom->Pt() > 15 && fabs(fourmom->Eta())<2.5 && (*phoIsPassLoose)[i] == 1) RKPhotonCollection.push_back(photons);
  }
}


void RKAnalyzer::TauProducer(){
  //std::cout<<" inside tau producer "<<std::endl;

}
void RKAnalyzer::ElectronProducer(){

  //opening file for effective area 
  //  edm::FileInPath eaConstantsFile("EgammaAnalysis/ElectronTools/data/PHYS14/effAreaElectrons_cone03_pfNeuHadronsAndPhotons.txt");
  //EffectiveAreas effectiveAreas(eaConstantsFile.fullPath());


  ElectronSelectionBitsProducer eleselectbits;
  for(size_t i=0; i<(size_t) nEle; i++){
    TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(i);
    float eA =EAElectron::EA(fourmom->Eta());
    electrons.p4         = (*fourmom); 
    electrons.IsPassVeto  =  (*eleIsPassVeto)[i]  ; 
    electrons.IsPassLoose  =  (*eleIsPassLoose)[i]  ; 
    electrons.IsPassMedium  =  (*eleIsPassMedium)[i]  ; 
    electrons.IsPassTight  =  (*eleIsPassTight)[i]  ; 
    electrons.IsPassHEEP  =  (*eleIsPassHEEP)[i]  ;  
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
    electrons.isoDeltaBeta  = ((*eleChHadIso)[i] + max<float>( 0.0, ((*eleNeHadIso)[i]+(*eleGamIso)[i]- 0.5 * (*elePUPt)[i])))/(electrons.p4.Pt());
    electrons.isoRho  = ((*eleChHadIso)[i] + max<float>( 0.0, ((*eleNeHadIso)[i]+(*eleGamIso)[i]- (eleRho) * (eA)) ))/(electrons.p4.Pt());
    electrons.d0  =  (*eleD0)[i]  ;     //fix it 
    electrons.dz  =  (*eleDz)[i]  ;
    electrons.expectedMissingInnerHits  =  (*eleMissHits)[i]  ;
    electrons.passConversionVeto  =  (*eleConvVeto)[i]  ;
    electrons.nVtx    =  nVtx;

    electrons.barrel  =  (*eleInBarrel)[i]  ; 
    electrons.endcap  =  (*eleInEndcap)[i]  ; 
    
    electrons.trigger =  triggerstatus;
    if(electrons.barrel) electrons.cutsStatusL = eleselectbits.SelectionBitsSaver(electrons,eleCuts.LooseDYcutValueMapBarrel);
    if(electrons.endcap) electrons.cutsStatusL = eleselectbits.SelectionBitsSaver(electrons,eleCuts.LooseDYcutValueMapEndcap);
						 
    if(electrons.barrel) electrons.cutsStatusM = eleselectbits.SelectionBitsSaver(electrons,eleCuts.MediumDYcutValueMapBarrel);
    if(electrons.endcap) electrons.cutsStatusM = eleselectbits.SelectionBitsSaver(electrons,eleCuts.MediumDYcutValueMapEndcap);
						 
    if(electrons.barrel) electrons.cutsStatusT = eleselectbits.SelectionBitsSaver(electrons,eleCuts.TightDYcutValueMapBarrel);
    if(electrons.endcap) electrons.cutsStatusT = eleselectbits.SelectionBitsSaver(electrons,eleCuts.TightDYcutValueMapEndcap);
    
    //electron.cutsStatusM = SelectionBitsSaver(electrons,);
    //electron.cutsStatusT = SelectionBitsSaver(electrons,);
    
    
    if(fourmom->Pt() > 10 && TMath::Abs(fourmom->Eta())<2.5 && electrons.IsPassVeto)  RKElectronCollection.push_back(electrons);
    if(triggerstatus && fourmom->Pt() > 20 && fabs(fourmom->Eta())<2.5 && (*eleInBarrel)[i] ==1 )  RKElectronCollection_barrel.push_back(electrons);
    if(triggerstatus && fourmom->Pt() > 20 && fabs(fourmom->Eta())<2.5 && (*eleInEndcap)[i]==1  )    RKElectronCollection_endcap.push_back(electrons);

    if(triggerstatus && fourmom->Pt() > 20 && fabs(fourmom->Eta())<2.5 && (*eleIsPassMedium)[i]==1)  RKElectronCollection_allCutM.push_back(electrons);
    bool isobarrel =  electrons.barrel && (electrons.isoRho ) < 0.107587;
    bool isoendcap =  electrons.endcap && (electrons.isoRho ) < 0.113254;
    if(triggerstatus && fourmom->Pt() > 20 && fabs(fourmom->Eta())<2.5 && (*eleIsPassMedium)[i]==1 && (isobarrel || isoendcap) )  RKElectronCollection_allCutMIso.push_back(electrons);
    

  }
  
}



void RKAnalyzer::ClearCollections(){
  RKJetCollection.clear();
  RKJetCollection_selected.clear();
  RKMuonCollection.clear();
  MH_FATJetCollection.clear();
  MH_ADDJetCollection.clear();
  
  RKElectronCollection.clear();

  RKElectronCollection_barrel.clear();
  RKElectronCollection_endcap.clear();
  RKElectronCollection_allCutM.clear();
  RKElectronCollection_allCutMIso.clear();
  
  RKdiElectronCollection.clear();
  RKdiElectronCollectionIso.clear();

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
  //int ic=0;
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

  bool triggerstat=false;
  if(false) std::cout<<" number of triggers = "<<(*hlt_trigResult).size()<<std::endl;
  for(size_t i =0; i < (*hlt_trigResult).size() ; i++) {
    std::string trigname = (*hlt_trigName)[i];
    size_t foundEle00=trigname.find(TRIGNAME);//HLT_DoubleEle33
    if ( foundEle00==std::string::npos) continue;
    
    if(false) std::cout<<"trigger name = "<<trigname
             <<" status = "<<(*hlt_trigResult)[i]<<std::endl;
    triggerstat=(*hlt_trigResult)[i];
  }
  return triggerstat;
}


void RKAnalyzer::EventProducer(){
  events.run      = runId;
  events.lumi     = lumiSection;
  events.event    = eventId;
  if(isData)        events.mcweight = 1.0 ;
  if(!isData) {
    if(mcWeight<0)   events.mcweight = -1.0;
    if(mcWeight>0)   events.mcweight =  1.0;
  }
  events.nvtx            = nVtx;
}
