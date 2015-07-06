void CreateBinByBinUncertainityHistograms(TString rootfilename){
  TFile* f = new TFile(rootfilename , "UPDATE");
  
  TH1F* QCD_bbb = QCD->Clone("QCD_bbb");
  ChangeAllBins(QCD_bbb, "QCD_QCD_bin");

  TH1F* WJets_bbb = WJets->Clone("WJets_bbb");
  ChangeAllBins(WJets_bbb, "WJets_WJets_bin");
  
}


void ChangeOneBin(TH1F* h_in, int ibin, TString name){
  double oldbincontent = h_in->GetBinContent(ibin) ;
  double newbincontent_up   = oldbincontent + sqrt(oldbincontent) ;
  double newbincontent_down = oldbincontent - sqrt(oldbincontent) ;
  
  TString binnumber = Form("%d",ibin);
  TString nameup = name+binnumber+"_Up";
  TString namedown = name+binnumber+"_Down";
  
  TH1F* h_up = h_in->Clone(nameup);
  h_up->SetBinContent(ibin,newbincontent_up);
  h_up->Write();

  TH1F* h_down = h_in->Clone(namedown);
  if(newbincontent_down<0) newbincontent_down = 0.;
  h_down->SetBinContent(ibin,newbincontent_down);
  h_down->Write();
}



void ChangeAllBins(TH1F* h_in, TString name){
  for (int ibin=1; ibin <= h_in->GetNbinsX(); ibin++){
    ChangeOneBin(h_in, ibin, name);
  }
}
