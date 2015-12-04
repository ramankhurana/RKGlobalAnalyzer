#ifndef ScaleFactorElectron_h_
#define ScaleFactorElectron_h_ 
using namespace std; 
class ScaleFactorElectron{ 
 public: 
   ScaleFactorElectron(){};
   ~ScaleFactorElectron(){};
   static Float_t SFIdIsoReco(float eta, float pt){
   Float_t  SF;
if( eta >  -2.5 && eta <=   -2  && pt >   25  && pt <=   40) SF =  0.8574  ;
if( eta >  -2.5 && eta <=   -2  && pt >   40  && pt <=   55) SF =  0.933  ;
if( eta >  -2.5 && eta <=   -2  && pt >   55  && pt <=   8000) SF =  0.8617  ;
if( eta >  -2 && eta <=   -1.6  && pt >   25  && pt <=   40) SF =  0.941  ;
if( eta >  -2 && eta <=   -1.6  && pt >   40  && pt <=   55) SF =  0.9689  ;
if( eta >  -2 && eta <=   -1.6  && pt >   55  && pt <=   8000) SF =  0.8314  ;
if( eta >  -1.6 && eta <=   -1.4  && pt >   25  && pt <=   40) SF =  0.9295  ;
if( eta >  -1.6 && eta <=   -1.4  && pt >   40  && pt <=   55) SF =  0.9776  ;
if( eta >  -1.6 && eta <=   -1.4  && pt >   55  && pt <=   8000) SF =  0.7222  ;
if( eta >  -1.4 && eta <=   -1  && pt >   25  && pt <=   40) SF =  0.8857  ;
if( eta >  -1.4 && eta <=   -1  && pt >   40  && pt <=   55) SF =  0.9077  ;
if( eta >  -1.4 && eta <=   -1  && pt >   55  && pt <=   8000) SF =  1.0068  ;
if( eta >  -1 && eta <=   -0.5  && pt >   25  && pt <=   40) SF =  0.9712  ;
if( eta >  -1 && eta <=   -0.5  && pt >   40  && pt <=   55) SF =  0.9662  ;
if( eta >  -1 && eta <=   -0.5  && pt >   55  && pt <=   8000) SF =  0.9368  ;
if( eta >  -0.5 && eta <=   0  && pt >   25  && pt <=   40) SF =  0.8908  ;
if( eta >  -0.5 && eta <=   0  && pt >   40  && pt <=   55) SF =  0.9585  ;
if( eta >  -0.5 && eta <=   0  && pt >   55  && pt <=   8000) SF =  0.9551  ;
if( eta >  0 && eta <=   0.5  && pt >   25  && pt <=   40) SF =  0.9178  ;
if( eta >  0 && eta <=   0.5  && pt >   40  && pt <=   55) SF =  0.9497  ;
if( eta >  0 && eta <=   0.5  && pt >   55  && pt <=   8000) SF =  0.9571  ;
if( eta >  0.5 && eta <=   1  && pt >   25  && pt <=   40) SF =  0.9003  ;
if( eta >  0.5 && eta <=   1  && pt >   40  && pt <=   55) SF =  0.9425  ;
if( eta >  0.5 && eta <=   1  && pt >   55  && pt <=   8000) SF =  0.9045  ;
if( eta >  1 && eta <=   1.4  && pt >   25  && pt <=   40) SF =  0.9137  ;
if( eta >  1 && eta <=   1.4  && pt >   40  && pt <=   55) SF =  0.9654  ;
if( eta >  1 && eta <=   1.4  && pt >   55  && pt <=   8000) SF =  0.905  ;
if( eta >  1.4 && eta <=   1.6  && pt >   25  && pt <=   40) SF =  0.9779  ;
if( eta >  1.4 && eta <=   1.6  && pt >   40  && pt <=   55) SF =  1.0267  ;
if( eta >  1.4 && eta <=   1.6  && pt >   55  && pt <=   8000) SF =  0.7712  ;
if( eta >  1.6 && eta <=   2  && pt >   25  && pt <=   40) SF =  0.9245  ;
if( eta >  1.6 && eta <=   2  && pt >   40  && pt <=   55) SF =  1.002  ;
if( eta >  1.6 && eta <=   2  && pt >   55  && pt <=   8000) SF =  0.9462  ;
if( eta >  2 && eta <=   2.5  && pt >   25  && pt <=   40) SF =  0.9974  ;
if( eta >  2 && eta <=   2.5  && pt >   40  && pt <=   55) SF =  1.0227  ;
if( eta >  2 && eta <=   2.5  && pt >   55  && pt <=   8000) SF =  0.8444  ;
   else SF = 1;
   return SF;
  }
};
#endif
