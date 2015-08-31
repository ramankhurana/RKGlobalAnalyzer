// Original class : JetValidator.h
// Created By     : ramankhurana 
// Created On     : Sun Apr 26 18:26:44 CEST 2015

#ifndef JetValidator_h_
#define JetValidator_h_

#define NJETS  4
#define NSJ    2
#include "../../RKDataFormats/interface/Jet.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"

class JetValidator {
 public:
  TFile* file;
  TString prefix;
  
  JetValidator(){};
  ~JetValidator(){};

  void Fill(std::vector<Jet> jetcollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  TLorentzVector subjetp4;
  // 1D Histograms 
  TH1F*    h_nJets                 ;
  TH1F*    h_pt                    ;
  TH1F*    h_eta                   ;
  TH1F*    h_phi                   ;
  TH1F*    h_charge                ;
  TH1F*    h_partonFlavor          ;
  TH1F*    h_B_SSV                 ;
  TH1F*    h_B_CSV                 ;
  TH1F*    h_B_SSVHE               ;
  TH1F*    h_B_CISVV2              ;
  TH1F*    h_B_TCHP                ;
  TH1F*    h_B_TCHE                ;
  TH1F*    h_B_JP                  ;
  TH1F*    h_B_JBP                 ;
  TH1F*    h_tau1                  ;
  TH1F*    h_tau2                  ;
  TH1F*    h_tau3                  ;
  TH1F*    h_jetMuEF               ;
  TH1F*    h_jetPhoEF              ;
  TH1F*    h_jetCEmEF              ;
  TH1F*    h_jetCHadEF             ;
  TH1F*    h_jetNEmEF              ;
  TH1F*    h_jetNHadEF             ;
  TH1F*    h_jetCMulti             ;
  TH1F*    h_jetHFHadEF            ;
  TH1F*    h_jetHFEMEF             ;
  TH1F*    h_jetCHHadMultiplicity  ;
  TH1F*    h_jetNHadMulplicity     ;
  TH1F*    h_jetPhMultiplicity     ;
  TH1F*    h_jetEleMultiplicity    ;
  TH1F*    h_jetHFHadMultiplicity  ;
  TH1F*    h_jetHFEMMultiplicity   ;
  TH1F*    h_jetChMuEF             ;
  TH1F*    h_jetNMultiplicity      ;
  TH1F*    h_jetHOEnergy           ;
  TH1F*    h_jetHOEF               ;
  
  TH1F*    h_tau21                 ;

  TH1F* h_SDmass[NJETS];
  TH1F* h_TRmass[NJETS];
  TH1F* h_PRmass[NJETS];
  TH1F* h_Fimass[NJETS];
  TH1F* h_nsubJets[NJETS];

  
  TH1F*  h_SJ_pt [NJETS][NSJ] ;
  TH1F*  h_SJ_csv[NJETS][NSJ] ;
  TH1F*  h_SJ_eta[NJETS][NSJ] ;
  TH1F*  h_SJ_phi[NJETS][NSJ] ;
  
  
  TH1F*    h_pt_vec[NJETS]                    ;
  TH1F*    h_eta_vec[NJETS]                   ;
  TH1F*    h_phi_vec[NJETS]                   ;
  TH1F*    h_charge_vec[NJETS]                ;
  TH1F*    h_partonFlavor_vec[NJETS]          ;
  TH1F*    h_B_SSV_vec[NJETS]                 ;
  TH1F*    h_B_CSV_vec[NJETS]                 ;
  TH1F*    h_B_SSVHE_vec[NJETS]               ;
  TH1F*    h_B_CISVV2_vec[NJETS]              ;
  TH1F*    h_B_TCHP_vec[NJETS]                ;
  TH1F*    h_B_TCHE_vec[NJETS]                ;
  TH1F*    h_B_JP_vec[NJETS]                  ;
  TH1F*    h_B_JBP_vec[NJETS]                 ;
  TH1F*    h_tau1_vec[NJETS]                  ;
  TH1F*    h_tau2_vec[NJETS]                  ;
  TH1F*    h_tau3_vec[NJETS]                  ;
  TH1F*    h_jetMuEF_vec[NJETS]               ;
  TH1F*    h_jetPhoEF_vec[NJETS]              ;
  TH1F*    h_jetCEmEF_vec[NJETS]              ;
  TH1F*    h_jetCHadEF_vec[NJETS]             ;
  TH1F*    h_jetNEmEF_vec[NJETS]              ;
  TH1F*    h_jetNHadEF_vec[NJETS]             ;
  TH1F*    h_jetCMulti_vec[NJETS]             ;
  TH1F*    h_jetHFHadEF_vec[NJETS]            ;
  TH1F*    h_jetHFEMEF_vec[NJETS]             ;
  TH1F*    h_jetCHHadMultiplicity_vec[NJETS]  ;
  TH1F*    h_jetNHadMulplicity_vec[NJETS]     ;
  TH1F*    h_jetPhMultiplicity_vec[NJETS]     ;
  TH1F*    h_jetEleMultiplicity_vec[NJETS]    ;
  TH1F*    h_jetHFHadMultiplicity_vec[NJETS]  ;
  TH1F*    h_jetHFEMMultiplicity_vec[NJETS]   ;
  TH1F*    h_jetChMuEF_vec[NJETS]             ;
  TH1F*    h_jetNMultiplicity_vec[NJETS]      ;
  TH1F*    h_jetHOEnergy_vec[NJETS]           ;
  TH1F*    h_jetHOEF_vec[NJETS]               ;
  
  TH1F*    h_tau21_vec[NJETS]                 ;
  
    // 2D Histograms

  // 
 protected:
  
 private:
  
};
#endif

