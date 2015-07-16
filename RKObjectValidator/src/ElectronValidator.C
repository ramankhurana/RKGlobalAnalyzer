#define ElectronValidator_cxx
#include "../interface/ElectronValidator.h"
void ElectronValidator::Fill(std::vector<Electron> electroncollection){
  
  h_nElectron->Fill(electroncollection.size());
  for (int i=0; i< (int) electroncollection.size(); i++){
      h_pt[4]->Fill(electroncollection[i].p4.Pt());
      h_eta[4]->Fill(electroncollection[i].p4.Eta());
      h_phi[4]->Fill(electroncollection[i].p4.Phi());
      h_IsPassVeto[4]->Fill(electroncollection[i].IsPassVeto);
      h_IsPassLoose[4]->Fill(electroncollection[i].IsPassLoose);
      h_IsPassMedium[4]->Fill(electroncollection[i].IsPassMedium);
      h_IsPassTight[4]->Fill(electroncollection[i].IsPassTight);
      h_IsPassHEEP[4]->Fill(electroncollection[i].IsPassHEEP);
      h_IsMVATrig[4]->Fill(electroncollection[i].IsMVATrig);  //Add This
      h_IsMVANonTrig[4]->Fill(electroncollection[i].IsMVANonTrig);
      h_MVATrig[4]->Fill(electroncollection[i].MVATrig);
      h_MVANonTrig[4]->Fill(electroncollection[i].MVANonTrig);
      h_charge[4]->Fill(electroncollection[i].charge);
      h_r9[4]->Fill(electroncollection[i].r9);

      h_etSC[4]->Fill(electroncollection[i].etSC);
      h_etaSC[4]->Fill(electroncollection[i].etaSC);
      h_energySC[4]->Fill(electroncollection[i].energySC);
      h_preenergySC[4]->Fill(electroncollection[i].preenergySC);
      h_phiSC[4]->Fill(electroncollection[i].phiSC);
      h_dEtaIn[4]->Fill(electroncollection[i].dEtaIn);
      h_dPhiIn[4]->Fill(electroncollection[i].dPhiIn);
      h_hOverE[4]->Fill(electroncollection[i].hOverE);
      h_full5x5_sigmaIetaIeta[4]->Fill(electroncollection[i].full5x5_sigmaIetaIeta);
      h_eoverP[4]->Fill(electroncollection[i].eoverP);
      h_eoverPInv[4]->Fill(electroncollection[i].eoverPInv);
      h_brem[4]->Fill(electroncollection[i].brem);
      h_dEtaWidth[4]->Fill(electroncollection[i].dEtaWidth);
      h_dPhiWidth[4]->Fill(electroncollection[i].dPhiWidth);
      h_isoChargedHadrons[4]->Fill((electroncollection[i].isoChargedHadrons)/(electroncollection[i].p4.Pt()));
      h_isoNeutralHadrons[4]->Fill((electroncollection[i].isoNeutralHadrons)/(electroncollection[i].p4.Pt()));
      h_isoPhotons[4]->Fill((electroncollection[i].isoPhotons)/(electroncollection[i].p4.Pt()));
      h_isoChargedFromPU[4]->Fill((electroncollection[i].isoChargedFromPU)/(electroncollection[i].p4.Pt())); //add in main code
      h_isoDeltaBeta[4]->Fill((electroncollection[i].isoDeltaBeta)/(electroncollection[i].p4.Pt()));
      h_isoRho[4]->Fill((electroncollection[i].isoRho)/(electroncollection[i].p4.Pt()));
      h_d0[4]->Fill(electroncollection[i].d0);     //fix it 
      h_dz[4]->Fill(electroncollection[i].dz);
      h_expectedMissingInnerHits[4]->Fill(electroncollection[i].expectedMissingInnerHits);
      h_passConversionVeto[4]->Fill(electroncollection[i].passConversionVeto);
      h_barrel[4]->Fill(electroncollection[i].barrel);
      h_endcap[4]->Fill(electroncollection[i].endcap);




    // Fill First Four Jets Properties 
    if(i<4){
      h_pt[i]->Fill(electroncollection[i].p4.Pt());
      h_eta[i]->Fill(electroncollection[i].p4.Eta());   
      h_phi[i]->Fill(electroncollection[i].p4.Phi());  
      h_IsPassVeto[i]->Fill(electroncollection[i].IsPassVeto); 
      h_IsPassLoose[i]->Fill(electroncollection[i].IsPassLoose); 
      h_IsPassMedium[i]->Fill(electroncollection[i].IsPassMedium); 
      h_IsPassTight[i]->Fill(electroncollection[i].IsPassTight); 
      h_IsPassHEEP[i]->Fill(electroncollection[i].IsPassHEEP);  
      h_IsMVATrig[i]->Fill(electroncollection[i].IsMVATrig);  //Add This
      h_IsMVANonTrig[i]->Fill(electroncollection[i].IsMVANonTrig);
      h_MVATrig[i]->Fill(electroncollection[i].MVATrig);
      h_MVANonTrig[i]->Fill(electroncollection[i].MVANonTrig);
      h_charge[i]->Fill(electroncollection[i].charge);
      h_r9[i]->Fill(electroncollection[i].r9);
      
      h_etSC[i]->Fill(electroncollection[i].etSC);
      h_etaSC[i]->Fill(electroncollection[i].etaSC);
      h_energySC[i]->Fill(electroncollection[i].energySC);
      h_preenergySC[i]->Fill(electroncollection[i].preenergySC);
      h_phiSC[i]->Fill(electroncollection[i].phiSC);
      h_dEtaIn[i]->Fill(electroncollection[i].dEtaIn);
      h_dPhiIn[i]->Fill(electroncollection[i].dPhiIn);
      h_hOverE[i]->Fill(electroncollection[i].hOverE);
      h_full5x5_sigmaIetaIeta[i]->Fill(electroncollection[i].full5x5_sigmaIetaIeta);
      h_eoverP[i]->Fill(electroncollection[i].eoverP);
      h_eoverPInv[i]->Fill(electroncollection[i].eoverPInv);
      h_brem[i]->Fill(electroncollection[i].brem);
      h_dEtaWidth[i]->Fill(electroncollection[i].dEtaWidth);
      h_dPhiWidth[i]->Fill(electroncollection[i].dPhiWidth);
      h_isoChargedHadrons[i]->Fill((electroncollection[i].isoChargedHadrons)/(electroncollection[i].p4.Pt()));
      h_isoNeutralHadrons[i]->Fill((electroncollection[i].isoNeutralHadrons)/(electroncollection[i].p4.Pt()));
      h_isoPhotons[i]->Fill((electroncollection[i].isoPhotons)/(electroncollection[i].p4.Pt()));
      h_isoChargedFromPU[i]->Fill((electroncollection[i].isoChargedFromPU)/(electroncollection[i].p4.Pt())); //add in main code
      h_isoDeltaBeta[i]->Fill((electroncollection[i].isoDeltaBeta)/(electroncollection[i].p4.Pt()));
      h_isoRho[i]->Fill((electroncollection[i].isoRho)/(electroncollection[i].p4.Pt()));
      // h_ooEmooP[i]->Fill(electroncollection[i].ooEmooP);
      h_d0[i]->Fill(electroncollection[i].d0);     //fix it 
      h_dz[i]->Fill(electroncollection[i].dz);
      h_expectedMissingInnerHits[i]->Fill(electroncollection[i].expectedMissingInnerHits);
      h_passConversionVeto[i]->Fill(electroncollection[i].passConversionVeto);
      h_barrel[i]->Fill(electroncollection[i].barrel); 
      h_endcap[i]->Fill(electroncollection[i].endcap);
      
    }// if(i<4)
  }
}



void ElectronValidator::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for Jets "<<std::endl;
  DefineHistograms();
  std::cout<<" Jets histo defined "<<std::endl;
}


void ElectronValidator::DefineHistograms(){
  TString postfix;
  for(int i=0; i<5;i++){
    postfix.Form("%d",i);
    h_pt[i]                         =  new TH1F("h_pt"+postfix,"",100,0.,700.);
    h_eta[i]                        =  new TH1F("h_eta"+postfix,"",48,-2.4,2.4);
    h_phi[i]                        =  new TH1F("h_phi"+postfix,"",70,-3.5,3.5);
    h_IsPassVeto[i]                 =  new TH1F("h_IsPassVeto"+postfix,"",2,0,2);
    h_IsPassLoose[i]                =  new TH1F("h_IsPassLoose"+postfix,"",2,0,2);
    h_IsPassMedium[i]               =  new TH1F("h_IsPassMedium"+postfix,"",2,0,2);
    h_IsPassTight[i]                =  new TH1F("h_IsPassTight"+postfix,"",2,0,2);
    h_IsPassHEEP[i]                 =  new TH1F("h_IsPassHEEP"+postfix,"",2,0,2);
    h_IsMVATrig[i]                  =  new TH1F("h_IsMVATrig"+postfix,"",2,0,2);
    h_IsMVANonTrig[i]               =  new TH1F("h_IsMVANonTrig"+postfix,"",2,0,2);
    h_MVATrig[i]                    =  new TH1F("h_MVATrig"+postfix,"",40,0.,1.);
    h_MVANonTrig[i]                 =  new TH1F("h_MVANonTrig"+postfix,"",40,0.,1.);
   
    h_charge[i]                     =  new TH1F("h_charge"+postfix,"",14,-2,2);
    h_r9[i]                         =  new TH1F("h_r9"+postfix,"",100,0,2);
    h_etSC[i]                       =  new TH1F("h_etSC"+postfix,"",105,0.,700.);
    h_etaSC[i]                      =  new TH1F("h_etaSC"+postfix,"",48,-2.4,2.4);
    h_energySC[i]                   =  new TH1F("h_energySC"+postfix,"",100,0.,1000);
    h_preenergySC[i]                =  new TH1F("h_preenergySC"+postfix,"",100,0.,1000.);
    h_phiSC[i]                      =  new TH1F("h_phiSC"+postfix,"",70,-3.5,3.5);
    h_dEtaIn[i]                     =  new TH1F("h_dEtaIn"+postfix,"",260,0.0,0.01);
    h_dPhiIn[i]                     =  new TH1F("h_dPhiIn"+postfix,"",160,0.0,0.08);
    h_hOverE[i]                     =  new TH1F("h_hOverE"+postfix,"",100,0.,0.1);
    h_full5x5_sigmaIetaIeta[i]      =  new TH1F("h_full5x5_sigmaIetaIeta"+postfix,"",100,0.,0.1);
    h_eoverP[i]                     =  new TH1F("h_eoverP"+postfix,"",400,0,0.5);
    h_eoverPInv[i]                  =  new TH1F("h_eoverPInv"+postfix,"",400,0.,0.5);
    h_brem[i]                       =  new TH1F("h_brem"+postfix,"",100,0,100);
    h_dEtaWidth[i]                    =  new TH1F("h_dEtaVtx"+postfix,"",100,0,100);
    h_dPhiWidth[i]                    =  new TH1F("h_dPhiVtx"+postfix,"",100,0,100);
    h_isoChargedHadrons[i]          =  new TH1F("h_isoChargedHadrons"+postfix,"",100,0,2);
    h_isoNeutralHadrons[i]          =  new TH1F("h_isoNeutralHadrons"+postfix,"",100,0,2);
    h_isoPhotons[i]                 =  new TH1F("h_isoPhotons"+postfix,"",100,0,2);
    h_isoChargedFromPU[i]           =  new TH1F("h_isoChargedFromPU"+postfix,"",100,0,2);
    h_isoDeltaBeta[i]               =  new TH1F("h_isoDeltaBeta"+postfix,"",100,0,2);
    h_isoRho[i]                     =  new TH1F("h_isoRho"+postfix,"",100,0,2);
    //    h_ooEmooP[i]                    =  new TH1F("h_ooEmooP"+postfix,"",400,0.,0.5);
    h_d0[i]                         =  new TH1F("h_d0"+postfix,"",10000,0,100);
    h_dz[i]                         =  new TH1F("h_dz"+postfix,"",10000,0,100);
    h_expectedMissingInnerHits[i]   =  new TH1F("h_expectedMissingInnerHits"+postfix,"",8,-1,7);
    h_passConversionVeto[i]         =  new TH1F("h_passConversionVeto"+postfix,"",5,-1,4);
    h_barrel[i]                     =  new TH1F("h_barrel"+postfix,"",2,0,2);
    h_endcap[i]                     =  new TH1F("h_endcap"+postfix,"",2,0,2);

    
  }

    h_nElectron                      =  new TH1F("h_nelectrons"+postfix,"",10,0,10);  

}


void ElectronValidator::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  
  for(int i=0; i<5;i++){
     h_pt[i]                         ->Write();   
     h_eta[i]                        ->Write();
     h_phi[i]                        ->Write();
     h_IsPassVeto[i]                 ->Write();
     h_IsPassLoose[i]                ->Write();
     h_IsPassMedium[i]               ->Write();
     h_IsPassTight[i]                ->Write();
     h_IsPassHEEP[i]                 ->Write();
     h_IsMVATrig[i]                  ->Write();
     h_IsMVANonTrig[i]               ->Write();
     h_MVATrig[i]                    ->Write();
     h_MVANonTrig[i]                 ->Write();
                                      
     h_charge[i]                     ->Write();
     h_r9[i]                         ->Write();
     h_etSC[i]                       ->Write();
     h_etaSC[i]                      ->Write();
     h_energySC[i]                   ->Write();
     h_preenergySC[i]                ->Write();
     h_phiSC[i]                      ->Write();
     h_dEtaIn[i]                     ->Write();
     h_dPhiIn[i]                     ->Write();
     h_hOverE[i]                     ->Write();
     h_full5x5_sigmaIetaIeta[i]      ->Write();
     h_eoverP[i]                     ->Write();
     h_eoverPInv[i]                  ->Write();
     h_brem[i]                       ->Write();
     h_dEtaWidth[i]                    ->Write();
     h_dPhiWidth[i]                    ->Write();
     h_isoChargedHadrons[i]          ->Write();
     h_isoNeutralHadrons[i]          ->Write();
     h_isoPhotons[i]                 ->Write();
     h_isoChargedFromPU[i]           ->Write();
     h_isoDeltaBeta[i]               ->Write();
     h_isoRho[i]                     ->Write();
     //h_ooEmooP[i]                    ->Write();
     h_d0[i]                         ->Write();
     h_dz[i]                         ->Write();
     h_expectedMissingInnerHits[i]   ->Write();
     h_passConversionVeto[i]         ->Write();
     h_barrel[i]                     ->Write();
     h_endcap[i]                     ->Write();
     
  }
  h_nElectron                      ->Write();
  
}
