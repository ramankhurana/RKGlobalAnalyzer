#define SelectionBitsProducer_cxx
#include "../interface/SelectionBitsProducer.h"
#include "../../RKUtilities/interface/RKDebugger.h"

std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > SelectionBitsProducer::SelectionBitsSaver(std::vector<ResonanceMET<Resonance<Jet,Jet>,MET > > objectCollection){

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
      
      if(objectCollection[i].jet1.jet1.p4.Pt() > 80 && TMath::Abs(objectCollection[i].jet1.jet1.p4.Eta()) <2.5 )          StatusOfCuts[cuts.cutsMap["leadingpteta"]] = 1;
      if(objectCollection[i].jet1.jet2.p4.Pt() > 30 && TMath::Abs(objectCollection[i].jet1.jet2.p4.Eta()) <2.5 )          StatusOfCuts[cuts.cutsMap["subleadingpteta"]] = 1;
      if(objectCollection[i].jet1.jet1.B_CISVV2 > 0.432 )                                                                 StatusOfCuts[cuts.cutsMap["leadingcsv"]] = 1;
      if(objectCollection[i].jet1.jet2.B_CISVV2 > 0.432 )                                                                 StatusOfCuts[cuts.cutsMap["subleadingcsv"]] = 1;
      //if(objectCollection[i].jet1.jet1.charge * objectCollection[i].jet1.jet2.charge == -1)                               StatusOfCuts[4] = 1;
      
      if(objectCollection[i].jet2.RawPt > 150. )                                                                          StatusOfCuts[cuts.cutsMap["metpt"]] = 1;
      
      if(TMath::Abs(objectCollection[i].ResonancemetProp.DeltaPhi) > 2.5 )                                                StatusOfCuts[cuts.cutsMap["DPHIDijetMet"]] = 1;
      
      if(objectCollection[i].ResonancemetProp.TransMass > 400. )                                                          StatusOfCuts[cuts.cutsMap["MTDijet"]] = 1;

      if(objectCollection[i].jet1.ResonanceProp.InvMass > 100. && objectCollection[i].jet1.ResonanceProp.InvMass < 150.)  StatusOfCuts[cuts.cutsMap["MDijet"]] = 1;
      
      if(TMath::Abs(objectCollection[i].objMet1.DeltaPhi) > 2. )                                                          StatusOfCuts[cuts.cutsMap["DPHIJet1Met"]] = 1;
      if(TMath::Abs(objectCollection[i].objMet2.DeltaPhi) > 2. )                                                          StatusOfCuts[cuts.cutsMap["DPHIJet2Met"]] = 1;
      if(objectCollection[i].objMet1.TransMass > 300. )                                                                   StatusOfCuts[cuts.cutsMap["MTJet1"]] = 1;
      if(objectCollection[i].objMet2.TransMass > 200. )                                                                   StatusOfCuts[cuts.cutsMap["MTJet2"]] = 1;
      
      
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
