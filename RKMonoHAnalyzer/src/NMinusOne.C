#define NMinusOne_cxx
#include "../interface/NMinusOne.h"
#include "../../RKUtilities/interface/RKDebugger.h"

void  NMinusOne::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){
  if(objectCollection.size()>0){
    //for(int i=0; i<(int)objectCollection.size();i++){
    if(true/*i<2*/) { // i = 0, i = 1 ; save only two combinations not more than that. 
	std::map<TString, bitset<16> >::iterator mapiter;
	int icut=0;
	for(mapiter=cutsMap.begin(); mapiter != cutsMap.end(); ++mapiter){
	  //std::cout<<mapiter->first<<"  "<<mapiter->second<<std::endl;
	  
	  if(objectCollection[0].cutsStatus == mapiter->second || objectCollection[0].cutsStatus == 0b0000000000001111) {
	    // Fill the histograms when 
	    // all cuts are satisfied OR
	    // cuts from map is satisfied 
	    // this is equavivalent to not applying a particular cut from the map
	    // this is what we need for N-1 plots
	    // Fix me ? 	   
	    h_DiJetMass[icut]->Fill(objectCollection[0].jet1.ResonanceProp.p4.Mag());
	    h_DeltaEtaJets[icut]->Fill(objectCollection[0].jet1.ResonanceProp.DeltaEta);
	    h_DeltaPhiJets[icut]->Fill(objectCollection[0].jet1.ResonanceProp.DeltaPhi);
	    h_PtOverPt1Pt2[icut]->Fill(objectCollection[0].jet1.ResonanceProp.PtOverPt1Pt2);
	    std::cout<<" matched "<<objectCollection[0].jet1.ResonanceProp.p4.Mag()<<std::endl;
	  }
	  icut++;
	}
	
      }// if(i<2) {
      //}//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}

void NMinusOne::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for MET "<<std::endl;
  std::cout<<" MET histo defined "<<std::endl;
  cutsMap["dijetmass"]      = 0b0000000000001110;
  cutsMap["detaJets"]       = 0b0000000000001101;
  cutsMap["dphiJets"]       = 0b0000000000001011;
  cutsMap["ptOverpt1pt1"]   = 0b0000000000000111;
  DefineHistograms();

}




void NMinusOne::DefineHistograms(){
  std::vector<TString> postfix;
  postfix.clear();
  for(std::map<TString,bitset<16> >::iterator  mapiter=cutsMap.begin(); mapiter != cutsMap.end(); ++mapiter){
    postfix.push_back(mapiter->first);
  }
  for(int i=0;i<RKTS;i++){
    h_DiJetMass[i]    = new TH1F("h_DiJetMass_"+postfix[i],"h_DiJetMass_"+postfix[i]      ,300,0,3000);
    h_DeltaEtaJets[i] = new TH1F("h_DeltaEtaJets_"+postfix[i],"h_DeltaEtaJets_"+postfix[i],50,-5,5);
    h_DeltaPhiJets[i] = new TH1F("h_DeltaPhiJets_"+postfix[i],"h_DeltaPhiJets_"+postfix[i],70,-3.5,3.5);
    h_PtOverPt1Pt2[i] = new TH1F("h_PtOverPt1Pt2_"+postfix[i],"h_PtOverPt1Pt2_"+postfix[i],50,0.,1.);
  }
}


void NMinusOne::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  for(int i=0;i<RKTS;i++){
    h_DiJetMass[i]->Write();
    h_DeltaEtaJets[i]->Write();
    h_DeltaPhiJets[i]->Write();
    h_PtOverPt1Pt2[i]->Write();
  }
    
}
