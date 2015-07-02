#define HistFactory_cxx
#include "../interface/HistFactory.h"
#include "../../RKUtilities/interface/RKDebugger.h"


void HistFactory::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for Mono-H "<<std::endl;
  DefineHistograms();
  std::cout<<" Mono-H histo defined "<<std::endl;
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
    // 2D Histograms
    h_M_vs_MET[i]   = new TH2F("h_MET_vs_M"+postfix,"h_MET_vs_M",100,0.,200.,200,0.,1000.);
    h_MET_vs_Q1Q2[i]= new TH2F("h_MET_vs_Q1Q2"+postfix,"h_MET_vs_Q1Q2",200,0,1000,21,-10,10);
    h_M_vs_Q1Q2[i]  = new TH2F("h_M_vs_Q1Q2"+postfix,"h_M_vs_Q1Q2",100,0,200,21,-10,10);
  }

}

void HistFactory::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs){
  //  std::cout<<" 
  if(objectCollection.size()>0){
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)nobjectmet);i++){
      h_nMuons[i]->Fill(objectCollection[i].muons.size());
      h_nElectrons[i]->Fill(objectCollection[i].electrons.size());
      if(objectCollection[i].jets.size() >= 2) h_nJets[i]->Fill(objectCollection[i].jets.size()-2); //  -2 is required to get the additional jets.
      h_Q1Q2[i]->Fill(objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge);
      
      h_M_vs_MET[i]->Fill(objectCollection[i].jet1.ResonanceProp.InvMass, objectCollection[i].jet2.RawPt);
      h_MET_vs_Q1Q2[i]->Fill(objectCollection[i].jet2.RawPt, (objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge));
      h_M_vs_Q1Q2[i]->Fill(objectCollection[i].jet1.ResonanceProp.InvMass, (objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge));
      
      std::cout<<" charge = "<<objectCollection[i].jet1.jet1.charge
	       <<" : "<<objectCollection[i].jet1.jet2.charge<<std::endl;
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void HistFactory::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);

  for(int i =0; i<nobjectmet; i++){
    // 1D Histograms
    h_nMuons[i]     ->Write();
    h_nElectrons[i] ->Write();
    h_nJets[i]      ->Write();
    h_Q1Q2[i]       ->Write();
    // 2D Histograms
    h_M_vs_MET[i]   ->Write();
    h_MET_vs_Q1Q2[i]->Write();
    h_M_vs_Q1Q2[i]  ->Write();
  }
}
