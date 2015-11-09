#define NMinusOne_cxx
#include "../interface/NMinusOne.h"
#include "../../RKUtilities/interface/RKDebugger.h"

void  NMinusOne::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){
  if(objectCollection.size()>0){
    //for(int i=0; i<(int)objectCollection.size();i++){
    if(true/*i<2*/) { // i = 0, i = 1 ; save only two combinations not more than that. 
	std::map<TString, bitset<26> >::iterator mapiter;
	int icut=0;
	for(mapiter=cutsMap.begin(); mapiter != cutsMap.end(); ++mapiter){
	  //std::cout<<mapiter->first<<"  "<<mapiter->second<<std::endl;
	  if(false) std::cout<<" status= "<<objectCollection[0].cutsStatus
		   <<" map = "<<mapiter->second
		   <<std::endl;
	  if(objectCollection[0].cutsStatus == mapiter->second || objectCollection[0].cutsStatus == 0b00000000000000000000001111) {
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
	    if(false) std::cout<<" matched "<<objectCollection[0].jet1.ResonanceProp.p4.Mag()<<std::endl;
	  }
	  icut++;
	}
	
      }// if(i<2) {
      //}//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
}



void  NMinusOne::Fill(std::vector<ResonanceWithMET<Jet,MET > > objectCollection,
		      std::vector<int> bitVector){
  nHistWrite = bitVector.size();
  for(size_t i=0; i<bitVector.size(); i++){
    std::vector<int> UsedBitVector;
    UsedBitVector.clear();
    for(size_t j=0; j<bitVector.size(); j++){
      if(i==j) continue;
      UsedBitVector.push_back(j);
    }
    //std::cout<<" i = "<<i<<" bitvec "<<objectCollection[0].cutsStatus<<std::endl;
    if(CheckBitPattern(objectCollection,UsedBitVector)){
      //std::cout<<" filling histograms for i = "<<i<<std::endl;
      // if these cuts are passes then fill the variable histogram which cut is not applied. 
      // Since it is not known in the loop which cut is not applied we are filling all the histograms. 
      h_FatJetpT[i]->Fill(objectCollection[0].jet1.p4.Pt());
      h_FatJetCSV[i]->Fill(objectCollection[0].jet1.B_CISVV2);
      h_DPhiFatJetMET[i]->Fill(TMath::Abs(objectCollection[0].TransverseObjProp.DeltaPhi));
      h_MSoftDrop[i]->Fill(objectCollection[0].jet1.SDmass);
      h_MET[i]->Fill(objectCollection[0].jet2.RawPt);
      
    }
    
  }
  
}

void NMinusOne::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(false) std::cout<<" calling define histograms for MET "<<std::endl;
  if(false) std::cout<<" MET histo defined "<<std::endl;
  cutsMap["dijetmass"]      = 0b00000000000000000000001110;
  cutsMap["detaJets"]       = 0b00000000000000000000001101;
  cutsMap["dphiJets"]       = 0b00000000000000000000001011;
  cutsMap["ptOverpt1pt1"]   = 0b00000000000000000000000111;
  
  
  DefineHistograms();
  
}




void NMinusOne::DefineHistograms(){
  std::vector<TString> postfix;
  postfix.clear();
  std::map<std::string,int> cutsFatJet = cuts_.cutsMapFatJet;
  for(std::map<std::string,int >::iterator  mapiter=cutsFatJet.begin(); mapiter != cutsFatJet.end(); ++mapiter){
    postfix.push_back(mapiter->first);
  }
  for(int i=0;i<RKTS;i++){
    h_DiJetMass[i]    = new TH1F("h_DiJetMass_"+postfix[i],"h_DiJetMass_"+postfix[i]      ,300,0,3000);
    h_DeltaEtaJets[i] = new TH1F("h_DeltaEtaJets_"+postfix[i],"h_DeltaEtaJets_"+postfix[i],50,-5,5);
    h_DeltaPhiJets[i] = new TH1F("h_DeltaPhiJets_"+postfix[i],"h_DeltaPhiJets_"+postfix[i],70,-3.5,3.5);
    h_PtOverPt1Pt2[i] = new TH1F("h_PtOverPt1Pt2_"+postfix[i],"h_PtOverPt1Pt2_"+postfix[i],50,0.,1.);
    
    
    // FatJet Variables 
    h_FatJetpT[i]        = new TH1F("h_FatJetpT"+postfix[i],"",1000,0,2500.);
    h_FatJetCSV[i]       = new TH1F("h_FatJetCSV"+postfix[i],"",100,0,1.);
    h_DPhiFatJetMET[i]   = new TH1F("h_DPhiFatJetMET"+postfix[i],"",70,0,3.5);
    h_MSoftDrop[i]       = new TH1F("h_MSoftDrop"+postfix[i],"",200,0,200);
    h_MET[i]             = new TH1F("h_MET"+postfix[i],"",1000,0,2500);
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
    
    h_FatJetpT[i]->Write();
    h_FatJetCSV[i]->Write();
    h_DPhiFatJetMET[i]->Write();
    h_MSoftDrop[i]->Write();
    h_MET[i]->Write();
    
  }
  
}



bool NMinusOne::CheckBitPattern(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, std::vector<int> bitVector){
  //std::cout<<" SIZE = "<<bitVector.size();
  bool decision=false;
  size_t nbit=0;
  for(int ibit=0;ibit<(int)bitVector.size();ibit++){
    //std::cout<<" ibit = "<<bitVector[ibit]
    //	     <<" value  = "<<objectCollection[0].cutsStatus[ibit]<<std::endl;
    // bitVector has the integer which values are to be cut on.
    // so bitVector[ibit] is the bit number NOT ibit itself
    if(objectCollection[0].cutsStatus[bitVector[ibit]]==1) nbit++;
  }
  if(nbit==bitVector.size()) decision=true;
  return decision;
  
}

