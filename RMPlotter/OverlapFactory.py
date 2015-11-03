import os
## Template macro is fed to a python variable
macro='''{

gROOT->ProcessLine(".L ~/Downloads/tdrstyle.C");
setTDRStyle();
gStyle->SetOptStat(0);
gStyle->SetOptTitle(0);
gStyle->SetFrameLineWidth(3);
gStyle->SetErrorX(0);
gStyle->SetLineWidth(1);
// DYJets 1
//TTbar 2 ZH 4
// Signal 6



//Backround Files

// TFile s1("/home/monika/Desktop/Work/After_Phd/Inputfile/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-main.root");
// TFile s1("/home/monika/Desktop/Work/After_Phd/InputFile_3runs/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root");
// TFile s1("/home/monika/Desktop/Work/After_Phd/InputFile_17July/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8.root");
// TFile s1 ("/home/monika/Desktop/Work/After_Phd/InputFile_17July/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_2015_07_18_1.root");
TFile s1 ("/home/monika/Desktop/Work/After_Phd/DYAnalysis/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_2015_07_19-runallAnalysis.root");

 TH1F *bdt_s1 = (TH1F*) s1->Get("HISTPATH/HISTNAME");
 TH1F *nevents_s1 = (TH1F*) s1->Get("nEvents"); 

// TFile d1("/home/monika/Desktop/Work/After_Phd/Inputfile/Merged_SingleElectron-main.root");
//TFile d1("/home/monika/Desktop/Work/After_Phd/InputFile_3runs/Merged_SingleElectron.root");
//TFile d1("/home/monika/Desktop/Work/After_Phd/InputFile_17July/Merged_SingleElectron_2015_07_17_2.root");
TFile d1("/home/monika/Desktop/Work/After_Phd/DYAnalysis/Merged_SingleElectron_2015_07_19-runallAnalysis.root");
//TFile d1("/home/monika/Desktop/Work/After_Phd/InputFile_17July/Merged_SingleElectron_2015_07_18_1.root");

 TH1F *bdt_d1 = (TH1F*)d1->Get("HISTPATH/HISTNAME");
 TH1F *nevents_d1 = (TH1F*) d1->Get("nEvents");


 //3.042 pb -1 of data + 2.69
 //6104 pb
 double xs1 = (5.59*6104)/(nevents_s1->GetEntries());  

 bdt_s1->Scale(xs1);
                                                                                
 TLegend *legend = new TLegend(0.73, 0.78, 0.95,0.92,NULL,"brNDC");
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(22);
 legend->SetTextSize(0.05);
 legend->SetNColumns(1);
 legend->AddEntry(bdt_s1,"DY","f");
 legend->AddEntry(bdt_d1,"Data","p");
 /*
 legend->AddEntry(bdt_B3,"QCD","l");
 legend->AddEntry(bdt_B4,"TTJets","l");
 legend->AddEntry(bdt_B5,"WWJets", "l");
 legend->AddEntry(bdt_s1,"M600", "l");
 legend->AddEntry(bdt_s4,"M900", "l");
 legend->AddEntry(bdt_s6,"M1500", "l");
 */
 

//================================Latex=================//
 TLatex *t2a = new TLatex(0.5,0.97,"CMS Work In progress, #sqrt{s} = 13 TeV #scale[0.45]{#int}L = 5.73 pb^{-1}");
 t2a->SetTextSize(0.04);
 t2a->SetTextAlign(22);
 t2a->SetNDC(kTRUE);
 t2a->SetTextFont(22);
//THStack *hs = new THStack("hs","BDT");
//============== canvas declaration ===================
TCanvas *c12 = new TCanvas("Vertex Multiplicity ", "vertex Multiplicity"  , 0,0,500,500);
//
TPaveText *pave = new TPaveText(0.15,0.80,0.35,0.92,"brNDC");
                                                                      
                                                                                      
bdt_s1->Rebin(REBIN);
bdt_d1->Rebin(REBIN);                                                                                                  
                                                                                       

bdt_s1->SetFillColor(kTeal-8);
//bdt_s1->SetLineWidth(3);

bdt_d1->SetMarkerColor(kBlack);
bdt_d1->SetMarkerStyle(20);


float maxi = bdt_d1->GetMaximum();

c12->SetLogy(0);

  

  
  TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.99);
  c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->Draw();
  c1_2->cd();
  bdt_s1->Draw(); 
  bdt_d1->SetLineColor(1);
  bdt_d1->Draw("same p e1");
  
  bdt_s1->SetMinimum(0.1);
  if(!ISLOG) bdt_s1->SetMaximum(maxi *1.22);
  if(ISLOG) bdt_s1->SetMaximum(maxi *10);

 

 //if(!ISLOG) bdt_s1->SetMaximum(0.4);

  bdt_s1->GetXaxis()->SetTitleSize(0.05);
  bdt_s1->GetXaxis()->SetTitleOffset(0.97);
  bdt_s1->GetXaxis()->SetTitleFont(22);
  bdt_s1->GetXaxis()->SetLabelFont(22);
  bdt_s1->GetXaxis()->SetLabelSize(.05);
  bdt_s1->GetYaxis()->SetTitle("Events");
  bdt_s1->GetYaxis()->SetTitleSize(0.05);
  bdt_s1->GetYaxis()->SetTitleOffset(1.09);
  bdt_s1->GetYaxis()->SetTitleFont(22);
  bdt_s1->GetYaxis()->SetLabelFont(22);
  bdt_s1->GetYaxis()->SetLabelSize(.05);
  bdt_s1->GetXaxis()->SetTitle("XAXISLABEL");
  bdt_s1->GetXaxis()->SetRangeUser(XMIN,XMAX);
  bdt_s1->GetXaxis()->SetNdivisions(508);
  bdt_s1->GetXaxis()->SetNdivisions(510);


cout <<"HISTPATH_HISTNAME" << "   " <<"  Data  " << bdt_d1->Integral() << "  " << "MC  " << bdt_s1->Integral() <<std::endl;

//ZH TTbar DYjet WWjet QCD signal 
//pave->Draw();
legend->Draw("same");
 t2a->Draw("same");

 
 c12->Draw();
 c12->SaveAs("DYPdf/HISTPATH_HISTNAME.pdf");
 c12->SaveAs("DYPng/HISTPATH_HISTNAME.png");
 c12->SaveAs("DYROOT/HISTPATH_HISTNAME.root");                                                                                                    }
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
            line = line.replace(".pdf",str(inputs[7]+".pdf"))
            line = line.replace(".png",str(inputs[7]+".png"))

        #print line
        NewPlot.write(line)
    NewPlot.close()
    
    os.system('root -l -b -q  Plot.C')
makeplot(['Electron_NoCut_','h_nVtx', '# of vertices', '0', '50', '1', '0' ])
####makeplot(['DiElectronMediumID', 'h_InvMass', 'M_{ee}', '0', '400', '6', '1', 'fullrange' ])
####makeplot(['DiElectronMediumID',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ])
####makeplot(['DiElectronMediumID',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
####makeplot(['DiElectronMediumID',   'h_eta', '#eta_{ee} ', '-3.', '3' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_energy','energy_{ee}','0','800','1','1'])
####makeplot(['DiElectronMediumID',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '2', '1' ])
####makeplot(['DiElectronMediumID',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
####makeplot(['DiElectronMediumID',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
####makeplot(['DiElectronMediumID',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
####
####
####makeplot(['DiElectronMediumIDIso', 'h_InvMass', 'M_{ee}', '0', '400', '6', '1', 'fullrange' ])
####makeplot(['DiElectronMediumIDIso',  'h_InvMass', 'M_{ee}', '60', '120', '3', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_pt', 'p_{T}^{ee} ', '0 ', '300' , '8', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_eta', '#eta_{ee} ', '-3.', '3' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_energy','energy_{ee}','0','800','1','1'])
####makeplot(['DiElectronMediumIDIso',   'h_phi', '#phi_{ee} ', '-3.5', '3.5' , '2', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_DeltaR', '#Delta#R{ee} ', '0', '5' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_DeltaPhi', '#Delta#phi{ee} ', '-3.5', '3.5' , '2', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_DeltaEta', '#Delta#eta{ee} ', '-5', '5' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_Pt2OverPt1', 'p_{T}^{e1}/p_{T}^{e2} ', '0', '1' , '1', '1' ])
####makeplot(['DiElectronMediumIDIso',   'h_PtOverPt1Pt2', 'p_{T}^{ee}/p_{T}^{e1}+p_{T}^{e2} ', '0', '1' , '1', '1' ])
####
####
####
####
####
####makeplot(['Electron_NoCut_',   'h_pt4', 'p_{T}^{e} ', '0', '500' , '2', '1' ])
####makeplot(['Electron_NoCut_',   'h_eta4', '#eta^{e} ', '-3', '3' , '2', '1' ])
####makeplot(['Electron_NoCut_',   'h_phi4', '#phi^{e} ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_dEtaIn4', '#Delta#eta_{In} ', '0', '0.01' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_dPhiIn4', '#Delta#phi_{In} ', '0', '0.08' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_hOverE4', 'H/E', '0', '0.1' , '2', '1' ])
####makeplot(['Electron_NoCut_',   'h_full5x5_sigmaIetaIeta4', '#sigma_{i#eta i#eta}^{5x5} ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_eoverPInv4', 'E/P(Inv) ', '0', '0.25' , '4', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoDeltaBeta4', ' Isolation(#Delta#beta)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_isoRho4', 'Isolation(#rho) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_d04', 'd_{0} ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_dz4', 'd_{z} ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_expectedMissingInnerHits4', 'ExpextedMissingInnerHits ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_passConversionVeto4', 'ConversionVeto ', '0', '2' , '1', '1' ])
####makeplot(['Electron_NoCut_',   'h_nelectrons', 'N_{ele}', '0', '5' , '1', '1' ])
####
####
####makeplot(['Electron_NoCut_Barrel_',   'h_pt4', 'p_{T}^{e}(barrel) ', '0', '500' , '2', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eta4', '#eta^{e}(barrel) ', '-3', '3' , '2', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_phi4', '#phi^{e}(barrel) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dEtaIn4', '#Delta#eta_{In}(barrel) ', '0', '0.01' , '8', '1' ])
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
####makeplot(['Electron_NoCut_Endcap_',   'h_dEtaIn4', '#Delta#eta_{In}(endcap) ', '0', '0.01' , '8', '1' ])
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
####
####makeplot(['Electron_NoCut_Barrel_',   'h_pt1', 'p_{T}^{e}(barrel)(sub-leading)   ', '0', '500' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eta1', '#eta^{e}(barrel)(sub-leading) ', '-3', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_phi1', '#phi^{e}(barrel)(sub-leading) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dEtaIn1', '#Delta#eta_{In}(barrel)(sub-leading) ', '0', '0.01' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dPhiIn1', '#Delta#phi_{In}(barrel)(sub-leading) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_hOverE1', 'H/E(barrel)(sub-leading)', '0', '0.1' , '4', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_full5x5_sigmaIetaIeta1', '#sigma_{i#eta i#eta}^{5x5}(barrel)(sub-leading) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eoverPInv1', 'E/P(Inv)(barrel)(sub-leading) ', '0', '0.25' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_isoDeltaBeta1', ' Isolation(#Delta#beta)(barrel)(sub-leading)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_isoRho1', 'Isolation(#rho)(barrel)(sub-leading) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_d01', 'd_{0}(barrel)(sub-leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dz1', 'd_{z}(barrel)(sub-leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_expectedMissingInnerHits1', 'ExpextedMissingInnerHits(barrel)(sub-leading) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_passConversionVeto1', 'ConversionVeto(barrel)(sub-leading) ', '0', '2' , '1', '1' ])
####
####makeplot(['Electron_NoCut_Endcap_',   'h_pt1', 'p_{T}^{e}(endcap)(sub-leading) ', '0', '500' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_eta1', '#eta^{e}(endcap)(sub-leading) ', '-3', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_phi1', '#phi^{e}(endcap)(sub-leading) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dEtaIn1', '#Delta#eta_{In}(endcap)(sub-leading) ', '0', '0.01' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dPhiIn1', '#Delta#phi_{In}(endcap)(sub-leading) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_hOverE1', 'H/E(endcap)(sub-leading)', '0', '0.1' , '4', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_full5x5_sigmaIetaIeta1', '#sigma_{i#eta i#eta}^{5x5}(endcap)(sub-leading) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_eoverPInv1', 'E/P(Inv)(endcap)(sub-leading) ', '0', '0.25' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_isoDeltaBeta1', ' Isolation(#Delta#beta)(endcap)(sub-leading)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_isoRho1', 'Isolation(#rho)(endcap)(sub-leading) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_d01', 'd_{0}(endcap)(sub-leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dz1', 'd_{z}(endcap)(sub-leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_expectedMissingInnerHits1', 'ExpextedMissingInnerHits(endcap)(sub-leading) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_passConversionVeto1', 'ConversionVeto(endcap)(sub-leading) ', '0', '2' , '1', '1' ])
####
####
####makeplot(['Electron_NoCut_Barrel_',   'h_pt0', 'p_{T}^{e}(barrel)(leading)   ', '0', '500' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eta0', '#eta^{e}(barrel)(leading) ', '-3', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_phi0', '#phi^{e}(barrel)(leading) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dEtaIn0', '#Delta#eta_{In}(barrel)(leading) ', '0', '0.01' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dPhiIn0', '#Delta#phi_{In}(barrel)(leading) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_hOverE0', 'H/E(barrel)(leading)', '0', '0.1' , '4', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_full5x5_sigmaIetaIeta0', '#sigma_{i#eta i#eta}^{5x5}(barrel)(leading) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_eoverPInv0', 'E/P(Inv)(barrel)(leading) ', '0', '0.25' , '8', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_isoDeltaBeta0', ' Isolation(#Delta#beta)(barrel)(leading)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_isoRho0', 'Isolation(#rho)(barrel)(leading) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_d00', 'd_{0}(barrel)(leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_dz0', 'd_{z}(barrel)(leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_expectedMissingInnerHits0', 'ExpextedMissingInnerHits(barrel)(leading) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Barrel_',   'h_passConversionVeto0', 'ConversionVeto(barrel)(leading) ', '0', '2' , '1', '1' ])
####
####makeplot(['Electron_NoCut_Endcap_',   'h_pt0', 'p_{T}^{e}(endcap)(leading) ', '0', '500' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_eta0', '#eta^{e}(endcap)(leading) ', '-3', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_phi0', '#phi^{e}(endcap)(leading) ', '-3.5', '3.5' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dEtaIn0', '#Delta#eta_{In}(endcap)(leading) ', '0', '0.01' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dPhiIn0', '#Delta#phi_{In}(endcap)(leading) ', '0', '0.08' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_hOverE0', 'H/E(endcap)(leading)', '0', '0.1' , '4', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_full5x5_sigmaIetaIeta0', '#sigma_{i#eta i#eta}^{5x5}(endcap)(leading) ', '0', '0.06' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_eoverPInv0', 'E/P(Inv)(endcap)(leading) ', '0', '0.25' , '8', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_isoDeltaBeta0', ' Isolation(#Delta#beta)(endcap)(leading)  ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_isoRho0', 'Isolation(#rho)(endcap)(leading) ', '0', '0.4' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_d00', 'd_{0}(endcap)(leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_dz0', 'd_{z}(endcap)(leading) ', '0', '0.2' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_expectedMissingInnerHits0', 'ExpextedMissingInnerHits(endcap)(leading) ', '0', '3' , '1', '1' ])
####makeplot(['Electron_NoCut_Endcap_',   'h_passConversionVeto0', 'ConversionVeto(endcap)(leading) ', '0', '2' , '1', '1' ])
####
####
####
####
####
####makeplot(['ElectronNMinus1B', 'h_IdEtaIn_aDEtaIn', '#Delta#eta_{In}(barrel)', '0', '0.01' , '4', '1'])
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
####
####makeplot(['ElectronNMinus1E', 'h_IdEtaIn_aDEtaIn', '#Delta#eta_{In}(endcap)', '0', '0.01' , '4', '1'])
####makeplot(['ElectronNMinus1E', 'h_IdPhiIn_bDPhiIn', '#Delta#phi_{In}(endcap) ', '0', '0.08' , '8', '1' ])
####makeplot(['ElectronNMinus1E', 'h_Idfull5x5_sigmaIetaIeta_cSigmaIetaIetaFull','#sigma_{i#eta i#eta}^{5x5}(endcap)) ', '0', '0.06' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdhOverE_dHOverE','H/E(endcap)', '0', '0.1' , '4', '1' ])
####makeplot(['ElectronNMinus1E', 'h_Idd0_eD0','d_{0}(endcap) ', '0', '0.2' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_Iddz_fDz','d_{z}(endcap) ', '0', '0.2' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdeoverPInv_gEInvP','E/P(Inv)(endcap) ', '0', '0.25' , '8', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdisoRho_hRhoIsolation','Isolation(#rho)(endcap) ', '0', '0.4' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdexpectedMissingInnerHits_iExpMissingHits','ExpextedMissingInnerHits(endcap) ', '0', '5' , '1', '1' ])
####makeplot(['ElectronNMinus1E', 'h_IdpassConversionVeto_jConversionVeto','ConversionVeto(endcap) ', '0', '2' , '1', '1' ])
####
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
