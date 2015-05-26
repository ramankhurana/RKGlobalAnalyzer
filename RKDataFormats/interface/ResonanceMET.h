#ifndef ResonanceMET_H_
#define ResonanceMET_H_

#include <iostream>
#include <TLorentzVector.h>

#include "Jet.h"
#include "MET.h"
#include "ResonanceMETProp.h" 
#include "ObjectMET.h"

#include <bitset>
using namespace std;
template <class T1,class T2>
class ResonanceMET{
 public:
  ResonanceMET(){ };
  ~ResonanceMET(){};
  ObjectMET ResonancemetProp;
  ObjectMET objMet1;
  ObjectMET objMet2;
  
  T1 jet1;
  T2 jet2;
  Int_t index_j1;
  std::bitset<16> cutsStatus;
  
 private:
 protected:
  
};


#endif
