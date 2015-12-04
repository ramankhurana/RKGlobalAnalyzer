#include <vector>
#include <string>
#include <iostream>
#include <TH1D.h>
#include <TMath.h>
#include <TFile.h>
#include <TClonesArray.h>
//#include <TLorentzVector.h>                                                                                                                  
#include <TSystemDirectory.h>
void CopyTree_chain() {  
  TChain ch;
  ch = TChain("qcd");
  ch.Add("/hdfs/store/user/khurana/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/151009_133143/0001/NCUGlobalTuples_1.root");
  nEntries = ch.GetEntries()
    cout << nEntries <<std::endl;
  /*
#--- Throw away some branches
    ch.SetBranchStatus("el_*",    0)
    ch.SetBranchStatus("mu_*",    0)

#--- Write to new file
outFile = "qcd.slim.root"
    newFile = TFile(outFile,"RECREATE")
    ch_new = ch.CloneTree(0)

    for i in range(nEntries):
  ch.GetEntry(i)
    #--- Only write out certain events that pass some cut
	    if passCut(ch.RunNumber, ch.lbn):
  ch_new.Fill()
 
# use GetCurrentFile just in case we went over the
			# (customizable) maximum file size
			ch_new.GetCurrentFile().Write()
			ch_new.GetCurrentFile().Close() 

  Int_t  nGenPar;
  std::vector<int> *genStFlag;
  std::vector<int> *genParSt;
  std::vector<int> *genParId;
  int GenCond =-1;
  
  // Example of Root macro to copy a subset of a Tree to a new Tree
  // Only selected entries are copied to the new Tree.
  
  //Get old file, old tree and set top branch address
  TFile *oldfile = new TFile("/hdfs/store/user/khurana/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/151009_133143/0001/NCUGlobalTuples_1.root");
  oldfile->cd();
  TTree *oldtree = (TTree*)oldfile->Get("tree/treeMaker");
  cout<<  oldtree->GetEntries() <<std::endl;  
  
  Long64_t nentries = oldtree->GetEntries();
  cout <<  "neentry:  " <<  nentries <<std::endl;
  
  
  oldtree->SetBranchAddress("genStFlag",&genStFlag);
  oldtree->SetBranchAddress("genParSt",&genParSt);
  oldtree->SetBranchAddress("genParId",&genParId);
  oldtree->SetBranchAddress("nGenPar",&nGenPar);

   
  //Create a new file + a clone of old tree in new file
  TFile *newfile = new TFile("DYToEE.root","recreate");
  newfile->cd();
  newfile->mkdir("tree");
  newfile->cd("tree");
  TTree *newtree = oldtree->CloneTree(0);
    for (Long64_t i=0;i<nentries; i++) {
      oldtree->GetEntry(i);
      if(i > 100) continue;
      GenCond =0;
      cout <<  "event" << i << "   :   " << GenCond <<std::endl;
      cout <<"  ngenpar: "<<  nGenPar <<std::endl;
      cout <<"  ngenpar: "<<  nGenPar <<std::endl;
      for (Int_t ele = 0; ele < nGenPar ; ele++) {
	//if( ((*genParSt)[ele] ==1 ) && (((*genStFlag)[i] >> 9 ) & 1)  &&  abs((*genParId)[ele])==11){ 
	if((((*genStFlag)[i] >> 2 ) & 1)   && (((*genStFlag)[i] >> 9 ) & 1)  &&  abs((*genParId)[ele])==15){
	  GenCond =1 ;      
	}
      } 
      if(GenCond ==1){newtree->Fill();
	cout <<"2nd Time"  << i   <<" GenCond : " << GenCond << " flag : " << (*genStFlag)[i]<<  std::endl;}
    }
    
    newtree->AutoSave();
    newfile->cd("tree");
    newtree->Write();
    delete oldfile;
    delete newfile;*/
    
}
