// Original class : ABCDMethod.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class estimate the background using ABCD method. 

#ifndef ABCDMethod_h_
#define ABCDMethod_h_


#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/ResonanceMET.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TMath.h"
#define nobjectMet 1

class ABCDMethod {
 public:
  ABCDMethod(){};
  ~ABCDMethod(){};
  void Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  TString prefix;
  TFile* file;
  TH2F* h_Region;
  protected:

  private:

};
#endif
