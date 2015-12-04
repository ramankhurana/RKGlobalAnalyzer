import os
## if root file exist then delete it 
## add this line
## Created by Monika Mittal Khurana
macro='''{
TString filenameString("/afs/hep.wisc.edu/cms/khurana/METScanning/ForHotLine/CMSSW_7_4_7/src/MetScanning/MetAnalyzer/METScanningHotLine2015D.root");

//histoname
TString histnameString("HISTPATH/HISTNAME");
TFile *fIn;

TH1F* h_num ;
TH1F* h_den;

fIn = new TFile(filenameString,"READ");
h_num = (TH1F*) fIn->Get(histnameString);
h_den = (TH1F*) fIn->Get("HISTPATH/HISTDEN");

TGraphAsymmErrors* gr = new TGraphAsymmErrors(h_num, h_den);
gr->Draw("APL");
gr->SetName("HISTNAME");



TString FilePreName("METScan_Eff");
TFile *fout= new TFile(FilePreName+".root","FILEMODE");
fout->cd();
gr->Write();
fout->Write();
fout->Close();



}
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
        line = line.replace("HISTDEN",inputs[2])
        line = line.replace("FILEMODE",inputs[3])
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here

makeplot(['Metanalyzer','h_nVtxhbhet','h_nVtxNoFilter','RECREATE']);
makeplot(['Metanalyzer','h_nVtxcsct','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxEESCBad','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxECDCTP','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxCSCTH2015','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxCSCTHMu','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxHCALStrp','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxAllCSCTH2015','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxAllCSCTHMu','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxAllHCALStrp','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxAllCSCTH2015HCALStrp','h_nVtxNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_nVtxAllCSCTH2015HCALStrpIsolation','h_nVtxNoFilter','UPDATE']);

makeplot(['Metanalyzer','h_RunNumberhbhet','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumbercsct','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberEESCBad','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberECDCTP','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberCSCTH2015','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberCSCTHMu','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberHCALStrp','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberAllCSCTH2015','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberAllCSCTHMu','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberAllHCALStrp','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberAllCSCTH2015HCALStrp','h_RunNumberNoFilter','UPDATE']);
makeplot(['Metanalyzer','h_RunNumberAllCSCTH2015HCALStrpIsolation','h_RunNumberNoFilter','UPDATE']);



#makeplot(['CutFlowAndEachCutFatJet','h_cutflow_0_f','2','RECREATE']);
#makeplot(['CutFlowAndEachCutFatJet_2subj','h_cutflow_0_f','2','UPDATE']);



