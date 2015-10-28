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
    cutsMapFatJet["nMjetVeto"]          = 13;
    cutsMapFatJet["oNjetless"]          = 14;
    cutsMapFatJet["pNLepton"]           = 15;
    cutsMapFatJet["qZLightBJet"]        = 16;
    cutsMapFatJet["rZHeavyBJet"]        = 17;
    cutsMapFatJet["s"]                  = 18;
    cutsMapFatJet["t"]                  = 19;
    cutsMapFatJet["u"]                  = 20;
    cutsMapFatJet["v"]                  = 21;
    cutsMapFatJet["w"]                  = 22;
    cutsMapFatJet["x"]                  = 23;
    cutsMapFatJet["y"]                  = 24;
    cutsMapFatJet["z"]                  = 25;
    

    // cutValueMap
    cutValueMapFatJet.clear();
    cutValueMapFatJet["leadingjetpt"]=200.;
    cutValueMapFatJet["jeteta"]=2.5;
    cutValueMapFatJet["leadingcsv"]=0.605;
    cutValueMapZLight["csvlow"]=0.3;
    cutValueMapZLight["csvhigh"]=0.6;
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
    cutValueMapFatJet["NLepton"]=0;
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
    cutValueMapZLight["csvlow"]=0.3;
    cutValueMapZLight["csvhigh"]=0.6;
    cutValueMapTTBar["metpt"]=200.;
    cutValueMapTTBar["dphiDiJetMet"]=2.5;
    cutValueMapTTBar["MTDiJet"]=400;
    cutValueMapTTBar["MDiJetLow"]=150.; //  make sure this cut is 
    cutValueMapTTBar["MDiJetHigh"]=100.; // applied correctly.
    cutValueMapTTBar["DPHIJet1MET"]=2.;
    cutValueMapTTBar["DPHIJet2MET"]=2.;
    cutValueMapTTBar["MTJet1"]=300.;
    cutValueMapTTBar["MTJet2"]=200.;
    cutValueMapTTBar["Nele"]=1;
    cutValueMapTTBar["Nmu"]=1;
    cutValueMapTTBar["Ntau"]=1;
    cutValueMapTTBar["Njet"]=1;// atleast 1 jets
    cutValueMapTTBar["NLepton"]=1;
    cutValueMapTTBar["DPHIMETClosedJ"]=0.5;


    // cutValueMapZLight
    cutValueMapZLight.clear();
    cutValueMapZLight["leadingjetpt"]=200.;
    cutValueMapZLight["jeteta"]=2.5;
    cutValueMapZLight["leadingcsv"]=0.605;
    cutValueMapZLight["csvlow"]=0.3;
    cutValueMapZLight["csvhigh"]=0.6;
    cutValueMapZLight["metpt"]=200.;
    cutValueMapZLight["dphiDiJetMet"]=2.5;
    cutValueMapZLight["MTDiJet"]=400;
    cutValueMapZLight["MDiJetLow"]=30.; //  make sure this cut is 
    cutValueMapZLight["MDiJetHigh"]=250.; // applied correctly.
    cutValueMapZLight["DPHIJet1MET"]=2.;
    cutValueMapZLight["DPHIJet2MET"]=2.;
    cutValueMapZLight["MTJet1"]=300.;
    cutValueMapZLight["MTJet2"]=200.;
    cutValueMapZLight["Nele"]=0;
    cutValueMapZLight["Nmu"]=0;
    cutValueMapZLight["Ntau"]=0;
    cutValueMapZLight["NLepton"]=0;
    cutValueMapZLight["Njet"]=2;
    cutValueMapZLight["DPHIMETClosedJ"]=0.5;



    // cutValueMapZHeavy
    cutValueMapZHeavy.clear();
    cutValueMapZHeavy["leadingjetpt"]=200.;
    cutValueMapZHeavy["jeteta"]=2.5;
    cutValueMapZHeavy["leadingcsv"]=0.605;
    cutValueMapZHeavy["csvlow"]=0.3;
    cutValueMapZHeavy["csvhigh"]=0.6;
    cutValueMapZHeavy["metpt"]=200.;
    cutValueMapZHeavy["dphiDiJetMet"]=2.5;
    cutValueMapZHeavy["MTDiJet"]=400;
    cutValueMapZHeavy["MDiJetLow"]=150.; //  make sure this cut is 
    cutValueMapZHeavy["MDiJetHigh"]=100.; // applied correctly.
    cutValueMapZHeavy["DPHIJet1MET"]=2.;
    cutValueMapZHeavy["DPHIJet2MET"]=2.;
    cutValueMapZHeavy["MTJet1"]=300.;
    cutValueMapZHeavy["MTJet2"]=200.;
    cutValueMapZHeavy["Nele"]=0;
    cutValueMapZHeavy["Nmu"]=0;
    cutValueMapZHeavy["Ntau"]=0;
    cutValueMapZHeavy["Njet"]=2;
    cutValueMapZHeavy["NLepton"]=0;
    cutValueMapZHeavy["DPHIMETClosedJ"]=0.5;



    // cutValueMapWLight
    // cutValueMapWLight
    cutValueMapWLight.clear();
    cutValueMapWLight["leadingjetpt"]=200.;
    cutValueMapWLight["jeteta"]=2.5;
    cutValueMapWLight["leadingcsv"]=0.605;
    cutValueMapWLight["csvlow"]=0.3;
    cutValueMapWLight["csvhigh"]=0.6;
    cutValueMapWLight["metpt"]=200.;
    cutValueMapWLight["dphiDiJetMet"]=2.5;
    cutValueMapWLight["MTDiJet"]=400;
    cutValueMapWLight["MDiJetLow"]=30.; //  make sure this cut is 
    cutValueMapWLight["MDiJetHigh"]=250.; // applied correctly.
    cutValueMapWLight["DPHIJet1MET"]=2.;
    cutValueMapWLight["DPHIJet2MET"]=2.;
    cutValueMapWLight["MTJet1"]=300.;
    cutValueMapWLight["MTJet2"]=200.;
    cutValueMapWLight["Nele"]=1;
    cutValueMapWLight["Nmu"]=1;
    cutValueMapWLight["Ntau"]=1;
    cutValueMapWLight["NLepton"]=1;
    cutValueMapWLight["Njet"]=1;
    cutValueMapWLight["DPHIMETClosedJ"]=0.5;
    
    //cutValueMapWLight.clear();
    //cutValueMapWLight["leadingjetpt"]=200.;
    //cutValueMapWLight["jeteta"]=2.5;
    //cutValueMapWLight["leadingcsv"]=0.605;
    //cutValueMapWLight["csvlow"]=0.3;
    //cutValueMapWLight["csvhigh"]=0.6;
    //cutValueMapWLight["metpt"]=200.;
    //cutValueMapWLight["dphiDiJetMet"]=2.5;
    //cutValueMapWLight["MTDiJet"]=400;
    //cutValueMapWLight["MDiJetLow"]=30.; //  make sure this cut is 
    //cutValueMapWLight["MDiJetHigh"]=250.; // applied correctly.
    //cutValueMapWLight["DPHIJet1MET"]=2.;
    //cutValueMapWLight["DPHIJet2MET"]=2.;
    //cutValueMapWLight["MTJet1"]=300.;
    //cutValueMapWLight["MTJet2"]=200.;
    //cutValueMapWLight["Nele"]=1;
    //cutValueMapWLight["Nmu"]=1;
    //cutValueMapWLight["Ntau"]=1;
    //cutValueMapWLight["Njet"]=1;
    //cutValueMapWLight["NLepton"]=1;
    //cutValueMapWLight["DPHIMETClosedJ"]=0.5;



    // cutValueMapWHeavy
    cutValueMapWHeavy.clear();
    cutValueMapWHeavy["leadingjetpt"]=200.;
    cutValueMapWHeavy["jeteta"]=2.5;
    cutValueMapWHeavy["leadingcsv"]=0.605;
    cutValueMapWHeavy["csvlow"]=0.3;
    cutValueMapWHeavy["csvhigh"]=0.6;
    cutValueMapWHeavy["metpt"]=200.;
    cutValueMapWHeavy["dphiDiJetMet"]=2.5;
    cutValueMapWHeavy["MTDiJet"]=400;
    cutValueMapWHeavy["MDiJetLow"]=150.; //  make sure this cut is 
    cutValueMapWHeavy["MDiJetHigh"]=100.; // applied correctly.
    cutValueMapWHeavy["DPHIJet1MET"]=2.;
    cutValueMapWHeavy["DPHIJet2MET"]=2.;
    cutValueMapWHeavy["MTJet1"]=300.;
    cutValueMapWHeavy["MTJet2"]=200.;
    cutValueMapWHeavy["Nele"]=1;
    cutValueMapWHeavy["Nmu"]=1;
    cutValueMapWHeavy["Ntau"]=1;
    cutValueMapWHeavy["Njet"]=1;
    cutValueMapWHeavy["NLepton"]=1;
    cutValueMapWHeavy["DPHIMETClosedJ"]=0.5;



  };
  ~MonoHiggsCuts(){};
  std::map<std::string, int> cutsMap;
  std::map<std::string, int> cutsMapFatJet;
  
  std::map<std::string, float> cutValueMap;
  std::map<std::string, float> cutValueMapFatJet;
  std::map<std::string, float> cutValueMapTTBar;
  std::map<std::string, float> cutValueMapZLight;
  std::map<std::string, float> cutValueMapZHeavy;
  std::map<std::string, float> cutValueMapWLight;
  std::map<std::string, float> cutValueMapWHeavy;
  
  
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
