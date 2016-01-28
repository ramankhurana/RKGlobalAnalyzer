#ifndef PileUpWeights_h_
#define PileUpWeights_h_ 
using namespace std; 
class PileUpWeights{ 
 public: 
   PileUpWeights(){};
   ~PileUpWeights(){};
   static Float_t PUWEIGHT(Int_t nvtx){
   Float_t  puweight[200]= {1.};
   puweight[0]  =  1;
   puweight[1]  =  76.0075;
   puweight[2]  =  141.672;
   puweight[3]  =  108.536;
   puweight[4]  =  33.2175;
   puweight[5]  =  16.5623;
   puweight[6]  =  3.21019;
   puweight[7]  =  1.67064;
   puweight[8]  =  1.99356;
   puweight[9]  =  2.71089;
   puweight[10]  =  2.72963;
   puweight[11]  =  2.65436;
   puweight[12]  =  2.61617;
   puweight[13]  =  2.30684;
   puweight[14]  =  1.72843;
   puweight[15]  =  1.09061;
   puweight[16]  =  0.572373;
   puweight[17]  =  0.259177;
   puweight[18]  =  0.11011;
   puweight[19]  =  0.0525016;
   puweight[20]  =  0.029831;
   puweight[21]  =  0.0176558;
   puweight[22]  =  0.00922755;
   puweight[23]  =  0.00409597;
   puweight[24]  =  0.00156594;
   puweight[25]  =  0.000564468;
   puweight[26]  =  0.000223401;
   puweight[27]  =  0.000110317;
   puweight[28]  =  6.87029e-05;
   puweight[29]  =  5.07085e-05;
   puweight[30]  =  3.91553e-05;
   puweight[31]  =  2.84123e-05;
   puweight[32]  =  1.88721e-05;
   puweight[33]  =  9.87497e-06;
   puweight[34]  =  4.40182e-06;
   puweight[35]  =  1.73263e-06;
   puweight[36]  =  6.39321e-07;
   puweight[37]  =  2.04986e-07;
   puweight[38]  =  7.78851e-08;
   puweight[39]  =  2.68419e-08;
   puweight[40]  =  8.44084e-09;
   puweight[41]  =  2.13722e-09;
   puweight[42]  =  6.49443e-10;
   puweight[43]  =  2.01329e-10;
   puweight[44]  =  4.85648e-11;
   puweight[45]  =  1.32343e-11;
   puweight[46]  =  3.13512e-12;
   puweight[47]  =  1.82668e-12;
   puweight[48]  =  4.67292e-13;
   puweight[49]  =  1.06172e-12;
   puweight[50]  =  0;
   puweight[51]  =  0;
   if(nvtx >= 50) puweight[nvtx] =0;
   return puweight[nvtx];
  }
};
#endif
