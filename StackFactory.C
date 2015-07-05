#include <vector>
#include <iomanip>
#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TString.h"
TString outputdirname = "Plots_5thOctober";
void StackFactory(){
  gSystem->Exec("mkdir "+outputdirname);
  gSystem->Exec("mkdir "+outputdirname+"/PNG/");
  gSystem->Exec("mkdir "+outputdirname+"/PDF/");
  gSystem->Exec("mkdir "+outputdirname+"/ROOT/");
  gSystem->Exec("mkdir "+outputdirname+"/MACRO/");

  
  bool fillstack = true;
  bool fillFR = true;
  bool fill4lMass = false;
  bool sevenTeV = false;
  bool eightTeV = true;
  bool fordisplay = true;
  TFile *f ;
  
  if(fill4lMass)
    const int nfiles    = 7 ;
  else
    const int nfiles    = 13 ;

  TCanvas *c = new TCanvas("c", "ZZMass_7Plus8TeV_70-800_10GeV",286,86,600,600);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  c->Range(-68.75,-7.5,856.25,42.5);
  c->SetFillColor(0);
  c->SetBorderMode(0);
  c->SetBorderSize(2);
  c->SetTickx(1);
  c->SetTicky(1);
  c->SetLeftMargin(0.15);
  c->SetRightMargin(0.05);
  c->SetTopMargin(0.05);
  c->SetBottomMargin(0.15);
  c->SetFrameFillStyle(0);
  c->SetFrameBorderMode(0);
  c->SetFrameFillStyle(0);
  c->SetFrameBorderMode(0);
  c->SetLogy(1);

  char hstackname[200];
  TString filename[nfiles];
  
  if(!fill4lMass){
    //TString BkgPath  = "";
    //TString DataPath = "";

    //TString BkgPath  = "/lustre/home/khurana/ForPaper/PostAnalyzer/1April_SkimmedDataMC_PostAna/Merged_1April_SkimmedMC/";
    //TString DataPath = "/lustre/home/khurana/ForPaper/PostAnalyzer/1April_SkimmedDataMC_PostAna/Merged_1April_SkimmedData/Merged_Data.root";
        
    TString BkgPath  = "/lustre/cms/store/user/khurana/PostAnalyzer/Merged_PostAnalyzerFiles_19Sept2013ForHighMassPaperMCOld/";
    TString DataPath = "/lustre/cms/store/user/khurana/PostAnalyzer/Merged_PostAnalyzerFiles_19Sept2013ForHighMassPaper/Merged_Data.root";
        
    
    //filename[0 ]= "/lustre/home/khurana/Moriond_NewTauID/GluGlu/GluGlu_Merged_GluGluToHToZZTo4L_M-200_8TeV-powheg-pythia6.root" ;
    filename[0 ]= BkgPath+"/Merged_GluGluToZZTo2L2L_TuneZ2star_8TeV-gg2zz-pythia6.root" ;
    
    filename[1 ]= BkgPath+"/Merged_GluGluToZZTo2L2L_TuneZ2star_8TeV-gg2zz-pythia6.root" ;
    filename[2 ]= BkgPath+"/Merged_GluGluToZZTo4L_8TeV-gg2zz-pythia6.root" ;
    
    filename[3 ]= BkgPath+"/Merged_ZZTo4mu_8TeV-powheg-pythia6.root" ;
    filename[4 ]= BkgPath+"/Merged_ZZTo4e_8TeV-powheg-pythia6.root" ;
    filename[5 ]= BkgPath+"/Merged_ZZTo4tau_8TeV-powheg-pythia6.root" ;
    filename[6 ]= BkgPath+"/Merged_ZZTo2e2mu_8TeV-powheg-pythia6.root" ;
    filename[7 ]= BkgPath+"/Merged_ZZTo2mu2tau_8TeV-powheg-pythia6.root" ;
    filename[8 ]= BkgPath+"/Merged_ZZTo2e2tau_8TeV-powheg-pythia6.root" ;
    filename[9 ]= BkgPath+"/Merged_WZJetsTo3LNu_TuneZ2_8TeV-madgraph-tauola.root" ;
    filename[10 ]= BkgPath+"/Merged_TTTo2L2Nu2B_8TeV-powheg-pythia6.root" ;
    filename[11 ]= BkgPath+"/Merged_DYJetsToLL_M-50_TuneZ2Star_8TeV-madgraph-tarball.root" ;
    
    filename[12] = DataPath;
  }
  

  if(fill4lMass){
    filename[0 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-1000_8TeV-powheg-pythia6.root";
    filename[1 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-180_8TeV-powheg-pythia6.root";
    filename[2 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-200_8TeV-powheg-pythia6_2.root";
    filename[3 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-220_8TeV-powheg-pythia6.root";
    filename[4 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-250_8TeV-powheg-pythia6.root";
    filename[5 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-300_8TeV-powheg-pythia6.root";
    filename[6 ]= "GluGluHiggs/Merged_GluGluToHToZZTo4L_M-350_8TeV-powheg-pythia6.root";
  }
  //----------------------------------------------
  //-----Stack Filling----------------------------
  //----------------------------------------------
  TString FileProcessed[nfiles];
  
  TFile *FileObj[nfiles];
  
  if(fillstack){
    std::vector<TH1F*> mmttVector;
    std::vector<TH1F*> mmetVector;
    std::vector<TH1F*> mmmtVector;
    std::vector<TH1F*> mmmeVector;
  
    std::vector<TH1F*> eettVector;
    std::vector<TH1F*> eeetVector;
    std::vector<TH1F*> eemtVector;
    std::vector<TH1F*> eeemVector;
  
    std::vector<TH1F*> statusallVector;
    std::vector<TH1F*> statusallPUVector;
    std::vector<TH1F*> statusallTnPVector;
    std::vector<TH1F*> statusallPuAndTnPVector;
    
    std::vector<TH1F*> MeeVector;
    std::vector<TH1F*> MmmVector;

    std::vector<TH1F*> leadingeleIsoVector;
    std::vector<TH1F*> subleadingeleIsoVector;
    std::vector<TH1F*> leadingelePtVector;
    std::vector<TH1F*> subleadingelePtVector;
    std::vector<TH1F*> leadingeleEtaVector;
    std::vector<TH1F*> subleadingeleEtaVector;
    std::vector<TH1F*> leadingmuIsoVector;
    std::vector<TH1F*> subleadingmuIsoVector;
    std::vector<TH1F*> leadingmuPtVector;
    std::vector<TH1F*> subleadingmuPtVector;
    std::vector<TH1F*> leadingmuEtaVector;
    std::vector<TH1F*> subleadingmuEtaVector;
    
    //Jet FR Tau Control Region
    std::vector<TH1F*> MmmttNoIso;
    
    std::vector<TH1F*> MmmttFirstTauIsoLoose;
    std::vector<TH1F*> MmmttSecondTauIsoLoose;
    std::vector<TH1F*> MmmttBothTauIsoLoose;
    
    std::vector<TH1F*> MmmttFirstTauIsoMedium;
    std::vector<TH1F*> MmmttSecondTauIsoMedium;
    std::vector<TH1F*> MmmttBothTauIsoMedium;

    std::vector<TH1F*> MmmttFirstTauIsoTight;
    std::vector<TH1F*> MmmttSecondTauIsoTight;
    std::vector<TH1F*> MmmttBothTauIsoTight;

    std::vector<TH1F*> MeettNoIso;
    
    std::vector<TH1F*> MeettFirstTauIsoLoose;
    std::vector<TH1F*> MeettSecondTauIsoLoose;
    std::vector<TH1F*> MeettBothTauIsoLoose;
    
    std::vector<TH1F*> MeettFirstTauIsoMedium;
    std::vector<TH1F*> MeettSecondTauIsoMedium;
    std::vector<TH1F*> MeettBothTauIsoMedium;
    
    std::vector<TH1F*> MeettFirstTauIsoTight;
    std::vector<TH1F*> MeettSecondTauIsoTight;
    std::vector<TH1F*> MeettBothTauIsoTight;
    
    // Jet FR Electron Control Region
    std::vector<TH1F*> Mmmet_noIso;
    std::vector<TH1F*> Meeet_noIso;
    
    std::vector<TH1F*> Mmmet_IsoLoose;
    std::vector<TH1F*> Meeet_IsoLoose;
    
    std::vector<TH1F*> Mmmet_IsoMedium;
    std::vector<TH1F*> Meeet_IsoMedium;
    
    std::vector<TH1F*> Mmmet_IsoTight;
    std::vector<TH1F*> Meeet_IsoTight;
    
    // Jet FR Muon Control Region
    std::vector<TH1F*> Mmmmt_noIso;
    std::vector<TH1F*> Meemt_noIso;
    
    std::vector<TH1F*> Mmmmt_IsoLoose;
    std::vector<TH1F*> Meemt_IsoLoose;
    
    std::vector<TH1F*> Mmmmt_IsoMedium;
    std::vector<TH1F*> Meemt_IsoMedium;
    
    std::vector<TH1F*> Mmmmt_IsoTight;
    std::vector<TH1F*> Meemt_IsoTight;
  }
  
  
  //----------------------------------------------
  //-----Fake Rate Histo Filling------------------
  //----------------------------------------------
  if(fillFR){
    //Pt
    std::vector<TH1F*> JetFRTauPtDenominator;
    std::vector<TH1F*> JetFRTauPtNumeratorLoose;
    std::vector<TH1F*> JetFRTauPtNumeratorMedium;
    std::vector<TH1F*> JetFRTauPtNumeratorTight;
    //Phi
    std::vector<TH1F*> JetFRTauPhiDenominator;
    std::vector<TH1F*> JetFRTauPhiNumeratorLoose;
    std::vector<TH1F*> JetFRTauPhiNumeratorMedium;
    std::vector<TH1F*> JetFRTauPhiNumeratorTight;
    //PU
    std::vector<TH1F*> JetFRTauPUDenominator;
    std::vector<TH1F*> JetFRTauPUNumeratorLoose;
    std::vector<TH1F*> JetFRTauPUNumeratorMedium;
    std::vector<TH1F*> JetFRTauPUNumeratorTight;
    //Eta
    std::vector<TH1F*> JetFRTauEtaDenominator;
    std::vector<TH1F*> JetFRTauEtaNumeratorLoose;
    std::vector<TH1F*> JetFRTauEtaNumeratorMedium;
    std::vector<TH1F*> JetFRTauEtaNumeratorTight;
    
    
    //Pt
    std::vector<TH1F*> ElePtDenominator;
    std::vector<TH1F*> ElePtNumeratorLoose;
    std::vector<TH1F*> ElePtNumeratorMedium;
    std::vector<TH1F*> ElePtNumeratorTight;
    
    std::vector<TH1F*> MuPtDenominator;
    std::vector<TH1F*> MuPtNumeratorLoose;
    std::vector<TH1F*> MuPtNumeratorMedium;
    std::vector<TH1F*> MuPtNumeratorTight;
    
    //Eta
    std::vector<TH1F*> EleEtaDenominator;
    std::vector<TH1F*> EleEtaNumeratorLoose;
    std::vector<TH1F*> EleEtaNumeratorMedium;
    std::vector<TH1F*> EleEtaNumeratorTight;
    
    std::vector<TH1F*> MuEtaDenominator;
    std::vector<TH1F*> MuEtaNumeratorLoose;
    std::vector<TH1F*> MuEtaNumeratorMedium;
    std::vector<TH1F*> MuEtaNumeratorTight;
    
    //Phi
    std::vector<TH1F*> ElePhiDenominator;
    std::vector<TH1F*> ElePhiNumeratorLoose;
    std::vector<TH1F*> ElePhiNumeratorMedium;
    std::vector<TH1F*> ElePhiNumeratorTight;
    
    std::vector<TH1F*> MuPhiDenominator;
    std::vector<TH1F*> MuPhiNumeratorLoose;
    std::vector<TH1F*> MuPhiNumeratorMedium;
    std::vector<TH1F*> MuPhiNumeratorTight;
    
    //PU
    std::vector<TH1F*> ElePUDenominator;
    std::vector<TH1F*> ElePUNumeratorLoose;
    std::vector<TH1F*> ElePUNumeratorMedium;
    std::vector<TH1F*> ElePUNumeratorTight;
    
    std::vector<TH1F*> MuPUDenominator;
    std::vector<TH1F*> MuPUNumeratorLoose;
    std::vector<TH1F*> MuPUNumeratorMedium;
    std::vector<TH1F*> MuPUNumeratorTight;
  }
  
  if(fillstack){
    mmttVector.clear();
    mmetVector.clear();
    mmmtVector.clear();
    mmmeVector.clear();
    
    eettVector.clear();
    eeetVector.clear();
    eemtVector.clear();
    eeemVector.clear();
    
    statusallVector.clear();
    statusallPUVector.clear();
    statusallTnPVector.clear();
    statusallPuAndTnPVector.clear();
    
    MeeVector.clear();
    MmmVector.clear();

    leadingeleIsoVector.clear();
    subleadingeleIsoVector.clear();
    leadingelePtVector.clear();
    subleadingelePtVector.clear();
    leadingeleEtaVector.clear();
    subleadingeleEtaVector.clear();
    leadingmuIsoVector.clear();
    subleadingmuIsoVector.clear();
    leadingmuPtVector.clear();
    subleadingmuPtVector.clear();
    leadingmuEtaVector.clear();
    subleadingmuEtaVector.clear();
    
    //Jet FR Tau Control Region
    MmmttNoIso.clear();
    
    MmmttFirstTauIsoLoose.clear();
    MmmttSecondTauIsoLoose.clear();
    MmmttBothTauIsoLoose.clear();
    
    MmmttFirstTauIsoMedium.clear();
    MmmttSecondTauIsoMedium.clear();
    MmmttBothTauIsoMedium.clear();
    
    MmmttFirstTauIsoTight.clear();
    MmmttSecondTauIsoTight.clear();
    MmmttBothTauIsoTight.clear();

    MeettNoIso.clear();
    
    MeettFirstTauIsoLoose.clear();
    MeettSecondTauIsoLoose.clear();
    MeettBothTauIsoLoose.clear();

    MeettFirstTauIsoMedium.clear();
    MeettSecondTauIsoMedium.clear();
    MeettBothTauIsoMedium.clear();
    
    MeettFirstTauIsoTight.clear();
    MeettSecondTauIsoTight.clear();
    MeettBothTauIsoTight.clear();
    
    // Jet FR Electron Control Region
    Mmmet_noIso.clear();
    Meeet_noIso.clear();
    // Jet FR Muon Control Region
    Mmmmt_noIso.clear();
    Meemt_noIso.clear();
    
    Mmmet_IsoLoose.clear();
    Meeet_IsoLoose.clear();
    Mmmmt_IsoLoose.clear();
    Meemt_IsoLoose.clear();

    Mmmet_IsoMedium.clear();
    Meeet_IsoMedium.clear();
    Mmmmt_IsoMedium.clear();
    Meemt_IsoMedium.clear();

    Mmmet_IsoTight.clear();
    Meeet_IsoTight.clear();
    Mmmmt_IsoTight.clear();
    Meemt_IsoTight.clear();
}
  //----------------------------------------------
  //-----Fake Rate Histo Filling------------------
  //----------------------------------------------
  if(fillFR){
    JetFRTauPtDenominator.clear();
    JetFRTauPtNumeratorLoose.clear();
    JetFRTauPtNumeratorMedium.clear();
    JetFRTauPtNumeratorTight.clear();
    
    
    JetFRTauPhiDenominator.clear();
    JetFRTauPhiNumeratorLoose.clear();
    JetFRTauPhiNumeratorMedium.clear();
    JetFRTauPhiNumeratorTight.clear();
    
    JetFRTauPUDenominator.clear();
    JetFRTauPUNumeratorLoose.clear();
    JetFRTauPUNumeratorMedium.clear();
    JetFRTauPUNumeratorTight.clear();
    
    JetFRTauEtaDenominator.clear();
    JetFRTauEtaNumeratorLoose.clear();
    JetFRTauEtaNumeratorMedium.clear();
    JetFRTauEtaNumeratorTight.clear();
    
    
    //Pt
    ElePtDenominator.clear();
    ElePtNumeratorLoose.clear();
    ElePtNumeratorMedium.clear();
    ElePtNumeratorTight.clear();
    
    MuPtDenominator.clear();
    MuPtNumeratorLoose.clear();
    MuPtNumeratorMedium.clear();
    MuPtNumeratorTight.clear();
    
    
    //Eta
    EleEtaDenominator.clear();
    EleEtaNumeratorLoose.clear();
    EleEtaNumeratorMedium.clear();
    EleEtaNumeratorTight.clear();
    
    MuEtaDenominator.clear();
    MuEtaNumeratorLoose.clear();
    MuEtaNumeratorMedium.clear();
    MuEtaNumeratorTight.clear();
    
    //Phi
    ElePhiDenominator.clear();
    ElePhiNumeratorLoose.clear();
    ElePhiNumeratorMedium.clear();
    ElePhiNumeratorTight.clear();
  
    MuPhiDenominator.clear();
    MuPhiNumeratorLoose.clear();
    MuPhiNumeratorMedium.clear();
    MuPhiNumeratorTight.clear();
  
    //PU
    ElePUDenominator.clear();
    ElePUNumeratorLoose.clear();
    ElePUNumeratorMedium.clear();
    ElePUNumeratorTight.clear();
    
    MuPUDenominator.clear();
    MuPUNumeratorLoose.clear();
    MuPUNumeratorMedium.clear();
    MuPUNumeratorTight.clear();
  }
  std::vector<Double_t> EventProcessed;
  EventProcessed.clear();
    
  for (int ifile=0; ifile < nfiles; ifile++) {
    FileObj[ifile]  = (TFile*)gROOT->GetListOfFiles()->FindObject(filename[ifile]);
    if (!FileObj[ifile])
      FileObj[ifile]  = new TFile(filename[ifile]);
    FileObj[ifile]->cd();
    FileObj[ifile]->cd("status");
    //EventProcessed.push_back(higgstree->GetEntriesFast());
    EventProcessed.push_back(totalentries->Integral());
    
    if(fillstack){
    mmttVector.push_back(statusmmtt_);
    mmetVector.push_back(statusmmet_);
    mmmtVector.push_back(statusmmmt_);
    mmmeVector.push_back(statusmmme_);
    eettVector.push_back(statuseett_);
    eeetVector.push_back(statuseeet_);
    eemtVector.push_back(statuseemt_);
    eeemVector.push_back(statuseeem_);
    
    statusallVector.push_back(statusall_);
    statusallPUVector.push_back(statusallPU_);
    statusallTnPVector.push_back(statusallTnP_);
    statusallPuAndTnPVector.push_back(statusallPuAndTnP_);
    std::cout<<"pushing"<<std::endl;
    MeeVector.push_back(Mee_);
    MmmVector.push_back(Mmm_);

    leadingeleIsoVector.push_back(leadingeleIso_);
    leadingelePtVector.push_back(leadingelePt_);
    subleadingeleIsoVector.push_back(subleadingeleIso_);
    subleadingelePtVector.push_back(subleadingelePt_);
    leadingeleEtaVector.push_back(leadingeleEta_);
    subleadingeleEtaVector.push_back(subleadingeleEta_);
    leadingmuIsoVector.push_back(leadingmuIso_);
    subleadingmuIsoVector.push_back(subleadingmuIso_);
    leadingmuPtVector.push_back(leadingmuPt_);
    subleadingmuPtVector.push_back(subleadingmuPt_);
    leadingmuEtaVector.push_back(leadingmuEta_);
    subleadingmuEtaVector.push_back(subleadingmuEta_);
    
    //Jet FR Tau Control Region
    MmmttNoIso.push_back(MmmttNoIso_);
    
    MmmttFirstTauIsoLoose.push_back(MmmttFirstTauIso_loose);
    MmmttFirstTauIsoMedium.push_back(MmmttFirstTauIso_medium);
    MmmttFirstTauIsoTight.push_back(MmmttFirstTauIso_tight);
    
    MmmttSecondTauIsoLoose.push_back(MmmttSecondTauIso_loose);
    MmmttSecondTauIsoMedium.push_back(MmmttSecondTauIso_medium);
    MmmttSecondTauIsoTight.push_back(MmmttSecondTauIso_tight);
    
    MmmttBothTauIsoLoose.push_back(MmmttBothTauIso_loose);
    MmmttBothTauIsoMedium.push_back(MmmttBothTauIso_medium);
    MmmttBothTauIsoTight.push_back(MmmttBothTauIso_tight);
    
    MeettNoIso.push_back(MeettNoIso_);
    
    MeettFirstTauIsoLoose.push_back(MeettFirstTauIso_loose);
    MeettSecondTauIsoLoose.push_back(MeettSecondTauIso_loose);
    MeettBothTauIsoLoose.push_back(MeettBothTauIso_loose);

    MeettFirstTauIsoMedium.push_back(MeettFirstTauIso_medium);
    MeettSecondTauIsoMedium.push_back(MeettSecondTauIso_medium);
    MeettBothTauIsoMedium.push_back(MeettBothTauIso_medium);

    MeettFirstTauIsoTight.push_back(MeettFirstTauIso_tight);
    MeettSecondTauIsoTight.push_back(MeettSecondTauIso_tight);
    MeettBothTauIsoTight.push_back(MeettBothTauIso_tight);
        
    // Jet FR Electron Control Region
    Mmmet_noIso.push_back(Mmmet_noIso_);
    Meeet_noIso.push_back(Meeet_noIso_);
    // Jet FR Muon Control Region
    Mmmmt_noIso.push_back(Mmmmt_noIso_);
    Meemt_noIso.push_back(Meemt_noIso_);
    
    Mmmet_IsoLoose.push_back(Mmmet_Iso_loose);
    Meeet_IsoLoose.push_back(Meeet_Iso_loose);
    Mmmmt_IsoLoose.push_back(Mmmmt_Iso_loose);
    Meemt_IsoLoose.push_back(Meemt_Iso_loose);

    Mmmet_IsoMedium.push_back(Mmmet_Iso_medium);
    Meeet_IsoMedium.push_back(Meeet_Iso_medium);
    Mmmmt_IsoMedium.push_back(Mmmmt_Iso_medium);
    Meemt_IsoMedium.push_back(Meemt_Iso_medium);

    Mmmet_IsoTight.push_back(Mmmet_Iso_tight);
    Meeet_IsoTight.push_back(Meeet_Iso_tight);
    Mmmmt_IsoTight.push_back(Mmmmt_Iso_tight);
    Meemt_IsoTight.push_back(Meemt_Iso_tight);
    }
    //----------------------------------------------
    //-----Fake Rate Histo Filling------------------
    //----------------------------------------------
    if(fillFR){
      if(ifile == nfiles-1){
	//Pt
	JetFRTauPtNumeratorTight.push_back(TauPtAfterIso_eett_tight);
	JetFRTauPtNumeratorMedium.push_back(TauPtAfterIso_eett_medium);
	JetFRTauPtNumeratorLoose.push_back(TauPtAfterIso_eett_loose);
	JetFRTauPtDenominator.push_back(TauPtBeforeIso_eett_);
	
	JetFRTauPtNumeratorTight.push_back(TauPtAfterIso_mmtt_tight);
	JetFRTauPtNumeratorMedium.push_back(TauPtAfterIso_mmtt_medium);
	JetFRTauPtNumeratorLoose.push_back(TauPtAfterIso_mmtt_loose);
	JetFRTauPtDenominator.push_back(TauPtBeforeIso_mmtt_);
	
	//Phi
	JetFRTauPhiNumeratorTight.push_back(TauPhiAfterIso_eett_tight);
	JetFRTauPhiNumeratorMedium.push_back(TauPhiAfterIso_eett_medium);
	JetFRTauPhiNumeratorLoose.push_back(TauPhiAfterIso_eett_loose);
	JetFRTauPhiDenominator.push_back(TauPhiBeforeIso_eett_);
	
	JetFRTauPhiNumeratorTight.push_back(TauPhiAfterIso_mmtt_tight);
	JetFRTauPhiNumeratorMedium.push_back(TauPhiAfterIso_mmtt_medium);
	JetFRTauPhiNumeratorLoose.push_back(TauPhiAfterIso_mmtt_loose);
	JetFRTauPhiDenominator.push_back(TauPhiBeforeIso_mmtt_);
	
	//Eta
	JetFRTauEtaNumeratorTight.push_back(TauEtaAfterIso_eett_tight);
	JetFRTauEtaNumeratorMedium.push_back(TauEtaAfterIso_eett_medium);
	JetFRTauEtaNumeratorLoose.push_back(TauEtaAfterIso_eett_loose);
	JetFRTauEtaDenominator.push_back(TauEtaBeforeIso_eett_);
	
	JetFRTauEtaNumeratorTight.push_back(TauEtaAfterIso_mmtt_tight);
	JetFRTauEtaNumeratorMedium.push_back(TauEtaAfterIso_mmtt_medium);
	JetFRTauEtaNumeratorLoose.push_back(TauEtaAfterIso_mmtt_loose);
	JetFRTauEtaDenominator.push_back(TauEtaBeforeIso_mmtt_);
	
	
	//PU
	JetFRTauPUNumeratorTight.push_back(PU_AfterIsoeett_tight);
	JetFRTauPUNumeratorMedium.push_back(PU_AfterIsoeett_medium);
	JetFRTauPUNumeratorLoose.push_back(PU_AfterIsoeett_loose);
	JetFRTauPUDenominator.push_back(PU_BeforeIsoeett_);
	
	JetFRTauPUNumeratorTight.push_back(PU_AfterIsommtt_tight);
	JetFRTauPUNumeratorMedium.push_back(PU_AfterIsommtt_medium);
	JetFRTauPUNumeratorLoose.push_back(PU_AfterIsommtt_loose);
	JetFRTauPUDenominator.push_back(PU_BeforeIsommtt_);
	
	
	//Pt
	ElePtDenominator.push_back(ElePt_denominator_eeet_);
	ElePtNumeratorLoose.push_back(ElePt_numerator_eeet_loose);
	ElePtNumeratorMedium.push_back(ElePt_numerator_eeet_medium);
	ElePtNumeratorTight.push_back(ElePt_numerator_eeet_tight);
	
	ElePtDenominator.push_back(ElePt_denominator_mmet_);
	ElePtNumeratorLoose.push_back(ElePt_numerator_mmet_loose);
	ElePtNumeratorMedium.push_back(ElePt_numerator_mmet_medium);
	ElePtNumeratorTight.push_back(ElePt_numerator_mmet_medium);
	
	MuPtDenominator.push_back(MuPt_denominator_eemt_);
	MuPtNumeratorLoose.push_back(MuPt_numerator_eemt_loose);
	MuPtNumeratorMedium.push_back(MuPt_numerator_eemt_medium);
	MuPtNumeratorTight.push_back(MuPt_numerator_eemt_tight);
	
	MuPtDenominator.push_back(MuPt_denominator_mmmt_);
	MuPtNumeratorLoose.push_back(MuPt_numerator_mmmt_loose);
	MuPtNumeratorMedium.push_back(MuPt_numerator_mmmt_medium);
	MuPtNumeratorTight.push_back(MuPt_numerator_mmmt_tight);
	
	//Eta
	EleEtaDenominator.push_back(EleEta_denominator_eeet_);
	EleEtaNumeratorLoose.push_back(EleEta_numerator_eeet_loose);
	EleEtaNumeratorMedium.push_back(EleEta_numerator_eeet_medium);
	EleEtaNumeratorTight.push_back(EleEta_numerator_eeet_tight);
	
	EleEtaDenominator.push_back(EleEta_denominator_mmet_);
	EleEtaNumeratorLoose.push_back(EleEta_numerator_mmet_loose);
	EleEtaNumeratorMedium.push_back(EleEta_numerator_mmet_medium);
	EleEtaNumeratorTight.push_back(EleEta_numerator_mmet_medium);
	
	MuEtaDenominator.push_back(MuEta_denominator_eemt_);
	MuEtaNumeratorLoose.push_back(MuEta_numerator_eemt_loose);
	MuEtaNumeratorMedium.push_back(MuEta_numerator_eemt_medium);
	MuEtaNumeratorTight.push_back(MuEta_numerator_eemt_tight);
	
	MuEtaDenominator.push_back(MuEta_denominator_mmmt_);
	MuEtaNumeratorLoose.push_back(MuEta_numerator_mmmt_loose);
	MuEtaNumeratorMedium.push_back(MuEta_numerator_mmmt_medium);
	MuEtaNumeratorTight.push_back(MuEta_numerator_mmmt_tight);

	//Phi
	ElePhiDenominator.push_back(ElePhi_denominator_eeet_);
	ElePhiNumeratorLoose.push_back(ElePhi_numerator_eeet_loose);
	ElePhiNumeratorMedium.push_back(ElePhi_numerator_eeet_medium);
	ElePhiNumeratorTight.push_back(ElePhi_numerator_eeet_tight);
	
	ElePhiDenominator.push_back(ElePhi_denominator_mmet_);
	ElePhiNumeratorLoose.push_back(ElePhi_numerator_mmet_loose);
	ElePhiNumeratorMedium.push_back(ElePhi_numerator_mmet_medium);
	ElePhiNumeratorTight.push_back(ElePhi_numerator_mmet_medium);
	
	MuPhiDenominator.push_back(MuPhi_denominator_eemt_);
	MuPhiNumeratorLoose.push_back(MuPhi_numerator_eemt_loose);
	MuPhiNumeratorMedium.push_back(MuPhi_numerator_eemt_medium);
	MuPhiNumeratorTight.push_back(MuPhi_numerator_eemt_tight);
	
	MuPhiDenominator.push_back(MuPhi_denominator_mmmt_);
	MuPhiNumeratorLoose.push_back(MuPhi_numerator_mmmt_loose);
	MuPhiNumeratorMedium.push_back(MuPhi_numerator_mmmt_medium);
	MuPhiNumeratorTight.push_back(MuPhi_numerator_mmmt_tight);
	
	
	//PU
	ElePUDenominator.push_back(ElePU_denominator_eeet_);
	ElePUNumeratorLoose.push_back(ElePU_numerator_eeet_loose);
	ElePUNumeratorMedium.push_back(ElePU_numerator_eeet_medium);
	ElePUNumeratorTight.push_back(ElePU_numerator_eeet_tight);
	
	ElePUDenominator.push_back(ElePU_denominator_mmet_);
	ElePUNumeratorLoose.push_back(ElePU_numerator_mmet_loose);
	ElePUNumeratorMedium.push_back(ElePU_numerator_mmet_medium);
	ElePUNumeratorTight.push_back(ElePU_numerator_mmet_medium);
	
	MuPUDenominator.push_back(MuPU_denominator_eemt_);
	MuPUNumeratorLoose.push_back(MuPU_numerator_eemt_loose);
	MuPUNumeratorMedium.push_back(MuPU_numerator_eemt_medium);
	MuPUNumeratorTight.push_back(MuPU_numerator_eemt_tight);
	
	MuPUDenominator.push_back(MuPU_denominator_mmmt_);
	MuPUNumeratorLoose.push_back(MuPU_numerator_mmmt_loose);
	MuPUNumeratorMedium.push_back(MuPU_numerator_mmmt_medium);
	MuPUNumeratorTight.push_back(MuPU_numerator_mmmt_tight);
      }// if(ifile ==nfiles-1){......}
    }
  }
  
  std::vector<Double_t> Xsection;
  Xsection.clear();
  if(eightTeV){
    Xsection.push_back(18.5296)         ; //HZZ
    Xsection.push_back(9.74);//ZZto2L2L
    Xsection.push_back(3.85);//ZZTo4L
    Xsection.push_back(76.91); //ZZ to 4mu
    Xsection.push_back(76.91); //ZZ to 4e
    Xsection.push_back(76.91); //ZZ to 4tau
    Xsection.push_back(176.7); //ZZ to 2e2mu
    Xsection.push_back(176.7); //ZZ to 2mu2tau
    Xsection.push_back(176.7); //ZZ to 2e2tau
    Xsection.push_back(1057.)        ; //WZ
    Xsection.push_back(23640)        ; //tt
    Xsection.push_back(3503710.)      ; //Z+Jets
    Xsection.push_back(1.); //data just for book keeping
  }
  if(sevenTeV){
    Xsection.push_back(13.6); //HZZ  
    Xsection.push_back(106.0);//ZZ  
    Xsection.push_back(339.4); //WZ   
    Xsection.push_back(17320.0);//tt   
    Xsection.push_back(3048000);//Z+Jets
    Xsection.push_back(1.); //data just for book keeping
  }
  Double_t integral;
  TString title = ;
  TString inputTreeName = "tree";
  
  TFile *FileObj[nfiles];
  TH1F *histo[nfiles] ;
  
  TH1F *Ratio;
  char rationame[100];
  
  
  std::vector<Int_t> fillcolor;
  fillcolor.clear();
  fillcolor.push_back(2);
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(3);//ZZ
  fillcolor.push_back(5);
  fillcolor.push_back(7);
  fillcolor.push_back(20);
  fillcolor.push_back(1);
  
  
  std::vector<Int_t> markerstyle;
  markerstyle.clear();
  markerstyle.push_back(33);
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(22);//ZZ
  markerstyle.push_back(23);
  markerstyle.push_back(33);
  markerstyle.push_back(21);
  markerstyle.push_back(20);
  
  
  std::vector<TString> SampleName;
  SampleName.clear();
  SampleName.push_back("H->ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("EWK ZZ");
  SampleName.push_back("WZ");
  SampleName.push_back("tt~");
  SampleName.push_back("DY+Jets");
  SampleName.push_back("Data");
  
  
  std::vector<char*>  postname;
  postname.push_back("HZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("ZZ")  ;
  postname.push_back("WZ")  ;
  postname.push_back("tt")  ;
  postname.push_back("DYJets")  ;
  postname.push_back("Data")  ;
  

  if(fillstack){
    int rebinOne = 1;
    FillStackedHisto(mmttVector , "mmttVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statusmmtt", "",2.0 , 10.,rebinOne);
    FillStackedHisto(mmetVector , "mmetVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statusmmet", "",2.0 , 9.,rebinOne);
    FillStackedHisto(mmmtVector , "mmmtVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statusmmmt","", 2.0 , 9.,rebinOne);
    FillStackedHisto(mmmeVector , "mmmeVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statusmmme", "",2.0 , 7.,rebinOne);
    FillStackedHisto(eettVector , "eettVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statuseett", "",2.0 , 10.,rebinOne);
    FillStackedHisto(eeetVector , "eeetVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statuseeet","", 2.0 , 9.,rebinOne);
    FillStackedHisto(eemtVector , "eemtVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statuseemt","", 2.0 , 9.,rebinOne);
    FillStackedHisto(eeemVector , "eeemVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "statuseeem", "",2.0 , 7.,rebinOne);
  
  
    FillStackedHisto (MeeVector     , "MeeVector"   , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "Zll",
		      "M_{ee} (in GeV) ", 60.0, 120. ,rebinOne);
    FillStackedHisto (MmmVector     , "MmmVector"   , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "Zll",
		      "M_{#mu#mu} (in GeV) ", 60.0, 120. ,rebinOne);

    
    FillStackedHisto (leadingeleIsoVector     , "leadingeleIsoVector"   , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "isoe1",
		      "I_{rel. comb}^{PF} (leading e)", 0.0, 0.25 ,rebinOne);
    FillStackedHisto (leadingmuIsoVector      , "leadingmuIsoVector"    , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "isom1",
		      "_{rel. comb}^{PF} (leading #mu)", 0.0, 0.25,rebinOne);
    //FillStackedHisto (subleadingmuIsoVector   , "subleadingmuIsoVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "isom2",
    //	      "I_{rel. comb}^{PF} (sub-leading #mu)" , 0.0, 0.25,rebinOne);
    //FillStackedHisto (subleadingeleIsoVector  , "subleadingeleIsoVector", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "isoe2",
    //	      "I_{rel. comb}^{PF} (sub-leading e)" ,  0.0, 0.25,rebinOne);
  
    //FillStackedHisto (leadingeleEtaVector     , "leadingeleEtaVector"   , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "etae1",
    //		      "#eta_{leading e}" , -2.5, 2.5 ,rebinOne);
    //FillStackedHisto (leadingmuEtaVector      , "leadingmuEtaVector"    , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "etam1",
    //		      "#eta_{leading #mu}" , -2.5, 2.5,rebinOne);
    //FillStackedHisto (subleadingmuEtaVector   , "subleadingmuEtaVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "etam2",
    //		      "#eta_{sub-leading #mu}" , -2.5, 2.5,rebinOne);
    //FillStackedHisto (subleadingeleEtaVector  , "subleadingeleEtaVector", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "etae2",
    //		      "#eta_{sub-leading e}" , -2.5, 2.5,rebinOne);
    //
    //FillStackedHisto (leadingelePtVector      , "leadingelePtVector"    , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "pte1",
    //		      "p_{T}^{leading e}" , 10.0 , 200.0,rebinOne);
    //FillStackedHisto (leadingmuPtVector       , "leadingmuPtVector"     , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "ptm1",
    //		      "p_{T}^{leading #mu}" , 10.0 , 200.0,rebinOne);
    //FillStackedHisto (subleadingelePtVector   , "subleadingelePtVector" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "pte2",
    //		      "p_{T}^{sub-leading e}" , 10.0 , 200.0,rebinOne);
    //FillStackedHisto (subleadingmuPtVector    , "subleadingmuPtVector"  , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "ptm2",
    //      "p_{T}^{sub-leading #mu}" , 10.0 , 200.0,rebinOne);
    
    double xhighForHiggs = 600.0;
    if(fordisplay)  xhighForHiggs = 400.0 ; 
    else   xhighForHiggs = 2000.0;
    int rebin25 = 25;
    FillStackedHisto (MmmttNoIso           , "MmmttNoIso"          , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    
    //FillStackedHisto (MmmttFirstTauIsoLoose, "MmmttFirstTauIsoLoose", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MmmttFirstTauIsoMedium, "MmmttFirstTauIsoMedium", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MmmttFirstTauIsoTight, "MmmttFirstTauIsoTight", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //
    //FillStackedHisto (MmmttSecondTauIsoLoose, "MmmttSecondTauIsoLoose", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MmmttSecondTauIsoMedium,"MmmttSecondTauIsoMedium", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MmmttSecondTauIsoTight, "MmmttSecondTauIsoTight" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //
    //FillStackedHisto (MmmttBothTauIsoLoose, "MmmttBothTauIsoLoose" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MmmttBothTauIsoMedium, "MmmttBothTauIsoMedium", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MmmttBothTauIsoTight, "MmmttBothTauIsoTight", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //	      "M_{#mu#mu#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    
    FillStackedHisto (MeettNoIso	         , "MeettNoIso"          , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    
    //FillStackedHisto (MeettFirstTauIsoLoose , "MeettFirstTauIsoLoose" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MeettFirstTauIsoMedium, "MeettFirstTauIsoMedium", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MeettFirstTauIsoTight , "MeettFirstTauIsoTight", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //
    //FillStackedHisto (MeettSecondTauIsoLoose , "MeettSecondTauIsoLoose", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MeettSecondTauIsoMedium,"MeettSecondTauIsoMedium", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MeettSecondTauIsoTight, "MeettSecondTauIsoTight", SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs,rebin25 );
    //
    //FillStackedHisto (MeettBothTauIsoLoose, "MeettBothTauIsoLoose" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs,rebin25 );
    //FillStackedHisto (MeettBothTauIsoMedium, "MeettBothTauIsoMedium" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (MeettBothTauIsoTight, "MeettBothTauIsoTight" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //	      "M_{ee#tau_{h}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    
    FillStackedHisto (Mmmet_noIso	         , "Mmmet_noIso"         , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
		      "M_{#mu#mu#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    FillStackedHisto (Meeet_noIso	         , "Meeet_noIso"         , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
		      "M_{ee#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    FillStackedHisto (Mmmmt_noIso	         , "Mmmmt_noIso"         , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
                    "M_{#mu#mu#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    FillStackedHisto (Meemt_noIso	         , "Meemt_noIso"         , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
		      "M_{ee#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    
    //FillStackedHisto (Mmmet_IsoLoose , "Mmmet_IsoLoose"  , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Meeet_IsoLoose , "Meeet_IsoLoose"  , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Mmmmt_IsoLoose , "Mmmmt_IsoLoose"  , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs,rebin25 );
    //FillStackedHisto (Meemt_IsoLoose , "Meemt_IsoLoose"  , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //
    //FillStackedHisto (Mmmet_IsoMedium, "Mmmet_IsoMedium" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs,rebin25 );
    //FillStackedHisto (Meeet_IsoMedium, "Meeet_IsoMedium" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Mmmmt_IsoMedium, "Mmmmt_IsoMedium" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Meemt_IsoMedium, "Meemt_IsoMedium" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "_{ee#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //
    //
    //FillStackedHisto (Mmmet_IsoTight, "Mmmet_IsoTight" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Meeet_IsoTight, "Meeet_IsoTight" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{ee#tau_{e}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Mmmmt_IsoTight, "Mmmmt_IsoTight" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //		      "M_{#mu#mu#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    //FillStackedHisto (Meemt_IsoTight, "Meemt_IsoTight" , SampleName , Xsection , fillcolor , EventProcessed , markerstyle , "fourlCR",
    //	      "M_{ee#tau_{#mu}#tau_{h}}" , 100.0 , xhighForHiggs ,rebin25);
    
  }
  //----------------------------------------------
  //-----Fake Rate Histo Filling------------------
  //----------------------------------------------
  
  if(fillFR){
    TFile *FRRootFile = new TFile ("FRRootFile.root","RECREATE");
    
    // Jet to Tau
    FillFakeRateGraphs(JetFRTauPtNumeratorTight, JetFRTauPtDenominator, "JetFRTauPtTight" , FRRootFile , true , "p_{T}^{jet}" , 0.0 , 120.0 , true, 0.4 , 2);
    FillFakeRateGraphs(JetFRTauPtNumeratorMedium, JetFRTauPtDenominator, "JetFRTauPtMedium" , FRRootFile , true , "p_{T}^{jet}" , 0.0 , 120.0 , true, 0.4 , 2);
    //FillFakeRateGraphs(JetFRTauPtNumeratorLoose, JetFRTauPtDenominator, "JetFRTauPtLoose", true );
    
    FillFakeRateGraphs(JetFRTauPhiNumeratorTight, JetFRTauPhiDenominator, "JetFRTauPhiTight" , FRRootFile , false, "#phi^{jet}" ,   -3.5 , 3.5  , true, 0.4 ,2);
    FillFakeRateGraphs(JetFRTauPhiNumeratorMedium, JetFRTauPhiDenominator, "JetFRTauPhiMedium" , FRRootFile , false, "#phi^{jet}" ,  -3.5 , 3.5 , true, 0.4 ,2);
    //FillFakeRateGraphs(JetFRTauPhiNumeratorLoose, JetFRTauPhiDenominator, "JetFRTauPhiLoose", true );

    FillFakeRateGraphs(JetFRTauEtaNumeratorTight, JetFRTauEtaDenominator, "JetFRTauEtaTight" , FRRootFile  , false, "#eta^{jet}" ,   -2.5 , 2.5 , true, 0.4 ,2);
    FillFakeRateGraphs(JetFRTauEtaNumeratorMedium, JetFRTauEtaDenominator, "JetFRTauEtaMedium" , FRRootFile , false, "#eta^{jet}" ,  -2.5 , 2.5 , true, 0.4 ,2);
    //FillFakeRateGraphs(JetFRTauEtaNumeratorLoose, JetFRTauEtaDenominator, "JetFRTauEtaLoose", true );
    
    //FillFakeRateGraphs(JetFRTauPUNumeratorTight, JetFRTauPUDenominator, "JetFRTauPUTight" , FRRootFile  , false, "NPU" , 0.0 ,  50.0 , true, 0.4 ,2);
    //FillFakeRateGraphs(JetFRTauPUNumeratorMedium, JetFRTauPUDenominator, "JetFRTauPUMedium" , FRRootFile , false, "NPU" , 0.0 , 50.0 , true, 0.4 ,2);
    //FillFakeRateGraphs(JetFRTauPUNumeratorLoose, JetFRTauPUDenominator, "JetFRTauPULoose", true );

    //Jet to Electron
    FillFakeRateGraphs(ElePtNumeratorLoose  , ElePtDenominator, "JetFRElePtLoose"  , FRRootFile  , true, "p_{T}^{electron}" , 0.0 , 120.0 , true, 0.6 ,1);
    FillFakeRateGraphs(ElePtNumeratorMedium , ElePtDenominator, "JetFRElePtMedium" , FRRootFile  , false, "p_{T}^{electron}" , 0.0 , 120.0 , true, 0.6 ,1);
    FillFakeRateGraphs(ElePtNumeratorTight  , ElePtDenominator, "JetFRElePtTight"  , FRRootFile  , true, "p_{T}^{electron}" , 0.0 , 120.0 , true, 0.6 ,1);
    
    //FillFakeRateGraphs(EleEtaNumeratorLoose  , EleEtaDenominator, "JetFREleEtaLoose"  , FRRootFile  , false, "#eta^{electron}" , -2.5 , 2.5 , true ,4 );
    //FillFakeRateGraphs(EleEtaNumeratorMedium , EleEtaDenominator, "JetFREleEtaMedium" , FRRootFile  , false, "#eta^{electron}" , -2.5 , 2.5 , true ,4 );
    //FillFakeRateGraphs(EleEtaNumeratorTight  , EleEtaDenominator, "JetFREleEtaTight"  , FRRootFile  , false, "#eta^{electron}" , -2.5 , 2.5 , true ,4 );
    //
    //FillFakeRateGraphs(ElePhiNumeratorLoose  , ElePhiDenominator, "JetFRElePhiLoose"  , FRRootFile  , false, "#phi^{electron}" , -3.5 , 3.5  , true ,4 );
    //FillFakeRateGraphs(ElePhiNumeratorMedium , ElePhiDenominator, "JetFRElePhiMedium" , FRRootFile  , false, "#phi^{electron}" , -3.5 , 3.5  , true ,4 );
    //FillFakeRateGraphs(ElePhiNumeratorTight  , ElePhiDenominator, "JetFRElePhiTight"  , FRRootFile  , false, "#phi^{electron}" , -3.5 , 3.5  , true ,4 );
    //
    //FillFakeRateGraphs(ElePUNumeratorLoose  , ElePUDenominator, "JetFRElePULoose"  , FRRootFile  , false, "NPU" , 0.0 , 50.0 , true ,4 );
    //FillFakeRateGraphs(ElePUNumeratorMedium , ElePUDenominator, "JetFRElePUMedium" , FRRootFile  , false, "NPU" , 0.0 , 50.0 , true ,4 );
    //FillFakeRateGraphs(ElePUNumeratorTight  , ElePUDenominator, "JetFRElePUTight"  , FRRootFile  , false, "NPU" , 0.0 , 50.0 , true ,4 );

    // For Jet to Muon
    FillFakeRateGraphs(MuPtNumeratorLoose  , MuPtDenominator, "JetFRMuPtLoose"  , FRRootFile  , true, "p_{T}^{#mu}" , 0.0 , 120.0 , true, 0.4 ,1 );
    FillFakeRateGraphs(MuPtNumeratorMedium , MuPtDenominator, "JetFRMuPtMedium" , FRRootFile  , true, "p_{T}^{#mu}" , 0.0 , 120.0 , true, 0.4 ,1 );
    FillFakeRateGraphs(MuPtNumeratorTight  , MuPtDenominator, "JetFRMuPtTight"  , FRRootFile  , false, "p_{T}^{#mu}" , 0.0 , 120.0 , true, 0.4 ,1 );

    //FillFakeRateGraphs(MuEtaNumeratorLoose  , MuEtaDenominator, "JetFRMuEtaLoose"  , FRRootFile  , false, "#eta^{#mu}" , -2.5 , 2.5  , true ,4 );
    //FillFakeRateGraphs(MuEtaNumeratorMedium , MuEtaDenominator, "JetFRMuEtaMedium" , FRRootFile  , false, "#eta^{#mu}" , -2.5 , 2.5  , true ,4 );
    //FillFakeRateGraphs(MuEtaNumeratorTight  , MuEtaDenominator, "JetFRMuEtaTight"  , FRRootFile  , false, "#eta^{#mu}" , -2.5 , 2.5  , true ,4 );
    //
    //FillFakeRateGraphs(MuPhiNumeratorLoose  , MuPhiDenominator, "JetFRMuPhiLoose"  , FRRootFile  , false, "#phi^{#mu}" , -3.5 , 3.5  , true ,4 );
    //FillFakeRateGraphs(MuPhiNumeratorMedium , MuPhiDenominator, "JetFRMuPhiMedium" , FRRootFile  , false, "#phi^{#mu}" , -3.5 , 3.5  , true ,4 );
    //FillFakeRateGraphs(MuPhiNumeratorTight  , MuPhiDenominator, "JetFRMuPhiTight"  , FRRootFile  , false, "#phi^{#mu}" , -3.5 , 3.5  , true ,4 );
    //
    //FillFakeRateGraphs(MuPUNumeratorLoose  , MuPUDenominator, "JetFRMuPULoose"  , FRRootFile  , false, "NPU" , 0.0 , 50.0 , true ,4 );
    //FillFakeRateGraphs(MuPUNumeratorMedium , MuPUDenominator, "JetFRMuPUMedium" , FRRootFile  , false, "NPU" , 0.0 , 50.0 , true ,4 );
    //FillFakeRateGraphs(MuPUNumeratorTight  , MuPUDenominator, "JetFRMuPUTight"  , FRRootFile  , false, "NPU" , 0.0 , 50.0 , true ,4 );
    
    FRRootFile->Close();
  }
  
  if(fillFR){//if(draw2overlapgraphs)
    TFile *FRRootFile = new TFile ("FRRootFile.root","READ");
    FRRootFile->cd();
    DrawTWOOverLappingFRGraphs(  numJetFRTauPtTight , denJetFRTauPtTight ,  numJetFRTauPtMedium , denJetFRTauPtMedium, "FRTau_Medium_Tight",
				 "Tight #tau Iso" , "Medium #tau Iso",0.2,"p_{T}^{#tau_{h}}", 2);
    DrawTWOOverLappingFRGraphs(  numJetFRElePtTight , denJetFRElePtTight ,  numJetFRElePtLoose , denJetFRElePtLoose ,"FREle_Loose_Tight","Tight e Iso",
				 "Loose e Iso", 1.0, "p_{T}^{electron}", 1);
    DrawTWOOverLappingFRGraphs(  numJetFRMuPtTight , denJetFRMuPtTight ,  numJetFRMuPtLoose , denJetFRMuPtLoose ,"FRMu_Loose_Tight", "Tight #mu Iso",
				 "Loose #mu Iso",1.0,"p_{T}^{#mu}", 1);
    
  }
  
}
void FillStackedHisto(std::vector<TH1F*> histvector , TString gifFilename, std::vector<TString> SampleName,
		      std::vector<Double_t> Xsection, std::vector<Int_t> fillcolor , std::vector<Double_t> EventProcessed ,
		      std::vector<Int_t> markerstyle, TString type, TString XaxisTitle=" " , double xLow=0.0, double xHigh=1000.0, int rebin ) {
  
  float luminosity = 19.3 ; // in fb -1
  
  THStack* hstack = new THStack("higgsstack","");
  TLegend *leg = new TLegend(0.73,0.68,0.89,0.89,NULL,"brNDC");
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);

  
  int nfiles = int(histvector.size());
  double y=0.;
  for (int ifile=1; ifile < int(histvector.size()); ifile++) {
    //std::cout<<" working ::   "<<histvector[ifile]->Integral()<<std::endl;
    histvector[ifile]->Rebin(rebin);
    if(ifile<(nfiles-1)){
      histvector[ifile]->Scale((Xsection[ifile]*luminosity)/EventProcessed[ifile]);
      //histvector[ifile]->SetMarkerStyle(markerstyle[ifile]);
      //histvector[ifile]->SetMarkerColor(fillcolor[ifile]);
      histvector[ifile]->SetMarkerStyle(markerstyle[ifile]);
      histvector[ifile]->SetFillColor(fillcolor[ifile]);

      histvector[ifile]->SetLineColor(kBlack);

      
      if( ifile==1 ) {
	std::cout<<" yield of "<<ifile<<"  = "<<histvector[ifile]->Integral()<<std::endl;
	TH1F* ZZ = (TH1F*)histvector[ifile]->Clone("ZZ");
	y += histvector[ifile]->Integral();
      }
      if( ifile > 1 && ifile < 9 ){
	ZZ->Add(histvector[ifile]);
	std::cout<<" yield of "<<ifile<<"  = "<<histvector[ifile]->Integral()<<std::endl;
	y += histvector[ifile]->Integral();
      }
      //histvector[ifile]->SetLineColor(fillcolor[ifile]); 
      
      histvector[ifile]->SetLineWidth(2);      
      
      if( !(ifile>0 && ifile < 9 ) ){
	hstack->Add(histvector[ifile]);
      }
      else if (ifile ==8){
	std::cout<<"total yield of ZZ = "<<ZZ->Integral()<<std::endl;
	std::cout<<"total yield = "<<y<<std::endl;
	
	ZZ->SetLineColor(kBlack);
	ZZ->SetLineWidth(2);
	ZZ->SetFillColor(fillcolor[ifile]);
      	hstack->Add(ZZ);
      }
      
      hstack->SetMinimum(0.5);
      //hstack->SetMaximum(100000000);
      hstack->SetMaximum(1000000);
      if( !(ifile>0 && ifile < 8 ) ){	//leg->AddEntry(histvector[ifile],SampleName[ifile],"f");
      }
      hstack->Draw();
    }
    
    if(ifile==(nfiles-1)){
      histvector[ifile]->Draw("SAME,E1");
      histvector[ifile]->SetLineColor(1);
      std::cout<<" number of events in data = "<<histvector[ifile]->Integral()<<std::endl;
      
      //leg->AddEntry(histvector[ifile],SampleName[ifile],"lep");
      histvector[ifile]->SetMarkerStyle(kFullCircle);
    }
    
  }
    TLegendEntry *entry=leg->AddEntry(histvector[12],SampleName[12],"P");
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(1);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(20);
    entry->SetMarkerSize(1.1);
    
    TLegendEntry *entry=leg->AddEntry(histvector[11],SampleName[11],"f");
    TLegendEntry *entry=  leg->AddEntry(histvector[10],SampleName[10],"f");
    TLegendEntry *entry=  leg->AddEntry(histvector[9],SampleName[9],"f");
    TLegendEntry *entry=  leg->AddEntry(histvector[8],SampleName[8],"f");
    
    /*
    TLegendEntry *entry=leg->AddEntry(histvector[11],SampleName[11],"p");
    TLegendEntry *entry=  leg->AddEntry(histvector[10],SampleName[10],"p");
    TLegendEntry *entry=  leg->AddEntry(histvector[9],SampleName[9],"p");
    TLegendEntry *entry=  leg->AddEntry(histvector[8],SampleName[8],"p");
    */
    
  
  if( type == "statusmmtt"  || type == "statuseett" ){
    hstack->GetXaxis()->SetRangeUser(2,10);
    hstack->GetXaxis()->SetBinLabel(2,"Z1 Selected");
    hstack->GetXaxis()->SetBinLabel(3,"p_{T}^{#tau}");
    hstack->GetXaxis()->SetBinLabel(4,"charge");
    hstack->GetXaxis()->SetBinLabel(5,"Z2 Mass");
    hstack->GetXaxis()->SetBinLabel(6,"#mu Veto");
    hstack->GetXaxis()->SetBinLabel(7,"e veto");
    hstack->GetXaxis()->SetBinLabel(8,"#tau_{1} Iso");
    hstack->GetXaxis()->SetBinLabel(9,"#tau_{2} Iso");
    hstack->GetXaxis()->SetBinLabel(10,"4l veto");
  }
  
  if( type == "statuseeet" || type == "statusmmet"){
    hstack->GetXaxis()->SetRangeUser(2,9);
    hstack->GetXaxis()->SetBinLabel(2,"Z1 Selected");
    hstack->GetXaxis()->SetBinLabel(3,"Iso_{lepton}");
    hstack->GetXaxis()->SetBinLabel(4,"charge");
    hstack->GetXaxis()->SetBinLabel(5,"Z2 Mass");
    hstack->GetXaxis()->SetBinLabel(6,"#mu Veto");
    hstack->GetXaxis()->SetBinLabel(7,"e veto");
    hstack->GetXaxis()->SetBinLabel(8,"#tau Iso, p_{T}");
    hstack->GetXaxis()->SetBinLabel(9,"4l veto");
  }

  
  if( type == "statuseemt" || type == "statusmmmt"){
    hstack->GetXaxis()->SetRangeUser(2,9);
    hstack->GetXaxis()->SetBinLabel(2,"Z1 Selected");
    hstack->GetXaxis()->SetBinLabel(3,"#mu Veto");
    hstack->GetXaxis()->SetBinLabel(4,"e veto");
    hstack->GetXaxis()->SetBinLabel(5,"Iso_{lepton}");
    hstack->GetXaxis()->SetBinLabel(6,"charge");
    hstack->GetXaxis()->SetBinLabel(7,"Z2 Mass");
    hstack->GetXaxis()->SetBinLabel(8,"#tau Iso, p_{T}");
    hstack->GetXaxis()->SetBinLabel(9,"4l veto");
  }
  

  
  if( type == "statuseeem" || type == "statusmmme"){
    hstack->GetXaxis()->SetRangeUser(2,7);
    hstack->GetXaxis()->SetBinLabel(2,"Z1 Selected");
    hstack->GetXaxis()->SetBinLabel(3,"e Iso");
    hstack->GetXaxis()->SetBinLabel(4,"#mu Iso");
    hstack->GetXaxis()->SetBinLabel(5,"charge");
    hstack->GetXaxis()->SetBinLabel(6,"Z2 Mass");
    hstack->GetXaxis()->SetBinLabel(7,"4l veto");
  }
  
  hstack->GetXaxis()->SetRangeUser(xLow, xHigh);
  hstack->GetXaxis()->SetTitle(XaxisTitle);
    
  if( type == "pte1"){
    hstack->GetXaxis()->SetRangeUser(10,200);
    hstack->GetXaxis()->SetTitle("p_{T}^{leading e}");
  }
  else if( type == "pte2"){
    hstack->GetXaxis()->SetRangeUser(10,200);
    hstack->GetXaxis()->SetTitle("p_{T}^{sub-leading e}");
  }
  else if( type == "ptm1"){
    hstack->GetXaxis()->SetRangeUser(10,200);
    hstack->GetXaxis()->SetTitle("p_{T}^{leading #mu}");
  }
  else if( type == "ptm2"){
    hstack->GetXaxis()->SetRangeUser(10,200);
    hstack->GetXaxis()->SetTitle("p_{T}^{sub-leading #mu}");
  }

  else if( type == "etae1"){
    hstack->GetXaxis()->SetRangeUser(-2.5,2.5);
    hstack->GetXaxis()->SetTitle("#eta_{leading e}");
  }
  else  if( type == "etae2"){
    hstack->GetXaxis()->SetRangeUser(-2.5,2.5);
    hstack->GetXaxis()->SetTitle("#eta_{sub-leading e}");
  }
  else  if( type == "etam1"){
    hstack->GetXaxis()->SetRangeUser(-2.5,2.5);
    hstack->GetXaxis()->SetTitle("#eta_{leading #mu}");
  }
  else  if( type == "etam2"){
    hstack->GetXaxis()->SetRangeUser(-2.5,2.5);
    hstack->GetXaxis()->SetTitle("#eta_{sub-leading #mu}");
  }
  else if( type == "isoe1"){
    hstack->GetXaxis()->SetRangeUser(0.0,0.25);
    hstack->GetXaxis()->SetTitle("I_{rel. comb}^{PF} (leading e)");
  }
  else if( type == "isoe2"){
    hstack->GetXaxis()->SetRangeUser(0.0,0.25);
    hstack->GetXaxis()->SetTitle("I_{rel. comb}^{PF} (sub-leading e)");
  }
  else if( type == "isom1"){
    hstack->GetXaxis()->SetRangeUser(0.0,0.25);
    hstack->GetXaxis()->SetTitle("I_{rel. comb}^{PF} (leading #mu)");
  }
  else if( type == "isom2"){
    hstack->GetXaxis()->SetRangeUser(0.0,0.25);
    hstack->GetXaxis()->SetTitle("I_{rel. comb}^{PF} (sub-leading #mu)");
  }//New
  else if( type == "isom2"){
    hstack->GetXaxis()->SetRangeUser(0.0,0.25);
    hstack->GetXaxis()->SetTitle("I_{rel. comb}^{PF} (sub-leading #mu)");
  }
     
  //  else std::cout<<" no matched type found"<<std::endl;
  leg->Draw();

  TPaveText *pt = new TPaveText(0.1577181,0.9562937,0.9580537,0.9947552,"brNDC");
  pt->SetBorderSize(0);
  pt->SetTextAlign(12);
  pt->SetFillStyle(0);
  pt->SetTextFont(42);
  pt->SetTextSize(0.03);
  TText *text = pt->AddText(0.01,0.5,"CMS preliminary");
  
  text = pt->AddText(0.3,0.6,"#sqrt{s} = 8 TeV, L = 19.3 fb^{-1}");
  pt->Draw();


  char gifname[200];
  c->SaveAs(outputdirname+"/PDF/"+gifFilename+".pdf");
  c->SaveAs(outputdirname+"/PNG/"+gifFilename+".png");
  c->SaveAs(outputdirname+"/ROOT/"+gifFilename+".root");
  c->SaveAs(outputdirname+"/MACRO/"+gifFilename+".C");
  //c->Close();
}//FillStackedHisto




void FillFakeRateGraphs(std::vector<TH1F*> Numerator, std::vector<TH1F*> Denominator, TString filename , TFile* FRRootFile , bool FitFR,
			TString XaxisTitle , double xLow, double xHigh ,bool  fillFRValue ,double setmax, int rebin){
  
  TCanvas *c = new TCanvas("c", "ZZMass_7Plus8TeV_70-800_10GeV",286,86,600,600);
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  c->Range(-68.75,-7.5,856.25,42.5);
  c->SetFillColor(0);
  c->SetBorderMode(0);
  c->SetBorderSize(2);
  c->SetTickx(1);
  c->SetTicky(1);
  c->SetLeftMargin(0.15);
  c->SetRightMargin(0.05);
  c->SetTopMargin(0.05);
  c->SetBottomMargin(0.15);
  c->SetFrameFillStyle(0);
  c->SetFrameBorderMode(0);
  c->SetFrameFillStyle(0);
  c->SetFrameBorderMode(0);
  c->SetLogy(0);

  
  TGraphAsymmErrors *FR = new TGraphAsymmErrors();
  std::cout<<"Num = "<<Numerator[0]->Integral()
	   <<" : Den = "<<Denominator[0]->Integral()
	   <<std::endl;
  TH1F *num = (TH1F*)Numerator[0]->Clone();
  num->SetName("num"+filename);
  
  TH1F *den = (TH1F*)Denominator[0]->Clone();
  den->SetName("den"+filename);
  //std::cout<<" hist name = "<<den->GetName()<<std::endl;
  num->Add(Numerator[1]);
  den->Add(Denominator[1]);
  num->Rebin(rebin);
  den->Rebin(rebin);
  
  den->GetXaxis()->SetRangeUser(0,120);
  num->GetXaxis()->SetRangeUser(0,120);

  /*  TH1F *tmpnum = (TH1F*)Numerator[0]->Clone();
  TH1F* tmpden = (TH1F*)Denominator[0]->Clone();
  tmpnum->Add(Numerator[1]);
  tmpden->Add(Denominator[1]);
  tmpden->GetXaxis()->SetRangeUser(0,100);
  tmpnum->GetXaxis()->SetRangeUser(0,100);
  
  
  double numbincontent[6]={0,0,0,0,0,0};
  double denbincontent[6]={0,0,0,0,0,0};
  for (int i = 1; i < 6; i++)   numbincontent[0] += tmpnum->GetBinContent(i);    denbincontent[0] += tmpden->GetBinContent(i);
  for (int i = 6; i < 11; i++)  numbincontent[1] += tmpnum->GetBinContent(i);    denbincontent[1] += tmpden->GetBinContent(i);
  for (int i = 11; i < 16; i++) numbincontent[2] += tmpnum->GetBinContent(i);    denbincontent[2] += tmpden->GetBinContent(i);
  for (int i = 16; i < 25; i++) numbincontent[3] += tmpnum->GetBinContent(i);    denbincontent[3] += tmpden->GetBinContent(i);
  for (int i = 26; i < 36; i++) numbincontent[4] += tmpnum->GetBinContent(i);    denbincontent[4] += tmpden->GetBinContent(i);
  for (int i = 36; i < 50; i++) numbincontent[5] += tmpnum->GetBinContent(i);    denbincontent[5] += tmpden->GetBinContent(i);

  for(int i = 0 ; i < 6; i++){
    std::cout<<"num = "<<numbincontent[i]
	     <<"  :   den = "<<denbincontent[i]
	     <<std::endl;
  }
  float nbins[7]={0,10,20,30,50,70,100};
  //TH1F* num = new TH1F("num","num",6,nbins);
  //TH1F* den = new TH1F("den","den",6,nbins);
  TH1F* num = new TH1F("num"+filename,"num",6,nbins);
  TH1F* den = new TH1F("den"+filename,"den",6,nbins);
  
  for(int i = 0 ; i < 6; i++){
    num->SetBinContent(i+1,numbincontent[i]);
    den->SetBinContent(i+1,denbincontent[i]);
  }
  */
  std::cout<<"fake rate =  "<<num->Integral()
	   <<" / "<<den->Integral()
	   <<" = "<<num->Integral()/den->Integral()
	   <<std::endl;
  FRRootFile->cd();
  num->Write();
  den->Write();
    
  FR->Divide(num,den);
  FR->Draw("AP");
  FR->GetYaxis()->SetTitleOffset(1.4);
  FR->SetMinimum(0.0005);
  FR->SetMaximum(setmax);
  //FR->GetXaxis()->SetRangeUser(xLow, xHigh);
  FR->GetXaxis()->SetTitle(XaxisTitle);
  
  //FR->GetXaxis()->SetRangeUser(0,120);
  FR->SetMarkerStyle(21);
  
  TPaveText *pt = new TPaveText(0.1577181,0.9562937,0.9580537,0.9947552,"brNDC");
  pt->SetBorderSize(0);
  pt->SetTextAlign(12);
  pt->SetFillStyle(0);
  pt->SetTextFont(42);
  pt->SetTextSize(0.03);
  TText *text = pt->AddText(0.01,0.5,"CMS preliminary");

  text = pt->AddText(0.3,0.6,"#sqrt{s} = 8 TeV, L = 19.3 fb^{-1}");
  pt->Draw();


  c->SetLogy(0);
  c->SaveAs(outputdirname+"/PDF/"+filename+".pdf");
  c->SaveAs(outputdirname+"/PNG/"+filename+".png");
  c->SaveAs(outputdirname+"/ROOT/"+filename+".root");
  c->SaveAs(outputdirname+"/MACRO/"+filename+".C");
  
  if(FitFR){
    fitFRPlot(FR, filename+"fitted", FRRootFile);
  }

  if(fillFRValue){
    FILLFRVALUE ( FRRootFile , filename , (num->Integral()/den->Integral())  );
  }
}

void DrawTWOOverLappingFRGraphs( TH1F* num1 , TH1F* den1 , TH1F* num2 , TH1F* den2 ,TString pngfilename, TString firstleg, TString secondleg , double setmax ,
				 TString xaxistitle, int rebin) {
  TCanvas *c = new TCanvas("c", "ZZMass_7Plus8TeV_70-800_10GeV",286,86,600,600);

  std::cout<<" tight fr = "<<num1->Integral()<<"/"<<den1->Integral()<<" = "<<num1->Integral()/den1->Integral()
	   <<" loose fr = "<<num2->Integral()<<"/"<<den2->Integral()<<" = "<<num2->Integral()/den2->Integral()
	   <<std::endl;
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  c->Range(-68.75,-7.5,856.25,42.5);
  c->SetFillColor(0);
  c->SetBorderMode(0);
  c->SetBorderSize(2);
  c->SetTickx(1);
  c->SetTicky(1);
  c->SetLeftMargin(0.15);
  c->SetRightMargin(0.05);
  c->SetTopMargin(0.05);
  c->SetBottomMargin(0.15);
  c->SetFrameFillStyle(0);
  c->SetFrameBorderMode(0);
  c->SetFrameFillStyle(0);
  c->SetFrameBorderMode(0);
  c->SetLogy(0);

  TGraphAsymmErrors *FR1 = new TGraphAsymmErrors();
  TGraphAsymmErrors *FR2 = new TGraphAsymmErrors();
  num1->Rebin(rebin);
  den1->Rebin(rebin);
  num2->Rebin(rebin);
  den2->Rebin(rebin);
  
  num1->GetXaxis()->SetRangeUser(0., 120.);
  num2->GetXaxis()->SetRangeUser(0., 120.);
  den1->GetXaxis()->SetRangeUser(0., 120.);
  den2->GetXaxis()->SetRangeUser(0., 120.);

  FR1->Divide(num1,den1);
  FR1->GetXaxis()->SetRangeUser(0., 120.);
  FR1->Draw("AP");
  FR1->SetMinimum(0.0005);
  FR1->SetMarkerStyle(21);
  FR1->SetMaximum(setmax);
  FR1->GetXaxis()->SetTitle(xaxistitle);
  FR1->GetYaxis()->SetTitle("fake rate");
  FR1->GetYaxis()->SetTitleOffset(1.4);


  FR2->Divide(num2,den2);
  FR2->GetXaxis()->SetRangeUser(0., 120.);
  FR2->Draw("P,same"); 
  FR2->SetMarkerStyle(25);
  FR2->GetYaxis()->SetTitleOffset(1.4);

  TPaveText *pt = new TPaveText(0.1577181,0.9562937,0.9580537,0.9947552,"brNDC");
  pt->SetBorderSize(0);
  pt->SetTextAlign(12);
  pt->SetFillStyle(0);
  pt->SetTextFont(42);
  pt->SetTextSize(0.03);
  TText *text = pt->AddText(0.01,0.5,"CMS preliminary");

  text = pt->AddText(0.3,0.6,"#sqrt{s} = 8 TeV, L = 19.3 fb^{-1}");
  pt->Draw();
  
  TLegend *leg = new TLegend(0.73,0.68,0.89,0.89,NULL,"brNDC");
  leg->SetTextSize(0.04);
  leg->SetTextFont(42);
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetFillStyle(0);

  leg->AddEntry(FR1,firstleg,"lep");
  leg->AddEntry(FR2,secondleg,"lep");
  leg->Draw();

  c->SetLogy(0);
  c->SaveAs(outputdirname+"/PDF/"+pngfilename+".pdf");
  c->SaveAs(outputdirname+"/PNG/"+pngfilename+".png");
  c->SaveAs(outputdirname+"/MACRO/"+pngfilename+".C");
  c->SaveAs(outputdirname+"/ROOT/"+pngfilename+".root");
}


double Calculate_givenLumi(Double_t Xsection ,Double_t integral , Double_t EventsProcessed) {
  double weight = Xsection / EventsProcessed ;
  double givenLumi =  integral * weight;
  return givenLumi;
}



double fitFRPlot(TGraphAsymmErrors* grae , TString pngfilename, TFile* FRRootFile){
  //TCanvas *c = new TCanvas("c", "ZZMass_7Plus8TeV_70-800_10GeV",286,86,600,600);
  //gStyle->SetOptStat(0);
  //gStyle->SetOptTitle(0);
  //c->Range(-68.75,-7.5,856.25,42.5);
  //c->SetFillColor(0);
  //c->SetBorderMode(0);
  //c->SetBorderSize(2);
  //c->SetTickx(1);
  //c->SetTicky(1);
  //c->SetLeftMargin(0.15);
  //c->SetRightMargin(0.05);
  //c->SetTopMargin(0.05);
  //c->SetBottomMargin(0.15);
  //c->SetFrameFillStyle(0);
  //c->SetFrameBorderMode(0);
  //c->SetFrameFillStyle(0);
  //c->SetFrameBorderMode(0);
  //c->SetLogy(0);
  
  TF1* myfit  = new TF1("g1","( [0] * TMath::Exp ([1] * x) + [2] )",10.0,100.0);
  myfit->SetParName(0,"c0");
  myfit->SetParName(1,"c1");
  myfit->SetParName(2,"c2");

  myfit->SetParameter(0,  0.024);
  myfit->SetParameter(1, -0.0098 );
  myfit->SetParameter(2, 0.032);

  grae->SetLineColor(1);
  grae->SetLineWidth(2);
  grae->GetXaxis()->SetTitle("p_{T}^{#tau}");
  grae->GetYaxis()->SetTitle("fake rate");
  myfit->SetLineColor(2);
  myfit->SetLineWidth(2);
  grae->Fit(myfit,"R");
  std::cout<<" chi square = "<<grae->Chisquare(myfit)<<std::endl;
  std::cout<<" nDOF       = "<<myfit->GetNDF()<<std::endl;
  double p0 = myfit->GetParameter(0) ;
  double p1 = myfit->GetParameter(1) ;
  double p2 = myfit->GetParameter(2) ;
  FRRootFile->cd();
  histname = ("FRCoeff"+pngfilename);
  TH1F* FRCoeff = new TH1F (histname,"FRCoeff", 10,1,11);
  FRCoeff->SetBinContent(1,p0);
  FRCoeff->SetBinContent(2,p1);
  FRCoeff->SetBinContent(3,p2);
  FRCoeff->Write();
  c->SaveAs(outputdirname+"/PDF/"+pngfilename+".pdf");
  c->SaveAs(outputdirname+"/PNG/"+pngfilename+".png");
  c->SaveAs(outputdirname+"/ROOT/"+pngfilename+".root");
  c->SaveAs(outputdirname+"/MACRO/"+pngfilename+".C");
}


double fitFunction(double x, double p0,double p1,double p2) {
  return (p0 * TMath::Exp (p1 * x) + p2) ;
}



void FILLFRVALUE(TFile* FRRootFile, TString pngfilename, double fakeratevalue ){
  FRRootFile->cd();
  histname = ("FRValue"+pngfilename);
  TH1F* FRValue = new TH1F (histname,"FRValue", 10,1,11);
  FRValue->SetBinContent(1,fakeratevalue);
  FRValue->Write();
}
