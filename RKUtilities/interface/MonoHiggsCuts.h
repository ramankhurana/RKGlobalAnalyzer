// Original class : MonoHiggsCuts.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

#ifndef MonoHiggsCuts_h_
#define MonoHiggsCuts_h_
#include <map>
using namespace std;

class MonoHiggsCuts {
 public:
  MonoHiggsCuts(){
    cutsMap.clear();
    cutsMap["leadingpteta"]=0;
    cutsMap["subleadingpteta"]=1;
    cutsMap["leadingcsv"]=2;
    cutsMap["subleadingcsv"]=3;
    cutsMap["metpt"]=4;
    cutsMap["DPHIDijetMet"]=5;
    cutsMap["MTDijet"]=6;
    cutsMap["MDijet"]=7;
    cutsMap["DPHIJet1Met"]=8;
    cutsMap["DPHIJet2Met"]=9;
    cutsMap["MTJet1"]=10;
    cutsMap["MTJet2"]=11;
  };
  ~MonoHiggsCuts(){};
  std::map<std::string, int> cutsMap;
    
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
