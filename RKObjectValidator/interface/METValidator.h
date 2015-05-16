// Original class : METValidator.h
// Created By     : ramankhurana 
// Created On     : Sun Apr 26 18:26:44 CEST 2015

#ifndef METValidator_h_
#define METValidator_h_

#include "../../RKDataFormats/interface/MET.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"

class METValidator {
 public:
  TFile* file;
  TString prefix;
  
  METValidator(){};
  ~METValidator(){};

  void Fill(MET metcollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();

  // 1D Histograms 
  TH1F*    h_CorrPt       ;
  TH1F*    h_CorrPhi	  ;
  TH1F*    h_CorrSumEt	  ;
  TH1F*    h_CorrSig	  ;
  TH1F*    h_RawPt  	  ;
  TH1F*    h_RawPhi	  ;
  TH1F*    h_RawSumEt	  ;
  TH1F*    h_RawCov00	  ;
  TH1F*    h_RawCov01	  ;
  TH1F*    h_RawCov10	  ;
  TH1F*    h_RawCov11	  ;
  TH1F*    h_mvaPt	  ;
  TH1F*    h_mvaPhi	  ;
  TH1F*    h_mvaSumEt	  ;
  TH1F*    h_mvaSig       ;
  
    // 2D Histograms

  // 
 protected:
  
 private:
  
};
#endif

