
// Original class : TwoBodyDecay.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015
// ---------
// This small class takes two LorentzVectors as Input and then you can access few of the 
// derived functions out of the box from this class. Functions are listed here. 
// Most of them are Implemented here inline. 
// ---------


#ifndef TwoBodyDecay_h_
#define TwoBodyDecay_h_
#include <iostream>
#include <TLorentzVector.h>
class TwoBodyDecay {
 public:
  // Variables for corrected TwoBodyDecay
  TwoBodyDecay(){};
  void GetValues(TLorentzVector obj1, TLorentzVector obj2);
  ~TwoBodyDecay(){};
  
  Float_t DeltaR() {return (obj1_.DeltaR(obj2_));}
  Float_t DeltaPhi(){return (obj1_.DeltaPhi(obj2_));}
  Float_t DeltaEta(){return (obj1_.Eta() - obj2_.Eta());}
  Float_t InvMass(){ return (TwoObj_.Mag());}
  Float_t Pt(){return (TwoObj_.Pt());}
  Float_t Eta(){return (TwoObj_.Eta()) ;}
  Float_t Phi(){return (TwoObj_.Phi());}
  Float_t Energy(){return (TwoObj_.Energy());}
  Float_t Pt1OverPt2(){return (obj1_.Pt()/obj2_.Pt());}
  Float_t PtOverPt1Pt2(){return (  TwoObj_.Pt() /( obj1_.Pt()+obj2_.Pt() ) );}
  
  protected:

  private:
  TLorentzVector obj1_;
  TLorentzVector obj2_;
  TLorentzVector TwoObj_;
};
#endif

