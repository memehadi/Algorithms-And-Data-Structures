/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <ctime>
#include <iostream>
#include<string>
#include <set>
#include <algorithm>
#include "Access.h"
using namespace std;

int main()
{
	Access people;
	people.activate(1234);
	people.activate(9999);
	people.activate(9876);
	int password;
//	while(password!=1234 && password!=9999 && password!=9876 )
	cout<<"enter the access code"<<endl;
	here:
	cin>>password;
	if(password==1234||password==9999 || password==9876)
	cout<<"access granted"<<endl;
	else 
	{
	cout<<"access denied please enter a new password"<<endl;
	goto here;
	}
    people.deactivate(password);
    people.deactivate(9999);
    people.activate(1111);
    int newpassword;
    cout<<"enter the access code"<<endl;
	newhere:
	cin>>newpassword;
	if(newpassword==1234||newpassword==1111 || newpassword==9876)
	cout<<"access granted"<<endl;
	else 
	{
	cout<<"access denied please enter a new password"<<endl;
	goto newhere;
	}

	return 0;
}
