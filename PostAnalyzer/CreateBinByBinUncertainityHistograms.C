void CreateBinByBinUncertainityHistograms(TString rootfilename="histfacFatJet_ZLight.root"){

  
  TFile* f = new TFile(rootfilename , "UPDATE");
  std::vector<TString> HistVector;
  HistVector.clear();
  
  HistVector.push_back("TT");
  HistVector.push_back("ZH");
  HistVector.push_back("DIBOSON");
  HistVector.push_back("DYJets");
  HistVector.push_back("WJets");
  
  HistVector.push_back("monoHbbM600_300");
  HistVector.push_back("monoHbbM800_300");
  HistVector.push_back("monoHbbM1000_300");
  HistVector.push_back("monoHbbM1400_300");
  HistVector.push_back("monoHbbM1700_300");
  HistVector.push_back("monoHbbM2000_300");
  HistVector.push_back("monoHbbM2500_300");
    
  for (int ihist =0; ihist< int(HistVector.size()); ihist++){
    TString name = HistVector[ihist];// + "_bbb";
    TH1F* process_ = (TH1F*) f->Get(HistVector[ihist]);
    TH1F* TT_bbb = process_->Clone(name);
    ChangeAllBins(TT_bbb, name);
  }
  
    
}


void ChangeOneBin(TH1F* h_in, int ibin, TString name){
  double binerror = h_in->GetBinError(ibin) ;
  double oldbincontent = h_in->GetBinContent(ibin);
  double newbincontent_up   = oldbincontent + binerror ;
  double newbincontent_down = oldbincontent - binerror ;
  
  TString binnumber = Form("%d",ibin);
  TString nameup = name+"_"+name+"_stat_bin"+binnumber+"Up";
  TString namedown = name+"_"+name+"_stat_bin"+binnumber+"Down";
  
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
