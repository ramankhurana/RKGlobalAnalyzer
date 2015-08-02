//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Apr 25 23:21:07 2015 by ROOT version 5.34/22
// from TTree tree/tree
// found on file: RKGlobalTuples.root
//////////////////////////////////////////////////////////

#ifndef RKAnalyzer_h
#define RKAnalyzer_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <TClonesArray.h>
#include <TLorentzVector.h>
#include <vector>
#include "../../RKUtilities/interface/RKDebugger.h"
#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Muon.h"
#include "../../RKDataFormats/interface/Event.h"

#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKObjectValidator/interface/JetValidator.h"
#include "../../RKObjectValidator/interface/ElectronValidator.h"
#include "../../RKObjectValidator/interface/METValidator.h"
#include "../../RKProducers/interface/TwoObjectCombination.h"
#include "../../RKProducers/interface/ObjectMETCombination.h"
#include "../../RKProducers/interface/TwoObjectMETCombination.h"
#include "../../RKObjectValidator/interface/TwoObjectValidator.h"
#include "../../RKObjectValidator/interface/ObjectMETValidator.h"
#include "../../RKMonoHAnalyzer/interface/SelectionBitsProducer.h"
#include "../../RKMonoHAnalyzer/interface/CutFlowAndEachCut.h"
#include "../../RKMonoHAnalyzer/interface/NMinusOne.h"
#include "../../RKMonoHAnalyzer/interface/HistFactory.h"
#include "../../RKMonoHAnalyzer/interface/ABCDMethod.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h" 
#include "../../RKUtilities/interface/DYAnalysisCuts.h" 
#include "../../RKDYAnalysis/interface/ElectronSelectionBitsProducer.h"
#include "../../RKDYAnalysis/interface/ElectronNMinusOne.h"
#include "../../RKMonoHAnalyzer/interface/Synchronization.h" 

using namespace std;
//class Electron;
// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxmuInnerdxy = 1;
const Int_t kMaxmuInnerdz = 1;
const Int_t kMaxmuTrkQuality = 1;
const Int_t kMaxMuInnervalidFraction = 1;
const Int_t kMaxpfmvaMetPt = 1;
const Int_t kMaxpfmvaMetPhi = 1;
const Int_t kMaxpfmvaMetSumEt = 1;
const Int_t kMaxpfmvaMetSig = 1;

class RKAnalyzer {
 public :
  TFile* fout;
  TFile* f;
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain
  
  
  bool triggerstatus;
  // Main Program Histograms
  TH1F* nEvents;
  TH1F* nEvents_weight;
  
  //   TString inputfilename;
   //TString outputfilename;
   
   // Physics Object Classes
   // Jets
   Jet jets;
   // FatJets;
   Jet fatjets;
   // AddJets
   Jet addjets;
   // MET
   MET met;
   // Muons
   Muon muons;
   //Electrons
   Electron electrons;
   //Photons
   Muon photons;
   //Event
   Event events;
   // Dijets
   TwoObjectCombination<Jet,Jet> dijet;
   TwoObjectCombination<Jet,Jet> dijet_selected;
   
   // DiElectron 
   TwoObjectCombination<Electron,Electron> dielectron;
   // Jet-MET
   ObjectMETCombination<Jet,MET> jet_met;
   //DiObject-MET
   TwoObjectMETCombination< Resonance<Jet,Jet>,MET > dijet_met;

   // Synchronize
   Synchronization syncmonoh;

   
   // Physics Object Validator 
   // jet 
   JetValidator jetvalidator;
   JetValidator jetvalidator_selected;
   JetValidator fatjetvalidator;;
   JetValidator addjetvalidator;;
   // Electron 
   ElectronValidator electronvalidator;
   ElectronValidator electronvalidator_barrel;
   ElectronValidator electronvalidator_endcap;
   // MET
   METValidator metvalidator;
   // DiJet   
   TwoObjectValidator<Resonance<Jet,Jet> > diJetValidator;
   TwoObjectValidator<Resonance<Jet,Jet> > diJetValidator_selected;
   // DiJet   
   TwoObjectValidator<Resonance<Electron,Electron> > diElectronValidator;
   TwoObjectValidator<Resonance<Electron,Electron> > diElectronValidatorIso;
   // Jet-MET
   ObjectMETValidator<ResonanceWithMET<Jet,MET> > jetmetValidator;
   // DiJet-MET
   ObjectMETValidator<ResonanceMET<Resonance<Jet,Jet>,MET > >  dijetmetValidator;
   // Mono-H Histograms
   HistFactory histfac;
   HistFactory histfacJetPreSel;
   HistFactory histfacJetHardPreSel;
   HistFactory histfacFullSel;
   // Mono-H ABCD method 
   ABCDMethod abcd;
   // Mono-H cuts maps and vectos
   MonoHiggsCuts cuts;
   // DYAnalysis Electron Cuts
   DYAnalysisCuts eleCuts;
   // Physics Object Container 
   // Jets
   std::vector<Jet> RKJetCollection;
   std::vector<Jet> RKJetCollection_selected;
   std::vector<Jet> MH_FATJetCollection;
   std::vector<Jet> MH_ADDJetCollection;
   //Muons
   std::vector<Muon> RKMuonCollection;
   //Photon
   std::vector<Muon> RKPhotonCollection; // Using Muon for photon
   //Electron
   std::vector<Electron> RKElectronCollection;
   std::vector<Electron> RKElectronCollection_barrel;
   std::vector<Electron> RKElectronCollection_endcap;
   std::vector<Electron> RKElectronCollection_allCutM;
   std::vector<Electron> RKElectronCollection_allCutMIso;
   
   // DiJet
   std::vector<Resonance<Jet,Jet> > RKdiJetCollection;
   std::vector<Resonance<Jet,Jet> > RKdiJetCollection_selected;
   
   // DiElectron 
   std::vector<Resonance<Electron,Electron> > RKdiElectronCollection;
   std::vector<Resonance<Electron,Electron> > RKdiElectronCollectionIso;
   
   // Jet-MET
   std::vector<ResonanceWithMET<Jet,MET> > RKjetMETCollection;
   //DiJet-MET
   std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > RKDiJetMETCollection;
   std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > RKDiJetMETCollectionWithStatus;
   std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > RKDiJetMETCollectionTTBar;
   
   
   
   // MonoHiggs Analysis Specific 
   // --- Set the bits 
   SelectionBitsProducer selectionbits;
   CutFlowAndEachCut cutflowobj;
   NMinusOne nminusobj;
   ElectronNMinusOne elenminusoneobjB;
   ElectronNMinusOne elenminusoneobjE;
   //// Use the bits to fill N-1 Histograms
   //// And cut flow histograms. 
  
   
   
   // Declaration of leaf types
   //   Float_t         pu_nTrueInt;
   //   Int_t           pu_nPUVert;
   
   Int_t           isData;
   Int_t           eventId;
   Int_t           runId;
   Int_t           lumiSection;
   Int_t           bunchXing;
   Int_t           nVtx;
   Float_t         ptHat;
   Float_t         mcWeight;
   Int_t           nGenPar;
   vector<float>   *genParE;
   vector<float>   *genParPt;
   vector<float>   *genParEta;
   vector<float>   *genParPhi;
   vector<float>   *genParM;
   vector<int>     *genParQ;
   vector<int>     *genParId;
   vector<int>     *genParSt;
   vector<int>     *genMomParId;
   vector<int>     *genParIndex;
   vector<int>     *genNMo;
   vector<int>     *genNDa;
   vector<int>     *genMo1;
   vector<int>     *genMo2;
   vector<int>     *genDa1;
   vector<int>     *genDa2;
   Int_t           nGenJet;
   vector<float>   *genJetE;
   vector<float>   *genJetPt;
   vector<float>   *genJetEta;
   vector<float>   *genJetPhi;
   vector<float>   *genJetEM;
   vector<float>   *genJetHAD;
   
   Int_t           nMu;
   TClonesArray    *muP4;
   vector<int>     *muType;
   vector<int>     *muCharge;
   vector<bool>    *isGlobalMuon;
   vector<bool>    *isTrackerMuon;
   vector<bool>    *isPFMuon;
   vector<bool>    *isTightMuon_;
   vector<bool>    *isLooseMuon_;
   vector<bool>    *isMediumMuon_;
   vector<bool>    *isSoftMuon_;
   vector<bool>    *isHighPtMuon_;
   vector<bool>    *isCustomTrackerMuon_;
   vector<int>     *muITrkID;
   vector<int>     *muSegID;
   vector<int>     *muNSegs;
   vector<bool>    *muGood;
   vector<bool>    *muIsGood;
   vector<float>   *muTrkPt;
   vector<float>   *muTrkPtErr;
   vector<float>   *mudxy;
   vector<float>   *mudz;
   vector<float>   *musegmentCompatibility;
   vector<float>   *muchi2LocalPosition;
   vector<float>   *mutrkKink;
   vector<float>   *muInnerdxy;
   vector<float>   *muInnerdz;
   vector<int>     *muTrkLayers;
   vector<int>     *muPixelLayers;
   vector<int>     *muPixelHits;
   vector<float>   *muTrkQuality_;
   vector<int>     *muHits;
   vector<float>   *muChi2NDF;
   vector<float>   *muInnervalidFraction_;
   vector<int>     *muMatches;
   vector<float>   *muTrkIso;
   vector<float>   *muHcalIso;
   vector<float>   *muEcalIso;
   vector<float>   *muChHadIso;
   vector<float>   *muNeHadIso;
   vector<float>   *muGamIso;
   vector<float>   *muPUPt;
   vector<float>   *muMiniIso;
   Int_t           HPSTau_n;
   vector<float>   *taupt;
   TClonesArray    *HPSTau_4Momentum;
   TClonesArray    *HPSTau_Vposition;
   vector<bool>    *HPSTau_leadPFChargedHadrCand;
   vector<bool>    *HPSTau_leadPFChargedHadrCand_trackRef;
   vector<bool>    *disc_againstElectronLoose;
   vector<bool>    *disc_againstElectronMedium;
   vector<bool>    *disc_againstElectronTight;
   vector<bool>    *disc_againstElectronLooseMVA5;
   vector<bool>    *disc_againstElectronMediumMVA5;
   vector<bool>    *disc_againstElectronTightMVA5;
   vector<bool>    *disc_againstElectronVLooseMVA5;
   vector<bool>    *disc_againstElectronVTightMVA5;
   vector<bool>    *disc_againstMuonLoose;
   vector<bool>    *disc_againstMuonMedium;
   vector<bool>    *disc_againstMuonTight;
   vector<bool>    *disc_againstMuonLoose2;
   vector<bool>    *disc_againstMuonMedium2;
   vector<bool>    *disc_againstMuonTight2;
   vector<bool>    *disc_againstMuonLooseMVA;
   vector<bool>    *disc_againstMuonMediumMVA;
   vector<bool>    *disc_againstMuonTightMVA;
   vector<bool>    *disc_againstMuonLoose3;
   vector<bool>    *disc_againstMuonTight3;
   vector<bool>    *disc_byVLooseCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byLooseCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byMediumCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byTightCombinedIsolationDeltaBetaCorr;
   vector<bool>    *disc_byLooseIsolation;
   vector<bool>    *disc_byVLooseIsolationMVA3newDMwLT;
   vector<bool>    *disc_byLooseIsolationMVA3newDMwLT;
   vector<bool>    *disc_byMediumIsolationMVA3newDMwLT;
   vector<bool>    *disc_byTightIsolationMVA3newDMwLT;
   vector<bool>    *disc_byVTightIsolationMVA3newDMwLT;
   vector<bool>    *disc_byVVTightIsolationMVA3newDMwLT;
   vector<bool>    *disc_byVLooseIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byLooseIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byMediumIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byTightIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byVTightIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byVVTightIsolationMVA3newDMwoLT;
   vector<bool>    *disc_byVLooseIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byLooseIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byMediumIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byTightIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byVTightIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byVVTightIsolationMVA3oldDMwLT;
   vector<bool>    *disc_byVLooseIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byLooseIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byMediumIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byTightIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byVTightIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byVVTightIsolationMVA3oldDMwoLT;
   vector<bool>    *disc_byLooseCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *disc_byMediumCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *disc_byTightCombinedIsolationDeltaBetaCorr3Hits;
   vector<bool>    *disc_decayModeFinding;
   vector<bool>    *disc_decayModeFindingNewDMs;
   vector<float>   *disc_chargedIsoPtSum;
   vector<float>   *disc_neutralIsoPtSum;
   vector<float>   *disc_puCorrPtSum;
   vector<float>   *HPSTau_NewVz;
   vector<int>     *HPSTau_charge;
   Int_t           nPho;
   TClonesArray    *phoP4;
   vector<bool>    *phoIsPassTight;
   vector<bool>    *phoIsPassLoose;
   vector<bool>    *phoIsPassMedium;
   Float_t         eleRho;
   Int_t           nEle;
   TClonesArray    *eleP4;
   vector<bool>    *eleInBarrel;
   vector<bool>    *eleInEndcap;
   vector<int>     *eleCharge;
   vector<int>     *eleChargeConsistent;
   vector<float>   *elecaloEnergy;
   vector<float>   *eleScEt;
   vector<float>   *eleScEn;
   vector<float>   *eleScPreEn;
   vector<float>   *eleScEta;
   vector<float>   *eleScPhi;
   vector<float>   *eleScRawEn;
   vector<float>   *eleScEtaWidth;
   vector<float>   *eleScPhiWidth;
   vector<float>   *eleR9;
   vector<float>   *eleHoverE;
   vector<float>   *eleD0;
   vector<float>   *eleDz;
   vector<float>   *eleEoverP;
   vector<float>   *eleBrem;
   vector<float>   *eledEtaAtVtx;
   vector<float>   *eledPhiAtVtx;
   vector<float>   *eleSigmaIEtaIEta;
   vector<float>   *eleSigmaIEtaIPhi;
   vector<float>   *eleSigmaIPhiIPhi;
   vector<bool>    *eleConvVeto;
   vector<int>     *eleMissHits;
   vector<float>   *eleEoverPInv;
   vector<float>   *eleEtaseedAtVtx;
   vector<float>   *eleE1x5;
   vector<float>   *eleE2x5;
   vector<float>   *eleE5x5;
   vector<float>   *eleSigmaIEtaIEtaFull5x5;
   vector<float>   *eleE1x5Full5x5;
   vector<float>   *eleE2x5Full5x5;
   vector<float>   *eleE5x5Full5x5;
   vector<float>   *eleR9Full5x5;
   vector<float>   *eleChHadIso;
   vector<float>   *eleNeHadIso;
   vector<float>   *eleGamIso;
   vector<float>   *elePUPt;
   vector<float>   *eleMiniIso;
   vector<float>   *eleEcalDrivenSeed;
   vector<float>   *eleDr03EcalRecHitSumEt;
   vector<float>   *eleDr03HcalDepth1TowerSumEt;
   vector<float>   *eleDr03HcalDepth2TowerSumEt;
   vector<float>   *eleDr03HcalTowerSumEt;
   vector<float>   *eleDr03TkSumPt;
   vector<bool>    *eleIsPassVeto;
   vector<bool>    *eleIsPassLoose;
   vector<bool>    *eleIsPassMedium;
   vector<bool>    *eleIsPassTight;
   vector<bool>    *eleIsPassHEEP;
   vector<bool>    *eleIsPassMVAMedium;
   vector<bool>    *eleIsPassMVATight;
   vector<float>   *eleMVAValue;
   vector<int>     *eleMVACategory;
   
   Float_t         pfMetCorrPt;
   Float_t         pfMetCorrPhi;
   Float_t         pfMetCorrSumEt;
   Float_t         pfMetCorrSig;
   Float_t         pfMetRawPt;
   Float_t         pfMetRawPhi;
   Float_t         pfMetRawSumEt;
   Float_t         pfMetRawCov00;
   Float_t         pfMetRawCov01;
   Float_t         pfMetRawCov10;
   Float_t         pfMetRawCov11;
   Float_t         pfmvaMetPt_;
   Float_t         pfmvaMetPhi_;
   Float_t         pfmvaMetSumEt_;
   Float_t         pfmvaMetSig_;
   
   Int_t           FATnJet;
   TClonesArray    *FATgenjetP4;
   vector<float>   *FATgenjetEM;
   vector<float>   *FATgenjetHAD;
   vector<float>   *FATgenjetINV;
   vector<float>   *FATgenjetAUX;
   vector<float>   *FATmatchedDR;

   vector<float>   *FATjetRawFactor;
   TClonesArray    *FATjetP4;
   vector<int>     *FATjetCharge;
   vector<int>     *FATjetPartonFlavor;

   vector<bool>    *FATjetPassIDLoose;
   vector<bool>    *FATjetPassIDTight;
   vector<float>   *FATPUJetID;
   vector<bool>    *FATisPUJetID;

   vector<float>   *FATjetCEmEF;
   vector<float>   *FATjetCHadEF;
   vector<float>   *FATjetPhoEF;
   vector<float>   *FATjetNEmEF;
   vector<float>   *FATjetNHadEF;
   vector<float>   *FATjetMuEF;
   vector<int>     *FATjetCMulti;
   
   vector<float>   *FATjetSSV;
   vector<float>   *FATjetCSV;
   vector<float>   *FATjetSSVHE;
   vector<float>   *FATjetCISVV2;
   vector<float>   *FATjetTCHP;
   vector<float>   *FATjetTCHE;
   vector<float>   *FATjetJP;
   vector<float>   *FATjetJBP;

   vector<float>   *FATjetSDmass;
   vector<float>   *FATjetTRmass;
   vector<float>   *FATjetPRmass;
   vector<float>   *FATjetFimass;
   vector<float>   *FATjetTau1;
   vector<float>   *FATjetTau2;
   vector<float>   *FATjetTau3;
   vector<float>   *FATjetTau4;
   vector<int>     *FATnSubSDJet;
   vector<vector<float> > *FATsubjetSDPx;
   vector<vector<float> > *FATsubjetSDPy;
   vector<vector<float> > *FATsubjetSDPz;
   vector<vector<float> > *FATsubjetSDCE;
   vector<vector<float> > *FATsubjetSDCSV;
   Int_t           ADDnJet;
   TClonesArray    *ADDgenjetP4;
   vector<float>   *ADDgenjetEM;
   vector<float>   *ADDgenjetHAD;
   vector<float>   *ADDgenjetINV;
   vector<float>   *ADDgenjetAUX;
   vector<float>   *ADDmatchedDR;
   vector<float>   *ADDjetRawFactor;
   TClonesArray    *ADDjetP4;
   vector<int>     *ADDjetCharge;
   vector<int>     *ADDjetPartonFlavor;
   vector<bool>    *ADDjetPassIDLoose;
   vector<bool>    *ADDjetPassIDTight;
   vector<float>   *ADDPUJetID;
   vector<bool>    *ADDisPUJetID;
   vector<float>   *ADDjetCEmEF;
   vector<float>   *ADDjetCHadEF;
   vector<float>   *ADDjetPhoEF;
   vector<float>   *ADDjetNEmEF;
   vector<float>   *ADDjetNHadEF;
   vector<float>   *ADDjetMuEF;
   vector<int>     *ADDjetCMulti;
   vector<float>   *ADDjetSSV;
   vector<float>   *ADDjetCSV;
   vector<float>   *ADDjetSSVHE;
   vector<float>   *ADDjetCISVV2;
   vector<float>   *ADDjetTCHP;
   vector<float>   *ADDjetTCHE;
   vector<float>   *ADDjetJP;
   vector<float>   *ADDjetJBP;
   vector<float>   *ADDjet_DoubleSV;
   vector<int>     *ADDjet_nSV;
   vector<vector<float> > *ADDjet_SVMass;
   vector<float>   *ADDjetTau1;
   vector<float>   *ADDjetTau2;
   vector<float>   *ADDjetTau3;
   vector<float>   *ADDjetTau4;
   vector<int>     *ADDnSubSDJet;
   vector<vector<float> > *ADDsubjetSDPx;
   vector<vector<float> > *ADDsubjetSDPy;
   vector<vector<float> > *ADDsubjetSDPz;
   vector<vector<float> > *ADDsubjetSDCE;
   vector<vector<float> > *ADDsubjetSDCSV;
   
   Int_t           THINnJet;
   TClonesArray    *THINgenjetP4;
   vector<float>   *THINgenjetEM;
   vector<float>   *THINgenjetHAD;
   vector<float>   *THINgenjetINV;
   vector<float>   *THINgenjetAUX;
   vector<float>   *THINmatchedDR;
   vector<float>   *THINjetRawFactor;
   TClonesArray    *THINjetP4;
   vector<int>     *THINjetCharge;
   vector<int>     *THINjetPartonFlavor;
   
   vector<bool>    *THINjetPassIDLoose;
   vector<bool>    *THINjetPassIDTight;
   vector<float>   *THINPUJetID;
   vector<bool>    *THINisPUJetID;
   vector<float>   *THINjetCEmEF;
   vector<float>   *THINjetCHadEF;
   vector<float>   *THINjetPhoEF;
   vector<float>   *THINjetNEmEF;
   vector<float>   *THINjetNHadEF;
   vector<float>   *THINjetMuEF;
   vector<int>     *THINjetCMulti;

   vector<float>   *THINjetSSV;
   vector<float>   *THINjetCSV;
   vector<float>   *THINjetSSVHE;
   vector<float>   *THINjetCISVV2;
   vector<float>   *THINjetTCHP;
   vector<float>   *THINjetTCHE;
   vector<float>   *THINjetJP;
   vector<float>   *THINjetJBP;
   

   
   Int_t           hlt_nTrigs;
   vector<bool>     *hlt_trigResult;
   vector<string>  *hlt_trigName;

   
   // List of branches
   //   TBranch        *b_pu_nTrueInt;   //!
   //TBranch        *b_pu_nPUVert;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_eventId;   //!
   TBranch        *b_runId;   //!
   TBranch        *b_lumiSection;   //!
   TBranch        *b_bunchXing;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_ptHat;   //!
   TBranch        *b_mcWeight;   //!
   TBranch        *b_nGenPar;   //!
   TBranch        *b_genParE;   //!
   TBranch        *b_genParPt;   //!
   TBranch        *b_genParEta;   //!
   TBranch        *b_genParPhi;   //!
   TBranch        *b_genParM;   //!
   TBranch        *b_genParQ;   //!
   TBranch        *b_genParId;   //!
   TBranch        *b_genParSt;   //!
   TBranch        *b_genMomParId;   //!
   TBranch        *b_genParIndex;   //!
   TBranch        *b_genNMo;   //!
   TBranch        *b_genNDa;   //!
   TBranch        *b_genMo1;   //!
   TBranch        *b_genMo2;   //!
   TBranch        *b_genDa1;   //!
   TBranch        *b_genDa2;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_genJetE;   //!
   TBranch        *b_genJetPt;   //!
   TBranch        *b_genJetEta;   //!
   TBranch        *b_genJetPhi;   //!
   TBranch        *b_genJetEM;   //!
   TBranch        *b_genJetHAD;   //!
   
   TBranch        *b_nMu;   //!
   TBranch        *b_muP4;   //!
   TBranch        *b_muType;   //!
   TBranch        *b_muCharge;   //!
   TBranch        *b_isGlobalMuon;   //!
   TBranch        *b_isTrackerMuon;   //!
   TBranch        *b_isPFMuon;   //!
   TBranch        *b_isTightMuon_;   //!
   TBranch        *b_isLooseMuon_;   //!
   TBranch        *b_isMediumMuon_;   //!
   TBranch        *b_isSoftMuon_;   //!
   TBranch        *b_isHighPtMuon_;   //!
   TBranch        *b_isCustomTrackerMuon_;   //!
   TBranch        *b_muITrkID;   //!
   TBranch        *b_muSegID;   //!
   TBranch        *b_muNSegs;   //!
   TBranch        *b_muGood;   //!
   TBranch        *b_muIsGood;   //!
   TBranch        *b_muTrkPt;   //!
   TBranch        *b_muTrkPtErr;   //!
   TBranch        *b_mudxy;   //!
   TBranch        *b_mudz;   //!
   TBranch        *b_musegmentCompatibility;   //!
   TBranch        *b_muchi2LocalPosition;   //!
   TBranch        *b_mutrkKink;   //!
   TBranch        *b_muInnerdxy;   //!
   TBranch        *b_muInnerdz;   //!
   TBranch        *b_muTrkLayers;   //!
   TBranch        *b_muPixelLayers;   //!
   TBranch        *b_muPixelHits;   //!
   TBranch        *b_muTrkQuality_;   //!
   TBranch        *b_muHits;   //!
   TBranch        *b_muChi2NDF;   //!
   TBranch        *b_muInnervalidFraction_;   //!
   TBranch        *b_muMatches;   //!
   TBranch        *b_muTrkIso;   //!
   TBranch        *b_muHcalIso;   //!
   TBranch        *b_muEcalIso;   //!
   TBranch        *b_muChHadIso;   //!
   TBranch        *b_muNeHadIso;   //!
   TBranch        *b_muGamIso;   //!
   TBranch        *b_muPUPt;   //!
   TBranch        *b_muMiniIso;   //!
   TBranch        *b_HPSTau_n;   //!
   TBranch        *b_taupt;   //!
   TBranch        *b_HPSTau_4Momentum;   //!
   TBranch        *b_HPSTau_Vposition;   //!
   TBranch        *b_HPSTau_leadPFChargedHadrCand;   //!
   TBranch        *b_HPSTau_leadPFChargedHadrCand_trackRef;   //!
   TBranch        *b_disc_againstElectronLoose;   //!
   TBranch        *b_disc_againstElectronMedium;   //!
   TBranch        *b_disc_againstElectronTight;   //!
   TBranch        *b_disc_againstElectronLooseMVA5;   //!
   TBranch        *b_disc_againstElectronMediumMVA5;   //!
   TBranch        *b_disc_againstElectronTightMVA5;   //!
   TBranch        *b_disc_againstElectronVLooseMVA5;   //!
   TBranch        *b_disc_againstElectronVTightMVA5;   //!
   TBranch        *b_disc_againstMuonLoose;   //!
   TBranch        *b_disc_againstMuonMedium;   //!
   TBranch        *b_disc_againstMuonTight;   //!
   TBranch        *b_disc_againstMuonLoose2;   //!
   TBranch        *b_disc_againstMuonMedium2;   //!
   TBranch        *b_disc_againstMuonTight2;   //!
   TBranch        *b_disc_againstMuonLooseMVA;   //!
   TBranch        *b_disc_againstMuonMediumMVA;   //!
   TBranch        *b_disc_againstMuonTightMVA;   //!
   TBranch        *b_disc_againstMuonLoose3;   //!
   TBranch        *b_disc_againstMuonTight3;   //!
   TBranch        *b_disc_byVLooseCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byLooseCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byMediumCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byTightCombinedIsolationDeltaBetaCorr;   //!
   TBranch        *b_disc_byLooseIsolation;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3newDMwLT;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3newDMwoLT;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3oldDMwLT;   //!
   TBranch        *b_disc_byVLooseIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byLooseIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byMediumIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byVTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byVVTightIsolationMVA3oldDMwoLT;   //!
   TBranch        *b_disc_byLooseCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_disc_byMediumCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_disc_byTightCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_disc_decayModeFinding;   //!
   TBranch        *b_disc_decayModeFindingNewDMs;   //!
   TBranch        *b_disc_chargedIsoPtSum;   //!
   TBranch        *b_disc_neutralIsoPtSum;   //!
   TBranch        *b_disc_puCorrPtSum;   //!
   TBranch        *b_HPSTau_NewVz;   //!
   TBranch        *b_HPSTau_charge;   //!
   TBranch        *b_nPho;   //!
   TBranch        *b_phoP4;   //!
   TBranch        *b_phoIsPassTight;   //!
   TBranch        *b_phoIsPassLoose;   //!
   TBranch        *b_phoIsPassMedium;   //!   
   
   TBranch        *b_eleRho;   //!
   TBranch        *b_nEle;   //!
   TBranch        *b_eleP4;   //!
   TBranch        *b_eleInBarrel;   //!
   TBranch        *b_eleInEndcap;   //!
   TBranch        *b_eleCharge;   //!
   TBranch        *b_eleChargeConsistent;   //!
   TBranch        *b_elecaloEnergy;   //!
   TBranch        *b_eleScEt;   //!
   TBranch        *b_eleScEn;   //!
   TBranch        *b_eleScPreEn;   //!
   TBranch        *b_eleScEta;   //!
   TBranch        *b_eleScPhi;   //!
   TBranch        *b_eleScRawEn;   //!
   TBranch        *b_eleScEtaWidth;   //!
   TBranch        *b_eleScPhiWidth;   //!
   TBranch        *b_eleR9;   //!
   TBranch        *b_eleHoverE;   //!
   TBranch        *b_eleD0;   //!
   TBranch        *b_eleDz;   //!
   TBranch        *b_eleEoverP;   //!
   TBranch        *b_eleBrem;   //!
   TBranch        *b_eledEtaAtVtx;   //!
   TBranch        *b_eledPhiAtVtx;   //!
   TBranch        *b_eleSigmaIEtaIEta;   //!
   TBranch        *b_eleSigmaIEtaIPhi;   //!
   TBranch        *b_eleSigmaIPhiIPhi;   //!
   TBranch        *b_eleConvVeto;   //!
   TBranch        *b_eleMissHits;   //!
   TBranch        *b_eleEoverPInv;   //!
   TBranch        *b_eleEtaseedAtVtx;   //!
   TBranch        *b_eleE1x5;   //!
   TBranch        *b_eleE2x5;   //!
   TBranch        *b_eleE5x5;   //!
   TBranch        *b_eleSigmaIEtaIEtaFull5x5;   //!
   TBranch        *b_eleE1x5Full5x5;   //!
   TBranch        *b_eleE2x5Full5x5;   //!
   TBranch        *b_eleE5x5Full5x5;   //!
   TBranch        *b_eleR9Full5x5;   //!
   TBranch        *b_eleChHadIso;   //!
   TBranch        *b_eleNeHadIso;   //!
   TBranch        *b_eleGamIso;   //!
   TBranch        *b_elePUPt;   //!
   TBranch        *b_eleMiniIso;   //!
   TBranch        *b_eleEcalDrivenSeed;   //!
   TBranch        *b_eleDr03EcalRecHitSumEt;   //!
   TBranch        *b_eleDr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_eleDr03HcalDepth2TowerSumEt;   //!
   TBranch        *b_eleDr03HcalTowerSumEt;   //!
   TBranch        *b_eleDr03TkSumPt;   //!
   TBranch        *b_eleIsPassVeto;   //!
   TBranch        *b_eleIsPassLoose;   //!
   TBranch        *b_eleIsPassMedium;   //!
   TBranch        *b_eleIsPassTight;   //!
   TBranch        *b_eleIsPassHEEP;   //!
   TBranch        *b_eleIsPassMVAMedium;   //!
   TBranch        *b_eleIsPassMVATight;   //!
   TBranch        *b_eleMVAValue;   //!
   TBranch        *b_eleMVACategory;   //!
   TBranch        *b_pfMetCorrPt;   //!
   TBranch        *b_pfMetCorrPhi;   //!
   TBranch        *b_pfMetCorrSumEt;   //!
   TBranch        *b_pfMetCorrSig;   //!
   TBranch        *b_pfMetRawPt;   //!
   TBranch        *b_pfMetRawPhi;   //!
   TBranch        *b_pfMetRawSumEt;   //!
   TBranch        *b_pfMetRawCov00;   //!
   TBranch        *b_pfMetRawCov01;   //!
   TBranch        *b_pfMetRawCov10;   //!
   TBranch        *b_pfMetRawCov11;   //!
   TBranch        *b_pfmvaMetPt_;   //!
   TBranch        *b_pfmvaMetPhi_;   //!
   TBranch        *b_pfmvaMetSumEt_;   //!
   TBranch        *b_pfmvaMetSig_;   //!
   
   TBranch        *b_FATnJet;   //!
   TBranch        *b_FATgenjetP4;   //!
   TBranch        *b_FATgenjetEM;   //!
   TBranch        *b_FATgenjetHAD;   //!
   TBranch        *b_FATgenjetINV;   //!
   TBranch        *b_FATgenjetAUX;   //!
   TBranch        *b_FATmatchedDR;   //!
   TBranch        *b_FATjetRawFactor;   //!
   TBranch        *b_FATjetP4;   //!
   TBranch        *b_FATjetCharge;   //!
   TBranch        *b_FATjetPartonFlavor;   //!
   TBranch        *b_FATjetPassIDLoose;   //!
   TBranch        *b_FATjetPassIDTight;   //!
   TBranch        *b_FATPUJetID;   //!
   TBranch        *b_FATisPUJetID;   //!
   TBranch        *b_FATjetCEmEF;   //!
   TBranch        *b_FATjetCHadEF;   //!
   TBranch        *b_FATjetPhoEF;   //!
   TBranch        *b_FATjetNEmEF;   //!
   TBranch        *b_FATjetNHadEF;   //!
   TBranch        *b_FATjetMuEF;   //!
   TBranch        *b_FATjetCMulti;   //!
   TBranch        *b_FATjetSSV;   //!
   TBranch        *b_FATjetCSV;   //!
   TBranch        *b_FATjetSSVHE;   //!
   TBranch        *b_FATjetCISVV2;   //!
   TBranch        *b_FATjetTCHP;   //!
   TBranch        *b_FATjetTCHE;   //!
   TBranch        *b_FATjetJP;   //!
   TBranch        *b_FATjetJBP;   //!
   TBranch        *b_FATjetSDmass;   //!
   TBranch        *b_FATjetTRmass;   //!
   TBranch        *b_FATjetPRmass;   //!
   TBranch        *b_FATjetFimass;   //!
   TBranch        *b_FATjetTau1;   //!
   TBranch        *b_FATjetTau2;   //!
   TBranch        *b_FATjetTau3;   //!
   TBranch        *b_FATjetTau4;   //!
   TBranch        *b_FATnSubSDJet;   //!
   TBranch        *b_FATsubjetSDPx;   //!
   TBranch        *b_FATsubjetSDPy;   //!
   TBranch        *b_FATsubjetSDPz;   //!
   TBranch        *b_FATsubjetSDCE;   //!
   TBranch        *b_FATsubjetSDCSV;   //!
   TBranch        *b_ADDnJet;   //!
   TBranch        *b_ADDgenjetP4;   //!
   TBranch        *b_ADDgenjetEM;   //!
   TBranch        *b_ADDgenjetHAD;   //!
   TBranch        *b_ADDgenjetINV;   //!
   TBranch        *b_ADDgenjetAUX;   //!
   TBranch        *b_ADDmatchedDR;   //!
   TBranch        *b_ADDjetRawFactor;   //!
   TBranch        *b_ADDjetP4;   //!
   TBranch        *b_ADDjetCharge;   //!
   TBranch        *b_ADDjetPartonFlavor;   //!
   TBranch        *b_ADDjetPassIDLoose;   //!
   TBranch        *b_ADDjetPassIDTight;   //!
   TBranch        *b_ADDPUJetID;   //!
   TBranch        *b_ADDisPUJetID;   //!
   TBranch        *b_ADDjetCEmEF;   //!
   TBranch        *b_ADDjetCHadEF;   //!
   TBranch        *b_ADDjetPhoEF;   //!
   TBranch        *b_ADDjetNEmEF;   //!
   TBranch        *b_ADDjetNHadEF;   //!
   TBranch        *b_ADDjetMuEF;   //!
   TBranch        *b_ADDjetCMulti;   //!
   TBranch        *b_ADDjetSSV;   //!
   TBranch        *b_ADDjetCSV;   //!
   TBranch        *b_ADDjetSSVHE;   //!
   TBranch        *b_ADDjetCISVV2;   //!
   TBranch        *b_ADDjetTCHP;   //!
   TBranch        *b_ADDjetTCHE;   //!
   TBranch        *b_ADDjetJP;   //!
   TBranch        *b_ADDjetJBP;   //!
   TBranch        *b_ADDjet_DoubleSV;   //!
   TBranch        *b_ADDjet_nSV;   //!
   TBranch        *b_ADDjet_SVMass;   //!
   TBranch        *b_ADDjetTau1;   //!
   TBranch        *b_ADDjetTau2;   //!
   TBranch        *b_ADDjetTau3;   //!
   TBranch        *b_ADDjetTau4;   //!
   TBranch        *b_ADDnSubSDJet;   //!
   TBranch        *b_ADDsubjetSDPx;   //!
   TBranch        *b_ADDsubjetSDPy;   //!
   TBranch        *b_ADDsubjetSDPz;   //!
   TBranch        *b_ADDsubjetSDCE;   //!
   TBranch        *b_ADDsubjetSDCSV;   //!
   
   TBranch        *b_THINnJet;   //!
   TBranch        *b_THINgenjetP4;   //!
   TBranch        *b_THINgenjetEM;   //!
   TBranch        *b_THINgenjetHAD;   //!
   TBranch        *b_THINgenjetINV;   //!
   TBranch        *b_THINgenjetAUX;   //!
   TBranch        *b_THINmatchedDR;   //!
   TBranch        *b_THINjetRawFactor;   //!
   TBranch        *b_THINjetP4;   //!
   TBranch        *b_THINjetCharge;   //!
   TBranch        *b_THINjetPartonFlavor;   //!
   TBranch        *b_THINjetPassIDLoose;   //!
   TBranch        *b_THINjetPassIDTight;   //!
   
   TBranch        *b_THINPUJetID;   //!
   TBranch        *b_THINisPUJetID;   //!
   TBranch        *b_THINjetCEmEF;   //!
   TBranch        *b_THINjetCHadEF;   //!
   TBranch        *b_THINjetPhoEF;   //!
   TBranch        *b_THINjetNEmEF;   //!
   TBranch        *b_THINjetNHadEF;   //!
   TBranch        *b_THINjetMuEF;   //!
   TBranch        *b_THINjetCMulti;   //!

   TBranch        *b_THINjetSSV;   //!
   TBranch        *b_THINjetCSV;   //!
   TBranch        *b_THINjetSSVHE;   //!
   TBranch        *b_THINjetCISVV2;   //!
   TBranch        *b_THINjetTCHP;   //!
   TBranch        *b_THINjetTCHE;   //!
   TBranch        *b_THINjetJP;   //!
   TBranch        *b_THINjetJBP;   //!


   TBranch        *b_hlt_nTrigs;   //!
   TBranch        *b_hlt_trigResult;   //!
   TBranch        *b_hlt_trigName;   //!
   
   RKAnalyzer(TTree *tree=0);
   virtual ~RKAnalyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString output);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void TotalEvent(std::vector<TString> filelist);
   void TotalEvent(TH1F* h);
   bool TriggerStatus(std::string TRIGNAME);
   // User Functions 
   // Clear all the collections for each event.
   void ClearCollections();
   // fill all the jet related variables in the vector which will be used later for analysis.
   void JetProducer();
   void FATJetProducer();
   void ADDJetProducer();
   // fill all the MET variables in the vector which will be used later for analysis. 
   void METProducer();
   // fill all the electron variables in the vector 
   void ElectronProducer();
   // fill all the muon variables in the vector 
   void MuonProducer();
   void PhotonProducer();
   void TauProducer();
   void EventProducer();

};

#endif

#ifdef RKAnalyzer_cxx
 RKAnalyzer::RKAnalyzer(TTree *tree) : fChain(0) 
{
  //inputfilename=input;
  //  outputfilename=output;
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.


  //TString filename="/hdfs/store/user/khurana/SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1/150713_071520/0000/NCUGlobalTuples_89.root";
  //TString filename="/hdfs/store/user/khurana/SingleElectron/crab_SingleElectron_Run2015B-PromptReco-v1/150713_071520/0000/NCUGlobalTuples_108.root";
  //TString filename="/hdfs/store/user/khurana/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_HLT/150713_072349/0000/NCUGlobalTuples_1.root";
  TString filename="/hdfs/store/user/khurana/MET/crab_MET-Run2015B-PromptReco-v1_PR/150730_111504/0000/NCUGlobalTuples_10.root";

   if (tree == 0) {
     //f = (TFile*)gROOT->GetListOfFiles()->FindObject("InputRootFile/NCUGlobalTuples_10.root");
     
     f = (TFile*)gROOT->GetListOfFiles()->FindObject(filename);
      if (!f || !f->IsOpen()) {
	//f = new TFile("InputRootFile/NCUGlobalTuples_10.root");
	f = new TFile(filename);
      }
      //TDirectory * dir = (TDirectory*)f->Get("InputRootFile/NCUGlobalTuples_10.root:/tree");
      TDirectory * dir = (TDirectory*)f->Get(filename+":/tree");

      dir->GetObject("treeMaker",tree);

   }
   Init(tree);
}

RKAnalyzer::~RKAnalyzer()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t RKAnalyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t RKAnalyzer::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void RKAnalyzer::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   genParE = 0;
   genParPt = 0;
   genParEta = 0;
   genParPhi = 0;
   genParM = 0;
   genParQ = 0;
   genParId = 0;
   genParSt = 0;
   genMomParId = 0;
   genParIndex = 0;
   genNMo = 0;
   genNDa = 0;
   genMo1 = 0;
   genMo2 = 0;
   genDa1 = 0;
   genDa2 = 0;
   genJetE = 0;
   genJetPt = 0;
   genJetEta = 0;
   genJetPhi = 0;
   genJetEM = 0;
   genJetHAD = 0;
   muP4 = 0;
   muType = 0;
   muCharge = 0;
   isGlobalMuon = 0;
   isTrackerMuon = 0;
   isPFMuon = 0;
   isTightMuon_ = 0;
   isLooseMuon_ = 0;
   isMediumMuon_ = 0;
   isSoftMuon_ = 0;
   isHighPtMuon_ = 0;
   isCustomTrackerMuon_ = 0;
   muITrkID = 0;
   muSegID = 0;
   muNSegs = 0;
   muGood = 0;
   muIsGood = 0;
   muTrkPt = 0;
   muTrkPtErr = 0;
   mudxy = 0;
   mudz = 0;
   musegmentCompatibility = 0;
   muchi2LocalPosition = 0;
   mutrkKink = 0;
   muInnerdxy = 0;
   muInnerdz = 0;
   muTrkLayers = 0;
   muPixelLayers = 0;
   muPixelHits = 0;
   muTrkQuality_ = 0;
   muHits = 0;
   muChi2NDF = 0;
   muInnervalidFraction_ = 0;
   muMatches = 0;
   muTrkIso = 0;
   muHcalIso = 0;
   muEcalIso = 0;
   muChHadIso = 0;
   muNeHadIso = 0;
   muGamIso = 0;
   muPUPt = 0;
   muMiniIso = 0;
   taupt = 0;
   HPSTau_4Momentum = 0;
   HPSTau_Vposition = 0;
   HPSTau_leadPFChargedHadrCand = 0;
   HPSTau_leadPFChargedHadrCand_trackRef = 0;
   disc_againstElectronLoose = 0;
   disc_againstElectronMedium = 0;
   disc_againstElectronTight = 0;
   disc_againstElectronLooseMVA5 = 0;
   disc_againstElectronMediumMVA5 = 0;
   disc_againstElectronTightMVA5 = 0;
   disc_againstElectronVLooseMVA5 = 0;
   disc_againstElectronVTightMVA5 = 0;
   disc_againstMuonLoose = 0;
   disc_againstMuonMedium = 0;
   disc_againstMuonTight = 0;
   disc_againstMuonLoose2 = 0;
   disc_againstMuonMedium2 = 0;
   disc_againstMuonTight2 = 0;
   disc_againstMuonLooseMVA = 0;
   disc_againstMuonMediumMVA = 0;
   disc_againstMuonTightMVA = 0;
   disc_againstMuonLoose3 = 0;
   disc_againstMuonTight3 = 0;
   disc_byVLooseCombinedIsolationDeltaBetaCorr = 0;
   disc_byLooseCombinedIsolationDeltaBetaCorr = 0;
   disc_byMediumCombinedIsolationDeltaBetaCorr = 0;
   disc_byTightCombinedIsolationDeltaBetaCorr = 0;
   disc_byLooseIsolation = 0;
   disc_byVLooseIsolationMVA3newDMwLT = 0;
   disc_byLooseIsolationMVA3newDMwLT = 0;
   disc_byMediumIsolationMVA3newDMwLT = 0;
   disc_byTightIsolationMVA3newDMwLT = 0;
   disc_byVTightIsolationMVA3newDMwLT = 0;
   disc_byVVTightIsolationMVA3newDMwLT = 0;
   disc_byVLooseIsolationMVA3newDMwoLT = 0;
   disc_byLooseIsolationMVA3newDMwoLT = 0;
   disc_byMediumIsolationMVA3newDMwoLT = 0;
   disc_byTightIsolationMVA3newDMwoLT = 0;
   disc_byVTightIsolationMVA3newDMwoLT = 0;
   disc_byVVTightIsolationMVA3newDMwoLT = 0;
   disc_byVLooseIsolationMVA3oldDMwLT = 0;
   disc_byLooseIsolationMVA3oldDMwLT = 0;
   disc_byMediumIsolationMVA3oldDMwLT = 0;
   disc_byTightIsolationMVA3oldDMwLT = 0;
   disc_byVTightIsolationMVA3oldDMwLT = 0;
   disc_byVVTightIsolationMVA3oldDMwLT = 0;
   disc_byVLooseIsolationMVA3oldDMwoLT = 0;
   disc_byLooseIsolationMVA3oldDMwoLT = 0;
   disc_byMediumIsolationMVA3oldDMwoLT = 0;
   disc_byTightIsolationMVA3oldDMwoLT = 0;
   disc_byVTightIsolationMVA3oldDMwoLT = 0;
   disc_byVVTightIsolationMVA3oldDMwoLT = 0;
   disc_byLooseCombinedIsolationDeltaBetaCorr3Hits = 0;
   disc_byMediumCombinedIsolationDeltaBetaCorr3Hits = 0;
   disc_byTightCombinedIsolationDeltaBetaCorr3Hits = 0;
   disc_decayModeFinding = 0;
   disc_decayModeFindingNewDMs = 0;
   disc_chargedIsoPtSum = 0;
   disc_neutralIsoPtSum = 0;
   disc_puCorrPtSum = 0;
   HPSTau_NewVz = 0;
   HPSTau_charge = 0;
   phoP4 = 0;
   phoIsPassTight = 0;
   phoIsPassLoose = 0;
   phoIsPassMedium = 0;
   eleP4 = 0;
   eleInBarrel = 0;
   eleInEndcap = 0;
   eleCharge = 0;
   eleChargeConsistent = 0;
   elecaloEnergy = 0;
   eleScEt = 0;
   eleScEn = 0;
   eleScPreEn = 0;
   eleScEta = 0;
   eleScPhi = 0;
   eleScRawEn = 0;
   eleScEtaWidth = 0;
   eleScPhiWidth = 0;
   eleR9 = 0;
   eleHoverE = 0;
   eleD0 = 0;
   eleDz = 0;
   eleEoverP = 0;
   eleBrem = 0;
   eledEtaAtVtx = 0;
   eledPhiAtVtx = 0;
   eleSigmaIEtaIEta = 0;
   eleSigmaIEtaIPhi = 0;
   eleSigmaIPhiIPhi = 0;
   eleConvVeto = 0;
   eleMissHits = 0;
   eleEoverPInv = 0;
   eleEtaseedAtVtx = 0;
   eleE1x5 = 0;
   eleE2x5 = 0;
   eleE5x5 = 0;
   eleSigmaIEtaIEtaFull5x5 = 0;
   eleE1x5Full5x5 = 0;
   eleE2x5Full5x5 = 0;
   eleE5x5Full5x5 = 0;
   eleR9Full5x5 = 0;
   eleChHadIso = 0;
   eleNeHadIso = 0;
   eleGamIso = 0;
   elePUPt = 0;
   eleMiniIso = 0;
   eleEcalDrivenSeed = 0;
   eleDr03EcalRecHitSumEt = 0;
   eleDr03HcalDepth1TowerSumEt = 0;
   eleDr03HcalDepth2TowerSumEt = 0;
   eleDr03HcalTowerSumEt = 0;
   eleDr03TkSumPt = 0;
   eleIsPassVeto = 0;
   eleIsPassLoose = 0;
   eleIsPassMedium = 0;
   eleIsPassTight = 0;
   eleIsPassHEEP = 0;
   eleIsPassMVAMedium = 0;
   eleIsPassMVATight = 0;
   eleMVAValue = 0;
   eleMVACategory = 0;
   
   FATgenjetP4 = 0;
   FATgenjetEM = 0;
   FATgenjetHAD = 0;
   FATgenjetINV = 0;
   FATgenjetAUX = 0;
   FATmatchedDR = 0;
   FATjetRawFactor = 0;
   FATjetP4 = 0;
   FATjetCharge = 0;
   FATjetPartonFlavor = 0;
   FATjetPassIDLoose = 0;
   FATjetPassIDTight = 0;
   FATPUJetID = 0;
   FATisPUJetID = 0;
   FATjetCEmEF = 0;
   FATjetCHadEF = 0;
   FATjetPhoEF = 0;
   FATjetNEmEF = 0;
   FATjetNHadEF = 0;
   FATjetMuEF = 0;
   FATjetCMulti = 0;
   FATjetSSV = 0;
   FATjetCSV = 0;
   FATjetSSVHE = 0;
   FATjetCISVV2 = 0;
   FATjetTCHP = 0;
   FATjetTCHE = 0;
   FATjetJP = 0;
   FATjetJBP = 0;
   FATjetSDmass = 0;
   FATjetTRmass = 0;
   FATjetPRmass = 0;
   FATjetFimass = 0;
   FATjetTau1 = 0;
   FATjetTau2 = 0;
   FATjetTau3 = 0;
   FATjetTau4 = 0;
   FATnSubSDJet = 0;
   FATsubjetSDPx = 0;
   FATsubjetSDPy = 0;
   FATsubjetSDPz = 0;
   FATsubjetSDCE = 0;
   FATsubjetSDCSV = 0;
   ADDgenjetP4 = 0;
   ADDgenjetEM = 0;
   ADDgenjetHAD = 0;
   ADDgenjetINV = 0;
   ADDgenjetAUX = 0;
   ADDmatchedDR = 0;
   ADDjetRawFactor = 0;
   ADDjetP4 = 0;
   ADDjetCharge = 0;
   ADDjetPartonFlavor = 0;
   ADDjetPassIDLoose = 0;
   ADDjetPassIDTight = 0;
   ADDPUJetID = 0;
   ADDisPUJetID = 0;
   ADDjetCEmEF = 0;
   ADDjetCHadEF = 0;
   ADDjetPhoEF = 0;
   ADDjetNEmEF = 0;
   ADDjetNHadEF = 0;
   ADDjetMuEF = 0;
   ADDjetCMulti = 0;
   ADDjetSSV = 0;
   ADDjetCSV = 0;
   ADDjetSSVHE = 0;
   ADDjetCISVV2 = 0;
   ADDjetTCHP = 0;
   ADDjetTCHE = 0;
   ADDjetJP = 0;
   ADDjetJBP = 0;
   ADDjet_DoubleSV = 0;
   ADDjet_nSV = 0;
   ADDjet_SVMass = 0;
   ADDjetTau1 = 0;
   ADDjetTau2 = 0;
   ADDjetTau3 = 0;
   ADDjetTau4 = 0;
   ADDnSubSDJet = 0;
   ADDsubjetSDPx = 0;
   ADDsubjetSDPy = 0;
   ADDsubjetSDPz = 0;
   ADDsubjetSDCE = 0;
   ADDsubjetSDCSV = 0;
   
   THINgenjetP4 = 0;
   THINgenjetEM = 0;
   THINgenjetHAD = 0;
   THINgenjetINV = 0;
   THINgenjetAUX = 0;
   THINmatchedDR = 0;
   THINjetRawFactor = 0;
   THINjetP4 = 0;
   THINjetCharge = 0;
   THINPUJetID = 0;
   THINjetPartonFlavor = 0;
   THINjetPassIDLoose = 0;
   THINjetPassIDTight = 0;

   THINPUJetID = 0;
   THINisPUJetID = 0;
   THINjetCEmEF = 0;
   THINjetCHadEF = 0;
   THINjetPhoEF = 0;
   THINjetNEmEF = 0;
   THINjetNHadEF = 0;
   THINjetMuEF = 0;
   THINjetCMulti = 0;

   THINjetSSV = 0;
   THINjetCSV = 0;
   THINjetSSVHE = 0;
   THINjetCISVV2 = 0;
   THINjetTCHP = 0;
   THINjetTCHE = 0;
   THINjetJP = 0;
   THINjetJBP = 0;
   
   hlt_trigResult = 0;

   hlt_trigName = 0;


   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);
   
   //   fChain->SetBranchAddress("pu_nTrueInt", &pu_nTrueInt, &b_pu_nTrueInt);
   //   fChain->SetBranchAddress("pu_nPUVert", &pu_nPUVert, &b_pu_nPUVert);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("eventId", &eventId, &b_eventId);
   fChain->SetBranchAddress("runId", &runId, &b_runId);
   fChain->SetBranchAddress("lumiSection", &lumiSection, &b_lumiSection);
   fChain->SetBranchAddress("bunchXing", &bunchXing, &b_bunchXing);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("ptHat", &ptHat, &b_ptHat);
   fChain->SetBranchAddress("mcWeight", &mcWeight, &b_mcWeight);
   fChain->SetBranchAddress("nGenPar", &nGenPar, &b_nGenPar);
   fChain->SetBranchAddress("genParE", &genParE, &b_genParE);
   fChain->SetBranchAddress("genParPt", &genParPt, &b_genParPt);
   fChain->SetBranchAddress("genParEta", &genParEta, &b_genParEta);
   fChain->SetBranchAddress("genParPhi", &genParPhi, &b_genParPhi);
   fChain->SetBranchAddress("genParM", &genParM, &b_genParM);
   fChain->SetBranchAddress("genParQ", &genParQ, &b_genParQ);
   fChain->SetBranchAddress("genParId", &genParId, &b_genParId);
   fChain->SetBranchAddress("genParSt", &genParSt, &b_genParSt);
   fChain->SetBranchAddress("genMomParId", &genMomParId, &b_genMomParId);
   fChain->SetBranchAddress("genParIndex", &genParIndex, &b_genParIndex);
   fChain->SetBranchAddress("genNMo", &genNMo, &b_genNMo);
   fChain->SetBranchAddress("genNDa", &genNDa, &b_genNDa);
   fChain->SetBranchAddress("genMo1", &genMo1, &b_genMo1);
   fChain->SetBranchAddress("genMo2", &genMo2, &b_genMo2);
   fChain->SetBranchAddress("genDa1", &genDa1, &b_genDa1);
   fChain->SetBranchAddress("genDa2", &genDa2, &b_genDa2);
   
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("muP4", &muP4, &b_muP4);
   fChain->SetBranchAddress("muType", &muType, &b_muType);
   fChain->SetBranchAddress("muCharge", &muCharge, &b_muCharge);
   fChain->SetBranchAddress("isGlobalMuon", &isGlobalMuon, &b_isGlobalMuon);
   fChain->SetBranchAddress("isTrackerMuon", &isTrackerMuon, &b_isTrackerMuon);
   fChain->SetBranchAddress("isPFMuon", &isPFMuon, &b_isPFMuon);
   fChain->SetBranchAddress("isTightMuon_", &isTightMuon_, &b_isTightMuon_);
   fChain->SetBranchAddress("isLooseMuon_", &isLooseMuon_, &b_isLooseMuon_);
   fChain->SetBranchAddress("isMediumMuon_", &isMediumMuon_, &b_isMediumMuon_);
   fChain->SetBranchAddress("isSoftMuon_", &isSoftMuon_, &b_isSoftMuon_);
   fChain->SetBranchAddress("isHighPtMuon_", &isHighPtMuon_, &b_isHighPtMuon_);
   fChain->SetBranchAddress("isCustomTrackerMuon_", &isCustomTrackerMuon_, &b_isCustomTrackerMuon_);
   fChain->SetBranchAddress("muITrkID", &muITrkID, &b_muITrkID);
   fChain->SetBranchAddress("muSegID", &muSegID, &b_muSegID);
   fChain->SetBranchAddress("muNSegs", &muNSegs, &b_muNSegs);
   fChain->SetBranchAddress("muGood", &muGood, &b_muGood);
   fChain->SetBranchAddress("muIsGood", &muIsGood, &b_muIsGood);
   fChain->SetBranchAddress("muTrkPt", &muTrkPt, &b_muTrkPt);
   fChain->SetBranchAddress("muTrkPtErr", &muTrkPtErr, &b_muTrkPtErr);
   fChain->SetBranchAddress("mudxy", &mudxy, &b_mudxy);
   fChain->SetBranchAddress("mudz", &mudz, &b_mudz);
   fChain->SetBranchAddress("musegmentCompatibility", &musegmentCompatibility, &b_musegmentCompatibility);
   fChain->SetBranchAddress("muchi2LocalPosition", &muchi2LocalPosition, &b_muchi2LocalPosition);
   fChain->SetBranchAddress("mutrkKink", &mutrkKink, &b_mutrkKink);
   fChain->SetBranchAddress("muInnerdxy", &muInnerdxy, &b_muInnerdxy);
   fChain->SetBranchAddress("muInnerdz", &muInnerdz, &b_muInnerdz);
   fChain->SetBranchAddress("muTrkLayers", &muTrkLayers, &b_muTrkLayers);
   fChain->SetBranchAddress("muPixelLayers", &muPixelLayers, &b_muPixelLayers);
   fChain->SetBranchAddress("muPixelHits", &muPixelHits, &b_muPixelHits);
   fChain->SetBranchAddress("muTrkQuality_", &muTrkQuality_, &b_muTrkQuality_);
   fChain->SetBranchAddress("muHits", &muHits, &b_muHits);
   fChain->SetBranchAddress("muChi2NDF", &muChi2NDF, &b_muChi2NDF);
   fChain->SetBranchAddress("muInnervalidFraction_", &muInnervalidFraction_, &b_muInnervalidFraction_);
   fChain->SetBranchAddress("muMatches", &muMatches, &b_muMatches);
   fChain->SetBranchAddress("muTrkIso", &muTrkIso, &b_muTrkIso);
   fChain->SetBranchAddress("muHcalIso", &muHcalIso, &b_muHcalIso);
   fChain->SetBranchAddress("muEcalIso", &muEcalIso, &b_muEcalIso);
   fChain->SetBranchAddress("muChHadIso", &muChHadIso, &b_muChHadIso);
   fChain->SetBranchAddress("muNeHadIso", &muNeHadIso, &b_muNeHadIso);
   fChain->SetBranchAddress("muGamIso", &muGamIso, &b_muGamIso);
   fChain->SetBranchAddress("muPUPt", &muPUPt, &b_muPUPt);
   fChain->SetBranchAddress("muMiniIso", &muMiniIso, &b_muMiniIso);
   fChain->SetBranchAddress("HPSTau_n", &HPSTau_n, &b_HPSTau_n);
   fChain->SetBranchAddress("taupt", &taupt, &b_taupt);
   fChain->SetBranchAddress("HPSTau_4Momentum", &HPSTau_4Momentum, &b_HPSTau_4Momentum);
   fChain->SetBranchAddress("HPSTau_Vposition", &HPSTau_Vposition, &b_HPSTau_Vposition);
   fChain->SetBranchAddress("HPSTau_leadPFChargedHadrCand", &HPSTau_leadPFChargedHadrCand, &b_HPSTau_leadPFChargedHadrCand);
   fChain->SetBranchAddress("HPSTau_leadPFChargedHadrCand_trackRef", &HPSTau_leadPFChargedHadrCand_trackRef, &b_HPSTau_leadPFChargedHadrCand_trackRef);
   fChain->SetBranchAddress("disc_againstElectronLoose", &disc_againstElectronLoose, &b_disc_againstElectronLoose);
   fChain->SetBranchAddress("disc_againstElectronMedium", &disc_againstElectronMedium, &b_disc_againstElectronMedium);
   fChain->SetBranchAddress("disc_againstElectronTight", &disc_againstElectronTight, &b_disc_againstElectronTight);
   fChain->SetBranchAddress("disc_againstElectronLooseMVA5", &disc_againstElectronLooseMVA5, &b_disc_againstElectronLooseMVA5);
   fChain->SetBranchAddress("disc_againstElectronMediumMVA5", &disc_againstElectronMediumMVA5, &b_disc_againstElectronMediumMVA5);
   fChain->SetBranchAddress("disc_againstElectronTightMVA5", &disc_againstElectronTightMVA5, &b_disc_againstElectronTightMVA5);
   fChain->SetBranchAddress("disc_againstElectronVLooseMVA5", &disc_againstElectronVLooseMVA5, &b_disc_againstElectronVLooseMVA5);
   fChain->SetBranchAddress("disc_againstElectronVTightMVA5", &disc_againstElectronVTightMVA5, &b_disc_againstElectronVTightMVA5);
   fChain->SetBranchAddress("disc_againstMuonLoose", &disc_againstMuonLoose, &b_disc_againstMuonLoose);
   fChain->SetBranchAddress("disc_againstMuonMedium", &disc_againstMuonMedium, &b_disc_againstMuonMedium);
   fChain->SetBranchAddress("disc_againstMuonTight", &disc_againstMuonTight, &b_disc_againstMuonTight);
   fChain->SetBranchAddress("disc_againstMuonLoose2", &disc_againstMuonLoose2, &b_disc_againstMuonLoose2);
   fChain->SetBranchAddress("disc_againstMuonMedium2", &disc_againstMuonMedium2, &b_disc_againstMuonMedium2);
   fChain->SetBranchAddress("disc_againstMuonTight2", &disc_againstMuonTight2, &b_disc_againstMuonTight2);
   fChain->SetBranchAddress("disc_againstMuonLooseMVA", &disc_againstMuonLooseMVA, &b_disc_againstMuonLooseMVA);
   fChain->SetBranchAddress("disc_againstMuonMediumMVA", &disc_againstMuonMediumMVA, &b_disc_againstMuonMediumMVA);
   fChain->SetBranchAddress("disc_againstMuonTightMVA", &disc_againstMuonTightMVA, &b_disc_againstMuonTightMVA);
   fChain->SetBranchAddress("disc_againstMuonLoose3", &disc_againstMuonLoose3, &b_disc_againstMuonLoose3);
   fChain->SetBranchAddress("disc_againstMuonTight3", &disc_againstMuonTight3, &b_disc_againstMuonTight3);
   fChain->SetBranchAddress("disc_byVLooseCombinedIsolationDeltaBetaCorr", &disc_byVLooseCombinedIsolationDeltaBetaCorr, &b_disc_byVLooseCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byLooseCombinedIsolationDeltaBetaCorr", &disc_byLooseCombinedIsolationDeltaBetaCorr, &b_disc_byLooseCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byMediumCombinedIsolationDeltaBetaCorr", &disc_byMediumCombinedIsolationDeltaBetaCorr, &b_disc_byMediumCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byTightCombinedIsolationDeltaBetaCorr", &disc_byTightCombinedIsolationDeltaBetaCorr, &b_disc_byTightCombinedIsolationDeltaBetaCorr);
   fChain->SetBranchAddress("disc_byLooseIsolation", &disc_byLooseIsolation, &b_disc_byLooseIsolation);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3newDMwLT", &disc_byVLooseIsolationMVA3newDMwLT, &b_disc_byVLooseIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3newDMwLT", &disc_byLooseIsolationMVA3newDMwLT, &b_disc_byLooseIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3newDMwLT", &disc_byMediumIsolationMVA3newDMwLT, &b_disc_byMediumIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3newDMwLT", &disc_byTightIsolationMVA3newDMwLT, &b_disc_byTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3newDMwLT", &disc_byVTightIsolationMVA3newDMwLT, &b_disc_byVTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3newDMwLT", &disc_byVVTightIsolationMVA3newDMwLT, &b_disc_byVVTightIsolationMVA3newDMwLT);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3newDMwoLT", &disc_byVLooseIsolationMVA3newDMwoLT, &b_disc_byVLooseIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3newDMwoLT", &disc_byLooseIsolationMVA3newDMwoLT, &b_disc_byLooseIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3newDMwoLT", &disc_byMediumIsolationMVA3newDMwoLT, &b_disc_byMediumIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3newDMwoLT", &disc_byTightIsolationMVA3newDMwoLT, &b_disc_byTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3newDMwoLT", &disc_byVTightIsolationMVA3newDMwoLT, &b_disc_byVTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3newDMwoLT", &disc_byVVTightIsolationMVA3newDMwoLT, &b_disc_byVVTightIsolationMVA3newDMwoLT);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3oldDMwLT", &disc_byVLooseIsolationMVA3oldDMwLT, &b_disc_byVLooseIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3oldDMwLT", &disc_byLooseIsolationMVA3oldDMwLT, &b_disc_byLooseIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3oldDMwLT", &disc_byMediumIsolationMVA3oldDMwLT, &b_disc_byMediumIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3oldDMwLT", &disc_byTightIsolationMVA3oldDMwLT, &b_disc_byTightIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3oldDMwLT", &disc_byVTightIsolationMVA3oldDMwLT, &b_disc_byVTightIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3oldDMwLT", &disc_byVVTightIsolationMVA3oldDMwLT, &b_disc_byVVTightIsolationMVA3oldDMwLT);
   fChain->SetBranchAddress("disc_byVLooseIsolationMVA3oldDMwoLT", &disc_byVLooseIsolationMVA3oldDMwoLT, &b_disc_byVLooseIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byLooseIsolationMVA3oldDMwoLT", &disc_byLooseIsolationMVA3oldDMwoLT, &b_disc_byLooseIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byMediumIsolationMVA3oldDMwoLT", &disc_byMediumIsolationMVA3oldDMwoLT, &b_disc_byMediumIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byTightIsolationMVA3oldDMwoLT", &disc_byTightIsolationMVA3oldDMwoLT, &b_disc_byTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byVTightIsolationMVA3oldDMwoLT", &disc_byVTightIsolationMVA3oldDMwoLT, &b_disc_byVTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byVVTightIsolationMVA3oldDMwoLT", &disc_byVVTightIsolationMVA3oldDMwoLT, &b_disc_byVVTightIsolationMVA3oldDMwoLT);
   fChain->SetBranchAddress("disc_byLooseCombinedIsolationDeltaBetaCorr3Hits", &disc_byLooseCombinedIsolationDeltaBetaCorr3Hits, &b_disc_byLooseCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("disc_byMediumCombinedIsolationDeltaBetaCorr3Hits", &disc_byMediumCombinedIsolationDeltaBetaCorr3Hits, &b_disc_byMediumCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("disc_byTightCombinedIsolationDeltaBetaCorr3Hits", &disc_byTightCombinedIsolationDeltaBetaCorr3Hits, &b_disc_byTightCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("disc_decayModeFinding", &disc_decayModeFinding, &b_disc_decayModeFinding);
   fChain->SetBranchAddress("disc_decayModeFindingNewDMs", &disc_decayModeFindingNewDMs, &b_disc_decayModeFindingNewDMs);
   fChain->SetBranchAddress("disc_chargedIsoPtSum", &disc_chargedIsoPtSum, &b_disc_chargedIsoPtSum);
   fChain->SetBranchAddress("disc_neutralIsoPtSum", &disc_neutralIsoPtSum, &b_disc_neutralIsoPtSum);
   fChain->SetBranchAddress("disc_puCorrPtSum", &disc_puCorrPtSum, &b_disc_puCorrPtSum);
   fChain->SetBranchAddress("HPSTau_NewVz", &HPSTau_NewVz, &b_HPSTau_NewVz);
   fChain->SetBranchAddress("HPSTau_charge", &HPSTau_charge, &b_HPSTau_charge);
   fChain->SetBranchAddress("nPho", &nPho, &b_nPho);
   fChain->SetBranchAddress("phoP4", &phoP4, &b_phoP4);
   fChain->SetBranchAddress("phoIsPassTight", &phoIsPassTight, &b_phoIsPassTight);
   fChain->SetBranchAddress("phoIsPassLoose", &phoIsPassLoose, &b_phoIsPassLoose);
   fChain->SetBranchAddress("phoIsPassMedium", &phoIsPassMedium, &b_phoIsPassMedium);
   fChain->SetBranchAddress("eleRho", &eleRho, &b_eleRho);
   fChain->SetBranchAddress("nEle", &nEle, &b_nEle);
   fChain->SetBranchAddress("eleP4", &eleP4, &b_eleP4);
   fChain->SetBranchAddress("eleInBarrel", &eleInBarrel, &b_eleInBarrel);
   fChain->SetBranchAddress("eleInEndcap", &eleInEndcap, &b_eleInEndcap);
   fChain->SetBranchAddress("eleCharge", &eleCharge, &b_eleCharge);
   fChain->SetBranchAddress("eleChargeConsistent", &eleChargeConsistent, &b_eleChargeConsistent);
   fChain->SetBranchAddress("elecaloEnergy", &elecaloEnergy, &b_elecaloEnergy);
   fChain->SetBranchAddress("eleScEt", &eleScEt, &b_eleScEt);
   fChain->SetBranchAddress("eleScEn", &eleScEn, &b_eleScEn);
   fChain->SetBranchAddress("eleScPreEn", &eleScPreEn, &b_eleScPreEn);
   fChain->SetBranchAddress("eleScEta", &eleScEta, &b_eleScEta);
   fChain->SetBranchAddress("eleScPhi", &eleScPhi, &b_eleScPhi);
   fChain->SetBranchAddress("eleScRawEn", &eleScRawEn, &b_eleScRawEn);
   fChain->SetBranchAddress("eleScEtaWidth", &eleScEtaWidth, &b_eleScEtaWidth);
   fChain->SetBranchAddress("eleScPhiWidth", &eleScPhiWidth, &b_eleScPhiWidth);
   fChain->SetBranchAddress("eleR9", &eleR9, &b_eleR9);
   fChain->SetBranchAddress("eleHoverE", &eleHoverE, &b_eleHoverE);
   fChain->SetBranchAddress("eleD0", &eleD0, &b_eleD0);
   fChain->SetBranchAddress("eleDz", &eleDz, &b_eleDz);
   fChain->SetBranchAddress("eleEoverP", &eleEoverP, &b_eleEoverP);
   fChain->SetBranchAddress("eleBrem", &eleBrem, &b_eleBrem);
   fChain->SetBranchAddress("eledEtaAtVtx", &eledEtaAtVtx, &b_eledEtaAtVtx);
   fChain->SetBranchAddress("eledPhiAtVtx", &eledPhiAtVtx, &b_eledPhiAtVtx);
   fChain->SetBranchAddress("eleSigmaIEtaIEta", &eleSigmaIEtaIEta, &b_eleSigmaIEtaIEta);
   fChain->SetBranchAddress("eleSigmaIEtaIPhi", &eleSigmaIEtaIPhi, &b_eleSigmaIEtaIPhi);
   fChain->SetBranchAddress("eleSigmaIPhiIPhi", &eleSigmaIPhiIPhi, &b_eleSigmaIPhiIPhi);
   fChain->SetBranchAddress("eleConvVeto", &eleConvVeto, &b_eleConvVeto);
   fChain->SetBranchAddress("eleMissHits", &eleMissHits, &b_eleMissHits);
   fChain->SetBranchAddress("eleEoverPInv", &eleEoverPInv, &b_eleEoverPInv);
   fChain->SetBranchAddress("eleEtaseedAtVtx", &eleEtaseedAtVtx, &b_eleEtaseedAtVtx);
   fChain->SetBranchAddress("eleE1x5", &eleE1x5, &b_eleE1x5);
   fChain->SetBranchAddress("eleE2x5", &eleE2x5, &b_eleE2x5);
   fChain->SetBranchAddress("eleE5x5", &eleE5x5, &b_eleE5x5);
   fChain->SetBranchAddress("eleSigmaIEtaIEtaFull5x5", &eleSigmaIEtaIEtaFull5x5, &b_eleSigmaIEtaIEtaFull5x5);
   fChain->SetBranchAddress("eleE1x5Full5x5", &eleE1x5Full5x5, &b_eleE1x5Full5x5);
   fChain->SetBranchAddress("eleE2x5Full5x5", &eleE2x5Full5x5, &b_eleE2x5Full5x5);
   fChain->SetBranchAddress("eleE5x5Full5x5", &eleE5x5Full5x5, &b_eleE5x5Full5x5);
   fChain->SetBranchAddress("eleR9Full5x5", &eleR9Full5x5, &b_eleR9Full5x5);
   fChain->SetBranchAddress("eleChHadIso", &eleChHadIso, &b_eleChHadIso);
   fChain->SetBranchAddress("eleNeHadIso", &eleNeHadIso, &b_eleNeHadIso);
   fChain->SetBranchAddress("eleGamIso", &eleGamIso, &b_eleGamIso);
   fChain->SetBranchAddress("elePUPt", &elePUPt, &b_elePUPt);
   fChain->SetBranchAddress("eleMiniIso", &eleMiniIso, &b_eleMiniIso);
   fChain->SetBranchAddress("eleEcalDrivenSeed", &eleEcalDrivenSeed, &b_eleEcalDrivenSeed);
   fChain->SetBranchAddress("eleDr03EcalRecHitSumEt", &eleDr03EcalRecHitSumEt, &b_eleDr03EcalRecHitSumEt);
   fChain->SetBranchAddress("eleDr03HcalDepth1TowerSumEt", &eleDr03HcalDepth1TowerSumEt, &b_eleDr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("eleDr03HcalDepth2TowerSumEt", &eleDr03HcalDepth2TowerSumEt, &b_eleDr03HcalDepth2TowerSumEt);
   fChain->SetBranchAddress("eleDr03HcalTowerSumEt", &eleDr03HcalTowerSumEt, &b_eleDr03HcalTowerSumEt);
   fChain->SetBranchAddress("eleDr03TkSumPt", &eleDr03TkSumPt, &b_eleDr03TkSumPt);
   fChain->SetBranchAddress("eleIsPassVeto", &eleIsPassVeto, &b_eleIsPassVeto);
   fChain->SetBranchAddress("eleIsPassLoose", &eleIsPassLoose, &b_eleIsPassLoose);
   fChain->SetBranchAddress("eleIsPassMedium", &eleIsPassMedium, &b_eleIsPassMedium);
   fChain->SetBranchAddress("eleIsPassTight", &eleIsPassTight, &b_eleIsPassTight);
   fChain->SetBranchAddress("eleIsPassHEEP", &eleIsPassHEEP, &b_eleIsPassHEEP);
   fChain->SetBranchAddress("eleIsPassMVAMedium", &eleIsPassMVAMedium, &b_eleIsPassMVAMedium);
   fChain->SetBranchAddress("eleIsPassMVATight", &eleIsPassMVATight, &b_eleIsPassMVATight);
   fChain->SetBranchAddress("eleMVAValue", &eleMVAValue, &b_eleMVAValue);
   fChain->SetBranchAddress("eleMVACategory", &eleMVACategory, &b_eleMVACategory);
   fChain->SetBranchAddress("pfMetCorrPt", &pfMetCorrPt, &b_pfMetCorrPt);
   fChain->SetBranchAddress("pfMetCorrPhi", &pfMetCorrPhi, &b_pfMetCorrPhi);
   fChain->SetBranchAddress("pfMetCorrSumEt", &pfMetCorrSumEt, &b_pfMetCorrSumEt);
   fChain->SetBranchAddress("pfMetCorrSig", &pfMetCorrSig, &b_pfMetCorrSig);
   fChain->SetBranchAddress("pfMetRawPt", &pfMetRawPt, &b_pfMetRawPt);
   fChain->SetBranchAddress("pfMetRawPhi", &pfMetRawPhi, &b_pfMetRawPhi);
   fChain->SetBranchAddress("pfMetRawSumEt", &pfMetRawSumEt, &b_pfMetRawSumEt);
   fChain->SetBranchAddress("pfMetRawCov00", &pfMetRawCov00, &b_pfMetRawCov00);
   fChain->SetBranchAddress("pfMetRawCov01", &pfMetRawCov01, &b_pfMetRawCov01);
   fChain->SetBranchAddress("pfMetRawCov10", &pfMetRawCov10, &b_pfMetRawCov10);
   fChain->SetBranchAddress("pfMetRawCov11", &pfMetRawCov11, &b_pfMetRawCov11);
   fChain->SetBranchAddress("pfmvaMetPt_", &pfmvaMetPt_, &b_pfmvaMetPt_);
   fChain->SetBranchAddress("pfmvaMetPhi_", &pfmvaMetPhi_, &b_pfmvaMetPhi_);
   fChain->SetBranchAddress("pfmvaMetSumEt_", &pfmvaMetSumEt_, &b_pfmvaMetSumEt_);
   fChain->SetBranchAddress("pfmvaMetSig_", &pfmvaMetSig_, &b_pfmvaMetSig_);
   
   fChain->SetBranchAddress("FATnJet", &FATnJet, &b_FATnJet);
   fChain->SetBranchAddress("FATgenjetP4", &FATgenjetP4, &b_FATgenjetP4);
   fChain->SetBranchAddress("FATgenjetEM", &FATgenjetEM, &b_FATgenjetEM);
   fChain->SetBranchAddress("FATgenjetHAD", &FATgenjetHAD, &b_FATgenjetHAD);
   fChain->SetBranchAddress("FATgenjetINV", &FATgenjetINV, &b_FATgenjetINV);
   fChain->SetBranchAddress("FATgenjetAUX", &FATgenjetAUX, &b_FATgenjetAUX);
   fChain->SetBranchAddress("FATmatchedDR", &FATmatchedDR, &b_FATmatchedDR);
   fChain->SetBranchAddress("FATjetRawFactor", &FATjetRawFactor, &b_FATjetRawFactor);
   fChain->SetBranchAddress("FATjetP4", &FATjetP4, &b_FATjetP4);
   fChain->SetBranchAddress("FATjetCharge", &FATjetCharge, &b_FATjetCharge);
   fChain->SetBranchAddress("FATjetPartonFlavor", &FATjetPartonFlavor, &b_FATjetPartonFlavor);
   fChain->SetBranchAddress("FATjetPassIDLoose", &FATjetPassIDLoose, &b_FATjetPassIDLoose);
   fChain->SetBranchAddress("FATjetPassIDTight", &FATjetPassIDTight, &b_FATjetPassIDTight);
   fChain->SetBranchAddress("FATPUJetID", &FATPUJetID, &b_FATPUJetID);
   fChain->SetBranchAddress("FATisPUJetID", &FATisPUJetID, &b_FATisPUJetID);
   fChain->SetBranchAddress("FATjetCEmEF", &FATjetCEmEF, &b_FATjetCEmEF);
   fChain->SetBranchAddress("FATjetCHadEF", &FATjetCHadEF, &b_FATjetCHadEF);
   fChain->SetBranchAddress("FATjetPhoEF", &FATjetPhoEF, &b_FATjetPhoEF);
   fChain->SetBranchAddress("FATjetNEmEF", &FATjetNEmEF, &b_FATjetNEmEF);
   fChain->SetBranchAddress("FATjetNHadEF", &FATjetNHadEF, &b_FATjetNHadEF);
   fChain->SetBranchAddress("FATjetMuEF", &FATjetMuEF, &b_FATjetMuEF);
   fChain->SetBranchAddress("FATjetCMulti", &FATjetCMulti, &b_FATjetCMulti);
   fChain->SetBranchAddress("FATjetSSV", &FATjetSSV, &b_FATjetSSV);
   fChain->SetBranchAddress("FATjetCSV", &FATjetCSV, &b_FATjetCSV);
   fChain->SetBranchAddress("FATjetSSVHE", &FATjetSSVHE, &b_FATjetSSVHE);
   fChain->SetBranchAddress("FATjetCISVV2", &FATjetCISVV2, &b_FATjetCISVV2);
   fChain->SetBranchAddress("FATjetTCHP", &FATjetTCHP, &b_FATjetTCHP);
   fChain->SetBranchAddress("FATjetTCHE", &FATjetTCHE, &b_FATjetTCHE);
   fChain->SetBranchAddress("FATjetJP", &FATjetJP, &b_FATjetJP);
   fChain->SetBranchAddress("FATjetJBP", &FATjetJBP, &b_FATjetJBP);
   fChain->SetBranchAddress("FATjetSDmass", &FATjetSDmass, &b_FATjetSDmass);
   fChain->SetBranchAddress("FATjetTRmass", &FATjetTRmass, &b_FATjetTRmass);
   fChain->SetBranchAddress("FATjetPRmass", &FATjetPRmass, &b_FATjetPRmass);
   fChain->SetBranchAddress("FATjetFimass", &FATjetFimass, &b_FATjetFimass);
   fChain->SetBranchAddress("FATjetTau1", &FATjetTau1, &b_FATjetTau1);
   fChain->SetBranchAddress("FATjetTau2", &FATjetTau2, &b_FATjetTau2);
   fChain->SetBranchAddress("FATjetTau3", &FATjetTau3, &b_FATjetTau3);
   fChain->SetBranchAddress("FATjetTau4", &FATjetTau4, &b_FATjetTau4);
   fChain->SetBranchAddress("FATnSubSDJet", &FATnSubSDJet, &b_FATnSubSDJet);
   fChain->SetBranchAddress("FATsubjetSDPx", &FATsubjetSDPx, &b_FATsubjetSDPx);
   fChain->SetBranchAddress("FATsubjetSDPy", &FATsubjetSDPy, &b_FATsubjetSDPy);
   fChain->SetBranchAddress("FATsubjetSDPz", &FATsubjetSDPz, &b_FATsubjetSDPz);
   fChain->SetBranchAddress("FATsubjetSDCE", &FATsubjetSDCE, &b_FATsubjetSDCE);
   fChain->SetBranchAddress("FATsubjetSDCSV", &FATsubjetSDCSV, &b_FATsubjetSDCSV);
   fChain->SetBranchAddress("ADDnJet", &ADDnJet, &b_ADDnJet);
   fChain->SetBranchAddress("ADDgenjetP4", &ADDgenjetP4, &b_ADDgenjetP4);
   fChain->SetBranchAddress("ADDgenjetEM", &ADDgenjetEM, &b_ADDgenjetEM);
   fChain->SetBranchAddress("ADDgenjetHAD", &ADDgenjetHAD, &b_ADDgenjetHAD);
   fChain->SetBranchAddress("ADDgenjetINV", &ADDgenjetINV, &b_ADDgenjetINV);
   fChain->SetBranchAddress("ADDgenjetAUX", &ADDgenjetAUX, &b_ADDgenjetAUX);
   fChain->SetBranchAddress("ADDmatchedDR", &ADDmatchedDR, &b_ADDmatchedDR);
   fChain->SetBranchAddress("ADDjetRawFactor", &ADDjetRawFactor, &b_ADDjetRawFactor);
   fChain->SetBranchAddress("ADDjetP4", &ADDjetP4, &b_ADDjetP4);
   fChain->SetBranchAddress("ADDjetCharge", &ADDjetCharge, &b_ADDjetCharge);
   fChain->SetBranchAddress("ADDjetPartonFlavor", &ADDjetPartonFlavor, &b_ADDjetPartonFlavor);
   fChain->SetBranchAddress("ADDjetPassIDLoose", &ADDjetPassIDLoose, &b_ADDjetPassIDLoose);
   fChain->SetBranchAddress("ADDjetPassIDTight", &ADDjetPassIDTight, &b_ADDjetPassIDTight);
   fChain->SetBranchAddress("ADDPUJetID", &ADDPUJetID, &b_ADDPUJetID);
   fChain->SetBranchAddress("ADDisPUJetID", &ADDisPUJetID, &b_ADDisPUJetID);
   fChain->SetBranchAddress("ADDjetCEmEF", &ADDjetCEmEF, &b_ADDjetCEmEF);
   fChain->SetBranchAddress("ADDjetCHadEF", &ADDjetCHadEF, &b_ADDjetCHadEF);
   fChain->SetBranchAddress("ADDjetPhoEF", &ADDjetPhoEF, &b_ADDjetPhoEF);
   fChain->SetBranchAddress("ADDjetNEmEF", &ADDjetNEmEF, &b_ADDjetNEmEF);
   fChain->SetBranchAddress("ADDjetNHadEF", &ADDjetNHadEF, &b_ADDjetNHadEF);
   fChain->SetBranchAddress("ADDjetMuEF", &ADDjetMuEF, &b_ADDjetMuEF);
   fChain->SetBranchAddress("ADDjetCMulti", &ADDjetCMulti, &b_ADDjetCMulti);
   fChain->SetBranchAddress("ADDjetSSV", &ADDjetSSV, &b_ADDjetSSV);
   fChain->SetBranchAddress("ADDjetCSV", &ADDjetCSV, &b_ADDjetCSV);
   fChain->SetBranchAddress("ADDjetSSVHE", &ADDjetSSVHE, &b_ADDjetSSVHE);
   fChain->SetBranchAddress("ADDjetCISVV2", &ADDjetCISVV2, &b_ADDjetCISVV2);
   fChain->SetBranchAddress("ADDjetTCHP", &ADDjetTCHP, &b_ADDjetTCHP);
   fChain->SetBranchAddress("ADDjetTCHE", &ADDjetTCHE, &b_ADDjetTCHE);
   fChain->SetBranchAddress("ADDjetJP", &ADDjetJP, &b_ADDjetJP);
   fChain->SetBranchAddress("ADDjetJBP", &ADDjetJBP, &b_ADDjetJBP);
   fChain->SetBranchAddress("ADDjet_DoubleSV", &ADDjet_DoubleSV, &b_ADDjet_DoubleSV);
   fChain->SetBranchAddress("ADDjet_nSV", &ADDjet_nSV, &b_ADDjet_nSV);
   fChain->SetBranchAddress("ADDjet_SVMass", &ADDjet_SVMass, &b_ADDjet_SVMass);
   fChain->SetBranchAddress("ADDjetTau1", &ADDjetTau1, &b_ADDjetTau1);
   fChain->SetBranchAddress("ADDjetTau2", &ADDjetTau2, &b_ADDjetTau2);
   fChain->SetBranchAddress("ADDjetTau3", &ADDjetTau3, &b_ADDjetTau3);
   fChain->SetBranchAddress("ADDjetTau4", &ADDjetTau4, &b_ADDjetTau4);
   fChain->SetBranchAddress("ADDnSubSDJet", &ADDnSubSDJet, &b_ADDnSubSDJet);
   fChain->SetBranchAddress("ADDsubjetSDPx", &ADDsubjetSDPx, &b_ADDsubjetSDPx);
   fChain->SetBranchAddress("ADDsubjetSDPy", &ADDsubjetSDPy, &b_ADDsubjetSDPy);
   fChain->SetBranchAddress("ADDsubjetSDPz", &ADDsubjetSDPz, &b_ADDsubjetSDPz);
   fChain->SetBranchAddress("ADDsubjetSDCE", &ADDsubjetSDCE, &b_ADDsubjetSDCE);
   fChain->SetBranchAddress("ADDsubjetSDCSV", &ADDsubjetSDCSV, &b_ADDsubjetSDCSV);
   
   fChain->SetBranchAddress("THINnJet", &THINnJet, &b_THINnJet);
   fChain->SetBranchAddress("THINgenjetP4", &THINgenjetP4, &b_THINgenjetP4);
   fChain->SetBranchAddress("THINgenjetEM", &THINgenjetEM, &b_THINgenjetEM);
   fChain->SetBranchAddress("THINgenjetHAD", &THINgenjetHAD, &b_THINgenjetHAD);
   fChain->SetBranchAddress("THINgenjetINV", &THINgenjetINV, &b_THINgenjetINV);
   fChain->SetBranchAddress("THINgenjetAUX", &THINgenjetAUX, &b_THINgenjetAUX);
   fChain->SetBranchAddress("THINmatchedDR", &THINmatchedDR, &b_THINmatchedDR);
   fChain->SetBranchAddress("THINjetRawFactor", &THINjetRawFactor, &b_THINjetRawFactor);
   fChain->SetBranchAddress("THINjetP4", &THINjetP4, &b_THINjetP4);
   fChain->SetBranchAddress("THINjetCharge", &THINjetCharge, &b_THINjetCharge);
   fChain->SetBranchAddress("THINPUJetID", &THINPUJetID, &b_THINPUJetID);
   fChain->SetBranchAddress("THINjetPartonFlavor", &THINjetPartonFlavor, &b_THINjetPartonFlavor);
   fChain->SetBranchAddress("THINjetPassIDLoose", &THINjetPassIDLoose, &b_THINjetPassIDLoose);
   fChain->SetBranchAddress("THINjetPassIDTight", &THINjetPassIDTight, &b_THINjetPassIDTight);
   fChain->SetBranchAddress("THINPUJetID", &THINPUJetID, &b_THINPUJetID);
   fChain->SetBranchAddress("THINisPUJetID", &THINisPUJetID, &b_THINisPUJetID);
   fChain->SetBranchAddress("THINjetCEmEF", &THINjetCEmEF, &b_THINjetCEmEF);
   fChain->SetBranchAddress("THINjetCHadEF", &THINjetCHadEF, &b_THINjetCHadEF);
   fChain->SetBranchAddress("THINjetPhoEF", &THINjetPhoEF, &b_THINjetPhoEF);
   fChain->SetBranchAddress("THINjetNEmEF", &THINjetNEmEF, &b_THINjetNEmEF);
   fChain->SetBranchAddress("THINjetNHadEF", &THINjetNHadEF, &b_THINjetNHadEF);
   fChain->SetBranchAddress("THINjetMuEF", &THINjetMuEF, &b_THINjetMuEF);
   fChain->SetBranchAddress("THINjetCMulti", &THINjetCMulti, &b_THINjetCMulti);

   fChain->SetBranchAddress("THINjetSSV", &THINjetSSV, &b_THINjetSSV);
   fChain->SetBranchAddress("THINjetCSV", &THINjetCSV, &b_THINjetCSV);
   fChain->SetBranchAddress("THINjetSSVHE", &THINjetSSVHE, &b_THINjetSSVHE);
   fChain->SetBranchAddress("THINjetCISVV2", &THINjetCISVV2, &b_THINjetCISVV2);
   fChain->SetBranchAddress("THINjetTCHP", &THINjetTCHP, &b_THINjetTCHP);
   fChain->SetBranchAddress("THINjetTCHE", &THINjetTCHE, &b_THINjetTCHE);
   fChain->SetBranchAddress("THINjetJP", &THINjetJP, &b_THINjetJP);
   fChain->SetBranchAddress("THINjetJBP", &THINjetJBP, &b_THINjetJBP);
   
   
   fChain->SetBranchAddress("hlt_nTrigs", &hlt_nTrigs, &b_hlt_nTrigs);
   fChain->SetBranchAddress("hlt_trigResult", &hlt_trigResult, &b_hlt_trigResult);
   fChain->SetBranchAddress("hlt_trigName", &hlt_trigName, &b_hlt_trigName);


   Notify();
}

Bool_t RKAnalyzer::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void RKAnalyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t RKAnalyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

class DiJetpTSorting{
 public:
  bool operator() (Resonance<Jet,Jet> obj1, Resonance<Jet,Jet> obj2 ){
    double Pt1 = obj1.ResonanceProp.p4.Pt();
    double Pt2 = obj2.ResonanceProp.p4.Pt();
    return Pt2 <= Pt1;
  }
};

#endif // #ifdef RKAnalyzer_cxx


