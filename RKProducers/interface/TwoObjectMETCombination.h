// Original class : TwoObjectMETCombination.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

#ifndef TwoObjectMETCombination_h_
#define TwoObjectMETCombination_h_

#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Jet.h"
//#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/DiJet.h"
#include "../../RKDataFormats/interface/ResonanceMET.h"
#include "../../RKDataFormats/interface/ResonanceMETProp.h"
#include "../../RKDataFormats/interface/ObjectMET.h"

template <class U1, class U2>
class TwoObjectMETCombination {
 public:
  ResonanceMET<U1,U2> resonanceMETCandidate;
  //ResonanceMETProp     resonancemetprop;
  ObjectMET resonancemetprop;
  ObjectMET            objmet;
  TwoObjectMETCombination(){};
  ~TwoObjectMETCombination(){};
  //ResonanceMETProp ResonanceMETProperties(TLorentzVector obj1, U2 obj2);
  ObjectMET ResonanceMETProperties(TLorentzVector obj1, U2 obj2);
  std::vector<ResonanceMET <U1,U2> > ReconstructDiObject(std::vector<U1> j1, U2 j2);
  void Clear();
  

  std::vector<ResonanceMET<U1,U2> > resonancemetvec;

 protected:
  
 private:
  
};
#endif


template <class U1, class U2> void TwoObjectMETCombination<U1,U2>::Clear(){
  resonancemetvec.clear();
  
}


template <class U1, class U2>
  std::vector<ResonanceMET <U1,U2> > TwoObjectMETCombination<U1,U2>::ReconstructDiObject(std::vector<U1> j1, U2 j2){
  // Clean the vector before filling with desired values. 
  Clear();
  if(j1.size()>=1){
    for(int i=0;i<(int)j1.size();i++){
      resonanceMETCandidate.jet1 = j1[i];
      resonanceMETCandidate.jet2 = j2;
      resonanceMETCandidate.index_j1 = i;
      resonanceMETCandidate.ResonancemetProp = ResonanceMETProperties(j1[i].ResonanceProp.p4, j2);
      resonanceMETCandidate.objMet1          = ResonanceMETProperties(j1[i].jet1.p4, j2);
      resonanceMETCandidate.objMet2          = ResonanceMETProperties(j1[i].jet2.p4, j2);
      resonanceMETCandidate.DPHI_MET_J       = TMath::Min(resonanceMETCandidate.objMet1.DeltaPhi, resonanceMETCandidate.objMet2.DeltaPhi);
      resonancemetvec.push_back(resonanceMETCandidate);
    }
  }
  return resonancemetvec;
}

  
template<class U1, class U2> 
  ObjectMET TwoObjectMETCombination<U1,U2>::ResonanceMETProperties(TLorentzVector obj1, U2 obj2){
  Float_t dphi = RKMath::DeltaPhi(obj1.Phi(),obj2.RawPhi) ;
  resonancemetprop.DeltaPhi      = dphi;
  resonancemetprop.TransMass     = TMath::Sqrt( 2 * obj1.Pt() * obj2.RawPt * (1-TMath::Cos(dphi)) );
  resonancemetprop.p4_1          = obj1;
  return resonancemetprop;
}

