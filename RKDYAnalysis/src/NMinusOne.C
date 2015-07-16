#define NMinusOne_cxx
#include "../interface/NMinusOne.h"
#include "../../RKUtilities/interface/RKDebugger.h"

void  NMinusOne::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(true/*i<2*/) { // i = 0, i = 1 ; save only two combinations not more than that. 
	std::map<TString, bitset<16> >::iterator mapiter;
	int icut=0;
	for(mapiter=cutsMap.begin(); mapiter != cutsMap.end(); ++mapiter){
	  //std::cout<<mapiter->first<<"  "<<mapiter->second<<std::endl;
	  std::cout<<" status= "<<objectCollection[0].cutsStatus
		   <<" map = "<<mapiter->second
		   <<std::endl;
	  if(objectCollection[i].cutsStatus == mapiter->second || objectCollection[i].cutsStatus == 0b0000001111111111) {
	    // Fill the histograms when 
	    // all cuts are satisfied OR
	    // cuts from map is satisfied 
	    // this is equavivalent to not applying a particular cut from the map
	    // this is what we need for N-1 plots
	    // Fix me ? 	   
	    
            h_IdEtaIn[icut]->Fill(objectCollection[i].dEtaIn); 
            h_IdPhiIn[icut]->Fill(objectCollection[i].dPhiIn);
            h_Idfull5x5_sigmaIetaIeta[icut]->Fill(objectCollection[i].full5x5_sigmaIetaIeta);
            h_IdhOverE[icut]->Fill(objectCollection[i].hOverE);
            h_Idd0[icut]->Fill(objectCollection[i].d0);
            h_Iddz[icut]->Fill(objectCollection[i].dz); 
            h_IdeoverPInv[icut]->Fill(objectCollection[i].eoverPInv);
            h_IdisoRho[icut]->Fill(objectCollection[i].isoRho);
            h_IdexpectedMissingInnerHits[icut]->Fill(objectCollection[i].expectedMissingInnerHits);
            h_IdpassConversionVeto[icut]->Fill(objectCollection[i].passConversionVeto);
	    // h_Id[icut]->Fill(objectCollection[i].); 



	    std::cout<<" matched "<<objectCollection[i].dEtaIn<<std::endl;
	  }
	  icut++;
	}
	
      }// if(i<2) {
    }//(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

}

void NMinusOne::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for MET "<<std::endl;
  std::cout<<" MET histo defined "<<std::endl;
  cutsMap["aDEtaIn"]      = 0b0000001111111110;
  cutsMap["bDPhiIn"]      = 0b0000001111111101;
  cutsMap["cSigmaIetaIetaFull"]      = 0b0000001111111011;
  cutsMap["dHOverE"]      = 0b0000001111110111;
  cutsMap["eD0"]      = 0b0000001111101111;
  cutsMap["fDz"]      = 0b0000001111011111;
  cutsMap["gEInvP"]      = 0b0000001110111111;
  cutsMap["hRhoIsolation"]      = 0b0000001101111111;
  cutsMap["iExpMissingHits"]      = 0b0000001011111111;
  cutsMap["jConversionVeto"]      = 0b0000000111111111;

  DefineHistograms();

}




void NMinusOne::DefineHistograms(){
  std::vector<TString> postfix;
  postfix.clear();
  for(std::map<TString,bitset<16> >::iterator  mapiter=cutsMap.begin(); mapiter != cutsMap.end(); ++mapiter){
    postfix.push_back(mapiter->first);
  }
  for(int i=0;i<RKTS;i++){
    
    h_IdEtaIn[i]                      =   new TH1F("h_IdEtaIn_"+postfix[i],"h_IdEtaIn_"+postfix[i], 260,  0.0  , 0.08);
    h_IdPhiIn[i]	              =   new TH1F("h_IdPhiIn_"+postfix[i],"h_IdPhiIn_"+postfix[i], 160  , 0.0 , 0.08);
    h_Idfull5x5_sigmaIetaIeta[i]      =   new TH1F("h_Idfull5x5_sigmaIetaIeta_"+postfix[i],"h_Idfull5x5_sigmaIetaIeta_"+postfix[i] , 100 , 0.0 ,0.1);
    h_IdhOverE[i]	              =   new TH1F("h_IdhOverE_"+postfix[i],"h_IdhOverE_"+postfix[i], 100  ,0.  ,0.1);
    h_Idd0[i]		              =   new TH1F("h_Idd0_"+postfix[i],"h_Idd0_"+postfix[i],10000 , 0 ,100);
    h_Iddz[i]		              =   new TH1F("h_Iddz_"+postfix[i],"h_Iddz_"+postfix[i],10000  , 0 ,100);
    h_IdeoverPInv[i]	              =   new TH1F("h_IdeoverPInv_"+postfix[i],"h_IdeoverPInv_"+postfix[i],400  ,0.  ,0.5);
    h_IdisoRho[i]	              =   new TH1F("h_IdisoRho_"+postfix[i],"h_IdisoRho_"+postfix[i],100 , 0 ,2);
    h_IdexpectedMissingInnerHits[i] =   new TH1F("h_IdexpectedMissingInnerHits_"+postfix[i],"h_IdexpectedMissingInnerHits_"+postfix[i], 2 , 0 ,2);
    h_IdpassConversionVeto[i]       =   new TH1F("h_IdpassConversionVeto_"+postfix[i],"h_IdpassConversionVeto_"+postfix[i], 2 , 0  ,2);
    
    
    
  }
}


void NMinusOne::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  for(int i=0;i<RKTS;i++){
    
    h_IdEtaIn[i]->Write();
    h_IdPhiIn[i]->Write();
    h_Idfull5x5_sigmaIetaIeta[i]->Write();
    h_IdhOverE[i]->Write();
    h_Idd0[i]->Write();
    h_Iddz[i]->Write();
    h_IdeoverPInv[i]->Write();
    h_IdisoRho[i]->Write();
    h_IdexpectedMissingInnerHits[i]->Write();
    h_IdpassConversionVeto[i]->Write();
    

      }
    
}
