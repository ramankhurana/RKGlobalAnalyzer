
// Original class : TwoBodyDecay.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015
// ---------
// This small class takes two LorentzVectors as Input and then you can access few of the 
// derived functions out of the box from this class. Functions are listed here. 
// Most of them are Implemented here inline. 
// ---------


#ifndef DiJet_h_
#define DiJet_h_
#include <iostream>
#include <TLorentzVector.h>
class DiJet {
 public:
  // Variables for corrected DiJet
  DiJet(){};
  ~DiJet(){};
  TLorentzVector p4;
  TLorentzVector p4_1;
  TLorentzVector p4_2;
  Float_t DeltaR;
  Float_t DeltaPhi;
  Float_t DeltaEta;
  Float_t InvMass;
  Float_t Pt1OverPt2;
  Float_t PtOverPt1Pt2;
  Float_t PtOverMass_1;
  Float_t PtOverMass_2;
  protected:

  private:
};
#endif

