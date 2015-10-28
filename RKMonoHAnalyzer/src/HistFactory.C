#define HistFactory_cxx
#include "../interface/HistFactory.h"
#include "../../RKUtilities/interface/RKDebugger.h"


void HistFactory::GetInputs(TFile* f, TString prefix_){
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
    
    h_Q1Q2[i]       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
    h_MET[i]        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);
    h_Mjj[i]        = new TH1F("h_Mjj"+postfix,"",300,0,3000);
    h_pTjj[i]       = new TH1F("h_pTjj"+postfix,"",300,0,3000);
    h_etajj[i]      = new TH1F("h_etajj"+postfix,"",50,-2.5,2.5);
    h_phijj[i]      = new TH1F("h_phijj"+postfix,"",70,-3.5,3.5);
    h_Tau21jj[i]    = new TH1F("h_h_Tau21jj"+postfix,"",20,0.,1.);
    
    h_CSVMax[i]     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
    h_CSVMin[i]     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
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
void HistFactory::Fill(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, Int_t howManyObjs, std::vector<int> istatus){
  if(objectCollection.size()>0){
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)nobjectmet);i++){
      Int_t nbits = 0;
      for (size_t ibit=0; ibit<istatus.size(); ibit++){
	
	if ( objectCollection[i].cutsStatus[istatus[ibit]]) {
	  nbits++;
	}
      }

    
      Float_t mcweight_  = 1.;
      //if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.allmcweight ;
      if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.mcweight ;
      
      if(nbits==(int)istatus.size()){
	if(false)	std::cout<<" filling FATJETMET "<<std::endl;
	h_nMuons[i]->Fill(objectCollection[0].muons.size()             , mcweight_  );
	h_nElectrons[i]->Fill(objectCollection[0].electrons.size()     , mcweight_  );
        h_nTaus[i]->Fill(objectCollection[0].taus.size()               , mcweight_  );
	int njets=objectCollection[0].jets.size();
	int naddjet = 0;
	for(int ij=0;ij<njets;ij++){
	  float dr_ = RKMath::DeltaR(objectCollection[0].jets[ij].p4.Eta() ,
				     objectCollection[0].jets[ij].p4.Phi() ,
				     objectCollection[0].jet1.p4.Eta(),
				     objectCollection[0].jet1.p4.Phi());
	  if(dr_ < 0.8 )  continue;
	  //float dphi_ = RKMath::DeltaPhi(objectCollection[0].jets[ij].p4.Phi(), objectCollection[0].jet1.p4.Phi() );
	  //if( dphi_ < 2.0 ) continue;
	  naddjet++;
	}
	h_nJets[i]->Fill(naddjet   , mcweight_  ); 
	
	if(objectCollection.size()>0) h_nFJets[i]->Fill(objectCollection.size()-1 , mcweight_);
	
	//h_nJets[i]->Fill(objectCollection[i].jets.size()     , mcweight_  ); //  -2 is not required when looking at fat-jets
	
	
	// subjet Delta R
	float drsj ;
	TLorentzVector p41;
	TLorentzVector p42;
	if(objectCollection[i].jet1.SDPx.size()>1){
	  p41.SetPxPyPzE(objectCollection[i].jet1.SDPx[0],
			 objectCollection[i].jet1.SDPy[0],
			 objectCollection[i].jet1.SDPz[0],
			 objectCollection[i].jet1.SDEn[0]);
	  p42.SetPxPyPzE(objectCollection[i].jet1.SDPx[1],
			 objectCollection[i].jet1.SDPy[1],
			 objectCollection[i].jet1.SDPz[1],
			 objectCollection[i].jet1.SDEn[1]);
	
	  drsj   = p41.DeltaR(p42);
	  float csv1 = objectCollection[i].jet1.SDCSV[0];
	  float csv2 = objectCollection[i].jet1.SDCSV[2];
	  float maxcsv = TMath::Max(csv1,csv2);
	  float mincsv = TMath::Min(csv1,csv2);
	  h_CSVMax[i]->Fill(maxcsv, mcweight_);
	  h_CSVMin[i]->Fill(mincsv, mcweight_);
	}
	else drsj = -1;
	h_DRSJ[i]->Fill(drsj   , mcweight_);
	// MET
	
	h_MET[i]->Fill(objectCollection[i].jet2.RawPt                  , mcweight_  );
	
	h_Mjj[i]->Fill(objectCollection[i].jet1.SDmass                 , mcweight_  );
	h_pTjj[i]->Fill(objectCollection[i].jet1.p4.Pt() , mcweight_  );
	h_etajj[i]->Fill(objectCollection[i].jet1.p4.Eta() , mcweight_);
	h_phijj[i]->Fill(objectCollection[i].jet1.p4.Phi() , mcweight_);
	
	
	h_CSVSum[i]->Fill(objectCollection[i].jet1.B_CISVV2 , mcweight_  );
	h_MT_bb_MET[i]->Fill(objectCollection[i].TransverseObjProp.TransMass  , mcweight_ );
	h_dPhi_bb_MET[i]->Fill(TMath::Abs(objectCollection[i].TransverseObjProp.DeltaPhi) , mcweight_ );
	h_Tau21jj[i]->Fill(objectCollection[i].jet1.tau2/objectCollection[i].jet1.tau1, mcweight_);

	
	h_MET_Over_SumET[i]->Fill(objectCollection[i].jet2.RawPt / objectCollection[i].jet2.RawSumEt  ,mcweight_);
	h_MET_Over_pTFatJet[i]->Fill(objectCollection[i].jet2.RawPt / objectCollection[i].jet1.p4.Pt()  ,mcweight_);
	h_CEmEF[i]->Fill(objectCollection[i].jet1.jetCEmEF  ,mcweight_);
	h_CHadEF[i]->Fill(objectCollection[i].jet1.jetCHadEF  ,mcweight_);
	h_PhoEF[i]->Fill(objectCollection[i].jet1.jetPhoEF  ,mcweight_);
	h_NEmEF[i]->Fill(objectCollection[i].jet1.jetNEmEF  ,mcweight_);
	h_NHadEF[i]->Fill(objectCollection[i].jet1.jetNHadEF  ,mcweight_);
	h_MuEF[i]->Fill(objectCollection[i].jet1.jetMuEF  ,mcweight_);
	h_CMulti[i]->Fill(objectCollection[i].jet1.jetCMulti  ,mcweight_);
	// 2D histograms 
	h_M_vs_MET[i]->Fill(objectCollection[i].jet1.SDmass, objectCollection[i].jet2.RawPt );
	
      }// if(nbits==istatus.size()){ 
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void HistFactory::Write(){
  file->cd();
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
    h_Mjj[i]          ->Write();
    h_pTjj[i]         ->Write();
    h_etajj[i]        ->Write();
    h_phijj[i]        ->Write();
    h_Tau21jj[i]      ->Write();
    h_CSVMax[i]       ->Write();
    h_CSVMin[i]       ->Write();
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
    
    // 2D Histograms
    h_M_vs_MET[i]   ->Write();
    h_MET_vs_Q1Q2[i]->Write();
    h_M_vs_Q1Q2[i]  ->Write();
  }
}
