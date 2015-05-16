// Original class : TwoObjectCombination.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

#ifndef TwoObjectCombination_h_
#define TwoObjectCombination_h_

#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/DiJet.h"
template <class U1, class U2>
class TwoObjectCombination {
 public:
  Resonance<U1,U2> resonanceCandidate;
  DiJet     dijetsCandidate;
  TwoObjectCombination(){};
  ~TwoObjectCombination(){};
  DiJet ResonanceProperties(TLorentzVector obj1, TLorentzVector obj2);
  std::vector<Resonance <U1,U2> > ReconstructDiObject(std::vector<U1> j1, std::vector<U2> j2);
  std::vector<Resonance <U1,U2> > ReconstructDiObject(std::vector<U1> j1);
  void Clear();
  

  std::vector<Resonance<U1,U2> > resonancevec;

 protected:
  
 private:
  
};
#endif


template <class U1, class U2> void TwoObjectCombination<U1,U2>::Clear(){
  resonancevec.clear();
  
}





template <class U1, class U2>
  std::vector<Resonance <U1,U2> > TwoObjectCombination<U1,U2>::ReconstructDiObject(std::vector<U1> j1){
  // Clean the vector before filling with desired values. 
  Clear();
  if(j1.size()>=2){
    if(RKDebugger::debug_TwoObjectCombination()) std::cout<<" inside dijet"<<std::endl;
    for(int i=0;i<(int)j1.size()-1;i++){
      for(int j=i+1;j<(int)j1.size();j++){
	//if(j1[i]==j1[j]) std::cout<<" they are same ==================== One should skip this "<<std::endl;
	if(j1[i]==j1[j]) continue; 
	resonanceCandidate.jet1 = j1[i];
	resonanceCandidate.jet2 = j1[j];
	resonanceCandidate.index_j1 = i;
	resonanceCandidate.index_j2 = j;
	resonanceCandidate.ResonanceProp = ResonanceProperties(j1[i].p4, j1[j].p4);
	resonancevec.push_back(resonanceCandidate);
      }
    }
  }
  if(RKDebugger::debug_TwoObjectCombination()) std::cout<<" size of resonancevec = "<<resonancevec.size()<<std::endl;
  return resonancevec;
}



template <class U1, class U2>
  std::vector<Resonance <U1,U2> > TwoObjectCombination<U1,U2>::ReconstructDiObject(std::vector<U1> j1, std::vector<U2> j2){
  // Clean the vector before filling with desired values. 
  Clear();
  if(j1.size()>=1 && j2.size()>=1){
    for(int i=0;i<(int)j1.size();i++){
      for(int j=0;j<(int)j2.size();j++){
	//if(j1[i]==j2[j]) std::cout<<" they are same ==================== One should skip this "<<std::endl;
	if(j1[i]==j2[j]) continue; 
	resonanceCandidate.jet1 = j1[i];
	resonanceCandidate.jet2 = j2[j];
	resonanceCandidate.index_j1 = i;
	resonanceCandidate.index_j2 = j;
	resonanceCandidate.ResonanceProp = ResonanceProperties(j1[i].p4, j2[j].p4);
	resonancevec.push_back(resonanceCandidate);
      }
    }
  }
  if(RKDebugger::debug_TwoObjectCombination()) std::cout<<" size of resonancevec = "<<resonancevec.size()<<std::endl;
  return resonancevec;
}


template<class U1, class U2> 
  DiJet TwoObjectCombination<U1,U2>::ResonanceProperties(TLorentzVector obj1, TLorentzVector obj2){
  TLorentzVector TwoObj = obj1 + obj2 ;
  dijetsCandidate.DeltaR        =  (obj1.DeltaR(obj2)) ;
  dijetsCandidate.DeltaPhi      = (obj1.DeltaPhi(obj2)); 
  dijetsCandidate.DeltaEta      =  (obj1.Eta() - obj2.Eta()) ;
  dijetsCandidate.InvMass       = (TwoObj.Mag());
  dijetsCandidate.Pt1OverPt2    =  (obj1.Pt()/obj2.Pt());
  dijetsCandidate.PtOverPt1Pt2  =  (TwoObj.Pt() /( obj1.Pt()+obj2.Pt() ) );
  dijetsCandidate.p4            = TwoObj;
  dijetsCandidate.p4_1          = obj1;
  dijetsCandidate.p4_2          = obj2;
  return dijetsCandidate;
}

