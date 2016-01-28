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
      TString running_mode="all" ;
      int i=0;
      while( !inputList.eof() ) { 
	infileName="";
	inputList >> infileName;
	TString filename_in = infileName;
	if (i==0) {
	  // for DYToEE M50
	  if(filename_in.Contains("DYJetsToEE")) {
	    if(filename_in.Contains("DYJetsToLL_M-50_")) {
	      running_mode = "DYEE50To200";
	    }
	    else {
	      running_mode = "DYEE";
	    }
	  }
	  if(filename_in.Contains("DYJetsToTauTau")){
	    if(filename_in.Contains("DYJetsToLL_M-50_")){
	      running_mode = "DYTauTau50To200";
	    }
	    else {
	      running_mode = "DYTauTau";
	    }
	  }
	  i++; 
	}
	std::cout << " Input File Name: "  << infileName<<"Mode :"  << running_mode <<  std::endl;
	theChain->Add( infileName );
	infileName_dump.push_back(infileName);
	
	//f = TFile::Open(infileName);
    //f->cd();
    //if( !f || !f->IsOpen() ) h_ntotal = dynamic_cast<TH1F*> (f->Get("allEventsCounter/totalEvents"));
  }
 
  
  RKAnalyzer analyzer;
  // Initialize and run analyzer on TChain
  analyzer.Init(theChain);
  analyzer.Loop(outfileName,running_mode);
  //analyzer.TotalEvent(infileName_dump);
  //analyzer.TotalEvent(h_ntotal);
  
  time(&end);
  std::cout<<" time used is = "<<-(start-end)<<" seconds"<<std::endl;
  
  return 0;
}
