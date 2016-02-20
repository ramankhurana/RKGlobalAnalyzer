#define HistFactory_cxx
#include "../interface/HistFactory.h"
#include "../../RKUtilities/interface/RKDebugger.h"
//#include "../../RKUtilities/interface/BTagScaleFactors.h"
//#include "../../RKUtilities/interface/BTagCalibrationStandalone.h"

void HistFactory::GetInputs(TFile* f, TString prefix_, std::string mode1, std::string mode2){
  

  // setup calibration readers
  calib = new BTagCalibration("CSVv2", "CSVv2.csv");
  
  //std::cout<<" mode of running is "<<mode<<std::endl;
  readerHF = new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "mujets", mode1);
  readerLF = new BTagCalibrationReader(calib, BTagEntry::OP_MEDIUM, "comb", mode2);

  /*
  readerHF_up = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "mujets", "up");
  readerLF_up = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "comb", "up");
  
  readerHF_down = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "mujets", "down");
  readerLF_down = new BTagCalibrationReader(calib, BTagEntry::OP_LOOSE, "comb", "down");
  */
  
  //calibration setup ends here. 
  // ------------------------------------------
  
  
  prefix = prefix_;
  file = f;
  if(false) std::cout<<" calling define histograms for Mono-H "<<std::endl;
  DefineHistograms();
  if(false) std::cout<<" Mono-H histo defined "<<std::endl;
}

void HistFactory::DefineHistograms(){
  TString postfix;
  for(int i =0; i<nobjectmet; i++){
    postfix.Form("%d",i);
    
    // 1D Histograms
    h_nMuons[i]     = new TH1F("h_nMuons"+postfix,"h_nMuons",10,0,10);
    h_nTaus[i]      = new TH1F("h_nTaus"+postfix,"h_nTaus",10,0,10);
    h_nElectrons[i] = new TH1F("h_nElectrons"+postfix,"h_nElectrons",10,0,10);
    h_nJets[i]      = new TH1F("h_nJetss"+postfix,"h_nJetss",10,0,10);
    h_nFJets[i]     = new TH1F("h_nFJets"+postfix,"h_nFJets",10,0,10);
    h_DRSJ[i]       = new TH1F("h_DRSJ"+postfix,"h_DRSJ",100,0,5);
    h_NThinJets[i]  = new TH1F("h_NThinJets"+postfix,"h_NThinJets",10,0,10);
    
    h_dPhiThinJetMET[i] = new TH1F("h_dPhiThinJetMET"+postfix,"h_dPhiThinJetMET",70,-3.5,3.5);
    
    h_Q1Q2[i]       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
    h_MET[i]        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);
    h_MHT[i]        = new TH1F("h_MHT"+postfix,"h_MHT",300,0,3000);
    h_Mjj[i]        = new TH1F("h_Mjj"+postfix,"",300,0,3000);
    h_pTjj[i]       = new TH1F("h_pTjj"+postfix,"",300,0,3000);
    h_etajj[i]      = new TH1F("h_etajj"+postfix,"",50,-2.5,2.5);
    h_phijj[i]      = new TH1F("h_phijj"+postfix,"",70,-3.5,3.5);
    h_Tau21jj[i]    = new TH1F("h_h_Tau21jj"+postfix,"",20,0.,1.);
    
    h_CSVMax[i]     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
    h_CSVMin[i]     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
    h_CSV1[i]       = new TH1F("h_CSV1"+postfix,"",20,0,1);
    h_CSV2[i]       = new TH1F("h_CSV2"+postfix,"",20,0,1);
    h_CSVSum[i]     = new TH1F("h_CSVSum"+postfix,"",40,0,2);
    h_dPhi_MET_J[i] = new TH1F("h_dPhi_MET_J"+postfix,"",70,0.,3.5);
    h_MT_bb_MET[i]  = new TH1F("h_MT_bb_MET"+postfix,"",1000,0,5000.);
    h_dPhi_bb_MET[i]= new TH1F("h_dPhi_bb_MET"+postfix,"",100,0,3.5);

    h_MET_Over_SumET[i]    = new TH1F("h_MET_Over_SumET"+postfix,"",20,0,1.);
    h_MET_Over_pTFatJet[i] = new TH1F("h_MET_Over_pTFatJet"+postfix,"",100,0,5);
    h_CEmEF[i]             = new TH1F("h_CEmEF"+postfix,"",20,0,1);
    h_CHadEF[i]            = new TH1F("h_CHadEF"+postfix,"",20,0,1);
    h_PhoEF[i]             = new TH1F("h_PhoEF"+postfix,"",20,0,1);
    h_NEmEF[i]             = new TH1F("h_NEmEF"+postfix,"",20,0,1);
    h_NHadEF[i]            = new TH1F("h_NHadEF"+postfix,"",20,0,1);
    h_MuEF[i]              = new TH1F("h_MuEF"+postfix,"",20,0,1);
    h_CMulti[i]            = new TH1F("h_CMulti"+postfix,"",20,0,1);
    
    //[i]= new TH1F(""+postfix,"",100,0,1);
    //[i]= new TH1F(""+postfix,"",100,0,1);
    
    // 2D Histograms
    h_M_vs_MET[i]   = new TH2F("h_MET_vs_M"+postfix,"h_MET_vs_M",100,0.,200.,200,0.,1000.);
    h_MET_vs_Q1Q2[i]= new TH2F("h_MET_vs_Q1Q2"+postfix,"h_MET_vs_Q1Q2",200,0,1000,21,-10,10);
    h_M_vs_Q1Q2[i]  = new TH2F("h_M_vs_Q1Q2"+postfix,"h_M_vs_Q1Q2",100,0,200,21,-10,10);
  }
  
  // Define Branches for skimTree;
  skimTree = new TTree("skimTree"+prefix,"Tree with relevant info only");
  skimTree->Branch("run_", &run_, "Run_/I");
  skimTree->Branch("lumi_", &lumi_, "Lumi_/I");
  skimTree->Branch("event_", &event_, "Event_/I");
  skimTree->Branch("dphiMin_",&dphiMin_,"dphiMin_/F");
  skimTree->Branch("nthinjets_",&nthinjets_,"nthinjets_/I");
  skimTree->Branch("MT_",&MT_,"MT_/F");
  skimTree->Branch("CSV1_",&CSV1_,"CSV1_/F");
  skimTree->Branch("CSV2_",&CSV2_,"CSV2_/F");
  skimTree->Branch("MHT_",&MHT_,"MHT_/F");
  //skimTree->Branch("",&,"/F");
  skimTree->Branch("NAddMu_",&NAddMu_,"NAddMu_/I");
  skimTree->Branch("NAddEle_",&NAddEle_,"NAddEle_/I");
  skimTree->Branch("NAddTau_",&NAddTau_,"NAddTau_/I");
  skimTree->Branch("NAddBJet",&NAddBJet,"NAddBJet/I");
  skimTree->Branch("MinCSV_",&MinCSV_,"MinCSV_/F");
  skimTree->Branch("MaxCSV_",&MaxCSV_,"MaxCSV_/F");
  skimTree->Branch("DRSJ_",&DRSJ_,"DRSJ_/F");
  skimTree->Branch("Mass_",&Mass_,"Mass_/F");
  skimTree->Branch("JetPhi_",&JetPhi_,"JetPhi_/F");
  skimTree->Branch("JetEta_",&JetEta_,"JetEta_/F");
  skimTree->Branch("JetCSVSum_",&JetCSVSum_,"JetCSVSum_/F");
  skimTree->Branch("JetMetDPhi_",&JetMetDPhi_,"JetMetDPhi_/F");
  skimTree->Branch("Tau21_",&Tau21_,"Tau21_/F");
  skimTree->Branch("JetPt_",&JetPt_,"JetPt_/F");
  skimTree->Branch("SumET_",&SumET_,"SumET_/F");
  skimTree->Branch("MET_",&MET_,"MET_/F");

  skimTree->Branch("jetCEmEF_",&jetCEmEF_,"jetCEmEF_/F");
  skimTree->Branch("jetCHadEF_",&jetCHadEF_,"jetCHadEF_/F");
  skimTree->Branch("jetPhoEF_",&jetPhoEF_,"jetPhoEF_/F");
  skimTree->Branch("jetNEmEF_",&jetNEmEF_,"jetNEmEF_/F");
  skimTree->Branch("jetNHadEF_",&jetNHadEF_,"jetNHadEF_/F");
  skimTree->Branch("jetMuEF_",&jetMuEF_,"jetMuEF_/F");
  skimTree->Branch("jetCMulti_",&jetCMulti_,"jetCMulti_/F");
  
  
}

void HistFactory::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs, std::vector<int> istatus){
  if(false) std::cout<<" inside the Histfac fill "<<objectCollection.size()<<std::endl;
  if(objectCollection.size()>0){
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)nobjectmet);i++){
      Int_t nbits = 0;
      for (size_t ibit=0; ibit<istatus.size(); ibit++){
	if ( objectCollection[i].cutsStatus[istatus[ibit]]) {
	  nbits++;
	}
      }

      
      if(false) std::cout<<" loop over bits done "<<nbits<<std::endl;
      Float_t mcweight_  = 1.;
      if(objectCollection.size() >0) mcweight_ = objectCollection[0].jet1.jet1.event.mcweight ;
      
      if(nbits==(int)istatus.size()){
	
	if(false)std::cout<<" before N muons "<<objectCollection[0].muons.size()<<std::endl;
	h_nMuons[i]->Fill(objectCollection[0].muons.size()             , mcweight_  );
	if(false)std::cout<<" after muons "<<std::endl;
	h_nElectrons[i]->Fill(objectCollection[0].electrons.size()     , mcweight_  );
	if(false)std::cout<<" after Neles "<<std::endl;
	
	if(objectCollection[i].jets.size() >= 2) h_nJets[i]->Fill(objectCollection[0].jets.size()-2     , mcweight_  ); //  -2 is required to get the additional jets.
	if(false)std::cout<<" after NJets "<<std::endl;

	h_Q1Q2[i]->Fill(objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge      , mcweight_   );
	if(false)std::cout<<" after charge "<<std::endl;

	h_MET[i]->Fill(objectCollection[i].jet2.RawPt                  , mcweight_  );
	h_Mjj[i]->Fill(objectCollection[i].jet1.ResonanceProp.InvMass  , mcweight_  );
	if(false)std::cout<<" after Invmass "<<std::endl;
	h_pTjj[i]->Fill(objectCollection[i].jet1.ResonanceProp.p4.Pt() , mcweight_  );
	
	float csv1=objectCollection[i].jet1.jet1.B_CISVV2;
	float csv2=objectCollection[i].jet1.jet2.B_CISVV2;
	
	h_CSVMax[i]->Fill(TMath::Max(csv1,csv2)                        , mcweight_  );
	h_CSVMin[i]->Fill(TMath::Min(csv1,csv2)                        , mcweight_  );
	
	h_CSV1[i]->Fill(csv1                                         , mcweight_  );
	h_CSV2[i]->Fill(csv2                                         , mcweight_  );
	
	h_CSVSum[i]->Fill((csv1+csv2)                     		  , mcweight_  );
	if(false)std::cout<<" after csv "<<std::endl;
	float dphi1 = objectCollection[i].objMet1.DeltaPhi;
	float dphi2 = objectCollection[i].objMet2.DeltaPhi;
	h_dPhi_MET_J[i]->Fill(TMath::Abs(TMath::Min(dphi1,dphi2))      , mcweight_  );
	
	h_MT_bb_MET[i]->Fill(objectCollection[i].ResonancemetProp.TransMass  , mcweight_ );
	h_dPhi_bb_MET[i]->Fill(objectCollection[i].ResonancemetProp.DeltaPhi , mcweight_ );

	if(false)	std::cout<<" after all 1d "<<std::endl;
	// 2D histograms 
	h_M_vs_MET[i]->Fill(objectCollection[i].jet1.ResonanceProp.InvMass, objectCollection[i].jet2.RawPt );
	h_MET_vs_Q1Q2[i]->Fill(objectCollection[i].jet2.RawPt, (objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge));
	h_M_vs_Q1Q2[i]->Fill(objectCollection[i].jet1.ResonanceProp.InvMass, (objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge));
	
	if(false) std::cout<<" charge = "<<objectCollection[i].jet1.jet1.charge
		 <<" : "<<objectCollection[i].jet1.jet2.charge<<std::endl;
      }// if(nbits==istatus.size()){ 
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}




// Following histograms will be filled when you have fat-jet-MET combination 
void HistFactory::Fill(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, Int_t howManyObjs, std::vector<int> istatus, std::vector<TString> eventlist){
  
 if(objectCollection.size()>0){
    
    bool objectfilled = false;
    for(size_t i=0; i< objectCollection.size();i++) {
      if(objectfilled) continue; // fill only one obj info
      //int i=0;
      Int_t nbits = 0;
      for (size_t ibit=0; ibit<istatus.size(); ibit++){
	
	if ( objectCollection[i].cutsStatus[istatus[ibit]]) {
	  nbits++;
	}
      }

    
      if(nbits==(int)istatus.size()){
	
	
	// --------------
	// btag scale factors 
	// --------------
	TLorentzVector p41;
	TLorentzVector p42;
	int flav1, flav2;
	flav1=flav2=0;
	if(objectCollection[i].jet1.SDPx.size()>1){
	  p41.SetPxPyPzE(objectCollection[i].jet1.SDPx[0],
			 objectCollection[i].jet1.SDPy[0],
			 objectCollection[i].jet1.SDPz[0],
			 objectCollection[i].jet1.SDEn[0]);
	  p42.SetPxPyPzE(objectCollection[i].jet1.SDPx[1],
			 objectCollection[i].jet1.SDPy[1],
			 objectCollection[i].jet1.SDPz[1],
			 objectCollection[i].jet1.SDEn[1]);
	  flav1 = objectCollection[i].jet1.HadronFlavor[0];
	  flav2 = objectCollection[i].jet1.HadronFlavor[1];
	}
	
	float sf = 1.0;
	sf = weightBtag( p41.Pt(), p41.Eta(),  flav1) * weightBtag( p42.Pt(), p42.Eta(),  flav2)  ;
	
	

	// ---------------
	// mc weight 
	// ewk weight
	// btag weight
	// --------------
	Float_t mcweight_  = 1.;
	if(objectCollection.size() >0) {
	  
	  std::cout<<" data = "<<objectCollection[0].events.isdata <<std::endl;
	  
	  if(! objectCollection[0].events.isdata ) mcweight_ = objectCollection[0].events.mcweight * objectCollection[0].events.EWKreweight * sf * objectCollection[0].events.puweight;
	  
	  std::cout<<" mcweight = "<<objectCollection[0].events.mcweight
		   <<" EWKreweight = "<<objectCollection[0].events.EWKreweight
		   <<" btag sf = "<<sf
		   <<" total = "<<mcweight_
		   <<std::endl;
	}
	
	std::cout<<" weight factor = "<<mcweight_<<std::endl;
	// ---------------
	// filling histograms
	// ---------------
	float dphimin=3.4;
	Int_t nthinjets = 0;
	for(int ij=0;ij<(int)objectCollection[0].thinjets.size();ij++){
	  //MHTp4 = MHTp4 + objectCollection[0].thinjets[ij].p4;
	  float dr_ =    RKMath::DeltaR(objectCollection[0].thinjets[ij].p4.Eta() ,
					objectCollection[0].thinjets[ij].p4.Phi() ,
					objectCollection[i].jet1.p4.Eta(),
					objectCollection[i].jet1.p4.Phi());
	  if(dr_ < 1.0 )  continue;
	  float dphi_ = RKMath::DeltaPhi( objectCollection[0].thinjets[ij].p4.Phi() ,
					  objectCollection[i].jet2.RawPhi);
	  nthinjets++;
	  if(TMath::Abs(dphi_)<dphimin) dphimin = TMath::Abs(dphi_);
	}
	
	h_NThinJets[0]->Fill(nthinjets, mcweight_);
	std::cout<<" mht in histfac = "<<objectCollection[0].MHTp4.Pt()<<std::endl;
	h_MHT[0]->Fill(objectCollection[0].MHTp4.Pt(), mcweight_);
	h_dPhiThinJetMET[0]->Fill(dphimin, mcweight_ );
	

	
	if(false)	std::cout<<" filling FATJETMET "<<std::endl;
	
	int naddmuon = 0;
	for (size_t imu=0; (imu< objectCollection[0].muons.size()); imu++){
	  float dr_ = objectCollection[0].muons[imu].p4.DeltaR(objectCollection[i].jet1.p4);
	  if(dr_ > 1.0) {
	    naddmuon++;
	  }
	}

	int naddele = 0;
	for (size_t iele=0; (iele< objectCollection[0].electrons.size()); iele++){
	  float dr_ = objectCollection[0].electrons[iele].p4.DeltaR(objectCollection[i].jet1.p4);
	  if(dr_ > 1.0) {
	    naddele++;
	  }
	}

	int naddtau = 0;
	for (size_t itau=0; (itau< objectCollection[0].taus.size()); itau++){
	  float dr_ = objectCollection[0].taus[itau].p4.DeltaR(objectCollection[i].jet1.p4);
	  if(dr_ > 1.0) {
	    naddtau++;
	  }
	}

	
	h_nMuons[0]->Fill(naddmuon             , mcweight_  );
	h_nElectrons[0]->Fill(naddele          , mcweight_  );
        h_nTaus[0]->Fill(naddtau               , mcweight_  );
	
	int njets=objectCollection[0].jets.size();
	int naddjet = 0;
	for(int ij=0;ij<njets;ij++){
	  float dr_ = RKMath::DeltaR(objectCollection[0].jets[ij].p4.Eta() ,
				     objectCollection[0].jets[ij].p4.Phi() ,
				     objectCollection[i].jet1.p4.Eta(),
				     objectCollection[i].jet1.p4.Phi());
	  if(dr_ < 0.8 )  continue;
	  //float dphi_ = RKMath::DeltaPhi(objectCollection[0].jets[ij].p4.Phi(), objectCollection[0].jet1.p4.Phi() );
	  //if( dphi_ < 2.0 ) continue;
	  naddjet++;
	}
	h_nJets[0]->Fill(naddjet   , mcweight_  ); 
	
	if(objectCollection.size()>0) h_nFJets[0]->Fill(objectCollection.size()-1 , mcweight_);
	
	//h_nJets[0]->Fill(objectCollection[i].jets.size()     , mcweight_  ); //  -2 is not required when looking at fat-jets
	
	
	// subjet Delta R
	float drsj ;
	float maxcsv=-999;
	float mincsv=-999;
	float csv1 ;
	float csv2 ;
	
	if(objectCollection[i].jet1.SDPx.size()>1){
	//p41.SetPxPyPzE(objectCollection[i].jet1.SDPx[0],
	//		 objectCollection[i].jet1.SDPy[0],
	//		 objectCollection[i].jet1.SDPz[0],
	//		 objectCollection[i].jet1.SDEn[0]);
	//p42.SetPxPyPzE(objectCollection[i].jet1.SDPx[1],
	//		 objectCollection[i].jet1.SDPy[1],
	//		 objectCollection[i].jet1.SDPz[1],
	//		 objectCollection[i].jet1.SDEn[1]);
	
	  drsj   = p41.DeltaR(p42);
	 csv1 = objectCollection[i].jet1.SDCSV[0];
	 csv2 = objectCollection[i].jet1.SDCSV[1];
	  maxcsv = TMath::Max(csv1,csv2);
	  mincsv = TMath::Min(csv1,csv2);
	  
	  h_CSVMax[0]->Fill(maxcsv, mcweight_);
	  h_CSVMin[0]->Fill(mincsv, mcweight_);
	  
	  h_CSV1[0]->Fill(csv1, mcweight_);
	  h_CSV2[0]->Fill(csv2, mcweight_);
	}
	else drsj = -1;
	h_DRSJ[0]->Fill(drsj   , mcweight_);
	// MET
	
	h_MET[0]->Fill(objectCollection[i].jet2.RawPt                  , mcweight_  );
	
	h_Mjj[0]->Fill(objectCollection[i].jet1.SDmass                 , mcweight_  );
	h_pTjj[0]->Fill(objectCollection[i].jet1.p4.Pt() , mcweight_  );
	h_etajj[0]->Fill(objectCollection[i].jet1.p4.Eta() , mcweight_);
	h_phijj[0]->Fill(objectCollection[i].jet1.p4.Phi() , mcweight_);
	
	
	h_CSVSum[0]->Fill(objectCollection[i].jet1.B_CISVV2 , mcweight_  );
	h_MT_bb_MET[0]->Fill(objectCollection[i].TransverseObjProp.TransMass  , mcweight_ );
	h_dPhi_bb_MET[0]->Fill(TMath::Abs(objectCollection[i].TransverseObjProp.DeltaPhi) , mcweight_ );
	h_Tau21jj[0]->Fill(objectCollection[i].jet1.tau2/objectCollection[i].jet1.tau1, mcweight_);

	
	h_MET_Over_SumET[0]->Fill(objectCollection[i].jet2.RawPt / objectCollection[i].jet2.RawSumEt  ,mcweight_);
	h_MET_Over_pTFatJet[0]->Fill(objectCollection[i].jet2.RawPt / objectCollection[i].jet1.p4.Pt()  ,mcweight_);
	h_CEmEF[0]->Fill(objectCollection[i].jet1.jetCEmEF  ,mcweight_);
	h_CHadEF[0]->Fill(objectCollection[i].jet1.jetCHadEF  ,mcweight_);
	h_PhoEF[0]->Fill(objectCollection[i].jet1.jetPhoEF  ,mcweight_);
	h_NEmEF[0]->Fill(objectCollection[i].jet1.jetNEmEF  ,mcweight_);
	h_NHadEF[0]->Fill(objectCollection[i].jet1.jetNHadEF  ,mcweight_);
	h_MuEF[0]->Fill(objectCollection[i].jet1.jetMuEF  ,mcweight_);
	h_CMulti[0]->Fill(objectCollection[i].jet1.jetCMulti  ,mcweight_);
	// 2D histograms 
	h_M_vs_MET[0]->Fill(objectCollection[i].jet1.SDmass, objectCollection[i].jet2.RawPt );
	
	//--------------
	// Filling the branches here which are used to fill the histograms. 
	// This can be used later for more debugging. 
	//--------------
	run_           = objectCollection[0].events.run;
	lumi_          = objectCollection[0].events.lumi;
	event_         = objectCollection[0].events.event;
	dphiMin_       = dphimin;
	nthinjets_     = nthinjets;
	MT_            = objectCollection[i].TransverseObjProp.TransMass;
	CSV1_          = csv1;
	CSV2_          = csv2;
	MHT_           = objectCollection[0].MHTp4.Pt();
	NAddMu_        = naddmuon;
	NAddEle_       = naddele;
	NAddTau_       = naddtau;
	NAddBJet       = naddjet;
	MinCSV_        = mincsv;
	MaxCSV_        = maxcsv;
	DRSJ_          = drsj;
	Mass_          = objectCollection[i].jet1.SDmass;
	JetPhi_        = objectCollection[i].jet1.p4.Phi();
	JetEta_        = objectCollection[i].jet1.p4.Eta();
	JetCSVSum_     = objectCollection[i].jet1.B_CISVV2;
	JetMetDPhi_    = TMath::Abs(objectCollection[i].TransverseObjProp.DeltaPhi);
	Tau21_         = objectCollection[i].jet1.tau2/objectCollection[i].jet1.tau1;
	JetPt_         = objectCollection[i].jet1.p4.Pt();
	SumET_         = objectCollection[i].jet2.RawSumEt;
	MET_           = objectCollection[i].jet2.RawPt;
	jetCEmEF_      = objectCollection[i].jet1.jetCEmEF;
	jetCHadEF_     = objectCollection[i].jet1.jetCHadEF;
	jetPhoEF_      = objectCollection[i].jet1.jetPhoEF;
	jetNEmEF_      = objectCollection[i].jet1.jetNEmEF;
	jetNHadEF_     = objectCollection[i].jet1.jetNHadEF;
	jetMuEF_       = objectCollection[i].jet1.jetMuEF;
	jetCMulti_     = objectCollection[i].jet1.jetCMulti;
	
	//--------------------
	// Branches ends here
	//--------------------
	skimTree->Fill();
	objectfilled=true;
      }// if(nbits==istatus.size()){ 
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void HistFactory::Write(){
  file->cd();
  skimTree->Write();
  file->mkdir(prefix);
  file->cd(prefix);
  
  for(int i =0; i<nobjectmet; i++){
    // 1D Histograms
    h_nMuons[i]       ->Write();
    h_nElectrons[i]   ->Write();
    h_nTaus[i]        ->Write();
    h_nJets[i]        ->Write();
    h_nFJets[i]       ->Write();
    h_DRSJ[i]         ->Write();
    h_Q1Q2[i]         ->Write();
    h_MET[i]          ->Write();
    h_MHT[i]          ->Write();
    h_Mjj[i]          ->Write();
    h_pTjj[i]         ->Write();
    h_etajj[i]        ->Write();
    h_phijj[i]        ->Write();
    h_Tau21jj[i]      ->Write();
    h_CSVMax[i]       ->Write();
    h_CSVMin[i]       ->Write();
    h_CSV1[i]       ->Write();
    h_CSV2[i]       ->Write();
    h_CSVSum[i]       ->Write();
    h_dPhi_MET_J[i]   ->Write();
    h_MT_bb_MET[i]    ->Write();
    h_dPhi_bb_MET[i]  ->Write();

    h_MET_Over_SumET[i]      ->Write();
    h_MET_Over_pTFatJet[i]   ->Write();
    h_CEmEF[i]               ->Write();
    h_CHadEF[i]              ->Write();
    h_PhoEF[i]               ->Write();
    h_NEmEF[i]               ->Write();
    h_NHadEF[i]              ->Write();
    h_MuEF[i]                ->Write();
    h_CMulti[i]              ->Write();
    h_NThinJets[i]           ->Write();
    h_dPhiThinJetMET[i]      ->Write();
    // 2D Histograms
    h_M_vs_MET[i]   ->Write();
    h_MET_vs_Q1Q2[i]->Write();
    h_M_vs_Q1Q2[i]  ->Write();
  }
}






inline double HistFactory::weightBtag(double pt, double eta, unsigned int flav) { // assuming CSVL                                                                                                
  double SF=1.0;
  float MaxBJetPt = 670., MaxLJetPt = 1000.;
  if (pt>MaxBJetPt && (flav==5 || flav==4) )  { // use MaxBJetPt for  heavy jets                                                                                                     
    pt = MaxBJetPt;
  }
  if (pt>MaxLJetPt && !(flav==5 || flav==4))  { // use MaxLJetPt for  light jets                                                                                                     
    pt = MaxLJetPt;
  }
  
  std::cout<<" pt = "<<pt
	   <<" eta = "<<eta
	   <<" flav = "<<flav
	   <<std::endl;
  switch(flav)
    {
    case 5:
      SF = readerHF->eval( BTagEntry::FLAV_B , eta, pt);
      break;
    case 4:
      SF = readerHF->eval( BTagEntry::FLAV_C , eta, pt);
      break;

    default:
      SF = readerLF->eval( BTagEntry::FLAV_UDSG , eta, pt);
    }
  
  
  
  std::cout << "SF for pt, " << pt <<" eta, " << eta << " flav " << flav << " is " << SF << std::endl;
  return SF ;


}




// HFup LFcentral   readerHF->eval( BTagEntry::FLAV_B , eta, pt) * readerLF->eval( BTagEntry::FLAV_UDSG , eta, pt);
