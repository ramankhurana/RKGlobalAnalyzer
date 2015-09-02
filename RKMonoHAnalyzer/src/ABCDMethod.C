#define ABCDMethod_cxx
#include "../interface/ABCDMethod.h"
#include "../../RKUtilities/interface/RKDebugger.h"

//      |        |          | 
//      |_A__|___D___|__A___|
//  M   |        |          | 
//  E   |_B _|___C____|__B__|
//  T             Mass


void ABCDMethod::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for Mono-H "<<std::endl;
  DefineHistograms();
  if(false) std::cout<<" Mono-H histo defined "<<std::endl;
}

void ABCDMethod::DefineHistograms(){
  h_Region = new TH2F("h_Region","h_Region",2,1,3, 2,1,3);
}

void ABCDMethod::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){
  
  if(objectCollection.size()>0){
    for(size_t i=0; i< TMath::Min(objectCollection.size(),(size_t)nobjectMet);i++){
      //for(size_t i=0; i< objectCollection.size();i++){
      if(false) std::cout<<" cutsStatus = "<<objectCollection[i].cutsStatus<<std::endl;
      if(!( (objectCollection[i].cutsStatus == 0b0000111101101111) || (objectCollection[i].cutsStatus == 0b0000111111111111)) ) continue;
    
      // Region A
      if(objectCollection[i].jet2.RawPt > 200.0  
	 && (objectCollection[i].jet1.ResonanceProp.InvMass < 100.
	     || objectCollection[i].jet1.ResonanceProp.InvMass > 150.) ) {
	if(false) std::cout<<" inside A"<<std::endl;
	h_Region->Fill(1,2);
      }

      // Region B
      if(objectCollection[i].jet2.RawPt < 200.0  
	 && (objectCollection[i].jet1.ResonanceProp.InvMass < 100.
	     || objectCollection[i].jet1.ResonanceProp.InvMass > 150.) ) {
	h_Region->Fill(1,1);
	
      }

      // Region C
      if(objectCollection[i].jet2.RawPt < 200.0  
	 && objectCollection[i].jet1.ResonanceProp.InvMass > 100.
	 && objectCollection[i].jet1.ResonanceProp.InvMass < 150. ) {
	h_Region->Fill(2,1);
      }

      // Region D
      if(objectCollection[i].jet2.RawPt > 100.0  
	 && objectCollection[i].jet1.ResonanceProp.InvMass > 100.
	 && objectCollection[i].jet1.ResonanceProp.InvMass < 150. ) {
	h_Region->Fill(2,2);
      }
	
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}



void ABCDMethod::Write(){
  file->cd();
  // this directory is alerady made by other class.
  // instead of commenting use a proper check
  file->mkdir(prefix);
  file->cd(prefix);
  h_Region->Write();
}
