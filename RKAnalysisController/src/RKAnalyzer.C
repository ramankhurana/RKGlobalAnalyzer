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
  std::cout<<" output = "<<output<<std::endl;
  nEvents = new TH1F("nEvents","",2,0,2);
  nEvents_weight = new TH1F("nEvents_weight","",2,0,2);
  //nEvents = dynamic_cast<TH1F*> (f->Get("allEventsCounter/totalEvents"));
  
  if(debug) std::cout<<" creating output file"<<std::endl;
  fout = new TFile(output,"RECREATE");
  //fout->cd();
  //nEvents->Write();



  jetvalidator.GetInputs(fout,"Jet_NoCut_");
  jetvalidator_selected.GetInputs(fout,"Jet_PtEtaBTag_");
  
  elenminusoneobjB.GetInputs(fout,"ElectronNMinus1B");
  elenminusoneobjE.GetInputs(fout,"ElectronNMinus1E");
  
  electronvalidator.GetInputs(fout,"Electron_NoCut_");
  electronvalidator_barrel.GetInputs(fout,"Electron_NoCut_Barrel_");
  electronvalidator_endcap.GetInputs(fout,"Electron_NoCut_Endcap_");
  
  metvalidator.GetInputs(fout,"MET_NoCut_");
  diJetValidator.GetInputs(fout,"DiJetNotCut");
  
  diElectronValidator.GetInputs(fout,"DiElectronMediumID");
  diElectronValidatorIso.GetInputs(fout,"DiElectronMediumIDIso");
  
  jetmetValidator.GetInputs(fout,"JetMETNoCuts");
  dijetmetValidator.GetInputs(fout,"DiJetMETNoCuts");
  cutflowobj.GetInputs(fout,"CutFlowAndEachCut");
  nminusobj.GetInputs(fout,"NMinusOne");
  histfac.GetInputs(fout,"NoCut");
  histfacJetPreSel.GetInputs(fout,"JetPreSel");
  //histfacJetHardPreSel.GetInputs(fout,"JetHardPreSel");
  
  abcd.GetInputs(fout,"ABCD");
  
  if(debug) std::cout<<" Sending information to JetValidator "<<std::endl;
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  std::cout<<" nevents ====== "<<nentries<<std::endl;
  //nentries = 100;
  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     if(mcWeight < 0) mcw=-1.;
     if(mcWeight > 0) mcw= 1.;
     nEvents->Fill(1);
     nEvents_weight->Fill(1,mcw);
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
       
     std::cout<<" ------------------- event number -----------------: = "<<jentry<<std::endl;
     // Clear all the collections
     ClearCollections();
     
     if(isData){ 
       triggerstatus = TriggerStatus("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");}
     if(!isData)
     // Produce jet collection for analysis and validation of object variables.
     JetProducer();
     // Produce MET collection for analysis and validation of object.
     // this contain all raw PFMET, corrected PFMET and MVA PFMET.
     METProducer();
     MuonProducer();
     ElectronProducer();

     // N-1 For Electron ID
     std::cout<<" N-1 for barrel with size "<<RKElectronCollection_barrel.size()<<std::endl;
     if(RKElectronCollection_barrel.size()>0 && RKElectronCollection_barrel[0].pt20_) elenminusoneobjB.Fill(RKElectronCollection_barrel);
     std::cout<<" N-1 for endcap with size "<<RKElectronCollection_endcap.size()<<std::endl;
     if(RKElectronCollection_endcap.size()>0 && RKElectronCollection_endcap[0].pt20_) elenminusoneobjE.Fill(RKElectronCollection_endcap);
     
     // Fill Validation Histograms for Jets
     std::cout<<" Jet Validator no sel"<<std::endl;
     if(RKJetCollection.size()>0) jetvalidator.Fill(RKJetCollection);
     std::cout<<" Jet Validator with sel"<<std::endl;
     if (RKJetCollection_selected.size()>0) jetvalidator_selected.Fill(RKJetCollection_selected);
     
     std::cout<<" electron Validator no sel"<<std::endl;
     // Fill the electron validation histograms 
     if(RKElectronCollection.size()>0 && RKElectronCollection[0].pt20_) electronvalidator.Fill(RKElectronCollection);
     std::cout<<" electron Validator no sel barrel with size "<<RKElectronCollection_barrel.size()<<std::endl;
     if(RKElectronCollection_barrel.size()>0 && RKElectronCollection_barrel[0].pt20_) electronvalidator_barrel.Fill(RKElectronCollection_barrel);
     std::cout<<" electron Validator no sel endcap"<<RKElectronCollection_endcap.size()<<std::endl;
     if(RKElectronCollection_endcap.size()>0 && RKElectronCollection_endcap[0].pt20_) electronvalidator_endcap.Fill(RKElectronCollection_endcap);
     // Fill Validation histograms for MET
     std::cout<<" MET Validator"<<std::endl;
     metvalidator.Fill(met);
     
     // Dijet 
     std::cout<<" calling dijet maker "<<std::endl;
     // for validation 
     if(RKJetCollection_selected.size()>0) RKdiJetCollection_selected = dijet_selected.ReconstructDiObject(RKJetCollection_selected);
     std::cout<<" made dijet selected "<<std::endl;
     // For further processing 
     if(RKJetCollection.size()>0) RKdiJetCollection = dijet.ReconstructDiObject(RKJetCollection);
     //RKdiJetCollection = RKdiJetCollection_selected;
     std::cout<< " dijet collection size = ========== "<<RKdiJetCollection.size()<<std::endl;

     // DiElectron 
     if(RKElectronCollection_allCutM.size()>0 ) RKdiElectronCollection = dielectron.ReconstructDiObject(RKElectronCollection_allCutM);
     if(RKElectronCollection_allCutMIso.size()>0 ) RKdiElectronCollectionIso = dielectron.ReconstructDiObject(RKElectronCollection_allCutMIso);

     // DiJet Validation
     if(RKdiJetCollection.size()>0) std::cout<<" diJet mass = "<<RKdiJetCollection[0].ResonanceProp.p4.Mag()<<std::endl;
     if(RKdiJetCollection.size() > 0) diJetValidator.Fill(RKdiJetCollection_selected);
     std::cout<<" dijet part done "<<std::endl;
     
     if(RKdiElectronCollection.size()>0 && RKdiElectronCollection[0].jet1.pt20_ )     diElectronValidator.Fill(RKdiElectronCollection);
     if(RKdiElectronCollectionIso.size()>0 && RKdiElectronCollectionIso[0].jet1.pt20_)  diElectronValidatorIso.Fill(RKdiElectronCollectionIso);
     
     std::cout<<" before sorting "<<std::endl;
     // Dijet Vector Sorting wrt pT of diJet candidate 
     for(size_t idj=0; idj<RKdiJetCollection.size();idj++){
       std::cout<<" mass = "<<RKdiJetCollection[idj].ResonanceProp.p4.Pt()
		<<std::endl;;
     }
     std::sort(RKdiJetCollection.begin(), RKdiJetCollection.end(), DiJetpTSorting() );
     std::cout<<" after sorting "<<std::endl;
      
     
     // Jet-MET
     if(RKJetCollection_selected.size()>0) RKjetMETCollection = jet_met.ReconstructDiObject(RKJetCollection_selected,met);
     if(RKjetMETCollection.size()>0) std::cout<<" transverse mass = "<<RKjetMETCollection[0].TransverseObjProp.TransMass <<std::endl;
     if(RKjetMETCollection.size()>0) jetmetValidator.Fill(RKjetMETCollection);
     
     //DiJet-MET
     if(RKdiJetCollection.size()>0) RKDiJetMETCollection = dijet_met.ReconstructDiObject(RKdiJetCollection,met);
     std::cout<<" size of DIJETMET collection is = "<<RKDiJetMETCollection.size()<<std::endl;
     
     // add electron to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].electrons = RKElectronCollection ;
     
     // add muon to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].muons = RKMuonCollection ;
     if(RKDiJetMETCollection.size()>0) std::cout<<" ----------------- muon size = "<<RKDiJetMETCollection[0].muons.size()<<std::endl;
     
     // add jets to the RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].jets  = RKJetCollection_selected ;
     
     // add selection bits for baseline Analysis.
     if(RKDiJetMETCollection.size()>0)RKDiJetMETCollectionWithStatus = selectionbits.SelectionBitsSaver(RKDiJetMETCollection, cuts.cutValueMap);
     
     // add selection bits for ttbar control region 
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollectionTTBar = selectionbits.SelectionBitsSaver(RKDiJetMETCollection,cuts.cutValueMapTTBar);
     
     
     // --------------------------------//
     // ---------- Histograms -----------//
     // --------------------------------//
     // fill histograms for di-jet + met vaiables. very basic and common variables.
     if(RKDiJetMETCollectionWithStatus.size()>0) dijetmetValidator.Fill(RKDiJetMETCollectionWithStatus,1); // Fill only one dijet+Met combo
     
     // fill histograms for di-jet + met vaiables. Mono-H Specific histograms. 
     std::vector<int> bitVec; bitVec.clear();
     if(RKDiJetMETCollectionWithStatus.size()>0) histfac.Fill(RKDiJetMETCollectionWithStatus,1, bitVec); // empty vector for no cuts
     // Following is pT,  Eta and CSV Loose
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); bitVec.push_back(3);
     if(RKDiJetMETCollectionWithStatus.size()>0) histfacJetPreSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     bitVec.clear();
     // Call again with different bit pattern to measure efficiency. 
     bitVec.push_back(0); bitVec.push_back(1); bitVec.push_back(2); 
     bitVec.push_back(3); bitVec.push_back(4); bitVec.push_back(5); 
     bitVec.push_back(6); bitVec.push_back(7); // upto Mbb cut
     //histfacJetHardPreSel.Fill(RKDiJetMETCollectionWithStatus,1, bitVec);
     bitVec.clear();
     
     if( RKDiJetMETCollectionWithStatus.size()>0)     std::cout<<" cut status main = "<<RKDiJetMETCollectionWithStatus[0].cutsStatus<<std::endl;
     
     std::cout<<" calling cutFlow "<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) cutflowobj.CutFlow(RKDiJetMETCollectionWithStatus);
     
     std::cout<<" calling nminus one"<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) nminusobj.Fill(RKDiJetMETCollectionWithStatus);
     
     std::cout<<" calling ABCD method "<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) abcd.Fill(RKDiJetMETCollectionWithStatus);
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
   //histfacJetHardPreSel.Write();
   abcd.Write();
   fout->cd();
   nEvents->Write();
   nEvents_weight->Write();
}




void RKAnalyzer::JetProducer(){
  
  std::cout<<" inside JetProducer "<<THINnJet<<std::endl;
  for(Int_t i=0;i<THINnJet;i++){
    jets.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) THINjetP4->At(i);
    if(false) std::cout<<" jet info = "<<fourmom->Pt()
	     <<"  :  "<<fourmom->Eta()
	     <<" : "<<(*THINjetCISVV2)[i]
	     <<"  :  "<<(*THINjetCHadEF)[i]
	     <<std::endl;
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
    jets.weight  =  mcw;
    jets.isdata  = (Bool_t) isData;

    
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
    jets.isLooseJet_     =   pt > 30.  && 
                        fabs(eta_) < 2.5 && 
                        csv > 0.432                      ;
    
    RKJetCollection.push_back(jets);
    RKJetCollection_selected.push_back(jets);
    //if(fabs(fourmom->Eta())<2.5 && jets.B_CISVV2 > 0.432 && fourmom->Pt() > 30. && RKJetCollection.size()<4 )     RKJetCollection_selected.push_back(jets);
    //RKJetCollection_selected.push_back(jets);
    
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
  for(size_t i=0; i<(size_t) nMu; i++){
    muons.Clear();
    TLorentzVector*  fourmom = (TLorentzVector*) muP4->At(i);
    muons.p4      = *fourmom ;
    muons.charge  = (*muCharge)[i] ;
    if(fourmom->Pt() > 20 && fabs(fourmom->Eta())<2.4 && (*isPFMuon)[i] == 1) RKMuonCollection.push_back(muons);
  }
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
    electrons.nTrueInt = pu_nTrueInt;
    electrons.nPUVert  = pu_nPUVert;
    electrons.nVtx    =  nVtx;
    electrons.weight  =  mcw;
    electrons.isdata  = (Bool_t) isData;
    electrons.pt20_   = electrons.p4.Pt()>20.;
    electrons.pt15_   = electrons.p4.Pt()>15.;
    
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
    
    
    if(triggerstatus && fourmom->Pt() > electrons.pt15_ && fabs(fourmom->Eta())<2.5)  RKElectronCollection.push_back(electrons);
    if(triggerstatus && fourmom->Pt() > electrons.pt15_ && fabs(fourmom->Eta())<2.5 && (*eleInBarrel)[i] ==1 )  RKElectronCollection_barrel.push_back(electrons);
    if(triggerstatus && fourmom->Pt() > electrons.pt15_ && fabs(fourmom->Eta())<2.5 && (*eleInEndcap)[i]==1  )    RKElectronCollection_endcap.push_back(electrons);

    if(triggerstatus && fourmom->Pt() > electrons.pt15_ && fabs(fourmom->Eta())<2.5 && (*eleIsPassMedium)[i]==1)  RKElectronCollection_allCutM.push_back(electrons);
    bool isobarrel =  electrons.barrel && (electrons.isoRho ) < 0.107587;
    bool isoendcap =  electrons.endcap && (electrons.isoRho ) < 0.113254;
    if(triggerstatus && fourmom->Pt() > electrons.pt15_ && fabs(fourmom->Eta())<2.5 && (*eleIsPassMedium)[i]==1 && (isobarrel || isoendcap) )  RKElectronCollection_allCutMIso.push_back(electrons);
    
  }
  std::cout<<" electron collection filled " <<std::endl;
}



void RKAnalyzer::ClearCollections(){
  RKJetCollection.clear();
  RKJetCollection_selected.clear();
  RKMuonCollection.clear();
  
  RKElectronCollection.clear();
  RKElectronCollection_barrel.clear();
  RKElectronCollection_endcap.clear();
  RKElectronCollection_allCutM.clear();
  RKElectronCollection_allCutMIso.clear();
  
  RKdiElectronCollection.clear();
  RKdiElectronCollectionIso.clear();
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


void RKAnalyzer::TotalEvent(TH1F* h){
  fout->cd();
  h->Write();

}





bool RKAnalyzer::TriggerStatus(std::string TRIGNAME){
  bool triggerstat=false;
  std::cout<<" number of triggers = "<<(*hlt_trigResult).size()<<std::endl;
  for(size_t i =0; i < (*hlt_trigResult).size() ; i++) {
    std::string trigname = (*hlt_trigName)[i];
    size_t foundEle00=trigname.find(TRIGNAME);//HLT_DoubleEle33
    if ( foundEle00==std::string::npos) continue;
    
    std::cout<<"trigger name = "<<trigname
             <<" status = "<<(*hlt_trigResult)[i]<<std::endl;
    triggerstat=(*hlt_trigResult)[i];
  }
  return triggerstat;
}
