// Original class : RKMath.h
// Created By     : khurana 
// Created On     : Sun Apr 26 00:55:43 CEST 2015

#ifndef RKMath_h_
#define RKMath_h_


class RKMath {
 public:
  RKMath(){};
  ~RKMath(){};
  
  static Float_t m_pi(){return (3.1415926535);}
  
  static Float_t DeltaPhi(Float_t phi1, Float_t phi2){
    double result = phi1 - phi2;
    if(result>m_pi()) result -= 2*m_pi();
    else if (result <= -m_pi()) result += 2*m_pi() ;
    else result = result;
    return result;
  }

  static Float_t DeltaR(Float_t eta1, Float_t  phi1, Float_t eta2, Float_t phi2){
    double phi = phi1 - phi2;
    double eta = eta1 - eta2;
    double dr2 = (phi*phi) + (eta*eta) ;
    double dr = sqrt(dr2);
    return dr;
  }
 protected:
 private:
  
};
#endif
