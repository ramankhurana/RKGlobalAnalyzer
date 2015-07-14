
// Original class : Electron.h 
// Created By     : khurana
// On             : Sat Apr 25 23:49:19 CEST 2015

#ifndef Electron_h_
#define Electron_h_
#include <iostream>
#include <TLorentzVector.h>
class Electron {
 public:
  // Variables for corrected Electron
  Electron(){};
  ~Electron(){};
  
  //IDs
  Bool_t IsPassVeto; 
  Bool_t IsPassLoose; 
  Bool_t IsPassMedium; 
  Bool_t IsPassTight; 
  Bool_t IsPassHEEP;  
  Bool_t IsMVATrig;  //Add This
  Bool_t IsMVANonTrig;
  Float_t MVATrig;
  Float_t MVANonTrig;

  TLorentzVector p4;
  Int_t nElectron;
  Int_t  charge;
  Float_t r9;
  
  Float_t  etSC;
  Float_t  etaSC;
  Float_t  energySC;
  Float_t  preenergySC;
  Float_t  phiSC;
  Float_t  dEtaIn;
  Float_t  dPhiIn;
  Float_t  hOverE;
  Float_t  full5x5_sigmaIetaIeta;
  Float_t  eoverP;
  Float_t  eoverPInv;
  Float_t  brem;
  Float_t  dEtaWidth;
  Float_t  dPhiWidth;


  Float_t  isoChargedHadrons;
  Float_t  isoNeutralHadrons;
  Float_t  isoPhotons;
  Float_t  isoChargedFromPU; //add in main code
  Float_t  isoDeltaBeta;
  Float_t  isoRho;
  //Float_t  ooEmooP;  //same as eoverpinv
  Float_t  d0;     //fix it 
  Float_t  dz;
  Int_t    expectedMissingInnerHits;
  Int_t    passConversionVeto;
  Bool_t   barrel; 
  Bool_t   endcap; 
  Bool_t   trigger;
  bool operator== (Electron& other_){
    return((this->p4.Pt()==other_.p4.Pt()) && (this->charge == other_.charge));
  }
  void Clear(){

    IsPassVeto= 0;
     IsPassLoose= 0;
     IsPassMedium= 0;
     IsPassTight= 0;
     IsPassHEEP= 0;
     IsMVATrig= 0;
     IsMVANonTrig= 0;
     MVATrig= 0;
     MVANonTrig= 0;
     p4.SetPxPyPzE(0.,0.,0.,0.);
     nElectron= 0;
     charge= 0;
     r9= 0;
     etSC= 0;
     etaSC= 0;
     energySC= 0;
     preenergySC= 0;
     phiSC= 0;
     dEtaIn= 0;
     dPhiIn= 0;
     hOverE= 0;
     full5x5_sigmaIetaIeta= 0;
     eoverP= 0;
     eoverPInv= 0;
     brem= 0;
     dEtaWidth= 0;
     dPhiWidth= 0;
  
     isoChargedHadrons= 0;
     isoNeutralHadrons= 0;
     isoPhotons= 0;
     isoChargedFromPU= 0; //add in main code  //nothing just to make corrections
     // two type of isolation                                                                                            
     isoDeltaBeta= 0;
     isoRho= 0;
     d0= 0;    
     dz= 0;
     expectedMissingInnerHits= 0;
     passConversionVeto= 0;
     barrel= 0;
     endcap= 0;
     trigger=false;



     

  }
  protected:

  private:

};
#endif
