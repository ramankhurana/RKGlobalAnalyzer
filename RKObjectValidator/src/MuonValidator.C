#define MuonValidator_cxx
#include"../interface/MuonValidator.h"
void MuonValidator::Fill(std::vector<Muon> muoncollection){
  h_nMu->Fill(muoncollection.size());
  for (int i=0; i< (int) muoncollection.size(); i++){
    // Fill First Four Jets Properties 
    if(i<4){
      h_pt[i]->Fill(muoncollection[i].p4.Pt());
      h_eta[i]->Fill(muoncollection[i].p4.Eta());
      h_phi[i]->Fill(muoncollection[i].p4.Phi());
      h_mass[i]->Fill(muoncollection[i].p4.Mag());
      h_Type[i]->Fill(muoncollection[i].Type);
      h_Charge[i]->Fill(muoncollection[i].Charge);
      h_IsGlobalMuon[i]->Fill(muoncollection[i].IsGlobalMuon);
      h_IsTrackerMuon[i]->Fill(muoncollection[i].IsTrackerMuon);
      h_IsPFMuon [i]->Fill(muoncollection[i].IsPFMuon);
      h_TrkPt [i]->Fill(muoncollection[i].TrkPt);
      h_TrkPtErr [i]->Fill(muoncollection[i].TrkPtErr);
      h_dxy[i]->Fill(muoncollection[i].dxy);
      h_dz[i]->Fill(muoncollection[i].dz);
      h_segmentCompatibility[i]->Fill(muoncollection[i].segmentCompatibility);
      h_chi2LocalPosition[i]->Fill(muoncollection[i].chi2LocalPosition);
      h_trkKink[i]->Fill(muoncollection[i].trkKink);
      h_Innerdxy_[i]->Fill(muoncollection[i].Innerdxy_);
      h_Innerdz_ [i]->Fill(muoncollection[i].Innerdz_);
      h_TrkLayers[i]->Fill(muoncollection[i].TrkLayers);
      h_PixelLayers [i]->Fill(muoncollection[i].PixelLayers);
      h_PixelHits[i]->Fill(muoncollection[i].PixelHits);
      h_TrkQuality_ [i]->Fill(muoncollection[i].TrkQuality_);
      h_Hits[i]->Fill(muoncollection[i].Hits);
      h_Chi2NDF[i]->Fill(muoncollection[i].Chi2NDF);
      h_InnervalidFraction_[i]->Fill(muoncollection[i].InnervalidFraction_);
      h_Matches[i]->Fill(muoncollection[i].Matches);
      h_ITrkID[i]->Fill(muoncollection[i].ITrkID);
      h_SegID [i]->Fill(muoncollection[i].SegID);
      h_NSegs [i]->Fill(muoncollection[i].NSegs);
      h_IsGood_TrackerMuonArbitrated [i]->Fill(muoncollection[i].IsGood_TrackerMuonArbitrated);
      h_IsGood_TMOneStationTight[i]->Fill(muoncollection[i].IsGood_TMOneStationTight);
      h_TrkIso[i]->Fill(muoncollection[i].TrkIso);
      h_HcalIso[i]->Fill(muoncollection[i].HcalIso);
      h_EcalIso[i]->Fill(muoncollection[i].EcalIso);
      h_ChHadIso [i]->Fill(muoncollection[i].ChHadIso);
      h_NeHadIso [i]->Fill(muoncollection[i].NeHadIso);
      h_GamIso[i]->Fill(muoncollection[i].GamIso);
      h_PUPt[i]->Fill(muoncollection[i].PUPt);
      
    }// if(i<4)
    
  }
  
}



void MuonValidator::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  std::cout<<" calling define histograms for Jets"<<std::endl;
  DefineHistograms();
  std::cout<<" Jets histo defined"<<std::endl;
}


void MuonValidator::DefineHistograms(){
  h_nMu= new TH1F("h_nMu","",100,0,100);
  TString postfix;
  for(int i=0; i<4;i++){
    postfix.Form("%d",i);
    h_pt[i]= new TH1F("h_pt"+postfix,"",100,0,100);
    h_eta[i]= new TH1F("h_eta"+postfix,"",100,0,100);
    h_phi[i]= new TH1F("h_phi"+postfix,"",100,0,100);
    h_mass[i]= new TH1F("h_mass"+postfix,"",100,0,100);
    h_Type[i]= new TH1F("h_Type"+postfix,"",100,0,100);
    h_Charge[i]= new TH1F("h_Charge"+postfix,"",100,0,100);
    h_IsGlobalMuon[i]= new TH1F("h_IsGlobalMuon"+postfix,"",100,0,100);
    h_IsTrackerMuon[i]= new TH1F("h_IsTrackerMuon"+postfix,"",100,0,100);
    h_IsPFMuon[i]= new TH1F("h_IsPFMuon"+postfix,"",100,0,100);
    h_TrkPt[i]= new TH1F("h_TrkPt"+postfix,"",100,0,100);
    h_TrkPtErr[i]= new TH1F("h_TrkPtErr"+postfix,"",100,0,100);
    h_dxy[i]= new TH1F("h_dxy"+postfix,"",100,0,100);
    h_dz[i]= new TH1F("h_dz"+postfix,"",100,0,100);
    h_segmentCompatibility[i]= new TH1F("h_segmentCompatibility"+postfix,"",100,0,100);
    h_chi2LocalPosition[i]= new TH1F("h_chi2LocalPosition"+postfix,"",100,0,100);
    h_trkKink[i]= new TH1F("h_trkKink"+postfix,"",100,0,100);
    h_Innerdxy_[i]= new TH1F("h_Innerdxy_"+postfix,"",100,0,100);
    h_Innerdz_[i]= new TH1F("h_Innerdz_"+postfix,"",100,0,100);
    h_TrkLayers[i]= new TH1F("h_TrkLayers"+postfix,"",100,0,100);
    h_PixelLayers[i]= new TH1F("h_PixelLayers"+postfix,"",100,0,100);
    h_PixelHits[i]= new TH1F("h_PixelHits"+postfix,"",100,0,100);
    h_TrkQuality_[i]= new TH1F("h_TrkQuality_"+postfix,"",100,0,100);
    h_Hits[i]= new TH1F("h_Hits"+postfix,"",100,0,100);
    h_Chi2NDF[i]= new TH1F("h_Chi2NDF"+postfix,"",100,0,100);
    h_InnervalidFraction_[i]= new TH1F("h_InnervalidFraction_"+postfix,"",100,0,100);
    h_Matches[i]= new TH1F("h_Matches"+postfix,"",100,0,100);
    h_ITrkID[i]= new TH1F("h_ITrkID"+postfix,"",100,0,100);
    h_SegID[i]= new TH1F("h_SegID"+postfix,"",100,0,100);
    h_NSegs[i]= new TH1F("h_NSegs"+postfix,"",100,0,100);
    h_IsGood_TrackerMuonArbitrated[i]= new TH1F("h_IsGood_TrackerMuonArbitrated"+postfix,"",100,0,100);
    h_IsGood_TMOneStationTight[i]= new TH1F("h_IsGood_TMOneStationTight"+postfix,"",100,0,100);
    h_TrkIso[i]= new TH1F("h_TrkIso"+postfix,"",100,0,100);
    h_HcalIso[i]= new TH1F("h_HcalIso"+postfix,"",100,0,100);
    h_EcalIso[i]= new TH1F("h_EcalIso"+postfix,"",100,0,100);
    h_ChHadIso[i]= new TH1F("h_ChHadIso"+postfix,"",100,0,100);
    h_NeHadIso[i]= new TH1F("h_NeHadIso"+postfix,"",100,0,100);
    h_GamIso[i]= new TH1F("h_GamIso"+postfix,"",100,0,100);
    h_PUPt[i]= new TH1F("h_PUPt"+postfix,"",100,0,100);
    
    
  }
}


void MuonValidator::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  h_nMu->Write();

  for(int i=0; i<4;i++){
    h_pt[i]->Write();
    h_eta[i]->Write();
    h_phi[i]->Write();
    h_mass[i]->Write();
    h_Type[i]->Write();
    h_Charge[i]->Write();
    h_IsGlobalMuon[i]->Write();
    h_IsTrackerMuon[i]->Write();
    h_IsPFMuon[i]->Write();
    h_TrkPt[i]->Write();
    h_TrkPtErr[i]->Write();
    h_dxy[i]->Write();
    h_dz[i]->Write();
    h_segmentCompatibility[i]->Write();
    h_chi2LocalPosition[i]->Write();
    h_trkKink[i]->Write();
    h_Innerdxy_[i]->Write();
    h_Innerdz_[i]->Write();
    h_TrkLayers[i]->Write();
    h_PixelLayers[i]->Write();
    h_PixelHits[i]->Write();
    h_TrkQuality_[i]->Write();
    h_Hits[i]->Write();
    h_Chi2NDF[i]->Write();
    h_InnervalidFraction_[i]->Write();
    h_Matches[i]->Write();
    h_ITrkID[i]->Write();
    h_SegID[i]->Write();
    h_NSegs[i]->Write();
    h_IsGood_TrackerMuonArbitrated[i]->Write();
    h_IsGood_TMOneStationTight[i]->Write();
    h_TrkIso[i]->Write();
    h_HcalIso[i]->Write();
    h_EcalIso[i]->Write();
    h_ChHadIso[i]->Write();
    h_NeHadIso[i]->Write();
    h_GamIso[i]->Write();
    h_PUPt[i]->Write();
  }

}
