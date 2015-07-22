#ifndef JET_H_
#define JET_H_

#include <iostream>
#include <TLorentzVector.h>
#include "MET.h"
#include "Muon.h"
#include "Electron.h"
using namespace std;

class Jet{
 public:
  
  Int_t  photon;
  Int_t  muon;
  Int_t  tau; // taking tau from muon
  Int_t  electron;
  
  Int_t nJets;
  TLorentzVector p4;
  Int_t charge;
  Int_t partonFlavor;
  
  Float_t B_SSV;
  Float_t B_CSV;
  Float_t B_SSVHE;
  Float_t B_CISVV2;
  Float_t B_TCHP;
  Float_t B_TCHE;
  Float_t B_JP;
  Float_t B_JBP;

  Float_t tau1;
  Float_t tau2;
  Float_t tau3;

  Float_t jetMuEF;
  Float_t jetPhoEF;
  Float_t jetCEmEF;
  Float_t jetCHadEF;
  Float_t jetNEmEF;
  Float_t jetNHadEF;
  Float_t jetCMulti;

  Float_t jetHFHadEF;
  Float_t jetHFEMEF;
  Int_t   jetCHHadMultiplicity;
  Int_t   jetNHadMulplicity;
  Int_t   jetPhMultiplicity;
  Int_t   jetEleMultiplicity;
  Int_t   jetHFHadMultiplicity;
  Int_t   jetHFEMMultiplicity;
  Float_t jetChMuEF;
  Int_t   jetNMultiplicity;
  Float_t jetHOEnergy;
  Float_t jetHOEF;

  Float_t mt;
  Float_t dphi;
  
  Bool_t ispT30_;
  Bool_t ispT50_;
  Bool_t ispT80_;
  Bool_t ispT100_;
  Bool_t iseta25_;
  Bool_t isCSVVL_;
  Bool_t isCSVL_;
  Bool_t isCSVMed_;
  Bool_t isCSVT_;
  Bool_t isLooseJet_;
  Bool_t isPUJet_;
  Int_t  nVtx;
  Int_t run;
  Int_t lumi;
  Int_t event;
  MET   met;
  bool operator== (Jet& other_){
    return((this->p4.Pt()==other_.p4.Pt()) && (this->charge == other_.charge));
  }
  
  void Clear(){
    jetHOEnergy=0.;
    jetHOEF=0.;
    nJets = 0;
    nVtx  = 0;
    ispT30_         =   false   ;
    ispT50_         =   false   ;
    ispT80_         =   false   ;
    ispT100_        =   false   ;
    iseta25_        =   false   ;
    isCSVVL_        =   false   ;
    isCSVL_         =   false   ;
    isCSVMed_       =   false   ;
    isCSVT_         =   false   ; 
    isLooseJet_     =   false   ;
    isPUJet_        =   false   ;
  }
};


#endif
