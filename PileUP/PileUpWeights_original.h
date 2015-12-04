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
   puweight[1]  =  16.2584;
   puweight[2]  =  2.20943;
   puweight[3]  =  1.32993;
   puweight[4]  =  1.12761;
   puweight[5]  =  1.09906;
   puweight[6]  =  1.09521;
   puweight[7]  =  1.13427;
   puweight[8]  =  1.15009;
   puweight[9]  =  1.16977;
   puweight[10]  =  1.18912;
   puweight[11]  =  1.20655;
   puweight[12]  =  1.20503;
   puweight[13]  =  1.19651;
   puweight[14]  =  1.17393;
   puweight[15]  =  1.15065;
   puweight[16]  =  1.09714;
   puweight[17]  =  1.04272;
   puweight[18]  =  0.976857;
   puweight[19]  =  0.89849;
   puweight[20]  =  0.811159;
   puweight[21]  =  0.718325;
   puweight[22]  =  0.626695;
   puweight[23]  =  0.535531;
   puweight[24]  =  0.453575;
   puweight[25]  =  0.374567;
   puweight[26]  =  0.3182;
   puweight[27]  =  0.252982;
   puweight[28]  =  0.203313;
   puweight[29]  =  0.159056;
   puweight[30]  =  0.129763;
   puweight[31]  =  0.10139;
   puweight[32]  =  0.0834997;
   puweight[33]  =  0.0637982;
   puweight[34]  =  0.04424;
   puweight[35]  =  0.0433769;
   puweight[36]  =  0.0226092;
   puweight[37]  =  0.0325678;
   puweight[38]  =  0.0170084;
   puweight[39]  =  0.0254069;
   puweight[40]  =  0.011458;
   puweight[41]  =  0.0199781;
   puweight[42]  =  0.00749179;
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
