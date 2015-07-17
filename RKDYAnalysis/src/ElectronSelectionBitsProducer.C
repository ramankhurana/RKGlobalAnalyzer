#define ElectronSelectionBitsProducer_cxx
#include "../interface/ElectronSelectionBitsProducer.h"
#include "../../RKUtilities/interface/RKDebugger.h"
#include <bitset>
std::bitset<16> ElectronSelectionBitsProducer::SelectionBitsSaver(Electron objectCollection, std::map<std::string, float> tmp_cutValueMap){
  
  std::bitset<16> StatusOfCuts;
  StatusOfCuts = 0;
  StatusOfCuts[elecuts.DYcutsMap["aDEtaIn"]] = objectCollection.dEtaIn > tmp_cutValueMap["VdEtaIn"]  ;
  StatusOfCuts[elecuts.DYcutsMap["bDPhiIn"]] = objectCollection.dPhiIn > tmp_cutValueMap["VdPhiIn"]  ;
  StatusOfCuts[elecuts.DYcutsMap["cSigmaIetaIetaFull"]] = objectCollection.full5x5_sigmaIetaIeta > tmp_cutValueMap["VsigmaIetaIetaFull"]  ;
  StatusOfCuts[elecuts.DYcutsMap["dHOverE"]] = objectCollection.hOverE > tmp_cutValueMap["VhOverE"]  ;
  StatusOfCuts[elecuts.DYcutsMap["eD0"]] = objectCollection.d0 > tmp_cutValueMap["VD0"]  ;
  StatusOfCuts[elecuts.DYcutsMap["fDz"]] = objectCollection.dz > tmp_cutValueMap["VDz"]  ;
  StatusOfCuts[elecuts.DYcutsMap["gEInvP"]] = objectCollection.eoverPInv > tmp_cutValueMap["VEInvP"]  ;
  StatusOfCuts[elecuts.DYcutsMap["hRhoIsolation"]] = objectCollection.isoRho > tmp_cutValueMap["VRhoIsolation"]  ;
  StatusOfCuts[elecuts.DYcutsMap["iExpMissingHits"]] = objectCollection.expectedMissingInnerHits > tmp_cutValueMap["VExpMissingHits"]  ;
  StatusOfCuts[elecuts.DYcutsMap["jConversionVeto"]] = objectCollection.passConversionVeto > tmp_cutValueMap["VConversionVeto"]  ;
  
  return StatusOfCuts;
}
