// Original class : NMinusOne.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves the N-1 and Cut Flow histograms. 
// This can be configured to do a lot more than these two tasks. 

#ifndef NMinusOne_h_
#define NMinusOne_h_
#define RKTS 10

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

class NMinusOne {
 public:
  NMinusOne(){};
  ~NMinusOne(){};
  void  Fill(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection);
  
  void  Fill(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, 
	     std::vector<int> bitVector);
  bool CheckBitPattern(std::vector<ResonanceWithMET<Jet,MET > > objectCollection,
		       std::vector<int> bitVector);
  void GetInputs(TFile* f, TString prefix_);
  void DefineHistograms();
  void Write();
  
  MonoHiggsCuts cuts_;
  int nHistWrite;
  TString prefix;
  TFile* file;
  // Histograms CutFlow 
  TH1F* h_DiJetMass[RKTS];
  TH1F* h_DeltaEtaJets[RKTS];
  TH1F* h_DeltaPhiJets[RKTS];
  TH1F* h_PtOverPt1Pt2[RKTS];
  
  TH1F* h_FatJetpT[RKTS];
  TH1F* h_FatJetCSV[RKTS];
  TH1F* h_DPhiFatJetMET[RKTS];
  TH1F* h_MSoftDrop[RKTS];
  TH1F* h_MET[RKTS];

  std::map <TString, bitset<26> > cutsMap; 
  
  protected:

  private:

};
#endif
