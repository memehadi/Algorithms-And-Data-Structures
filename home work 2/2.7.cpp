/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include<cstdlib>
#include <iostream>
#include<string>
#include <map>
#include <algorithm>
#include<fstream>
using namespace std;
int main()
{
	map<string,string>names;
	ifstream in;
	string x;
	string y;
	in.open("data.txt");
	while(!in.eof())
	{
		getline(in,y);
		getline(in,x);	
		names.insert(pair<string,string>(y,x));
	}
	map<string,string>::iterator it=names.begin();
	while(it!=names.end())
	{
		cout<< it->first<<"        "<<it->second<<endl;
		it++;
	}
	string input1;
	cout<<"enter a name"<<endl;

	getline(cin,input1);
	if(names.find(input1) == names.end())
	{
		cout<<"Name not found!"<<endl;
	}
	else
	{
		cout<<names[input1];    
	}
in.close();//closing file	
return 0;
}
