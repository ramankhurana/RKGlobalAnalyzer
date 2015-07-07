#define ElectronValidator_cxx
#include "../interface/ElectronValidator.h"
void ElectronValidator::Fill(std::vector<Electron> electroncollection){
  for (int i=0; i< (int) electroncollection.size(); i++){
    // Fill First Four Jets Properties 
    h_nElectron->Fill(electroncollection.size());
    if(i<4){
      h_pt[i]->Fill(electroncollection[i].p4.Pt());
      h_eta[i]->Fill(electroncollection[i].p4.Eta());   
      h_phi[i]->Fill(electroncollection[i].Phi());  
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
      h_dEtaVtx[i]->Fill(electroncollection[i].dEtaVtx);
      h_dPhiVtx[i]->Fill(electroncollection[i].dPhiVtx);
      h_isoChargedHadrons[i]->Fill(electroncollection[i].isoChargedHadrons);
      h_isoNeutralHadrons[i]->Fill(electroncollection[i].isoNeutralHadrons);
      h_isoPhotons[i]->Fill(electroncollection[i].isoPhotons);
      h_isoChargedFromPU[i]->Fill(electroncollection[i].isoChargedFromPU); //add in main code
      h_isoDeltaBeta[i]->Fill(electroncollection[i].isoDeltaBeta);
      h_isoRho[i]->Fill(electroncollection[i].isoRho);
      h_ooEmooP[i]->Fill(electroncollection[i].ooEmooP);
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
  for(int i=0; i<4;i++){
    postfix.Form("%d",i);
    
  }
}


void ElectronValidator::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  
  for(int i=0; i<4;i++){
  
  }
`}
