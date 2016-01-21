void WJetsTTScaleFactors(){

  Double_t  a1, a2, b1, b2, c1, c2;
  
  std::cout<<" Enter Values for first equation ";

  std::cout<<" Enter Value of a1 = ";
  std::cin>>a1;
  
  std::cout<<" Enter Value of b1 = ";
  std::cin>>b1;

  std::cout<<" Enter Value of c1 = ";
  std::cin>>c1;



  std::cout<<" Enter Values for second equation ";

  std::cout<<" Enter Value of a2 = ";
  std::cin>>a2;
  
  std::cout<<" Enter Value of b2 = ";
  std::cin>>b2;

  std::cout<<" Enter Value of c2 = ";
  std::cin>>c2;
  
  
  Double_t x = (c1*b2 - c2*b1) / (b2*a1 - b1*a2);
  Double_t y = (a1*c2 - a2*c1) / (b2*a1 - b1*a2);
  
  std::cout<<" x = "<<x
	   <<" and y = "<<y
	   <<std::endl;
}
