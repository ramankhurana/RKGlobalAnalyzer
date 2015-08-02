// Original class : TwoObjectValidator.h
// Created By     : ramankhurana 
// Created On     : Sun Apr 26 18:26:44 CEST 2015

#ifndef TwoObjectValidator_h_
#define TwoObjectValidator_h_

#define NJETS  4
#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/DiJet.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"


template <class T>
class TwoObjectValidator {
 public:
  TFile* file;
  TString prefix;
  
  TwoObjectValidator(){};
  ~TwoObjectValidator(){};

  void Fill(std::vector<T> diobjectcollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  // 1D Histograms 
  TH1F*    h_pt ;
  TH1F*    h_eta ;
  TH1F*    h_phi ;
  TH1F*    h_energy ;
  TH1F*    h_DeltaR ;
  TH1F*    h_DeltaPhi ;
  TH1F*    h_DeltaEta ;
  TH1F*    h_InvMass ;
  TH1F*    h_Pt2OverPt1 ;
  TH1F*    h_PtOverPt1Pt2 ;
  TH1F*    h_PtOverMass_1;
  TH1F*    h_PtOverMass_2;
  TH1F*    h_CSVSum;
    // 2D Histograms
  TH2F* h_DeltaR_vs_InvMass;
  TH2F* h_DeltaPhi_vs_InvMass;
  TH2F* h_DeltaEta_vs_InvMass;
 protected:
  
 private:
  
};
#endif



template <class T>
void TwoObjectValidator<T>::Fill(std::vector<T> objectcollection){
  
  Float_t mcweight_  = 1.;
  if(objectcollection.size() >0) mcweight_ = objectcollection[0].jet1.event.mcweight ;

  if(false) std::cout<<" num of dijets = "<<objectcollection.size()<<std::endl;
  
  if(objectcollection.size()>0){
    // Fill properties of first di-jet combination made from 
    // selected leading jet and selected sub-leading jet. 
    
    // 1D Histograms 
    h_pt           ->Fill(objectcollection[0].ResonanceProp.p4.Pt()                              ,  mcweight_    );
    h_eta          ->Fill(objectcollection[0].ResonanceProp.p4.Eta()                             ,  mcweight_    );
    h_phi          ->Fill(objectcollection[0].ResonanceProp.p4.Phi()                             ,  mcweight_    );
    h_energy       ->Fill(objectcollection[0].ResonanceProp.p4.Energy()                          ,  mcweight_    );
    h_DeltaR       ->Fill(objectcollection[0].ResonanceProp.DeltaR                               ,  mcweight_    );
    h_DeltaPhi     ->Fill(objectcollection[0].ResonanceProp.DeltaPhi                             ,  mcweight_    );
    h_DeltaEta     ->Fill(objectcollection[0].ResonanceProp.DeltaEta                             ,  mcweight_    );
    h_InvMass      ->Fill(objectcollection[0].ResonanceProp.InvMass                              ,  mcweight_    );
    h_Pt2OverPt1   ->Fill(1.0/objectcollection[0].ResonanceProp.Pt1OverPt2                       ,  mcweight_    );
    h_PtOverPt1Pt2 ->Fill(objectcollection[0].ResonanceProp.PtOverPt1Pt2                         ,  mcweight_    );
    h_PtOverMass_1 ->Fill(objectcollection[0].ResonanceProp.PtOverMass_1                         ,  mcweight_    );
    h_PtOverMass_2 ->Fill(objectcollection[0].ResonanceProp.PtOverMass_2                         ,  mcweight_    );
    h_CSVSum       ->Fill(objectcollection[0].jet1.B_CISVV2 + objectcollection[0].jet2.B_CISVV2  ,  mcweight_    );
    // 2D Histograms
    h_DeltaR_vs_InvMass->Fill(objectcollection[0].ResonanceProp.DeltaR, objectcollection[0].ResonanceProp.InvMass       );
    h_DeltaPhi_vs_InvMass->Fill(objectcollection[0].ResonanceProp.DeltaPhi,objectcollection[0].ResonanceProp.InvMass    );
    h_DeltaEta_vs_InvMass->Fill(objectcollection[0].ResonanceProp.DeltaEta,objectcollection[0].ResonanceProp.InvMass    );
    
  }
  
}

template <class T>
void TwoObjectValidator<T>::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(false) std::cout<<" calling define histograms for diJets "<<std::endl;
  DefineHistograms();
  if(false) std::cout<<" diJets histo defined "<<std::endl;
}

template <class T>
void TwoObjectValidator<T>::DefineHistograms(){
  // 1D Histograms 
  h_pt                    = new TH1F("h_pt","h_pt",2000,0,2000);
  h_eta                   = new TH1F("h_eta","h_eta",100,-5,5);
  h_phi                   = new TH1F("h_phi","h_phi",35,-3.5,3.5);
  h_energy                = new TH1F("h_energy","h_energy",2000,0,2000);
  h_DeltaR                = new TH1F("h_DeltaR","h_DeltaR",50,0.,5);
  h_DeltaPhi              = new TH1F("h_DeltaPhi","h_DeltaPhi",70,-3.5,3.5);
  h_DeltaEta              = new TH1F("h_DeltaEta","h_DeltaEta",50,-5,5);
  h_InvMass               = new TH1F("h_InvMass","h_InvMass",3000,0,3000);
  h_Pt2OverPt1            = new TH1F("h_Pt2OverPt1","h_Pt2OverPt1",50,0,1.);
  h_PtOverPt1Pt2          = new TH1F("h_PtOverPt1Pt2","h_PtOverPt1Pt2",50,0.,1.0);
  h_PtOverMass_1          = new TH1F("h_PtOverMass_1","h_PtOverMass_1",50,0,5.);
  h_PtOverMass_2          = new TH1F("h_PtOverMass_2","h_PtOverMass_2",50,0,5.);
  h_CSVSum                = new TH1F("h_CSVSum","h_CSVSum",1000,-2.,2.);
  
  // 2D Histograms
  h_DeltaR_vs_InvMass     = new TH2F("h_DeltaR_vs_InvMass","h_DeltaR_vs_InvMass",50,0.,5,300,0.,3000);
  h_DeltaPhi_vs_InvMass   = new TH2F("h_DeltaPhi_vs_InvMass","h_DeltaPhi_vs_InvMass",70,-3.5,3.5,300,0,3000);
  h_DeltaEta_vs_InvMass   = new TH2F("h_DeltaEta_vs_InvMass","h_DeltaEta_vs_InvMass",50,-5,5,300,0,3000);
  

}

template <class T>
void TwoObjectValidator<T>::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  
  // 1D Histograms 
  h_pt                   ->Write();
  h_eta                  ->Write();
  h_phi                  ->Write();
  h_energy               ->Write();
  h_DeltaR               ->Write();
  h_DeltaPhi             ->Write();
  h_DeltaEta             ->Write();
  h_InvMass              ->Write();
  h_Pt2OverPt1           ->Write();
  h_PtOverPt1Pt2         ->Write();
  h_PtOverMass_1         ->Write();
  h_PtOverMass_2         ->Write();
  h_CSVSum               ->Write();
  
    // 2D Histograms
  h_DeltaR_vs_InvMass    ->Write();
  h_DeltaPhi_vs_InvMass  ->Write();
  h_DeltaEta_vs_InvMass  ->Write();
  
  
}
