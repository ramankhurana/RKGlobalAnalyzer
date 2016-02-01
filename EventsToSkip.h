#ifndef EventsToSkip_h_
#define EventsToSkip_h_ 
#include "TString.h" 
using namespace std; 
class EventsToSkip{ 
 public: 
   std::vector<TString> eventlist;
   EventsToSkip(){
   eventlist.clear();
eventlist.push_back("254227:21:19773018");
eventlist.push_back("254227:21:19807176");
eventlist.push_back("254227:21:19881713");
eventlist.push_back("254227:21:20085119");
eventlist.push_back("254227:21:20109077");
eventlist.push_back("254227:21:20190779");
eventlist.push_back("254227:21:20239864");
eventlist.push_back("254227:21:20275585");
eventlist.push_back("254227:21:20279697");
eventlist.push_back("254227:21:20327621");
eventlist.push_back("254227:21:20456741");
eventlist.push_back("254227:21:20465212");
eventlist.push_back("254227:21:20791342");
eventlist.push_back("254227:22:20820007");
eventlist.push_back("254227:22:20871956");
eventlist.push_back("254227:22:20929473");
eventlist.push_back("254227:22:20965956");
eventlist.push_back("254227:22:21033379");
eventlist.push_back("254227:22:21055865");
eventlist.push_back("254227:22:21076706");
eventlist.push_back("254227:22:21078157");
eventlist.push_back("254227:22:21177805");
eventlist.push_back("254227:22:21209752");
eventlist.push_back("254227:22:21276307");
eventlist.push_back("254227:22:21281902");
eventlist.push_back("254227:22:21314346");
eventlist.push_back("254227:22:21422306");
eventlist.push_back("254227:22:21526859");
eventlist.push_back("254227:22:21668624");
eventlist.push_back("254227:22:21674316");
eventlist.push_back("254227:21:19773018");
eventlist.push_back("254227:21:19807176");
eventlist.push_back("254227:21:19881713");
eventlist.push_back("254227:21:20085119");
eventlist.push_back("254227:21:20109077");
eventlist.push_back("254227:21:20190779");
eventlist.push_back("");
  }
   ~EventsToSkip(){};
std::vector<TString> EventList(){
  return eventlist;
  }
};
#endif
