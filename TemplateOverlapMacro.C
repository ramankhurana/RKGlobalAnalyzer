{
#include <ctime>
#include <cstdlib>
 
 time_t now = time(0);
 tm *ltm = localtime(&now);
 TString dirpathname;

 TString DirPreName = "OutputDir/PlotElectrons_Electron_SET_SingleDataset_pileup_1_nvtx";
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
// gStyle->SetErrorX(0);
 gStyle->SetLineWidth(1);

//Provide luminosity of total data
 float lumi = 2.106;
float lumitotal = 2.106307;
 std::vector<TString> filenameString;

//TString filenamepath2("/afs/hep.wisc.edu/cms/khurana/Script/Electron_25ns_14012016_withoutPileup/");
//TString filenamepath1("/afs/hep.wisc.edu/cms/khurana/Script/Electron_25ns_14012016_withoutPileup/");
//TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/Electron_25ns_14012016/");
//TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_NoPileup_19012016/");
//TString filenamepath1("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_DY_withnewPileupWeights80mb_trueInt_20012016/");
//TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_pileup_correctedfloat_ShilpiCorrected_nvtx/");
//TString filenamepath1("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_pileup_correctedfloat_ShilpiCorrected_nvtx/");
//TString filenamepath2("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_pileup_correctedfloat_71mb_nvtx/");
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_pileup_1_nvtx/");
TString filenamepath1("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_pileup_1_nvtx/");
TString filenamepath2("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_pileup_1_nvtx/");

// TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/Electron_SET_SingleDataset_withoutpileup/");
// TString filenamepath1("/afs/hep.wisc.edu/cms/khurana/PlotElectrons_Electron_Script/Electron_SET_SingleDataset_pileup_80mb/");

//Signal 0-9
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-50to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToEE_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");


//WJets  10-17
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-600To800_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-800To1200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-1200To2500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_WJetsToLNu_HT-2500ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");



// Diboson WW WZ ZZ  18 19 20
 filenameString.push_back(filenamepath + "Merged_WW_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_WZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath + "Merged_ZZ_TuneCUETP8M1_13TeV-pythia8-runallAnalysis.root");

// TTJets 21
 filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_TTJets_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");

//DYTau tau contribution 22-31

 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-50to200_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-200to400_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-400to500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-500to700_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-700to800_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-800to1000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-1000to1500_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-1500to2000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");
 filenameString.push_back(filenamepath1 + "Merged_DYJetsToTauTau_M-2000to3000_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-runallAnalysis.root");


//QCD jets  32
 filenameString.push_back(filenamepath + "Merged_TT_TuneCUETP8M1_13TeV-powheg-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath + "Merged_QCD_Pt-15TTo7000_TuneZ2star-Flat_13TeV_pythia6-runallAnalysis.root");


//Data File
//25ns data
 filenameString.push_back(filenamepath2 + "Data_25ns.root");

//histoname
 TString histnameString("HISTPATH/HISTNAME");
 if(HISTDIR){TString histnameString("HISTNAME");}

 TFile *fIn;
 const int nfiles = (int) filenameString.size();

 float n_IntegralError[nfiles];
 float n_Integral[nfiles];
 float n_IntegralNorm[nfiles];
 float n_Integral_data;

 float Xsec[nfiles];


 Xsec[0] = 6203.3;   // DY 10-50
 Xsec[1] = 2031;     
 Xsec[2] = 2.56;
 Xsec[3] = 0.141;
 Xsec[4] = 0.08;
 Xsec[5] = 0.012;
 Xsec[6] = 0.01;
 Xsec[7] = 0.0053; 
 Xsec[8] = 0.00067; 
 Xsec[9] = 0.00018;

 Xsec[10] = 61526;  //WJetsToLNu
 Xsec[11] = 1347; 
 Xsec[12] =  360;
 Xsec[13] = 48.9;
 Xsec[14] = 12.8;
 Xsec[15] = 5.26;
 Xsec[16] = 1.33;
 Xsec[17] = 0.03089; 

 Xsec[18] = 118.7;  //WW
 Xsec[19] = 44.9;   //WZ
 Xsec[20] = 15.4;   //ZZ
 Xsec[21] = 831.76; //TT
 Xsec[22] = 6203.3; //DYTotautau 
 Xsec[23] = 2031;
 Xsec[24] = 2.56;
 Xsec[25] = 0.141;
 Xsec[26] = 0.08;
 Xsec[27] = 0.012; 
 Xsec[28] = 0.01; 
 Xsec[29] = 0.0053;
 Xsec[30] = 0.00067;
 Xsec[31] = 0.00018;
 Xsec[32] = 89731000000;

 TH1F* h_mc[nfiles] ;
 TH1F* h_rebin[nfiles];
 float normalization[nfiles];
 TH1F *h_data;
 TH1F *h_data_rebin;

//Varibale reebinning of mass
 double massbin[46] ={15,20,25,30,35,40,45,50,55,60,64,68,72,76,81,86,91,96,101,106,110,115,120,126,133,141,150,160,171,185,200,220,243,273,320,380,440,510,600,700,830,1000,1200,1500,2000,3000};


// Main Code starts here

 TFile *f1 = new TFile(filenameString[0],"READ");
 TH1F *testhisto = (TH1F*) f1->Get(histnameString);
 TAxis *xaxis = testhisto->GetXaxis();
 Int_t binxmin = xaxis->FindBin(XMIN);
 Int_t binxmax = xaxis->FindBin(XMAX);


//std::mout << " Range given from  "  << XMIN <<" to  " << XMAX << "with bin number from :  "<< binxmin << " to  :  " << binxmax <<std::endl; 

for(int i =0; i<(int)filenameString.size()-1; i++){
 fIn = new TFile(filenameString[i],"READ");
 h_total              = (TH1F*) fIn->Get("nEvents_weight");                                                                                  
 normalization[i]     = (lumitotal* Xsec[i]*1000.)/(h_total->Integral());

 if(VARIABLEBINS){
   h_rebin[i]        = (TH1F*) fIn->Get(histnameString);
   n_Integral[i]     = h_rebin[i]->Integral(binxmin,binxmax);
   if(n_Integral[i] <0.){n_Integral[i] = 0;}
   h_rebin[i]->Scale(normalization[i]);
   n_IntegralNorm[i] = n_Integral[i]*normalization[i];
   h_rebin[i]->Sumw2();
   h_rebin[i]->Rebin(45,"hnew",massbin);
   h_mc[i]            = (TH1F*)hnew->Clone();
   n_IntegralError[i] = (TMath::Sqrt(n_Integral[i]))*normalization[i];
 }
 if(!VARIABLEBINS){
   h_mc[i]    = (TH1F*) fIn->Get(histnameString);
   h_mc[i]->Sumw2();
   n_Integral[i]= h_mc[i]->Integral(binxmin,binxmax);
   if(n_Integral[i] <0.){n_Integral[i] = 0;}
   h_mc[i]->Scale(normalization[i]);
   n_IntegralError[i] = (TMath::Sqrt(n_Integral[i]))*normalization[i];
   n_IntegralNorm[i] = n_Integral[i]*normalization[i];
   h_mc[i]->Rebin(REBIN);

 }

cout << filenameString[i] <<  "  &  "  <<  normalization[i] <<"  &  " <<n_Integral[i]  << " " <<  n_IntegralNorm[i] << std::endl;
 }

 fIn = new TFile(filenameString[nfiles-1],"READ");
 if(VARIABLEBINS){
   h_data_rebin = (TH1F*) fIn->Get(histnameString);
   n_Integral_data = h_data_rebin->Integral(binxmin,binxmax);
   h_data_rebin->Rebin(45,"hnewdata",massbin);                                                                                               
   h_data= (TH1F*)hnewdata->Clone();
 }
 if(!VARIABLEBINS){
   h_data = (TH1F*) fIn->Get(histnameString);
   n_Integral_data = h_data->Integral(binxmin,binxmax);
   h_data->Rebin(REBIN);}
   
 //Legend
 TLegend *legend;
 
 if(NORATIOPLOT){
   legend = new TLegend(0.73, 0.68, 0.95,0.92,NULL,"brNDC");
   legend->SetTextSize(0.05);
 }else{

 //legend = new TLegend(0.5, 0.7, 0.9,0.88,NULL,"brNDC"); 
//legend = new TLegend(0.13, 0.85, 0.95,0.92,NULL,"brNDC");
  legend = new TLegend(0.7, 0.62, 0.95,0.92,NULL,"brNDC");
  legend->SetTextSize(0.06);
 }

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
 legend->AddEntry(h_mc[21],"t#bar{t}","f");
 legend->AddEntry(h_mc[22],"DY#rightarrow #tau#tau","f"); 
 legend->AddEntry(h_mc[18],"Diboson","f");                                                                                                     
 legend->AddEntry(h_mc[10],"WJets","f");
//legend->AddEntry(h_mc[32],"QCD","f");
 
//===========================Latex=================//

 TString latexCMSname= "CMS";
 TString latexPreCMSname= "Preliminary";
 
 TString latexnamemiddle;
 latexnamemiddle.Form("%1.2f",lumi); 
 TString latexnamepost = " fb^{-1} (13 TeV)";
 TString latexname = latexnamemiddle+latexnamepost;

 TLatex *t2b;
 TLatex *t2c;

 if(NORATIOPLOT){
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
 if(("HISTPATH" == "ElectronNMinus1E") || ("HISTPATH" == "ElectronNMinus1B") ){
   nminus =1;
   tt  = new TLatex(0.5,0.87,"N-1");
   tt->SetTextSize(0.05);
   tt->SetTextAlign(22);
   tt->SetNDC(kTRUE);
   tt->SetTextFont(22);
 }                                                                                
                                                                                       
//Colors for Histos
 for(int DYtoEE =0; DYtoEE< 10; DYtoEE++){
   h_mc[DYtoEE]->SetFillColor(kTeal-8);
   h_mc[DYtoEE]->SetLineColor(kTeal-8);
 }


 for(int diboson =18; diboson <21; diboson++){
   h_mc[diboson]->SetFillColor(kOrange-5);
   h_mc[diboson]->SetLineColor(kOrange-5);
 }

 for(int wjets = 10; wjets < 18; wjets++){
   h_mc[wjets]->SetFillColor(kBlue-5);
   h_mc[wjets]->SetLineColor(kBlue-5);
 }


 h_mc[21]->SetFillColor(kRed-3);
 h_mc[21]->SetLineColor(kRed-3);


 h_mc[32]->SetFillColor(kOrange+4);                                                                                                            
 h_mc[32]->SetLineColor(kOrange+4);

 for(int DYtoTauTau =22; DYtoTauTau< 32; DYtoTauTau++){
   h_mc[DYtoTauTau]->SetFillColor(kMagenta-10);
   h_mc[DYtoTauTau]->SetLineColor(kMagenta-10);
 }


//hadd all the histos acc to their contributions


 for(int wjets = 11; wjets < 18; wjets++){
   hs->Add(h_mc[wjets]);}
 for(int diboson = 18; diboson < 21; diboson++){
   hs->Add(h_mc[diboson]);}
 for(int DYtoTauTau =22; DYtoTauTau< 32; DYtoTauTau++){
   hs->Add(h_mc[DYtoTauTau]);}
 
 hs->Add(h_mc[21]);  
 for(int DYtoEE =0; DYtoEE< 10; DYtoEE++){
   hs->Add(h_mc[DYtoEE]);}



//Get Histo from stack for ratio plot 
 TH1 *Stackhist = (TH1*)hs->GetStack()->Last();


 h_data->SetMarkerColor(kBlack);
 h_data->SetMarkerStyle(20);
 h_data->SetStats(0);

float maxi = h_data->GetMaximum();

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
  if(VARIABLEBINS){ c1_2->SetLogx(1);}
  c1_2->Draw();
  c1_2->cd();
  hs->Draw("hist"); 


  //For Statitical errpr. For this analysis it is very less. 
//  Stackhist->Draw("E2 SAME");
//  Stackhist->SetMarkerStyle(1);
//  Stackhist->SetMarkerSize(0.000001);
//  Stackhist->SetFillColor(1);
//  Stackhist->SetFillStyle(3002); 
//
  h_data->SetLineColor(1);
  h_data->Draw("same p e1");
  
  if(ISLOG)    hs->SetMinimum(0.1);
  if(!ISLOG)   hs->SetMinimum(0.);
  if(!ISLOG)   hs->SetMaximum(maxi *1.22);
  if(ISLOG)    hs->SetMaximum(maxi *100);
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

  hs->GetYaxis()->SetTitle("Events");                                                                                                           hs->GetYaxis()->SetTitleSize(0.07);                                                                                                           hs->GetYaxis()->SetTitleOffset(0.9);                                                                                                          hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);                                                                                                             hs->GetYaxis()->SetLabelSize(.07);   
  hs->GetXaxis()->SetRangeUser(XMIN,XMAX);                                                                                                      hs->GetXaxis()->SetNdivisions(508); 
  legend->Draw("same"); 
  t2a->Draw("same");
  t2b->Draw("same");
  t2c->Draw("same");
  if(nminus = =1){tt->Draw("same");}

  
 // Lower Tpad Decalaration
 
  if(! NORATIOPLOT){
  c12->cd();
  
  TH1F *DataMC = (TH1F*) h_data->Clone();
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
  if(VARIABLEBINS){ c1_1->SetLogx(1);
    DataMC->GetXaxis()->SetMoreLogLabels();
    DataMC->GetXaxis()->SetNoExponent();
  } 
  DataMC->GetXaxis()->SetRangeUser(XMIN,XMAX);
  DataMC->Draw("PE1");
  DataMC->SetMarkerStyle(20);
  DataMC->SetMarkerColor(1);
  DataMC->SetMinimum(0.);
  DataMC->SetMaximum(2.);
  DataMC->GetXaxis()->SetNdivisions(508);
  DataMC->GetYaxis()->SetNdivisions(505);
  c1_1->SetGridy();
 }

 if(TEXTINFILE){ 
   
//=======================================================================
 //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets

 TAxis *xaxis = h_mc[0]->GetXaxis();
 Int_t binxmin = xaxis->FindBin(XMIN);
 Int_t binxmax = xaxis->FindBin(XMAX);

 float qcdEntries =0.0, Err_qcdEntries =0.0, Int_qcdEntries =0.0; 
 float dibosonentries =0.0, Err_dibosonentries =0.0, Int_dibosonentries =0.0;
 float DYtoEEEntries =0.0, Err_DYtoEEEntries =0.0, Int_DYtoEEEntries =0.0;
 float wjetsEntries =0.0, Err_wjetsEntries =0.0, Int_wjetsEntries =0.0;
 float DYtoTauTauEntries =0.0, Err_DYtoTauTauEntries =0.0, Int_DYtoTauTauEntries =0.0;
 float ttbarEntries =0.0, Err_ttbarEntries =0.0, Int_ttbarEntries =0.0;
 float totalMC =0.0 , Err_totalMC =0.0, Int_totalMC =0.0;
 float ratioDataMC =0.0;


  for(int wjets = 11; wjets < 18; wjets++){
     wjetsEntries+ = h_mc[wjets]->Integral(binxmin,binxmax);
     Err_wjetsEntries+ = n_IntegralError[wjets]*n_IntegralError[wjets];
     Int_wjetsEntries+ = n_IntegralNorm[wjets];
  }
  for(int DYtoTauTau =22; DYtoTauTau< 32; DYtoTauTau++){
     DYtoTauTauEntries+ = h_mc[DYtoTauTau]->Integral(binxmin,binxmax);
     Err_DYtoTauTauEntries+ = n_IntegralError[DYtoTauTau]*n_IntegralError[DYtoTauTau];
     Int_DYtoTauTauEntries+ = n_IntegralNorm[DYtoTauTau];
  }
  for(int DYtoEE =0; DYtoEE< 10; DYtoEE++){
     DYtoEEEntries+ = h_mc[DYtoEE]->Integral(binxmin,binxmax);
     Err_DYtoEEEntries+ = n_IntegralError[DYtoEE]*n_IntegralError[DYtoEE];
     Int_DYtoEEEntries+ = n_IntegralNorm[DYtoEE];
  }
  for(int diboson = 18; diboson < 21; diboson++){                                                                                                  dibosonentries+ = h_mc[diboson]->Integral(binxmin,binxmax);
     Err_dibosonentries+ = n_IntegralError[diboson]*n_IntegralError[diboson];
     Int_dibosonentries+ = n_IntegralNorm[diboson];
  }

  ttbarEntries = h_mc[21]->Integral(binxmin,binxmax);
  Err_ttbarEntries = n_IntegralError[21]*n_IntegralError[21];
  Int_ttbarEntries = n_IntegralNorm[21];
 
  totalMC = Int_DYtoEEEntries + Int_wjetsEntries + Int_dibosonentries + Int_ttbarEntries +Int_DYtoTauTauEntries;
//totalMC = DYtoEEEntries + wjetsEntries + dibosonentries + ttbarEntries +DYtoTauTauEntries;
  Err_totalMC = Err_DYtoEEEntries + Err_wjetsEntries + Err_dibosonentries + Err_ttbarEntries + Err_DYtoTauTauEntries;  



  ratioDataMC = h_data->Integral(binxmin,binxmax)/(totalMC); 
  ratioSB    = DYtoEEEntries/(totalMC);

  std::mout               
  <<"HISTPATH_HISTNAME"                                                   << "   &   " 
  << n_Integral_data                                                      << "   &   " 
  << int(Int_DYtoEEEntries)      << " $\\pm$" << int(TMath::Sqrt(Err_DYtoEEEntries))      << "   &   "
  << int(Int_DYtoTauTauEntries)  << " $\\pm$" << int(TMath::Sqrt(Err_DYtoTauTauEntries))  << "   &   " 
  << int(Int_dibosonentries)     << " $\\pm$" << int(TMath::Sqrt(Err_dibosonentries))     << "   &   "
  << int(Int_ttbarEntries)       << " $\\pm$" << int(TMath::Sqrt(Err_ttbarEntries))       << "   &   " 
  << int(Int_wjetsEntries)       << " $\\pm$" << int(TMath::Sqrt(Err_wjetsEntries))       << "   &   "
  << int(totalMC)                << " $\\pm$" << int(TMath::Sqrt(Err_totalMC))            << "   &   "
  //<< ratioDataMC                                                          << "   \   "
  //<<Stackhist->Integral(binxmin,binxmax) << "  \   "
  <<std::endl;
//=========================================================================

}
 
 c12->Draw();
 c12->SaveAs(DirPreName+dirpathname +"/DYPdf/HISTPATH_HISTNAME.pdf");
 c12->SaveAs(DirPreName+dirpathname +"/DYPng/HISTPATH_HISTNAME.png");
 c12->SaveAs(DirPreName+dirpathname +"/DYROOT/HISTPATH_HISTNAME.root");                                                                         }
