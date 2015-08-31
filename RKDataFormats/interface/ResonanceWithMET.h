#ifndef ResonanceWithMET_H_
#define ResonanceWithMET_H_

#include <iostream>
#include <TLorentzVector.h>

#include "Jet.h"
#include "MET.h"
#include "ObjectMET.h" 

#include "Jet.h"
#include "MET.h"
#include "ResonanceMETProp.h" 
#include "ObjectMET.h"
#include "Muon.h"
#include "Electron.h"
#include "Jet.h"
#include "MET.h"
#include "Muon.h"
#include "Electron.h"
#include <bitset>
#include "Event.h"
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

  std::bitset<16> cutsStatus;
  std::vector<Jet> jets;
  MET met;
  std::vector<Muon> muons;
  std::vector<Electron> electrons;
  Event events;
  
 private:
 protected:
  
};


#endif
