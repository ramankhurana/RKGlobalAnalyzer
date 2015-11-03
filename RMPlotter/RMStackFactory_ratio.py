import os
## Ratio is added Data/MC 
## Template macro is fed to a python variable
## 1.) Dir is created on DateBase 
## 2.) Starting Extension of your Dir..Like 
## in a day you want 2 directories jsut
## change the DirPreName
## Monika Mittal Khuarana
macro='''{
#include <ctime>
#include <cstdlib>
#include "TStyle.h" 
 time_t now = time(0);
 tm *ltm = localtime(&now);
 TString dirpathname;

 TString DirPreName = "PlotsRaman_VeniceConf";
 dirpathname.Form("%d%1.2d%d",ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
 system("mkdir -p  " + DirPreName+dirpathname +"/DYROOT");
 system("mkdir -p  " + DirPreName+dirpathname +"/DYPdf");
 system("mkdir -p  " + DirPreName+dirpathname +"/DYPng");
 
 ofstream mout;
 mout.open(DirPreName+dirpathname +"/"+dirpathname +"Integral.txt",std::ios::app);

gROOT->ProcessLine(".L /afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/tdrstyle.C");                                     setTDRStyle();
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);
gStyle->SetFrameLineWidth(3);
gStyle->SetErrorX(0);
gStyle->SetLineWidth(1);

//Provide luminosity of total data
float lumi = 1263.8; // It will print on your plots too

std::vector<TString> filenameString;
//Change here Directories of the file
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/MonoHFatJetAnalysis_AllMCWithPU_V4_relax_subjetBTag/"); //_And_2AddbJetsV2
filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
//WJets  1
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");

// Diboson WW WZ ZZ 2 3 4
filenameString.push_back(filenamepath + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
// TTJets 5
filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//QCD jets 
// dummy qcd
filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");

//Raman ZH background 7                                                                                                                       
filenameString.push_back(filenamepath + "Merged_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8-runallAnalysis.root"); 
//filenameString.push_back(filenamepath + "Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-runallAnalysis.root");
//Raman Signal Sample 8-14
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root");  
filenameString.push_back(filenamepath + "Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root");  


//DYJets High pt DYSample 15,16,17,18
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-100To200_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-200To400_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-400To600_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph-runallAnalysis.root");


//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");


// WJets in Bins  19,20,21,22,23,24,25
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");

// Single Top 26,27,28,29,30
filenameString.push_back(filenamepath + "Merged_ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1-runallAnalysis.root");

                                                                   
//Data File
//filenameString.push_back(filenamepath + "Merged_MET-Run2015B-PromptReco-v1TotalV3-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_MET.root");
//histoname
TString histnameString("HISTPATH/HISTNAME");

TFile *fIn;
const int nfiles = (int) filenameString.size();

//check it once
float Xsec[nfiles];
Xsec[0] = 6104;
Xsec[1] = 61500;
Xsec[2] = 118.7; 
Xsec[3] = 66.1;
Xsec[4] = 15.4;
Xsec[5] = 831.76;
Xsec[6] = 89731000000;
Xsec[7] = 0.9696*0.577; //ZH
float scalexs=20.; 
Xsec[8]  = scalexs * 0.202;//600
Xsec[9]  = scalexs * 0.160;//700
Xsec[10] = scalexs * 0.12498; //800
Xsec[11] = scalexs * 0.100; //900
Xsec[12] = scalexs * 0.065056; //1000
Xsec[13] = scalexs * 0.03437; //1200
Xsec[14] = scalexs * 0.015; //1500

Xsec[15] = 280.47; // Znunu HT
Xsec[16] = 78.36; // Znunu HT
Xsec[17] = 10.94; // Znunu HT
Xsec[18] = 4.203;  // Znunu HT

Xsec[19] = 1.21*1347;  // WJets HT 100-200
Xsec[20] = 1.21*360;   // WJets HT 200-400
Xsec[21] = 1.21*48.9;  // WJets HT 400-600
Xsec[22] = 1.21*12.8;  // WJets HT 600-800
Xsec[23] = 1.21*5.26;  // WJets HT 800-1200
Xsec[24] = 1.21*1.33;  // WJets HT 1200-2500
Xsec[25] = 1.21*0.03089;  // WJets HT 2500-Inf

Xsec[26] = 44.51; // single top
Xsec[27] = 26.49; // single top
Xsec[28] = 3.38; // single top
Xsec[29] = 35.85; // single top
Xsec[30] = 35.85; // single top

//Xsec[15] = 139.4; // DY HT
//Xsec[16] = 42.75; // DY HT
//Xsec[17] = 5.497; // DY HT
//Xsec[18] = 2.21;  // DY HT
//

TH1F* h_mc[nfiles] ;
float normalization[nfiles];
TH1F *h_data;

for(int i =0; i<(int)filenameString.size()-1; i++){
 fIn = new TFile(filenameString[i],"READ");
 h_mc[i] = (TH1F*) fIn->Get(histnameString);
 h_total      = (TH1F*) fIn->Get("nEvents_weight");
 
std::cout<<" normalization for = "<<filenameString[i]<<"   "
<<h_mc[i]->Integral()<<std::endl;
 if(h_total->Integral()>0) normalization[i]     = (lumi* Xsec[i])/(h_total->Integral());
else normalization[i]      = 0;
 //cout<<"normalization :" << normalization[i] << std::endl;
 h_mc[i]->Rebin(REBIN); 
 h_mc[i]->Scale(normalization[i]);  
// mout << filenameString[i] <<  "  &  " << Xsec[i] <<"  &  " << std::endl; 
// cout << "Integral : " << h_total->Integral() << "  Entries :  " << h_total->GetEntries() << std::endl;                                         

 }

fIn = new TFile(filenameString[nfiles-1],"READ");
h_data = (TH1F*) fIn->Get(histnameString);
h_data->Rebin(REBIN);
h_data->Sumw2();



 //Legend
 TLegend *legend;
 
 if(NORATIOPLOT){
 legend = new TLegend(0.73, 0.68, 0.95,0.92,NULL,"brNDC");
 legend->SetTextSize(0.05);
 }else{

legend = new TLegend(0.62, 0.71, 0.94,0.92,NULL,"brNDC"); 
//legend = new TLegend(0.13, 0.85, 0.95,0.92,NULL,"brNDC");
// legend = new TLegend(0.7, 0.68, 0.95,0.92,NULL,"brNDC");
 legend->SetTextSize(0.05); }
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(42);
 legend->SetNColumns(2);
 legend->AddEntry(h_data,"Data","p");                                                                                                          
 legend->AddEntry(h_mc[8],"M600", "l");
 legend->AddEntry(h_mc[12],"M1000", "l");
 legend->AddEntry(h_mc[14],"M1500", "l");
 legend->AddEntry(h_mc[15],"Z#nu#nu+Jets","f");
 legend->AddEntry(h_mc[2],"Diboson","f");                                                                                                      
 legend->AddEntry(h_mc[5],"t#bar{t}","f");
 legend->AddEntry(h_mc[26],"Single Top","f");
 legend->AddEntry(h_mc[19],"WJets","f");
 legend->AddEntry(h_mc[7],"ZH","f");
 //legend->AddEntry(h_mc[6],"QCD","f");
 

 
//===========================Latex=================//
TString latexCMSname= "CMS";
TString latexPreCMSname= "Preliminary";
 
TString latexnamemiddle;
latexnamemiddle.Form("%1.2f",lumi); 
TString latexnamepost = " pb^{-1} (13 TeV)";
//TString latexname = latexnamepre+latexnamemiddle+latexnamepost;  
TString latexname = latexnamemiddle+latexnamepost;

TLatex *t2b;
TLatex *t2c;

if(NORATIOPLOT){
 t2a = new TLatex(0.7,0.97,latexname);
 t2a->SetTextSize(0.04);
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
if(("HISTPATH" == "ElectronNMinus1E") || ("HISTPATH" == "ElectronNMinus1B") ){
nminus =1;
tt  = new TLatex(0.5,0.87,"N-1");
tt->SetTextSize(0.05);
tt->SetTextAlign(22);
tt->SetNDC(kTRUE);
tt->SetTextFont(22);
}                                                                                
                                                                                       
//Colors for Histos
//h_mc[0]->SetFillColor(kOrange-1);
//h_mc[0]->SetLineColor(kOrange-1);

h_mc[15]->SetFillColor(kOrange-1);
h_mc[15]->SetLineColor(kOrange-1);

h_mc[16]->SetFillColor(kOrange-1);
h_mc[16]->SetLineColor(kOrange-1);

h_mc[17]->SetFillColor(kOrange-1);
h_mc[17]->SetLineColor(kOrange-1);

h_mc[18]->SetFillColor(kOrange-1);
h_mc[18]->SetLineColor(kOrange-1);



h_mc[7]->SetFillColor(kTeal-8);
h_mc[7]->SetLineColor(kTeal-8);

for(int diboson =2; diboson <5; diboson++){
h_mc[diboson]->SetFillColor(kRed-10);
h_mc[diboson]->SetLineColor(kRed-10);
}

h_mc[5]->SetFillColor(kBlue-5);
h_mc[5]->SetLineColor(kBlue-5);

//Old W+Jets
//h_mc[1]->SetFillColor(kOrange+4);                                                                                                            


// WJets HT Bins
h_mc[19]->SetFillColor(kOrange+4);                                                                                                            
h_mc[19]->SetLineColor(kOrange+4);


h_mc[20]->SetFillColor(kOrange+4);                                                                                                            
h_mc[20]->SetLineColor(kOrange+4);

h_mc[21]->SetFillColor(kOrange+4);                                                                                                            
h_mc[21]->SetLineColor(kOrange+4);

h_mc[22]->SetFillColor(kOrange+4);                                                                                                            
h_mc[22]->SetLineColor(kOrange+4);

h_mc[23]->SetFillColor(kOrange+4);                                                                                                            
h_mc[23]->SetLineColor(kOrange+4);

h_mc[24]->SetFillColor(kOrange+4);                                                                                                            
h_mc[24]->SetLineColor(kOrange+4);

h_mc[25]->SetFillColor(kOrange+4);                                                                                                            
h_mc[25]->SetLineColor(kOrange+4);

// Single Top 
h_mc[26]->SetFillColor(kBlue-7);                                                                                                            
h_mc[26]->SetLineColor(kBlue-7);

h_mc[27]->SetFillColor(kBlue-7);                                                                                                            
h_mc[27]->SetLineColor(kBlue-7);

h_mc[28]->SetFillColor(kBlue-7);                                                                                                            
h_mc[28]->SetLineColor(kBlue-7);

h_mc[29]->SetFillColor(kBlue-7);                                                                                                            
h_mc[29]->SetLineColor(kBlue-7);

h_mc[30]->SetFillColor(kBlue-7);                                                                                                            
h_mc[30]->SetLineColor(kBlue-7);



h_mc[6]->SetFillColor(kGreen);
h_mc[6]->SetLineColor(kGreen);

/*
for(int qcd = 6; qcd < 7 ; qcd++){ 
h_mc[qcd]->SetFillColor(kOrange+4);                                                                                                            
h_mc[qcd]->SetLineColor(kOrange+4);
}*/

h_mc[8]->SetLineColor(kBlack);
h_mc[8]->SetLineWidth(3);
h_mc[12]->SetLineColor(kGreen);
h_mc[12]->SetLineWidth(3);
h_mc[14]->SetLineColor(kRed);
h_mc[14]->SetLineWidth(3);



//hadd all the histos acc to their contributions

//for QCD Contribution
//hs->Add(h_mc[6]);

for(int diboson = 2; diboson < 5; diboson++){
 hs->Add(h_mc[diboson]);
}                                                                                                          
//hs->Add(h_mc[0]);                                                                        
hs->Add(h_mc[15]);
hs->Add(h_mc[16]);
hs->Add(h_mc[17]);
hs->Add(h_mc[18]);
hs->Add(h_mc[7]); 
//hs->Add(h_mc[1]);
hs->Add(h_mc[19]);
hs->Add(h_mc[20]);
hs->Add(h_mc[21]);
hs->Add(h_mc[22]);
hs->Add(h_mc[23]);
hs->Add(h_mc[24]);
hs->Add(h_mc[25]);
hs->Add(h_mc[26]);
hs->Add(h_mc[27]);
hs->Add(h_mc[28]);
hs->Add(h_mc[29]);
hs->Add(h_mc[30]);

hs->Add(h_mc[5]);

h_data->SetMarkerColor(kBlack);
h_data->SetMarkerStyle(20);
float maxi = h_data->GetMaximum();

TH1 *Stackhist = (TH1*)hs->GetStack()->Last(); 


//Setting canvas without log axis
c12->SetLogy(0);
  
  
  
  // Upper canvas declaration
 
  if(NORATIOPLOT){
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.993);
  }else{
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.29,1,0.974);
  c1_2->SetBottomMargin(0.03);
  }
 //c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->Draw();
  c1_2->cd();
  hs->Draw("hist"); 
  h_data->SetLineColor(1);
  h_data->Draw("same p e1");
  
  if(ISLOG)    hs->SetMinimum(0.1);
  if(!ISLOG)   hs->SetMinimum(1);
  if(!ISLOG)   hs->SetMaximum(maxi *1.22);
  if(ISLOG)    hs->SetMaximum(maxi *10);
  //if(!ISLOG) hs->SetMaximum(0.4);
 
  if(NORATIOPLOT){
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
  hs->GetXaxis()->SetTitle("XAXISLABEL");
  }else{
  hs->GetXaxis()->SetLabelOffset(999);
  hs->GetXaxis()->SetLabelSize(0);  

  }  


  hs->GetYaxis()->SetTitle("Events");                                   
  hs->GetYaxis()->SetTitleSize(0.07);                                                                                                            hs->GetYaxis()->SetTitleOffset(0.9);                                                                                                           hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);                                                                                                              hs->GetYaxis()->SetLabelSize(.07);   
  hs->GetXaxis()->SetRangeUser(XMIN,XMAX);                                                                                                       hs->GetXaxis()->SetNdivisions(508); 
  legend->Draw("same"); 
  t2a->Draw("same");
  t2b->Draw("same");
  t2c->Draw("same");
  
  
  if(nminus = =1){tt->Draw("same");}
  
// Commenting out the signal for control region
  //h_mc[8]->Draw("same");
  //h_mc[12]->Draw("same");
  //h_mc[14]->Draw("same");


  
 // Lower Tpad Decalaration
 
  if(! NORATIOPLOT){
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
  DataMC->GetXaxis()->SetTitle("XAXISLABEL");
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
 DataMC->GetXaxis()->SetRangeUser(XMIN,XMAX);
 DataMC->Draw("PE1");
 DataMC->SetMarkerStyle(20);
 DataMC->SetMarkerColor(1);
 DataMC->SetMinimum(0.);
 DataMC->SetMaximum(2.2);
 DataMC->GetXaxis()->SetNdivisions(508);
 DataMC->GetYaxis()->SetNdivisions(503);
 c1_1->SetGridy();


 TF1 *line0 = new TF1("line0","[0]*x",XMIN,XMAX);
 line0->FixParameter(0,0);
// line0->FixParameter(1,0);
 
 //DataMC->Fit("line0");
 //line0->SetLineColor(kRed);
 //line0->Draw("same");
 //
 //Double_t chi2 = line0->GetChisquare();
 //cout <<"chi2:" << chi2 <<std::endl;

 }
  


if(TEXTINFILE){ 
   
//=======================================================================
  //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets
 TAxis *xaxis = h_mc[0]->GetXaxis();
 Int_t binxmin = xaxis->FindBin(XMIN);
 Int_t binxmax = xaxis->FindBin(XMAX);

  float qcdEntries =0.0, dibosonentries =0.0 , wjetentries=0.0;
//  for(int qcd = 6; qcd < 22 ; qcd++){                                                                                   
//    qcdEntries+ = h_mc[qcd]->GetBinContent(5);}

  for(int diboson = 2; diboson < 5; diboson++){                                                                                                  dibosonentries+ = h_mc[diboson]->GetBinContent(5);}       

wjetentries= h_mc[19]->Integral() +h_mc[20]->Integral()+h_mc[21]->Integral()+h_mc[22]->Integral()+h_mc[23]->Integral()+h_mc[24]->Integral()+h_mc[25]->Integral();
                                             
                                     
  mout << "HISTPATH_HISTNAME"            << std::endl; 
  mout << " DATA "    << h_data->Integral()  << std::endl; 
  mout << " DYJETS "  << h_mc[0]->Integral() << std::endl; 
  mout << " DIBOSON " << dibosonentries                     << std::endl;
  mout << " TT "      << h_mc[5]->Integral() << std::endl; 
  mout << " WJETS "   << h_mc[19]->Integral() +h_mc[20]->Integral()+h_mc[21]->Integral()+h_mc[22]->Integral()+h_mc[23]->Integral()+h_mc[24]->Integral()+h_mc[25]->Integral()<< std::endl;
  mout << " ZH "      << h_mc[7]->Integral() << std::endl;
  mout << " DY high pt"<<h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral() << std::endl;  
  mout << " Single Top "<<h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() << std::endl;  
  mout << " M600 "    << h_mc[8]->Integral() << std::endl;
  mout << " M700 "    << h_mc[9]->Integral() << std::endl;
  mout << " M800 "    << h_mc[10]->Integral() << std::endl;
  mout << " M900 "    << h_mc[11]->Integral() << std::endl;
  mout << " M1000 "   << h_mc[12]->Integral() << std::endl;
  mout << " M1200 "   << h_mc[13]->Integral() << std::endl;
  mout << " M1500 "   << h_mc[14]->Integral() << std::endl;
  mout << " QCD "     << h_mc[6]->Integral() <<  std::endl;
  mout << "Total Bkg " << dibosonentries+h_mc[5]->Integral()+wjetentries+h_mc[7]->Integral()+h_mc[15]->Integral()+h_mc[16]->Integral()+h_mc[17]->Integral()+h_mc[18]->Integral()+h_mc[26]->Integral()+h_mc[27]->Integral()+h_mc[28]->Integral()+h_mc[29]->Integral()+ h_mc[30]->Integral() <<std::endl;
  mout << "======================================================" <<std::endl;
//=========================================================================

}
 
 c12->Draw();
 c12->SaveAs(DirPreName+dirpathname +"/DYPdf/HISTPATH_HISTNAME.pdf");
 c12->SaveAs(DirPreName+dirpathname +"/DYPng/HISTPATH_HISTNAME.png");
 c12->SaveAs(DirPreName+dirpathname +"/DYROOT/HISTPATH_HISTNAME.root");                                                                         }
'''
## template macro ends here

TemplateOverlapMacro = open('TemplateOverlapMacro.C','w')
TemplateOverlapMacro.write(macro)
TemplateOverlapMacro.close()

def makeplot(inputs):
    print inputs
    TemplateOverlapMacro = open('TemplateOverlapMacro.C','r')
    NewPlot       = open('Plot.C','w')
    for line in TemplateOverlapMacro:
        line = line.replace("HISTPATH",inputs[0])
        line = line.replace("HISTNAME",inputs[1])
        line = line.replace("XAXISLABEL",inputs[2])
        line = line.replace("XMIN",inputs[3])
        line = line.replace("XMAX",inputs[4])
        line = line.replace("REBIN",inputs[5]) 
        line = line.replace("ISLOG",inputs[6])
        if len(inputs) > 7 : 
            line = line.replace("TEXTINFILE", inputs[7])
        else : 
            line = line.replace("TEXTINFILE", "0")     
        if len(inputs) > 8 :
            line = line.replace(".pdf",str(inputs[8]+".pdf"))
            line = line.replace(".png",str(inputs[8]+".png"))
        if len(inputs) > 9 :
            line = line.replace("NORATIOPLOT", inputs[9])
        else :
            line = line.replace("NORATIOPLOT", "0")
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here

#dirnames=['MonoHFatJetsPreselection_2subj','histfacFatJet_TTBar','histfacFatJet_ZLight','histfacFatJet_ZHeavy','histfacFatJet_WLight','histfacFatJet_WHeavy']
dirnames=['histfacFatJet_WLight']
## Plots After Pre-selection
#makeplot(['CutFlowAndEachCutFatJet', 'h_cutflow_0_f', 'Cut Flow', '0','5', '1', '1','1'])
for dirname in dirnames:
    makeplot([dirname,'h_nMuons0','N_{add. #mu}','0','5','1','0'])
    makeplot([dirname,'h_nElectrons0','N_{add. e}','0','5','1','0'])
    makeplot([dirname,'h_nJetss0','N_{add. Jets}','0','5','1','0']) 
    makeplot([dirname,'h_MET0','MET','200','800','4','0'])
    makeplot([dirname,'h_Mjj0','M_{SD}','20','200','2','0','1']) 
    makeplot([dirname,'h_pTjj0','p_{T}^{AK8Jet}','100','1600','4','0'])
    makeplot([dirname,'h_h_Tau21jj0','#tau_{21}','0','1','1','0'])
    makeplot([dirname,'h_CSVSum0','CSV','0','1','1','0'])
    makeplot([dirname,'h_phijj0','#phi_{AK8Jet}','-3.5','3.5','5','0'])
    makeplot([dirname,'h_etajj0','#eta_{AK8Jet}','-2.5','2.5','5','0'])
    makeplot([dirname,'h_nTaus0','N_{#tau}','0','5','1','0'])
    makeplot([dirname,'h_dPhi_bb_MET0','#Delta#phi_{AK8Jet-MET}','2.','3.5','2','0'])
    makeplot([dirname,'h_MT_bb_MET0', 'M_{T}', '200','1000', '10','0'])
    makeplot([dirname,'h_DRSJ0', '#DeltaR_{sub-jets}', '0','1', '1','0'])
    makeplot([dirname,'h_CSVMax0', 'CSV_{Max}', '0','1', '1','0'])
    makeplot([dirname,'h_CSVMin0', 'CSV_{Min}', '0','1', '1','0'])
    makeplot([dirname,'h_MET_Over_SumET0', 'MET/SumET', '0','5', '2','0'])
    makeplot([dirname,'h_MET_Over_pTFatJet0', 'MET/p_{T}^{AK8-Jet}', '0','1.', '1','0'])
    makeplot([dirname,'h_CEmEF0', 'CEmEF', '0','1.', '1','0'])
    makeplot([dirname,'h_CHadEF0', 'CHadEF', '0','1.', '1','0'])
    makeplot([dirname,'h_PhoEF0', 'PhoEF', '0','1.', '1','0'])
    makeplot([dirname,'h_NHadEF0;1', 'NHadEF', '0','1.', '1','0'])
    makeplot([dirname,'h_MuEF0', 'MuEF', '0','1.', '1','0'])

#
        
#
### N-1 Plots
##makeplot(['NMinusOne','h_FatJetpTapteta','p_{T}^{AK8Jet}','180','700','10','0'])
##makeplot(['NMinusOne','h_FatJetCSVbcsv','CSV','0','1','5','0'])
##makeplot(['NMinusOne','h_DPhiFatJetMETcDPHIJetMet','#Delta#phi_{AK8Jet-MET}','0','3.5','2','0'])
##makeplot(['NMinusOne','h_MSoftDropdMjet','M_{SD}','0','200','5','0'])
##makeplot(['NMinusOne','h_METemetpt','MET','0','1000','10','0'])

#makeplot(['MonoHFatJetsPreselection','','','','','',''])


