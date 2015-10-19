// Original class : MonoHiggsCuts.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

#ifndef MonoHiggsCuts_h_
#define MonoHiggsCuts_h_
#include <map>
#include <unordered_map>
using namespace std;

class MonoHiggsCuts {
 public:
  MonoHiggsCuts(){
    // cutsMap
    // they are named like this so that they remain sorted in the map.
    // saved in alphabatical order in the cuts name map.
    cutsMap.clear();
    // preselection
    cutsMap["aleadingpteta"]       = 0  ;
    cutsMap["bsubleadingpteta"]    = 1  ;
    cutsMap["cleadingcsv"]         = 2  ;
    cutsMap["dsubleadingcsv"]      = 3  ;

    cutsMap["eDPHIDijetMet"]       = 4  ;
    cutsMap["fMDijet"]             = 5  ;
    cutsMap["gmetpt"]              = 6  ;
    
    // full selection
    cutsMap["hNele"]               = 7  ;
    cutsMap["iNmu"]                = 8  ;
    cutsMap["jNjet"]               = 9  ;
    cutsMap["kDPHIMETClosestJ"]    =10  ;
    
    //  0000 1111 1111 1111
    
    // When using Fat-Jet with MET
    cutsMapFatJet.clear();
    cutsMapFatJet["apteta"]             = 0;

    cutsMapFatJet["bcsv"]               = 1;
    cutsMapFatJet["c2subjet"]           = 2;
    cutsMapFatJet["d1subjet"]           = 3;
    cutsMapFatJet["edeltaRsubjet"]      = 4;
    cutsMapFatJet["fdeltaRAtLeastOneSubjet"] = 5;
    
    cutsMapFatJet["gDPHIJetMet"]        = 6;
    cutsMapFatJet["hMjet"]              = 7;
    cutsMapFatJet["imetpt"]             = 8;
    cutsMapFatJet["jNele"]              = 9;
    cutsMapFatJet["kNmu"]               = 10;
    cutsMapFatJet["lNjet"]              = 11;
    cutsMapFatJet["mNtau"]              = 12;
    // Specific for control Region
    cutsMapFatJet["nMjetVeto"]           =13;

    // cutValueMap
    cutValueMapFatJet.clear();
    cutValueMapFatJet["leadingjetpt"]=200.;
    cutValueMapFatJet["jeteta"]=2.5;
    cutValueMapFatJet["leadingcsv"]=0.605;
    cutValueMapFatJet["metpt"]=200.;
    cutValueMapFatJet["dphiDiJetMet"]=2.5;
    cutValueMapFatJet["MTDiJet"]=400;
    cutValueMapFatJet["MDiJetLow"]=100.;
    cutValueMapFatJet["MDiJetHigh"]=150.;
    cutValueMapFatJet["DPHIJet1MET"]=2.;
    cutValueMapFatJet["DPHIJet2MET"]=2.;
    cutValueMapFatJet["MTJet1"]=300.;
    cutValueMapFatJet["MTJet2"]=200.;
    cutValueMapFatJet["Nele"]=0;
    cutValueMapFatJet["Nmu"]=0;
    cutValueMapFatJet["Ntau"]=0;
    cutValueMapFatJet["Njet"]=2;// atleast 2 jets
    cutValueMapFatJet["DPHIMETClosedJ"]=0.5;


    
    
    
    // cutValueMap
    cutValueMap.clear();
    cutValueMap["leadingjetpt"]=80.;
    cutValueMap["subleadingjetpt"]=30;
    cutValueMap["jeteta"]=2.5;
    //cutValueMap["leadingcsv"]=0.432;
    //cutValueMap["subleadingcsv"]=0.432;
    cutValueMap["leadingcsv"]=0.605;
    cutValueMap["subleadingcsv"]=0.605;
    cutValueMap["metpt"]=200.;
    cutValueMap["dphiDiJetMet"]=2.5;
    cutValueMap["MTDiJet"]=400;
    cutValueMap["MDiJetLow"]=90.;
    cutValueMap["MDiJetHigh"]=150.;
    cutValueMap["DPHIJet1MET"]=2.;
    cutValueMap["DPHIJet2MET"]=2.;
    cutValueMap["MTJet1"]=300.;
    cutValueMap["MTJet2"]=200.;
    cutValueMap["Nele"]=0;
    cutValueMap["Nmu"]=0;
    cutValueMap["Ntau"]=0;
    cutValueMap["njet"]=2;// atleast 2 jets
    cutValueMap["DPHIMETClosedJ"]=0.5;

    
    

    // cutValueMapTTBar
    cutValueMapTTBar.clear();
    cutValueMapTTBar["leadingjetpt"]=200.;
    cutValueMapTTBar["jeteta"]=2.5;
    cutValueMapTTBar["leadingcsv"]=0.605;
    cutValueMapTTBar["metpt"]=200.;
    cutValueMapTTBar["dphiDiJetMet"]=2.5;
    cutValueMapTTBar["MTDiJet"]=400;
    cutValueMapTTBar["MDiJetLow"]=150.; //  make sure this cut is 
    cutValueMapTTBar["MDiJetHigh"]=100.; // applied correctly.
    cutValueMapTTBar["DPHIJet1MET"]=2.;
    cutValueMapTTBar["DPHIJet2MET"]=2.;
    cutValueMapTTBar["MTJet1"]=300.;
    cutValueMapTTBar["MTJet2"]=200.;
    cutValueMapTTBar["Nele"]=0;
    cutValueMapTTBar["Nmu"]=0;
    cutValueMapTTBar["Ntau"]=0;
    cutValueMapTTBar["Njet"]=2;// atleast 2 jets
    cutValueMapTTBar["DPHIMETClosedJ"]=0.5;


    
  };
  ~MonoHiggsCuts(){};
  std::map<std::string, int> cutsMap;
  std::map<std::string, int> cutsMapFatJet;
  
  std::map<std::string, float> cutValueMap;
  std::map<std::string, float> cutValueMapFatJet;
  std::map<std::string, float> cutValueMapTTBar;
    enum cuts  {
      dijetmass    = 0b0000000000000001,
      detaJets     = 0b0000000000000011,
      dphiJets     = 0b0000000000000111,
      ptOverpt1pt1 = 0b0000000000001111
    };
 protected:
 private:
  
};
#endif
