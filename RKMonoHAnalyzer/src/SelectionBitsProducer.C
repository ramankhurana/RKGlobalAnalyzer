#define SelectionBitsProducer_cxx
#include "../interface/SelectionBitsProducer.h"
#include "../../RKUtilities/interface/RKDebugger.h"

std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > SelectionBitsProducer::SelectionBitsSaver(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection, std::map<std::string, float> tmp_cutValueMap){
  
  //std::map<std::string, float> tmp_cutValueMap = cuts.cutValueMap;
  std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > outputvec;
  outputvec.clear();
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(RKDebugger::debug_SelectionBitsProducer()) if(false) std::cout <<"   ========= DiJetMET entry number  ======= "<<i<<std::endl;
      if(RKDebugger::debug_SelectionBitsProducer()) if(false) std::cout <<" mass = "<<objectCollection[i].jet1.ResonanceProp.InvMass<<std::endl;
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
      
      
      if(objectCollection[i].jet1.jet1.p4.Pt() > tmp_cutValueMap["leadingjetpt"] && 
	 TMath::Abs(objectCollection[i].jet1.jet1.p4.Eta()) < tmp_cutValueMap["jeteta"] )                 StatusOfCuts[cuts.cutsMap["aleadingpteta"]] = 1;
      if(objectCollection[i].jet1.jet2.p4.Pt() > tmp_cutValueMap["subleadingjetpt"] && 
	 TMath::Abs(objectCollection[i].jet1.jet2.p4.Eta()) < tmp_cutValueMap["jeteta"] )                 StatusOfCuts[cuts.cutsMap["bsubleadingpteta"]] = 1;
      if(objectCollection[i].jet1.jet1.B_CISVV2 > tmp_cutValueMap["leadingcsv"] )                         StatusOfCuts[cuts.cutsMap["cleadingcsv"]] = 1;
      if(objectCollection[i].jet1.jet2.B_CISVV2 > tmp_cutValueMap["subleadingcsv"] )                      StatusOfCuts[cuts.cutsMap["dsubleadingcsv"]] = 1;
      //if(objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge == -1)             StatusOfCuts[4] = 1;
      
      if(objectCollection[i].jet2.RawPt > tmp_cutValueMap["metpt"] )                                      StatusOfCuts[cuts.cutsMap["emetpt"]] = 1;
      if(TMath::Abs(objectCollection[i].ResonancemetProp.DeltaPhi) > tmp_cutValueMap["dphiDiJetMet"] )    StatusOfCuts[cuts.cutsMap["fDPHIDijetMet"]] = 1;
      
      if(objectCollection[i].ResonancemetProp.TransMass > tmp_cutValueMap["MTDiJet"] )                    StatusOfCuts[cuts.cutsMap["gMTDijet"]] = 1;
      
      if(objectCollection[i].jet1.ResonanceProp.InvMass > tmp_cutValueMap["MDiJetLow"]  &&         
	 objectCollection[i].jet1.ResonanceProp.InvMass < tmp_cutValueMap["MDiJetHigh"] )                 StatusOfCuts[cuts.cutsMap["hMDijet"]] = 1;
      
      if(TMath::Abs(objectCollection[i].objMet1.DeltaPhi) > tmp_cutValueMap["DPHIJet1MET"] )              StatusOfCuts[cuts.cutsMap["iDPHIJet1Met"]] = 1;
      if(TMath::Abs(objectCollection[i].objMet2.DeltaPhi) > tmp_cutValueMap["DPHIJet2MET"] )              StatusOfCuts[cuts.cutsMap["jDPHIJet2Met"]] = 1;
      if(objectCollection[i].objMet1.TransMass > tmp_cutValueMap["MTJet1"] )                              StatusOfCuts[cuts.cutsMap["kMTJet1"]] = 1;
      if(objectCollection[i].objMet2.TransMass > tmp_cutValueMap["MTJet2"] )                              StatusOfCuts[cuts.cutsMap["lMTJet2"]] = 1;
      
      //std::map<TString, bitset<16> >::iterator mapiter;
      
      std::map<std::string, int>::iterator mapit = cuts.cutsMap.begin();
      for(mapit=cuts.cutsMap.begin(); mapit != cuts.cutsMap.end(); ++mapit){
	if(false) std::cout <<mapit->first<<"  :   "<<mapit->second<<std::endl;;
      }
      bool amuon = false;
      for (size_t imu=0; (imu< objectCollection[0].muons.size()) && (amuon==false); imu++){
	float dr = objectCollection[0].muons[imu].p4.DeltaR(objectCollection[i].jet1.jet1.p4);
	if(dr < 0.4) {
	  amuon = true;
	  if(false) std::cout <<" ***************** working "<<dr<<std::endl;
	}
      }
      
      objectCollection[i].cutsStatus = StatusOfCuts;
      if(false) std::cout <<" cut status selectionbits = "<<StatusOfCuts<<std::endl;
      //if(false) std::cout <<" value 1 = "<<(bitset<16>)MonoHiggsCuts::dphiJets <<std::endl;
      outputvec.push_back(objectCollection[i]);
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
  return outputvec;
}
