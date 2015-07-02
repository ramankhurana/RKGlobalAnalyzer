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
    cutsMap.clear();
    cutsMap["aleadingpteta"]=0;
    cutsMap["bsubleadingpteta"]=1;
    cutsMap["cleadingcsv"]=2;
    cutsMap["dsubleadingcsv"]=3;
    cutsMap["emetpt"]=4;
    cutsMap["fDPHIDijetMet"]=5;
    cutsMap["gMTDijet"]=6;
    cutsMap["hMDijet"]=7;
    cutsMap["iDPHIJet1Met"]=8;
    cutsMap["jDPHIJet2Met"]=9;
    cutsMap["kMTJet1"]=10;
    cutsMap["lMTJet2"]=11;


    
    // cutValueMap
    cutValueMap.clear();
    cutValueMap["leadingjetpt"]=80.;
    cutValueMap["subleadingjetpt"]=30;
    cutValueMap["jeteta"]=2.5;
    cutValueMap["leadingcsv"]=0.432;
    cutValueMap["subleadingcsv"]=0.432;
    cutValueMap["csvVLoose"]=0.25;
    cutValueMap["csvTight"]=0.732;
    cutValueMap["metpt"]=200;
    cutValueMap["dphiDiJetMet"]=2.5;
    cutValueMap["MTDiJet"]=400;
    cutValueMap["MDiJetLow"]=90.;
    cutValueMap["MDiJetHigh"]=150.;
    cutValueMap["DPHIJet1MET"]=2.;
    cutValueMap["DPHIJet2MET"]=2.;
    cutValueMap["MTJet1"]=300.;
    cutValueMap["MTJet2"]=200.;



    // cutValueMapTTBar
    cutValueMapTTBar.clear();
    cutValueMapTTBar["leadingjetpt"]=80.;
    cutValueMapTTBar["subleadingjetpt"]=30;
    cutValueMapTTBar["jeteta"]=2.5;
    cutValueMapTTBar["leadingcsv"]=0.432;
    cutValueMapTTBar["subleadingcsv"]=0.432;
    cutValueMapTTBar["csvVLoose"]=0.25;
    cutValueMapTTBar["csvTight"]=0.732;
    cutValueMapTTBar["metpt"]=200;
    cutValueMapTTBar["dphiDiJetMet"]=2.5;
    cutValueMapTTBar["MTDiJet"]=400;
    cutValueMapTTBar["MDiJetLow"]=90.;
    cutValueMapTTBar["MDiJetHigh"]=150.;
    cutValueMapTTBar["DPHIJet1MET"]=2.;
    cutValueMapTTBar["DPHIJet2MET"]=2.;
    cutValueMapTTBar["MTJet1"]=300.;
    cutValueMapTTBar["MTJet2"]=200.;

  };
  ~MonoHiggsCuts(){};
  std::map<std::string, int> cutsMap;
  std::map<std::string, float> cutValueMap;
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
