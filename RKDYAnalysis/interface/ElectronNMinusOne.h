// Original class : ElectronNMinusOne.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves the N-1 and Cut Flow histograms. 
// This can be configured to do a lot more than these two tasks. 

#ifndef ElectronNMinusOne_h_
#define ElectronNMinusOne_h_
#define RKVARS 10

#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH3F.h>
#include <TProfile.h>
#include <TProfile2D.h>
#include <TString.h>
#include "ElectronSelectionBitsProducer.h"
#include "../../RKDataFormats/interface/Electron.h"
//#include "../../RKDataFormats/interface/Jet.h"
//#include "../../RKDataFormats/interface/MET.h"
//#include "../../RKDataFormats/interface/Resonance.h"
//#include "../../RKDataFormats/interface/ResonanceMET.h"
//#include "../../RKUtilities/interface/MonoHiggsCuts.h"

class ElectronNMinusOne {
 public:
  ElectronNMinusOne(){};
  ~ElectronNMinusOne(){};
  void  Fill(std::vector<Electron> objectCollection);
  void GetInputs(TFile* f, TString prefix_);
  void DefineHistograms();
  void Write();
  
  TString prefix;
  TFile* file;
  // Histograms CutFlow 
  Float_t mcweight_;
  TH1F*  h_IdEtaIn[RKVARS];
  TH1F*  h_IdPhiIn[RKVARS];
  TH1F*  h_Idfull5x5_sigmaIetaIeta[RKVARS];
  TH1F*  h_IdhOverE[RKVARS];
  TH1F*  h_Idd0[RKVARS];
  TH1F*  h_Iddz[RKVARS];
  TH1F*  h_IdeoverPInv[RKVARS];
  TH1F*  h_IdisoRho[RKVARS];
  TH1F*  h_IdexpectedMissingInnerHits[RKVARS];
  TH1F*  h_IdpassConversionVeto[RKVARS];
  std::map <TString, bitset<16> > ElectroncutsMap; 
  
  protected:

  private:

};
#endif
