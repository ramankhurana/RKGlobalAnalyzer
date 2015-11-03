void PrintNumbers(){
  TFile* f = new TFile("OutputRootFile/analysis.root","READ");
  //f->cd("syncSig");
  TH1F* sync = (TH1F*) f->Get("syncSig/sync_");
  std::cout<<" all  =  "<<sync->GetBinContent(1)<<std::endl;
  std::cout<<" vtx  =  "<<sync->GetBinContent(2)<<std::endl;
  std::cout<<" jet1 =  "<<sync->GetBinContent(3)<<std::endl;
  std::cout<<" dphi =  "<<sync->GetBinContent(4)<<std::endl;
  std::cout<<" MET  =  "<<sync->GetBinContent(5)<<std::endl;
  std::cout<<" nJet =  "<<sync->GetBinContent(6)<<std::endl;
  std::cout<<" nLep =  "<<sync->GetBinContent(7)<<std::endl;
  std::cout<<" nTau =  "<<sync->GetBinContent(8)<<std::endl;
  std::cout<<" nPho =  "<<sync->GetBinContent(9)<<std::endl;


}
