void SkimTree(){
  TFile* inputfile = new TFile("RelValQCDFlatPt_15_3000HS_13.root","READ");
  inputfile->cd();
  tree->cd();
  TTree* newtree = tree->CopyTree("pfpatgenMetPt_>30","",1000000000,0);
  TFile* outputfile = new TFile("skimmedMET.root","RECREATE");
  outputfile->cd();
  newtree->Write();
  outputfile->Write();
    
}
