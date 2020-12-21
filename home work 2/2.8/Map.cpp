 /*Musab Mehadi
mmehadi@jacobs-university.de
*/
 #include <ctime>
#include <iostream>
#include<string>
#include <Map>
#include <algorithm>
#include "Map.h"
 void Access::activate(unsigned int code, unsigned int level)
	  {
	     pw.insert(pair<int,int>(code,level));
	  }
	   void Access::deactivate(unsigned int code)
	  {
	     pw.erase(code);
	  }
	  	bool Access:: isactive(unsigned int code, unsigned int level) const {
		  
		
		if (pw.find(code)==pw.end())
		{
			cout<<"code dont exist"<<endl;
			return false;
		}
		else {
		if(pw.find(code)->second<=level)
		{
			cout<<"you can get access"<<endl;
			return true;
		}
		else
		{
			cout<<"your access level can not be less"<<endl;
			return false;
		}
	}
	}
		/*{
			/*multimap<int,int>:: iterator miter=pw.begin();
			while(miter!=pw.end())
			{
				if(*siter==code) 
				return true;
				siter++;
				
			}*/
	  	


