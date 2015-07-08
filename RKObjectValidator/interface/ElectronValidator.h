// Original class : ElectroValidator.h
// Created By     : ramanmonika khurana 
// Created On     : Sun Apr 26 18:26:44 CEST 2015

#ifndef ElectroValidator_h_
#define ElectroValidator_h_

#define nELECTRONS  4
#include "../../RKDataFormats/interface/Electron.h"
#include <vector>
#include <iostream>
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TProfile.h"
#include "TProfile2D.h"
#include "TFile.h"

class ElectroValidator {
 public:
  TFile* file;
  TString prefix;
  
  ElectroValidator(){};
  ~ElectroValidator(){};

  void Fill(std::vector<Electron> electroncollection);
  void DefineHistograms();
  void GetInputs(TFile* f, TString prefix_);
  void Write();
  
  // 1D Histograms 
  TH1F*     h_pt[nELECTRONS];                    
  TH1F*     h_eta[nELECTRONS];   
  
  TH1F*     h_phi[nELECTRONS];                                                                            
  
  TH1F*     h_IsPassVeto[nELECTRONS]; 
  TH1F*     h_IsPassLoose[nELECTRONS]; 
  TH1F*     h_IsPassMedium[nELECTRONS]; 
  TH1F*     h_IsPassTight[nELECTRONS]; 
  TH1F*     h_IsPassHEEP[nELECTRONS];  
  TH1F*     h_IsMVATrig[nELECTRONS];  //Add This
  TH1F*     h_IsMVANonTrig[nELECTRONS];
  TH1F*     h_MVATrig[nELECTRONS];
  TH1F*     h_MVANonTrig[nELECTRONS];
  
  TH1F*     h_nElectron;
  TH1F*     h_charge[nELECTRONS];
  TH1F*     h_r9[nELECTRONS];
  
  TH1F*     h_etSC[nELECTRONS];
  TH1F*     h_etaSC[nELECTRONS];
  TH1F*     h_energySC[nELECTRONS];
  TH1F*     h_preenergySC[nELECTRONS];
  TH1F*     h_phiSC[nELECTRONS];
  TH1F*     h_dEtaIn[nELECTRONS];
  TH1F*     h_dPhiIn[nELECTRONS];
  TH1F*     h_hOverE[nELECTRONS];
  TH1F*     h_full5x5_sigmaIetaIeta[nELECTRONS];
  TH1F*     h_eoverP[nELECTRONS];
  TH1F*     h_eoverPInv[nELECTRONS];
  TH1F*     h_brem[nELECTRONS];
  TH1F*     h_dEtaVtx[nELECTRONS];
  TH1F*     h_dPhiVtx[nELECTRONS];
  TH1F*     h_isoChargedHadrons[nELECTRONS];
  TH1F*     h_isoNeutralHadrons[nELECTRONS];
  TH1F*     h_isoPhotons[nELECTRONS];
  TH1F*     h_isoChargedFromPU[nELECTRONS]; //add in main code
  TH1F*     h_isoDeltaBeta[nELECTRONS];
  TH1F*     h_isoRho[nELECTRONS];
  TH1F*     h_ooEmooP[nELECTRONS];
  TH1F*     h_d0[nELECTRONS];     //fix it 
  TH1F*     h_dz[nELECTRONS];
  TH1F*     h_expectedMissingInnerHits[nELECTRONS];
  TH1F*     h_passConversionVeto[nELECTRONS];
  TH1F*     h_barrel[nELECTRONS]; 
  TH1F*     h_endcap[nELECTRONS];                            
  
    // 2D Histograms

  // 
 protected:
  
 private:
  
};
#endif

