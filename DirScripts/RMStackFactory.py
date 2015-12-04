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

 TString DirPreName = "PlotsRaman_VeniceConf";
 dirpathname.Form("%d%1.2d%d",ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);

 system("mkdir -p  " + DirPreName +"/DYROOT");
 system("mkdir -p  " + DirPreName +"/DYPdf");
 system("mkdir -p  " + DirPreName +"/DYPng");

  
 
 ofstream mout;
 mout.open(DirPreName +"/"+dirpathname +"Limit.txt",std::ios::app);


//gROOT->ProcessLine(".L /afs/hep.wisc.edu/cms/khurana/Monika/CMSSW_7_4_5/src/RKGlobalAnalyzer/tdrstyle.C");
//setTDRStyle();
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);
gStyle->SetFrameLineWidth(3);
gStyle->SetErrorX(0);
gStyle->SetLineWidth(1);

//Provide luminosity of total data
float lumi = 71.3; // It will print on your plots too

std::vector<TString> filenameString;
//Change here Directories of the file
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/MonoHFatJetAnalysis_AllMCWithPU_V3/");
TString filenamepath_old("/afs/hep.wisc.edu/cms/khurana/DMRunII/CMSSW_7_4_5/src/RKGlobalAnalyzer/RootFiles/MonoHFatJet_9/");
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
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-100To200_13TeV-madgraph-runallAnalysis.root");

//Raman ZH background 7                                                                                                                       
filenameString.push_back(filenamepath + "Merged_ZH_HToBB_ZToNuNu_M120_13TeV_amcatnloFXFX_madspin_pythia8-runallAnalysis.root"); 
//filenameString.push_back(filenamepath + "Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-runallAnalysis.root");
//Raman Signal Sample 8-14
//filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-600GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-800GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-1000GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-1200GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-1400GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-1700GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-2000GeV_MA0-300GeVTreeMaker_0919.root");
filenameString.push_back(filenamepath + "runallAnalysis-Merged_crab_MonoHToBBarMZp-2500GeV_MA0-300GeVTreeMaker_0919.root");

//DYJets High pt DYSample 15,16,17,18
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-100To200_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-200To400_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-400To600_13TeV-madgraph-runallAnalysis.root");
filenameString.push_back(filenamepath + "Merged_ZJetsToNuNu_HT-600ToInf_13TeV-madgraph-runallAnalysis.root");


//filenameString.push_back(filenamepath_old + "Merged_DYJetsToLL_M-50_HT-100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath_old + "Merged_DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath_old + "Merged_DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");
//filenameString.push_back(filenamepath_old + "Merged_DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-runallAnalysis.root");


 

                                                                   
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
float scalexs=1.; 
Xsec[8]  = scalexs *0.02881  ;//800
Xsec[9]  = scalexs *0.02337 ;//1000
Xsec[10] = scalexs *0.01832 ; //1200
Xsec[11] = scalexs *0.01359 ; //1400
Xsec[12] = scalexs *0.00871 ; //1700
Xsec[13] = scalexs *0.00561 ; //2000
Xsec[14] = scalexs *0.00280 ; //2500

Xsec[15] = 280.47; // Znunu HT
Xsec[16] = 78.36; // Znunu HT
Xsec[17] = 10.94; // Znunu HT
Xsec[18] = 4.203;  // Znunu HT

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
 normalization[i]     = (lumi* Xsec[i])/(h_total->Integral());
 //cout<<"normalization :" << normalization[i] << std::endl;
 h_mc[i]->Rebin(REBIN); 
 h_mc[i]->Scale(normalization[i]);  
 //mout << filenameString[i] <<  "  &  " << Xsec[i] <<"  &  " << std::endl; 
// cout << "Integral : " << h_total->Integral() << "  Entries :  " << h_total->GetEntries() << std::endl;                                         

 }

fIn = new TFile(filenameString[nfiles-1],"READ");
h_data = (TH1F*) fIn->Get(histnameString);
h_data->Rebin(REBIN);
h_data->Sumw2();

 //Legend
 TLegend* legend = new TLegend(0.23, 0.78, 0.80,0.88,NULL,"brNDC");
// TLegend *legend = new TLegend(0.73, 0.68, 0.95,0.92,NULL,"brNDC");
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(22);
 legend->SetTextSize(0.040);
 legend->SetNColumns(3);
 legend->AddEntry(h_data,"Data","p");                            
 legend->AddEntry(h_mc[5],"t#bar{t}","f");
 legend->AddEntry(h_mc[1],"WJets","f");                           
 legend->AddEntry(h_mc[15],"Z#nu#nu+Jets","f");
 legend->AddEntry(h_mc[7],"ZH","f");
 legend->AddEntry(h_mc[2],"Diboson","f");                                                                                                      
 legend->AddEntry(h_mc[8],"M800", "l");
 legend->AddEntry(h_mc[9],"M1000", "l");
 legend->AddEntry(h_mc[10],"M1200", "l"); 
 
 //legend->AddEntry(h_mc[6],"QCD","f");
 

 
//===========================Latex=================//
TString latexnamepre= "CMS Preliminary, #sqrt{s} = 13 TeV #scale[0.45]{#int}L = ";
TString latexnamemiddle;
latexnamemiddle.Form("%1.1f",lumi); 
TString latexnamepost = " pb^{-1}";
TString latexname = latexnamepre+latexnamemiddle+latexnamepost;  
 TLatex *t2a = new TLatex(0.5,0.93,latexname);
// TLatex *t2a = new TLatex(0.5,0.97,"CMS Work In progress, #sqrt{s} = 13 TeV #scale[0.45]{#int}L = 5.73 pb^{-1}");
 t2a->SetTextSize(0.04);
 t2a->SetTextAlign(22);
 t2a->SetNDC(kTRUE);
 t2a->SetTextFont(22);

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

h_mc[1]->SetFillColor(kOrange+4);                                                                                                            
h_mc[1]->SetLineColor(kOrange+4);

h_mc[6]->SetFillColor(kGreen);
h_mc[6]->SetLineColor(kGreen);

/*
for(int qcd = 6; qcd < 7 ; qcd++){ 
h_mc[qcd]->SetFillColor(kOrange+4);                                                                                                            
h_mc[qcd]->SetLineColor(kOrange+4);
}*/

h_mc[8]->SetLineColor(kBlack);
h_mc[8]->SetLineWidth(3);
h_mc[9]->SetLineColor(kGreen);
h_mc[9]->SetLineWidth(3);
h_mc[10]->SetLineColor(kRed);
h_mc[10]->SetLineWidth(3);



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
hs->Add(h_mc[1]);
hs->Add(h_mc[5]);

h_data->SetMarkerColor(kBlack);
h_data->SetMarkerStyle(20);
float maxi = h_data->GetMaximum();

//Setting canvas without log axis
c12->SetLogy(0);

  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.99);
  c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->Draw();
  c1_2->cd();
  hs->Draw("hist"); 
  h_data->SetLineColor(1);
  h_data->Draw("same p e1");

   
  hs->SetMinimum(0.1);
  if(!ISLOG) hs->SetMaximum(maxi *1.2);
  if(ISLOG) hs->SetMaximum(maxi *10);
  //if(!ISLOG) hs->SetMaximum(0.4);

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
  hs->GetXaxis()->SetRangeUser(XMIN,XMAX);
  hs->GetXaxis()->SetNdivisions(508);
  
  legend->Draw("same"); 
  t2a->Draw("same");
  if(nminus = =1){tt->Draw("same");}
  h_mc[8]->Draw("hist same ");
  h_mc[9]->Draw("hist same");
  h_mc[10]->Draw("hist same");


if(TEXTINFILE){ 
   
//=======================================================================
  //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets
 TAxis *xaxis = h_mc[0]->GetXaxis();
 Int_t binxmin = xaxis->FindBin(XMIN);
 Int_t binxmax = xaxis->FindBin(XMAX);

  float qcdEntries =0.0, dibosonentries =0.0;
//  for(int qcd = 6; qcd < 22 ; qcd++){                                                                                   
//    qcdEntries+ = h_mc[qcd]->GetBinContent(5);}

  for(int diboson = 2; diboson < 5; diboson++){                                                                                                  dibosonentries+ = h_mc[diboson]->GetBinContent(5);}                                                    
                                     
  mout << "HISTPATH_HISTNAME"            << std::endl; 
  mout << " DATA "    << h_data->GetBinContent(5)  << std::endl; 
//  mout << " DYJETS "  << h_mc[0]->GetBinContent(5) << std::endl; 
  mout << " DIBOSON " << dibosonentries                     << std::endl;
  mout << " TT "      << h_mc[5]->GetBinContent(5) << std::endl; 
  mout << " WJETS "   << h_mc[1]->GetBinContent(5) << std::endl;
  mout << " ZH "      << h_mc[7]->GetBinContent(5) << std::endl;
  mout << " DYJETS"<<h_mc[15]->GetBinContent(5)+h_mc[16]->GetBinContent(5)+h_mc[17]->GetBinContent(5)+h_mc[18]->GetBinContent(5) << std::endl;  
  mout << " M800 "    << h_mc[8]->GetBinContent(5) << std::endl;
  mout << " M1000 "    << h_mc[9]->GetBinContent(5) << std::endl;
  mout << " M1200 "    << h_mc[10]->GetBinContent(5) << std::endl;
  mout << " M1400 "    << h_mc[11]->GetBinContent(5) << std::endl;
  mout << " M1700 "   << h_mc[12]->GetBinContent(5) << std::endl;
  mout << " M2000 "   << h_mc[13]->GetBinContent(5) << std::endl;
  mout << " M2500 "   << h_mc[14]->GetBinContent(5) << std::endl;
  mout << " QCD "     << h_mc[6]->GetBinContent(5) <<  std::endl;
  mout << "======================================================" <<std::endl;
//=========================================================================

}
 
 c12->Draw();
 c12->SaveAs(DirPreName +"/DYPdf/HISTPATH_HISTNAME.pdf");
 c12->SaveAs(DirPreName +"/DYPng/HISTPATH_HISTNAME.png");
 c12->SaveAs(DirPreName +"/DYROOT/HISTPATH_HISTNAME.root");                                                                         }
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
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here

## Plots After Pre-selection
makeplot(['CutFlowAndEachCutFatJet', 'h_cutflow_0_f', 'Cut Flow', '0','5', '1', '1','1'])
makeplot(['MonoHFatJetsPreselection','h_nMuons0','N_{add. #mu}','0','5','1','0'])
makeplot(['MonoHFatJetsPreselection','h_nElectrons0','N_{add. e}','0','5','1','0'])
makeplot(['MonoHFatJetsPreselection','h_nJetss0','N_{add. Jets}','0','5','1','0']) 
makeplot(['MonoHFatJetsPreselection','h_MET0','MET','200','600','2','0'])
makeplot(['MonoHFatJetsPreselection','h_Mjj0','M_{SD}','60','200','1','0','1']) 
makeplot(['MonoHFatJetsPreselection','h_pTjj0','p_{T}^{AK8Jet}','100','600','2','0'])
makeplot(['MonoHFatJetsPreselection','h_h_Tau21jj0','#tau_{21}','0','1','1','0'])
makeplot(['MonoHFatJetsPreselection','h_CSVSum0','CSV','0','1','1','0'])
makeplot(['MonoHFatJetsPreselection','h_phijj0','#phi_{AK8Jet}','-3.5','3.5','5','0'])
makeplot(['MonoHFatJetsPreselection','h_etajj0','#eta_{AK8Jet}','-2.5','2.5','5','0'])
makeplot(['MonoHFatJetsPreselection','h_nTaus0','N_{#tau}','0','5','1','0'])
makeplot(['MonoHFatJetsPreselection','h_dPhi_bb_MET0','#Delta#phi_{AK8Jet-MET}','2.','3.5','2','0'])
makeplot(['MonoHFatJetsPreselection','h_MT_bb_MET0', 'M_{T}', '200','1000', '10','0'])
####

makeplot(['MonoHFatJetsPreselection','h_DRSJ0' ,'#DeltaR(sub-jets)', '0','1','1','0'])
makeplot(['MonoHFatJetsPreselection','h_CSVMin0','CSV_{min}', '0','1','1','0'])
makeplot(['MonoHFatJetsPreselection','h_CSVMax0','CSV_{max}', '0','1','1','0'])
makeplot(['MonoHFatJetsPreselection','h_nFJets0','N_{add.}^{fatJets}','0','5','1','0'])
makeplot(['CutFlowAndEachCutFatJet_2subj','h_cutflow_0_f','Cut Flow', '0','5', '1', '1','1']) 
makeplot(['CutFlowAndEachCutFatJet_1subj','h_cutflow_0_f','Cut Flow', '0','5', '1', '1','1'])
makeplot(['CutFlowAndEachCutFatJet_DRsubj','h_cutflow_0_f','Cut Flow', '0','5', '1', '1','1'])
####
####
## N-1 Plots.
####makeplot(['NMinusOne','h_FatJetpTapteta','p_{T}^{AK8Jet}','180','700','1','0'])
####makeplot(['NMinusOne','h_FatJetCSVbcsv','CSV','0','1','5','0'])
####makeplot(['NMinusOne','h_DPhiFatJetMETcDPHIJetMet','#Delta#phi_{AK8Jet-MET}','0','3.5','2','0'])
####makeplot(['NMinusOne','h_MSoftDropdMjet','M_{SD}','0','200','5','0'])
####makeplot(['NMinusOne','h_METemetpt','MET','0','1000','10','0'])
####
#makeplot(['MonoHFatJetsPreselection','','','','','',''])


