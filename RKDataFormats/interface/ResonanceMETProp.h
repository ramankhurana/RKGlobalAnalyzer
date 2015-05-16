
// Original class : TwoBodyDecay.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015
// ---------
// This small class takes two LorentzVectors as Input and then you can access few of the 
// derived functions out of the box from this class. Functions are listed here. 
// Most of them are Implemented here inline. 
// ---------


#ifndef ResonanceMETProp_h_
#define ResonanceMETProp_h_
#include <iostream>
#include <TLorentzVector.h>
class ResonanceMETProp {
 public:
  // Variables for corrected ResonanceMETProp
  ResonanceMETProp(){};
  ~ResonanceMETProp(){};
  TLorentzVector p4_1;
  Float_t DeltaPhi;
  Float_t TransMass;
  
  protected:

  private:
};
#endif

