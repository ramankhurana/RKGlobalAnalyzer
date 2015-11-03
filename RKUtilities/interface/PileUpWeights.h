#ifndef PileUpWeights_h_
#define PileUpWeights_h_ 
using namespace std; 
class PileUpWeights{ 
 public: 
   PileUpWeights(){};
   ~PileUpWeights(){};
   static Float_t PUWEIGHT(Int_t nvtx){
   Float_t  puweight[60];
   puweight[0]  =  0;
   puweight[1]  =  22.7744;
   puweight[2]  =  3.32828;
   puweight[3]  =  1.68559;
   puweight[4]  =  1.50962;
   puweight[5]  =  1.34392;
   puweight[6]  =  1.25677;
   puweight[7]  =  1.25528;
   puweight[8]  =  1.21745;
   puweight[9]  =  1.21303;
   puweight[10]  =  1.2001;
   puweight[11]  =  1.20649;
   puweight[12]  =  1.16826;
   puweight[13]  =  1.15274;
   puweight[14]  =  1.12221;
   puweight[15]  =  1.09682;
   puweight[16]  =  1.04489;
   puweight[17]  =  1.02311;
   puweight[18]  =  0.938663;
   puweight[19]  =  0.875267;
   puweight[20]  =  0.814202;
   puweight[21]  =  0.754991;
   puweight[22]  =  0.685;
   puweight[23]  =  0.609266;
   puweight[24]  =  0.516387;
   puweight[25]  =  0.426086;
   puweight[26]  =  0.405862;
   puweight[27]  =  0.333153;
   puweight[28]  =  0.280702;
   puweight[29]  =  0.226911;
   puweight[30]  =  0.230156;
   puweight[31]  =  0.164951;
   puweight[32]  =  0.156805;
   puweight[33]  =  0.134342;
   puweight[34]  =  0.082246;
   puweight[35]  =  0.123987;
   puweight[36]  =  0.0643106;
   puweight[37]  =  0.0799027;
   puweight[38]  =  0.0480207;
   puweight[39]  =  0.0718533;
   puweight[40]  =  0.0492395;
   puweight[41]  =  0.0873891;
   puweight[42]  =  0.134725;
   puweight[43]  =  0;
   puweight[44]  =  0;
   puweight[45]  =  0;
   puweight[46]  =  0;
   puweight[47]  =  0;
   puweight[48]  =  0;
   puweight[49]  =  0;
   puweight[50]  =  0;
   puweight[51]  =  0;
   puweight[52]  =  0;
   puweight[53]  =  0;
   puweight[54]  =  0;
   puweight[55]  =  0;
   puweight[56]  =  0;
   puweight[57]  =  0;
   puweight[58]  =  0;
   puweight[59]  =  0;
   return puweight[nvtx];
  }
};
#endif
