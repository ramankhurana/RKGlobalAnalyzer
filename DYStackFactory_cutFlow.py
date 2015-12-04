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

 TString DirPreName = "DoubleEle_crosscheck_new";
 dirpathname.Form("%d%1.2d%d",ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
 system("mkdir -p  " + DirPreName+dirpathname +"/DYROOT");
 system("mkdir -p  " + DirPreName+dirpathname +"/DYPdf");
 system("mkdir -p  " + DirPreName+dirpathname +"/DYPng");
 
 ofstream mout;
 mout.open(DirPreName+dirpathname +"/"+dirpathname +".txt",std::ios::app);


gROOT->ProcessLine(".L ~/Downloads/tdrstyle.C");
setTDRStyle();
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);
gStyle->SetFrameLineWidth(3);
gStyle->SetErrorX(0);
gStyle->SetLineWidth(1);

//Provide luminosity of total data
//float lumi = 7.342 ;// It will print on your plots too
 float lumi = 40.028;

std::vector<TString> filenameString;

filenameString.push_back("OutputRootFile/analysis.root");                

TString histnameString("HISTNAME");

TFile *fIn;
const int nfiles = (int) filenameString.size();

//check it once
float Xsec[nfiles];
Xsec[0] = 6025;                                                               


TH1F* h_mc[nfiles] ;
float normalization[nfiles];


for(int i =0; i<(int)filenameString.size()-1; i++){
 fIn = new TFile(filenameString[i],"READ");
 h_mc[i] = (TH1F*) fIn->Get(histnameString);
 h_total      = (TH1F*) fIn->Get("nEvents_weight");
 normalization[i]     = (lumi* Xsec[i])/(h_total->Integral());
 cout<<"normalization :" << normalization[i] << std::endl;
//h_mc[i]->Scale(normalization[i]);  
 h_mc[i]->Rebin(REBIN);
 cout << i << "&" << Xsec[i] <<"&" << h_total->GetEntries() << "\\\\\" <<std::endl; 
 }



 //Legend
 TLegend *legend = new TLegend(0.73, 0.68, 0.95,0.92,NULL,"brNDC");
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(22);
 legend->SetTextSize(0.05);
 legend->SetNColumns(1);

 legend->AddEntry(h_mc[0],"DY#rightarrow ee","f");

 
//===========================Latex=================//
TString latexnamepre= "CMS Very Preliminary, #sqrt{s} = 13 TeV #scale[0.45]{#int}L = ";
TString latexnamemiddle;
latexnamemiddle.Form("%1.2f",lumi); 
TString latexnamepost = " pb^{-1}";
TString latexname = latexnamepre+latexnamemiddle+latexnamepost;  
TLatex *t2a = new TLatex(0.5,0.97,latexname);
// TLatex *t2a = new TLatex(0.5,0.97,"CMS Very Preliminary, #sqrt{s} = 13 TeV #scale[0.45]{#int}L = 5.73 pb^{-1}");
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
h_mc[0]->SetFillColor(kTeal-8);
h_mc[0]->SetLineColor(kTeal-8);


hs->Add(h_mc[0]);





//Setting canvas without log axis
c12->SetLogy(0);

  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.99);
  c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->Draw();
  c1_2->cd();
  hs->Draw("hist"); 

  
  hs->SetMinimum(0.1);
  if(!ISLOG) hs->SetMaximum(maxi *1.22);
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


if(TEXTINFILE){ 
   
//=======================================================================
  //Calculating the contribution of each background in particular range
 // As Data DY(ee) diboson TTjets WWJets
 TAxis *xaxis = h_mc[0]->GetXaxis();
// Int_t binxmin = xaxis->FindBin(XMIN);
// Int_t binxmax = xaxis->FindBin(XMAX);

 Int_t binxmin = XMIN;
 Int_t binxmax = XMAX;



                                     
  mout <<"HISTPATH_HISTNAME"            << "   &   " 
  //<< setprecision(0)

  << (int)h_mc[0]->GetBinContent(binxmax) << "   &   " 
 
  <<std::endl;
//=========================================================================

}

 h_data->Draw("text"); 
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
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here
makeplot(['abc','h_CutFlow', 'cutFlow', '1', '8', '1', '1']);
makeplot(['abc ','h_CutFlow', 'cutFlow', '1', '2', '1', '1' ,'1', 'Total']);
makeplot(['abc','h_CutFlow', 'cutFlow', '2', '3', '1', '1' ,'1', 'NEle']);
makeplot(['abc','h_CutFlow', 'cutFlow', '3', '4', '1', '1' ,'1', 'Trigger']);
makeplot(['abc','h_CutFlow', 'cutFlow', '4', '5', '1', '1' ,'1', 'kinematic']);
makeplot(['abc','h_CutFlow', 'cutFlow', '5', '6', '1', '1' ,'1', 'MediumID']);
makeplot(['abc','h_CutFlow', 'cutFlow', '6', '7', '1', '1' ,'1', 'Charge']);
makeplot(['abc','h_CutFlow', 'cutFlow', '7', '8', '1', '1' ,'1', 'ZMasscut']);


##makeplot(['Electron_NoCut_','h_nVtx', '# of vertices', '0', '50', '1', '0','0' ])

##makeplot(['DiElectronMediumID', 'h_InvMass', 'M_{ee}', '0', '400', '6', '0', '1' ,'fullrange' ])
###makeplot(['DiElectronMediumID',  'h_InvMass', 'M_{ee}', '60', '120', '3', '0' , '1'])
####makeplot(['DiElectronMediumID',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
####makeplot(['DiElectronMediumID',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
####makeplot(['DiElectronMediumID',   'h_rapidity', 'Rapidity_{ee}', '-3.5', '3.5' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_energy','energy_{ee}','0','800','1','1'])
####makeplot(['DiElectronMediumID',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
####makeplot(['DiElectronMediumID',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
########

####makeplot(['DiElectronMediumIDIso', 'h_InvMass', 'M_{ee}', '0', '400', '6', '1', '1', 'fullrange' ])
####makeplot(['DiElectronMediumIDIso',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ,'1'])
####makeplot(['DiElectronMediumIDIso',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_eta', '#eta_{ee} ', '-5.', '5' , '2', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_energy','energy_{ee}','0','800','1','1'])
####makeplot(['DiElectronMediumIDIso',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
####

####makeplot(['Electron_NoCut_',   'h_pt4', 'p_{T}^{e} ', '0', '500' , '2', '1' ])
####makeplot(['Electron_NoCut_',   'h_eta4', '#eta^{e} ', '-3', '3' , '2', '1' ])
####makeplot(['Electron_NoCut_',   'h_phi4', '#phi^{e} ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_etSC4', 'E_{T}^{SC}', '0', '500','1','1'])
####makeplot(['Electron_NoCut_',   'h_dEtaIn4', '#Delta#eta_{In} ', '0', '0.01' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_dPhiIn1', '#Delta#phi_{In} ', '0', '0.08' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_hOverE4', 'H/E', '0', '0.1' , '2', '1' ])
####makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5} ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_eoverPInv4', 'E/P(Inv) ', '0', '0.25' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoRho4', 'Isolation(#rho) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_d04', 'd_{0} ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_dz4', 'd_{z} ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_passConversionVeto4', 'ConversionVeto ', '0', '2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_nelectrons', 'N_{ele}', '1', '6' , '1', '1','1' ])
####

####makeplot(['Electron_NoCut_Barrel_',   'h_pt4', 'p_{T}^{e}(barrel) ', '0', '500' , '2', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eta4', '#eta^{e}(barrel) ', '-3', '3' , '2', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_phi4', '#phi^{e}(barrel) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_etSC4', 'E_{T}^{SC}(barrel)', '0', '500','1','1'])
####makeplot(['Electron_NoCut_Barrel_',   'h_dEtaIn4', '#Delta#eta_{In}(barrel) ', '0', '0.01' , '5', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dPhiIn4', '#Delta#phi_{In}(barrel) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_hOverE4', 'H/E(barrel)', '0', '0.1' , '2', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5}(barrel) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eoverPInv4', 'E/P(Inv)(barrel) ', '0', '0.25' , '4', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)(barrel)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_isoRho4', 'Isolation(#rho)(barrel) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_d04', 'd_{0}(barrel) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dz4', 'd_{z}(barrel) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits(barrel) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_passConversionVeto4', 'ConversionVeto(barrel) ', '0', '2' , '1', '1' ])
####
####makeplot(['Electron_NoCut_Endcap_',   'h_pt4', 'p_{T}^{e}(endcap) ', '0', '500' , '2', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_eta4', '#eta^{e}(endcap) ', '-3', '3' , '2', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_phi4', '#phi^{e}(endcap) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_etSC4', 'E_{T}^{SC}(endcap)', '0', '500','1','1'])
####makeplot(['Electron_NoCut_Endcap_',   'h_dEtaIn4', '#Delta#eta_{In}(endcap) ', '0', '0.01' , '5', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dPhiIn4', '#Delta#phi_{In}(endcap) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_hOverE4', 'H/E(endcap)', '0', '0.1' , '2', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5}(endcap) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_eoverPInv4', 'E/P(Inv)(endcap) ', '0', '0.25' , '4', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)(endcap)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_isoRho4', 'Isolation(#rho)(endcap) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_d04', 'd_{0}(endcap) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dz4', 'd_{z}(endcap) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits(endcap) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_passConversionVeto4', 'ConversionVeto(endcap) ', '0', '2' , '1', '1' ])
####

####makeplot(['Electron_NoCut_',   'h_pt1', 'p_{T}^{e}(sub-leading)   ', '0', '500' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_eta1', '#eta^{e}(sub-leading) ', '-3', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_phi1', '#phi^{e}(sub-leading) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_etSC1', 'E_{T}^{SC}(sub-leading)', '0', '500','1','1'])
####makeplot(['Electron_NoCut_',   'h_dEtaIn1', '#Delta#eta_{In}(sub-leading) ', '0', '0.01' , '5', '1' ])
####makeplot(['Electron_NoCut_',   'h_dPhiIn1', '#Delta#phi_{In}(sub-leading) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_',   'h_hOverE1', 'H/E(sub-leading)', '0', '0.1' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta1', '#sigma_{i#eta i#eta}^{5x5}(sub-leading) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_eoverPInv1', 'E/P(Inv)(sub-leading) ', '0', '0.25' , '8', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoDeltaBeta1', ' Isolation(#Delta#beta)(sub-leading)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoRho1', 'Isolation(#rho)(sub-leading) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_d01', 'd_{0}(sub-leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_dz1', 'd_{z}(sub-leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits1', 'ExpextedMissingInnerHits(sub-leading) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_passConversionVeto1', 'ConversionVeto(sub-leading) ', '0', '2' , '1', '1' ])
####
####makeplot(['Electron_NoCut_',   'h_pt0', 'p_{T}^{e}(leading) ', '0', '500' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_eta0', '#eta^{e}(leading) ', '-3', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_phi0', '#phi^{e}(leading) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_etSC0', 'E_{T}^{SC}(leading)', '0', '500','1','1'])
####makeplot(['Electron_NoCut_',   'h_dEtaIn0', '#Delta#eta_{In}(leading) ', '0', '0.01' , '5', '1' ])
####makeplot(['Electron_NoCut_',   'h_dPhiIn0', '#Delta#phi_{In}(leading) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_',   'h_hOverE0', 'H/E(leading)', '0', '0.1' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta0', '#sigma_{i#eta i#eta}^{5x5}(leading) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_eoverPInv0', 'E/P(Inv)(leading) ', '0', '0.25' , '8', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoDeltaBeta0', ' Isolation(#Delta#beta)(leading)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoRho0', 'Isolation(#rho)(leading) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_d00', 'd_{0}(leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_dz0', 'd_{z}(leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits0', 'ExpextedMissingInnerHits(leading) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_passConversionVeto0', 'ConversionVeto(leading) ', '0', '2' , '1', '1' ])
####
####
####makeplot(['ElectronNMinus1B', 'h_IdEtaIn_aDEtaIn', '#Delta#eta_{In}(barrel)', '0', '0.01' , '5', '1'])
####makeplot(['ElectronNMinus1B', 'h_IdPhiIn_bDPhiIn', '#Delta#phi_{In}(barrel) ', '0', '0.08' , '8', '1' ])
####makeplot(['ElectronNMinus1B', 'h_Idfull5x5_sigmaIetaIeta_cSigmaIetaIetaFull','#sigma_{i#eta i#eta}^{5x5}(barrel) ', '0', '0.06' , '1', '1' ]) 
####makeplot(['ElectronNMinus1B', 'h_IdhOverE_dHOverE','H/E(barrel)', '0', '0.1' , '4', '1' ])
####makeplot(['ElectronNMinus1B', 'h_Idd0_eD0','d_{0}(barrel) ', '0', '0.2' , '1', '1' ])
####makeplot(['ElectronNMinus1B', 'h_Iddz_fDz','d_{z}(barrel) ', '0', '0.2' , '1', '1' ])
####makeplot(['ElectronNMinus1B', 'h_IdeoverPInv_gEInvP','E/P(Inv)(barrel) ', '0', '0.25' , '8', '1' ]) 
####makeplot(['ElectronNMinus1B', 'h_IdisoRho_hRhoIsolation','Isolation(#rho)(barrel) ', '0', '0.4' , '1', '1' ])
####makeplot(['ElectronNMinus1B', 'h_IdexpectedMissingInnerHits_iExpMissingHits','ExpextedMissingInnerHits(barrel) ', '0', '5' , '1', '1' ])
####makeplot(['ElectronNMinus1B', 'h_IdpassConversionVeto_jConversionVeto','ConversionVeto(barrel) ', '0', '2' , '1', '1' ])
####
####
####
####makeplot(['ElectronNMinus1E', 'h_IdEtaIn_aDEtaIn', '#Delta#eta_{In}(endcap)', '0', '0.01' , '5', '1'])
####makeplot(['ElectronNMinus1E', 'h_IdPhiIn_bDPhiIn', '#Delta#phi_{In}(endcap) ', '0', '0.08' , '8', '1' ])
####makeplot(['ElectronNMinus1E', 'h_Idfull5x5_sigmaIetaIeta_cSigmaIetaIetaFull','#sigma_{i#eta i#eta}^{5x5}(endcap)) ', '0', '0.06' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdhOverE_dHOverE','H/E(endcap)', '0', '0.1' , '4', '1' ])
####makeplot(['ElectronNMinus1E', 'h_Idd0_eD0','d_{0}(endcap) ', '0', '0.2' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_Iddz_fDz','d_{z}(endcap) ', '0', '0.2' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdeoverPInv_gEInvP','E/P(Inv)(endcap) ', '0', '0.25' , '8', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdisoRho_hRhoIsolation','Isolation(#rho)(endcap) ', '0', '0.4' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdexpectedMissingInnerHits_iExpMissingHits','ExpextedMissingInnerHits(endcap) ', '0', '5' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdpassConversionVeto_jConversionVeto','ConversionVeto(endcap) ', '0', '2' , '1', '1' ])
################
#makeplot(['Electron_NoCut_',   'h_pt0', 'p_{T}^{leading}(e) ', '0', '500' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eta0', '#eta^{e}^{leading} ', '-3', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_phi0', '#phi^{e}^{leading} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dEtaIn0', '#Delta#eta_{In}^{leading} ', '0', '0.01' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_dPhiIn0', '#Delta#phi_{In}^{leading} ', '0', '0.08' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_hOverE0', 'H/E^{leading}', '0', '0.1' , '2', '1' ])
#makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta0', '#sigma_{i#eta i#eta}^{5x5}(leading) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eoverPInv0', 'E/P(Inv)^{leading} ', '0', '0.25' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoDeltaBeta0', ' Isolation(#Delta#beta)^{leading}  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoRho0', 'Isolation(#Rho)^{leading} ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_d00', 'd_{0}^{leading} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dz0', 'd_{z}^{leading} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits0', 'ExpextedMissingInnerHits^{leading} ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_passConversionVeto0', 'ConversionVeto^{leading} ', '0', '2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_nelectrons3', 'N_{ele}', '0', '5' , '1', '1' ])



#makeplot(['Electron_NoCut_',   'h_pt0', 'p_{T}^{leading}(e) ', '0', '500' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eta0', '#eta^{e}^{leading} ', '-3', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_phi0', '#phi^{e}^{leading} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dEtaIn0', '#Delta#eta_{In}^{leading} ', '0', '0.01' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_dPhiIn0', '#Delta#phi_{In}^{leading} ', '0', '0.08' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_hOverE0', 'H/E^{leading}', '0', '0.1' , '2', '1' ])
#makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta0', '#sigma_{i#eta i#eta}^{5x5}(leading) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eoverPInv0', 'E/P(Inv)^{leading} ', '0', '0.25' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoDeltaBeta0', ' Isolation(#Delta#beta)^{leading}  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoRho0', 'Isolation(#Rho)^{leading} ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_d00', 'd_{0}^{leading} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dz0', 'd_{z}^{leading} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits0', 'ExpextedMissingInnerHits^{leading} ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_passConversionVeto0', 'ConversionVeto^{leading} ', '0', '2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_nelectrons3', 'N_{ele}', '0', '5' , '1', '1' ])

#makeplot(['Electron_NoCut_',   'h_pt1', 'p_{T}^{sub-leading}(e) ', '0', '500' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eta1', '#eta^{e}^{sub-leading} ', '-3', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_phi1', '#phi^{e}^{sub-leading} ', '-3.5', '3.5' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dEtaIn1', '#Delta#eta_{In}^{sub-leading} ', '0', '0.01' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_dPhiIn1', '#Delta#phi_{In}^{sub-leading} ', '0', '0.08' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_hOverE1', 'H/E^{sub-leading}', '0', '0.1' , '2', '1' ])
#makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta1', '#sigma_{i#eta i#eta}^{5x5}(sub-leading) ', '0', '0.06' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_eoverPInv1', 'E/P(Inv)^{sub-leading} ', '0', '0.25' , '4', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoDeltaBeta1', ' Isolation(#Delta#beta)^{sub-leading}  ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_isoRho1', 'Isolation(#Rho)^{sub-leading} ', '0', '0.4' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_d01', 'd_{0}^{sub-leading} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_dz1', 'd_{z}^{sub-leading} ', '0', '0.2' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits1', 'ExpextedMissingInnerHits^{sub-leading} ', '0', '3' , '1', '1' ])
#makeplot(['Electron_NoCut_',   'h_passConversionVeto1', 'ConversionVeto^{sub-leading} ', '0', '2' , '1', '1' ])








#makeplot(['Jet_NoCut_', 'h_pt_vec_0',        'p_{T}^{leading jet}',   '0' , '500',   '2' ,'1'])
#makeplot(['Jet_NoCut_', 'h_pt_vec_1',        'p_{T}^{sub-leading jet}',   '0' , '300',   '2','1'])
#makeplot(['Jet_NoCut_', 'h_B_CISVV2_vec_0', 'CSV^{leading jet}',     '0' , ' 1',    '1','0'])
#makeplot(['Jet_NoCut_', 'h_B_CISVV2_vec_1', 'CSV^{subleading jet}',  '0' , '1 ',    '1', '0'])
#makeplot(['MET_NoCut_',  'h_RawPt'  ,      'MET ' ,                 '0' , '2000',  '4','1'])
#makeplot(['MET_NoCut_',  'h_RawPhi'  ,     '#phi^{MET} ',         '-3.5', '3.5',  '1','0'])

#makeplot(['DiJetNotCut',  'h_DeltaR'  ,     '#Delta R_{bb} ' ,       '0' , '5', '1', '1'])
#makeplot(['DiJetNotCut',  'h_DeltaPhi'  ,   '#Delta#Phi_{bb} ' ,    '-3.5' , '-3.5', '2','1'])
#makeplot(['DiJetNotCut',  'h_InvMass'  ,    'M_{bb}' ,               '0 ' , '400' , '1','0'])
#makeplot(['DiJetNotCut',  'h_Pt2OverPt1'  , 'p_{T}^{b2}/p_{T}^{b1} ' ,  '0 ' , '1 ', '1','1'])
#makeplot(['DiJetNotCut',  'h_PtOverPt1Pt2', 'p_{T}^{bb}/p_{T}^{b1}+p_{T}^{b2} ' ,  '0 ' , '1 ','1','1'])
#makeplot(['DiJetNotCut',  'h_CSVSum'  ,     'CSV_{jet1}+CSV_{jet2}' ,  '0 ' , '2 ', '8','0'])


#makeplot(['DiJetMETNoCuts',  'h_DeltaPhi0'  ,  '#Delta#Phi{bb,MET} ' ,  '-3.5  ' , '3.5 ', '1' ,'1' ])
#makeplot(['DiJetMETNoCuts',  'h_TransMass0'  ,  'M_{T}^{bb,MET} ' ,  '0 ' , '2000 ', '4','1'])



#makeplot(['Jet_NoCut_',  ' '  ,  ' ' ,  ' ' , ' ', ' '])


#makeplot(['JetPreSel','h_nMuons0','N_{add. #mu}','0','5','1'])
#makeplot(['CutFlowAndEachCut','h_cutflow_0','cutflow','0','7','1'])
#makeplot(['JetPreSel','h_nElectrons0','N_{add. e}','0','5','1'])
#makeplot(['JetPreSel','h_nJetss0','N_{add. Jets}','0','5','1'])
#makeplot(['JetPreSel','h_Q1Q20','','0','5'])
#makeplot(['JetPreSel','h_MET0','MET','0','2000','4'])
#makeplot(['JetPreSel','h_Mjj0','M_{bb}','60','200','1'])
#makeplot(['JetPreSel','h_pTjj0','p_{T}^{H}','0','2000','4'])
#makeplot(['JetPreSel','h_CSVMax0','CSV_{max}','0','1','1'])
#makeplot(['JetPreSel','h_CSVMin0','CSV_{min}','0','1','1'])
#makeplot(['JetPreSel','h_CSVSum0','CSV_{sum}','0','2','1'])
#makeplot(['JetPreSel','h_M_vs_Q1Q20','N_{#mu}','0','5'])
#makeplot(['JetPreSel','h_MET_vs_Q1Q20','N_{#mu}','0','5'])
#makeplot(['JetPreSel','h_MET_vs_M0','N_{#mu}','0','5'])
#makeplot(['JetPreSel','h_dPhi_MET_J0','#Delta#phi{MET,J}','-3.5','3.5','2'])
