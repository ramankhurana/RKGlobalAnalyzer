#define JetValidator_cxx
#include "../interface/JetValidator.h"
void JetValidator::Fill(std::vector<Jet> jetcollection){
  
  if(false) std::cout<<" num of jets = "<<jetcollection.size()<<std::endl;
  
  Float_t mcweight_  = 1.;

  if(jetcollection.size() >0) mcweight_ = jetcollection[0].event.mcweight ;
  
  for (int i=0; i< (int) jetcollection.size(); i++){
    
    
    
    // Fill First Four Jets Properties 
    if(i<4){
      h_pt_vec[i]                   ->Fill(jetcollection[i].p4.Pt()                   , mcweight_          );
      h_eta_vec[i]                  ->Fill(jetcollection[i].p4.Eta()                  , mcweight_          );
      h_phi_vec[i]                  ->Fill(jetcollection[i].p4.Phi()                  , mcweight_          );
      h_charge_vec[i]               ->Fill(jetcollection[i].charge                    , mcweight_          );
      h_partonFlavor_vec[i]         ->Fill(jetcollection[i].partonFlavor              , mcweight_          );
      h_B_CISVV2_vec[i]             ->Fill(jetcollection[i].B_CISVV2                  , mcweight_          );
      
      h_tau1_vec[i]                 ->Fill(jetcollection[i].tau1                      , mcweight_          );
      h_tau2_vec[i]                 ->Fill(jetcollection[i].tau2                      , mcweight_          );
      h_tau3_vec[i]                 ->Fill(jetcollection[i].tau3                      , mcweight_          );
      
      h_tau21_vec[i]                ->Fill(jetcollection[i].tau2/jetcollection[i].tau1, mcweight_           );

      
      // Fat Jet variables :: for the first 4 fat jet
      h_DMmass  [i]             ->Fill(jetcollection[i].DMmass,mcweight_);
      h_TRmass  [i]             ->Fill(jetcollection[i].TRmass,mcweight_);
      h_PRmass  [i]             ->Fill(jetcollection[i].PRmass,mcweight_);
      h_Fimass  [i]             ->Fill(jetcollection[i].Fimass,mcweight_);
      h_nsubJets[i]             ->Fill(jetcollection[i].nsubJets,mcweight_);
      
      for(int j =0; i<jetcollection[i].nsubJets; j++){
	// Sub-jet variables ::  for the first 4 fat jet
	if(j>2) continue;
	subjetp4.SetPxPyPzE(jetcollection[i].SDPx[j],
					   jetcollection[i].SDPy[j],
					   jetcollection[i].SDPz[j],
					   jetcollection[i].SDEn[j]);
	
	h_SJ_pt[i][j]                ->Fill(subjetp4.Pt(),mcweight_);
	h_SJ_eta[i][j]               ->Fill(subjetp4.Eta(),mcweight_);
	h_SJ_phi[i][j]               ->Fill(subjetp4.Phi(),mcweight_);
	h_SJ_csv[i][j]               ->Fill(jetcollection[i].SDCSV[j],mcweight_);
      }
      
      
    }// if(i<4)
    
    // Fill properties of all jets together in same histograms. 
    h_nJets                ->Fill(jetcollection[i].nJets                     , mcweight_        );
    h_pt                   ->Fill(jetcollection[i].p4.Pt()                   , mcweight_        );
    h_eta                  ->Fill(jetcollection[i].p4.Eta()                  , mcweight_        );
    h_phi                  ->Fill(jetcollection[i].p4.Phi()                  , mcweight_        );
    h_charge               ->Fill(jetcollection[i].charge                    , mcweight_        );
    h_partonFlavor         ->Fill(jetcollection[i].partonFlavor              , mcweight_        );
    h_B_CISVV2             ->Fill(jetcollection[i].B_CISVV2                  , mcweight_        );
    h_tau1                 ->Fill(jetcollection[i].tau1                      , mcweight_        );
    h_tau2                 ->Fill(jetcollection[i].tau2                      , mcweight_        );
    h_tau3                 ->Fill(jetcollection[i].tau3                      , mcweight_        );
    h_tau21                ->Fill(jetcollection[i].tau2/jetcollection[i].tau1, mcweight_        );

    
  }
  
}


void JetValidator::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(true) std::cout<<" calling define histograms for Jets "<<std::endl;
  DefineHistograms();
  if(true) std::cout<<" Jets histo defined "<<std::endl;
}


void JetValidator::DefineHistograms(){
  TString postfix;
  for(int i=0; i<4;i++){
    postfix.Form("%d",i);
    if(false) std::cout<<" postfix for jets= "<<postfix<<std::endl;
    h_pt_vec[i]           = new TH1F("h_pt_vec_"+postfix,"h_pt_vec_"+postfix,100,0,500);
    h_eta_vec[i]                   = new TH1F("h_eta_vec_"+postfix,"h_eta_vec_"+postfix,100,-5.0,5.0);
    h_phi_vec[i]                   = new TH1F("h_phi_vec_"+postfix,"h_phi_vec_"+postfix,80,-4.0,4.);
    h_charge_vec[i]                = new TH1F("h_charge_vec_"+postfix,"h_charge_vec_"+postfix,6,-3,3);
    h_partonFlavor_vec[i]          = new TH1F("h_partonFlavor_vec_"+postfix,"h_partonFlavor_vec_"+postfix,100,-50,50);
    h_B_SSV_vec[i]                 = new TH1F("h_B_SSV_vec_"+postfix,"h_B_SSV_vec_"+postfix,100,-50,50);
    h_B_CSV_vec[i]                 = new TH1F("h_B_CSV_vec_"+postfix,"h_B_CSV_vec_"+postfix,100,-50,50);
    h_B_SSVHE_vec[i]               = new TH1F("h_B_SSVHE_vec_"+postfix,"h_B_SSVHE_vec_"+postfix,100,-50,50);
    h_B_CISVV2_vec[i]              = new TH1F("h_B_CISVV2_vec_"+postfix,"h_B_CISVV2_vec_"+postfix,120,-10,2);
    h_B_TCHP_vec[i]                = new TH1F("h_B_TCHP_vec_"+postfix,"h_B_TCHP_vec_"+postfix,100,-50,50);
    h_B_TCHE_vec[i]                = new TH1F("h_B_TCHE_vec_"+postfix,"h_B_TCHE_vec_"+postfix,100,-50,50);
    h_B_JP_vec[i]                  = new TH1F("h_B_JP_vec_"+postfix,"h_B_JP_vec_"+postfix,100,-50,50);
    h_B_JBP_vec[i]                 = new TH1F("h_B_JBP_vec_"+postfix,"h_B_JBP_vec_"+postfix,100,-50,50);
    h_tau1_vec[i]                  = new TH1F("h_tau1_vec_"+postfix,"h_tau1_vec_"+postfix,100,-50,50);
    h_tau2_vec[i]                  = new TH1F("h_tau2_vec_"+postfix,"h_tau2_vec_"+postfix,100,-50,50);
    h_tau3_vec[i]                  = new TH1F("h_tau3_vec_"+postfix,"h_tau3_vec_"+postfix,100,-50,50);
    h_jetMuEF_vec[i]               = new TH1F("h_jetMuEF_vec_"+postfix,"h_jetMuEF_vec_"+postfix,100,-50,50);
    h_jetPhoEF_vec[i]              = new TH1F("h_jetPhoEF_vec_"+postfix,"h_jetPhoEF_vec_"+postfix,100,-50,50);
    h_jetCEmEF_vec[i]              = new TH1F("h_jetCEmEF_vec_"+postfix,"h_jetCEmEF_vec_"+postfix,100,-50,50);
    h_jetCHadEF_vec[i]             = new TH1F("h_jetCHadEF_vec_"+postfix,"h_jetCHadEF_vec_"+postfix,100,-50,50);
    h_jetNEmEF_vec[i]              = new TH1F("h_jetNEmEF_vec_"+postfix,"h_jetNEmEF_vec_"+postfix,100,-50,50);
    h_jetNHadEF_vec[i]             = new TH1F("h_jetNHadEF_vec_"+postfix,"h_jetNHadEF_vec_"+postfix,100,-50,50);
    h_jetCMulti_vec[i]             = new TH1F("h_jetCMulti_vec_"+postfix,"h_jetCMulti_vec_"+postfix,100,-50,50);
    h_jetHFHadEF_vec[i]            = new TH1F("h_jetHFHadEF_vec_"+postfix,"h_jetHFHadEF_vec_"+postfix,100,-50,50);
    h_jetHFEMEF_vec[i]             = new TH1F("h_jetHFEMEF_vec_"+postfix,"h_jetHFEMEF_vec_"+postfix,100,-50,50);
    h_jetCHHadMultiplicity_vec[i]  = new TH1F("h_jetCHHadMultiplicity_vec_"+postfix,"h_jetCHHadMultiplicity_vec_"+postfix,100,-50,50);
    h_jetNHadMulplicity_vec[i]     = new TH1F("h_jetNHadMulplicity_vec_"+postfix,"h_jetNHadMulplicity_vec_"+postfix,100,-50,50);
    h_jetPhMultiplicity_vec[i]     = new TH1F("h_jetPhMultiplicity_vec_"+postfix,"h_jetPhMultiplicity_vec_"+postfix,100,-50,50);
    h_jetEleMultiplicity_vec[i]    = new TH1F("h_jetEleMultiplicity_vec_"+postfix,"h_jetEleMultiplicity_vec_"+postfix,100,-50,50);
    h_jetHFHadMultiplicity_vec[i]  = new TH1F("h_jetHFHadMultiplicity_vec_"+postfix,"h_jetHFHadMultiplicity_vec_"+postfix,100,-50,50);
    h_jetHFEMMultiplicity_vec[i]   = new TH1F("h_jetHFEMMultiplicity_vec_"+postfix,"h_jetHFEMMultiplicity_vec_"+postfix,100,-50,50);
    h_jetChMuEF_vec[i]             = new TH1F("h_jetChMuEF_vec_"+postfix,"h_jetChMuEF_vec_"+postfix,100,-50,50);
    h_jetNMultiplicity_vec[i]      = new TH1F("h_jetNMultiplicity_vec_"+postfix,"h_jetNMultiplicity_vec_"+postfix,100,-50,50);
    h_jetHOEnergy_vec[i]           = new TH1F("h_jetHOEnergy_vec_"+postfix,"h_jetHOEnergy_vec_"+postfix,100,-50,50);
    h_jetHOEF_vec[i]               = new TH1F("h_jetHOEF_vec_"+postfix,"h_jetHOEF_vec_"+postfix,100,-50,50);
    
    h_tau21_vec[i]                 = new TH1F("h_tau21_vec_"+postfix,"h_tau21_vec_"+postfix,100,-50,50);

    // Fat Jets
    h_DMmass[i]                     = new TH1F("h_DMmass"+postfix,"h_DMmass"+postfix,3000,0,3000);
    h_TRmass[i]                     = new TH1F("h_TRmass"+postfix,"h_TRmass"+postfix,3000,0,3000);
    h_PRmass[i]                     = new TH1F("h_PRmass"+postfix,"h_PRmass"+postfix,3000,0,3000);
    h_Fimass[i]                     = new TH1F("h_Fimass"+postfix,"h_Fimass"+postfix,3000,0,3000);
    h_nsubJets[i]                   = new TH1F("h_nsubJets"+postfix,"h_nsubJets"+postfix,10,0,10);
    for(int j=0; j<2;j++){
      TString postfix0;
      postfix0.Form("%d",j); // subjet index
      TString postfix1=postfix+postfix0;
      h_SJ_pt[i][j]                     = new TH1F("h_SJ_pt"+postfix1,"h_SJ_pt"+postfix1,3000,0,3000);
      h_SJ_csv[i][j]                     = new TH1F("h_SJ_csv"+postfix1,"h_SJ_csv"+postfix1,20,0,1.);
      h_SJ_eta[i][j]                     = new TH1F("h_SJ_eta"+postfix1,"h_SJ_eta"+postfix1,60,-3.,3.);
      h_SJ_phi[i][j]                     = new TH1F("h_SJ_phi"+postfix1,"h_SJ_phi"+postfix1,60,-3.0,3.0);
    }
  }
  
  if(false) std::cout<<" vector histo defined "<<std::endl;
  h_nJets                 = new TH1F("h_nJets","h_nJets",25,0,25);
  h_pt                    = new TH1F("h_pt","h_pt",100,0,500);
  h_eta                   = new TH1F("h_eta","h_eta",100,-5.0,5.0);
  h_phi                   = new TH1F("h_phi","h_phi",80,-4.0,4.);
  h_charge                = new TH1F("h_charge","h_charge",6,-3,3);
  h_partonFlavor          = new TH1F("h_partonFlavor","h_partonFlavor",100,-50,50);
  h_B_SSV                 = new TH1F("h_B_SSV","h_B_SSV",100,-50,50);
  h_B_CSV                 = new TH1F("h_B_CSV","h_B_CSV",100,-50,50);
  h_B_SSVHE               = new TH1F("h_B_SSVHE","h_B_SSVHE",100,-50,50);
  h_B_CISVV2              = new TH1F("h_B_CISVV2","h_B_CISVV2",120,-10,2);
  h_B_TCHP                = new TH1F("h_B_TCHP","h_B_TCHP",100,-50,50);
  h_B_TCHE                = new TH1F("h_B_TCHE","h_B_TCHE",100,-50,50);
  h_B_JP                  = new TH1F("h_B_JP","h_B_JP",100,-50,50);
  h_B_JBP                 = new TH1F("h_B_JBP","h_B_JBP",100,-50,50);
  h_tau1                  = new TH1F("h_tau1","h_tau1",100,-50,50);
  h_tau2                  = new TH1F("h_tau2","h_tau2",100,-50,50);
  h_tau3                  = new TH1F("h_tau3","h_tau3",100,-50,50);
  h_jetMuEF               = new TH1F("h_jetMuEF","h_jetMuEF",100,-50,50);
  h_jetPhoEF              = new TH1F("h_jetPhoEF","h_jetPhoEF",100,-50,50);
  h_jetCEmEF              = new TH1F("h_jetCEmEF","h_jetCEmEF",100,-50,50);
  h_jetCHadEF             = new TH1F("h_jetCHadEF","h_jetCHadEF",100,-50,50);
  h_jetNEmEF              = new TH1F("h_jetNEmEF","h_jetNEmEF",100,-50,50);
  h_jetNHadEF             = new TH1F("h_jetNHadEF","h_jetNHadEF",100,-50,50);
  h_jetCMulti             = new TH1F("h_jetCMulti","h_jetCMulti",100,-50,50);
  h_jetHFHadEF            = new TH1F("h_jetHFHadEF","h_jetHFHadEF",100,-50,50);
  h_jetHFEMEF             = new TH1F("h_jetHFEMEF","h_jetHFEMEF",100,-50,50);
  h_jetCHHadMultiplicity  = new TH1F("h_jetCHHadMultiplicity","h_jetCHHadMultiplicity",100,-50,50);
  h_jetNHadMulplicity     = new TH1F("h_jetNHadMulplicity","h_jetNHadMulplicity",100,-50,50);
  h_jetPhMultiplicity     = new TH1F("h_jetPhMultiplicity","h_jetPhMultiplicity",100,-50,50);
  h_jetEleMultiplicity    = new TH1F("h_jetEleMultiplicity","h_jetEleMultiplicity",100,-50,50);
  h_jetHFHadMultiplicity  = new TH1F("h_jetHFHadMultiplicity","h_jetHFHadMultiplicity",100,-50,50);
  h_jetHFEMMultiplicity   = new TH1F("h_jetHFEMMultiplicity","h_jetHFEMMultiplicity",100,-50,50);
  h_jetChMuEF             = new TH1F("h_jetChMuEF","h_jetChMuEF",100,-50,50);
  h_jetNMultiplicity      = new TH1F("h_jetNMultiplicity","h_jetNMultiplicity",100,-50,50);
  h_jetHOEnergy           = new TH1F("h_jetHOEnergy","h_jetHOEnergy",100,-50,50);
  h_jetHOEF               = new TH1F("h_jetHOEF","h_jetHOEF",100,-50,50);
  
  h_tau21                 = new TH1F("h_tau21","h_tau21",100,-50,50);


}


void JetValidator::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  
  for(int i=0; i<4;i++){
    h_pt_vec[i]                    ->Write()   ;
    h_eta_vec[i]                   ->Write()   ;
    h_phi_vec[i]                   ->Write()   ;
    h_charge_vec[i]                ->Write()   ;
    h_partonFlavor_vec[i]          ->Write()   ;
    h_B_SSV_vec[i]                 ->Write()   ;
    h_B_CSV_vec[i]                 ->Write()   ;
    h_B_SSVHE_vec[i]               ->Write()   ;
    h_B_CISVV2_vec[i]              ->Write()   ;
    h_B_TCHP_vec[i]                ->Write()   ;
    h_B_TCHE_vec[i]                ->Write()   ;
    h_B_JP_vec[i]                  ->Write()   ;
    h_B_JBP_vec[i]                 ->Write()   ;
    h_tau1_vec[i]                  ->Write()   ;
    h_tau2_vec[i]                  ->Write()   ;
    h_tau3_vec[i]                  ->Write()   ;
    h_jetMuEF_vec[i]               ->Write()   ;
    h_jetPhoEF_vec[i]              ->Write()   ;
    h_jetCEmEF_vec[i]              ->Write()   ;
    h_jetCHadEF_vec[i]             ->Write()   ;
    h_jetNEmEF_vec[i]              ->Write()   ;
    h_jetNHadEF_vec[i]             ->Write()   ;
    h_jetCMulti_vec[i]             ->Write()   ;
    h_jetHFHadEF_vec[i]            ->Write()   ;
    h_jetHFEMEF_vec[i]             ->Write()   ;
    h_jetCHHadMultiplicity_vec[i]  ->Write()   ;
    h_jetNHadMulplicity_vec[i]     ->Write()   ;
    h_jetPhMultiplicity_vec[i]     ->Write()   ;
    h_jetEleMultiplicity_vec[i]    ->Write()   ;
    h_jetHFHadMultiplicity_vec[i]  ->Write()   ;
    h_jetHFEMMultiplicity_vec[i]   ->Write()   ;
    h_jetChMuEF_vec[i]             ->Write()   ;
    h_jetNMultiplicity_vec[i]      ->Write()   ;
    h_jetHOEnergy_vec[i]           ->Write()   ;
    h_jetHOEF_vec[i]               ->Write()   ;
    				   
    h_tau21_vec[i]                 ->Write()   ;      
    
  }

  h_nJets                ->Write();
  h_pt                   ->Write();
  h_eta                  ->Write();
  h_phi                  ->Write();
  h_charge               ->Write();
  h_partonFlavor         ->Write();
  h_B_SSV                ->Write();
  h_B_CSV                ->Write();
  h_B_SSVHE              ->Write();
  h_B_CISVV2             ->Write();
  h_B_TCHP               ->Write();
  h_B_TCHE               ->Write();
  h_B_JP                 ->Write();
  h_B_JBP                ->Write();
  h_tau1                 ->Write();
  h_tau2                 ->Write();
  h_tau3                 ->Write();
  h_jetMuEF              ->Write();
  h_jetPhoEF             ->Write();
  h_jetCEmEF             ->Write();
  h_jetCHadEF            ->Write();
  h_jetNEmEF             ->Write();
  h_jetNHadEF            ->Write();
  h_jetCMulti            ->Write();
  h_jetHFHadEF           ->Write();
  h_jetHFEMEF            ->Write();
  h_jetCHHadMultiplicity ->Write();
  h_jetNHadMulplicity    ->Write();
  h_jetPhMultiplicity    ->Write();
  h_jetEleMultiplicity   ->Write();
  h_jetHFHadMultiplicity ->Write();
  h_jetHFEMMultiplicity  ->Write();
  h_jetChMuEF            ->Write();
  h_jetNMultiplicity     ->Write();
  h_jetHOEnergy          ->Write();
  h_jetHOEF              ->Write();
  			   
  h_tau21                ->Write();
  
  
}
