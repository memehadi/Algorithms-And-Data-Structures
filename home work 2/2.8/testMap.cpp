/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include <ctime>
#include <iostream>
#include<string>
#include <set>
#include <algorithm>
#include "Map.h"
using namespace std;

int main()
{
	Access people;
	people.activate(1234,1);
	people.activate(9999,5);
	people.activate(9876,9);
	int password;
//	while(password!=1234 && password!=9999 && password!=9876 )
	cout<<"enter the access code"<<endl;
	here:	cin>>password;
	if(people.isactive(password,5))
	cout<<"access granted"<<endl;
	else 
	{
	cout<<"access denied please enter a new password"<<endl;
	goto here;
	}
    people.deactivate(password);
    people.deactivate(9999);
    people.activate(1111,7);
    int newpassword;
    cout<<"enter the access code"<<endl;
	newhere:
	cin>>newpassword;
	if(people.isactive(password,5))
	cout<<"access granted"<<endl;
	else 
	{
	cout<<"access denied please enter a new password"<<endl;
	goto newhere;
	}

	return 0;
}

