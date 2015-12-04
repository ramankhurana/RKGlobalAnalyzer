#if  !defined(__CINT__) || defined (__MAKECINT__)
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <TROOT.h>
#include <TString.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TCanvas.h>
#include <TMarker.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <TH1F.h>
#include <TH2F.h>
#include <THStack.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TCut.h>
#include <TGraph.h>
#include <TLorentzVector.h>
#include <TClonesArray.h>
#include <TMath.h>
#include <Math/VectorUtil.h>
#include <TF1.h>
#include <TLegend.h>
#endif
using namespace std;

void pileup(){
Int_t  nsimvertex;

TH1F * pileup   = new TH1F( "pileup", "pileup", 60, 0., 60.);

//TFile* file_mc = new TFile("/media/Elements/Background_2011/result.root");
TFile* file_mc = new TFile("QCD_Inf.root"); 

   TTree *tree= (TTree*)file_mc->Get("t1");
   tree->SetBranchAddress("nsimvertex",&nsimvertex);
   int entry = tree->GetEntries();
    
   //  pileup->Draw();
   //  TH1F *pileupMC = (TH1F*) file_mc->Get("nsimvertex");
   TFile efile("MyPileupMC2013QCD_Inf.root","recreate");  
   for (Int_t im = 0; im < entry ; im++) {
      tree->GetEntry(im);   
      pileup->Fill(nsimvertex);
      
      }
      pileup->Write();
/*   for(Int_t im =0; im<100; im++){ 
     if(im < 36) {
     nvtx_mc[im] = pileup->GetBinContent(im+1);
     } else {
       nvtx_mc[im] = 0.;
     }
     cout <<" MC bin im = " << im <<"  bin content = " << nvtx_mc[im] << endl; 
   }*/

}


