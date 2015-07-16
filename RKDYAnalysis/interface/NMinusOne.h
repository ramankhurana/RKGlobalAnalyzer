// Original class : NMinusOne.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves the N-1 and Cut Flow histograms. 
// This can be configured to do a lot more than these two tasks. 

#ifndef NMinusOne_h_
#define NMinusOne_h_
#define RKTS 4

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
#include "../../RKUtilities/interface/MonoHiggsCuts.h"

class NMinusOne {
 public:
  NMinusOne(){};
  ~NMinusOne(){};
  void  Fill(std::vector<Electron> objectCollection);
  void GetInputs(TFile* f, TString prefix_);
  void DefineHistograms();
  void Write();
  
  TString prefix;
  TFile* file;
  // Histograms CutFlow 

  TH1F*  h_IdEtaIn[RKTS];
  TH1F*  h_IdPhiIn[RKTS];
  TH1F*  h_Idfull5x5_sigmaIetaIeta[RKTS];
  TH1F*  h_IdhOverE[RKTS];
  TH1F*  h_Idd0[RKTS];
  TH1F*  h_Iddz[RKTS];
  TH1F*  h_IdeoverPInv[RKTS];
  TH1F*  h_IdisoRho[RKTS];
  TH1F*  h_IdexpectedMissingInnerHits[RKTS];
  TH1F*  h_IdpassConversionVeto[RKTS];
    std::map <TString, bitset<16> > cutsMap; 
  
  protected:

  private:

};
#endif
