#ifndef JET_H_
#define JET_H_

#include <iostream>
#include <TLorentzVector.h>
#include "Event.h"
using namespace std;

class Jet{
 public:
  
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
  Float_t tau4;
  Float_t jetPhoEF;
  Float_t jetCEmEF;
  Float_t jetCHadEF;
  Float_t jetNEmEF;
  Float_t jetNHadEF;
  Float_t jetCMulti;
  Float_t jetMuEF;
  
  // sub-jet variable information 
  Float_t SDmass;
  Float_t TRmass;
  Float_t PRmass;
  Float_t Fimass;
  
  Int_t nsubJets;
  std::vector<Float_t> SDPx;
  std::vector<Float_t> SDPy;
  std::vector<Float_t> SDPz;
  std::vector<Float_t> SDEn;
  std::vector<Float_t> SDCSV;
  std::vector<int> HadronFlavor;
  // additional Fat Jets
  Float_t doubleSV;
  Int_t   nSV;
  std::vector<Float_t> SVMass;
  
  Float_t muRUp;
  Float_t muRDown;
  Float_t muFUp;
  Float_t muFDown;
  std::vector<Float_t> pdfWeights;
  
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
  Event event;
  bool operator== (Jet& other_){
    return((this->p4.Pt()==other_.p4.Pt()) && (this->charge == other_.charge));
  }
  
  void Clear(){
    jetHOEnergy=0.;
    jetHOEF=0.;
    nJets = 0;
    nVtx  = 0;
    
    SDPx.clear();
    SDPy.clear();
    SDPz.clear();
    SDEn.clear();
    SDCSV.clear();
    HadronFlavor.clear();
    

    muRUp=0.;
    muRDown=0.;
    muFUp=0.;
    muFDown=0.;
    pdfWeights.clear();
    
    doubleSV=0.;
    nSV=0;
    SVMass.clear();
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
