// Original class : Synchronization.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves histograms wspecific for Mono-H analysis.
//  -- these includes variables which are not covered in other histo classes

#ifndef Synchronization_h_
#define Synchronization_h_


#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/ResonanceMET.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TMath.h"
#define nobjectmet 2


class Synchronization {
 public:
  Synchronization(){};
  ~Synchronization(){};
  void Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, std::vector<Jet> jetcollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  TString prefix;
  TFile* file;
  TH1F* sync_;
  protected:

  private:

};
#endif
