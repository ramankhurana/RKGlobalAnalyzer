// Original class : DYAnalysisCuts.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

#ifndef DYAnalysisCuts_h_
#define DYAnalysisCuts_h_
#include <map>
#include <unordered_map>

using namespace std;


class DYAnalysisCuts {
 public:
  DYAnalysisCuts(){

    // cutsMap
    // they are named like this so that they remain sorted in the map.
    // saved in alphabatical order in the cuts name map.
    DYcutsMap.clear();
    DYcutsMap["aDEtaIn"]                    = 0  ;
    DYcutsMap["bDPhiIn"]                    = 1  ;
    DYcutsMap["cSigmaIetaIetaFull"]         = 2  ;
  
    DYcutsMap["dHOverE"]                    = 3  ;
    DYcutsMap["eD0"]                        = 4  ;
    DYcutsMap["fDz"]                        = 5  ;
    DYcutsMap["gEInvP"]                     = 6  ;
    DYcutsMap["hRhoIsolation"]              = 7  ;
    
    DYcutsMap["iExpMissingHits"]            = 8  ;
    DYcutsMap["jConversionVeto"]            = 9  ;
    //  DYcutsMap["kMTJet1"]             = 10 ;
    //DYcutsMap["lMTJet2"]             = 11 ;
    //  0000 1111 1111 1111

    
    // cutValueMap
    LooseDYcutValueMapBarrel.clear(); 
    LooseDYcutValueMapBarrel["VdEtaIn"]            =0.009277;
    LooseDYcutValueMapBarrel["VdPhiIn"]            =0.094739;  
   
    LooseDYcutValueMapBarrel["VsigmaIetaIetaFull"] =0.010331;
    LooseDYcutValueMapBarrel["VhOverE"]            =0.093068;
    LooseDYcutValueMapBarrel["VD0"]                =0.035904;

    LooseDYcutValueMapBarrel["VDz"]                =0.075496;
    LooseDYcutValueMapBarrel["VEInvP"]              =0.189968;
    LooseDYcutValueMapBarrel["VRhoIsolation"]       =0.130136;
    LooseDYcutValueMapBarrel["VExpMissingHits"]    =1;
    LooseDYcutValueMapBarrel["VConversionVeto"]    =1 ; //see this

    // cutValueMap                                                             
    MediumDYcutValueMapBarrel.clear();
    MediumDYcutValueMapBarrel["VdEtaIn"]            =0.008925;
    MediumDYcutValueMapBarrel["VdPhiIn"]            =0.035973 ;
    MediumDYcutValueMapBarrel["VsigmaIetaIetaFull"] =0.009996;
    MediumDYcutValueMapBarrel["VhOverE"]            =0.050537;
    MediumDYcutValueMapBarrel["VD0"]                =0.012235 ;
    MediumDYcutValueMapBarrel["VDz"]                =0.042020;
    MediumDYcutValueMapBarrel["VEInvP"]              =0.091942;
    MediumDYcutValueMapBarrel["VRhoIsolation"]       =0.107587 ;
    MediumDYcutValueMapBarrel["VExpMissingHits"]    =1;
    MediumDYcutValueMapBarrel["VConversionVeto"]    =1;


    // cutValueMap                                                             
    TightDYcutValueMapBarrel.clear();
    TightDYcutValueMapBarrel["VdEtaIn"]            =0.006046 ;
    TightDYcutValueMapBarrel["VdPhiIn"]            =0.028092 ;
    TightDYcutValueMapBarrel["VsigmaIetaIetaFull"] =0.009947;
    TightDYcutValueMapBarrel["VhOverE"]            =0.045772;
    TightDYcutValueMapBarrel["VD0"]                =0.008790;
    TightDYcutValueMapBarrel["VDz"]                =0.021226;
    TightDYcutValueMapBarrel["VEInvP"]              =0.020118 ;
    TightDYcutValueMapBarrel["VRhoIsolation"]       =0.069537;
    TightDYcutValueMapBarrel["VExpMissingHits"]    =1;
    TightDYcutValueMapBarrel["VConversionVeto"]    =1;


    // cutValueMap                                                                                                                              
    LooseDYcutValueMapEndcap.clear();
    LooseDYcutValueMapEndcap["VdEtaIn"]            =0.009833;
    LooseDYcutValueMapEndcap["VdPhiIn"]            =0.149934;

    LooseDYcutValueMapEndcap["VsigmaIetaIetaFull"] =0.031838;
    LooseDYcutValueMapEndcap["VhOverE"]            =0.115754 ;
    LooseDYcutValueMapEndcap["VD0"]                =0.099266 ;
    LooseDYcutValueMapEndcap["VDz"]                =0.197897 ;
    LooseDYcutValueMapEndcap["VEInvP"]              =0.140662;
    LooseDYcutValueMapEndcap["VRhoIsolation"]       =0.163368;
    LooseDYcutValueMapEndcap["VExpMissingHits"]    =1;
    LooseDYcutValueMapEndcap["VConversionVeto"]    =1 ; //see this                                                                              

    // cutValueMap                                                                                                                              
    MediumDYcutValueMapEndcap.clear();
    MediumDYcutValueMapEndcap["VdEtaIn"]            =0.007429;
    MediumDYcutValueMapEndcap["VdPhiIn"]            =0.067879;
    MediumDYcutValueMapEndcap["VsigmaIetaIetaFull"] =0.030135;
    MediumDYcutValueMapEndcap["VhOverE"]            =0.086782 ;
    MediumDYcutValueMapEndcap["VD0"]                =0.036719;
    MediumDYcutValueMapEndcap["VDz"]                =0.138142 ;
    MediumDYcutValueMapEndcap["VEInvP"]              =0.100683;
    MediumDYcutValueMapEndcap["VRhoIsolation"]       =0.113254;
    MediumDYcutValueMapEndcap["VExpMissingHits"]    =1;
    MediumDYcutValueMapEndcap["VConversionVeto"]    =1;


   
    // cutValueMap                                                                                                                              
    TightDYcutValueMapEndcap.clear();
    TightDYcutValueMapEndcap["VdEtaIn"]            =0.007057;
    TightDYcutValueMapEndcap["VdPhiIn"]            =0.030159;
    TightDYcutValueMapEndcap["VsigmaIetaIetaFull"] =0.028237;
    TightDYcutValueMapEndcap["VhOverE"]            =0.067778;
    TightDYcutValueMapEndcap["VD0"]                =0.027984;
    TightDYcutValueMapEndcap["VDz"]                =0.133431;

    TightDYcutValueMapEndcap["VEInvP"]              =0.098919;
    TightDYcutValueMapEndcap["VRhoIsolation"]       =0.078265;
    TightDYcutValueMapEndcap["VExpMissingHits"]    =1;
    TightDYcutValueMapEndcap["VConversionVeto"]    =1;



  };

  ~DYAnalysisCuts(){};
 public:
  std::map<std::string, int>   DYcutsMap;
  std::map<std::string, float> TightDYcutValueMapEndcap;
  std::map<std::string, float> TightDYcutValueMapBarrel;
  std::map<std::string, float> MediumDYcutValueMapEndcap;
  std::map<std::string, float> MediumDYcutValueMapBarrel;
  std::map<std::string, float> LooseDYcutValueMapEndcap;
  std::map<std::string, float> LooseDYcutValueMapBarrel;
  
 protected:
 private:
  
};
#endif
