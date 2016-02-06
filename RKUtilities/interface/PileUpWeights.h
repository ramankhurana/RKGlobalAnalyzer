#ifndef PileUpWeights_h_
#define PileUpWeights_h_ 
using namespace std; 
class PileUpWeights{ 
 public: 
   PileUpWeights(){};
   ~PileUpWeights(){};
   static Float_t PUWEIGHT(Int_t nvtx){
   Float_t  puweight[200]= {1.};
   puweight[0]  =  1.;
   puweight[1]  =  162.405;
   puweight[2]  =  123.505;
   puweight[3]  =  30.4728;
   puweight[4]  =  17.0003;
   puweight[5]  =  3.16955;
   puweight[6]  =  1.67983;
   puweight[7]  =  2.00222;
   puweight[8]  =  2.70321;
   puweight[9]  =  2.72198;
   puweight[10]  =  2.66497;
   puweight[11]  =  2.61761;
   puweight[12]  =  2.3039;
   puweight[13]  =  1.73163;
   puweight[14]  =  1.09124;
   puweight[15]  =  0.572786;
   puweight[16]  =  0.25889;
   puweight[17]  =  0.110005;
   puweight[18]  =  0.0524568;
   puweight[19]  =  0.0299666;
   puweight[20]  =  0.0176408;
   puweight[21]  =  0.00921793;
   puweight[22]  =  0.00407931;
   puweight[23]  =  0.00156008;
   puweight[24]  =  0.000561605;
   puweight[25]  =  0.000223715;
   puweight[26]  =  0.000111408;
   puweight[27]  =  6.9408e-05;
   puweight[28]  =  5.01042e-05;
   puweight[29]  =  3.8732e-05;
   puweight[30]  =  2.89728e-05;
   puweight[31]  =  1.87439e-05;
   puweight[32]  =  9.51068e-06;
   puweight[33]  =  4.2903e-06;
   puweight[34]  =  1.69486e-06;
   puweight[35]  =  6.29131e-07;
   puweight[36]  =  2.21324e-07;
   puweight[37]  =  7.49491e-08;
   puweight[38]  =  2.42443e-08;
   puweight[39]  =  7.36554e-09;
   puweight[40]  =  2.22336e-09;
   puweight[41]  =  6.25637e-10;
   puweight[42]  =  1.77453e-10;
   puweight[43]  =  4.67515e-11;
   puweight[44]  =  1.14411e-11;
   puweight[45]  =  2.96267e-12;
   puweight[46]  =  2.13236e-12;
   puweight[47]  =  7.14993e-13;
   puweight[48]  =  4.02716e-13;
   puweight[49]  =  3.10075e-13;
   puweight[50]  =  0;
   puweight[51]  =  0;
   puweight[52]  =  0;
   if(nvtx >= 50) puweight[nvtx] =0;
   return puweight[nvtx];
  }
};
#endif
