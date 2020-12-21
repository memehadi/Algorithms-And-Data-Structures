/*Musab Musab
mmehadi@jacobs-university.de*/
#include <iostream>
#include <cstdlib>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
	deque <float> A;
	int x;
	cout<<"enter a float"<<endl;
	while(1)
	{
		cin>>x;
		if(x==0)
			{
				cout<<"yor input can not be zero"<<endl;
				break;
			}
		else if(x>0)
			{
				A.push_back(x);
				cout<<" positive number added at the end of the deque "<<endl;
			}
		else
			{
				A.push_front(x);
				cout<<" negative number added at the beginning of the deque "<<endl;
			}			
		}
		
	for(int i=0;i<A.size();i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	
	deque<float>::iterator diter=A.begin();
	/*while (*diter<0 && diter != A.end()) 
	{
		diter++;
}
		A.insert(diter,0);*/
			while  ( diter != A.end())
		{
		if(*diter<0 && *(diter+1)>0) 
		A.insert(diter+1,0);
		diter++;
}
		
	

	
	////////////////////////////////////
	////////////////////
	/////////////////////
	/////////////////
	///////////////
	for(int i=0;i<A.size();i++)
	{
		if(i==(A.size())-1)
		cout<<A[i]<<endl;
		else
		cout<<A[i]<<";";
	}
	
	return 0;
	}
