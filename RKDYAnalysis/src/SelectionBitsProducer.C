#define SelectionBitsProducer_cxx
#include "../interface/SelectionBitsProducer.h"
#include "../../RKUtilities/interface/RKDebugger.h"

std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > SelectionBitsProducer::SelectionBitsSaver(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, std::map<std::string, float> tmp_cutValueMap){
  
  //std::map<std::string, float> tmp_cutValueMap = cuts.cutValueMap;
  std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > outputvec;
  outputvec.clear();
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(RKDebugger::debug_SelectionBitsProducer()) std::cout<<"   ========= DiJetMET entry number  ======= "<<i<<std::endl;
      if(RKDebugger::debug_SelectionBitsProducer()) std::cout<<" mass = "<<objectCollection[i].jet1.ResonanceProp.InvMass<<std::endl;
      std::bitset<16> StatusOfCuts;
      StatusOfCuts = 0;
      // pt, eta of leading jet              : 0
      // pt, eta of sub-leading jet          : 1
      // btag of both jets                   : 2
      // MET > 70 	                     : 3
      // dphi(met,bb) > 2.5                  : 4
      // 100 < Mbb < 150                     : 5
      // mT(bb,met) > 400                    : 6
      // mT(b1,MET) > 	                     : 7
      // mT (b2,MET) > 	                     : 8
      // dphi (met,b1)                     : 9
      // dphi (met,b2)                     : 10
      // 
      
      
      StatusOfCuts[cuts.DYcutsMap["aDEtaIn"]] = objectCollection[i].dEtaIn > tmp_cutValueMap["VdEtaIn"]  ;
      StatusOfCuts[cuts.DYcutsMap["bDPhiIn"]] = objectCollection[i].dPhiIn > tmp_cutValueMap["VdPhiIn"]  ;
      StatusOfCuts[cuts.DYcutsMap["cSigmaIetaIetaFull"]] = objectCollection[i].full5x5_sigmaIetaIeta > tmp_cutValueMap["VsigmaIetaIetaFull"]  ;
      StatusOfCuts[cuts.DYcutsMap["dHOverE"]] = objectCollection[i].hOverE > tmp_cutValueMap["VhOverE"]  ;
      StatusOfCuts[cuts.DYcutsMap["eD0"]] = objectCollection[i].d0 > tmp_cutValueMap["VD0"]  ;
      StatusOfCuts[cuts.DYcutsMap["fDz"]] = objectCollection[i].dz > tmp_cutValueMap["VDz"]  ;
      StatusOfCuts[cuts.DYcutsMap["gEInvP"]] = objectCollection[i].eoverPInv > tmp_cutValueMap["VEInvP"]  ;
      StatusOfCuts[cuts.DYcutsMap["hRhoIsolation"]] = objectCollection[i].isoRho > tmp_cutValueMap["VRhoIsolation"]  ;
      StatusOfCuts[cuts.DYcutsMap["iExpMissingHits"]] = objectCollection[i].expectedMissingInnerHits > tmp_cutValueMap["VExpMissingHits"]  ;
      StatusOfCuts[cuts.DYcutsMap["jConversionVeto"]] = objectCollection[i].passConversionVeto > tmp_cutValueMap["VConversionVeto"]  ;


      
      //std::map<TString, bitset<16> >::iterator mapiter;
      
      std::map<std::string, int>::iterator mapit = cuts.cutsMap.begin();
      for(mapit=cuts.cutsMap.begin(); mapit != cuts.cutsMap.end(); ++mapit){
	std::cout<<mapit->first<<"  :   "<<mapit->second<<std::endl;;
      }
      bool amuon = false;
      for (size_t imu=0; (imu< objectCollection[0].muons.size()) && (amuon==false); imu++){
	float dr = objectCollection[0].muons[imu].p4.DeltaR(objectCollection[i].jet1.jet1.p4);
	if(dr < 0.4) {
	  amuon = true;
	  std::cout<<" ***************** working "<<dr<<std::endl;
	}
      }
      
      objectCollection[i].cutsStatus = StatusOfCuts;
      std::cout<<" cut status selectionbits = "<<StatusOfCuts<<std::endl;
      //std::cout<<" value 1 = "<<(bitset<16>)MonoHiggsCuts::dphiJets <<std::endl;
      outputvec.push_back(objectCollection[i]);
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
  return outputvec;
}
