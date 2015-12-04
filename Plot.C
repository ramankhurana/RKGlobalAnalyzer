{
#include <ctime>
#include <cstdlib>
 
 time_t now = time(0);
 tm *ltm = localtime(&now);
 TString dirpathname;

 TString DirPreName = "PlotsElectron_25ns_";
 dirpathname.Form("%d%1.2d%d",ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
 system("mkdir -p  " + DirPreName+dirpathname +"/DYROOT");
 system("mkdir -p  " + DirPreName+dirpathname +"/DYPdf");
 system("mkdir -p  " + DirPreName+dirpathname +"/DYPng");
 
 ofstream mout;
 mout.open(DirPreName+dirpathname +"/"+dirpathname +".txt",std::ios::app);


gROOT->ProcessLine(".L /afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/tdrstyle.C");
setTDRStyle();
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);
gStyle->SetFrameLineWidth(3);
gStyle->SetErrorX(0);
gStyle->SetLineWidth(1);

//Provide luminosity of total data

//float lumi = 45.034; // B data set
//float lumi = 26.48; // C data set 
//float lumi = 71.51 ; // total 50 ns 
float lumi = 2.09;

std::vector<TString> filenameString;
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/Electron_25ns_29112015/");

//Signal 0
filenameString.push_back(filenamepath + "Merged_DYJetsToEE_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");

//WJets  1
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");

// Diboson WW WZ ZZ 2 3 4
filenameString.push_back(filenamepath + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");

// TTJets 5
filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");

//QCD jets 6 
filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_QCD_Pt-15TTo7000_TuneZ2star-Flat_13TeV_pythia6-runallAnalysis.root");

//DYJets Low 7
filenameString.push_back(filenamepath + "Merged_DYJetsToEE_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");

//DYTau tau contribution
filenameString.push_back(filenamepath + "Merged_DYJetsToTauTau_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_DYJetsToTauTau_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
//Data File
//25ns data
filenameString.push_back(filenamepath + "Data_25ns.root");

//histoname
TString histnameString("Electron_NoCut_Endcap/h_passConversionVeto4");

TFile *fIn;
const int nfiles = (int) filenameString.size();

//check it once
float Xsec[nfiles];
Xsec[0] = 2008.;//6025;
Xsec[1] = 61526;
Xsec[2] = 118.7; 
Xsec[3] = 44.9;
Xsec[4] = 15.4;
Xsec[5] = 831.76;
Xsec[6] = 89731000000;
Xsec[7] = 6203;// 18610; 
Xsec[8] = 2008; 
Xsec[9] = 6203;

TH1F* h_mc[nfiles] ;
TH1F* h_rebin[nfiles];
float normalization[nfiles];
TH1F *h_data;
TH1F *h_data_rebin;

//Varibale reebinning of mass
double massbin[46] ={15,20,25,30,35,40,45,50,55,60,64,68,72,76,81,86,91,96,101,106,110,115,120,126,133,141,150,160,171,185,200,220,243,273,320,380,440,510,600,700,830,1000,1200,1500,2000,3000};


// Main Code starts here

for(int i =0; i<(int)filenameString.size()-1; i++){
 fIn = new TFile(filenameString[i],"READ");
 h_total              = (TH1F*) fIn->Get("nEvents_weight");                                                                                  
 normalization[i]     = (lumi* Xsec[i]*1000)/(h_total->Integral());

if(0){
 h_rebin[i] = (TH1F*) fIn->Get(histnameString);
 h_rebin[i]->Scale(normalization[i]);
 h_rebin[i]->Rebin(45,"hnew",massbin);
 h_mc[i]= (TH1F*)hnew->Clone();
}
if(!0){
 h_mc[i]              = (TH1F*) fIn->Get(histnameString);
 h_mc[i]->Scale(normalization[i]);
 h_mc[i]->Rebin(1);
}

  cout << filenameString[i] <<  "  &  "  <<  Xsec[i] <<"  &  " << h_total->GetEntries() <<  " & "   << h_total->Integral()  "\\" <<std::endl; 
  cout<<"normalization :" << normalization[i] << std::endl;
 }

fIn = new TFile(filenameString[nfiles-1],"READ");
if(0){
h_data_rebin = (TH1F*) fIn->Get(histnameString);
h_data_rebin->Rebin(45,"hnewdata",massbin);                                                                                               
h_data= (TH1F*)hnewdata->Clone();}
if(!0){
h_data = (TH1F*) fIn->Get(histnameString);
h_data->Rebin(1);}
h_data->Sumw2();

 //Legend
 TLegend *legend;
 
 if(0){
 legend = new TLegend(0.73, 0.68, 0.95,0.92,NULL,"brNDC");
 legend->SetTextSize(0.05);
 }else{

// legend = new TLegend(0.5, 0.7, 0.9,0.88,NULL,"brNDC"); 
//legend = new TLegend(0.13, 0.85, 0.95,0.92,NULL,"brNDC");
 legend = new TLegend(0.7, 0.62, 0.95,0.92,NULL,"brNDC");
 legend->SetTextSize(0.06); }
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetNColumns(1);
 legend->AddEntry(h_data,"Data","p");                                                                                                          
 legend->AddEntry(h_mc[0],"DY#rightarrow ee","f");
legend->AddEntry(h_mc[5],"t#bar{t}","f");
legend->AddEntry(h_mc[8],"DY#rightarrow #tau#tau","f"); 
legend->AddEntry(h_mc[2],"Diboson","f");                                                                                                     
 
 legend->AddEntry(h_mc[1],"WJets","f");
//legend->AddEntry(h_mc[6],"QCD","f");
 
//===========================Latex=================//

TString latexCMSname= "CMS";
TString latexPreCMSname= "Preliminary";
 
TString latexnamemiddle;
latexnamemiddle.Form("%1.2f",lumi); 
TString latexnamepost = " fb^{-1} (13 TeV)";
//TString latexname = latexnamepre+latexnamemiddle+latexnamepost;  
TString latexname = latexnamemiddle+latexnamepost;

TLatex *t2b;
TLatex *t2c;

if(0){
 t2a = new TLatex(0.7,0.97,latexname);
 t2a->SetTextSize(0.04);
 t2b = new TLatex(0.190,0.92,latexCMSname);
 t2b->SetTextSize(0.05);

 t2c = new TLatex(0.22,0.87,latexPreCMSname);
 t2c->SetTextSize(0.047);

 }else{
 t2a = new TLatex(0.8,0.975,latexname);
 t2a->SetTextSize(0.047); 

 t2b = new TLatex(0.190,0.92,latexCMSname);
 t2b->SetTextSize(0.05);

 t2c = new TLatex(0.22,0.87,latexPreCMSname);
 t2c->SetTextSize(0.047);


 }
 t2a->SetTextAlign(22);
 t2a->SetNDC(kTRUE);
 t2a->SetTextFont(42);

 t2b->SetTextAlign(22);
 t2b->SetNDC(kTRUE);
 t2b->SetTextFont(61);


 t2c->SetTextAlign(22);
 t2c->SetNDC(kTRUE);
 t2c->SetTextFont(52);

//============== CANVAS DECLARATION ===================
TCanvas *c12 = new TCanvas("Hist", "Hist", 0,0,500,500);
 
//==================Stack==========================                                                                  
THStack *hs = new THStack("hs"," ");

// For N-1 Plots only
bool nminus = 0;
TLatex *tt;
if(("Electron_NoCut_Endcap" == "ElectronNMinus1E") || ("Electron_NoCut_Endcap" == "ElectronNMinus1B") ){
nminus =1;
tt  = new TLatex(0.5,0.87,"N-1");
tt->SetTextSize(0.05);
tt->SetTextAlign(22);
tt->SetNDC(kTRUE);
tt->SetTextFont(22);
}                                                                                
                                                                                       
//Colors for Histos
h_mc[0]->SetFillColor(kTeal-8);
h_mc[0]->SetLineColor(kTeal-8);

h_mc[7]->SetFillColor(kTeal-8);
h_mc[7]->SetLineColor(kTeal-8);

for(int diboson =2; diboson <5; diboson++){
h_mc[diboson]->SetFillColor(kOrange-5);
h_mc[diboson]->SetLineColor(kOrange-5);
}

h_mc[1]->SetFillColor(kBlue-5);
h_mc[1]->SetLineColor(kBlue-5);


h_mc[5]->SetFillColor(kRed-3);
h_mc[5]->SetLineColor(kRed-3);


h_mc[6]->SetFillColor(kOrange+4);                                                                                                            
h_mc[6]->SetLineColor(kOrange+4);


h_mc[8]->SetFillColor(kMagenta-10);
h_mc[8]->SetLineColor(kMagenta-10);
h_mc[9]->SetFillColor(kMagenta-10);
h_mc[9]->SetLineColor(kMagenta-10);


//hadd all the histos acc to their contributions
/*
for(int qcd = 11; qcd < 22 ; qcd++){
hs->Add(h_mc[qcd]);
}*/

hs->Add(h_mc[1]);
for(int diboson = 2; diboson < 5; diboson++){
hs->Add(h_mc[diboson]);}
hs->Add(h_mc[8]);
hs->Add(h_mc[9]);
hs->Add(h_mc[5]);                                                                                                                              
//hs->Add(h_mc[1]);
hs->Add(h_mc[7]);
hs->Add(h_mc[0]);


//Get Histo from stack for ratio plot 
TH1 *Stackhist = (TH1*)hs->GetStack()->Last();


h_data->SetMarkerColor(kBlack);
h_data->SetMarkerStyle(20);
h_data->SetStats(0);

float maxi = h_data->GetMaximum();

//Setting canvas without log axis
 c12->SetLogy(0);

// Upper canvas declaration
 
  if(0){
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.993);
  }else{
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.29,1,0.974);
  c1_2->SetBottomMargin(0.03);
  }
 //c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(1);
  if(0){ c1_2->SetLogx(1);}
  c1_2->Draw();
  c1_2->cd();
  hs->Draw("hist"); 
  h_data->SetLineColor(1);
  h_data->Draw("same p e1");
  
  if(1)    hs->SetMinimum(1);
  if(!1)   hs->SetMinimum(1);
  if(!1)   hs->SetMaximum(maxi *1.22);
  if(1)    hs->SetMaximum(maxi *100);
  //if(!1) hs->SetMaximum(0.4);
 
  if(0){
  hs->GetXaxis()->SetTitleSize(0.05);
  hs->GetXaxis()->SetTitleOffset(0.97);
  hs->GetXaxis()->SetTitleFont(22);
  hs->GetXaxis()->SetLabelFont(22);
  hs->GetXaxis()->SetLabelSize(.05);
  hs->GetYaxis()->SetTitle("Events");
  hs->GetYaxis()->SetTitleSize(0.05);
  hs->GetYaxis()->SetTitleOffset(1.);
  hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);
  hs->GetYaxis()->SetLabelSize(.05);
  hs->GetXaxis()->SetTitle("ConversionVeto(endcap) ");
  }else{
  hs->GetXaxis()->SetLabelOffset(999);
  hs->GetXaxis()->SetLabelSize(0);  

  }  

  hs->GetYaxis()->SetTitle("Events");                                                                                                            hs->GetYaxis()->SetTitleSize(0.07);                                                                                                            hs->GetYaxis()->SetTitleOffset(0.9);                                                                                                           hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);                                                                                                              hs->GetYaxis()->SetLabelSize(.07);   
  hs->GetXaxis()->SetRangeUser(0,2);                                                                                                       hs->GetXaxis()->SetNdivisions(508); 
  legend->Draw("same"); 
  t2a->Draw("same");
  t2b->Draw("same");
t2c->Draw("same");
  if(nminus = =1){tt->Draw("same");}

  
 // Lower Tpad Decalaration
 
  if(! 0){
  c12->cd();
  
  TH1F *DataMC = (TH1F*) h_data->Clone();
/* DataMC->Divide(DataMC);

  double NMC=0;
  double NData=0;
  double RatioNMCNData =1.;
  int nbins = h_data->GetNbinsX();
  for( int j=0; j < nbins-1; j++){
   NData = h_data->GetBinContent(j+1);
   NMC   = Stackhist->GetBinContent(j+1); 
   if(NData > 0){
   RatioNMCNData = NData/NMC;
  // RatioNMCNData = (NData-NMC)/(sqrt(NData));
   }
   DataMC->SetBinContent(j+1, RatioNMCNData);
   }   

  DataMC->SetNameTitle("DataMC", "DataMC");*/
  
  DataMC->Divide(Stackhist);
  DataMC->GetYaxis()->SetTitle("Data/MC");
  DataMC->GetYaxis()->SetTitleSize(0.155);
  DataMC->GetYaxis()->SetTitleOffset(0.3);
  DataMC->GetYaxis()->SetTitleFont(22);
  DataMC->GetYaxis()->SetLabelSize(0.15);
  DataMC->GetYaxis()->CenterTitle();
  DataMC->GetXaxis()->SetTitle("ConversionVeto(endcap) ");
//DataMC->GetXaxis()->SetIndiceSize(0.1);
  DataMC->GetXaxis()->SetLabelSize(0.157);
  DataMC->GetXaxis()->SetTitleSize(0.162);
  DataMC->GetXaxis()->SetTitleOffset(1.02);
  DataMC->GetXaxis()->SetTitleFont(22);
  DataMC->GetXaxis()->SetTickLength(0.07);
  DataMC->GetXaxis()->SetLabelFont(22);
  DataMC->GetYaxis()->SetLabelFont(22);     
  
 TPad *c1_1 = new TPad("c1_1", "newpad",0,0.00,1,0.29);
 c1_1->Draw();
 c1_1->cd();
 c1_1->Range(-7.862408,-629.6193,53.07125,486.5489);
 c1_1->SetFillColor(0);
 c1_1->SetTicky(1);
 c1_1->SetLeftMargin(0.1290323);
 c1_1->SetRightMargin(0.05040323);
 c1_1->SetTopMargin(0.00);//0.0
 c1_1->SetBottomMargin(0.366666678814);
 c1_1->SetFrameFillStyle(0);
 c1_1->SetFrameBorderMode(0);
 c1_1->SetFrameFillStyle(0);
 c1_1->SetFrameBorderMode(0);
 c1_1->SetLogy(0);
 if(0){ c1_1->SetLogx(1);
 DataMC->GetXaxis()->SetMoreLogLabels();
 DataMC->GetXaxis()->SetNoExponent();

} 
 DataMC->GetXaxis()->SetRangeUser(0,2);
 DataMC->Draw("PE1");
 DataMC->SetMarkerStyle(20);
 DataMC->SetMarkerColor(1);
 DataMC->SetMinimum(0.7);
 DataMC->SetMaximum(1.8);
 DataMC->GetXaxis()->SetNdivisions(508);
 DataMC->GetYaxis()->SetNdivisions(503);
 c1_1->SetGridy();
 }

if(0){ 
   
//=======================================================================
  //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets
 TAxis *xaxis = h_mc[0]->GetXaxis();
 Int_t binxmin = xaxis->FindBin(0);
 Int_t binxmax = xaxis->FindBin(2);

  float qcdEntries =0.0, dibosonentries =0.0, totalMC =0.0, ratioDataMC = 0.0;
  /*for(int qcd = 6; qcd < 22 ; qcd++){                                                                                   
    qcdEntries+ = h_mc[qcd]->Integral(binxmin,binxmax);}*/

  for(int diboson = 2; diboson < 5; diboson++){                                                                                                   dibosonentries+ = h_mc[diboson]->Integral(binxmin,binxmax);}
 
  totalMC = h_mc[0]->Integral(binxmin,binxmax)+h_mc[7]->Integral(binxmin,binxmax)+ 
            h_mc[1]->Integral(binxmin,binxmax)+
            h_mc[5]->Integral(binxmin,binxmax)+
            dibosonentries;
 
  ratioDataMC = (h_mc[0]->Integral(binxmin,binxmax)+h_mc[7]->Integral(binxmin,binxmax))/(totalMC); 

  std::mout               
  <<"Electron_NoCut_Endcap_h_passConversionVeto4"                 << "   &   " 
  << h_data->Integral(binxmin,binxmax)  << "   &   " 
  << h_mc[0]->Integral(binxmin,binxmax) + h_mc[7]->Integral(binxmin,binxmax) << "   &   "
  <<h_mc[8]->Integral(binxmin,binxmax)+h_mc[9]->Integral(binxmin,binxmax)  << "   &   " 
  << dibosonentries                     << "   &   "
  << h_mc[5]->Integral(binxmin,binxmax) << "   &   " 
  << h_mc[1]->Integral(binxmin,binxmax) << "   &   "
  << h_mc[7]->Integral(binxmin,binxmax) << "   &   "
  << totalMC                            << "   &   "
  << ratioDataMC                        << "   &   "
  <<Stackhist->Integral(binxmin,binxmax) << "  \   "
  <<std::endl;
//=========================================================================

}
 
 c12->Draw();
 c12->SaveAs(DirPreName+dirpathname +"/DYPdf/Electron_NoCut_Endcap_h_passConversionVeto4.pdf");
 c12->SaveAs(DirPreName+dirpathname +"/DYPng/Electron_NoCut_Endcap_h_passConversionVeto4.png");
 c12->SaveAs(DirPreName+dirpathname +"/DYROOT/Electron_NoCut_Endcap_h_passConversionVeto4.root");                                                                         }
