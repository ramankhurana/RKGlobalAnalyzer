{
cout << "a "<<std::endl;

std::vector<TString> filenameString;
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/DYJetsToLL/");
                                                            
cout << "b "<<std::endl;
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-10to50.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_new_M-50to200.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-200to400.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-400to500.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-500to700.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-700to800.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-800to1000.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-1000to1500.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-1500to2000.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-2000to3000.root");

cout << "c "<<std::endl;
const int nfiles = (int) filenameString.size();                                                                                          
//cout << nfiles <<std::endl;
//nfiles = 9;
//cout << nfiles <<std::endl;

 int numberfiles=10;
 float Xsec[10];
 Xsec[0] = 6203.3;
 Xsec[1] = 2031.9;
 Xsec[2] = 2.56;
 Xsec[3] = 0.141;
 Xsec[4] = 0.08;
 Xsec[5] = 0.012;
 Xsec[6] = 0.01;
 Xsec[7] = 0.0053;
 Xsec[8] = 0.00067;
 Xsec[9] = 0.00018;

cout << "d "<<std::endl;

//histoname
TString histnameString("h_ZMass_Acc_Reco");
TFile *fIn;

TH1F* h_num[10];
TH1F* h_den[10];
TH1F* h_lum;

  TH1F* h_num_error[10];
  TH1F* h_den_error[10];

for(int i =0; i< nfiles  ; i++){
fIn = new TFile(filenameString[i],"READ");

h_num[i] = (TH1F*) fIn->Get(histnameString);
h_lum = (TH1F*) fIn->Get("h_ZMass");
h_den[i] = (TH1F*) fIn->Get("h_ZMass");
if(i==1 && true){
h_den[i] = (TH1F*) fIn->Get("h_total");
}

    Float_t bins[] ={15,20,25,30,35,40,45,50,55,60,64,68,72,76,81,86,91,96,101,106,110,115,120,126,133,141,150,160,171,185,200,220,243,273,320,380,440,510,600,700,830,1000,1200,1500 ,2000,3000};
    Int_t  binnum = sizeof(bins)/sizeof(Float_t) - 1;
    TString postfix;
    postfix = Form("%d",i);
    h_num_error[i] = new TH1F("h_num_error"+postfix,"",binnum,bins) ;
    h_den_error[i] = new TH1F("h_den_error"+postfix,"",binnum,bins) ;
    
    //Raman
    // Taking default histogram
    for(int ibin=0; ibin<h_num[i]->GetNbinsX();ibin++){
      float num_err = TMath::Sqrt(h_num[i]->GetBinContent(ibin));
      
      if(i==0) std::cout<<" ibin = "<<ibin
			<<" content = "<<h_num[i]->GetBinContent(ibin)
			<<" num_err = "<<num_err
			<<std::endl;
      h_num_error[i]->SetBinContent(ibin,num_err);
      h_den_error[i]->SetBinContent(ibin,TMath::Sqrt(h_den[i]->GetBinContent(ibin)));
    }
    // Raman ---
    float scale_ = Xsec[i]/h_lum->Integral();
    h_num[i]->Scale(scale_);
    h_den[i]->Scale(scale_);
    
    // Raman
    h_num_error[i]->Scale(scale_);
    h_den_error[i]->Scale(scale_);
    // Raman ---
    for(int ibin=0; ibin<h_num[i]->GetNbinsX();ibin++){
      if(i==0) std::cout<<"after scaling "<<scale_
			<<" ibin = "<<ibin
			<<" content = "<<h_num[i]->GetBinContent(ibin)
			<<" num_err = "<<h_num_error[i]->GetBinContent(ibin)
			<<std::endl;
    }
    //h_num[i]->Sumw2();
    //h_den[i]->Sumw2();
    std::cout<<" error indi = "<<h_num_error[i]->GetBinContent(42)<<std::endl;
    std::cout << filenameString[i] << "   " << " h_ZMass_Acc_Reco "  <<   " Integral : " << h_num[i]->Integral() << "   " << h_den[i]->Integral() << std::endl;
 }

THStack *hs_num = new THStack("hs_num"," ");
THStack *hs_den = new THStack("hs_den"," ");

   //Raman
  THStack *hs_num_err = new THStack("hs_num_err"," ");
  THStack *hs_den_err = new THStack("hs_den_err"," ");
  //Raman ---
for(int j =0; j <nfiles; j++){
hs_num->Add(h_num[j]);
hs_den->Add(h_den[j]);


    //Raman
    hs_num_err->Add(h_num_error[j]);
    hs_den_err->Add(h_den_error[j]);
    // Raman --

}

TH1F *Stackhist_num = (TH1F*)hs_num->GetStack()->Last();
TH1F *Stackhist_den = (TH1F*)hs_den->GetStack()->Last();

  //Raman
  TH1F* Stackhist_num_error = (TH1F*) hs_num_err->GetStack()->Last();
  TH1F* Stackhist_den_error = (TH1F*) hs_den_err->GetStack()->Last();
  //Raman --

//Stackhist_num->Sumw2();
//Stackhist_den->Sumw2();
TH1F *histo = (TH1F*) Stackhist_num->Clone();
histo->Divide(Stackhist_den);


  for(int ibin=0;ibin<=Stackhist_num_error->GetNbinsX();ibin++){
    float  a = Stackhist_num->GetBinContent(ibin);
    float  b = Stackhist_den->GetBinContent(ibin);
    float da = Stackhist_num_error->GetBinContent(ibin);
    float db = Stackhist_den_error->GetBinContent(ibin);
    
    float r = histo->GetBinContent(ibin);
    float first = (da*da) / (a*a) ;
    float second = (db*db) / (b*b) ;
    
    float dr = r * TMath::Sqrt(first + second );
    std::cout<<" ibin = "<<ibin<<" da =  "<<da<<" db =  "<<db
	     <<" a = "<<a
	     <<" b = "<<b
	     <<" r = "<<r
	     <<" dr "<<dr <<std::endl;
    histo->SetBinError(ibin,dr);
    
  }

histo->Draw("P");
histo->SetName("h_ZMass_Acc_Reco_h_ZMass");

//TGraphAsymmErrors* gr = new TGraphAsymmErrors(Stackhist_num, Stackhist_den);
//gr->Draw("AP");
//gr->SetName("h_ZMass_Acc_Reco_h_ZMass");

TString FilePreName("AccEff_All");
TFile *fout= new TFile("AccEff_All4.root","RECREATE");

//TFile *fout= new TFile(FilePreName+".root","RECREATE");
fout->cd();
histo->Write();
fout->Write();
fout->Close();



}
