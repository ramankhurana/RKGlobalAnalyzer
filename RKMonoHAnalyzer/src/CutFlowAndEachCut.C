#define CutFlowAndEachCut_cxx
#include "../interface/CutFlowAndEachCut.h"
#include "../../RKUtilities/interface/RKDebugger.h"

void  CutFlowAndEachCut::CutFlow(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(i<2) { // i = 0, i = 1 ; save only two combinations not more than that. 
	if(false) std::cout<<" bit size = "<<objectCollection[i].cutsStatus.size()
		 <<" content = "<<objectCollection[i].cutsStatus
		 <<std::endl;
	// ---- For each cut 
	for(int ibin=0;ibin<(int)objectCollection[i].cutsStatus.size(); ibin++){
	  int a = (int) objectCollection[i].cutsStatus[ibin];
	  h_eachcut[i]->Fill(ibin*a);
	}// End for For Each Cut 
	
	
	// --- For Cut Flow 
	for(int ibin=0;ibin<(int)objectCollection[i].cutsStatus.size(); ibin++){
	  int a = (int) objectCollection[i].cutsStatus[ibin];
	  if(objectCollection[i].cutsStatus.test(ibin)){
	    h_cutflow[i]->Fill(ibin*a);
	    if(false) std::cout<<" bin val = "<<a<<std::endl;
	  }
	  else break;
	}// End of For Cut Flow
	
      }// if(i<2) {
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void  CutFlowAndEachCut::CutFlow(std::vector<ResonanceWithMET<Jet,MET > > objectCollection){
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(i<2) { // i = 0, i = 1 ; save only two combinations not more than that. 
	if(false) std::cout<<" bit size = "<<objectCollection[i].cutsStatus.size()
			   <<" content = "<<objectCollection[i].cutsStatus
			   <<std::endl;
	// ---- For each cut 
	for(int ibin=0;ibin<(int)objectCollection[i].cutsStatus.size(); ibin++){
	  int a = (int) objectCollection[i].cutsStatus[ibin];
	  h_eachcut_f[i]->Fill(ibin*a);
	}// End for For Each Cut 
	
	
	Float_t mcweight_ = 1.;
	//if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.mcweight ;
	if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.allmcweight ;
	// --- For Cut Flow 
	for(int ibin=0;ibin<(int)objectCollection[i].cutsStatus.size(); ibin++){
	  int a = (int) objectCollection[i].cutsStatus[ibin];
	  if(objectCollection[i].cutsStatus.test(ibin)){
	    h_cutflow_f[i]->Fill(ibin*a,mcweight_);
	    if(false) std::cout<<" bin val = "<<a<<std::endl;
	  }
	  else break;
	}// End of For Cut Flow
	
      }// if(i<2) {
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}


// when you want to make CutFlow using given cuts
void  CutFlowAndEachCut::CutFlow(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, std::vector<int> statusbitVector){
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(i<2) { // i = 0, i = 1 ; save only two combinations not more than that. 
	if(false) std::cout<<" bit size = "<<objectCollection[i].cutsStatus.size()
			   <<" content = "<<objectCollection[i].cutsStatus
			   <<std::endl;
	// ---- For each cut 
	for(int ibin=0;ibin<(int)statusbitVector.size(); ibin++){
	  int a = (int) objectCollection[i].cutsStatus[statusbitVector[ibin]];
	  h_eachcut_f[i]->Fill(ibin*a);
	}// End for For Each Cut 
	
	
	Float_t mcweight_ = 1.;
	//if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.mcweight ;
	if(objectCollection.size() >0) mcweight_ = objectCollection[0].events.allmcweight ;
	// --- For Cut Flow 
	for(int ibin=0;ibin<(int)statusbitVector.size(); ibin++){
	  int a = (int) objectCollection[i].cutsStatus[statusbitVector[ibin]];
	  if(objectCollection[i].cutsStatus.test(statusbitVector[ibin])){
	    h_cutflow_f[i]->Fill(ibin*a,mcweight_);
	    if(false) std::cout<<" bin val = "<<a<<std::endl;
	  }
	  else break;
	}// End of For Cut Flow
	
      }// if(i<2) {
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}

void CutFlowAndEachCut::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(false) std::cout<<" calling define histograms for MET "<<std::endl;
  DefineHistograms();
  if(false) std::cout<<" MET histo defined "<<std::endl;
}




void CutFlowAndEachCut::DefineHistograms(){
  TString postfix;
  for(int i=0;i<2;i++){
    postfix.Form("%d",i);
    h_eachcut[i] = new TH1F("h_eachcut_"+postfix,"h_eachcut_"+postfix,16,0,16);
    h_cutflow[i] = new TH1F("h_cutflow_"+postfix,"h_cutflow_"+postfix,16,0,16);

    h_eachcut_f[i] = new TH1F("h_eachcut_"+postfix+"_f","h_eachcut_"+postfix,16,0,16);
    h_cutflow_f[i] = new TH1F("h_cutflow_"+postfix+"_f","h_cutflow_"+postfix,16,0,16);
    
  }
}


void CutFlowAndEachCut::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  for(int i=0;i<2;i++){
    h_cutflow[i]->Write();
    h_eachcut[i]->Write();

    h_cutflow_f[i]->Write();
    h_eachcut_f[i]->Write();
  }
    
}
