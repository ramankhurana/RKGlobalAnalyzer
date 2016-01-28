/////// Macro created for reading from a text file and producing a class
/// Created by Monika Mittal on 14/10/2015
// It read a line by line a text file and store the output in form of vectors
// Then these vectors can be using by just looping over the vector size 
//and then do what you want to do.
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

void ReadTxtfile(){

  ifstream in;
  string line;
  //input file                                                                                                                                    

  std::vector<float> eta_min;
  std::vector<float> eta_max;
  std::vector<float> pt_min;
  std::vector<float> pt_max;
  std::vector<float> DataEff;
  std::vector<float> DataStat;
  std::vector<float> MCEff;
  std::vector<float> MCStat;


  int nlines =0;

  // input file name should be given here                            
  in.open("TextFile/CutBasedID_MediumWP_fromTemplates_withSyst_v1.txt");

  double first, second , three, four, five, six, seven, eight;
  
  while(!in.eof()){
    getline(in,line);
    stringstream ss(stringstream::in | stringstream::out);
    //nlines <10 to read only 10 lines just to check everything                                                                                  
    if (line.empty()){continue;}
    if (!line.empty()) {
      ss << line;
      ss >> first >> second >> three >> four >>five >>six>>seven>>eight;
  
      eta_min.push_back(first);
      eta_max.push_back(second);
      pt_min.push_back(three);
      pt_max.push_back(four);
      DataEff.push_back(five);
      DataStat.push_back(six);
      MCEff.push_back(seven);
      MCStat.push_back(eight);
    

      nlines++;
      //cout<<"nlines"<<nlines<<std::endl;}                                                                                                          
    }
  }

  //to acess theis size variable.size() and loop over                                                                                            //and then use as them array                                                                                                                   //Event Loop example                                                                                                                            

  // To make a  class 
    std::cout<<"#include <iostream> "<<std::endl;
    std::cout<<"#include <fstream> "<<std::endl;
    ofstream f1;
    f1.open("ScaleFactorElectron.h");

    f1<<"#ifndef ScaleFactorElectron_h_"<<std::endl;
    f1<<"#define ScaleFactorElectron_h_ "<<std::endl;
    f1<<"using namespace std; "<<std::endl;
    f1<<"class ScaleFactorElectron{ "<<std::endl;
    f1<<" public: "<<std::endl;
    f1<<"   ScaleFactorElectron(){};"<<std::endl;
    f1<<"   ~ScaleFactorElectron(){};"<<std::endl;
    f1<<"   static Float_t SFIdIsoReco(float eta, float pt){"<<std::endl;
    f1<<"   Float_t  SF;"<<std::endl;
    for (int i=0; i < eta_min.size(); i++){
      if(i==0){
	f1<< "if( eta >  "  <<eta_min[i] <<  " && eta <=   "  << eta_max[i] <<  "  && pt >   "   << pt_min[i] <<   "  && pt <=   " << pt_max[i] <<  ") SF =  " << DataEff[i]/MCEff[i] <<"  ;"<<std::endl; }
      if( i >0 ){   
	f1<< "else if( eta >  "  <<eta_min[i] <<  " && eta <=   "  << eta_max[i] <<  "  && pt >   "   << pt_min[i] <<   "  && pt <=   " << pt_max[i] <<  ") SF =  " << DataEff[i]/MCEff[i] <<"  ;"<<std::endl; }
    }
    f1<<"   else SF = 1;"<<std::endl; 
    f1<<"   return SF;"<<std::endl;
    f1<<"  }"<<std::endl;
    f1<<"};"<<std::endl;
    f1<<"#endif"<<std::endl;
  }
