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
  
  TLorentzVector MHTp4;
  std::bitset<26> cutsStatus;
  std::vector<Jet> jets;
  std::vector<Jet> thinjets;
  MET met;
  std::vector<Muon> muons;
  std::vector<Muon> taus;
  std::vector<Electron> electrons;
  Event events;
  
 private:
 protected:
  
};


#endif
