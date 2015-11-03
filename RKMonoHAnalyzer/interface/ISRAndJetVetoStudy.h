// Original class : ISRAndJetVetoStudy.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves histograms wspecific for Mono-H analysis.
//  -- these includes variables which are not covered in other histo classes

#ifndef ISRAndJetVetoStudy_h_
#define ISRAndJetVetoStudy_h_


#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/ResonanceMET.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h"
#include "../../RKUtilities/interface/RKMath.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TMath.h"
#define naddjet 3


class ISRAndJetVetoStudy {
 public:
  ISRAndJetVetoStudy(){};
  ~ISRAndJetVetoStudy(){};
  void Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs, std::vector<int> bitVec);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  Int_t nobjectmet_;
  
  TString prefix;
  
  TFile* file;
  TH1F*    h_nAddJets[5];
  TH1F*    h_DeltaRLeadingB[naddjet][5];
  TH1F*    h_DeltaRSubLeadingB[naddjet][5];
  TH1F*    h_DeltaRClosestB[naddjet][5];
  
  TH1F*    h_pTAddJet[naddjet];
  
  TH2F*    h_pT_vs_DR[naddjet];
  protected:

  private:

};
#endif
