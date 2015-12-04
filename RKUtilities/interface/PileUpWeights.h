#ifndef PileUpWeights_h_
#define PileUpWeights_h_ 
using namespace std; 
class PileUpWeights{ 
 public: 
   PileUpWeights(){};
   ~PileUpWeights(){};
   static Float_t PUWEIGHT(Int_t nvtx){
   Float_t  puweight[200]= {1.};
   puweight[1]  =  118.771;
   puweight[2]  =  157.616;
   puweight[3]  =  118.27;
   puweight[4]  =  34.6473;
   puweight[5]  =  20.1383;
   puweight[6]  =  3.8617;
   puweight[7]  =  2.21604;
   puweight[8]  =  2.74399;
   puweight[9]  =  3.40931;
   puweight[10]  =  3.15684;
   puweight[11]  =  2.91814;
   puweight[12]  =  2.70932;
   puweight[13]  =  2.21338;
   puweight[14]  =  1.50988;
   puweight[15]  =  0.854504;
   puweight[16]  =  0.404925;
   puweight[17]  =  0.170766;
   puweight[18]  =  0.0741342;
   puweight[19]  =  0.0385258;
   puweight[20]  =  0.0220523;
   puweight[21]  =  0.0115762;
   puweight[22]  =  0.00511544;
   puweight[23]  =  0.00189828;
   puweight[24]  =  0.000632312;
   puweight[25]  =  0.000219444;
   puweight[26]  =  9.38868e-05;
   puweight[27]  =  5.12995e-05;
   puweight[28]  =  3.33857e-05;
   puweight[29]  =  2.41903e-05;
   puweight[30]  =  1.82184e-05;
   puweight[31]  =  1.29633e-05;
   puweight[32]  =  7.83545e-06;
   puweight[33]  =  3.83077e-06;
   puweight[34]  =  1.57204e-06;
   puweight[35]  =  5.75802e-07;
   puweight[36]  =  1.95809e-07;
   puweight[37]  =  6.29474e-08;
   puweight[38]  =  1.92754e-08;
   puweight[39]  =  5.6417e-09;
   puweight[40]  =  1.58122e-09;
   puweight[41]  =  4.24923e-10;
   puweight[42]  =  1.096e-10;
   puweight[43]  =  2.71545e-11;
   puweight[44]  =  6.4671e-12;
   puweight[45]  =  1.48151e-12;
   puweight[46]  =  3.26598e-13;
   puweight[47]  =  1.715e-13;
   puweight[48]  =  5.08905e-14;
   puweight[49]  =  4.63956e-14;
   puweight[50]  =  0;
   puweight[51]  =  0;
   puweight[52]  =  0;
   if(nvtx >= 50) puweight[nvtx] =1;
   return puweight[nvtx];
  }
};
#endif
