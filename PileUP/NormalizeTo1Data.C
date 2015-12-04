1;3409;0c{
  TFile *f1 = TFile::Open("dataPUDist.root");
  TH1F *data = (TH1F*) f1->Get("pileup");
  data->Scale(1./data->Integral());
  data->SetNameTitle("pileup","pileup" );
  TFile *f2 = new TFile("DataPU.root", "recreate");
  f2->cd();
  data->Write();
  f2->Close();

  TFile *f3 = TFile::Open("mcPUDist25ns.root");
  TH1F *mc = (TH1F*) f3->Get("mcPUDist");
  mc->SetNameTitle("pileup","pileup" );
  TFile *f4 = new TFile("MCPU.root", "recreate");
  f4->cd();
  mc->Write();
  f4->Close();



  
}
