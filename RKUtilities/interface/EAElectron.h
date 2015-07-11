// taken from /cvmfs/cms.cern.ch/slc6_amd64_gcc491/cms/cmssw/CMSSW_7_4_5/external/slc6_amd64_gcc491/data/RecoEgamma/ElectronIdentification/data/PHYS14/effAreaElectrons_cone03_pfNeuHadronsAndPhotons.txt
// Origin Class : EAElectron.h
// Created By   : khurana
// Created On   : Sun Apr 26 00:55:43 CEST 2015
#ifndef EAElectron_h_
#define EAElectron_h_

class EAElectron{
  EAElectron();
 public :
  static float EA(float eta);
};
#endif


float EAElectron::EA(float eta){
  float ea;
  if(abs(eta) > 0.0 && abs (eta) < 0.8 ) ea = 0.1013;
  else if (abs(eta) > 0.8 && abs (eta) <= 1.3 ) ea = 0.0988;
  else if (abs(eta) > 1.3 && abs (eta) <= 2.0 ) ea = 0.0572;
  else if (abs(eta) > 2.0 && abs (eta) <= 2.2 ) ea = 0.0842;
  else if (abs(eta) > 2.2 && abs (eta) <= 5.0 ) ea = 0.1530;
  else ea = 0.1013; // default is taken as first bin
  return ea;
}
