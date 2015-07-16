// Original class : HistFactory.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves histograms wspecific for Mono-H analysis.
//  -- these includes variables which are not covered in other histo classes

#ifndef HistFactory_h_
#define HistFactory_h_


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


class HistFactory {
 public:
  HistFactory(){};
  ~HistFactory(){};
  void Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  TString prefix;
  TFile* file;
  TH1F*    h_nMuons[nobjectmet];
  TH1F*    h_nElectrons[nobjectmet];
  TH1F*    h_nJets[nobjectmet];
  TH1F*    h_Q1Q2[nobjectmet];
  TH1F*    h_MET[nobjectmet];
  TH1F*    h_Mjj[nobjectmet];
  TH1F*    h_pTjj[nobjectmet];
  TH1F*    h_CSVMax[nobjectmet];
  TH1F*    h_CSVMin[nobjectmet];
  TH1F*    h_CSVSum[nobjectmet];
  TH1F*    h_dPhi_MET_J[nobjectmet];
  
  TH2F*    h_M_vs_MET[nobjectmet];
  TH2F*    h_MET_vs_Q1Q2[nobjectmet];
  TH2F*    h_M_vs_Q1Q2[nobjectmet];

  protected:

  private:

};
#endif
