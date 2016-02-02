#include "../interface/RKAnalyzer.h"
#include <ctime>
#include <iostream>

using namespace std;
int main(int argc, char *argv[]){
  time_t start, end;
  time(&start);

  if(argc<3) {
    std::cout<< " insufficient input provided "<<std::endl;
    std::cout<< " usage : ./main.exe input.root output.root "<<std::endl;
    return 0;
  }

  //TString input  = argv[1];
  TString output = argv[2];
  TTree *tree=0;
  RKAnalyzer* ncuAna;
  std::cout<<" caling const"<<std::endl;
  ncuAna = new RKAnalyzer(tree);
  std::cout<<" caling loop"<<std::endl;
  
  TString filename_in = argv[1];
  TString running_mode="all";
  if(filename_in.Contains("WJetsToLNu")) {
    running_mode="WJETS";
  }
  else if (filename_in.Contains("ZJetsToNuNu")){
    running_mode="ZJETS";
  }
  else running_mode="all";
  
  
  ncuAna->Loop(output, running_mode);
  //std::vector<TString> filenames;
  //filenames.push_back("/store/user/khurana/ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8/crab_ggZH_HToBB_ZToNuNu_M120_13TeV_powheg_pythia8/150702_105011/0000/NCUGlobalTuples_10.root");
  //ncuAna->TotalEvent(filenames);
  //  detEffects->RKAnalyzer::~RKAnalyzer();


  time(&end);
  std::cout<<" time used is = "<<-(start-end)<<" seconds"<<std::endl;

  return 0;
}
