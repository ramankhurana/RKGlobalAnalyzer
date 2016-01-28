#ifndef ScaleFactorElectron_h_
#define ScaleFactorElectron_h_ 
using namespace std; 
class ScaleFactorElectron{ 
 public: 
   ScaleFactorElectron(){};
   ~ScaleFactorElectron(){};
   static Float_t SFIdIsoReco(float eta, float pt){
   Float_t  SF;
if( eta >  -2.5 && eta <=   -2  && pt >   10  && pt <=   20) SF =  1.25131  ;
else if( eta >  -2 && eta <=   -1.566  && pt >   10  && pt <=   20) SF =  1.09255  ;
else if( eta >  -1.566 && eta <=   -1.444  && pt >   10  && pt <=   20) SF =  1.29412  ;
else if( eta >  -1.444 && eta <=   -0.8  && pt >   10  && pt <=   20) SF =  1.32673  ;
else if( eta >  -0.8 && eta <=   0  && pt >   10  && pt <=   20) SF =  1.23371  ;
else if( eta >  0 && eta <=   0.8  && pt >   10  && pt <=   20) SF =  1.22889  ;
else if( eta >  0.8 && eta <=   1.444  && pt >   10  && pt <=   20) SF =  1.30827  ;
else if( eta >  1.444 && eta <=   1.566  && pt >   10  && pt <=   20) SF =  1.35498  ;
else if( eta >  1.566 && eta <=   2  && pt >   10  && pt <=   20) SF =  1.06283  ;
else if( eta >  2 && eta <=   2.5  && pt >   10  && pt <=   20) SF =  1.20769  ;
else if( eta >  -2.5 && eta <=   -2  && pt >   20  && pt <=   30) SF =  1.0536  ;
else if( eta >  -2 && eta <=   -1.566  && pt >   20  && pt <=   30) SF =  0.969453  ;
else if( eta >  -1.566 && eta <=   -1.444  && pt >   20  && pt <=   30) SF =  1.04043  ;
else if( eta >  -1.444 && eta <=   -0.8  && pt >   20  && pt <=   30) SF =  1.05939  ;
else if( eta >  -0.8 && eta <=   0  && pt >   20  && pt <=   30) SF =  1.02262  ;
else if( eta >  0 && eta <=   0.8  && pt >   20  && pt <=   30) SF =  1.01799  ;
else if( eta >  0.8 && eta <=   1.444  && pt >   20  && pt <=   30) SF =  1.07742  ;
else if( eta >  1.444 && eta <=   1.566  && pt >   20  && pt <=   30) SF =  1.18801  ;
else if( eta >  1.566 && eta <=   2  && pt >   20  && pt <=   30) SF =  0.980392  ;
else if( eta >  2 && eta <=   2.5  && pt >   20  && pt <=   30) SF =  1.02649  ;
else if( eta >  -2.5 && eta <=   -2  && pt >   30  && pt <=   40) SF =  1.01235  ;
else if( eta >  -2 && eta <=   -1.566  && pt >   30  && pt <=   40) SF =  0.971279  ;
else if( eta >  -1.566 && eta <=   -1.444  && pt >   30  && pt <=   40) SF =  1.02482  ;
else if( eta >  -1.444 && eta <=   -0.8  && pt >   30  && pt <=   40) SF =  0.990897  ;
else if( eta >  -0.8 && eta <=   0  && pt >   30  && pt <=   40) SF =  0.978616  ;
else if( eta >  0 && eta <=   0.8  && pt >   30  && pt <=   40) SF =  0.986163  ;
else if( eta >  0.8 && eta <=   1.444  && pt >   30  && pt <=   40) SF =  1.00654  ;
else if( eta >  1.444 && eta <=   1.566  && pt >   30  && pt <=   40) SF =  0.990991  ;
else if( eta >  1.566 && eta <=   2  && pt >   30  && pt <=   40) SF =  0.961892  ;
else if( eta >  2 && eta <=   2.5  && pt >   30  && pt <=   40) SF =  1.0096  ;
else if( eta >  -2.5 && eta <=   -2  && pt >   40  && pt <=   50) SF =  1.00875  ;
else if( eta >  -2 && eta <=   -1.566  && pt >   40  && pt <=   50) SF =  0.983313  ;
else if( eta >  -1.566 && eta <=   -1.444  && pt >   40  && pt <=   50) SF =  0.990155  ;
else if( eta >  -1.444 && eta <=   -0.8  && pt >   40  && pt <=   50) SF =  0.974057  ;
else if( eta >  -0.8 && eta <=   0  && pt >   40  && pt <=   50) SF =  0.969838  ;
else if( eta >  0 && eta <=   0.8  && pt >   40  && pt <=   50) SF =  0.974448  ;
else if( eta >  0.8 && eta <=   1.444  && pt >   40  && pt <=   50) SF =  0.976359  ;
else if( eta >  1.444 && eta <=   1.566  && pt >   40  && pt <=   50) SF =  0.956153  ;
else if( eta >  1.566 && eta <=   2  && pt >   40  && pt <=   50) SF =  0.978469  ;
else if( eta >  2 && eta <=   2.5  && pt >   40  && pt <=   50) SF =  1.00125  ;
else if( eta >  -2.5 && eta <=   -2  && pt >   50  && pt <=   200) SF =  1.006  ;
else if( eta >  -2 && eta <=   -1.566  && pt >   50  && pt <=   200) SF =  0.985109  ;
else if( eta >  -1.566 && eta <=   -1.444  && pt >   50  && pt <=   200) SF =  0.948856  ;
else if( eta >  -1.444 && eta <=   -0.8  && pt >   50  && pt <=   200) SF =  0.958097  ;
else if( eta >  -0.8 && eta <=   0  && pt >   50  && pt <=   200) SF =  0.967489  ;
else if( eta >  0 && eta <=   0.8  && pt >   50  && pt <=   200) SF =  0.970819  ;
else if( eta >  0.8 && eta <=   1.444  && pt >   50  && pt <=   200) SF =  0.964773  ;
else if( eta >  1.444 && eta <=   1.566  && pt >   50  && pt <=   200) SF =  0.974394  ;
else if( eta >  1.566 && eta <=   2  && pt >   50  && pt <=   200) SF =  0.994253  ;
else if( eta >  2 && eta <=   2.5  && pt >   50  && pt <=   200) SF =  1.00481  ;
else if( eta >  2 && eta <=   2.5  && pt >   50  && pt <=   200) SF =  1.00481  ;
   else SF = 1;
   return SF;
  }
};
#endif
