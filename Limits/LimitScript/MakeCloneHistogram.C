#include <vector> 
#include "iostream.h"  
#include "TH1F.h"  
void MakeCloneHistogram(){ 
   double luminosity = 19800. ; 
   std::vector<double> Xsection; 
   Xsection.push_back(1871.0); //DYToEE    
   Xsection.push_back(1871.0); //DYToTauTau  
   Xsection.push_back(30400.0); //WJets 
   Xsection.push_back(136.3); //TTJets 
   Xsection.push_back(1.0); //Data         
   Xsection.push_back(5.196); //ZZ     
   Xsection.push_back(33.61); //WW     
   Xsection.push_back(12.63); //WZ     
  TFile* filedata1    = new TFile("histo_files/Fail_endcap_LoosedbetaIso_VTightMVA3EV.root","READ");  
  TH1F* Data_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV = (TH1F*)hprefit->Clone("data_obs");   
  TFile* filedata    = new TFile("OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto_withDz/Merged_SingleElectronData.root","READ");  
  TH1F* Data_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV = (TH1F*)mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Clone("Data_mass_Fail_endcap_SS_LoosedbetaIso_LooseMVA3EV");   
   // no scaling needed for data save it as it is  
   
  TFile* fileDYee    = new TFile("OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto_withDz/Merged_DYEE.root","READ"); 
  TH1F* DYee_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Clone("DYee"); 
  TH1F* DYee_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Clone("DYee_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV"); 
  DYee_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Scale( Xsection[0]*luminosity/totalEvents->Integral() ) ;
  DYee_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Scale( Xsection[0]*luminosity/totalEvents->Integral() ) ;
   
  TH1F* DYee_escale_tagUp = mass_Fail_tag_UP_endcap_OS_LooseMVAIso_VTightMVA3EV->Clone("DYee_escale_tagUp"); 
  DYee_escale_tagUp->Scale(Xsection[0]*luminosity/totalEvents->Integral() ); 
  TH1F* DYee_escale_tagDown = mass_Fail_tag_DOWN_endcap_OS_LooseMVAIso_VTightMVA3EV->Clone("DYee_escale_tagDown"); 
  DYee_escale_tagDown->Scale(Xsection[0]*luminosity/totalEvents->Integral()) ; 
  TH1F* DYee_escale_probeUp = mass_Fail_probe_UP_endcap_OS_LooseMVAIso_VTightMVA3EV->Clone("DYee_escale_probeUp"); 
  DYee_escale_probeUp->Scale(Xsection[0]*luminosity/totalEvents->Integral() ); 
  TH1F* DYee_escale_probeDown = mass_Fail_probe_DOWN_endcap_OS_LooseMVAIso_VTightMVA3EV->Clone("DYee_escale_probeDown"); 
  DYee_escale_probeDown->Scale(Xsection[0]*luminosity/totalEvents->Integral()) ; 
   
   
  TFile* fileDYtt    = new TFile("OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto_withDz/Merged_DYToTauTau_M_20_CT10_TuneZ2star_v2_8TeV_powheg_tauola_pythia6.root","READ"); 
  TH1F* DYtt_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Clone("DYtt"); 
  TH1F* DYtt_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Clone("DYtt_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV"); 
  DYtt_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Scale(Xsection[1]*luminosity/totalEvents->Integral() ) ;
  DYtt_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Scale(Xsection[1]*luminosity/totalEvents->Integral() ) ;
   
  std::cout<<" totalEvents->Integral() = "<<totalEvents->Integral()<<std::endl; 
  TFile* fileWJets    = new TFile("OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto_withDz/Merged_WJetsToLNu_TuneZ2Star_8TeV_madgraph_tarball.root","READ"); 
  TH1F* WJets_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Clone("WJets"); 
  TH1F* WJets_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Clone("WJets_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV"); 
  WJets_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Scale( 1.499 * Xsection[2]*luminosity/totalEvents->Integral()); 
  WJets_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Scale( 1.499 * Xsection[2]*luminosity/totalEvents->Integral()); 
   
  std::cout<<" totalEvents->Integral() = "<<totalEvents->Integral()<<std::endl; 
  TFile* fileTT    = new TFile("OutPutHistoFiles/Merged_MC_WithoutSecondElectronVeto_withDz/Merged_TTJets_MassiveBinDECAY_TuneZ2star_8TeV_madgraph_tauola.root","READ"); 
  TH1F* TT_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Clone("TT"); 
  TH1F* TT_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV = mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Clone("TT_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV"); 
  TT_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Scale(Xsection[3]*luminosity/totalEvents->Integral()); 
  TT_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Scale(Xsection[3]*luminosity/totalEvents->Integral()); 
   
  std::cout<<" totalEvents->Integral() = "<<totalEvents->Integral()<<std::endl; 
  TH1F* QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV = Data_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV->Clone("QCD"); 
  QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Add(DYee_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV ,-1); 
  QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Add(DYtt_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV ,-1); 
  QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Add(WJets_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV ,-1); 
  QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Add(TT_mass_Fail_endcap_SS_LoosedbetaIso_VTightMVA3EV ,-1); 
   
  TH2F* eventtield = new TH2F("eventtield","eventtield",6,0.,6.,6,0.,6.);
  eventtield->SetBinContent(1 ,1 , Data_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Integral()) ; 
  eventtield->SetBinContent(2 ,1 , DYee_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Integral()) ; 
  eventtield->SetBinContent(3 ,1 , DYtt_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Integral()) ; 
  eventtield->SetBinContent(4 ,1 , WJets_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Integral()); 
  eventtield->SetBinContent(5 ,1 , TT_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Integral())   ; 
  eventtield->SetBinContent(6 ,1 , QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Integral())  ; 
  //Dummy signal histogram
  TH1F* Signal = new TH1F("Sig","Sig",60,60.,120.) ;
  for(int i = 0 ; i < 60; i++ ){ 
     Signal->SetBinContent(i,0.00001);
   }  
  Signal->SetBinContent(60,5000.0); 
  TFile* fileOut    = new TFile("Fail_endcap_LoosedbetaIso_VTightMVA3EV.root","RECREATE");  
  Data_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Write(); 
  DYee_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Write(); 
  DYtt_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Write(); 
  WJets_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Write(); 
  TT_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Write(); 
  QCD_mass_Fail_endcap_OS_LoosedbetaIso_VTightMVA3EV->Write(); 
  DYee_escale_tagUp->Write(); 
  DYee_escale_tagDown->Write(); 
  DYee_escale_probeUp->Write(); 
  DYee_escale_probeDown->Write(); 
  Signal->Write();  
  eventtield->Write();  
}
