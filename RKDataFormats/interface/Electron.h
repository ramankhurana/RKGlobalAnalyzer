
// Original class : Electron.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015

#ifndef Electron_h_
#define Electron_h_
#include <iostream>
#include <TLorentzVector.h>
class Electron {
 public:
  // Variables for corrected Electron
  Electron(){};
  ~Electron(){};
  
  TLorentzVector p4;
  Int_t nElectron;
  Int_t charge;
  
  void Clear(){
    nElectron=0;
    charge=0;
  }
  protected:

  private:

};
#endif

