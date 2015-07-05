#include "../interface/RKAnalyzer.h"
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
  time_t start, end;
  time(&start);
  
  TString input  = getenv("INPUT");
  TString output = getenv("OUTPUT");
  std::cout<<" input and output defined "<<std::endl;

  TString outfileName = getenv("OUTPUT");
  TString inputListName = getenv("INPUT");
  std::cout << "Output File Name: " << outfileName << std::endl;

  TChain *theChain = new TChain("tree/treeMaker");

  vector<TString> infileName_dump;
  
  // Find files to be run over and add to TChain
  ifstream inputList;
  inputList.open(inputListName);
  if( !inputList.good() ) { 
    std::cerr <<  
   "Can not open automatically generated input list file:  "
	      << inputListName 
	      << std::endl;
    abort();
  }
  

  /// Loop through lines in file (paths to .root files)
      // and add to TChain
      TString infileName = ""; 
      TFile* f;
      TH1F* h_ntotal;
  while( !inputList.eof() ) { 
    infileName="";
    inputList >> infileName;
    
    std::cout << " Input File Name: "  << infileName <<  std::endl;
    theChain->Add( infileName );
    infileName_dump.push_back(infileName);
    //f = TFile::Open(infileName);
    //f->cd();
    //if( !f || !f->IsOpen() ) h_ntotal = dynamic_cast<TH1F*> (f->Get("allEventsCounter/totalEvents"));
  }
 
  
  RKAnalyzer analyzer;
  // Initialize and run analyzer on TChain
  analyzer.Init(theChain);
  analyzer.Loop(outfileName);
  //analyzer.TotalEvent(infileName_dump);
  //analyzer.TotalEvent(h_ntotal);
  
  time(&end);
  std::cout<<" time used is = "<<-(start-end)<<" seconds"<<std::endl;
  
  return 0;
}
