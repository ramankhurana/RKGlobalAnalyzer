// Original class : ObjectMETCombination.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

// This class is to combine MET and a physics object. 
// Either a jet or lepton, or any other primary object. 
// To combine secondary object (reconstructed using two primary object) with MET you need a differnt class. 
#ifndef ObjectMETCombination_h_
#define ObjectMETCombination_h_

#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/ResonanceWithMET.h"
#include "../../RKDataFormats/interface/ObjectMET.h"
#include "../../RKUtilities/interface/RKMath.h"
template <class U1, class U2>
class ObjectMETCombination {
 public:
  ResonanceWithMET<U1,U2> resonanceWithMETCandidate;
  ObjectMET     objectMETCandidate;
  ObjectMETCombination(){};
  ~ObjectMETCombination(){};
  ObjectMET ResonanceProperties(TLorentzVector obj1, U2 obj2);
  
  // Function to reconstruct
  std::vector<ResonanceWithMET <U1,U2> > ReconstructDiObject(std::vector<U1> j1, U2 j2);
  std::vector<ResonanceWithMET <U1,U2> > ReconstructDiObject(std::vector<U1> j1, U2 j2, std::string jettype);
  void Clear();
  

  std::vector<ResonanceWithMET<U1,U2> > resonancevec;

 protected:
  
 private:
  
};
#endif


template <class U1, class U2> void ObjectMETCombination<U1,U2>::Clear(){
  resonancevec.clear();
  
}


template <class U1, class U2>
  std::vector<ResonanceWithMET <U1,U2> > ObjectMETCombination<U1,U2>::ReconstructDiObject(std::vector<U1> j1, U2 j2){
  // Clean the vector before filling with desired values. 
  Clear();
  if(j1.size()>=1){
    for(int i=0;i<(int)j1.size();i++){
      resonanceWithMETCandidate.jet1 = j1[i];
      resonanceWithMETCandidate.jet2 = j2; // this is MET always 
      resonanceWithMETCandidate.index_j1 = i;
      resonanceWithMETCandidate.TransverseObjProp = ResonanceProperties(j1[i].p4, j2);
      resonancevec.push_back(resonanceWithMETCandidate);
    }
  }
  return resonancevec;
}


// For Fat Jets
template <class U1, class U2>
  std::vector<ResonanceWithMET <U1,U2> > ObjectMETCombination<U1,U2>::ReconstructDiObject(std::vector<U1> j1, U2 j2, std::string jettype){
  // Clean the vector before filling with desired values. 
  Clear();
  if(j1.size()>=1){
    for(int i=0;i<(int)j1.size();i++){
      resonanceWithMETCandidate.jet1 = j1[i];
      resonanceWithMETCandidate.jet2 = j2; // this is MET always 
      resonanceWithMETCandidate.index_j1 = i;
      resonanceWithMETCandidate.TransverseObjProp = ResonanceProperties(j1[i].p4, j2);
      if(jettype=="FATJET"){
	std::cout<<" fill this up "<<std::endl;
      }
      resonancevec.push_back(resonanceWithMETCandidate);
    }
  }
  return resonancevec;
}


template<class U1, class U2> 
  ObjectMET ObjectMETCombination<U1,U2>::ResonanceProperties(TLorentzVector obj1, U2 obj2){
  //float dphi = obj1.Phi() - obj2.RawPhi ;
  Float_t dphi = RKMath::DeltaPhi(obj1.Phi(), obj2.RawPhi);
  // correction the phi definition 
  objectMETCandidate.DeltaPhi      = dphi;
  objectMETCandidate.p4_1          = obj1;
  objectMETCandidate.TransMass     = TMath::Sqrt( 2 * obj1.Pt() * obj2.RawPt * (1-TMath::Cos(dphi)) );
  return objectMETCandidate;
}

