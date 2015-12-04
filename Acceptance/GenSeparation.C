#define GenAceptance_cxx
#include "GenAceptance.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

void GenAceptance::Loop()
{
   if (fChain == 0) return;
   TFile efile ("GenAcceptance.root","recreate");

   int mcw =-999;
   TH1F* h_PreFSRMass = new TH1F("h_PreFSRMass","h_PreFSRMass", 100, 0, 400);
   TH1F* h_PostFSRMass = new TH1F("h_PostFSRMass","h_PostFSRMass", 100, 0, 400);
   TH1F* nEvents  = new TH1F("nEvents","nEvents",100,0,400); 
   
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;


      if(mcWeight < 0) mcw=-1;                                                                                                                 
      if(mcWeight > 0) mcw= 1; 

      // For PostFSR isPrompt() ans is FinalState()
      bool Zee = false;
      int nGenele = 0;
      int nGenPreFSRele = 0;
      int nGenPostFSRele = 0;
      TLorentzVector* PreFSRele1;
      TLorentzVector* PreFSRele2;
      TLorentzVector* PostFSRele1;
      TLorentzVector* PostFSRele2;
      TLorentzVector* FSRele1;
      TLorentzVector* FSRele2;  
    
      TLorentzVector PreFSRtwo;
      TLorentzVector PostFSRtwo;
      TLorentzVector FSRtwo;

      for (int i=0; i< nGenPar; i++){
	TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
        if((*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){   
	  nGenele++;
	  if (nGenele ==1 ){FSRele1 = (TLorentzVector*) genParP4->At(i);}
	  if (nGenele ==2 ){FSRele2 = (TLorentzVector*) genParP4->At(i);}
	  //	  cout << "entry:  " << ientry <<  "   nGenPar: " << nGenPar << "  genStFlag :   " << (*genStFlag)[i] << "   Par Status :   " << (*genParSt)[i]  << std::endl;
	}
      }
      
      if(nGenele >= 2){
	Zee = true;
	//  nEvents->Fill(1,mcw);
	FSRtwo = *FSRele1 + *FSRele2;
	if(FSRtwo.M() >=60. && FSRtwo.M() <=120){
	  nEvents->Fill(FSRtwo.M(),mcw);
	  //cout << "Dielectron mass: "  <<PostFSRtwo.Pt() <<std::endl;
	}   
      }
      

      if(Zee == false){continue;}
      cout << "is Zee: "<< Zee <<std::endl; 
      
      
      for (int i=0; i< nGenPar; i++){
	TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
        if(fourmom->Pt() > 25.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && (*genParSt)[i] == 1 && (((*genStFlag)[i] >> 1 ) & 1) && fabs((*genParId)[i]) ==11){   
	  //	  cout << "is Zee" << Zee <<std::endl;
	  nGenPostFSRele++;
	  if (nGenPostFSRele ==1 ){PostFSRele1 = (TLorentzVector*) genParP4->At(i);}
	  if (nGenPostFSRele ==2 ){PostFSRele2 = (TLorentzVector*) genParP4->At(i);}
	  //	  cout << "entry:  " << ientry <<  "   nGenPar: " << nGenPar << "  genStFlag :   " << (*genStFlag)[i] << "   Par Status :   " << (*genParSt)[i]  << std::endl;
	}
      }
      if(nGenPostFSRele >=2){
	PostFSRtwo = *PostFSRele1 + *PostFSRele2;
	if(PostFSRtwo.M() >=60. && PostFSRtwo.M() <=120){
	  h_PostFSRMass->Fill(PostFSRtwo.M(),mcw);
	  //cout << "Dielectron mass: "  <<PostFSRtwo.Pt() <<std::endl;
	}
      }
   
      
      // For PreFSR fromHardProcessBeforeFSR()
      // from HardProcess  ==9
      
      
      for (int i=0; i< nGenPar; i++){
	TLorentzVector*  fourmom = (TLorentzVector*) genParP4->At(i);
	if( (((*genStFlag)[i] >> 9 ) & 1) && fourmom->Pt() > 25.  && fabs(fourmom->Eta()) < 2.5 && !(fabs(fourmom->Eta()) > 1.4442 && fabs(fourmom->Eta()) < 1.566) && fabs((*genParId)[i]) ==11 )  {   
	  nGenPreFSRele++;
          if (nGenPreFSRele ==1 ){PreFSRele1 = (TLorentzVector*) genParP4->At(i);}
          if (nGenPreFSRele ==2 ){PreFSRele2 = (TLorentzVector*) genParP4->At(i);}
	  //	  cout << "entry:  " << ientry <<  "   nGenPar: " << nGenPreFSRele << "  genStFlag :   " << (*genStFlag)[i] << "   Par Status :   " << (*genParSt)[i]  << std::endl;
	}
      }
      if(nGenPreFSRele >= 2){
	PreFSRtwo = *PreFSRele1 + *PreFSRele2 ;
	if(PreFSRtwo.M() >=60. && PreFSRtwo.M() <=120){
	  h_PreFSRMass->Fill(PreFSRtwo.M(),mcw);
	  //	  cout << "Dielectron mass: "  <<PreFSRtwo.Pt() <<std::endl;
	}
      }
      
      
      
      
      // if (Cut(ientry) < 0) continue;
   }
   efile.cd();
   nEvents->Write();
   h_PreFSRMass->Write();
   h_PostFSRMass->Write();
   efile.Close();
}
