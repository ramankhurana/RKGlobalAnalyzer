
// Original class : DiJet.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015

#define DiJet_cxx
#include "../interface/DiJet.h"
void DiJet::GetValues(TLorentzVector obj1, TLorentzVector obj2){
  obj1_ = obj1;
  obj2_ = obj2;
  TwoObj_ = obj1_ + obj2_ ;
}
