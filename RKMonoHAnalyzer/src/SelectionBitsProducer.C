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
      std::bitset<26> StatusOfCuts;
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
      
      //std::map<TString, bitset<26> >::iterator mapiter;
      
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
      //std::cout<<" value 1 = "<<(bitset<26>)MonoHiggsCuts::dphiJets <<std::endl;
      outputvec.push_back(objectCollection[i]);
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
  return outputvec;
}



// This is for Fat-jet + MET
std::vector<ResonanceWithMET<Jet,MET> > SelectionBitsProducer::SelectionBitsSaver(std::vector<ResonanceWithMET<Jet,MET > > objectCollection, std::map<std::string, float> tmp_cutValueMap){
  
  //std::map<std::string, float> tmp_cutValueMap = cuts.cutValueMap;
  std::vector<ResonanceWithMET<Jet,MET > > outputvec;
  outputvec.clear();
  if(objectCollection.size()>0){
    for(int i=0; i<(int)objectCollection.size();i++){
      if(RKDebugger::debug_SelectionBitsProducer()) std::cout<<"   ========= DiJetMET entry number  ======= "<<i<<std::endl;
      
      std::bitset<26> StatusOfCuts;
      objectCollection[i].cutsStatus = 0;
      StatusOfCuts = 0;
      std::cout<<" FATJET pt = "<<objectCollection[i].jet1.p4.Pt()<<std::endl;
      StatusOfCuts[cuts.cutsMapFatJet["apteta"]]            = (objectCollection[i].jet1.p4.Pt() > tmp_cutValueMap["leadingjetpt"] && 
							       TMath::Abs(objectCollection[i].jet1.p4.Eta()) < tmp_cutValueMap["jeteta"] )   ;            
      // for fat-jet CSV
      StatusOfCuts[cuts.cutsMapFatJet["bcsv"]]              = (objectCollection[i].jet1.B_CISVV2 > tmp_cutValueMap["leadingcsv"] )         ;  
      
      if (objectCollection[i].jet1.nsubJets >1 ) {
	// for two sub-jets csv
	StatusOfCuts[cuts.cutsMapFatJet["c2subjet"]]        = (objectCollection[i].jet1.SDCSV[0] > tmp_cutValueMap["leadingcsv"]
							       && objectCollection[i].jet1.SDCSV[1] > tmp_cutValueMap["leadingcsv"] )         ;  
	
	bool a = objectCollection[i].jet1.SDCSV[0] > tmp_cutValueMap["leadingcsv"];
	bool b = objectCollection[i].jet1.SDCSV[1] > tmp_cutValueMap["leadingcsv"];
	bool first = a && !b;
	bool second = !a && b;
	// XOR will give exactly one of them passing the CSV
	StatusOfCuts[cuts.cutsMapFatJet["d1subjet"]]        = (first || second);
	
	TLorentzVector p41;
	p41.SetPxPyPzE(objectCollection[i].jet1.SDPx[0],
		       objectCollection[i].jet1.SDPy[0],
		       objectCollection[i].jet1.SDPz[0],
		       objectCollection[i].jet1.SDEn[0]);
	TLorentzVector p42;
	p42.SetPxPyPzE(objectCollection[i].jet1.SDPx[1],
		       objectCollection[i].jet1.SDPy[1],
		       objectCollection[i].jet1.SDPz[1],
		       objectCollection[i].jet1.SDEn[1]);

	float dr = p41.DeltaR(p42);
	std::cout<<" a = "<<a<<" b = "<<b<<" first = "<<first<<" second = "<<second
		 <<" (a && b) = "<<(a && b) << "(first || second)"<<(first || second)
		 <<std::endl;
	
	// When one sub-jet below 0.3 and 2 subjet above 0.3
	if(dr>0.3) StatusOfCuts[cuts.cutsMapFatJet["edeltaRsubjet"]]    =  (a && b);
	if(dr<0.3) StatusOfCuts[cuts.cutsMapFatJet["edeltaRsubjet"]]    =  (first || second);
	
	// When ATLEAST 1 subjet below 0.3 and two subjets above 0.3
	if(dr>0.3) StatusOfCuts[cuts.cutsMapFatJet["fdeltaRAtLeastOneSubjet"]]   = (a && b); // both sub-jets pass csv
	if(dr<0.3) StatusOfCuts[cuts.cutsMapFatJet["fdeltaRAtLeastOneSubjet"]]   =  (first || second) || (a && b) ; // atleast one subjet pass csv. 
      }
      else {
	StatusOfCuts[cuts.cutsMapFatJet["c2subjet"]]         = false;
	StatusOfCuts[cuts.cutsMapFatJet["d1subjet"]]         = false;
	StatusOfCuts[cuts.cutsMapFatJet["edeltaRsubjet"]]    = false;
	StatusOfCuts[cuts.cutsMapFatJet["fdeltaRAtLeastOneSubjet"]]   =  false;
      }
      // for 1 subjet csv 
      
      StatusOfCuts[cuts.cutsMapFatJet["gDPHIJetMet"]]       = (TMath::Abs(objectCollection[i].TransverseObjProp.DeltaPhi) > tmp_cutValueMap["dphiDiJetMet"] );    
      
      std::cout<<" SDMASS  = "<<objectCollection[i].jet1.SDmass <<std::endl;
      StatusOfCuts[cuts.cutsMapFatJet["hMjet"]]             = (objectCollection[i].jet1.SDmass > tmp_cutValueMap["MDiJetLow"]  &&         
							       objectCollection[i].jet1.SDmass < tmp_cutValueMap["MDiJetHigh"] )  ;
      
      
      StatusOfCuts[cuts.cutsMapFatJet["imetpt"]]            = (objectCollection[i].jet2.RawPt > tmp_cutValueMap["metpt"] )                        ;
      
      // e, mu, tau information is associated to only first element.
      
      // Jets less than this number
      int njets=objectCollection[0].jets.size();
      int naddjet = 0;
      for(int ij=0;ij<njets;ij++){
	float dr_ = RKMath::DeltaR(objectCollection[0].jets[ij].p4.Eta() ,
				   objectCollection[0].jets[ij].p4.Phi() ,
				   objectCollection[0].jet1.p4.Eta(),
				   objectCollection[0].jet1.p4.Phi());
	if(dr_ < 0.8 )  continue;
	//float dphi_ = RKMath::DeltaPhi(objectCollection[0].jets[ij].p4.Phi(), objectCollection[0].jet1.p4.Phi() );                                                                  
	//if( TMath::Abs(dphi_) < 2.0 ) continue;                                                                      
	naddjet++;
      }
      StatusOfCuts[cuts.cutsMapFatJet["jNele"]]             = (objectCollection[0].electrons.size() == tmp_cutValueMap["Nele"]);
      StatusOfCuts[cuts.cutsMapFatJet["kNmu"]]              = (objectCollection[0].muons.size()  == tmp_cutValueMap["Nmu"]);
      StatusOfCuts[cuts.cutsMapFatJet["lNjet"]]             = (naddjet >= tmp_cutValueMap["Njet"]);
      StatusOfCuts[cuts.cutsMapFatJet["mNtau"]]             = (objectCollection[0].taus.size() == tmp_cutValueMap["Ntau"]);
      
      
      
      StatusOfCuts[cuts.cutsMapFatJet["nMjetVeto"]]         = ( (objectCollection[i].jet1.SDmass > 30.0  && 
								 objectCollection[i].jet1.SDmass < 250.0 ) && 
								(objectCollection[i].jet1.SDmass > tmp_cutValueMap["MDiJetLow"]  ||         
								 objectCollection[i].jet1.SDmass < tmp_cutValueMap["MDiJetHigh"] ) )  ;
      
      

      
      StatusOfCuts[cuts.cutsMapFatJet["oNjetless"]]             = (naddjet < tmp_cutValueMap["Njet"]);
      
      // exactly Zero leptons
      StatusOfCuts[cuts.cutsMapFatJet["pNLepton"]]              = (objectCollection[0].muons.size() +  objectCollection[0].electrons.size() +
								   objectCollection[0].taus.size())  == tmp_cutValueMap["NLepton"] ;
      
      
      
      // Light Jets BJets
      bool csv_subjet1 = objectCollection[i].jet1.SDCSV[0] > tmp_cutValueMap["csvlow"]  &&  objectCollection[i].jet1.SDCSV[0] < tmp_cutValueMap["csvhigh"];
      bool csv_subjet2 = objectCollection[i].jet1.SDCSV[1] > tmp_cutValueMap["csvlow"] && objectCollection[i].jet1.SDCSV[1] < tmp_cutValueMap["csvhigh"] ;
      StatusOfCuts[cuts.cutsMapFatJet["qZLightBJet"]]           =  csv_subjet1 || csv_subjet2 ;
      
      // Heavy Jets BJets
      // One of the b-jet pass loose criteria 
      // and other one pass the very loose criteria
      bool csv_subjet1a = objectCollection[i].jet1.SDCSV[0] > tmp_cutValueMap["csvlow"] ;
      bool csv_subjet1b = objectCollection[i].jet1.SDCSV[0] > tmp_cutValueMap["leadingcsv"] ;

      bool csv_subjet2a = objectCollection[i].jet1.SDCSV[1] > tmp_cutValueMap["csvlow"] ;
      bool csv_subjet2b = objectCollection[i].jet1.SDCSV[1] > tmp_cutValueMap["leadingcsv"] ;

      bool csv_heavyjet = (csv_subjet1a && csv_subjet2b)  || ( csv_subjet1b && csv_subjet2a );
      StatusOfCuts[cuts.cutsMapFatJet["rZHeavyBJet"]]           =  csv_heavyjet ;
      
      
      
      
      objectCollection[i].cutsStatus = StatusOfCuts;
      std::cout<<" cut status selectionbits FATJETMET = "<<StatusOfCuts<<std::endl;
      //std::cout<<" value 1 = "<<(bitset<26>)MonoHiggsCuts::dphiJets <<std::endl;
      outputvec.push_back(objectCollection[i]);
    }//for(int i=0; i<(int)objectCollection.size();i++){
  }// if(objectCollection.size()>0){
  return outputvec;
}
