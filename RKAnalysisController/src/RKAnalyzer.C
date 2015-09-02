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
  h_CutFlow      = new TH1F("h_CutFlow","",8,0,8);
  
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
  
  metvalidator.GetInputs(fout,"MET_NoCut_");
  diJetValidator.GetInputs(fout,"DiJetNotCut");
  
  diElectronValidator.GetInputs(fout,"DiElectronMediumID");

  Tmp_diElectronValidator_NEle.GetInputs(fout,"NEle");
  Tmp_diElectronValidator_Trig.GetInputs(fout,"Trig");
  Tmp_diElectronValidator_Kin.GetInputs(fout,"Kin");
  Tmp_diElectronValidator_MID.GetInputs(fout,"MID");
  Tmp_diElectronValidator_Charge.GetInputs(fout,"Charge");
  
  jetmetValidator.GetInputs(fout,"JetMETNoCuts");
  dijetmetValidator.GetInputs(fout,"DiJetMETNoCuts");
  cutflowobj.GetInputs(fout,"CutFlowAndEachCut");
  nminusobj.GetInputs(fout,"NMinusOne");
  histfac.GetInputs(fout,"NoCut");
  histfacJetPreSel.GetInputs(fout,"JetPreSel");
  //histfacJetHardPreSel.GetInputs(fout,"JetHardPreSel");
  
  abcd.GetInputs(fout,"ABCD");
  
  if(false) std::cout<<" Sending information to JetValidator "<<std::endl;
  if (fChain == 0) return;
  
  Long64_t nentries = fChain->GetEntriesFast();
  
  std::cout<<" nevents ====== "<<nentries<<std::endl;
  // nentries = 100;
  Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     if(isData){mcw =1 ;}
     if(!isData){
     if(mcWeight < 0) mcw=-1;
     if(mcWeight > 0) mcw= 1;}
     
     nEvents->Fill(1);
     nEvents_weight->Fill(1,mcw);

     
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     
          
     std::cout<<" ------------------- event number -----------------: = "<<jentry<<std::endl;
     // Clear all the collections
     ClearCollections();

     //double electron trigger 
     // triggerstatus = TriggerStatus("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL"); 
     // Single electron trigger
     if(isData){ 
       triggerstatus = TriggerStatus("HLT_Ele23_WPLoose_Gsf_v");}
     if(!isData){
     triggerstatus = TriggerStatus("HLT_Ele23_WP75_Gsf");}
     
     // Produce jet collection for analysis and validation of object variables.
     JetProducer();
     // Produce MET collection for analysis and validation of object.
     // this contain all raw PFMET, corrected PFMET and MVA PFMET.
     METProducer();
     MuonProducer();
     ElectronProducer();

     // N-1 For Electron ID
     if(false) std::cout <<" N-1 for barrel with size "<<RKElectronCollection_barrel.size()<<std::endl;
     if(RKElectronCollection_barrel.size()>0) elenminusoneobjB.Fill(RKElectronCollection_barrel);
     if(false) std::cout <<" N-1 for endcap with size "<<RKElectronCollection_endcap.size()<<std::endl;
     if(RKElectronCollection_endcap.size()>0) elenminusoneobjE.Fill(RKElectronCollection_endcap);
     
     // Fill Validation Histograms for Jets
     if(false) std::cout <<" Jet Validator no sel"<<std::endl;
     if(RKJetCollection.size()>0) jetvalidator.Fill(RKJetCollection);
     if(false) std::cout <<" Jet Validator with sel"<<std::endl;
     if (RKJetCollection_selected.size()>0) jetvalidator_selected.Fill(RKJetCollection_selected);
     
     if(false) std::cout <<" electron Validator no sel"<<std::endl;
     // Fill the electron validation histograms 
     if(RKElectronCollection.size()>0) electronvalidator.Fill(RKElectronCollection);


     // Fill Validation histograms for MET
     if(false) std::cout <<" MET Validator"<<std::endl;
     metvalidator.Fill(met);
     
     // Dijet 
     if(false) std::cout <<" calling dijet maker "<<std::endl;
     // for validation 
     if(RKJetCollection_selected.size()>0) RKdiJetCollection_selected = dijet_selected.ReconstructDiObject(RKJetCollection_selected);
     if(false) std::cout <<" made dijet selected "<<std::endl;
     // For further processing 
     if(RKJetCollection.size()>0) RKdiJetCollection = dijet.ReconstructDiObject(RKJetCollection);
     //RKdiJetCollection = RKdiJetCollection_selected;
     if(false) std::cout << " dijet collection size = ========== "<<RKdiJetCollection.size()<<std::endl;

     // DiElectron 
     if(RKElectronCollection.size()>0 ) RKdiElectronCollection = dielectron.ReconstructDiObject(RKElectronCollection);
     
     /*      Bool_t triggermatched = true; 
      Double_t drtmp= 999. , drtmp1 =999. ;
     //to check the leading jet has matched the trigger or not
      if(isData &&  RKdiElectronCollection.size() >0 && (*hlt_TrigObjPt).size() >0 ){  
	triggermatched = false;
	//cout << "trigger filter size :"  <<  (*hlt_TrigObjPt)[0].size() <<std::endl;
	std::vector<float> single_ele_pt = (*hlt_TrigObjPt)[0];
	std::vector<float> single_ele_eta = (*hlt_TrigObjEta)[0];
	std::vector<float> single_ele_phi = (*hlt_TrigObjPhi)[0];
	if((*hlt_TrigObjPt)[0].size() > 0){
	  // triggermatched = true;
	  
	  drtmp = deltaR(single_ele_eta[0], single_ele_phi[0], RKdiElectronCollection[0].jet1.etaSC, RKdiElectronCollection[0].jet1.phiSC);
	  drtmp1 = deltaR(single_ele_eta[0], single_ele_phi[0], RKdiElectronCollection[0].jet2.etaSC, RKdiElectronCollection[0].jet2.phiSC);
	  //   cout << "DeltaR : "  << drtmp << std::endl;    
	  if( (drtmp < 0.4) || (drtmp1 < 0.4)){
	    triggermatched = true;
	    }
	}
      }
      
     */
     

     // DiJet Validation
     if(RKdiJetCollection.size()>0) if(false) std::cout <<" diJet mass = "<<RKdiJetCollection[0].ResonanceProp.p4.Mag()<<std::endl;
     if(RKdiJetCollection.size()> 0) diJetValidator.Fill(RKdiJetCollection_selected);
     if(false) std::cout <<" dijet part done "<<std::endl;
     
     if(RKdiElectronCollection.size()>0 )diElectronValidator.Fill(RKdiElectronCollection);

     /*if(TmpElectronCollection_NEle.size()>0) TmpdiElectronCollection_nEle =  dielectron_Nele.ReconstructDiObject(TmpElectronCollection_NEle);
     if(TmpElectronCollection_NTrig.size()>0)TmpdiElectronCollection_Trig =  dielectron_Trig.ReconstructDiObject(TmpElectronCollection_NTrig);
     if(TmpElectronCollection_NKin.size()>0) TmpdiElectronCollection_Kin = dielectron_Kin.ReconstructDiObject(TmpElectronCollection_NKin);
     
     if(TmpdiElectronCollection_nEle.size()>0)   Tmp_diElectronValidator_NEle.Fill(TmpdiElectronCollection_nEle);
     if(TmpdiElectronCollection_Trig.size()>0)   Tmp_diElectronValidator_Trig.Fill(TmpdiElectronCollection_Trig);
     if(TmpdiElectronCollection_Kin.size()>0)    Tmp_diElectronValidator_Kin.Fill(TmpdiElectronCollection_Kin);
     if(RKdiElectronCollection.size()>0)    Tmp_diElectronValidator_MID.Fill(RKdiElectronCollection); */


     if( RKdiElectronCollection.size()>0 && ((RKdiElectronCollection[0].jet1.charge * RKdiElectronCollection[0].jet2.charge ) == -1 ) &&  (RKdiElectronCollection[0].jet1.etSC > 25.) && ((RKdiElectronCollection[0].ResonanceProp.InvMass > 10.) && (RKdiElectronCollection[0].ResonanceProp.InvMass < 60.) ))Tmp_diElectronValidator_NEle.Fill(RKdiElectronCollection);
       
     if(RKdiElectronCollection.size()>0 && ((RKdiElectronCollection[0].jet1.charge * RKdiElectronCollection[0].jet2.charge ) == -1 )  &&  (RKdiElectronCollection[0].jet1.etSC > 25.) && ((RKdiElectronCollection[0].ResonanceProp.InvMass > 60.) && (RKdiElectronCollection[0].ResonanceProp.InvMass < 120.) ))Tmp_diElectronValidator_Trig.Fill(RKdiElectronCollection);
       
     if(RKdiElectronCollection.size()>0 && ((RKdiElectronCollection[0].jet1.charge * RKdiElectronCollection[0].jet2.charge ) == -1 ) &&  (RKdiElectronCollection[0].jet1.etSC > 25.) && ((RKdiElectronCollection[0].ResonanceProp.InvMass > 120.) && (RKdiElectronCollection[0].ResonanceProp.InvMass < 300.) )) Tmp_diElectronValidator_Kin.Fill(RKdiElectronCollection);
       
     if(RKdiElectronCollection.size()>0 && ((RKdiElectronCollection[0].jet1.charge * RKdiElectronCollection[0].jet2.charge ) == -1 ) &&  (RKdiElectronCollection[0].jet1.etSC > 25.) && ((RKdiElectronCollection[0].ResonanceProp.InvMass > 300.))) Tmp_diElectronValidator_MID.Fill(RKdiElectronCollection);
         

     
     if(RKdiElectronCollection.size()>0 && ((RKdiElectronCollection[0].jet1.charge * RKdiElectronCollection[0].jet2.charge ) == -1 )  && (RKdiElectronCollection[0].jet1.etSC > 25.))   Tmp_diElectronValidator_Charge.Fill(RKdiElectronCollection);
	  // if(RKdiElectronCollection.size()>0 && ((RKdiElectronCollection[0].jet1.charge * RKdiElectronCollection[0].jet2.charge ) == -1 ) )   Tmp_diElectronValidator_Charge.Fill(RKdiElectronCollection);
     


     if(false) std::cout <<" before sorting "<<std::endl;
     // Dijet Vector Sorting wrt pT of diJet candidate 
     for(size_t idj=0; idj<RKdiJetCollection.size();idj++){
       if(false) std::cout <<" mass = "<<RKdiJetCollection[idj].ResonanceProp.p4.Pt()
		<<std::endl;;
     }
     
     std::sort(RKdiJetCollection.begin(), RKdiJetCollection.end(), DiJetpTSorting() );
     if(false) std::cout <<" after sorting "<<std::endl;
      
     
     // Jet-MET
     if(RKJetCollection_selected.size()>0) RKjetMETCollection = jet_met.ReconstructDiObject(RKJetCollection_selected,met);
     if(RKjetMETCollection.size()>0) if(false) std::cout <<" transverse mass = "<<RKjetMETCollection[0].TransverseObjProp.TransMass <<std::endl;
     if(RKjetMETCollection.size()>0) jetmetValidator.Fill(RKjetMETCollection);
     
     //DiJet-MET
     if(RKdiJetCollection.size()>0) RKDiJetMETCollection = dijet_met.ReconstructDiObject(RKdiJetCollection,met);
     if(false) std::cout <<" size of DIJETMET collection is = "<<RKDiJetMETCollection.size()<<std::endl;
     
     // add electron to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].electrons = RKElectronCollection ;





     
     // add muon to RKDiJetMETCollectionWithStatus
     if(RKDiJetMETCollection.size()>0) RKDiJetMETCollection[0].muons = RKMuonCollection ;
     if(RKDiJetMETCollection.size()>0) if(false) std::cout <<" ----------------- muon size = "<<RKDiJetMETCollection[0].muons.size()<<std::endl;
     
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
     
     if( RKDiJetMETCollectionWithStatus.size()>0)     if(false) std::cout <<" cut status main = "<<RKDiJetMETCollectionWithStatus[0].cutsStatus<<std::endl;
     
     if(false) std::cout <<" calling cutFlow "<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) cutflowobj.CutFlow(RKDiJetMETCollectionWithStatus);
     
     if(false) std::cout <<" calling nminus one"<<std::endl;
     if(RKDiJetMETCollectionWithStatus.size()>0) nminusobj.Fill(RKDiJetMETCollectionWithStatus);
     
     if(false) std::cout <<" calling ABCD method "<<std::endl;
     // if(RKDiJetMETCollectionWithStatus.size()>0) abcd.Fill(RKDiJetMETCollectionWithStatus);
     if(false) std::cout <<" pfMetCorrPt = "<<pfMetCorrPt
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
   
   metvalidator.Write();
   diJetValidator.Write();
   
   diElectronValidator.Write();

   Tmp_diElectronValidator_NEle.Write();
   Tmp_diElectronValidator_Trig.Write();
   Tmp_diElectronValidator_Kin.Write();
   Tmp_diElectronValidator_MID.Write();
   Tmp_diElectronValidator_Charge.Write();
   

   
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
   h_CutFlow->Write();
     

}




void RKAnalyzer::JetProducer(){
  
  if(false) std::cout <<" inside JetProducer "<<THINnJet<<std::endl;
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
  if(false) std::cout <<" inside MET Prodicer "<<std::endl;
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
  if(false) std::cout << " inside muon producer "<<std::endl;
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
  Int_t kinematic = 0;
  Int_t IDcut = 0;
  Int_t mCFweight =1; 
  Bool_t Chargecut  = false;
  Bool_t masscut = false;
  TLorentzVector Zp4;  
  std::vector<int> indx; indx.clear();

  float leadelept =-999, subleadelept = -999, leadeleeta = -999, leadelecphi = -999, subleadeleeta = -999, subleadelecphi = -999, dielectronmass =-999, dielectronpt = -999, dielectronrapidity = -999, dielectronphi = -999;
  

  ElectronSelectionBitsProducer eleselectbits;
  for(size_t i=0; i<(size_t) nEle; i++){
    //TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(i);
    TLorentzVector* fourmom;
    fourmom = new TLorentzVector();
    fourmom->SetPtEtaPhiE((*eleScEt)[i],  (*eleScEta)[i],  (*eleScPhi)[i],   (*eleScEn)[i]);
     
    //  cout << " Supercluster : " <<" eta : " << (*eleScEta)[i] << "  Et:  " << (*eleScEt)[i] << " Phi:  " << (*eleScPhi)[i] << "  energy :"  <<(*eleScEn)[i] <<std::endl;

    // cout << " Electron : " <<" eta : " << (*fourmom).Eta() << "  Et:  " << (*fourmom).Pt() << " Phi:  " << (*fourmom).Phi() << "  energy :"  << (*fourmom).Energy() <<std::endl;
  float eA =EAElectron::EA(abs(fourmom->Eta()));
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

    electrons.RE25E55 = (*eleE2x5)[i]/(*eleE5x5)[i];
    electrons.MiniIso = (*eleMiniIso)[i];
    electrons.EcalDrivenSeed = (*eleEcalDrivenSeed)[i];
    electrons.Dr03TkSumPt = (*eleDr03TkSumPt)[i];   
        
    
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

    if(electrons.etSC > 25. &&
       fabs(electrons.etaSC) < 2.5 &&
       !( fabs(electrons.etaSC) > 1.4442 && fabs(electrons.etaSC) < 1.566 )
       ){
       //( fabs(electrons.etaSC) < 1.4442 || ( fabs(electrons.etaSC) > 1.566 && fabs(electrons.etaSC)< 2.5 ) )  ) {
      kinematic++;
      if((*eleIsPassMedium)[i]==1 && electrons.EcalDrivenSeed){
	indx.push_back(i);
	IDcut++;
	if(IDcut==2 && (((*eleCharge)[ indx[0] ] *  (*eleCharge)[ indx[1] ]) == -1 ) && (*eleScEt)[indx[0]] > 25. ){
	  Chargecut=true ;
          TLorentzVector* fourmom1;
          TLorentzVector* fourmom2;
	  fourmom1 = new TLorentzVector();
          fourmom2 = new TLorentzVector();
	  fourmom1->SetPtEtaPhiE((*eleScEt)[indx[0]],  (*eleScEta)[indx[0]],  (*eleScPhi)[indx[0]],   (*eleScEn)[indx[0]]);
          fourmom2->SetPtEtaPhiE((*eleScEt)[indx[1]],  (*eleScEta)[indx[1]],  (*eleScPhi)[indx[1]],   (*eleScEn)[indx[1]]);
	  //TLorentzVector*  fourmom1 = (TLorentzVector*) eleP4->At(indx[0]);
	  //TLorentzVector*  fourmom2 = (TLorentzVector*) eleP4->At(indx[1]);
           Zp4 = (*fourmom1) + (*fourmom2);
	  if((Zp4.M() >= 60.0) && (Zp4.M() <= 120.0)){
	    masscut = true;
            leadelept      = (*eleScEt)[indx[0]];
	    subleadelept   = (*eleScEt)[indx[1]];
	    leadeleeta     = (*eleScEta)[indx[0]];
	    leadelecphi    = (*eleScPhi)[indx[0]]; 
	    subleadeleeta  = (*eleScEta)[indx[1]];
	    subleadelecphi = (*eleScPhi)[indx[1]]; 
	    dielectronmass =  Zp4.M(); 
	    dielectronpt   =   Zp4.Pt();
	    dielectronrapidity = Zp4.Rapidity();
	    dielectronphi =       Zp4.Phi();
	    
	  }
        }
      }	
    }
    
    
    
    /*    if(nEle>=2)  TmpElectronCollection_NEle.push_back(electrons);
    if( nEle>=2 &&
	triggerstatus ==1 )TmpElectronCollection_NTrig.push_back(electrons);
    if( nEle>=2 &&
	triggerstatus ==1
	&& electrons.etSC > 25.
	&& fabs(electrons.etaSC) < 2.5
	&& !(fabs(electrons.etaSC) > 1.4442 && fabs(electrons.etaSC) < 1.566 )
	) TmpElectronCollection_NKin.push_back(electrons);
    // 10-60
    if(nEle >=2 && triggerstatus && electrons.etSC > 25. && fabs(electrons.etaSC) < 2.5 && !(fabs(electrons.etaSC) > 1.4442 && fabs(electrons.etaSC) < 1.566 ) && (*eleIsPassMedium)[i]==1 && electrons.EcalDrivenSeed ) TmpElectronCollection_NEle.push_back(electrons);
    //60-120 
    if(nEle >=2 && triggerstatus && electrons.etSC > 25. && fabs(electrons.etaSC) < 2.5 && !(fabs(electrons.etaSC) > 1.4442 && fabs(electrons.etaSC) < 1.566 ) && (*eleIsPassMedium)[i]==1 && electrons.EcalDrivenSeed ) TmpElectronCollection_NTrig.push_back(electrons);
    //120-300 
    if(nEle >=2 && triggerstatus && electrons.etSC > 25. && fabs(electrons.etaSC) < 2.5 && !(fabs(electrons.etaSC) > 1.4442 && fabs(electrons.etaSC) < 1.566 ) && (*eleIsPassMedium)[i]==1 && electrons.EcalDrivenSeed ) TmpElectronCollection_NKin.push_back(electrons);
    */    
    

    if(nEle >=2 && triggerstatus && electrons.etSC > 15. && fabs(electrons.etaSC) < 2.5 && !(fabs(electrons.etaSC) > 1.4442 && fabs(electrons.etaSC) < 1.566 ) && (*eleIsPassMedium)[i]==1 && electrons.EcalDrivenSeed ) RKElectronCollection.push_back(electrons);
    if(triggerstatus &&  electrons.etSC > 25. && fabs(electrons.etaSC)< 1.4442 ) RKElectronCollection_barrel.push_back(electrons);
    if(triggerstatus &&  electrons.etSC > 25. && ( fabs(electrons.etaSC) > 1.566 && fabs(electrons.etaSC)< 2.5 )) RKElectronCollection_endcap.push_back(electrons); 
  }
  std::cout<<" electron collection filled " <<std::endl;
  
  if(electrons.isdata)  mCFweight=1;
  if(!electrons.isdata) mCFweight=mcw;
  
  h_CutFlow->Fill(1,mCFweight);
  if(nEle >= 2){
       h_CutFlow->Fill(2,mCFweight);
       if(triggerstatus){
         h_CutFlow->Fill(3,mCFweight);
         if(kinematic >= 2){
            h_CutFlow->Fill(4,mCFweight);
            if(IDcut >= 2){
              h_CutFlow->Fill(5,mCFweight);
              if(Chargecut){
                 h_CutFlow->Fill(6,mCFweight);
                 if(masscut){
                   h_CutFlow->Fill(7,mCFweight);

		   std::cout << "run:lumi:event " << runId << ":"<<lumiSection<<":"<<eventId
		             <<" "<<dielectronmass
		             <<" "<<dielectronpt
		             <<" "<<dielectronrapidity
		             <<" "<<dielectronphi
		             <<" "<<leadelept
		             <<" "<<subleadelept
		             <<" "<<leadeleeta
		             <<" "<<subleadeleeta
		             <<" "<<leadelecphi
		             <<" "<<subleadelecphi
		             <<std::endl;   
		 }   
	      }             
	    }
	 }
       }
  }
  std::cout<<" exiting ele producer "<<std::endl;
}
    
void RKAnalyzer::ClearCollections(){
  RKJetCollection.clear();
  RKJetCollection_selected.clear();
  RKMuonCollection.clear();
  
  RKElectronCollection.clear();
  RKElectronCollection_barrel.clear();
  RKElectronCollection_endcap.clear();

  
  
  RKdiElectronCollection.clear();

  TmpElectronCollection_NEle.clear();
  TmpElectronCollection_NTrig.clear();
  TmpElectronCollection_NKin.clear();
  TmpdiElectronCollection_nEle.clear();
  TmpdiElectronCollection_Trig.clear();
  TmpdiElectronCollection_Kin.clear();
  TmpdiElectronCollection_MID.clear();
  TmpdiElectronCollection_Charge.clear();
  
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
    if(false) std::cout <<" name = "<<name<<std::endl;
    if(false) std::cout <<" false 1"<<iFile<<std::endl;
    m_f[iFile] = TFile::Open(name.c_str());
    if(false) std::cout <<" false 2"<<iFile<<std::endl;
    //if(false){
    if(iFile==0){
      if(false) std::cout <<" false 3"<<iFile<<std::endl;
      dummyHist = dynamic_cast<TH1F*> (m_f[iFile]->Get("allEventsCounter/totalEvents"));
      if(false) std::cout <<" false 4"<<iFile<<std::endl;
      outHist = (TH1F*)dummyHist->Clone();
    }
    if(false) std::cout <<" false 5"<<iFile<<std::endl;
    //if(false){
    if(iFile>0){
      dummyHist = dynamic_cast <TH1F*> (m_f[iFile]->Get("allEventsCounter/totalEvents"));
      if(false) std::cout <<" false 6"<<iFile<<std::endl;
      outHist->Add(dummyHist);
      if(false) std::cout <<" false 7"<<iFile<<std::endl;
    }
    
  }
  fout->cd();
  outHist->Write();
  
}


void RKAnalyzer::TotalEvent(TH1F* h){
  fout->cd();
  h->Write();

}

Double_t RKAnalyzer::deltaPhi(Double_t phi1, Double_t phi2)
{
  Double_t pi = 3.1415927;
  Double_t dphi = fabs(phi1 - phi2);
  if(dphi >= pi) dphi = 2. * pi - dphi;
  return dphi;
}

Double_t RKAnalyzer::deltaEta(Double_t eta1, Double_t eta2)
{
  Double_t deta = fabs(eta1 - eta2);
  return deta;
}



Double_t RKAnalyzer::deltaR(Double_t eta1, Double_t phi1, Double_t eta2, Double_t phi2)
{
  Double_t deta = deltaEta(eta1, eta2);
  Double_t dphi = deltaPhi(phi1, phi2);
  Double_t dr = sqrt(deta*deta + dphi*dphi);
  return dr;
}



bool RKAnalyzer::TriggerStatus(std::string TRIGNAME){
  bool triggerstat=false;
  if(false) std::cout <<" number of triggers = "<<(*hlt_trigResult).size()<<std::endl;
  for(size_t i =0; i < (*hlt_trigResult).size() ; i++) {
    std::string trigname = (*hlt_trigName)[i];
    size_t foundEle00=trigname.find(TRIGNAME);//HLT_DoubleEle33
    if ( foundEle00==std::string::npos) continue;
    
    if(false) std::cout <<"trigger name = "<<trigname
             <<" status = "<<(*hlt_trigResult)[i]<<std::endl;
    triggerstat=(*hlt_trigResult)[i];
  }
  return triggerstat;
}
