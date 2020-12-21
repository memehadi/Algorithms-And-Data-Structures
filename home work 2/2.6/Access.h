/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <ctime>
#include <iostream>
#include<string>
#include <set>
#include <algorithm>
using namespace std;
	class Access 
	{ 
	public: 
	void activate(unsigned int code); 
	void deactivate(unsigned int code); 
	bool isactive(unsigned int code) ;
	 private:
	 set<int> pw;
	  };
	 
