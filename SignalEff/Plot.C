{
std::vector<TString> filenameString;
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/MonoHFatJetAnalysis_ForExoWorkShopV6/");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root");

//histoname
TString histnameString("MonoHFatJetSelection_JetAndLeptonVeto/h_Mjj0");


TFile *fIn;
int nfiles_ = (int) filenameString.size();

const int nfiles = nfiles_;
float yarray_[nfiles];
float x[]={600, 800, 1000,1200,1400,1700,2000,2500};


TH1F* h_mc ;
TH1F* h_total;
float normalization[nfiles];

for(int i =0; i<(int)filenameString.size(); i++){
 fIn = new TFile(filenameString[i],"READ");
 h_mc = (TH1F*) fIn->Get(histnameString);
 h_total = (TH1F*) fIn->Get("nEvents_weight");
 yarray_[i]= (h_mc->Integral())/(h_total->Integral()); 
 cout << "x: " << x[i]  << "y : " << yarray_[i]  << std::endl;
 
}


TGraphAsymmErrors *gr;
gr = new TGraphAsymmErrors(nfiles, x,yarray_ );
gr->Draw("APL");
gr->SetName("MonoHFatJetSelection_JetAndLeptonVeto");

TString FilePreName("SignalEff_Graph_20151108");
TFile *fout= new TFile(FilePreName+".root","UPDATE");
fout->cd();
gr->Write();
fout->Write();
fout->Close();



}
