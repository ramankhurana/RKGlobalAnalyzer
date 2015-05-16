
// Original class : TwoBodyDecay.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015

#define TwoBodyDecay_cxx
#include "../interface/TwoBodyDecay.h"

std::vector<Resonance> TwoBodyDecay::ReconstructDiObject(std::vector<Jet> j1, std::vector<Jet> j2){
  if(j1.size()>=2){
    resonanceCandidate.jet1 = j1[0];
    resonanceCandidate.jet2 = j2[1];
    resonanceCandidate.index_j1 = 0;
    resonanceCandidate.index_j2 = 1;
    resonanceCandidate.ResonanceP4 = ResonanceProperties(j1[0].p4, j1[1].p4);
  }
}





DiJet TwoBodyDecay::ResonanceProperties(TLorentzVector obj1, TLorentzVector obj2){
  obj1_ = obj1;
  obj2_ = obj2;
  TwoObj_ = obj1_ + obj2_ ;
  dijetsCandidate.DeltaR        =  (obj1_.DeltaR(obj2_)) ;
  dijetsCandidate.DeltaPhi      = (obj1_.DeltaPhi(obj2_)); 
  dijetsCandidate.DeltaEta      =  (obj1_.Eta() - obj2_.Eta()) ;
  dijetsCandidate.InvMass       = (TwoObj_.Mag());
  dijetsCandidate.Pt1OverPt2    =  (obj1_.Pt()/obj2_.Pt());
  dijetsCandidate.PtOverPt1Pt2  =  (TwoObj_.Pt() /( obj1_.Pt()+obj2_.Pt() ) );
  dijetsCandidate.p4            = TwoObj_;
  dijetsCandidate.p4_1          = obj1;
  dijetsCandidate.p4_2          = obj2;




}
