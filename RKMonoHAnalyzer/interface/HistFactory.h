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
#include "../../RKDataFormats/interface/ResonanceWithMET.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h"
#include "../../RKUtilities/interface/RKMath.h"
#include "../../RKUtilities/interface/BTagCalibrationStandalone.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TMath.h"
#include "TTree.h"
#include "TBranch.h"
#define nobjectmet 2


class HistFactory {
 public:
  HistFactory(){};
  ~HistFactory(){};
  BTagCalibration* calib;
  
  // for central value 
  BTagCalibrationReader* readerHF;
  BTagCalibrationReader* readerLF;
  
  
  
  /*
  // for sys up value 
  BTagCalibrationReader* readerHF_up;
  BTagCalibrationReader* readerLF_up;  
  

  // for sys down value 
  BTagCalibrationReader* readerHF_down;
  BTagCalibrationReader* readerLF_down;  
  */
  
void Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, Int_t howManyObjs, std::vector<int> bitVec);
  void Fill(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, Int_t howManyObjs, std::vector<int> bitVec, std::vector<TString> eventlist);
  void DefineHistograms();
  virtual void GetInputs(TFile* f, TString prefix_, std::string mode1 = "central",std::string mode2="central");
  void Write();
  double weightBtag(double pt, double eta, unsigned int flav) ;
  TString prefix;
  TFile* file;
  TTree*   skimTree;
  TH2F*    h_dPhi_MT_[nobjectmet];
  TH2F*    h_dPhi_MT_4Bin_[nobjectmet];
  TH2F*    h_dPhi_CSV_4Bin_[nobjectmet];
  TH2F*    h_dPhi_CSV_[nobjectmet];
  TH1F*    h_nMuons[nobjectmet];
  TH1F*    h_nTaus[nobjectmet];
  TH1F*    h_nElectrons[nobjectmet];
  TH1F*    h_nJets[nobjectmet];
  TH1F*    h_nFJets[nobjectmet];
  TH1F*    h_NThinJets[nobjectmet];
  TH1F*    h_dPhiThinJetMET[nobjectmet];
  TH1F*    h_DRSJ[nobjectmet];
  TH1F*    h_Q1Q2[nobjectmet];
  TH1F*    h_MET[nobjectmet];
  TH1F*    h_MHT[nobjectmet];
  TH1F*    h_Mjj[nobjectmet];
  TH1F*    h_pTjj[nobjectmet];
  TH1F*    h_etajj[nobjectmet];
  TH1F*    h_phijj[nobjectmet];
  TH1F*    h_Tau21jj[nobjectmet];
  TH1F*    h_CSVMax[nobjectmet];
  TH1F*    h_CSVMin[nobjectmet];
  TH1F*    h_CSV1[nobjectmet];
  TH1F*    h_CSV2[nobjectmet];
  TH1F*    h_CSVSum[nobjectmet];
  TH1F*    h_dPhi_MET_J[nobjectmet];
  TH1F*    h_MT_bb_MET[nobjectmet];
  TH1F*    h_dPhi_bb_MET[nobjectmet];
  
  TH1F*    h_MET_Over_SumET[nobjectmet];
  TH1F*    h_MET_Over_pTFatJet[nobjectmet];
  TH1F*    h_CEmEF[nobjectmet];
  TH1F*    h_CHadEF[nobjectmet];
  TH1F*    h_PhoEF[nobjectmet];
  TH1F*    h_NEmEF[nobjectmet];
  TH1F*    h_NHadEF[nobjectmet];
  TH1F*    h_MuEF[nobjectmet];
  TH1F*    h_CMulti[nobjectmet];
  
  TH2F*    h_M_vs_MET[nobjectmet];
  TH2F*    h_MET_vs_Q1Q2[nobjectmet];
  TH2F*    h_M_vs_Q1Q2[nobjectmet];
  
  //--------------------
  // Adding tree varibales for more debugging.
  //--------------------
  Int_t       run_;
  Int_t       lumi_;
  Int_t       event_;
  Float_t     dphiMin_;
  Int_t       nthinjets_;
  Float_t     MT_;
  Float_t     CSV1_;
  Float_t     CSV2_;
  Float_t     MHT_;
  Int_t       NAddMu_;
  Int_t       NAddEle_;
  Int_t       NAddTau_;
  Int_t       NAddBJet;
  Float_t     MinCSV_;
  Float_t     MaxCSV_;
  Float_t     DRSJ_;
  Float_t     Mass_;
  Float_t     JetPhi_;
  Float_t     JetEta_;
  Float_t     JetCSVSum_;
  Float_t     JetMetDPhi_;
  Float_t     Tau21_;
  Float_t     JetPt_;
  Float_t     SumET_;
  Float_t     MET_;
  Float_t     jetCEmEF_;
  Float_t     jetCHadEF_;
  Float_t     jetPhoEF_;
  Float_t     jetNEmEF_;
  Float_t     jetNHadEF_;
  Float_t     jetMuEF_;
  Float_t     jetCMulti_;
  
  protected:

  private:

};
#endif
