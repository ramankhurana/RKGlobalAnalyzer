void CopyTree(){  


  gSystem->Load("$ROOTSYS/test/libEvent");  
  Int_t  nGenPar;
  std::vector<int> *genStFlag;
  std::vector<int> *genParSt;
  std::vector<int> *genParId;
  int GenCond =-1;
  
  TFile *oldfile = new TFile("/hdfs/store/user/khurana/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/crab_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8TreeMaker_MC50ns_1009/151009_133143/0001/NCUGlobalTuples_1.root");
  oldfile->cd();
  TTree *oldtree = (TTree*)oldfile->Get("tree/treeMaker");
  Long64_t nentries = oldtree->GetEntries();

  oldtree->SetBranchAddress("genStFlag",&genStFlag);
  oldtree->SetBranchAddress("genParSt",&genParSt);
  oldtree->SetBranchAddress("genParId",&genParId);
  oldtree->SetBranchAddress("nGenPar",&nGenPar);
  
   
  // Create a new file + a clone of old tree in new file
  TFile *newfile = new TFile("DYToEE.root","recreate");
  newfile->mkdir("tree");
  newfile->cd();
  TTree *newtree = oldtree->CloneTree(0);
  newtree->SetDirectory(0);
  


  for (Long64_t i=0; i<nentries; i++) {
    oldtree->GetEntry(i);
    if(i > 100) continue;
    GenCond =0;
    cout <<  "event" << i << "   :   " << GenCond <<std::endl;
    cout <<"  ngenpar: "<<  nGenPar <<std::endl;
    for (Int_t ele = 0; ele < nGenPar ; ele++) {
      //if( ((*genParSt)[ele] ==1 ) && (((*genStFlag)[ele] >> 9 ) & 1)  &&  abs((*genParId)[ele])==11){ 
      if((((*genStFlag)[ele] >> 2 ) & 1)   && (((*genStFlag)[ele] >> 9 ) & 1)  &&  abs((*genParId)[ele])==15){
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
    delete newfile;

  
}
