#ifndef Resonance_H_
#define Resonance_H_

#include <iostream>
#include <TLorentzVector.h>

#include "Jet.h"
#include "MET.h"
#include "DiJet.h" // change this class name"

using namespace std;
template <class T1,class T2>
class Resonance{
 public:
  Resonance(){ };
  ~Resonance(){};
  DiJet ResonanceProp;
  T1 jet1;
  T2 jet2;
  Int_t index_j1;
  Int_t index_j2;
  
 private:
 protected:
  
};


#endif
