// Original class : ObjectMETValidator.h
// Created By     : ramankhurana 
// Created On     : Sun Apr 26 18:26:44 CEST 2015

#ifndef ObjectMETValidator_h_
#define ObjectMETValidator_h_

#define nobjectmet 2
#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/DiJet.h"
#include "../../RKDataFormats/interface/ObjectMET.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/ResonanceWithMET.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"


template <class T>
class ObjectMETValidator {
 public:
  TFile* file;
  TString prefix;
  
  ObjectMETValidator(){};
  ~ObjectMETValidator(){};

  void Fill(std::vector<T> objectmetcollection);
  void Fill(std::vector<T> objectmetcollection,Int_t howManyObj);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  // 1D Histograms 
  TH1F*    h_DeltaPhi[nobjectmet] ;
  TH1F*    h_TransMass[nobjectmet] ;
  // 2D Histograms
  TH2F* h_DeltaPhi_vs_TransMass[nobjectmet];
        
 protected:
  
 private:
  
};
#endif



template <class T>
void ObjectMETValidator<T>::Fill(std::vector<T> objectcollection){
  
  if(false) std::cout<<" num of jet-met pairs = "<<objectcollection.size()<<std::endl;
  
  
  // Fill properties of first di-jet combination made from 
  // selected leading jet and selected sub-leading jet. 
  
  // 1D Histograms 
  for( int i=0; i<(int)objectcollection.size();i++){
    if(i<2){
      h_DeltaPhi[i]     ->Fill(objectcollection[i].TransverseObjProp.DeltaPhi);
      h_TransMass[i]      ->Fill(objectcollection[i].TransverseObjProp.TransMass);
      
      // 2D Histograms
      if(false) std::cout<<" filling 2d "<<std::endl;
      h_DeltaPhi_vs_TransMass[i]   ->Fill(objectcollection[i].TransverseObjProp.DeltaPhi,objectcollection[0].TransverseObjProp.TransMass);
    }
  }

  
}





// This one is for Two-Objects + MET 
// Overloading the templated functions 
template <class T>
void ObjectMETValidator<T>::Fill(std::vector<T> objectcollection, Int_t howManyObj){
  
  if(false) std::cout<<" num of djet-met pairs = "<<objectcollection.size()<<std::endl;
  
  
  // Fill properties of first di-jet combination made from 
  // selected leading jet and selected sub-leading jet. 
  
  // 1D Histograms 
  for( int i=0; i<(int)objectcollection.size();i++){
    if(i<howManyObj){
      h_DeltaPhi[i]     ->Fill(objectcollection[i].ResonancemetProp.DeltaPhi);
      h_TransMass[i]      ->Fill(objectcollection[i].ResonancemetProp.TransMass);
      // 2D Histograms
      if(false) std::cout<<" filling 2d "<<std::endl;
      h_DeltaPhi_vs_TransMass[i]   ->Fill(objectcollection[i].ResonancemetProp.DeltaPhi,objectcollection[0].ResonancemetProp.TransMass);
    }
  }

  
}

template <class T>
void ObjectMETValidator<T>::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(false) std::cout<<" calling define histograms for Jets-MET "<<std::endl;
  DefineHistograms();
  if(false) std::cout<<" Jets-MET histo defined "<<std::endl;
}

template <class T>
void ObjectMETValidator<T>::DefineHistograms(){
  TString postfix;
  for(int i =0; i<2; i++){
    postfix.Form("%d",i);
    if(false) std::cout<<" ObjectMETValidator = "<<postfix<<std::endl;
    // 1D Histograms 
    h_DeltaPhi[i]                 = new TH1F("h_DeltaPhi"+postfix,"h_DeltaPhi"+postfix,70,-3.5,3.5);
    h_TransMass[i]                = new TH1F("h_TransMass"+postfix,"h_TransMass"+postfix,300,0,3000);
    // 2D Histograms
    h_DeltaPhi_vs_TransMass[i]    = new TH2F("h_DeltaPhi_vs_TransMass"+postfix,"h_DeltaPhi_vs_TransMass"+postfix,70,-3.5,3.5,300,0,3000);
  }
}

template <class T>
void ObjectMETValidator<T>::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  for(int i =0; i<2; i++){
    // 1D Histograms 
    h_DeltaPhi[i]               ->Write();
    h_TransMass[i]              ->Write();
    // 2D Histograms
    h_DeltaPhi_vs_TransMass[i]  ->Write();
  }
  
}
