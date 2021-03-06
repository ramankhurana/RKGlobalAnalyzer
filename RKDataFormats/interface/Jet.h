#ifndef JET_H_
#define JET_H_

#include <iostream>
#include <TLorentzVector.h>

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
  bool operator== (Jet& other_){
    return((this->p4.Pt()==other_.p4.Pt()) && (this->charge == other_.charge));
  }
  
  void Clear(){
    jetHOEnergy=0.;
    jetHOEF=0.;
    nJets = 0;
    
  }
};


#endif
