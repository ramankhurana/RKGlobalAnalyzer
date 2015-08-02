#ifndef ResonanceWithMET_H_
#define ResonanceWithMET_H_

#include <iostream>
#include <TLorentzVector.h>

#include "Jet.h"
#include "MET.h"
#include "ObjectMET.h" 

using namespace std;
template <class T1,class T2>
class ResonanceWithMET{
 public:
  ResonanceWithMET(){ };
  ~ResonanceWithMET(){};
  ObjectMET TransverseObjProp;
  T1 jet1;
  T2 jet2;

  Int_t index_j1;

  
 private:
 protected:
  
};


#endif
