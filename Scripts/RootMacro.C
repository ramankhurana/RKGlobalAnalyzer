#include "TString.h"
#include "TFile.h"
#include <iostream>
using namespace std;
void RootMacro(TString inputrootfile, TString outputrootfile){
  TFile* f = new TFile(inputrootfile, "READ");
  f->cd();
  
  
  TFile* fout = new TFile(outputrootfile,"RECREATE");
  std::cout<<" script processed "<<std::endl;

}
