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

void Synchronization::Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, std::vector<Jet> jetcollection){
  sync_->Fill(0);
  bool isvtx=false;
  bool isleadingjet=false;
  bool isdphi=false;
  bool ismet=false;
  bool njets=false;
  bool nlepton=false;
  bool ntau=false;
  bool nphoton=false;
  // using jet collection
  // Good Vertex
  if(jetcollection.size()>0 && jetcollection[0].nVtx>0) {
    sync_->Fill(1);
    isvtx=true;
  }
  // Leading Jet selection 
  for(size_t j=0; j<jetcollection.size(); j++){
    if(j>0) continue;
    //if(jetcollection[j].p4.Pt() > 30.
    // && jetcollection[j].isPUJet_
    // && jetcollection[j].isLooseJet_
    // && TMath::Abs(jetcollection[j].p4.Eta())<2.5 ) njet++;

    if( //njet==1
        jetcollection[j].p4.Pt() > 110.
	//&& jetcollection[j].isPUJet_
	//&& jetcollection[j].isLooseJet_
	&& jetcollection[j].jetCHadEF > 0.2
	&& jetcollection[j].jetNHadEF < 0.7
	&& jetcollection[j].jetNEmEF < 0.7
	&& isvtx
	&& !isleadingjet ) { 
      sync_->Fill(2);
      isleadingjet=true;
      break;
    }
  }
    // Leading- SubLeading DPhi
  if(objectCollection.size()>0){
    for(size_t i=0; i< objectCollection.size();i++){

      //std::cout<<
      //std::cout<<" nVtx in Fill == "<<objectCollection[i].jet1.jet1.nVtx<<std::endl;
      //if(objectCollection[i].jet1.jet1.nVtx > 0 && !isvtx) {
      //	sync_->Fill(1);
      //	isvtx=true;
      //}	
      //
      if( objectCollection[i].jet1.jet1.p4.Pt() > 110.
	  && objectCollection[i].jet1.jet1.jetCHadEF > 0.2
	  && objectCollection[i].jet1.jet1.jetNHadEF < 0.7
	  && objectCollection[i].jet1.jet1.jetNEmEF < 0.7
	  && isvtx
	  //if(//objectCollection[i].jet1.jet2.isLooseJet_
	 //&& objectCollection[i].jet1.jet2.isPUJet_
	 && objectCollection[i].jet1.jet2.jetNHadEF < 0.7
	 && objectCollection[i].jet1.jet2.jetNEmEF < 0.9
	 && TMath::Abs(objectCollection[i].jet1.ResonanceProp.DeltaPhi) < 2.5
	 && !isdphi
	  //&& isleadingjet
	  ){
	std::cout<<objectCollection[0].events.run<<":"
		 <<objectCollection[0].events.lumi<<":"
		 <<objectCollection[0].events.event
		 <<std::endl;//":"<<(Double_t)pfMetCorrPt<<std::endl;
	isdphi=true;
	sync_->Fill(3);
      }//isdphi

      // MET
      if(objectCollection[i].jet2.CorrPt > 200. && isdphi && !ismet ){
	ismet=true;
	sync_->Fill(4);
      }// ismet

    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){

  if(ismet
     && objectCollection.size()>0
     && objectCollection[0].jets.size() <3
     && !njets
     ){
    sync_->Fill(5);
    njets=true;
  }

  if(njets
     && objectCollection.size()>0
     && objectCollection[0].muons.size() <1
     && objectCollection[0].electrons.size() <1
     && !nlepton) {
    sync_->Fill(6);
    nlepton=true;
  }

  if(nlepton) {
    sync_->Fill(7);
    ntau=true;
  }

  if(ntau){
    sync_->Fill(8);
    nphoton=true;
    std::cout<<nphoton<<std::endl;
  }
}



void Synchronization::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  sync_->Write();
    
}
