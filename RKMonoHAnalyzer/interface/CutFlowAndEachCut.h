// Original class : CutFlowAndEachCut.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves the N-1 and Cut Flow histograms. 
// This can be configured to do a lot more than these two tasks. 

#ifndef CutFlowAndEachCut_h_
#define CutFlowAndEachCut_h_
#define NOBJECTS 4

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH3F.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TString.h>
#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/ResonanceMET.h"
#include "../../RKDataFormats/interface/ResonanceWithMET.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h"

class CutFlowAndEachCut {
 public:
  CutFlowAndEachCut(){};
  ~CutFlowAndEachCut(){};
  void  CutFlow(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection);
  void  CutFlow(std::vector<ResonanceWithMET<Jet,MET > >  objectCollection);
  void  CutFlow(std::vector<ResonanceWithMET<Jet,MET > >  objectCollection, std::vector<int> statusbitVector);
  void GetInputs(TFile* f, TString prefix_);
  void DefineHistograms();
  void Write();
  
  TString prefix;
  TFile* file;
  // Histograms CutFlow 
  TH1F* h_cutflow[NOBJECTS];
  TH1F* h_eachcut[NOBJECTS];
  TH1F* h_cutflow_f[NOBJECTS];
  TH1F* h_eachcut_f[NOBJECTS];

  protected:

  private:

};
#endif
