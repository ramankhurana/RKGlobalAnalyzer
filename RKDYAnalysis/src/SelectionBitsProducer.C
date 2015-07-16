#define SelectionBitsProducer_cxx
#include "../interface/SelectionBitsProducer.h"
#include "../../RKUtilities/interface/RKDebugger.h"
#include <bitset>
std::bitset<16> SelectionBitsProducer::SelectionBitsSaver(Electron objectCollection, std::map<std::string, float> tmp_cutValueMap){
  
  //std::map<std::string, float> tmp_cutValueMap = cuts.cutValueMap;
  std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > outputvec;
  outputvec.clear();
  if(RKDebugger::debug_SelectionBitsProducer()) std::cout<<"   ========= DiJetMET entry number  ======= "<<i<<std::endl;
  if(RKDebugger::debug_SelectionBitsProducer()) std::cout<<" mass = "<<objectCollection.jet1.ResonanceProp.InvMass<<std::endl;
  std::bitset<16> StatusOfCuts;
  StatusOfCuts = 0;
  StatusOfCuts[cuts.DYcutsMap["aDEtaIn"]] = objectCollection.dEtaIn > tmp_cutValueMap["VdEtaIn"]  ;
  StatusOfCuts[cuts.DYcutsMap["bDPhiIn"]] = objectCollection.dPhiIn > tmp_cutValueMap["VdPhiIn"]  ;
  StatusOfCuts[cuts.DYcutsMap["cSigmaIetaIetaFull"]] = objectCollection.full5x5_sigmaIetaIeta > tmp_cutValueMap["VsigmaIetaIetaFull"]  ;
  StatusOfCuts[cuts.DYcutsMap["dHOverE"]] = objectCollection.hOverE > tmp_cutValueMap["VhOverE"]  ;
  StatusOfCuts[cuts.DYcutsMap["eD0"]] = objectCollection.d0 > tmp_cutValueMap["VD0"]  ;
  StatusOfCuts[cuts.DYcutsMap["fDz"]] = objectCollection.dz > tmp_cutValueMap["VDz"]  ;
  StatusOfCuts[cuts.DYcutsMap["gEInvP"]] = objectCollection.eoverPInv > tmp_cutValueMap["VEInvP"]  ;
  StatusOfCuts[cuts.DYcutsMap["hRhoIsolation"]] = objectCollection.isoRho > tmp_cutValueMap["VRhoIsolation"]  ;
  StatusOfCuts[cuts.DYcutsMap["iExpMissingHits"]] = objectCollection.expectedMissingInnerHits > tmp_cutValueMap["VExpMissingHits"]  ;
  StatusOfCuts[cuts.DYcutsMap["jConversionVeto"]] = objectCollection.passConversionVeto > tmp_cutValueMap["VConversionVeto"]  ;
  
  return StatusOfCuts;
}
