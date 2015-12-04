import os
## if root file exist then delete it 
## add this line
## Created by Monika Mittal Khurana
macro='''{
//TString filenameString("DYJetsToLL_M-50_MC25ns_ReMiniAOD_20151026.root");
//TString filenameString1("DYJetsToLL_M-10to50_MC25ns_ReMiniAOD_NewMiniIso_Extended.root");


TString filenameString("DYJetsToLL_M-50.root");
TString filenameString1("DYJetsToLL_M-10to50.root");


//histoname
TString histnameString("HISTNAME");
TFile *fIn;
TFile *fIn1;

TH1F* h_num ;
TH1F* h_den;


TH1F* h_lownum;
TH1F* h_lowden;
fIn = new TFile(filenameString,"READ");
fIn1 = new TFile(filenameString1,"READ");

h_num = (TH1F*) fIn->Get(histnameString);
h_den = (TH1F*) fIn->Get("HISTDEN");
h_lownum = (TH1F*) fIn1->Get(histnameString);
h_lowden = (TH1F*) fIn1->Get("HISTDEN");

h_num->Scale(2034.7/h_den->Integral());
h_lownum->Scale(6203.3/h_lowden->Integral());
h_den->Scale(2034.7/h_den->Integral());
h_lowden->Scale(6203.3/h_lowden->Integral());

h_num->Add(h_lownum);
h_den->Add(h_lowden);

h_num->Sumw2();
h_den->Sumw2();

cout << " HISTNAME  "  <<   " Integral : " << h_num->Integral() << std::endl;

TH1F *histo = (TH1F*) h_num->Clone();
histo->Divide(h_den);

histo->Draw("PE1");
histo->SetName("HISTNAME_HISTDEN");

//TGraphAsymmErrors* gr = new TGraphAsymmErrors(h_num, h_den);//gr->Draw("AP");
//gr->SetName("HISTNAME");



TString FilePreName("AccAndEff");
TFile *fout= new TFile(FilePreName+".root","FILEMODE");
fout->cd();
histo->Write();
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
        line = line.replace("HISTNAME",inputs[0])
        line = line.replace("HISTDEN",inputs[1])
        line = line.replace("FILEMODE",inputs[2])
        #print line
        NewPlot.write(line)
    NewPlot.close()
    os.system('root -l -b -q  Plot.C')

##########Start Adding your plots here
makeplot(['h_ZMass','h_ZMass','RECREATE']);
makeplot(['h_ZMass_Acc_Reco','h_ZMass','RECREATE']);
makeplot(['h_ZMass_Acc_Gen','h_ZMass','UPDATE']);

makeplot(['h_ZMass_AE','h_ZMass','UPDATE'])
makeplot(['h_ZMass_AE_DETrig','h_ZMass','UPDATE']);
makeplot(['h_ZMass_AE_DETrig_HEEP','h_ZMass','UPDATE']);
makeplot(['h_ZMass_AE_DETrig_HEEP_NoIso','h_ZMass','UPDATE']);
makeplot(['h_ZMass_AE_Trig_HEEP','h_ZMass','UPDATE']);
makeplot(['h_ZMass_AE_Trig_HEEP_NoIso','h_ZMass','UPDATE']);

makeplot(['h_ZMass_AE','h_ZMass_Acc_Gen','UPDATE'])
makeplot(['h_ZMass_AE_DETrig','h_ZMass_Acc_Gen','UPDATE']);
makeplot(['h_ZMass_AE_DETrig_HEEP','h_ZMass_Acc_Gen','UPDATE']);
makeplot(['h_ZMass_AE_DETrig_HEEP_NoIso','h_ZMass_Acc_Gen','UPDATE']);
makeplot(['h_ZMass_AE_Trig_HEEP','h_ZMass_Acc_Gen','UPDATE']);
makeplot(['h_ZMass_AE_Trig_HEEP_NoIso','h_ZMass_Acc_Gen','UPDATE']);




makeplot(['h_ZMass_Trig','h_ZMass_Acc_Gen','UPDATE'])
makeplot(['h_ZMass_TrigDE','h_ZMass_Acc_Gen','UPDATE'])
makeplot(['h_ZMass_ID','h_ZMass_Acc_Gen','UPDATE'])
makeplot(['h_ZMass_HEEPID_NoIso','h_ZMass_Acc_Gen','UPDATE'])
makeplot(['h_ZMass_HEEPID','h_ZMass_Acc_Gen','UPDATE'])
