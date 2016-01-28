#include <vector>
#include <string>
#include <iostream>
#include <TH1D.h>
#include <TMath.h>
#include <TFile.h>
#include <TClonesArray.h>
#include <TLorentzVector.h>
#include "../untuplizer.h"
#include "../readSample.h"
#include <ctime>
void untuplizer_AccEff(std::string inputFile, std::string outputFile){

  time_t start, end;
  time(&start);

  TString OUTPUTFILENAME(outputFile);
  
  TFile outFile(OUTPUTFILENAME, "recreate");
  

  //read the ntuple
   std::vector<string> infiles;
   if(inputFile.find(".root") != std::string::npos )
     infiles.push_back(inputFile.data());
   TreeReader data(infiles);
   //   std::cout << "Input file is :" << inputFile << std::endl;
   
   //Declare Histrogram
   int mcw =-999;
   Float_t bins[] ={15,20,25,30,35,40,45,50,55,60,64,68,72,76,81,86,91,96,101,106,110,115,120,126,133,141,150,160,171,185,200,220,243,273,320,380,440,510,600,700,830,1000,1200,1500,2000,3000};  
   Int_t  binnum = sizeof(bins)/sizeof(Float_t) - 1; // or just = 9
   TH1F *h_total = new TH1F("h_total", "h_total", binnum,bins);
   TH1F *h_ZMass = new TH1F("h_ZMass", "h_ZMass", binnum,bins);
   TH1F *h_ZMass_Acc_Reco = new TH1F("h_ZMass_Acc_Reco", "h_ZMass_Acc_Reco", binnum,bins);
   TH1F *h_ZMass_Acc_Gen = new TH1F("h_ZMass_Acc_Gen", "h_ZMass_Acc_Gen", binnum,bins);
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
   TH1F *h_leadpt_500 = new TH1F("h_leadpt_500","h_leadpt_500",2000., 0., 2000.);
   TH1F *h_subleadpt_500 = new TH1F("h_subleadpt_500","h_subleadpt_500",2000., 0., 2000.);
   TH1F *h_leadeta_500 = new TH1F("h_leadeta_500", "h_leadeta_500", 120,-6.,6.);
   TH1F *h_subleadeta_500=new TH1F("h_subleadeta_500", "h_leasubdeta_500", 120,-6.,6.);
   TH1F *h_leadpt_700 = new TH1F("h_leadpt_700","h_leadpt_700",2000., 0., 2000.);
   TH1F *h_subleadpt_700 = new TH1F("h_subleadpt_700","h_subleadpt_700",2000., 0., 2000.);
   TH1F *h_leadeta_700 = new TH1F("h_leadeta_700", "h_leadeta_700", 120,-6.,6.);
   TH1F *h_subleadeta_700=new TH1F("h_subleadeta_700", "h_leasubdeta_700", 120,-6.,6.);
   TH1F *h_leadpt_800 = new TH1F("h_leadpt_800","h_leadpt_800",2000., 0., 2000.);
   TH1F *h_subleadpt_800 = new TH1F("h_subleadpt_800","h_subleadpt_800",2000., 0., 2000.);
   TH1F *h_leadeta_800 = new TH1F("h_leadeta_800", "h_leadeta_800", 120,-6.,6.);
   TH1F *h_subleadeta_800=new TH1F("h_subleadeta_800", "h_leasubdeta_800", 120,-6.,6.);

  TH1F *h_totalleadpt = new TH1F("h_totalleadpt","h_totalleadpt",2000., 0., 2000.);
   TH1F *h_totalsubleadpt = new TH1F("h_totalsubleadpt","h_totalsubleadpt",2000., 0., 2000.); 
   TH1F *h_leadpt = new TH1F("h_leadpt","h_leadpt",2000., 0., 2000.);
   TH1F *h_subleadpt = new TH1F("h_subleadpt","h_subleadpt",2000., 0., 2000.);
   TH1F *h_totalleadpt = new TH1F("h_accleadpt","h_accleadpt",2000., 0., 2000.);
   TH1F *h_totalleadpt = new TH1F("h_accleadpt","h_accleadpt",2000., 0., 2000.);
   TH1F *h_effleadpt = new TH1F("h_effleadpt","h_effleadpt",2000., 0., 2000.);
   TH1F *h_effleadpt = new TH1F("h_effleadpt","h_effleadpt",2000., 0., 2000.);
      
   
   std::vector<Int_t> recoindex;
   Bool_t triggerstatus;
   Bool_t triggerstatusDE;
   
   
   Bool_t Zee = false;
   Int_t nGenele = 0;
   TLorentzVector* FSRele1;
   TLorentzVector* FSRele2;  
   TLorentzVector FSRtwo;
   Int_t nZMass_Acc_Gen =0;
   Int_t nZMass_Acc_Reco =0;
   Int_t nZMass_Trig =0;
   Int_t nZMass_TrigDE =0;
   Int_t nZMass_ID =0;
   Int_t nZMass_HEEPID=0;
   Int_t nZMass_HEEPID_NoIso =0; 
   
   
   Int_t nZMass_AE=0;
   Int_t nZMass_AE_DETrig=0;    
   Int_t nZMass_AE_Trig_HEEP =0;
   Int_t nZMass_AE_Trig_HEEP_NoIso =0;    
   Int_t nZMass_AE_DETrig_HEEP_NoIso =0;
   Int_t nZMass_AE_DETrig_HEEP =0;
   
   std::vector<Int_t> index;
   
   for( Long64_t ev = 0; ev < data.GetEntriesFast(); ev++ ){
     
     //  if( ev % 1000000 == 0 )
     //      fprintf(stderr, "Processing event %lli of %lli\n", ev + 1, data.GetEntriesFast());
     
     data.GetEntry(ev);
     
     //     Intialization
     
     Zee = false;
     FSRele1 = new TLorentzVector();
     FSRele2 = new TLorentzVector();
     triggerstatus = false;
     triggerstatusDE = false;
     nZMass_Acc_Gen =0;
     nZMass_Acc_Reco =0;
     recoindex.clear();
     
     nGenele =0;
     
     
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

     Float_t mcWeight = data.GetFloat("mcWeight");
    TClonesArray* genParP4 = (TClonesArray*) data.GetPtrTObject("genParP4");
    TClonesArray* eleP4 = (TClonesArray*) data.GetPtrTObject("eleP4");
    Int_t* genParSt=data.GetPtrInt("genParSt");  
    Int_t* genParId=data.GetPtrInt("genParId");
    Int_t* genStFlag=data.GetPtrInt("genStFlag");
    Int_t nGenPar = data.GetInt("nGenPar");
    Int_t nEle = data.GetInt("nEle");
    vector<bool>& eleIsPassMedium = *((vector<bool>*) data.GetPtr("eleIsPassMedium")); 
    vector<bool>& eleIsPassHEEP = *((vector<bool>*) data.GetPtr("eleIsPassHEEPNoIso")); 
    vector<bool>& eleIsPassHEEPNoIso = *((vector<bool>*) data.GetPtr("eleIsPassHEEPNoIso")); 
    std::string* hlt_trigName = data.GetPtrString("hlt_trigName");
    vector<bool> &hlt_trigResult = *((vector<bool>*) data.GetPtr("hlt_trigResult"));
    const Int_t nsize = data.GetPtrStringSize(); 

   
    if(mcWeight < 0) mcw=-1;                                                                                                          
    if(mcWeight > 0) mcw=1; 
    
    //triggerstatus = TriggerStatus("HLT_Ele22_eta2p1_WP75_Gsf_v");
    //triggerstatusDE = TriggerStatus("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
    
    
    for(Int_t i =0; i < nsize ; i++) {
      std::string trigname = hlt_trigName[i];
      bool results = hlt_trigResult[i];
      
      if(trigname.find("HLT_Ele22_eta2p1_WP75_Gsf_v") != std::string::npos && results == true ){
	triggerstatus = true;
      } 
      
      if(trigname.find("HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ") != std::string::npos && results == true ){
	triggerstatusDE = true;
      }
    }
    
    // For PostFSR isPrompt() ans is FinalState()  FromHardProcessFinalState
    recoindex.clear();    
    for (int i=0; i< nGenPar; i++){
      TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
      if( genParSt[i] == 1 && ((genStFlag[i] >> 9 ) & 1) && fabs(genParId[i]) ==11){   
	nGenele++;
	if (nGenele ==1 ){FSRele1 = (TLorentzVector*) genParP4->At(i);}
	if (nGenele ==2 ){FSRele2 = (TLorentzVector*) genParP4->At(i);}
	
	Double_t gen_Pt =  fourmom->Pt();
	Double_t gen_eta = fourmom->Eta();
	Double_t gen_phi = fourmom->Phi();
	//matching
	Int_t i_matched = -1;
	Double_t dPtMin = 1e10;
        for(Int_t j=0; j< nEle; j++){
	  TLorentzVector* fourmomreco = (TLorentzVector*) eleP4->At(j);
	  Double_t reco_Pt = fourmomreco->Pt();
	  Double_t reco_eta = fourmomreco->Eta();
	  Double_t reco_phi = fourmomreco->Phi();
	  
	  Double_t dR = sqrt( (gen_eta-reco_eta)*(gen_eta-reco_eta) + (gen_phi-reco_phi)*(gen_phi-reco_phi) );
	  Double_t dPt = fabs(gen_Pt - reco_Pt);
	  if( dR < 0.3 ){
	    if(dPt < dPtMin ){
              i_matched = j;
	      dPtMin = dPt;
	    }
	  }
	}
	if(i_matched != -1)recoindex.push_back(i_matched);
      }
    }
    if(nGenele >= 2){
      FSRtwo = *FSRele1 + *FSRele2;
      Zee = true;
      h_ZMass->Fill(FSRtwo.M(),mcw);
      
      if(FSRtwo.M() >= 500.  && FSRtwo.M() < 700.){
	h_leadpt_500->Fill(FSRele1->Pt());
	h_subleadpt_500->Fill(FSRele2->Pt());
	h_leadeta_500->Fill(FSRele1->Eta());
	h_subleadeta_500->Fill(FSRele2->Eta());
      }
      if(FSRtwo.M() >= 700.  && FSRtwo.M() < 800.){
	h_leadpt_700->Fill(FSRele1->Pt());
	h_subleadpt_700->Fill(FSRele2->Pt());
	h_leadeta_700->Fill(FSRele1->Eta());
	h_subleadeta_700->Fill(FSRele2->Eta());
      }
      if(FSRtwo.M() >= 800){
	h_leadpt_800->Fill(FSRele1->Pt());
	h_subleadpt_800->Fill(FSRele2->Pt());
	h_leadeta_800->Fill(FSRele1->Eta());
	h_subleadeta_800->Fill(FSRele2->Eta());
      }
    }
       
    if(Zee == false ){continue;}
    if(FSRtwo.M() >= 200.){continue;}
    h_total->Fill(FSRtwo.M(),mcw); 

    //Gen Level acceptance
      index.clear();
      for (int i=0; i< nGenPar; i++){
	TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
        if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && genParSt[i] == 1 && ((genStFlag[i] >> 9 ) & 1) && fabs(genParId[i]) ==11){   
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


     
      int nmatched = recoindex.size();
      if(nmatched <= 0)continue;


      //RecoLevel acceptance
      index.clear();
      for(Int_t j=0; j< nmatched; j++){
	TLorentzVector* fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)){
	  nZMass_Acc_Reco++;
          index.push_back(recoindex[j]);
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
      for(Int_t j=0; j< nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && triggerstatus){
	  index.push_back(recoindex[j]); 
    	  nZMass_Trig++;
	  
	}
      }
      if(nZMass_Trig >= 2) {
        TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
        if(fourmomlead->Pt() > 25.){
	  h_ZMass_Trig->Fill(FSRtwo.M(),mcw);
	}
      }
      //Double ElectronTrigger
      index.clear();
      for(Int_t j=0; j< nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && triggerstatusDE){
	  index.push_back(recoindex[j]); 
	  nZMass_TrigDE++;
	}
      }
      
      if(nZMass_TrigDE >= 2) {
        TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
        if(fourmomlead->Pt() > 25.){
	  h_ZMass_TrigDE->Fill(FSRtwo.M(),mcw);
	}
      }
      //ID
      index.clear();
       for(Int_t j=0; j< nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && eleIsPassMedium[recoindex[j]]==1){
	  index.push_back(recoindex[j]); 
	  nZMass_ID++;
	}
      }
      if(nZMass_ID >= 2) {
        TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
        if(fourmomlead->Pt() > 25.){
	  h_ZMass_ID->Fill(FSRtwo.M(),mcw);
	}
      }
      //HEEP ID
      index.clear();
      for(Int_t j=0; j< nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && eleIsPassHEEP[recoindex[j]]==1){
	  index.push_back(recoindex[j]); 
	  nZMass_HEEPID++;
	}
      }
      if(nZMass_HEEPID >= 2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.){
	  h_ZMass_HEEPID->Fill(FSRtwo.M(),mcw);
	}
      }

      // HEEP ID NO Is
      
      index.clear();
      for(Int_t j=0; j< nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && eleIsPassHEEPNoIso[recoindex[j]]==1){
	  index.push_back(recoindex[j]); 
	  nZMass_HEEPID_NoIso++;
	}
      }
      if(nZMass_HEEPID_NoIso >= 2) {
        TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
        if(fourmomlead->Pt() > 25.){
	  h_ZMass_HEEPID_NoIso->Fill(FSRtwo.M(),mcw);
	}
      }


       // Acc and  Eff
      //for (int i=0; i< nGenPar; i++){
      //if((*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){
      index.clear();
      for(Int_t j=0; j<  nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatus &&  eleIsPassMedium[recoindex[j]]==1  ){
	  index.push_back(recoindex[j]);
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
      for(Int_t j=0; j<  nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  eleIsPassMedium[recoindex[j]]==1  ){
	  index.push_back(recoindex[j]);
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
      for(Int_t j=0; j<  nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  eleIsPassHEEP[recoindex[j]]==1  ){
	  index.push_back(recoindex[j]);
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
      for(Int_t j=0; j<  nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatusDE &&  eleIsPassHEEPNoIso[recoindex[j]]==1  ){
	  index.push_back(recoindex[j]);
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
      for(Int_t j=0; j<  nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatus &&  eleIsPassHEEP[recoindex[j]]==1  ){
	  index.push_back(recoindex[j]);
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
      for(Int_t j=0; j<  nmatched; j++){
	TLorentzVector*  fourmom = (TLorentzVector*) eleP4->At(recoindex[j]);
	if(fourmom->Pt() > 15.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566)
	   && triggerstatus &&  eleIsPassHEEPNoIso[recoindex[j]]){
	  index.push_back(recoindex[j]);
	  nZMass_AE_Trig_HEEP_NoIso++;
	}
      }
      if(nZMass_AE_Trig_HEEP_NoIso>=2) {
	TLorentzVector*  fourmomlead = (TLorentzVector*) eleP4->At(index[0]);
	if(fourmomlead->Pt() > 25.)  {
	  h_ZMass_AE_Trig_HEEP_NoIso->Fill(FSRtwo.M(),mcw);
	} 
      } 
      //    cout << Zee <<std::endl;
      
   }
   
   outFile.cd();
   h_ZMass->Write();
   h_ZMass_Acc_Reco->Write();
   h_ZMass_Acc_Gen->Write();
   
   h_ZMass_Trig->Write();
   h_ZMass_TrigDE->Write();
   
   h_ZMass_HEEPID_NoIso->Write();
   h_ZMass_ID->Write();
   h_ZMass_HEEPID->Write();
   
   h_ZMass_AE->Write();
   h_ZMass_AE_DETrig->Write();
   h_ZMass_AE_Trig_HEEP->Write();
   h_ZMass_AE_Trig_HEEP_NoIso->Write();
   h_ZMass_AE_DETrig_HEEP->Write();
   h_ZMass_AE_DETrig_HEEP_NoIso->Write();   
   
   
   h_leadpt_500->Write();
   h_subleadpt_500->Write();
   h_leadeta_500->Write();
   h_subleadeta_500->Write();
   
   h_leadpt_800->Write();
   h_subleadpt_800->Write();
   h_leadeta_800->Write();
   h_subleadeta_800->Write();
   
   h_leadpt_700->Write();
   h_subleadpt_700->Write();
   h_leadeta_700->Write();
   h_subleadeta_700->Write();

   h_total->Write();   
   outFile.Write();
   time(&end);
   std::cout<<" time used  = "<<end-start<<" seconds"<<std::endl;
   
   
}



