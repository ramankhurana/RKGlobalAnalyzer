void MakePDFPlot(TString histname, TString legendText1, TString legendText2, TString RootFile, TString plotname){

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetTitleOffset(1.1,"Y");
  gStyle->SetTitleOffset(0.9,"X");
  gStyle->SetLineWidth(3);
  gStyle->SetFrameLineWidth(3);
  
  TCanvas *c12 = new TCanvas("Hist", "Hist", 0,0,500,500);
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.11,1,0.994);
  c1_2->Draw();  
  c12->SetFillColor(0);
  c12->cd();
  c1_2->SetBottomMargin(0.013);
  c1_2->SetLogy(0);
  c1_2->SetLogx(1);
  c1_2->cd();
  
  TLegend *leg = new TLegend(0.55, 0.75, 0.89, 0.89);
  leg->SetBorderSize(0);
  leg->SetLineColor(1);
  leg->SetLineStyle(1);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(0);
  leg->SetTextFont(22);
  leg->SetTextSize(0.05);
  
  
  TFile* f = new TFile(RootFile);
  
  int nbins = 3;
  Float_t  bins[] = {200.,350., 500., 3000.};
  TH1F* h_METFinal = new TH1F("h_METFinal","h_METFinal", nbins, bins);
  
  
  TH1F* met_prof[3];
  for(int ibin=0; ibin<=2; ibin++){
    TString postfix;
    postfix.Form("%d",ibin);
    met_prof[ibin] = new TH1F ("met_prof"+postfix, "met_prof", 1000,0,1000);
  }
  TH1F* h ;

  std::cout<<" created histograms"<<std::endl;
  
  for (int isys=0; isys<101; isys++){
    TString name;
    name.Form("%d",isys);
    name = histname+name;
    std::cout<<" isys = "<<isys
	     <<" name = "<<name<<std::endl;
    h = (TH1F*) f->Get(name);
    h->SetLineColor(5);
    h->SetLineStyle(2);
    float maximum = h->GetMaximum();
    h->SetMaximum(maximum*1.5);
    h->SetMinimum(0.0);
    
    
    for(int ibin=1; ibin<=3; ibin++){
      std::cout<<" ibin = "<<ibin<<std::endl;
      met_prof[ibin-1]->Fill(h->GetBinContent(ibin));
    }
    
    if (isys == 0){ h->Draw("hist");
      h->SetStats(0);
      h->SetTitle(0);
      h->GetYaxis()->SetTitle("Entries");
      h->GetYaxis()->SetTitleSize(0.052);
      h->GetYaxis()->SetTitleOffset(0.95);
      h->GetYaxis()->SetTitleFont(22);
      h->GetYaxis()->SetLabelFont(22);
      h->GetYaxis()->SetLabelSize(.05);
      h->GetXaxis()->SetRangeUser(0,3000);
      h->GetXaxis()->SetLabelSize(0.0000);
      h->GetXaxis()->SetTitle("E_{T}^{Miss}[GeV]");
      h->GetXaxis()->SetLabelSize(0.05);
      h->GetXaxis()->SetTitleSize(0.05);
      h->GetXaxis()->SetTitleOffset(0.95);
      h->GetXaxis()->SetTitleFont(22);
      h->GetXaxis()->SetTickLength(0.04);
      h->GetXaxis()->SetLabelFont(22);
      h->GetYaxis()->SetLabelFont(22);
      h->GetXaxis()->SetNdivisions(508);
      h->GetXaxis()->SetMoreLogLabels(); 
      h->GetXaxis()->SetNoExponent();
      h->GetXaxis()->SetNdivisions(508);
      leg->AddEntry(h,"PDF","L");
    }

    if (isys >  0) h->Draw("histsame");
  }

  std::cout<<" 101 histo drawn"<<std::endl;
  
  for(int ibin=1; ibin<=3; ibin++){
    std::cout<<" mean = "<<met_prof[ibin-1]->GetMean()<<std::endl;
    std::cout<<" rms = "<<met_prof[ibin-1]->GetRMS()<<std::endl;
    h_METFinal->SetBinContent(ibin, met_prof[ibin-1]->GetMean());
    h_METFinal->SetBinError(ibin, met_prof[ibin-1]->GetRMS());
  }
  
  
  h_METFinal->SetLineWidth(2);
  h_METFinal->SetLineColor(4);
  //h_METFinal->SetMarkerStyle(20);
  h_METFinal->Draw("hist same");
  
  TString newname = histname.ReplaceAll("_PDF","");
  h_nominal = (TH1F*) f->Get(newname);
  //h_nominal->SetLineColor(1);
  h_nominal->SetMarkerStyle(20);
  h_nominal->Draw("P E1 same");
  leg->AddEntry(h_nominal,"Nominal","P");
  
  leg->AddEntry(h_METFinal,"PDF Profile","L");
  leg->Draw();  


  TPaveText  *pt = new TPaveText(0.0877181,0.9,0.9580537,0.96,"brNDC");
  pt->SetBorderSize(0);
  pt->SetTextAlign(12);
  pt->SetFillStyle(0);
  pt->SetTextFont(22);
  pt->SetTextSize(0.046);
  text = pt->AddText(0.01,0.5,"CMS Simulation");
  text = pt->AddText(0.41,0.5,"(#sqrt{s} = 13 TeV #scale[0.45]{#int}L=2.3 fb^{-1})");
  pt->Draw();
  
  
  
  TPaveText *t2a = new TPaveText(0.0877181,0.81,0.9580537,0.89,"brNDC");
  t2a->SetBorderSize(0);
  t2a->SetFillStyle(0);
  t2a->SetTextSize(0.040); 
  t2a->SetTextAlign(12);
  t2a->SetTextFont(62);
  text1 = t2a->AddText(0.06,0.5,legendText2); 
  t2a->Draw();
  
  TPaveText *t2b = new TPaveText(0.5077181,0.60,0.9580537,0.67,"brNDC");
  t2b->SetBorderSize(0);
  t2b->SetFillStyle(0);
  t2b->SetTextSize(0.046); 
  t2b->SetTextAlign(12);
  t2b->SetTextFont(62);
  t2b->SetTextColor(2);
  text1 = t2b->AddText(0.40,0.5,legendText1); 
  t2b->Draw(); 
  

  
  plotname = "Uncertainty/"+plotname+".pdf";
  c12->SaveAs(plotname);
  plotname.ReplaceAll(".pdf",".png");
  c12->SaveAs(plotname);


  gSystem->Exec( " cp "+plotname+" /afs/hep.wisc.edu/home/khurana/public_html/Uncertainty/");
}



void PDFSyst(){
  MakePDFPlot("DYJets_PDF","Zj", "SR (Boosted) " ,"MonoHFatJetSelection_JetAndLeptonVeto.root", "PDF_Syst_SR_Zj");
  MakePDFPlot("WJets_PDF" ,"Wj", "SR (Boosted) " ,"MonoHFatJetSelection_JetAndLeptonVeto.root", "PDF_Syst_SR_Wj");
  MakePDFPlot("TT_PDF" ,"Top", "SR (Boosted) " ,"MonoHFatJetSelection_JetAndLeptonVeto.root", "PDF_Syst_SR_TT");

  MakePDFPlot("DYJets_PDF","Zj", "Mass sideband (Boosted) " ,"histfacFatJet_ZLight.root", "PDF_Syst_SB_Zj");
  MakePDFPlot("WJets_PDF" ,"Wj", "Mass sideband (Boosted) " ,"histfacFatJet_ZLight.root", "PDF_Syst_SB_Wj");
  MakePDFPlot("TT_PDF" ,"Top", "Mass sideband (Boosted) " ,"histfacFatJet_ZLight.root", "PDF_Syst_SB_TT");

  MakePDFPlot("DYJets_PDF","Zj", "1-lepton CR (Boosted) " ,"histfacFatJet_WHeavy.root", "PDF_Syst_WHF_Zj");
  MakePDFPlot("WJets_PDF" ,"Wj", "1-lepton CR (Boosted) " ,"histfacFatJet_WHeavy.root", "PDF_Syst_WHF_Wj");
  MakePDFPlot("TT_PDF" ,"Top", "1-lepton CR (Boosted) " ,"histfacFatJet_WHeavy.root", "PDF_Syst_WHF_TT");

  

  }
