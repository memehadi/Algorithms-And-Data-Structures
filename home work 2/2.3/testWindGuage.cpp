/*Musab Mehadi
mmehadi@jacobs-university.de*/ 
#include <iostream>
#include<deque>
#include<string>
#include"WindGuage.h"
using namespace std;
int main() 
{
		WindGuage A;
		A.currentWindSpeed(15);
		A.currentWindSpeed(16);
		A.currentWindSpeed(12);
		A.currentWindSpeed(15);
		A.currentWindSpeed(15);
		A.dump();
		/*cout<<A.highest()<<endl;
		cout<<A.lowest()<<endl;
		cout<<A.average()<<endl;*/
		A.currentWindSpeed(16);
		A.currentWindSpeed(17);
		A.currentWindSpeed(16);
		A.currentWindSpeed(16);
		A.currentWindSpeed(20);
		A.currentWindSpeed(17);
		A.currentWindSpeed(16);
		A.currentWindSpeed(15);
		A.currentWindSpeed(16);
		A.currentWindSpeed(20);
		/*cout<<A.highest()<<endl;
		cout<<A.lowest()<<endl;
		cout<<A.average()<<endl;*/
		A.dump();
	return 0;
}
