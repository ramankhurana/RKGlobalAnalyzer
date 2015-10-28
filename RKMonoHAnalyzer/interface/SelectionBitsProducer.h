// Original class : SelectionBitsProducer.h
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

#ifndef SelectionBitsProducer_h_
#define SelectionBitsProducer_h_


#include "../../RKDataFormats/interface/Jet.h"
#include "../../RKDataFormats/interface/MET.h"
#include "../../RKDataFormats/interface/Resonance.h"
#include "../../RKDataFormats/interface/ResonanceMET.h"
#include "../../RKDataFormats/interface/ResonanceWithMET.h"
#include "../../RKUtilities/interface/MonoHiggsCuts.h"
#include "../../RKUtilities/interface/RKMath.h"
#include <map>
class SelectionBitsProducer {
 public:
  SelectionBitsProducer(){};
  ~SelectionBitsProducer(){};
  std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > >   SelectionBitsSaver(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, 
									   std::map<std::string, float> tmp_cutValueMap);

  std::vector<ResonanceWithMET<Jet,MET > >   SelectionBitsSaver(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, 
									   std::map<std::string, float> tmp_cutValueMap);
  MonoHiggsCuts cuts;


  protected:

  private:

};
#endif
