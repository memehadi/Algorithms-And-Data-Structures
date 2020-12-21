/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include <ctime>
#include <iostream>
#include<string>
#include <Map>
#include <algorithm>
using namespace std;
class Access
 { public: 
 void activate(unsigned int code, unsigned int level); 
 void deactivate(unsigned int code);
  bool isactive(unsigned int code, unsigned int level) const; 
  private: 
	multimap<int,int> pw;
	  };
	 

