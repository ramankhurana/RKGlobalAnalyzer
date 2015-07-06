import os
from  ROOT import *
print "working"

#filename="OutPutHistoFiles/Merged_MC/"
#filename="OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto/"
#filename="OutPutHistoFiles/Merged_MC_WithSecondElectronVeto/"

filename="OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto_withDz/"
#filename="OutPutHistoFiles/Merged_MC_WithSecondElectronVeto_withDz/"

def MakeHistoMacro(fileopenmode, status ,etaregion , isolation , eveto , Closure):
    applySF = true
    if(applySF) : WJetsSF = 1.499
    if(applySF==0) : WJetsSF = 1.000
    
    f = open('MakeCloneHistogram.C','w')
    
    f.write('#include <vector> \n')
    f.write('#include \"iostream.h\"  \n')
    f.write('#include \"TH1F.h\"  \n')
    
    f.write('void MakeCloneHistogram(){ \n' )
    
    f.write('   double luminosity = 19800. ; \n')
    f.write('   std::vector<double> Xsection; \n')
    f.write('   Xsection.push_back(1871.0); //DYToEE    \n')
    f.write('   Xsection.push_back(1871.0); //DYToTauTau  \n')
    f.write('   Xsection.push_back(30400.0); //WJets \n')
    f.write('   Xsection.push_back(136.3); //TTJets \n')
    f.write('   Xsection.push_back(1.0); //Data         \n')
    
    f.write('   Xsection.push_back(5.196); //ZZ     \n')
    f.write('   Xsection.push_back(33.61); //WW     \n')
    f.write('   Xsection.push_back(12.63); //WZ     \n')
    
    if(Closure==0):
        f.write('  TFile* filedata    = new TFile(\"'+filename+'Merged_SingleElectronData.root\",\"READ\");  \n')
        f.write('  TH1F* Data_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = (TH1F*)mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Clone(\"data_obs\");   \n')
        
    ##
    ## end of if(Closure==0):
    ##    
    if(Closure==1):
        f.write('  TFile* filedata1    = new TFile(\"histo_files/'+status+'_'+etaregion+'_'+isolation+'_'+eveto+'.root\",\"READ\");  \n')
        f.write('  TH1F* Data_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = (TH1F*)hprefit->Clone(\"data_obs\");   \n')
        f.write('  TFile* filedata    = new TFile(\"'+filename+'Merged_SingleElectronData.root\",\"READ\");  \n')
                
    ##
    ## end of 
    ##
    
    f.write('  TH1F* Data_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' = (TH1F*)mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Clone(\"Data_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_LooseMVA3EV\");   \n')
    f.write('   // no scaling needed for data save it as it is  \n')
    f.write('   \n')
    f.write('  TFile* fileDYee    = new TFile(\"'+filename+'Merged_DYEE.root\",\"READ\"); \n')
    f.write('  TH1F* DYee_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Clone(\"DYee\"); \n')
    f.write('  TH1F* DYee_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Clone(\"DYee_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'\"); \n')
    
    f.write('  DYee_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Scale( Xsection[0]*luminosity/totalEvents->Integral() ) ;\n')
    f.write('  DYee_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Scale( Xsection[0]*luminosity/totalEvents->Integral() ) ;\n')
    #f.write('  std::cout<<\" totalEvents->Integral() = \"<<totalEvents->Integral()<<std::endl; \n')
    f.write('   \n')

    ## systematics
    f.write('  TH1F* DYee_escale_tagUp = mass_'+status+'_tag_UP_'+etaregion+'_OS_LooseMVAIso_'+eveto+'->Clone(\"DYee_escale_tagUp\"); \n')
    f.write('  DYee_escale_tagUp->Scale(Xsection[0]*luminosity/totalEvents->Integral() ); \n');
    
    f.write('  TH1F* DYee_escale_tagDown = mass_'+status+'_tag_DOWN_'+etaregion+'_OS_LooseMVAIso_'+eveto+'->Clone(\"DYee_escale_tagDown\"); \n')
    f.write('  DYee_escale_tagDown->Scale(Xsection[0]*luminosity/totalEvents->Integral()) ; \n');
    
    f.write('  TH1F* DYee_escale_probeUp = mass_'+status+'_probe_UP_'+etaregion+'_OS_LooseMVAIso_'+eveto+'->Clone(\"DYee_escale_probeUp\"); \n')
    f.write('  DYee_escale_probeUp->Scale(Xsection[0]*luminosity/totalEvents->Integral() ); \n');
    
    f.write('  TH1F* DYee_escale_probeDown = mass_'+status+'_probe_DOWN_'+etaregion+'_OS_LooseMVAIso_'+eveto+'->Clone(\"DYee_escale_probeDown\"); \n')
    f.write('  DYee_escale_probeDown->Scale(Xsection[0]*luminosity/totalEvents->Integral()) ; \n');
    
    f.write('   \n')
    f.write('   \n')
    
    
    f.write('  TFile* fileDYtt    = new TFile(\"'+filename+'Merged_DYToTauTau_M_20_CT10_TuneZ2star_v2_8TeV_powheg_tauola_pythia6.root\",\"READ\"); \n')
    f.write('  TH1F* DYtt_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Clone(\"DYtt\"); \n')
    f.write('  TH1F* DYtt_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Clone(\"DYtt_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'\"); \n')
    f.write('  DYtt_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Scale(Xsection[1]*luminosity/totalEvents->Integral() ) ;\n')
    f.write('  DYtt_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Scale(Xsection[1]*luminosity/totalEvents->Integral() ) ;\n')
    f.write('   \n')
    f.write('  std::cout<<\" totalEvents->Integral() = \"<<totalEvents->Integral()<<std::endl; \n')
    
    
    f.write('  TFile* fileWJets    = new TFile(\"'+filename+'Merged_WJetsToLNu_TuneZ2Star_8TeV_madgraph_tarball.root\",\"READ\"); \n')
    f.write('  TH1F* WJets_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Clone(\"WJets\"); \n')
    f.write('  TH1F* WJets_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Clone(\"WJets_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'\"); \n')
    f.write('  WJets_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Scale( '+str(WJetsSF)+' * Xsection[2]*luminosity/totalEvents->Integral()); \n')
    f.write('  WJets_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Scale( '+str(WJetsSF)+' * Xsection[2]*luminosity/totalEvents->Integral()); \n')
    f.write('   \n')
    f.write('  std::cout<<\" totalEvents->Integral() = \"<<totalEvents->Integral()<<std::endl; \n')
    
    
    f.write('  TFile* fileTT    = new TFile(\"'+filename+'Merged_TTJets_MassiveBinDECAY_TuneZ2star_8TeV_madgraph_tauola.root\",\"READ\"); \n')
    f.write('  TH1F* TT_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Clone(\"TT\"); \n')
    f.write('  TH1F* TT_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' = mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Clone(\"TT_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'\"); \n')
    f.write('  TT_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Scale(Xsection[3]*luminosity/totalEvents->Integral()); \n')
    f.write('  TT_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Scale(Xsection[3]*luminosity/totalEvents->Integral()); \n')
    f.write('   \n')
    f.write('  std::cout<<\" totalEvents->Integral() = \"<<totalEvents->Integral()<<std::endl; \n')
    
    
    f.write('  TH1F* QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+' = Data_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+'->Clone(\"QCD\"); \n')
    f.write('  QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Add(DYee_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' ,-1); \n')
    f.write('  QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Add(DYtt_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' ,-1); \n')
    f.write('  QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Add(WJets_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' ,-1); \n')
    f.write('  QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Add(TT_mass_'+status+'_'+etaregion+'_SS_'+isolation+'_'+eveto+' ,-1); \n')
    f.write('   \n')

    f.write('  TH2F* eventtield = new TH2F(\"eventtield\",\"eventtield\",6,0.,6.,6,0.,6.);\n')
    f.write('  eventtield->SetBinContent(1 ,1 , Data_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Integral()) ; \n')
    f.write('  eventtield->SetBinContent(2 ,1 , DYee_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Integral()) ; \n')
    f.write('  eventtield->SetBinContent(3 ,1 , DYtt_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Integral()) ; \n')
    f.write('  eventtield->SetBinContent(4 ,1 , WJets_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Integral()); \n')
    f.write('  eventtield->SetBinContent(5 ,1 , TT_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Integral())   ; \n')
    f.write('  eventtield->SetBinContent(6 ,1 , QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Integral())  ; \n')
    
    f.write('  //Dummy signal histogram\n')
    f.write('  TH1F* Signal = new TH1F(\"Sig\",\"Sig\",60,60.,120.) ;\n')
    f.write('  for(int i = 0 ; i < 60; i++ ){ \n')
    f.write('     Signal->SetBinContent(i,0.00001);\n')
    f.write('   }  \n')




    f.write('  Signal->SetBinContent(60,5000.0); \n')
    f.write('  TFile* fileOut    = new TFile(\"'+status+'_'+etaregion+'_'+isolation+'_'+eveto+'.root\",\"'+fileopenmode+'\");  \n')
    f.write('  Data_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Write(); \n')
    f.write('  DYee_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Write(); \n')
    f.write('  DYtt_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Write(); \n')
    f.write('  WJets_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Write(); \n')
    f.write('  TT_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Write(); \n')
    f.write('  QCD_mass_'+status+'_'+etaregion+'_OS_'+isolation+'_'+eveto+'->Write(); \n')
    ## systematic
    f.write('  DYee_escale_tagUp->Write(); \n')
    f.write('  DYee_escale_tagDown->Write(); \n')
    f.write('  DYee_escale_probeUp->Write(); \n')
    f.write('  DYee_escale_probeDown->Write(); \n')
    
    f.write('  Signal->Write();  \n')
        
    f.write('  eventtield->Write();  \n')
    
    f.write('}\n')
    f.close()
    os.system('root -l -b -q MakeCloneHistogram.C')
    
    
    return 0.0


def MakeDataCard(status, etaregion, isolation, eveto,inputdatacard):
    datacardname = 'Datacard_'+status+'_'+etaregion+'_'+isolation+'_'+eveto+'.txt'
    os.system('rm -rf  '+datacardname)
    
    
    
    file = TFile(status+'_'+etaregion+'_'+isolation+'_'+eveto+'.root',"READ")
    histYield = gROOT.FindObject('eventtield')
    #print type(histYield)

    if(status=="Fail"):
        filefail = TFile('Pass'+'_'+etaregion+'_'+isolation+'_'+eveto+'.root',"READ")
        histDYEEFAIL = gROOT.FindObject('eventtield')
        DYEEFail = histDYEEFAIL.GetBinContent(2,1)
    
    datacard = open(datacardname,"a")
    for line in open(inputdatacard):
        line = line.replace("ROOTFILENAME",str(status+'_'+etaregion+'_'+isolation+'_'+eveto+'.root'))
        line = line.replace("NUMBEROFPASSEVENTS",str(histYield.GetBinContent(1,1)))
        line = line.replace("PASSDYEERATE",str(histYield.GetBinContent(2,1)))
        line = line.replace("PASSDYTTRATE",str(histYield.GetBinContent(3,1)))
        line = line.replace("PASSWJETSRATE",str(histYield.GetBinContent(4,1)))
        line = line.replace("PASSTTRATE",str(histYield.GetBinContent(5,1)))
        line = line.replace("PASSQCDRATE",str(histYield.GetBinContent(6,1)))
        if(status=="Fail"):
            eletaufr = 1.0 - (5.0*DYEEFail/histYield.GetBinContent(2,1) )
            #print "eletaufr = ",eletaufr
            ## truncate this value to -5.0 so that combine can work without failure
            if(eletaufr<0.) : eletaufr = 0.01
            line = line.replace("ETOTAUFRVALUEFAIL",str(eletaufr))
        
        datacard.write(line)
    datacard.close()
    return 0.0

