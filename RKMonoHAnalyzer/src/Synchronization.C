#define Synchronization_cxx
#include "../interface/Synchronization.h"
#include "../../RKUtilities/interface/RKDebugger.h"


void Synchronization::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for Mono-H "<<std::endl;
  DefineHistograms();
  std::cout<<" Mono-H histo defined "<<std::endl;
}

void Synchronization::DefineHistograms(){
  TString postfix;
  sync_ = new TH1F("sync_","",10,0,10);
}

void Synchronization::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){
  if(objectCollection.size()>0){
    bool isvtx=false;
    bool isleadingjet=false;
    bool isdphi=false;
    bool ismet=false;
    bool njets=false;
    bool nlepton=false;
    bool ntau=false;
    bool nphoton=false;
    
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)nobjectmet);i++){
      if(i==0) sync_->Fill(1);
      if(objectCollection[i].jet1.jet1.nVtx>0 && !sync_) {
	sync_->Fill(2);
	isvtx=true;
	
	if( objectCollection[i].jet1.jet1.p4.Pt() > 110. && objectCollection[i].jet1.jet1.jetCHadEF > 0.2 && objectCollection[i].jet1.jet1.jetNHadEF < 0.7 && objectCollection[i].jet1.jet1.jetNEmEF < 0.7 && objectCollection[i].jet1.jet1.isLooseJet_ && objectCollection[i].jet1.jet1.isPUJet_ &&  !isleadingjet) { 
	  sync_->Fill(3);
	  isleadingjet=true;
	  if(!isdphi){
	    
	    isdphi=true;
	  }//isdphi
	}//isleadingjet 
      }//nVtx
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void Synchronization::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  sync_->Write();
    
}
