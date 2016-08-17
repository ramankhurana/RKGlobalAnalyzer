#include <vector>
#include <ctime>
#include <iostream>
#include <TString.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TSystemDirectory.h>
#include <TClonesArray.h>
#include <TLorentzVector.h>
#include <TList.h>
#include "untuplizer.h"
#include <fstream>
#include <map>
#include <TFile.h>
//#include "setNCUStyle.C"
#include <math.h>
#include <sstream>
#include <Sample.h>
#include <TProfile.h>

vector<string> split(TString str, char delimiter) {
  vector<string> internal;
  string str_ = string(str);
  stringstream ss(str_); 
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}


void subjStudy(int analysisid){
  bool CMSSW74 = false;
  time_t start, end;
  time(&start);
  
  // -----------------------------------
  // Define Histograms 
  // -----------------------------------
  for(int i=0; i<(int) Sample::fileNameFullSample().size(); i++){
    const int nobjectmet=2;
    TH1F*    h_cutFlow;
    TH1F*    h_nMuons;
    TH1F*    h_nTaus;
    TH1F*    h_nElectrons;
    TH1F*    h_nJets;
    TH1F*    h_nFJets;
    TH1F*    h_NThinJets;
    TH1F*    h_dPhiThinJetMET;
    TH1F*    h_DRSJ;
    TH1F*    h_Q1Q2;
    TH1F*    h_MET;
    TH1F*    h_MET_Sys[7];
    TH1F*    h_MET_PDF[101];
    TProfile* h_MET_PDFProfile;
    TH1F*    h_MHT;
    TH1F*    h_Mjj;
    TH1F*    h_Mjj_Rebin;
    TH1F*    h_pTjj;
    TH1F*    h_etajj;
    TH1F*    h_phijj;
    TH1F*    h_Tau21jj;
    TH1F*    h_CSVMax;
    TH1F*    h_CSVMin;
    TH1F*    h_CSV1;
    TH1F*    h_CSV2;
    TH1F*    h_CSVSum;
    TH1F*    h_dPhi_MET_J;
    TH1F*    h_MT_bb_MET;
    TH1F*    h_dPhi_bb_MET;
    
    TH1F*    h_MET_Over_SumET;
    TH1F*    h_MET_Over_pTFatJet;
    TH1F*    h_CEmEF;
    TH1F*    h_CHadEF;
    TH1F*    h_PhoEF;
    TH1F*    h_NEmEF;
    TH1F*    h_NHadEF;
    TH1F*    h_MuEF;
    
    TH1F*    h_CMulti;
    TH1F*    h_event;
    
    TString postfix;
    int pf=0;
    
    // -----------------------------------
    // deifne histograms 
    // -----------------------------------
    
    postfix.Form("%d",pf);
    h_cutFlow    = new TH1F("h_cutFlow"+postfix,"h_cutFlow",10,0,10);
    h_nMuons     = new TH1F("h_nMuons"+postfix,"h_nMuons",5,0,5);
    h_nTaus      = new TH1F("h_nTaus"+postfix,"h_nTaus",5,0,5);
    h_nElectrons = new TH1F("h_nElectrons"+postfix,"h_nElectrons",5,0,5);
    h_nJets      = new TH1F("h_nJetss"+postfix,"h_nJetss",5,0,5);
    h_nFJets     = new TH1F("h_nFJets"+postfix,"h_nFJets",5,0,5);
    h_DRSJ       = new TH1F("h_DRSJ"+postfix,"h_DRSJ",100,0,5);
    h_NThinJets  = new TH1F("h_NThinJets"+postfix,"h_NThinJets",10,0,10);
    
    h_dPhiThinJetMET = new TH1F("h_dPhiThinJetMET"+postfix,"h_dPhiThinJetMET",700,-3.5,3.5);
    
    h_Q1Q2       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
    h_MET        = new TH1F("h_MET"+postfix,"h_MET",3000,0,3000);
    
    // -----------------------------------------
    // MET histograms for systematics
    // -----------------------------------------
    TString sys[]={"_Nominal","_muRUp","_muRDown","_muFUp","_muFDown","_EWKUp","_EWKDown"};
    for (int isys=0; isys<7; isys++){
      int nbins = 3;
      float bins[] = {200.,350., 500., 3000.};
      h_MET_Sys[isys]    = new TH1F("h_MET"+postfix+sys[isys], "h_MET", nbins,  bins);
    }

    for (int isys=0; isys<101; isys++){
      int nbins = 3;
      float bins[] = {200.,350., 500., 3000.};
      TString pdf_;
      pdf_.Form("_%d",isys);
      h_MET_PDF[isys]    = new TH1F("h_MET"+postfix+pdf_, "h_MET", nbins,  bins);
    }
    
    int nbins = 3;
    Float_t  bins[] = {200.,350., 500., 3000.};
    
    Float_t massbins[]={30.0,100.,150.,250.};
    h_MET_PDFProfile = new TProfile("h_MET_PDFProfile", "h_MET_PDFProfile", nbins, bins);
    h_MHT        = new TH1F("h_MHT"+postfix,"h_MHT",3000,0,3000);
    h_Mjj        = new TH1F("h_Mjj"+postfix,"",3000,0,3000);
    
    h_Mjj_Rebin  = new TH1F("h_Mjj_Rebin"+postfix,"",nbins, massbins);
    
    h_pTjj       = new TH1F("h_pTjj"+postfix,"",3000,0,3000);
    h_etajj      = new TH1F("h_etajj"+postfix,"",500,-2.5,2.5);
    h_phijj      = new TH1F("h_phijj"+postfix,"",700,-3.5,3.5);
    h_Tau21jj    = new TH1F("h_h_Tau21jj"+postfix,"",20,0.,1.);
    
    h_CSVMax     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
    h_CSVMin     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
    h_CSV1       = new TH1F("h_CSV1"+postfix,"",20,0,1);
    h_CSV2       = new TH1F("h_CSV2"+postfix,"",20,0,1);
    h_CSVSum     = new TH1F("h_CSVSum"+postfix,"",40,0,2);
    h_dPhi_MET_J = new TH1F("h_dPhi_MET_J"+postfix,"",350,0.,3.5);
    h_MT_bb_MET  = new TH1F("h_MT_bb_MET"+postfix,"",5000,0,5000.);
    h_dPhi_bb_MET= new TH1F("h_dPhi_bb_MET"+postfix,"",350,0,3.5);
    
    h_MET_Over_SumET    = new TH1F("h_MET_Over_SumET"+postfix,"",20,0,1.);
    h_MET_Over_pTFatJet = new TH1F("h_MET_Over_pTFatJet"+postfix,"",100,0,5);
    h_CEmEF             = new TH1F("h_CEmEF"+postfix,"",20,0,1);
    h_CHadEF            = new TH1F("h_CHadEF"+postfix,"",20,0,1);
    h_PhoEF             = new TH1F("h_PhoEF"+postfix,"",20,0,1);
    h_NEmEF             = new TH1F("h_NEmEF"+postfix,"",20,0,1);
    h_NHadEF            = new TH1F("h_NHadEF"+postfix,"",20,0,1);
    h_MuEF              = new TH1F("h_MuEF"+postfix,"",20,0,1);
    h_CMulti            = new TH1F("h_CMulti"+postfix,"",20,0,1);
    h_event             = new TH1F("h_event"+postfix,"",100,0,100);
    
    
    // -----------------------------------
    //  set the name of output dir name 
    // -----------------------------------
    TString dirName;
    TString outputdirName ;
    outputdirName = Form("AnalysisHistograms_V%d",analysisid);
    gSystem->mkdir(outputdirName); 
    
    // -----------------------------------
    // Loop over the all control regions 
    // -----------------------------------
    // 1: signal
    // 6: TTBar
    // 23:ZnunuJets  
    // 24: W+Jets
    // 11:One Lepton CR  
    // 21: QCD enriched Signal Region
    std::vector<unsigned int> numbers = {1, 6, 23, 24, 11, 21}; // 11 for HF control region 
    for (int idir=0; idir < (int)numbers.size(); idir++){
      int id = numbers[idir];
      
      //  ------------------------------------------------------------------------
      // Clean the histograms before filling them for naother control region
      // -------------------------------------------------------------------------
      h_cutFlow ->Scale(0.0);
      h_nMuons ->Scale(0.0);
      h_nTaus ->Scale(0.0);
      h_nElectrons->Scale(0.0);
      h_DRSJ ->Scale(0.0);
      h_dPhiThinJetMET->Scale(0.0);
      h_NThinJets ->Scale(0.0);
      h_MET ->Scale(0.0);
      for (int isys=0; isys<7; isys++) {
	h_MET_Sys[isys]->Scale(0.0);
      }

      for (int isys=0; isys<101; isys++) {
	h_MET_PDF[isys]->Scale(0.0);
      }
      h_MET_PDFProfile->Scale(0.0);
      h_MT_bb_MET->Scale(0.0);
      h_Mjj ->Scale(0.0);
      h_Mjj_Rebin ->Scale(0.0);
      h_pTjj ->Scale(0.0);
      h_CSV1->Scale(0.0);
      h_CSV2->Scale(0.0);
      h_etajj ->Scale(0.0);
      h_phijj ->Scale(0.0);
      h_Tau21jj ->Scale(0.0);
      h_CSVMax ->Scale(0.0);
      h_MHT->Scale(0.0);
      
      h_CSVMin ->Scale(0.0);
      h_CSVSum ->Scale(0.0);
      h_dPhi_MET_J ->Scale(0.0);
      h_MET_Over_SumET ->Scale(0.0);
      h_MET_Over_pTFatJet ->Scale(0.0);
      h_CEmEF ->Scale(0.0);
      h_CHadEF ->Scale(0.0);
      h_PhoEF ->Scale(0.0);
      h_NEmEF ->Scale(0.0);
      h_NHadEF ->Scale(0.0);
      h_MuEF ->Scale(0.0);
      h_CMulti ->Scale(0.0);
      h_event->Scale(0.0);
      h_dPhi_bb_MET->Scale(0.0);
      
      // --------------------
      // read input file
      // --------------------
      TFile *inputFile;
      inputFile = new TFile(Sample::fileNameFullSample()[i],"READ");
      
      
      // --------------------
      // clone total event histo
      // --------------------
      TH1F *h = (TH1F *) gDirectory->Get("nEvents_weight");
      TH1F *h_total=(TH1F*)h->Clone();
      h_total->SetName("h_total");
      
      // --------------------
      // get the tree
      // --------------------
      TTree *tree = (TTree*)inputFile->Get("skimTreeMonoHFatJetsPreselection");
      
      
      // --------------------
      // set output file name
      // --------------------
      TString outputFile;
      TString searchFile =  Sample::fileNameFullSample()[i];
      vector<string> fileName = split(searchFile, '/');
      
      outputFile = fileName[7];
      
      cout << "Output file = " << outputFile.Data() << endl;
      
      TreeReader data(tree);
      //setNCUStyle();
      
      int countEvent=0;
      
      // -----------------------------------
      // Loop over the events 
      // -----------------------------------
      for(Long64_t jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){
	if (jEntry % 50000 == 0)
	  fprintf(stderr, "Processing event %lli of %lli\n", jEntry + 1, data.GetEntriesFast());
	data.GetEntry(jEntry);
	
	// -----------------------------------
	// Get all the branches 
	// -----------------------------------
	Int_t           run_        = data.GetInt("Run_");
	Int_t           lumi_       = data.GetInt("Lumi_");
	Int_t          event_      = data.GetInt("Event_");
	
	Float_t         dphiMin_    = data.GetFloat("dphiMin_");
	Int_t           NAddMu_     = data.GetInt("NAddMu_");
	Int_t           NAddEle_    = data.GetInt("NAddEle_");
	Int_t           NAddTau_    = data.GetInt("NAddTau_");
	Int_t           NAddBJet    = data.GetInt("NAddBJet");
	Int_t           nthinjets_  = data.GetInt("nthinjets_");
	Float_t         MinCSV_     = data.GetFloat("MinCSV_");
	Float_t         MaxCSV_     = data.GetFloat("MaxCSV_");
	Float_t         CSV1_     = data.GetFloat("CSV1_");
	Float_t         CSV2_     = data.GetFloat("CSV2_");
	Float_t         DRSJ_       = data.GetFloat("DRSJ_");
	Float_t         Mass_       = data.GetFloat("Mass_");
	Float_t         MT_         = data.GetFloat("MT_");
	Float_t         JetPhi_     = data.GetFloat("JetPhi_");
	Float_t         JetEta_     = data.GetFloat("JetEta_");
	Float_t         JetCSVSum_  = data.GetFloat("JetCSVSum_");
	Float_t         MHT_        = data.GetFloat("MHT_");
	Float_t         JetMetDPhi_ = data.GetFloat("JetMetDPhi_");
	Float_t         Tau21_      = data.GetFloat("Tau21_");
	Float_t         JetPt_      = data.GetFloat("JetPt_");
	Float_t         SumET_      = data.GetFloat("SumET_");
	Float_t         MET_        = data.GetFloat("MET_");
	Float_t         jetCEmEF_   = data.GetFloat("jetCEmEF_");
	Float_t         jetCHadEF_  = data.GetFloat("jetCHadEF_"); 
	Float_t         jetPhoEF_   = data.GetFloat("jetPhoEF_");
	Float_t         jetNEmEF_   = data.GetFloat("jetNEmEF_");
	Float_t         jetNHadEF_  = data.GetFloat("jetNHadEF_");
	Float_t         jetMuEF_    = data.GetFloat("jetMuEF_");
	Float_t         jetCMulti_  = data.GetFloat("jetCMulti_");
	Float_t         MCweight_   = data.GetFloat("MCweight_");
	Float_t         EWKweight_        = data.GetFloat("EWKweight_");
	Float_t         PUweight_         = data.GetFloat("PUweight_");
	Float_t         BTAGSF_           = data.GetFloat("BTAGSF_");
	Float_t         BTAGSFUP_         = data.GetFloat("BTAGSFUP_");
	Float_t         BTAGSFDOWN_       = data.GetFloat("BTAGSFDOWN_");
	Float_t         BTAGLFSFUP_       = data.GetFloat("BTAGLFSFUP_");
	Float_t         BTAGLFSFDOWN_     = data.GetFloat("BTAGLFSFDOWN_");


	Float_t         MuRUp           ;
	Float_t         MuRDown         ;
	Float_t         MuFUp           ;
	Float_t         MuFDown         ;
	Float_t*        SysPDFWeight    ;
	
	const char *str = fileName[7].c_str();
	if(!strstr(str,"Merged_MET")){
	  MuRUp             = data.GetFloat("MuRUp");
	  MuRDown           = data.GetFloat("MuRDown");
	  MuFUp             = data.GetFloat("MuFUp");
	  MuFDown           = data.GetFloat("MuFDown");
	  SysPDFWeight      = data.GetPtrFloat("SysPDFWeight");
	}


	if(strstr(str,"Merged_MET")){
	  MuRUp             = 1.;
	  MuRDown           = 1.;
	  MuFUp             = 1.;
	  MuFDown           = 1.;
	}

	//IN MET Bins > 200 : 0  200-350:1  350-500:2  and 500:3
        int metcat_ = 0;
	if(MET_ > 200 && MET_ <= 350) metcat_ =1;
        if(MET_ > 350 && MET_ <= 500) metcat_ =2;        	
        if(MET_ > 500) metcat_ =3;        	
	//if(metcat_ ==1 || metcat_ == 2 || metcat_ || 3) metcat_ = 0; 
	if (analysisid == 0 ) metcat_ =0;
	

	Float_t btagcut_;
	if(CMSSW74){
	  btagcut_= 0.605;}
	else
	  {btagcut_ = 0.460;} // CMSSW_76
	
	bool eventControl = false;
	
	// ------------
	// set weight 
	// ------------
	
	float weight = 0.0;
	float Sysweights[7]={0.0, 0.0,0.0,0.0,0.0,0.0,0.0};
	
        float PUW =0.0;
        if(CMSSW74){
	  PUW = PUweight_;
	}else{
	  PUW = 1.0;
	}
	
	str = fileName[7].c_str();
	if(strstr(str,"Merged_MET")){
	  Sysweights[0] = 1.0;
	  Sysweights[1] = 1.0;
	  Sysweights[2] = 1.0;
	  Sysweights[3] = 1.0;
	  Sysweights[4] = 1.0;
	  Sysweights[5] = 1.0;
	  Sysweights[6] = 1.0;
	}
        if(!strstr(str,"Merged_MET")){
	  Sysweights[0] = MCweight_ * EWKweight_ * BTAGSF_*PUW; // Nominal
	  Sysweights[1] = MCweight_ * EWKweight_ * BTAGSF_*PUW*MuRUp; // R up
	  Sysweights[2] = MCweight_ * EWKweight_ * BTAGSF_*PUW*MuRDown; // R down
	  Sysweights[3] = MCweight_ * EWKweight_ * BTAGSF_*PUW*MuFUp; // F up
	  Sysweights[4] = MCweight_ * EWKweight_ * BTAGSF_*PUW*MuFDown; // F down
	  Sysweights[5] = MCweight_ * EWKweight_*EWKweight_ * BTAGSF_*PUW; // EWK Up
	  Sysweights[6] = MCweight_ * BTAGSF_*PUW; // EWK Down
	}
	
	float pdfweight_;
	pdfweight_ = EWKweight_ * BTAGSF_*PUW;
	
	
	weight = MCweight_ * EWKweight_ * BTAGSF_*PUW ;
	
	//weight = MCweight_ * EWKweight_ * BTAGLFSFDOWN_*PUW ;
	float weightNoBTag = 0.0;
	weightNoBTag = MCweight_ * EWKweight_*PUW;
	
	// ----------------------
	// for data weight = 1
	// ----------------------
	str = fileName[7].c_str();
	if(strstr(str,"Merged_MET")){ weight = 1.0;
	  weightNoBTag = 1.0;
	}
	
	float dr = DRSJ_;
	bool csvstatus = false;
	//if (dr > 0.3) csvstatus = CSV1_ > btagcut_ && CSV2_ > btagcut_;
	//if (dr < 0.3) csvstatus = CSV1_ > btagcut_ || CSV2_ > btagcut_;
	
	// exactly one sub-jet pasing b-tag
	///csvstatus = (CSV1_ > btagcut_ && CSV2_ < btagcut_ )  || (CSV1_ < btagcut_ && CSV2_ > btagcut_);

	// exactly zero sub-jet pasing b-tag
	//csvstatus = (CSV1_ < btagcut_ && CSV2_ < btagcut_ );

	// exactly two sub-jet pasing b-tag
	csvstatus = (CSV1_ > btagcut_ && CSV2_ > btagcut_ );
	
	// ----------------
	// signal region
	// ----------------
	if(id == 1 && metcat_ == analysisid){
	  h_cutFlow ->Fill(0.,weightNoBTag);
	  
	  if ( dphiMin_ < 0.4) continue;
	  if (MT_ < 450.) continue;
	  h_cutFlow ->Fill(1.,weightNoBTag); //1
	  
	  
	  //if( Mass_>100 && Mass_<150){
	    if( true){
	  h_cutFlow ->Fill(2.,weightNoBTag); //2
	    
	    //if(CSV1_ < btagcut_)continue;
	    //if(CSV2_ < btagcut_)continue;
	    
	    if(!csvstatus) continue;
	    h_cutFlow ->Fill(3.,weight); //3
	    
	    //h_cutFlow ->Fill(4.,weight); //4
	    
	    if((NAddMu_ + NAddEle_ + NAddTau_ )!=0)continue;
	    h_cutFlow ->Fill(4.,weight); //5
	    
	    if(NAddBJet!=0)continue;
	    if(nthinjets_>1) continue;
	    h_cutFlow ->Fill(5.,weight); //6
	    
	    // -----------------
	    // print the run:lumi:event for selected event in signal region. 
	    // -----------------
	    std::cout<<run_<<":"<<lumi_<<":"<<std::endl;
	    
	    if(false) std::cout<<" metcat_ = "<<metcat_
			       <<" PUW = "<<PUW
			       <<" MET = "<<MET_
			       <<" cat = "<<analysisid
			       <<" MCweight_ "<< MCweight_
			       <<" EWKweight_ "<< EWKweight_
			       <<" BTAGSF_ "<< BTAGSF_
			       <<" weight "<<weight
			       <<std::endl;
	    eventControl = true;
	  }
	}
	




	// ----------------
	// signal region with QCD
	// ----------------

	if(id == 21 && metcat_ == analysisid){
	  h_cutFlow ->Fill(0.,weightNoBTag);
	  if((Mass_>30 && Mass_<100) || (Mass_>150 && Mass_<250)){
	    if(!csvstatus) continue;
	    if((NAddMu_ + NAddEle_ + NAddTau_ )!=0)continue;
	    eventControl = true;
	  }
	}
	
	
	// -----------------------------------------
	// signal region in one lepton region
	// Heavy Flavor region ttbar + W+Jets
	// -----------------------------------------
	if(id == 11 && metcat_ == analysisid){
	  h_cutFlow ->Fill(0.,weightNoBTag);
	  
	  if ( dphiMin_ < 0.4) continue;
          if (MT_ < 450.) continue;
          h_cutFlow ->Fill(1.,weightNoBTag); //1                                                                                                                                     
	  
	  if( Mass_>30 && Mass_<250){
	    h_cutFlow ->Fill(2.,weightNoBTag); //2
	    
	    //if(CSV1_ < btagcut_)continue;
	    //if(CSV2_ < btagcut_)continue;
	    if(!csvstatus) continue;
	    h_cutFlow ->Fill(3.,weight); //3
	    
	    
	    //if(NAddBJet!=0)continue;
	    //h_cutFlow ->Fill(4.,weight); //4
	    
	    if( (NAddMu_ + NAddEle_ ) != 1 )continue;
	    h_cutFlow ->Fill(4.,weight); //5
	    
	    eventControl = true;
	  }
	}
	
	// --------------
	// w+jets
	// --------------
	if(id == 24 && metcat_ == analysisid){
	  
	  if ( TMath::Abs(dphiMin_) < 0.4) continue;
          
	  if (MT_ < 450.) continue;
          
	  //if(CSV1_ > btagcut_) continue;
	  //if(CSV2_ > btagcut_)continue;
	  bool csvwj = (CSV1_ > btagcut_ || CSV2_ > btagcut_ );
	  if (csvwj) continue;
	  if(Mass_<30 || 250<Mass_)continue;
	  
	  if(NAddBJet!=0)continue;
	  
	  if((NAddMu_ + NAddEle_ + NAddTau_) !=1)continue;
	  
	  eventControl = true;
	}
	
	// ---------------
	// ttbar 
	// ---------------
	if(id == 6 && metcat_ == analysisid){
	  if ( dphiMin_ < 0.4) continue;
          if (MT_ < 450.) continue;
          //h_cutFlow ->Fill(1.,weightNoBTag); //1                                                                                                                                     	  
	  if(CSV2_ < btagcut_)continue;
	  
	  if(CSV1_ < btagcut_)continue;
	  
	  if(Mass_<30 || 250<Mass_)continue;
	  
	  if(JetMetDPhi_<2.5)continue;
	  
	  if(TMath::Abs(dphiMin_)<0.5)continue;
	  
	  if(NAddBJet<2)continue;
	  
	  if((NAddMu_ + NAddEle_ + NAddTau_ )!=1)continue;
	  
	  eventControl = true;
	}
	
	// --------------
	// Z nnu + Jets
	// --------------
	if(id == 23 && metcat_ == analysisid){
	  h_cutFlow ->Fill(0., weightNoBTag);
	  
	  if ( dphiMin_ < 0.4) continue;
          if (MT_ < 450.) continue;
          h_cutFlow ->Fill(1.,weightNoBTag); //1
	  
	  if((Mass_>30 && Mass_<100) || (Mass_>150 && Mass_<250)){
	    h_cutFlow ->Fill(2., weightNoBTag); //2
	    
	    if(CSV1_ < btagcut_)continue;
	    if(CSV2_ < btagcut_)continue;
	    
	    if(!csvstatus) continue;
	    h_cutFlow ->Fill(3.,weight); //3
	    
	    //h_cutFlow ->Fill(4.,weight); //4
	    
	    if((NAddMu_ + NAddEle_ + NAddTau_ )!=0)continue;
	    h_cutFlow ->Fill(4.,weight); //5
	    
            if(NAddBJet!=0)continue;
	    if(nthinjets_>1) continue;
            h_cutFlow ->Fill(5.,weight); //6                                                                                                                                         
	    eventControl = true;
	  }
	}
	
	if(!eventControl)continue;
	countEvent++;
	
	//std::cout<<run_<<":"<<lumi_<<":"<<event_<<std::endl;
	
	// -----------------------------------
	// Fill the histograms 
	// -----------------------------------
	
	h_nMuons ->Fill(NAddMu_,weight);
	h_nTaus ->Fill(NAddTau_,weight);
	h_nElectrons->Fill(NAddEle_,weight);
	h_DRSJ ->Fill(DRSJ_,weight);
	h_NThinJets ->Fill(nthinjets_,weight);
	h_dPhiThinJetMET->Fill(dphiMin_, weight);
	h_MET ->Fill(MET_,weight);
	
	for(int isys=0; isys<7; isys++){
	  h_MET_Sys[isys]->Fill(MET_, Sysweights[isys]);
	}
	
	for(int isys=0; isys<101; isys++){
	  str = fileName[7].c_str();
	  if(strstr(str,"Merged_MET")){
	    if(SysPDFWeight)  h_MET_PDF[isys]->Fill(MET_, pdfweight_*SysPDFWeight[isys]);
	    if(!SysPDFWeight) h_MET_PDF[isys]->Fill(MET_, Sysweights[0]);
	  }
	}
       
	
	h_Mjj ->Fill(Mass_,weight);
	h_Mjj_Rebin ->Fill(Mass_,weight);
	h_pTjj ->Fill(JetPt_,weight);
	h_etajj ->Fill(JetEta_,weight);
	h_phijj ->Fill(JetPhi_,weight);
	h_CSV1->Fill(CSV1_,weight);
	h_CSV2->Fill(CSV2_,weight);
	h_MT_bb_MET->Fill(MT_,weight);
	h_Tau21jj ->Fill(Tau21_,weight);
	h_CSVMax ->Fill(MaxCSV_,weight);
	h_CSVMin ->Fill(MinCSV_,weight);
	h_CSVSum ->Fill(JetCSVSum_,weight);
	h_dPhi_MET_J ->Fill(dphiMin_,weight);
	h_MET_Over_SumET ->Fill(MET_/SumET_,weight);
	h_MET_Over_pTFatJet ->Fill(MET_/JetPt_,weight);
	h_CEmEF ->Fill(jetCEmEF_,weight);
	h_CHadEF ->Fill(jetCHadEF_,weight);
	h_PhoEF ->Fill(jetPhoEF_,weight);
	h_NEmEF ->Fill(jetNEmEF_,weight);
	h_NHadEF ->Fill(jetNHadEF_,weight);
	h_MuEF ->Fill(jetMuEF_,weight);
	h_CMulti ->Fill(jetCMulti_,weight);
	h_dPhi_bb_MET->Fill(JetMetDPhi_,weight);
	
      }//ENTRIES
      h_event->Fill(countEvent);
      //gSystem->cd(outputdirName);
      TString filename_ = outputdirName +"/"+ outputFile.Data();
      
      // -----------------------------------
      // Create RootFile 
      // -----------------------------------
      
      TFile* outFile ;
      if( idir ==0)  {
	outFile = new TFile(filename_,"recreate");
	outFile->cd();
	h_total->Write();
      }
      
      // -----------------------------------
      // Create directory inside root file 
      // -----------------------------------
      if(id==1){
	outFile->mkdir("MonoHFatJetSelection_JetAndLeptonVeto");
	outFile->cd("MonoHFatJetSelection_JetAndLeptonVeto");
      }
      if(id==6){
	outFile->mkdir("histfacFatJet_TTBar");
	outFile->cd("histfacFatJet_TTBar");
      }
      if(id==23){
	outFile->mkdir("histfacFatJet_ZLight");
	outFile->cd("histfacFatJet_ZLight");
      }
      if(id==24){
	outFile->mkdir("histfacFatJet_WLight");
	outFile->cd("histfacFatJet_WLight");
      }    

      if(id==11){
	outFile->mkdir("histfacFatJet_WHeavy");
	outFile->cd("histfacFatJet_WHeavy");
      }    

      if(id==21){
	outFile->mkdir("histfacFatJet_QCD");
	outFile->cd("histfacFatJet_QCD");
      }    

      // -----------------------------------
      // Write Histograms 
      // -----------------------------------
      
      h_cutFlow ->Write();
      h_nMuons ->Write();
      h_nTaus ->Write();
      h_nElectrons->Write();
      h_DRSJ ->Write();
      h_NThinJets ->Write();
      h_dPhiThinJetMET->Write();
      h_MET ->Write();
      for(int isys=0;isys<7;isys++){
	h_MET_Sys[isys]->Write();
      }

      for(int isys=0;isys<101;isys++){
	h_MET_PDF[isys]->Write();
      }
      h_MET_PDFProfile->Write();

      h_Mjj ->Write();
      h_Mjj_Rebin ->Write();
      h_pTjj ->Write();
      h_etajj ->Write();
      h_phijj ->Write();
      h_Tau21jj ->Write();
      h_CSVMax ->Write();
      h_CSVMin ->Write();
      h_CSV1->Write();
      h_CSV2->Write();
      h_CSVSum ->Write();
      h_MT_bb_MET->Write();
      h_dPhi_MET_J ->Write();
      h_MET_Over_SumET ->Write();
      h_MET_Over_pTFatJet ->Write();
      h_CEmEF ->Write();
      h_CHadEF ->Write();
      h_PhoEF ->Write();
      h_NEmEF ->Write();
      h_NHadEF ->Write();
      h_MuEF ->Write();
      h_CMulti ->Write();
      h_event->Write();
      h_dPhi_bb_MET->Write();
      //outFile->Close();
    } 
  }//files
  time(&end);
  std::cout<<" time used is = "<<-(start-end)<<" seconds"<<std::endl;
  
}//.cc
