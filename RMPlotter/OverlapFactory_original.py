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

TFile g2("/home/monika/Downloads/rerootfiles/Merged_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-main.root");
 TH1F *bdt_B1       = (TH1F*) g2->Get("HISTPATH/HISTNAME");
 TH1F *nevents_B1       = (TH1F*) g2->Get("nEvents");
 TFile g3("/home/monika/Downloads/rerootfiles/Merged_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8-main.root");
 TH1F *bdt_B2       = (TH1F*)g3->Get("HISTPATH/HISTNAME");
 TH1F *nevents_B2       = (TH1F*) g3->Get("nEvents");

TFile g4("/home/monika/Downloads/rerootfiles/Merged_QCD_Pt-15TTo7000_TuneZ2star-Flat_13TeV_pythia6-main.root");
 TH1F *bdt_B3       = (TH1F*)g4->Get("HISTPATH/HISTNAME");
 TH1F *nevents_B3       = (TH1F*) g4->Get("nEvents");

TFile g5("/home/monika/Downloads/rerootfiles/Merged_TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8-main.root");
 TH1F *bdt_B4       = (TH1F*)g5->Get("HISTPATH/HISTNAME");
 TH1F *nevents_B4       = (TH1F*) g5->Get("nEvents");

 TFile g6("/home/monika/Downloads/rerootfiles/Merged_WJetsToLNu_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8-main.root");
 TH1F *bdt_B5       = (TH1F*)g6->Get("HISTPATH/HISTNAME");
 TH1F *nevents_B5       = (TH1F*) g6->Get("nEvents");
  
 //Signal sample 
 TFile s1("/home/monika/Downloads/rerootfiles_S/main-NCUGlobalTuples_M600.root");
 TH1F *bdt_s1 = (TH1F*) s1->Get("HISTPATH/HISTNAME");
 TH1F *nevents_s1 = (TH1F*) s1->Get("nEvents"); 

 TFile s2("/home/monika/Downloads/rerootfiles_S/main-NCUGlobalTuples_M700.root");
 TH1F *bdt_s2 = (TH1F*) s2->Get("HISTPATH/HISTNAME");
 TH1F *nevents_s2 = (TH1F*) s2->Get("nEvents");
 
 
 TFile s3("/home/monika/Downloads/rerootfiles_S/main-NCUGlobalTuples_M800.root");
 TH1F *bdt_s3 = (TH1F*) s3->Get("HISTPATH/HISTNAME");
 TH1F *nevents_s3 = (TH1F*) s3->Get("nEvents");
 
 
 TFile s4("/home/monika/Downloads/rerootfiles_S/main-NCUGlobalTuples_M900.root");
 TH1F *bdt_s4 = (TH1F*) s4->Get("HISTPATH/HISTNAME");
 TH1F *nevents_s4 = (TH1F*) s4->Get("nEvents");
 
 
 TFile s5("/home/monika/Downloads/rerootfiles_S/main-NCUGlobalTuples_M1250.root");
 TH1F *bdt_s5 = (TH1F*) s5->Get("HISTPATH/HISTNAME");
 TH1F *nevents_s5 = (TH1F*) s5->Get("nEvents");


 TFile s6("/home/monika/Downloads/rerootfiles_S/main-NCUGlobalTuples_M1500.root");
 TH1F *bdt_s6 = (TH1F*) s6->Get("HISTPATH/HISTNAME");  
 TH1F *nevents_s6 = (TH1F*) s6->Get("nEvents");



 double xs1 = (1. *0.052432*1000)/(nevents_s1->GetEntries());  
 double xs2 = (1. *0.053500*1000)/(nevents_s2->GetEntries());
 double xs3 = (1. *0.055814*1000)/(nevents_s3->GetEntries());
 double xs4 = (1. *0.500000*1000)/(nevents_s4->GetEntries());
 double xs5 = (1. *0.030235*1000)/(nevents_s5->GetEntries());
 double xs6 = (1. *0.019893*1000)/(nevents_s6->GetEntries());

float integral_1 = (bdt_s1->Integral());
float integral_2 = (bdt_s2->Integral());
float integral_3 = (bdt_s3->Integral());
float integral_4 = (bdt_s4->Integral());
float integral_5 = (bdt_s5->Integral());
float integral_6 = (bdt_s6->Integral());
bdt_s1->Scale(1./integral_1);
bdt_s2->Scale(1./integral_2);
bdt_s3->Scale(1./integral_3);
bdt_s4->Scale(1./integral_4);
bdt_s5->Scale(1./integral_5);
bdt_s6->Scale(1./integral_6);


bdt_s1->Rebin(REBIN);                                                                                                              
bdt_s2->Rebin(REBIN);                                                                                                              
bdt_s3->Rebin(REBIN);                                                                                                                          
bdt_s4->Rebin(REBIN);                                                                                                                          bdt_s5->Rebin(REBIN);                                                                                                                           
bdt_s6->Rebin(REBIN);

//cross-section
 double n2           =(1. * 18610*1000)/(nevents_B1->GetEntries()); //DYJets
 double n3           =(1. *0.9696  *1000)/(nevents_B2->GetEntries()); // ZH
 double n4           =(1. *89731000000  *1000)/(nevents_B3->GetEntries()); //QCD
 double n5           =(1. *831.76   *1000)/(nevents_B4->GetEntries()); //TTjets
 double n6            =(1. *60290   *1000)/(nevents_B5->GetEntries()); // WJets

TLegend* legend = new TLegend(0.53, 0.72, 0.95,0.92,NULL,"brNDC");
 legend->SetBorderSize(0);
 legend->SetLineColor(1);
 legend->SetLineStyle(1);
 legend->SetLineWidth(1);
 legend->SetFillColor(0);
 legend->SetFillStyle(0);
 legend->SetTextFont(22);
 legend->SetTextSize(0.05);
 legend->SetNColumns(2);
 legend->AddEntry(bdt_B1,"DYJets","l");
 legend->AddEntry(bdt_B2,"ZH","l");
//legend->AddEntry(bdt_B3,"QCD","l");
 legend->AddEntry(bdt_B4,"TTJets","l");
 legend->AddEntry(bdt_B5,"WWJets", "l");
 legend->AddEntry(bdt_s1,"M600", "l");
legend->AddEntry(bdt_s4,"M900", "l");
legend->AddEntry(bdt_s6,"M1500", "l");

 

//================================Latex=================//
 TLatex *t2a = new TLatex(0.5,0.97,"CMS simulation, #sqrt{s} = 13 TeV #scale[0.45]{#int}L = 1 fb^{-1}");
 t2a->SetTextSize(0.04);
 t2a->SetTextAlign(22);
 t2a->SetNDC(kTRUE);
 t2a->SetTextFont(22);
//THStack *hs = new THStack("hs","BDT");
//============== canvas declaration ===================
TCanvas *c12 = new TCanvas("Vertex Multiplicity ", "vertex Multiplicity"  , 0,0,500,500);
//
TPaveText *pave = new TPaveText(0.15,0.80,0.35,0.92,"brNDC");


//bdt_B1->SetFillColor(kOrange-1);
  bdt_B1->SetLineColor(kOrange-1);
  bdt_B1->SetLineWidth(3);

   bdt_B2->SetLineColor(kTeal-8);
// bdt_B2->SetFillColor(kTeal-8);
   bdt_B2->SetLineWidth(3);                                                                                                                      

   bdt_B5->SetLineColor(kOrange+4);
//bdt_B5->SetFillColor(kOrange+4);
   bdt_B5->SetLineWidth(3);                                                                                                                      
   bdt_B4->SetLineColor(kBlue-5);
//bdt_B4->SetFillColor(kBlue-5);
   bdt_B4->SetLineWidth(3);                                                                                                                      
   bdt_B3->SetFillColor(kGreen);
// bdt_B3->SetLineColor(kGreen);
   bdt_B3->SetLineWidth(3);                                                                                                                      
// bdt_B6->SetLineColor(kTeal-8);
// bdt_B6->SetFillColor(kTeal-8);
///Scale 

bdt_s1->SetLineColor(kBlack);
bdt_s1->SetLineWidth(3);
bdt_s4->SetLineColor(kGreen);
bdt_s4->SetLineWidth(3);
bdt_s6->SetLineColor(kRed);
bdt_s6->SetLineWidth(3);


 


c12->SetLogy(0);
float integral_s1 = (bdt_B1->Integral());
float integral_s2 = (bdt_B2->Integral());
float integral_s3 = (bdt_B3->Integral());
float integral_s4 = (bdt_B4->Integral());
float integral_s5 = (bdt_B5->Integral());



  bdt_B1->Scale(1./integral_s1);
  bdt_B2->Scale(1./integral_s2);
  bdt_B3->Scale(1./integral_s3);
  bdt_B4->Scale(1./integral_s4);
  bdt_B5->Scale(1./integral_s5);

  bdt_B1->Rebin(REBIN);                                                                                                                          bdt_B2->Rebin(REBIN);                                                                                                                          bdt_B3->Rebin(REBIN);                                                                                                                          bdt_B4->Rebin(REBIN);                                                                                                                          bdt_B5->Rebin(REBIN);                                                                                                                          double no =bdt_B4->GetMaximum();
  

//   hs->Add(bdt_B2);
//  hs->Add(bdt_B5);
//  hs->Add(bdt_B1);    
//  hs->Add(bdt_B4);
  //hs->Add(bdt_B2);
    
 TPad *c1_2 = new TPad("c1_2","newpad",0,0.05,1,0.99);
 c1_2->SetBottomMargin(-0.5);
  c1_2->SetLogy(ISLOG);
  c1_2->Draw();
  c1_2->cd();
  bdt_B4->Draw(); 
  bdt_B1->Draw("same");
  bdt_B5->Draw("same");
  bdt_B2->Draw("same");

  bdt_B4->SetMinimum(0.0001);
  if(ISLOG) bdt_B4->SetMaximum(1.);
  if(!ISLOG) bdt_B4->SetMaximum(0.4);

  bdt_B4->GetXaxis()->SetTitleSize(0.05);
  bdt_B4->GetXaxis()->SetTitleOffset(0.97);
  bdt_B4->GetXaxis()->SetTitleFont(22);
  bdt_B4->GetXaxis()->SetLabelFont(22);
  bdt_B4->GetXaxis()->SetLabelSize(.05);
  bdt_B4->GetYaxis()->SetTitle("Events");
  bdt_B4->GetYaxis()->SetTitleSize(0.05);
  bdt_B4->GetYaxis()->SetTitleOffset(1.09);
  bdt_B4->GetYaxis()->SetTitleFont(22);
  bdt_B4->GetYaxis()->SetLabelFont(22);
  bdt_B4->GetYaxis()->SetLabelSize(.05);
  bdt_B4->GetXaxis()->SetTitle("XAXISLABEL");
  bdt_B4->GetXaxis()->SetRangeUser(XMIN,XMAX);
  bdt_B4->GetXaxis()->SetNdivisions(508);

//ZH TTbar DYjet WWjet QCD signal 
//pave->Draw();
legend->Draw("same");
 t2a->Draw("same");

bdt_s1->Draw("same");
bdt_s4->Draw("same");
bdt_s6->Draw("same");
 
 c12->Draw();
 c12->SaveAs("Pdf/HISTPATH_HISTNAME.pdf");
 c12->SaveAs("Png/HISTPATH_HISTNAME.png");
 c12->SaveAs("ROOT/HISTPATH_HISTNAME.root");                                                                                                    }
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
        #print line
        NewPlot.write(line)
    NewPlot.close()
    
    os.system('root -l -b -q  Plot.C')
makeplot(['Jet_NoCut_', 'h_pt_vec_0',        'p_{T}^{leading jet}',   '0' , '500',   '2' ,'1'])
makeplot(['Jet_NoCut_', 'h_pt_vec_1',        'p_{T}^{sub-leading jet}',   '0' , '300',   '2','1'])
makeplot(['Jet_NoCut_', 'h_B_CISVV2_vec_0', 'CSV^{leading jet}',     '0' , ' 1',    '1','0'])
makeplot(['Jet_NoCut_', 'h_B_CISVV2_vec_1', 'CSV^{subleading jet}',  '0' , '1 ',    '1', '0'])
makeplot(['MET_NoCut_',  'h_RawPt'  ,      'MET ' ,                 '0' , '2000',  '4','1'])
makeplot(['MET_NoCut_',  'h_RawPhi'  ,     '#phi^{MET} ',         '-3.5', '3.5',  '1','0'])

makeplot(['DiJetNotCut',  'h_DeltaR'  ,     '#Delta R_{bb} ' ,       '0' , '5', '1', '1'])
makeplot(['DiJetNotCut',  'h_DeltaPhi'  ,   '#Delta#Phi_{bb} ' ,    '-3.5' , '-3.5', '2','1'])
makeplot(['DiJetNotCut',  'h_InvMass'  ,    'M_{bb}' ,               '0 ' , '400' , '1','0'])
makeplot(['DiJetNotCut',  'h_Pt2OverPt1'  , 'p_{T}^{b2}/p_{T}^{b1} ' ,  '0 ' , '1 ', '1','1'])
makeplot(['DiJetNotCut',  'h_PtOverPt1Pt2', 'p_{T}^{bb}/p_{T}^{b1}+p_{T}^{b2} ' ,  '0 ' , '1 ','1','1'])
makeplot(['DiJetNotCut',  'h_CSVSum'  ,     'CSV_{jet1}+CSV_{jet2}' ,  '0 ' , '2 ', '8','0'])


makeplot(['DiJetMETNoCuts',  'h_DeltaPhi0'  ,  '#Delta#Phi{bb,MET} ' ,  '-3.5  ' , '3.5 ', '1' ,'1' ])
makeplot(['DiJetMETNoCuts',  'h_TransMass0'  ,  'M_{T}^{bb,MET} ' ,  '0 ' , '2000 ', '4','1'])



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
