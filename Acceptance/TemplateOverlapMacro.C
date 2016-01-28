{
cout << "a "<<std::endl;

std::vector<TString> filenameString;
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/Acceptance/DYJetsToLL_AccEff_SETrigger_RecoBugR/");
                                                            
cout << "b "<<std::endl;
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-10to50.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-50to200.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-200to400.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-400to500.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-500to700.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-700to800.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-800to1000.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-1000to1500.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-1500to2000.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_Check_M-2000to3000.root");
//
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
TString histnameString("HISTNAME");
TFile *fIn;

TH1F* h_num[10];
TH1F* h_den[10];
TH1F* h_lum;

ofstream mout;                                                                                                                                
mout.open("AcceptancebinContent_SETrigger.txt",std::ios::app);
std::mout << "Num     " <<"den     "<<"errN     "<<"errD     " <<" ND     " << "END     "<<std::endl;
std::mout << histnameString << "HISTDEN" <<std::endl;
for(int i =0; i< nfiles  ; i++){
fIn = new TFile(filenameString[i],"READ");

h_num[i] = (TH1F*) fIn->Get(histnameString);
h_lum = (TH1F*) fIn->Get("h_ZMass");
h_den[i] = (TH1F*) fIn->Get("HISTDEN");
h_num[i]->Sumw2();
h_den[i]->Sumw2();



float scale_ = (Xsec[i]*1000.*1.)/h_lum->Integral() ;


std::cout << filenameString[i] << "   " << " HISTNAME "  <<   " Integral : " << h_num[i]->Integral() << "   " << h_den[i]->Integral() << "  "<< std::endl;
h_num[i]->Scale(scale_);
h_den[i]->Scale(scale_);
}

THStack *hs_num = new THStack("hs_num"," ");
THStack *hs_den = new THStack("hs_den"," ");

for(int j =0; j <nfiles; j++){
hs_num->Add(h_num[j]);
hs_den->Add(h_den[j]);
}

TH1F *Stackhist_num = (TH1F*)hs_num->GetStack()->Last();
TH1F *Stackhist_den = (TH1F*)hs_den->GetStack()->Last();
Stackhist_num->Sumw2();
Stackhist_den->Sumw2();


TH1F *histo = (TH1F*) Stackhist_num->Clone();
histo->Divide(Stackhist_den);
histo->Draw("PE");
histo->SetName("HISTNAME_HISTDEN");

/*  for(int ibin=1;ibin <=Stackhist_num->GetNbinsX();ibin++){
    float  a = Stackhist_num->GetBinContent(ibin);
    float  b = Stackhist_den->GetBinContent(ibin);
    float da = Stackhist_num->GetBinError(ibin);
    float db = Stackhist_den->GetBinError(ibin);
    
    float erra = (da*da)/(a*a);
    float errb = (db*db)/(b*b);
    float errc = a/b;
    float totalerr = erra+errb;
    float err = errc*(TMath::Sqrt(totalerr));
    cout << ibin << "  "<< errc  <<std::endl;
//    cout << " num: " << a << "den: " << b << " num err :" << da <<  "den err : " << db <<std::endl;
    std::mout << a << "  " <<b << "  " << da <<"  "<< db <<"  "  << a/b << "  "<< err <<  "   " <<histo->GetBinContent(ibin)<< " " << histo->GetBinError(ibin)<< " " <<std::endl;
  }



for(int ibin=1 ; ibin<=histo->GetNbinsX();ibin++){
    float  tvalue = histo->GetBinContent(ibin);
    float  terr =  histo->GetBinError(ibin);
    std::mout << "in histo :"  << tvalue << "  " <<terr << "  " <<std::endl;
  }
*/

//TGraphAsymmErrors* gr = new TGraphAsymmErrors(Stackhist_num, Stackhist_den,"");
//gr->SetMarkerColor(4);
//gr->SetMarkerStyle(21);
//gr->Draw("AP");
//gr->SetName("HISTNAME_HISTDEN");

TString FilePreName("AccEff_All");
TFile *fout= new TFile("AccEff_SETrigger_new_reco_BugR.root","FILEMODE");

//TFile *fout= new TFile(FilePreName+".root","RECREATE");
fout->cd();
//gr->Write();
histo->Write();
fout->Write();
fout->Close();



}
