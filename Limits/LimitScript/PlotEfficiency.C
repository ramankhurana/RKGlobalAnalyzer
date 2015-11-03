void PlotEfficiency(){
  TCanvas *c12 = new TCanvas("Vertex Multiplicity ", "vertex Multiplicity"  , 0,0,1000,510);
  c12->SetBottomMargin(0.15);
  TFile* f1 = new TFile("Merged_DMHistosSpring15_1/main-NCUGlobalTuples_M1500.root","READ");
  f1->cd();
  TH1F* num1 = (TH1F*) f1->Get("JetPreSel/h_pTjj0");
  num1->Rebin(6);
  TH1F* den1 = (TH1F*) f1->Get("NoCut/h_pTjj0");
  den1->Rebin(6);
  TGraphAsymmErrors* gr1;
  gr1 = new TGraphAsymmErrors(num1,den1);
  gr1->Draw("AP");
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerColor(1);
  gr1->SetLineColor(1);

  
  TFile* f2 = new TFile("Merged_DMHistosSpring15_1/main-NCUGlobalTuples_M900.root","READ");
  f2->cd();
  TH1F* num2 = (TH1F*) f2->Get("JetPreSel/h_pTjj0");
  num2->Rebin(6);
  TH1F* den2 = (TH1F*) f2->Get("NoCut/h_pTjj0");
  den2->Rebin(6);
  TGraphAsymmErrors* gr2;
  gr2 = new TGraphAsymmErrors(num2,den2);
  gr2->Draw("P,same");
  gr2->SetMarkerStyle(21);
  gr2->SetMarkerColor(2);
  gr2->SetLineColor(2);


  TFile* f3 = new TFile("Merged_DMHistosSpring15_1/Merged_TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-main.root","READ");
  f3->cd();
  TH1F* num3 = (TH1F*) f3->Get("JetPreSel/h_pTjj0");
  num3->Rebin(6);
  TH1F* den3 = (TH1F*) f3->Get("NoCut/h_pTjj0");
  den3->Rebin(6);
  TGraphAsymmErrors* gr3;
  gr3 = new TGraphAsymmErrors(num3,den3);
  gr3->Draw("P,same");
  gr3->SetMarkerStyle(22);
  gr3->SetMarkerColor(4);
  gr3->SetLineColor(4);

  
  TFile* f4 = new TFile("Merged_DMHistosSpring15_1/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-main.root","READ");
  f4->cd();
  TH1F* num4 = (TH1F*) f4->Get("JetPreSel/h_pTjj0");
  num4->Rebin(6);
  TH1F* den4 = (TH1F*) f4->Get("NoCut/h_pTjj0");
  den4->Rebin(6);
  TGraphAsymmErrors* gr4;
  gr4 = new TGraphAsymmErrors(num4,den4);
  gr4->Draw("P,same");
  gr4->SetMarkerStyle(23);
  gr4->SetMarkerColor(3);
  gr4->SetLineColor(3);

  

  TFile* f5 = new TFile("Merged_DMHistosSpring15_1/Merged_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-main.root","READ");
  f5->cd();
  TH1F* num5 = (TH1F*) f5->Get("JetPreSel/h_pTjj0");
  num5->Rebin(6);
  TH1F* den5 = (TH1F*) f5->Get("NoCut/h_pTjj0");
  den5->Rebin(6);
  TGraphAsymmErrors* gr5;
  gr5 = new TGraphAsymmErrors(num5,den5);
  gr5->Draw("P,same");
  gr5->SetMarkerStyle(24);
  gr5->SetMarkerColor(5);
  gr5->SetLineColor(5);




  TFile* f6 = new TFile("Merged_DMHistosSpring15_1/Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-main.root","READ");
  f6->cd();
  TH1F* num6 = (TH1F*) f6->Get("JetPreSel/h_pTjj0");
  num6->Rebin(6);
  TH1F* den6 = (TH1F*) f6->Get("NoCut/h_pTjj0");
  den6->Rebin(6);
  TGraphAsymmErrors* gr6;
  gr6 = new TGraphAsymmErrors(num6,den6);
  gr6->Draw("P,same");
  gr6->SetMarkerStyle(25);
  gr6->SetMarkerColor(7);
  gr6->SetLineColor(7);
  
  gr1->GetXaxis()->SetTitleSize(0.05);
  gr1->GetXaxis()->SetTitleOffset(1.03);
  gr1->GetXaxis()->SetTitleFont(22);
  gr1->GetXaxis()->SetLabelFont(22);
  gr1->GetXaxis()->SetLabelSize(.05);
  gr1->GetYaxis()->SetTitle("Efficiency");
  gr1->GetYaxis()->SetTitleSize(0.05);
  gr1->GetYaxis()->SetTitleOffset(0.75);
  gr1->GetYaxis()->SetTitleFont(22);
  gr1->GetYaxis()->SetLabelFont(22);
  gr1->GetYaxis()->SetLabelSize(.05);
  gr1->GetXaxis()->SetTitle("p_{T}^{bb}");



TLegend* legend = new TLegend(0.13, 0.7, 0.4,0.89,NULL,"brNDC");
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(22);
 legend->SetTextSize(0.05);
 legend->SetNColumns(2);
 legend->AddEntry(gr1,"M1500","lP");
 legend->AddEntry(gr2,"M900","lP");
 legend->AddEntry(gr3,"TTJets","lP");
 legend->AddEntry(gr4,"DYJets", "lP");
 legend->AddEntry(gr5,"WJets", "lP");
 legend->AddEntry(gr6,"ZH", "lP");
 legend->Draw();
  
  
  c12->SaveAs("effi.png");
}
