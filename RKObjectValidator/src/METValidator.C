#define METValidator_cxx
#include "../interface/METValidator.h"
void METValidator::Fill(MET metcollection){
    
  // Fill properties of all type of MET
  h_CorrPt      ->Fill(metcollection.CorrPt       );
  h_CorrPhi	 ->Fill(metcollection.CorrPhi	  );
  h_CorrSumEt	 ->Fill(metcollection.CorrSumEt	  );
  h_CorrSig	 ->Fill(metcollection.CorrSig	  );
  h_RawPt  	 ->Fill(metcollection.RawPt  	  );
  h_RawPhi	 ->Fill(metcollection.RawPhi	  );
  h_RawSumEt	 ->Fill(metcollection.RawSumEt	  );
  h_RawCov00	 ->Fill(metcollection.RawCov00	  );
  h_RawCov01	 ->Fill(metcollection.RawCov01	  );
  h_RawCov10	 ->Fill(metcollection.RawCov10	  );
  h_RawCov11	 ->Fill(metcollection.RawCov11	  );
  h_mvaPt	 ->Fill(metcollection.mvaPt	  );
  h_mvaPhi	 ->Fill(metcollection.mvaPhi	  );
  h_mvaSumEt	 ->Fill(metcollection.mvaSumEt	  );
  h_mvaSig      ->Fill(metcollection.mvaSig       );
      
}



void METValidator::GetInputs(TFile* f, TString prefix_){
  prefix = prefix_;
  file = f;
  if(false) std::cout <<" calling define histograms for MET "<<std::endl;
  DefineHistograms();
  if (false) std::cout <<" MET histo defined "<<std::endl;
}


void METValidator::DefineHistograms(){
  TString postfix;
  h_CorrPt       = new TH1F("h_CorrPt","h_CorrPt",200,0,1000);
  h_CorrPhi	 = new TH1F("h_CorrPhi","h_CorrPhi",70,-3.5,3.5);
  h_CorrSumEt	 = new TH1F("h_CorrSumEt","h_CorrSumEt",200,0,1000);
  h_CorrSig	 = new TH1F("h_CorrSig","h_CorrSig",100,-50,50);
  h_RawPt  	 = new TH1F("h_RawPt","h_RawPt",200,0,1000);
  h_RawPhi	 = new TH1F("h_RawPhi","h_RawPhi",70,-3.5,3.5);
  h_RawSumEt	 = new TH1F("h_RawSumEt","h_RawSumEt",200,0,1000);
  h_RawCov00	 = new TH1F("h_RawCov00","h_RawCov00",200,0,1000);
  h_RawCov01	 = new TH1F("h_RawCov01","h_RawCov01",200,0,1000);
  h_RawCov10	 = new TH1F("h_RawCov10","h_RawCov10",200,0,1000);
  h_RawCov11	 = new TH1F("h_RawCov11","h_RawCov11",200,0,1000);
  h_mvaPt	 = new TH1F("h_mvaPt","h_mvaPt",200,0,1000);
  h_mvaPhi	 = new TH1F("h_mvaPhi","h_mvaPhi",70,-3.5,3.5);
  h_mvaSumEt	 = new TH1F("h_mvaSumEt","h_mvaSumEt",200,0,1000);
  h_mvaSig       = new TH1F("h_mvaSig","h_mvaSig",100,-50,50);


}


void METValidator::Write(){
  file->cd();
  file->mkdir(prefix);
  file->cd(prefix);
  
  h_CorrPt    ->Write()   ; 
  h_CorrPhi   ->Write()   ; 
  h_CorrSumEt ->Write()   ; 
  h_CorrSig   ->Write()   ; 
  h_RawPt     ->Write()   ; 
  h_RawPhi    ->Write()   ; 
  h_RawSumEt  ->Write()   ; 
  h_RawCov00  ->Write()   ; 
  h_RawCov01  ->Write()   ; 
  h_RawCov10  ->Write()   ; 
  h_RawCov11  ->Write()   ; 
  h_mvaPt     ->Write()   ; 
  h_mvaPhi    ->Write()   ; 
  h_mvaSumEt  ->Write()   ; 
  h_mvaSig    ->Write()   ; 

  
  
}
