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
   puweight[1]  =  22.0644;
   puweight[2]  =  3.22452;
   puweight[3]  =  1.63304;
   puweight[4]  =  1.46256;
   puweight[5]  =  1.30203;
   puweight[6]  =  1.21759;
   puweight[7]  =  1.21615;
   puweight[8]  =  1.17949;
   puweight[9]  =  1.17521;
   puweight[10]  =  1.16269;
   puweight[11]  =  1.16888;
   puweight[12]  =  1.13184;
   puweight[13]  =  1.1168;
   puweight[14]  =  1.08723;
   puweight[15]  =  1.06263;
   puweight[16]  =  1.01232;
   puweight[17]  =  0.991215;
   puweight[18]  =  0.9094;
   puweight[19]  =  0.847981;
   puweight[20]  =  0.788819;
   puweight[21]  =  0.731454;
   puweight[22]  =  0.663645;
   puweight[23]  =  0.590272;
   puweight[24]  =  0.500288;
   puweight[25]  =  0.412803;
   puweight[26]  =  0.393209;
   puweight[27]  =  0.322767;
   puweight[28]  =  0.271951;
   puweight[29]  =  0.219837;
   puweight[30]  =  0.222981;
   puweight[31]  =  0.159809;
   puweight[32]  =  0.151916;
   puweight[33]  =  0.130154;
   puweight[34]  =  0.079682;
   puweight[35]  =  0.120122;
   puweight[36]  =  0.0623058;
   puweight[37]  =  0.0774117;
   puweight[38]  =  0.0465237;
   puweight[39]  =  0.0696132;
   puweight[40]  =  0.0477045;
   puweight[41]  =  0.0846647;
   puweight[42]  =  0.130525;
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
