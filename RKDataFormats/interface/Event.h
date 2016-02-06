
// Original class : Event.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015

#ifndef Event_h_
#define Event_h_
#include <iostream>
#include <TLorentzVector.h>
class Event {
 public:
  // Variables for corrected Event
  Event(){};
  ~Event(){};
  
  TLorentzVector p4;
  Int_t run;
  Int_t lumi;
  Int_t event;
  Float_t mcweight;
  Float_t puweight;
  Float_t allmcweight;
  Int_t nvtx;
  double EWKreweight;
  Bool_t isdata;
  void Clear()
  {
    isdata=false;
    run=0;
    lumi=0;
    event=0;
    mcweight = 0.;
    puweight = 0.;
    allmcweight=0.;
    nvtx=0;
    EWKreweight = 0.0;
  }
  protected:

  private:

};
#endif

