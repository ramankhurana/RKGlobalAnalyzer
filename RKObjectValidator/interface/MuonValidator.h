// Original class : MuonValidator.h
// Created By     : ramanmonika khurana 
// Created On     : Sun Apr 26 18:26:44 CEST 2015

#ifndef MuonValidator_h_
#define MuonValidator_h_

#define nMUON  4
#include "../../RKDataFormats/interface/Muon.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"

class MuonValidator {
 public:
  TFile* file;
  TString prefix;
  
  MuonValidator(){};
  ~MuonValidator(){};

  void Fill(std::vector<Muon> muoncollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  // 1D Histograms 
  TH1F*  h_pt[nMUON];
  TH1F*  h_eta[nMUON];
  TH1F*  h_phi[nMUON];
  TH1F*  h_mass[nMUON];
  TH1F*  h_nMu;
  TH1F*  h_Type[nMUON];
  TH1F*  h_Charge[nMUON];
  TH1F*  h_IsGlobalMuon[nMUON];
  TH1F*  h_IsTrackerMuon[nMUON];
  TH1F*  h_IsPFMuon[nMUON];
  TH1F*  h_TrkPt[nMUON];
  TH1F*  h_TrkPtErr[nMUON];
  TH1F*  h_dxy[nMUON];
  TH1F*  h_dz[nMUON];
  TH1F*  h_segmentCompatibility[nMUON];
  TH1F*  h_chi2LocalPosition[nMUON];
  TH1F*  h_trkKink[nMUON];
  TH1F*  h_Innerdxy_[nMUON];
  TH1F*  h_Innerdz_[nMUON];
  TH1F*  h_TrkLayers[nMUON];
  TH1F*  h_PixelLayers[nMUON];
  TH1F*  h_PixelHits[nMUON];
  TH1F*  h_TrkQuality_[nMUON];
  TH1F*  h_Hits[nMUON];
  TH1F*  h_Chi2NDF[nMUON];
  TH1F*  h_InnervalidFraction_[nMUON];
  TH1F*  h_Matches[nMUON];
  TH1F*  h_ITrkID[nMUON];
  TH1F*  h_SegID[nMUON];
  TH1F*  h_NSegs[nMUON];
  TH1F*  h_IsGood_TrackerMuonArbitrated[nMUON];
  TH1F*  h_IsGood_TMOneStationTight[nMUON];
  TH1F*  h_TrkIso[nMUON];
  TH1F*  h_HcalIso[nMUON];
  TH1F*  h_EcalIso[nMUON];
  TH1F*  h_ChHadIso[nMUON];
  TH1F*  h_NeHadIso[nMUON];
  TH1F*  h_GamIso[nMUON];
  TH1F*  h_PUPt[nMUON];
  
    // 2D Histograms

  // 
 protected:
  
 private:
  
};
#endif

