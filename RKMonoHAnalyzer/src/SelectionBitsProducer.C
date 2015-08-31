#define SelectionBitsProducer_cxx
#include "../interface/SelectionBitsProducer.h"
#include "../../RKUtilities/interface/RKDebugger.h"

// This is for di-jet + MET
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
      
      
      StatusOfCuts[cuts.cutsMap["aleadingpteta"]]     = (objectCollection[i].jet1.jet1.p4.Pt() > tmp_cutValueMap["leadingjetpt"] && 
						       TMath::Abs(objectCollection[i].jet1.jet1.p4.Eta()) < tmp_cutValueMap["jeteta"] )   ;            
      StatusOfCuts[cuts.cutsMap["bsubleadingpteta"]]  = (objectCollection[i].jet1.jet2.p4.Pt() > tmp_cutValueMap["subleadingjetpt"] && 
							 TMath::Abs(objectCollection[i].jet1.jet2.p4.Eta()) < tmp_cutValueMap["jeteta"] ) ;         
      StatusOfCuts[cuts.cutsMap["cleadingcsv"]]       = (objectCollection[i].jet1.jet1.B_CISVV2 > tmp_cutValueMap["leadingcsv"] )         ;  
      StatusOfCuts[cuts.cutsMap["dsubleadingcsv"]]    = (objectCollection[i].jet1.jet2.B_CISVV2 > tmp_cutValueMap["subleadingcsv"] )      ; 
            
      StatusOfCuts[cuts.cutsMap["eDPHIDijetMet"]]     = (TMath::Abs(objectCollection[i].ResonancemetProp.DeltaPhi) > tmp_cutValueMap["dphiDiJetMet"] );    
      StatusOfCuts[cuts.cutsMap["fMDijet"]]           = (objectCollection[i].jet1.ResonanceProp.InvMass > tmp_cutValueMap["MDiJetLow"]  &&         
							 objectCollection[i].jet1.ResonanceProp.InvMass < tmp_cutValueMap["MDiJetHigh"] )  ;
      StatusOfCuts[cuts.cutsMap["gmetpt"]]            = (objectCollection[i].jet2.RawPt > tmp_cutValueMap["metpt"] )                        ;
      
      // e, mu, tau information is associated to only first element.
      StatusOfCuts[cuts.cutsMap["hNele"]]             = (objectCollection[0].electrons.size() == tmp_cutValueMap["Nele"]);
      StatusOfCuts[cuts.cutsMap["iNmu"]]              = (objectCollection[0].muons.size()  == tmp_cutValueMap["Nmu"]);
      StatusOfCuts[cuts.cutsMap["jNjet"]]             = (objectCollection[0].jets.size() == tmp_cutValueMap["njet"]);
      
      StatusOfCuts[cuts.cutsMap["kDPHIMETClosestJ"]]  = (TMath::Abs(objectCollection[i].DPHI_MET_J) > tmp_cutValueMap["DPHIMETClosedJ"]);
      
      //std::map<TString, bitset<16> >::iterator mapiter;
      
      std::map<std::string, int>::iterator mapit = cuts.cutsMap.begin();
      for(mapit=cuts.cutsMap.begin(); mapit != cuts.cutsMap.end(); ++mapit){
	if(false) std::cout<<mapit->first<<"  :   "<<mapit->second<<std::endl;;
      }
      bool amuon = false;
      for (size_t imu=0; (imu< objectCollection[0].muons.size()) && (amuon==false); imu++){
	float dr = objectCollection[0].muons[imu].p4.DeltaR(objectCollection[i].jet1.jet1.p4);
	if(dr < 0.4) {
	  amuon = true;
	  if(false) std::cout<<" ***************** working "<<dr<<std::endl;
	}
      }
      
      objectCollection[i].cutsStatus = StatusOfCuts;
      if(false) std::cout<<" cut status selectionbits = "<<StatusOfCuts<<std::endl;
      //std::cout<<" value 1 = "<<(bitset<16>)MonoHiggsCuts::dphiJets <<std::endl;
      outputvec.push_back(objectCollection[i]);
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
  return outputvec;
}



// This is for Fat-jet + MET
std::vector<ResonanceWithMET<Jet,MET> > SelectionBitsProducer::SelectionBitsSaver(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, 
									      std::map<std::string, float> tmp_cutValueMap){
  
  //std::map<std::string, float> tmp_cutValueMap = cuts.cutValueMap;
  std::vector<ResonanceWithMET<Jet,MET > > outputvec;
  outputvec.clear();
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(RKDebugger::debug_SelectionBitsProducer()) std::cout<<"   ========= DiJetMET entry number  ======= "<<i<<std::endl;
      
      std::bitset<16> StatusOfCuts;
      StatusOfCuts = 0;
      std::cout<<" FATJET pt = "<<objectCollection[i].jet1.p4.Pt()<<std::endl;
      StatusOfCuts[cuts.cutsMapFatJet["apteta"]]            = (objectCollection[i].jet1.p4.Pt() > tmp_cutValueMap["leadingjetpt"] && 
							       TMath::Abs(objectCollection[i].jet1.p4.Eta()) < tmp_cutValueMap["jeteta"] )   ;            
      StatusOfCuts[cuts.cutsMapFatJet["bcsv"]]              = (objectCollection[i].jet1.B_CISVV2 > tmp_cutValueMap["leadingcsv"] )         ;  
      StatusOfCuts[cuts.cutsMapFatJet["cDPHIJetMet"]]       = (TMath::Abs(objectCollection[i].TransverseObjProp.DeltaPhi) > tmp_cutValueMap["dphiDiJetMet"] );    
      StatusOfCuts[cuts.cutsMapFatJet["dMjet"]]             = (objectCollection[i].jet1.SDmass > tmp_cutValueMap["MDiJetLow"]  &&         
							       objectCollection[i].jet1.SDmass < tmp_cutValueMap["MDiJetHigh"] )  ;
      StatusOfCuts[cuts.cutsMapFatJet["emetpt"]]            = (objectCollection[i].jet2.RawPt > tmp_cutValueMap["metpt"] )                        ;
      
      // e, mu, tau information is associated to only first element.
      StatusOfCuts[cuts.cutsMapFatJet["fNele"]]             = (objectCollection[0].electrons.size() == tmp_cutValueMap["Nele"]);
      StatusOfCuts[cuts.cutsMapFatJet["gNmu"]]              = (objectCollection[0].muons.size()  == tmp_cutValueMap["Nmu"]);
      StatusOfCuts[cuts.cutsMapFatJet["hNjet"]]             = (objectCollection[0].jets.size() == tmp_cutValueMap["njet"]);
      
      objectCollection[i].cutsStatus = StatusOfCuts;
      std::cout<<" cut status selectionbits FATJETMET = "<<StatusOfCuts<<std::endl;
      //std::cout<<" value 1 = "<<(bitset<16>)MonoHiggsCuts::dphiJets <<std::endl;
      outputvec.push_back(objectCollection[i]);
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
  return outputvec;
}
