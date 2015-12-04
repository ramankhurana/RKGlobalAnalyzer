#define EffandAcc_cxx
#include "EffandAcc.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <ctime>

void EffandAcc::Loop()
{
  time_t start, end;
  time(&start);

  if (fChain == 0) return;
   TFile efile (OutputFileName,"recreate");

   int mcw =-999;

   Float_t bins[] ={15,20,25,30,35,40,45,50,55,60,64,68,72,76,81,86,91,96,101,106,110,115,120,126,133,141,150,160,171,185,200,220,243,273,320,380,440,510,600,700,830,1000,1200,1500,2000,3000};  
   Int_t  binnum = sizeof(bins)/sizeof(Float_t) - 1; // or just = 9
   

   TH1F *h_ZMass = new TH1F("h_ZMass", "h_ZMass", binnum,bins);
   TH1F *h_ZMass_Acc_Reco = new TH1F("h_ZMass_Acc_Reco", "h_ZMass_Acc_Reco", binnum,bins);
   TH1F *h_ZMass_Acc_Gen = new TH1F("h_ZMass_Acc_Gen", "h_ZMass_Acc_Gen", binnum,bins);

   TH1F *h_ZMass_Eff = new TH1F("h_ZMass_Eff", "h_ZMass_Eff", binnum,bins);
   TH1F *h_ZMass_Eff_DETrig = new TH1F("h_ZMass_Eff_DETrig", "h_ZMass_Eff_DETrig", binnum,bins);
   TH1F *h_ZMass_Eff_Trig_HEEP= new TH1F("h_ZMass_Eff_Trig_HEEP","h_ZMass_Eff_Trig_HEEP",binnum,bins);
   TH1F *h_ZMass_Eff_Trig_HEEP_NoIso= new TH1F("h_ZMass_Eff_Trig_HEEP_NoIso","h_ZMass_Eff_Trig_HEEP_NoIso",binnum,bins);
   TH1F *h_ZMass_Eff_DETrig_HEEP= new TH1F("h_ZMass_Eff_DETrig_HEEP","h_ZMass_Eff_DETrig_HEEP",binnum,bins);
   TH1F *h_ZMass_Eff_DETrig_HEEP_NoIso= new TH1F("h_ZMass_Eff_DETrig_HEEP_NoIso","h_ZMass_Eff_DETrig_HEEP_NoIso",binnum,bins);

   TH1F *h_ZMass_Trig = new TH1F("h_ZMass_Trig","h_ZMass_Trig",binnum,bins);
   TH1F *h_ZMass_TrigDE =new TH1F("h_ZMass_TrigDE","h_ZMass_TrigDE",binnum,bins);

   TH1F *h_ZMass_ID= new TH1F("h_ZMass_ID","h_ZMass_ID",binnum,bins);
   TH1F *h_ZMass_HEEPID= new TH1F("h_ZMass_HEEPID", "h_ZMass_HEEPID",binnum,bins);
   TH1F *h_ZMass_HEEPID_NoIso= new TH1F("h_ZMass_HEEPID_NoIso", "h_ZMass_HEEPID_NoIso",binnum,bins);  

   TH1F *h_ZMass_AE=new TH1F("h_ZMass_AE", "h_ZMass_AE", binnum,bins);
   TH1F *h_ZMass_AE_DETrig=new TH1F("h_ZMass_AE_DETrig", "h_ZMass_AE_DETrig", binnum,bins); 
   TH1F *h_ZMass_AE_Trig_HEEP= new TH1F("h_ZMass_AE_Trig_HEEP","h_ZMass_AE_Trig_HEEP",binnum,bins);
   TH1F *h_ZMass_AE_Trig_HEEP_NoIso= new TH1F("h_ZMass_AE_Trig_HEEP_NoIso","h_ZMass_AE_Trig_HEEP_NoIso",binnum,bins);
   TH1F *h_ZMass_AE_DETrig_HEEP= new TH1F("h_ZMass_AE_DETrig_HEEP","h_ZMass_AE_DETrig_HEEP",binnum,bins);
   TH1F *h_ZMass_AE_DETrig_HEEP_NoIso= new TH1F("h_ZMass_AE_DETrig_HEEP_NoIso","h_ZMass_AE_DETrig_HEEP_NoIso",binnum,bins);
      

   bool triggerstatus;
   bool triggerstatusDE;
   
   bool Zee = false;
   int nGenele = 0;
   TLorentzVector* FSRele1;
   TLorentzVector* FSRele2;  
   TLorentzVector FSRtwo;
   int nZMass_Acc_Gen =0;
   int nZMass_Acc_Reco =0;
   
   int nZMass_Eff=0;
   int nZMass_Eff_DETrig=0;    
   int nZMass_Eff_Trig_HEEP =0;
   int nZMass_Eff_Trig_HEEP_NoIso =0;    
   int nZMass_Eff_DETrig_HEEP_NoIso =0;
   int nZMass_Eff_DETrig_HEEP =0;
   
   int nZMass_Trig =0;
   int nZMass_TrigDE =0;
   int nZMass_ID =0;
   int nZMass_HEEPID=0;
   int nZMass_HEEPID_NoIso =0; 
   

   int nZMass_AE=0;
   int nZMass_AE_DETrig=0;    
   int nZMass_AE_Trig_HEEP =0;
   int nZMass_AE_Trig_HEEP_NoIso =0;    
   int nZMass_AE_DETrig_HEEP_NoIso =0;
   int nZMass_AE_DETrig_HEEP =0;
   
   std::vector<int> index;
   
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
    
      //Initialization

      Zee = false;
      FSRele1 = new TLorentzVector();
      FSRele2 = new TLorentzVector();
      // FSRtwo = new TLorentzVector();  
      triggerstatus = false;
      triggerstatusDE = false;
      nZMass_Acc_Gen =0;
      nZMass_Acc_Reco =0;
     
     
      nGenele =0;
      nZMass_Eff =0;
      nZMass_Eff_DETrig =0;
      nZMass_Eff_Trig_HEEP =0;
      nZMass_Eff_Trig_HEEP_NoIso =0;    
      nZMass_Eff_DETrig_HEEP_NoIso =0;
      nZMass_Eff_DETrig_HEEP =0;

      nZMass_AE =0;
      nZMass_AE_DETrig =0;
      nZMass_AE_Trig_HEEP =0;
      nZMass_AE_Trig_HEEP_NoIso =0;    
      nZMass_AE_DETrig_HEEP_NoIso =0;
      nZMass_AE_DETrig_HEEP =0;


      nZMass_Trig =0;
      nZMass_TrigDE =0;
      nZMass_ID =0;
      nZMass_HEEPID=0;
      nZMass_HEEPID_NoIso =0; 

      
      if(mcWeight < 0) mcw=1;                                                                                                                
      if(mcWeight > 0) mcw=1; 

      // For PostFSR isPrompt() ans is FinalState()
      triggerstatus = TriggerStatus("HLT_Ele22_eta2p1_WP75_Gsf_v");
      triggerstatusDE = TriggerStatus("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
    
     
      for (int i=0; i< nGenPar; i++){
	TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
        if((*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){   
	  nGenele++;
	  if (nGenele ==1 ){FSRele1 = (TLorentzVector*) genParP4->At(i);}
	  if (nGenele ==2 ){FSRele2 = (TLorentzVector*) genParP4->At(i);}
	}
      }
      if(nGenele >= 2){
	Zee = true;
	FSRtwo = *FSRele1 + *FSRele2;
	h_ZMass->Fill(FSRtwo.M(),mcw);
      }
      

      if(Zee == false){continue;}
      
      
      //Gen Level Acc
      index.clear();
      for (int i=0; i< nGenPar; i++){
	TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
        if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && (*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){   
	  nZMass_Acc_Gen++;
	  index.push_back(i);
	}
      }
      if(nZMass_Acc_Gen >=2){
        TLorentzVector*  fourmomlead = (TLorentzVector*) genParP4->At(index[0]);
        TLorentzVector*  fourmomsublead = (TLorentzVector*) genParP4->At(index[1]);
	if(fourmomlead->Pt() > 25. || fourmomsublead->Pt() >25){
	  h_ZMass_Acc_Gen->Fill(FSRtwo.M(),mcw);
	}
      }
      
      //Reco Level Acc
      //for (int i=0; i< nGenPar; i++){
      //      if((*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){
index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector* fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)){
	  nZMass_Acc_Reco++;
          index.push_back(j);
	}
      }
      if(nZMass_Acc_Reco>=2){
        TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
        if(fourmomlead->Pt() > 25.){
	  h_ZMass_Acc_Reco->Fill(FSRtwo.M(),mcw);
	}
      }

      
      
      // Trigger
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatus){
	  nZMass_Trig++;
	}
      }
      if(nZMass_Trig >= 2) {
	h_ZMass_Trig->Fill(FSRtwo.M(),mcw);
      }
//Double ElectronTrigger
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatusDE){
	  nZMass_TrigDE++;
	}
      }
      if(nZMass_TrigDE >= 2) {
	h_ZMass_TrigDE->Fill(FSRtwo.M(),mcw);
      }

      //ID
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if((*eleIsPassMedium)[j]==1){
	  nZMass_ID++;
	}
      }
      if(nZMass_ID >= 2) {
	h_ZMass_ID->Fill(FSRtwo.M(),mcw);
      }

      //HEEP ID
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if((*eleIsPassHEEP)[j]==1){
	  nZMass_HEEPID++;
	}
      }
      if(nZMass_HEEPID >= 2) {
	h_ZMass_HEEPID->Fill(FSRtwo.M(),mcw);
      }

      // HEEP ID NO Is

      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if((*eleIsPassHEEPNoIso)[j]==1){
	  nZMass_HEEPID_NoIso++;
	}
      }
      if(nZMass_HEEPID_NoIso >= 2) {
	h_ZMass_HEEPID_NoIso->Fill(FSRtwo.M(),mcw);
      }

     

      //Eff
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatus &&  (*eleIsPassMedium)[j]==1  ){
	  nZMass_Eff++;
	}
      }
      if(nZMass_Eff>=2) {
	 h_ZMass_Eff->Fill(FSRtwo.M(),mcw);
      }  

      // Eff  DE Trig
  
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatusDE &&  (*eleIsPassMedium)[j]==1  ){
	  nZMass_Eff_DETrig++;
	}
      }
      if(nZMass_Eff_DETrig >=2) {
	 h_ZMass_Eff_DETrig->Fill(FSRtwo.M(),mcw);
      }  
      

      // Eff Trig //HEEP ID
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatus &&  (*eleIsPassHEEP)[j]==1  ){
	  nZMass_Eff_Trig_HEEP++;
	}
      }
      if(nZMass_Eff_Trig_HEEP>=2) {
	 h_ZMass_Eff_Trig_HEEP->Fill(FSRtwo.M(),mcw);
      } 

      // Eff Trig //HEEP ID No Iso
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatus &&  (*eleIsPassHEEPNoIso)[j]==1  ){
	  nZMass_Eff_Trig_HEEP_NoIso++;
	}
      }
      if(nZMass_Eff_Trig_HEEP_NoIso>=2) {
	 h_ZMass_Eff_Trig_HEEP_NoIso->Fill(FSRtwo.M(),mcw);
      }  
      //Eff DE Trig  HEEP ID No Iso
     index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatusDE &&  (*eleIsPassHEEP)[j]==1  ){
	  nZMass_Eff_DETrig_HEEP++;
	}
      }
      if(nZMass_Eff_DETrig_HEEP>=2) {
	 h_ZMass_Eff_DETrig_HEEP->Fill(FSRtwo.M(),mcw);
      } 

      // Eff DE Trig //HEEP ID No Iso
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(triggerstatusDE &&  (*eleIsPassHEEPNoIso)[j]==1  ){
	  nZMass_Eff_DETrig_HEEP_NoIso++;
	}
      }
      if(nZMass_Eff_DETrig_HEEP_NoIso>=2) {
	h_ZMass_Eff_DETrig_HEEP_NoIso->Fill(FSRtwo.M(),mcw);
      }  
   


      // Acc and  Eff
      //for (int i=0; i< nGenPar; i++){
      //if((*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatus &&  (*eleIsPassMedium)[j]==1  ){
	  index.push_back(j);
	  nZMass_AE++;
	}
      }
      if(nZMass_AE>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE->Fill(FSRtwo.M(),mcw);
	} 
      }


      //DE acc Eff
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  (*eleIsPassMedium)[j]==1  ){
	  index.push_back(j);
	  nZMass_AE_DETrig++;
	}
      }
      if(nZMass_AE_DETrig>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE_DETrig->Fill(FSRtwo.M(),mcw);
	} 
      }

      //DE Acc and Eff HEEP ID
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  (*eleIsPassHEEP)[j]==1  ){
	  index.push_back(j);
	  nZMass_AE_DETrig_HEEP++;
	}
      }
      if(nZMass_AE_DETrig_HEEP>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE_DETrig_HEEP->Fill(FSRtwo.M(),mcw);
	} 
      }      

      // DE acc and Eff HEEP NO ISO
     index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  (*eleIsPassHEEPNoIso)[j]==1  ){
	  index.push_back(j);
	  nZMass_AE_DETrig_HEEP_NoIso++;
	}
      }
      if(nZMass_AE_DETrig_HEEP_NoIso>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE_DETrig_HEEP_NoIso->Fill(FSRtwo.M(),mcw);
	} 
      } 



      // Acc and Eff HEEP ID
      index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatus &&  (*eleIsPassHEEP)[j]==1  ){
	  index.push_back(j);
	  nZMass_AE_Trig_HEEP++;
	}
      }
      if(nZMass_AE_Trig_HEEP>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE_Trig_HEEP->Fill(FSRtwo.M(),mcw);
	} 
      }      

      //  acc and Eff HEEP NO ISO
     index.clear();
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatus &&  (*eleIsPassHEEPNoIso)[j]==1  ){
	  index.push_back(j);
	  nZMass_AE_Trig_HEEP_NoIso++;
	}
      }
      if(nZMass_AE_Trig_HEEP_NoIso>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE_Trig_HEEP_NoIso->Fill(FSRtwo.M(),mcw);
	} 
      } 




      /*
     

      //DE Eff
      // for (int i=0; i< nGenPar; i++){
      //	if((*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){
      index.clear();      
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  (*eleIsPassMedium)[j]==1  ){
	  nZMass_Eff_DETrig++;
	  index.push_back(j);
	}
      }
      if(nZMass_Eff_DETrig >= 2){
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.){
	h_ZMass_Eff_DETrig->Fill(FSRtwo.M(),mcw);
	}
      }

      // Heep ID 
      index.clear();      
      for(size_t j=0; j<(size_t) nEle; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(j);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  (*eleIsPassHEEP)[j]==1  ){
	  nZMass_Eff_Trig_HEEP++;
	  index.push_back(j);
	}
      }
      if(nZMass_Eff_Trig_HEEP >= 2){
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.){
	h_ZMass_Eff_Trig_HEEP->Fill(FSRtwo.M(),mcw);
	}
      }
      */
      
   }
   efile.cd();
   h_ZMass->Write();
   h_ZMass_Acc_Reco->Write();
   h_ZMass_Acc_Gen->Write();

   h_ZMass_Trig->Write();
   h_ZMass_TrigDE->Write();

   h_ZMass_HEEPID_NoIso->Write();
   h_ZMass_ID->Write();
   h_ZMass_HEEPID->Write();

   h_ZMass_Eff->Write();
   h_ZMass_Eff_DETrig->Write();
   h_ZMass_Eff_Trig_HEEP->Write();
   h_ZMass_Eff_Trig_HEEP_NoIso->Write();
   h_ZMass_Eff_DETrig_HEEP->Write();
   h_ZMass_Eff_DETrig_HEEP_NoIso->Write();   


   h_ZMass_AE->Write();
   h_ZMass_AE_DETrig->Write();
   h_ZMass_AE_Trig_HEEP->Write();
   h_ZMass_AE_Trig_HEEP_NoIso->Write();
   h_ZMass_AE_DETrig_HEEP->Write();
   h_ZMass_AE_DETrig_HEEP_NoIso->Write();   

   efile.Close();

   time(&end);
   std::cout<<" time used  = "<<end-start<<" seconds"<<std::endl;
}
bool EffandAcc::TriggerStatus(std::string TRIGNAME){
  bool triggerstat=false;
  // std::cout <<" number of triggers = "<<(*hlt_trigResult).size()<<std::endl;
  for(size_t i =0; i < (*hlt_trigResult).size() ; i++) {

    std::string trigname = (*hlt_trigName)[i];
    size_t foundEle00=trigname.find(TRIGNAME);//HLT_DoubleEle33                                                                               
     
    if ( foundEle00==std::string::npos) continue;

    //std::cout <<"trigger name = "<<trigname
    //	<<" status = "<<(*hlt_trigResult)[i]<<std::endl;
    triggerstat=(*hlt_trigResult)[i];
  }
  return triggerstat;
}
