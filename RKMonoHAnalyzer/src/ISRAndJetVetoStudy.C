#define ISRAndJetVetoStudy_cxx
#include "../interface/ISRAndJetVetoStudy.h"
#include "../../RKUtilities/interface/RKDebugger.h"


void ISRAndJetVetoStudy::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(false) std::cout<<" calling define histograms for Mono-H "<<std::endl;
  DefineHistograms();
  if(false) std::cout<<" Mono-H histo defined "<<std::endl;
}

void ISRAndJetVetoStudy::DefineHistograms(){
  TString postfix;
  std::vector<TString> ptcut_;
  ptcut_.clear();
  ptcut_.push_back("pt10");
  ptcut_.push_back("pt15");
  ptcut_.push_back("pt20");
  ptcut_.push_back("pt25");
  ptcut_.push_back("pt30");
  
  for(int j=0; j<5; j++){
      h_nAddJets[j]           =  new TH1F("h_nAddJets"+ptcut_[j],"h_nAddJets",10,0,10);
    }

  for(int i =0; i<3; i++){
    
    postfix.Form("%d",i);
    for(int j=0; j<5; j++){
      
      h_DeltaRLeadingB[i][j]     =  new TH1F("h_DeltaRLeadingB"+postfix+ptcut_[j],"h_DeltaRLeadingB",50,0,5);
      h_DeltaRSubLeadingB[i][j]  =  new TH1F("h_DeltaRSubLeadingB"+postfix+ptcut_[j],"h_DeltaRSubLeadingB",50,0,5.);
      h_DeltaRClosestB[i][j]     =  new TH1F("h_DeltaRClosestB"+postfix+ptcut_[j],"h_DeltaRClosestB",50,0,5.);
    }
    
    h_pTAddJet[i]           =  new TH1F("h_pTAddJet"+postfix,"h_pTAddJet",500,0,500);
    h_pT_vs_DR[i]           =  new TH2F("h_pT_vs_DR"+postfix,"h_pT_vs_DR",500,0,500, 50,0,5.);

  }

}

void ISRAndJetVetoStudy::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs, std::vector<int> istatus){
  nobjectmet_ = howManyObjs;
  if(objectCollection.size()>0){
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)howManyObjs);i++){
      Int_t nbits = 0;
      for (size_t ibit=0; ibit<istatus.size(); ibit++){
	if ( objectCollection[i].cutsStatus[istatus[ibit]]) {
	  nbits++;
	}
      }

      
      Float_t mcweight_  = 1.;
      if(false) std::cout<<" mcweight_ = "<<mcweight_<<std::endl;
      if(objectCollection.size() >0) mcweight_ = objectCollection[0].jet1.jet1.event.mcweight ;
      
      if(nbits==(int)istatus.size()){ // number of high Bit is equal to size of cuts.
	
	if(objectCollection[0].jets.size()<1) continue; //skip if no jet is there
	if(false) std::cout<<" after preselection "<<std::endl;
	// loop over jets 
	int pt10_=0;
	int pt15_=0;
	int pt20_=0;
	int pt25_=0;
	int pt30_=0;
	int cleanjet=0;
	for(int ijet = 0; ijet < (int) objectCollection[0].jets.size(); ijet++){// loop over jet collection
	  Jet jet   = objectCollection[0].jets[ijet];
	  Jet bjet1 = objectCollection[0].jet1.jet1;
	  Jet bjet2 = objectCollection[0].jet1.jet2;
	  if(false) std::cout<<" copied jets "<<std::endl;
	  if(RKMath::DeltaR(jet.p4.Eta(), jet.p4.Phi(), bjet1.p4.Eta(),bjet1.p4.Phi()) < 0.1) continue; // shouldn't match with leading b-jet
	  if(RKMath::DeltaR(jet.p4.Eta(), jet.p4.Phi(), bjet2.p4.Eta(),bjet2.p4.Phi()) < 0.1) continue; // shouldn't match with sub-leading b-jet
	  
	  std::cout<<" after cleaning "<<cleanjet<<std::endl;
	  if(cleanjet >= naddjet) continue;
	  std::cout<<" after skipping 3 jet "<<std::endl;
	  
	  
	  float dr1 = RKMath::DeltaR(jet.p4.Eta(), jet.p4.Phi(), bjet1.p4.Eta(),bjet1.p4.Phi());
	  float dr2 = RKMath::DeltaR(jet.p4.Eta(), jet.p4.Phi(), bjet2.p4.Eta(),bjet2.p4.Phi());
	  float drmin = TMath::Min(dr1,dr2);
	  std::cout<<" dr s = "<<dr1<<"  "<<dr2<<std::endl;
	  if(false) std::cout<<" found minimum dr "<<std::endl;
	  // This is curent jet pT vs Dr with closest b-jet
	  h_pT_vs_DR[cleanjet]->Fill(jet.p4.Pt(),drmin);
	  h_pTAddJet[cleanjet]->Fill(jet.p4.Pt());
	  
	  if(jet.p4.Pt()>10.0) {
	    pt10_++;
	    std::cout<<" pt 10 "<<std::endl;
	    h_DeltaRLeadingB[cleanjet][0]->Fill(dr1);
	    h_DeltaRSubLeadingB[cleanjet][0]->Fill(dr2);
	    h_DeltaRClosestB[cleanjet][0]->Fill(drmin);
	  }
	  if(jet.p4.Pt()>15.0) {
	    std::cout<<" pt 15 "<<std::endl;
	    pt15_++;
	    h_DeltaRLeadingB[cleanjet][1]->Fill(dr1);
	    h_DeltaRSubLeadingB[cleanjet][1]->Fill(dr2);
	    h_DeltaRClosestB[cleanjet][1]->Fill(drmin);
	  }
	  if(jet.p4.Pt()>20.0) {
	    std::cout<<" pt 20 "<<std::endl;
	    pt20_++;
	    h_DeltaRLeadingB[cleanjet][2]->Fill(dr1);
	    h_DeltaRSubLeadingB[cleanjet][2]->Fill(dr2);
	    h_DeltaRClosestB[cleanjet][2]->Fill(drmin);
	  }
	  if(jet.p4.Pt()>25.0) {
	    std::cout<<" pt 25 "<<std::endl;
	    pt25_++;
	    h_DeltaRLeadingB[cleanjet][3]->Fill(dr1);
	    h_DeltaRSubLeadingB[cleanjet][3]->Fill(dr2);
	    h_DeltaRClosestB[cleanjet][3]->Fill(drmin);
	  }
	  if(jet.p4.Pt()>30.0) {
	    std::cout<<" pt 30 "<<std::endl;
	    pt30_++;
	    h_DeltaRLeadingB[cleanjet][4]->Fill(dr1);
	    h_DeltaRSubLeadingB[cleanjet][4]->Fill(dr2);
	    h_DeltaRClosestB[cleanjet][4]->Fill(drmin);
	  }
	  
	  cleanjet++;
	  if(false) std::cout<<" filled all histograms for dr"<<std::endl;
	}//for(int ijet = 0; ijet < (int) objectCollection[0].jets.size(); ijet++){
	h_nAddJets[0]->Fill(pt10_);
	h_nAddJets[1]->Fill(pt15_);
	h_nAddJets[2]->Fill(pt20_);
	h_nAddJets[3]->Fill(pt25_);
	h_nAddJets[4]->Fill(pt30_);
	
	
      }// if(nbits==istatus.size()){ 
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void ISRAndJetVetoStudy::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);

  for(int i =0; i<3; i++){
    for(int j =0; j<5; j++){
      if(i==0) h_nAddJets[j]->Write(); // write them only once
      h_DeltaRLeadingB[i][j]->Write();
      h_DeltaRSubLeadingB[i][j]->Write();
      h_DeltaRClosestB[i][j]->Write();
    }
    h_pTAddJet[i]->Write();
    h_pT_vs_DR[i]->Write();
  }
}
