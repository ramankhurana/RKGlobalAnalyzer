//created by Monika mitta Khuaran
//It will a root file containing the nvtx or npileup histrogram 
// Please give input file name and output directory name 
#include <vector>
#include <string>
#include <iostream>
#include <TH1D.h>
#include <TMath.h>
#include <TFile.h>
#include <TClonesArray.h>
#include "/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/PileUP/PileUpWeights.h"
//x#include <TLorentzVector.h>
#include <TSystemDirectory.h>
void PileUpCode_withreweight(){
  Int_t  nVtx;
  TH1F * pileup   = new TH1F( "pileup", "pileup", 60, 0., 60.);
  
  TString PreoutFile("PileupReweighted_"); 
   TString PostoutFile("DYJetsToLL_M-50.root");
  //TString PostoutFile("METRun2015B_Prompt.root");
  TString outputfilename = PreoutFile+PostoutFile;
  TFile efile(outputfilename,"recreate");
  TString InputDirectory("/hdfs/store/user/khurana/");
  TString InputFileName("DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/");
  //TString InputFileName("MET/crab_MET-Run2015C-PromptReco-v120150920/");
  //TString InputFileName("MET/crab_MET-Run2015B-PromptReco-v120150920/");
  //TString InputFileName("MET/crab_MET-Run2015B-17Jul2015-v120150920/");   
  TString FullFileNme = InputDirectory+InputFileName;
  
  gSystem->Exec("find "+FullFileNme+" -name \\*.root >& inputroottextfile.txt");

  std::ifstream inputFile("inputroottextfile.txt");
  
  std::vector<TString> infiles;
  std::string str;
  while (std::getline(inputFile, str))
    {
      infiles.push_back(str);
        
    }

    const int numfiles = infiles.size();
    //    cout << numfiles << infiles[0]<<std::endl;
    TFile *fileList[numfiles];
    
    for (int i=0; i < numfiles; i++){
      //       if (!(i%10 == 0)) continue;      
      fileList[i] = new TFile(infiles[i],"READ"); 
      
      TTree *tree= (TTree*)fileList[i]->Get("tree/treeMaker");
       
      tree->SetBranchAddress("nVtx",&nVtx);
      int entry = tree->GetEntries();
      std::cout  << infiles[i] << "entries in tree: "<< entry <<std::endl; 
      for (Int_t im = 0; im < entry ; im++) {
	tree->GetEntry(im);
	pileup->Fill(nVtx,PileUpWeights::PUWEIGHT(nVtx));
      }
  


      //      fileList[i]->cd();
      //tree->cd();
      //std::cout<<treeMaker->GetEntries()<<std::endl;    

    }  
    efile.cd();
    pileup->Write();
}
