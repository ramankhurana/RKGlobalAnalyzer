void PlotEfficiency(){
  TCanvas *c12 = new TCanvas("Vertex Multiplicity ", "vertex Multiplicity"  , 0,0,500,500);
  TFile* f1 = new TFile("Merged_DMHistosSpring15_1/main-NCUGlobalTuples_M900.root","READ");
  f1->cd();
  TH1F* num1 = (TH1F*) f1->Get("JetPreSel/h_pTjj0");
  TH1F* den1 = (TH1F*) f1->Get("NoCut/h_pTjj0");
  
  TGraphAsymmErrors* gr1;
  gr1 = new TGraphAsymmErrors(num1,den1);
  gr1->Draw("AP");
  c12->SaveAs("effi.png");
}
