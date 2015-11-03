#include "t2.h"
#include <ctime>
#include <iostream>

using namespace std;
int main(){
  time_t start, end;
  time(&start);

  //TTree *tree=0;
  t2 obj1;
  //obj1 = new t2(tree);
  obj1.Loop();
  time(&end);
  std::cout<<" time used is = "<<-(start-end)<<" seconds"<<std::endl;

  return 0;
}
