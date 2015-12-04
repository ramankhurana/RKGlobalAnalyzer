#ifndef ScaleFactorElectron_h_
#define ScaleFactorElectron_h_ 
using namespace std; 
class ScaleFactorElectron{ 
 public: 
  ScaleFactorElectron(){};
  ~ScaleFactorElectron(){};
  static Float_t SFIdIsoReco(float pt, float eta){
    Float_t  SF;
    if( eta >  -2.5 && eta <=   -2.  && pt >   25.  && pt <=   40.) SF =  0.8574  ;
    else if( eta >  -2.5 && eta <=   -2.  && pt >   40.  && pt <=   55.) SF =  0.933  ;
    else if( eta >  -2.5 && eta <=   -2  && pt >   55.  && pt <=   8000.) SF =  0.8617  ;
    else if( eta >  -2 && eta <=   -1.6  && pt >   25  && pt <=   40) SF =  0.941  ;
    else if( eta >  -2 && eta <=   -1.6  && pt >   40  && pt <=   55) SF =  0.9689  ;
    else if( eta >  -2 && eta <=   -1.6  && pt >   55  && pt <=   8000) SF =  0.8314  ;
    else if( eta >  -1.6 && eta <=   -1.4  && pt >   25  && pt <=   40) SF =  0.9295  ;
    else if( eta >  -1.6 && eta <=   -1.4  && pt >   40  && pt <=   55) SF =  0.9776  ;
    else if( eta >  -1.6 && eta <=   -1.4  && pt >   55  && pt <=   8000) SF =  0.7222  ;
    else if( eta >  -1.4 && eta <=   -1  && pt >   25  && pt <=   40) SF =  0.8857  ;
    else if( eta >  -1.4 && eta <=   -1  && pt >   40.  && pt <=   55.) SF =  0.9077  ;
    else if( eta >  -1.4 && eta <=   -1  && pt >   55.  && pt <=   8000.) SF =  1.0068  ;
    else if( eta >  -1 && eta <=   -0.5  && pt >   25.  && pt <=   40.) SF =  0.9712  ;
    else if( eta >  -1 && eta <=   -0.5  && pt >   40  && pt <=   55) SF =  0.9662  ;
    else if( eta >  -1 && eta <=   -0.5  && pt >   55  && pt <=   8000) SF =  0.9368  ;
    else if( eta >  -0.5 && eta <=   0  && pt >   25  && pt <=   40) SF =  0.8908  ;
    else if( eta >  -0.5 && eta <=   0  && pt >   40  && pt <=   55) SF =  0.9585  ;
    else if( eta >  -0.5 && eta <=   0  && pt >   55  && pt <=   8000) SF =  0.9551  ;
    else if( eta >  0 && eta <=   0.5  && pt >   25  && pt <=   40) SF =  0.9178  ;
    else if( eta >  0 && eta <=   0.5  && pt >   40  && pt <=   55) SF =  0.9497  ;
    else if( eta >  0 && eta <=   0.5  && pt >   55  && pt <=   8000) SF =  0.9571  ;
    else if( eta >  0.5 && eta <=   1  && pt >   25  && pt <=   40) SF =  0.9003  ;
    else if( eta >  0.5 && eta <=   1  && pt >   40  && pt <=   55) SF =  0.9425  ;
    else if( eta >  0.5 && eta <=   1  && pt >   55  && pt <=   8000) SF =  0.9045  ;
    else if( eta >  1 && eta <=   1.4  && pt >   25  && pt <=   40) SF =  0.9137  ;
    else if( eta >  1 && eta <=   1.4  && pt >   40  && pt <=   55) SF =  0.9654  ;
    else if( eta >  1 && eta <=   1.4  && pt >   55  && pt <=   8000) SF =  0.905  ;
    else if( eta >  1.4 && eta <=   1.6  && pt >   25  && pt <=   40) SF =  0.9779  ;
    else if( eta >  1.4 && eta <=   1.6  && pt >   40  && pt <=   55) SF =  1.0267  ;
    else if( eta >  1.4 && eta <=   1.6  && pt >   55  && pt <=   8000) SF =  0.7712  ;
    else if( eta >  1.6 && eta <=   2  && pt >   25  && pt <=   40) SF =  0.9245  ;
    else if( eta >  1.6 && eta <=   2  && pt >   40  && pt <=   55) SF =  1.002  ;
    else if( eta >  1.6 && eta <=   2  && pt >   55  && pt <=   8000) SF =  0.9462  ;
    else if( eta >  2 && eta <=   2.5  && pt >   25  && pt <=   40) SF =  0.9974  ;
    else if( eta >  2 && eta <=   2.5  && pt >   40  && pt <=   55) SF =  1.0227  ;
    else if( eta >  2 && eta <=   2.5  && pt >   55  && pt <=   8000) SF =  0.8444  ;
    else SF = 1;
    return SF;
  }
};
#endif
