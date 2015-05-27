
// Original class : Muon.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015

#ifndef Muon_h_
#define Muon_h_
#include <iostream>
#include <TLorentzVector.h>
class Muon {
 public:
  // Variables for corrected Muon
  Muon(){};
  ~Muon(){};
  
  TLorentzVector p4;
  Int_t nMuon;
  Int_t charge;
  
  void Clear(){
    nMuon=0;
    charge=0;
  }
  protected:

  private:

};
#endif

