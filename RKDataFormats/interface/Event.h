
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
  
  void Clear(){
    run=0;
    lumi=0;
    event=0;
    
  }
 protected:

 private:

};
#endif
