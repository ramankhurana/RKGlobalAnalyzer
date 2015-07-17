// Original class : ElectronSelectionBitsProducer.h
// Created By     : ramankhurana 
// Created On     : Sun May  3 00:03:45 CEST 2015

// This class saves bits for each of the cuts used in the analysis in an integer and this integer can be used later to fill :
// 1. Cut Flow Histograms
// 2. Optimisation of cuts. 
// 3. Define control region for 
//     - Fake rate estimate 
//     - Apply fake rate and measure background
// 4. Systematics 
// 5. Input(s) for Limit calculation 
// 6. Efficiency plots 
//    - for object selction
//    - for each cut, as a function of other variables. e.g. see efficiency of deltaPhi cut as a funtion of H pT, H Mass, Jet1 pT, Jet2pT and many more. 

#ifndef ElectronSelectionBitsProducer_h_
#define ElectronSelectionBitsProducer_h_


#include "../../RKDataFormats/interface/Electron.h"
#include "../../RKUtilities/interface/DYAnalysisCuts.h"
#include <map>
#include <bitset>
class ElectronSelectionBitsProducer {
 public:
  DYAnalysisCuts elecuts;
  ElectronSelectionBitsProducer(){};
  ~ElectronSelectionBitsProducer(){};
  std::bitset<16> SelectionBitsSaver(Electron ele, std::map<std::string, float> tmp_cutValueMap);
  
  protected:

  private:

};
#endif
