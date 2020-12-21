/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <ctime>
#include <iostream>
#include<string>
#include <set>
#include <algorithm>
#include "Access.h"
 void Access::activate(unsigned int code)
	  {
	     pw.insert(code);
	  }
	   void Access::deactivate(unsigned int code)
	  {
	     pw.erase(code);
	  }
	  	bool Access:: isactive(unsigned int code) 
		{
			set<int>:: iterator siter=pw.begin();
			while(siter!=pw.end())
			{
				if(*siter==code) 
				return true;
				siter++;
				
			}
			return false;
	  	}
