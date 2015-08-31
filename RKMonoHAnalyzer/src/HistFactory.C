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
    h_nElectrons[i] = new TH1F("h_nElectrons"+postfix,"h_nElectrons",10,0,10);
    h_nJets[i]      = new TH1F("h_nJetss"+postfix,"h_nJetss",10,0,10);
    h_Q1Q2[i]       = new TH1F("h_Q1Q2"+postfix,"h_Q1Q2",21,-10,10);
    h_MET[i]        = new TH1F("h_MET"+postfix,"h_MET",300,0,3000);
    h_Mjj[i]        = new TH1F("h_Mjj"+postfix,"",300,0,3000);
    h_pTjj[i]       = new TH1F("h_pTjj"+postfix,"",300,0,3000);
    h_CSVMax[i]     = new TH1F("h_CSVMax"+postfix,"",20,0,1);
    h_CSVMin[i]     = new TH1F("h_CSVMin"+postfix,"",20,0,1);
    h_CSVSum[i]     = new TH1F("h_CSVSum"+postfix,"",40,0,2);
    h_dPhi_MET_J[i] = new TH1F("h_dPhi_MET_J"+postfix,"",70,0.,3.5);
    h_MT_bb_MET[i]  = new TH1F("h_MT_bb_MET"+postfix,"",1000,0,5000.);
    h_dPhi_bb_MET[i]= new TH1F("h_dPhi_bb_MET"+postfix,"",70,-3.5,3.5);
    // 2D Histograms
    h_M_vs_MET[i]   = new TH2F("h_MET_vs_M"+postfix,"h_MET_vs_M",100,0.,200.,200,0.,1000.);
    h_MET_vs_Q1Q2[i]= new TH2F("h_MET_vs_Q1Q2"+postfix,"h_MET_vs_Q1Q2",200,0,1000,21,-10,10);
    h_M_vs_Q1Q2[i]  = new TH2F("h_M_vs_Q1Q2"+postfix,"h_M_vs_Q1Q2",100,0,200,21,-10,10);
  }

}

void HistFactory::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs, std::vector<int> istatus){
  if(objectCollection.size()>0){
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)nobjectmet);i++){
      Int_t nbits = 0;
      for (size_t ibit=0; ibit<istatus.size(); ibit++){
	if ( objectCollection[i].cutsStatus[istatus[ibit]]) {
	  nbits++;
	}
      }

      
      Float_t mcweight_  = 1.;
      if(objectCollection.size() >0) mcweight_ = objectCollection[0].jet1.jet1.event.mcweight ;
      
      if(nbits==(int)istatus.size()){
	h_nMuons[i]->Fill(objectCollection[i].muons.size()             , mcweight_  );
	h_nElectrons[i]->Fill(objectCollection[i].electrons.size()     , mcweight_  );
	if(objectCollection[i].jets.size() >= 2) h_nJets[i]->Fill(objectCollection[i].jets.size()-2     , mcweight_  ); //  -2 is required to get the additional jets.
	h_Q1Q2[i]->Fill(objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge      , mcweight_   );
	h_MET[i]->Fill(objectCollection[i].jet2.RawPt                  , mcweight_  );
	h_Mjj[i]->Fill(objectCollection[i].jet1.ResonanceProp.InvMass  , mcweight_  );
	h_pTjj[i]->Fill(objectCollection[i].jet1.ResonanceProp.p4.Pt() , mcweight_  );
	
	float csv1=objectCollection[i].jet1.jet1.B_CISVV2;
	float csv2=objectCollection[i].jet1.jet2.B_CISVV2;
	
	h_CSVMax[i]->Fill(TMath::Max(csv1,csv2)                        , mcweight_  );
	h_CSVMin[i]->Fill(TMath::Min(csv1,csv2)                        , mcweight_  );
	h_CSVSum[i]->Fill((csv1+csv2)                                  , mcweight_  );
	
	float dphi1 = objectCollection[i].objMet1.DeltaPhi;
	float dphi2 = objectCollection[i].objMet2.DeltaPhi;
	h_dPhi_MET_J[i]->Fill(TMath::Abs(TMath::Min(dphi1,dphi2))      , mcweight_  );
	
	h_MT_bb_MET[i]->Fill(objectCollection[i].ResonancemetProp.TransMass  , mcweight_ );
	h_dPhi_bb_MET[i]->Fill(objectCollection[i].ResonancemetProp.DeltaPhi , mcweight_ );

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
      if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.mcweight ;

      if(nbits==(int)istatus.size()){
	std::cout<<" filling FATJETMET "<<std::endl;
	h_nMuons[i]->Fill(objectCollection[i].muons.size()             , mcweight_  );
	h_nElectrons[i]->Fill(objectCollection[i].electrons.size()     , mcweight_  );
	if(objectCollection[i].jets.size() >= 2) h_nJets[i]->Fill(objectCollection[i].jets.size()-2     , mcweight_  ); //  -2 is required to get the additional jets.
	
	h_MET[i]->Fill(objectCollection[i].jet2.RawPt                  , mcweight_  );
	h_Mjj[i]->Fill(objectCollection[i].jet1.SDmass                 , mcweight_  );
	h_pTjj[i]->Fill(objectCollection[i].jet1.p4.Pt() , mcweight_  );
	
	
	h_MT_bb_MET[i]->Fill(objectCollection[i].TransverseObjProp.TransMass  , mcweight_ );
	h_dPhi_bb_MET[i]->Fill(objectCollection[i].TransverseObjProp.DeltaPhi , mcweight_ );
	
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
    h_nJets[i]        ->Write();
    h_Q1Q2[i]         ->Write();
    h_MET[i]          ->Write();
    h_Mjj[i]          ->Write();
    h_pTjj[i]         ->Write();
    h_CSVMax[i]       ->Write();
    h_CSVMin[i]       ->Write();
    h_CSVSum[i]       ->Write();
    h_dPhi_MET_J[i]   ->Write();
    h_MT_bb_MET[i]    ->Write();
    h_dPhi_bb_MET[i]  ->Write();
    // 2D Histograms
    h_M_vs_MET[i]   ->Write();
    h_MET_vs_Q1Q2[i]->Write();
    h_M_vs_Q1Q2[i]  ->Write();
  }
}
