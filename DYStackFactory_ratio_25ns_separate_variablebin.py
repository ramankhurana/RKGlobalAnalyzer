import os
## Template macro is fed to a python variable
## 1.) Dir is created on DateBase 
## 2.) Starting Extension of your Dir..Like 
## in a day you want 2 directories jsut
## change the DirPreName
macro='''{
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
TString histnameString("HISTPATH/HISTNAME");

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
 h_rebin[i]              = (TH1F*) fIn->Get(histnameString);
 h_rebin[i]->Scale(normalization[i]);
 h_rebin[i]->Rebin(45,"hnew",massbin);
 h_mc[i]= (TH1F*)hnew->Clone();

  cout << filenameString[i] <<  "  &  "  <<  Xsec[i] <<"  &  " << h_total->GetEntries() <<  " & "   << h_total->Integral()  "\\\\\" <<std::endl; 
  cout<<"normalization :" << normalization[i] << std::endl;
 }

fIn = new TFile(filenameString[nfiles-1],"READ");

h_data_rebin = (TH1F*) fIn->Get(histnameString);
h_data_rebin->Rebin(45,"hnewdata",massbin);
h_data= (TH1F*)hnewdata->Clone();

 //Legend
 TLegend *legend;
 
 if(NORATIOPLOT){
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
//c12->SetLogx(1);
// Upper canvas declaration
 
  if(NORATIOPLOT){
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.993);
  }else{
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.29,1,0.974);
  c1_2->SetBottomMargin(0.03);
  }
 //c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->SetLogx(1);
  c1_2->Draw();
  c1_2->cd();
  hs->Draw("hist"); 
  h_data->SetLineColor(1);
  h_data->Draw("same p e1");
  
  if(ISLOG)    hs->SetMinimum(1);
  if(!ISLOG)   hs->SetMinimum(1);
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

  hs->GetYaxis()->SetTitle("Events");                                                                                                            hs->GetYaxis()->SetTitleSize(0.07);                                                                                                            hs->GetYaxis()->SetTitleOffset(0.9);                                                                                                           hs->GetYaxis()->SetTitleFont(22);
  hs->GetYaxis()->SetLabelFont(22);                                                                                                              hs->GetYaxis()->SetLabelSize(.07);   
  hs->GetXaxis()->SetRangeUser(XMIN,XMAX);                                                                                                       hs->GetXaxis()->SetNdivisions(508); 
  legend->Draw("same"); 
  t2a->Draw("same");
  t2b->Draw("same");
t2c->Draw("same");
  if(nminus = =1){tt->Draw("same");}

  
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
 c1_1->SetLogx(1);
 DataMC->GetXaxis()->SetRangeUser(XMIN,XMAX);
 DataMC->Draw("PE1");
 DataMC->SetMarkerStyle(20);
 DataMC->SetMarkerColor(1);
 DataMC->SetMinimum(0.7);
 DataMC->SetMaximum(1.8);
 DataMC->GetXaxis()->SetNdivisions(508);
 DataMC->GetYaxis()->SetNdivisions(503);
 c1_1->SetGridy();
 }

if(TEXTINFILE){ 
   
//=======================================================================
  //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets
 TAxis *xaxis = h_mc[0]->GetXaxis();
 Int_t binxmin = xaxis->FindBin(XMIN);
 Int_t binxmax = xaxis->FindBin(XMAX);

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
  <<"HISTPATH_HISTNAME"                 << "   &   " 
  << h_data->Integral(binxmin,binxmax)  << "   &   " 
  << h_mc[0]->Integral(binxmin,binxmax) + h_mc[7]->Integral(binxmin,binxmax) << "   &   "
  <<h_mc[8]->Integral(binxmin,binxmax)+h_mc[9]->Integral(binxmin,binxmax)  << "   &   " 
  << dibosonentries                     << "   &   "
  << h_mc[5]->Integral(binxmin,binxmax) << "   &   " 
  << h_mc[1]->Integral(binxmin,binxmax) << "   &   "
  << h_mc[7]->Integral(binxmin,binxmax) << "   &   "
  << totalMC                            << "   &   "
  << ratioDataMC                        << "   &   "
  <<Stackhist->Integral(binxmin,binxmax) << "  \\   "
  <<std::endl;
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
            
        if len(inputs) >10 :
            line = line.replace("VARIABLEBINS", inputs[10])
        else:
            line = line.replace("VARIABLEBINS", "0")

  
        #print line
        NewPlot.write(line)
    NewPlot.close()

    os.system('root -l -b -q  Plot.C')




makeplot(['DiElectronMediumID',  'h_InvMass', 'M_{ee}', '10', '3000',  '5', '1' , '1', 'fullrangelogvariableBin','0','0'])
#makeplot(['Charge',  'h_InvMass', 'M_{ee}', '60', '119', '1', '0' , '1', 'sel'])
#makeplot(['Charge',  'h_InvMass', 'M_{ee}', '0', '400',  '5', '1' , '0', 'fullrangelog'])
#makeplot(['Charge',  'h_InvMass', 'M_{ee}', '60', '120', '2', '1' , '0', 'sellog'])
#makeplot(['Charge',  'h_InvMass', 'M_{ee}', '10', '60', '2', '1' , '0', 'sel060'])
#makeplot(['Charge',  'h_InvMass', 'M_{ee}', '120', '300', '4', '1' , '0', 'sel120400'])
#
#makeplot(['Charge',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
#makeplot(['Charge',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['Charge',   'h_rapidity', 'Rapidity_{ee}', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Charge',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Charge',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['Charge',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['Charge',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#makeplot(['Charge',   'h_energy','energy_{ee}','0','800','1','1'])
#makeplot(['Charge',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
#makeplot(['Charge',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
#
######### Plots for electrons#####################
#makeplot(['Electron_NoCut_',   'h_pt4', 'p_{T}^{e} ', '0', '500' , '2', '1' ])
#makeplot(['Electron_NoCut_',   'h_etaSC4', '#eta^{e} ', '-3', '3' , '2', '0' ])
#makeplot(['Electron_NoCut_',   'h_phi4', '#phi^{e} ', '-3.5', '3.5' , '2', '0' ])
#makeplot(['Electron_NoCut_',   'h_etSC4', 'E_{T}^{SC}', '15', '500','1','1'])
#makeplot(['Electron_NoCut_',   'h_dEtaIn4', '#Delta#eta_{In} ', '0', '0.01' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_dPhiIn1', '#Delta#phi_{In} ', '0', '0.08' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_hOverE4', 'H/E', '0', '0.1' , '2', '1' ])
#makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5} ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eoverPInv4', 'E/P(Inv) ', '0', '0.25' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoRho4', 'Isolation(#rho) ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_d04', 'd_{0} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dz4', 'd_{z} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_passConversionVeto4', 'ConversionVeto ', '0', '2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_nelectrons', 'N_{ele}', '1', '5' , '1', '1','1' ])
#
#
#makeplot(['Electron_NoCut_',   'h_pt1', 'p_{T}^{e}(sub-leading)   ', '0', '500' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_etaSC1', '#eta^{e} ', '-3', '3' , '1', '0' ])
#makeplot(['Electron_NoCut_',   'h_phi1', '#phi^{e} ', '-3.5', '3.5' , '2', '0' ])
#makeplot(['Electron_NoCut_',   'h_etSC1', 'E_{T}^{SC}(sub-leading)', '15', '300','1','1'])
#makeplot(['Electron_NoCut_',   'h_dEtaIn1', '#Delta#eta_{In}(sub-leading) ', '0', '0.01' , '5', '1' ])
#makeplot(['Electron_NoCut_',   'h_dPhiIn1', '#Delta#phi_{In}(sub-leading) ', '0', '0.08' , '8', '1' ])
#makeplot(['Electron_NoCut_',   'h_hOverE1', 'H/E(sub-leading)', '0', '0.1' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta1', '#sigma_{i#eta i#eta}^{5x5}(sub-leading) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eoverPInv1', 'E/P(Inv)(sub-leading) ', '0', '0.25' , '8', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoDeltaBeta1', ' Isolation(#Delta#beta)(sub-leading)  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoRho1', 'Isolation(#rho)(sub-leading) ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_d01', 'd_{0}(sub-leading) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dz1', 'd_{z}(sub-leading) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits1', 'ExpextedMissingInnerHits(sub-leading) ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_passConversionVeto1', 'ConversionVeto(sub-leading) ', '0', '2' , '1', '1' ])
#
#makeplot(['Electron_NoCut_',   'h_pt0', 'p_{T}^{e}(leading) ', '0', '500' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_etaSC0', '#eta^{e}(leading) ', '-3', '3' , '1', '0' ])
#makeplot(['Electron_NoCut_',   'h_phi0', '#phi^{e}(leading) ', '-3.5', '3.5' , '2', '0' ])
#makeplot(['Electron_NoCut_',   'h_etSC0', 'E_{T}^{SC}(leading)', '15', '500','1','1'])
#makeplot(['Electron_NoCut_',   'h_dEtaIn0', '#Delta#eta_{In}(leading) ', '0', '0.01' , '5', '1' ])
#makeplot(['Electron_NoCut_',   'h_dPhiIn0', '#Delta#phi_{In}(leading) ', '0', '0.08' , '8', '1' ])
#makeplot(['Electron_NoCut_',   'h_hOverE0', 'H/E(leading)', '0', '0.1' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta0', '#sigma_{i#eta i#eta}^{5x5}(leading) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eoverPInv0', 'E/P(Inv)(leading) ', '0', '0.25' , '8', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoDeltaBeta0', ' Isolation(#Delta#beta)(leading)  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoRho0', 'Isolation(#rho)(leading) ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_d00', 'd_{0}(leading) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dz0', 'd_{z}(leading) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits0', 'ExpextedMissingInnerHits(leading) ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_passConversionVeto0', 'ConversionVeto(leading) ', '0', '2' , '1', '1' ])
##########
#
#
#
#makeplot(['DiElectronMediumID',  'h_InvMass', 'M_{ee}', '0', '3000', '6', '1', '1', 'fullrange' ])
#makeplot(['DiElectronMediumID',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ,'1'])
#makeplot(['DiElectronMediumID',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
#makeplot(['DiElectronMediumID',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['DiElectronMediumID',   'h_energy','energy_{ee}','0','800','1','1'])
#makeplot(['DiElectronMediumID',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['DiElectronMediumID',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['DiElectronMediumID',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['DiElectronMediumID',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#makeplot(['DiElectronMediumID',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
#makeplot(['DiElectronMediumID',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
#
#makeplot(['DiElectron_Barrel',  'h_InvMass', 'M_{ee}', '0', '3000', '6', '1', '1', 'fullrange' ])
#makeplot(['DiElectron_Barrel',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ,'1'])
#makeplot(['DiElectron_Barrel',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
#makeplot(['DiElectron_Barrel',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['DiElectron_Barrel',   'h_energy','energy_{ee}','0','800','1','1'])
#makeplot(['DiElectron_Barrel',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['DiElectron_Barrel',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['DiElectron_Barrel',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['DiElectron_Barrel',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#makeplot(['DiElectron_Barrel',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
#makeplot(['DiElectron_Barrel',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
#
#makeplot(['DiElectron_Endcap',  'h_InvMass', 'M_{ee}', '0', '3000', '6', '1', '1', 'fullrange' ])
#makeplot(['DiElectron_Endcap',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ,'1'])
#makeplot(['DiElectron_Endcap',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
#makeplot(['DiElectron_Endcap',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['DiElectron_Endcap',   'h_energy','energy_{ee}','0','800','1','1'])
#makeplot(['DiElectron_Endcap',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['DiElectron_Endcap',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['DiElectron_Endcap',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['DiElectron_Endcap',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#makeplot(['DiElectron_Endcap',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
#makeplot(['DiElectron_Endcap',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
#
#
#makeplot(['DiElectron_BarEnd',  'h_InvMass', 'M_{ee}', '0', '3000', '6', '1', '1', 'fullrange' ])
#makeplot(['DiElectron_BarEnd',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ,'1'])
#makeplot(['DiElectron_BarEnd',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_energy','energy_{ee}','0','800','1','1'])
#makeplot(['DiElectron_BarEnd',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
#makeplot(['DiElectron_BarEnd',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
#
#
#
#
#
#
#
#
#makeplot(['Electron_NoCut_Barrel',   'h_pt4', 'p_{T}^{e}(barrel) ', '0', '500' , '2', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_eta4', '#eta^{e}(barrel) ', '-3', '3' , '2', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_phi4', '#phi^{e}(barrel) ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_etSC4', 'E_{T}^{SC}(barrel)', '0', '500','1','1'])
#makeplot(['Electron_NoCut_Barrel',   'h_dEtaIn4', '#Delta#eta_{In}(barrel) ', '0', '0.01' , '5', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_dPhiIn4', '#Delta#phi_{In}(barrel) ', '0', '0.08' , '8', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_hOverE4', 'H/E(barrel)', '0', '0.1' , '2', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5}(barrel) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_eoverPInv4', 'E/P(Inv)(barrel) ', '0', '0.25' , '4', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)(barrel)  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_isoRho4', 'Isolation(#rho)(barrel) ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_d04', 'd_{0}(barrel) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_dz4', 'd_{z}(barrel) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits(barrel) ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_Barrel',   'h_passConversionVeto4', 'ConversionVeto(barrel) ', '0', '2' , '1', '1' ])
#
#makeplot(['Electron_NoCut_Endcap',   'h_pt4', 'p_{T}^{e}(endcap) ', '0', '500' , '2', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_eta4', '#eta^{e}(endcap) ', '-3', '3' , '2', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_phi4', '#phi^{e}(endcap) ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_etSC4', 'E_{T}^{SC}(endcap)', '0', '500','1','1'])
#makeplot(['Electron_NoCut_Endcap',   'h_dEtaIn4', '#Delta#eta_{In}(endcap) ', '0', '0.01' , '5', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_dPhiIn4', '#Delta#phi_{In}(endcap) ', '0', '0.08' , '8', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_hOverE4', 'H/E(endcap)', '0', '0.1' , '2', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5}(endcap) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_eoverPInv4', 'E/P(Inv)(endcap) ', '0', '0.25' , '4', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)(endcap)  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_isoRho4', 'Isolation(#rho)(endcap) ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_d04', 'd_{0}(endcap) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_dz4', 'd_{z}(endcap) ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits(endcap) ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_Endcap',   'h_passConversionVeto4', 'ConversionVeto(endcap) ', '0', '2' , '1', '1' ])
#####



#makeplot(['Charge',  'h_InvMass', 'M_{ee}', '0', '3000',  '5', '1' , '0', 'fullrangelog'])
##########Start Adding your plots here
####makeplot(['Electron_NoCut_','h_nVtx', '# of vertices', '0', '50', '1', '0','0' ])
####makeplot(['NEle', 'h_InvMass', 'M_{ee}', '0', '5000', '1', '1', '1', 'fullrange', '1' ])
####makeplot(['Trig', 'h_InvMass', 'M_{ee}', '0', '5000', '1', '0', '1' ])


####makeplot(['Kin', 'h_InvMass', 'M_{ee}', '0', '5000', '1', '0', '1' ])
####makeplot(['MID', 'h_InvMass', 'M_{ee}', '0', '5000', '1', '0', '1' ])
####makeplot(['Charge', 'h_InvMass', 'M_{ee}', '0', '5000', '1', '0', '1' ])
####makeplot(['DiElectronMediumID', 'h_InvMass', 'M_{ee}', '0', '400', '1', '0', '1' ,'fullrange' ])
####makeplot(['Charge',  'h_InvMass', 'M_{ee}', '60', '120', '1', '0' , '1', 'fullrange', '0'])
####makeplot(['Charge', 'h_InvMass', 'M_{ee}', '0', '400', '1', '0', '1' ,'fullrange' ])
####


###10-60

#makeplot(['NEle',  'h_InvMass', 'M_{ee}', '10', '60', '1', '0' , '1', 'sel'])
#makeplot(['NEle',  'h_InvMass', 'M_{ee}', '10', '60', '2', '1' , '0', 'sellog'])
#
#makeplot(['NEle',   'h_pt', 'p_{T}^{ee} ', '0 ', '350' , '8', '1' ])
#makeplot(['NEle',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['NEle',   'h_rapidity', 'Rapidity_{ee}', '-3.5', '3.5' , '1', '1' ])
#makeplot(['NEle',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['NEle',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['NEle',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['NEle',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#
####60-120
#
#makeplot(['Trig',  'h_InvMass', 'M_{ee}', '60', '120', '1', '0' , '1', 'sel'])
#makeplot(['Trig',  'h_InvMass', 'M_{ee}', '60', '120', '2', '1' , '0', 'sellog'])
#
#makeplot(['Trig',   'h_pt', 'p_{T}^{ee} ', '0 ', '350' , '8', '1' ])
#makeplot(['Trig',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['Trig',   'h_rapidity', 'Rapidity_{ee}', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Trig',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Trig',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['Trig',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['Trig',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#
### 120-300
#
#makeplot(['Kin',  'h_InvMass', 'M_{ee}', '120', '300', '1', '0' , '1', 'sel'])
#makeplot(['Kin',  'h_InvMass', 'M_{ee}', '120', '300', '2', '1' , '0', 'sellog'])
#
#makeplot(['Kin',   'h_pt', 'p_{T}^{ee} ', '0 ', '350' , '8', '1' ])
#makeplot(['Kin',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['Kin',   'h_rapidity', 'Rapidity_{ee}', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Kin',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Kin',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['Kin',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['Kin',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#
#### >300
#
#makeplot(['MID',  'h_InvMass', 'M_{ee}', '300', '1000', '1', '0' , '1', 'sel'])
#makeplot(['MID',  'h_InvMass', 'M_{ee}', '300', '1000', '2', '1' , '0', 'sellog'])
#
#makeplot(['MID',   'h_pt', 'p_{T}^{ee} ', '0 ', '350' , '8', '1' ])
#makeplot(['MID',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
#makeplot(['MID',   'h_rapidity', 'Rapidity_{ee}', '-3.5', '3.5' , '1', '1' ])
#makeplot(['MID',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['MID',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
#makeplot(['MID',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
#makeplot(['MID',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
#
#####full range 

###makePlot(['ElectronNMinus1B', 'h_IdEtaIn_aDEtaIn', '#Delta#eta_{In}(barrel)', '0', '0.01' , '5', '1'])
####makePlot(['ElectronNMinus1B', 'h_IdPhiIn_bDPhiIn', '#Delta#phi_{In}(barrel) ', '0', '0.08' , '8', '1' ])
####makePlot(['ElectronNMinus1B', 'h_Idfull5x5_sigmaIetaIeta_cSigmaIetaIetaFull','#sigma_{i#eta i#eta}^{5x5}(barrel) ', '0', '0.06' , '1', '1' ]) 
####makePlot(['ElectronNMinus1B', 'h_IdhOverE_dHOverE','H/E(barrel)', '0', '0.1' , '4', '1' ])
####makePlot(['ElectronNMinus1B', 'h_Idd0_eD0','d_{0}(barrel) ', '0', '0.2' , '1', '1' ])
####makePlot(['ElectronNMinus1B', 'h_Iddz_fDz','d_{z}(barrel) ', '0', '0.2' , '1', '1' ])
####makePlot(['ElectronNMinus1B', 'h_IdeoverPInv_gEInvP','E/P(Inv)(barrel) ', '0', '0.25' , '8', '1' ]) 
####makePlot(['ElectronNMinus1B', 'h_IdisoRho_hRhoIsolation','Isolation(#rho)(barrel) ', '0', '0.4' , '1', '1' ])
####makePlot(['ElectronNMinus1B', 'h_IdexpectedMissingInnerHits_iExpMissingHits','ExpextedMissingInnerHits(barrel) ', '0', '5' , '1', '1' ])
####makePlot(['ElectronNMinus1B', 'h_IdpassConversionVeto_jConversionVeto','ConversionVeto(barrel) ', '0', '2' , '1', '1' ])
########
####
####
####(['ElectronNMinus1E', 'h_IdEtaIn_aDEtaIn', '#Delta#eta_{In}(endcap)', '0', '0.01' , '5', '1'])
####(['ElectronNMinus1E', 'h_IdPhiIn_bDPhiIn', '#Delta#phi_{In}(endcap) ', '0', '0.08' , '8', '1' ])
####(['ElectronNMinus1E', 'h_Idfull5x5_sigmaIetaIeta_cSigmaIetaIetaFull','#sigma_{i#eta i#eta}^{5x5}(endcap)) ', '0', '0.06' , '1', '1' ])
####(['ElectronNMinus1E', 'h_IdhOverE_dHOverE','H/E(endcap)', '0', '0.1' , '4', '1' ])
####(['ElectronNMinus1E', 'h_Idd0_eD0','d_{0}(endcap) ', '0', '0.2' , '1', '1' ])
####(['ElectronNMinus1E', 'h_Iddz_fDz','d_{z}(endcap) ', '0', '0.2' , '1', '1' ])
####(['ElectronNMinus1E', 'h_IdeoverPInv_gEInvP','E/P(Inv)(endcap) ', '0', '0.25' , '8', '1' ])
####(['ElectronNMinus1E', 'h_IdisoRho_hRhoIsolation','Isolation(#rho)(endcap) ', '0', '0.4' , '1', '1' ])
####(['ElectronNMinus1E', 'h_IdexpectedMissingInnerHits_iExpMissingHits','ExpextedMissingInnerHits(endcap) ', '0', '5' , '1', '1' ])
####(['ElectronNMinus1E', 'h_IdpassConversionVeto_jConversionVeto','ConversionVeto(endcap) ', '0', '2' , '1', '1' ])
################
