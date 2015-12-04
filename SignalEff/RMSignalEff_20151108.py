import os
## if root file exist then delete it 
## add this line
## Created by Monika Mittal Khurana
macro='''{
std::vector<TString> filenameString;
TString filenamepath("/afs/hep.wisc.edu/cms/khurana/Script/MonoHFatJetAnalysis_ForExoWorkShopV6/");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-600GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-800GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1000GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1200GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1400GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-1700GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-2000GeV_MA0-300GeV-runallAnalysis.root");
filenameString.push_back(filenamepath +"Merged_MonoHToBBarMZp-2500GeV_MA0-300GeV-runallAnalysis.root");

//histoname
TString histnameString("HISTPATH/HISTNAME");


TFile *fIn;
int nfiles_ = (int) filenameString.size();

const int nfiles = nfiles_;
float yarray_[nfiles];
float x[]={600, 800, 1000,1200,1400,1700,2000,2500};


TH1F* h_mc ;
TH1F* h_total;
float normalization[nfiles];

for(int i =0; i<(int)filenameString.size(); i++){
 fIn = new TFile(filenameString[i],"READ");
 h_mc = (TH1F*) fIn->Get(histnameString);
 h_total = (TH1F*) fIn->Get("nEvents_weight");
 yarray_[i]= (h_mc->Integral())/(h_total->Integral()); 
 cout << "x: " << x[i]  << "y : " << yarray_[i]  << std::endl;
 
}


TGraphAsymmErrors *gr;
gr = new TGraphAsymmErrors(nfiles, x,yarray_ );
gr->Draw("APL");
gr->SetName("HISTPATH");

TString FilePreName("SignalEff_Graph_20151108");
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
        line = line.replace("FILEMODE",inputs[2])
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here
dirnames=['MonoHFatJetsPreselection','MonoHFatJetsPreselection_2subj','MonoHFatJetsPreselection_1subj','MonoHFatJetsPreselection_DRsubj','MonoHFatJetsPreselection_DROnesubj','MonoHFatJetSelection_Jetveto','MonoHFatJetSelection_LeptonVeto','MonoHFatJetSelection_JetAndLeptonVeto']
for dirname in range(len(dirnames)):
    if dirname == 0:
        makeplot([dirnames[dirname], 'h_Mjj0', 'RECREATE'] )
    else :
        makeplot([dirnames[dirname], 'h_Mjj0', 'UPDATE'] )




        
#makeplot(['CutFlowAndEachCutFatJet','h_cutflow_0_f','2','RECREATE']);
#makeplot(['CutFlowAndEachCutFatJet_2subj','h_cutflow_0_f','2','UPDATE']);
#makeplot(['CutFlowAndEachCutFatJet_1subj','h_cutflow_0_f','2','UPDATE']);
#makeplot(['CutFlowAndEachCutFatJet_DRsubj','h_cutflow_0_f','2','UPDATE']);
#
#makeplot(['CutFlowAndEachCutFatJet','h_cutflow_0_f','5','RECREATE']);
#makeplot(['CutFlowAndEachCutFatJet_2subj','h_cutflow_0_f','5','UPDATE']);
#makeplot(['CutFlowAndEachCutFatJet_1subj','h_cutflow_0_f','5','UPDATE']);
#makeplot(['CutFlowAndEachCutFatJet_DRsubj','h_cutflow_0_f','5','UPDATE']);
#


