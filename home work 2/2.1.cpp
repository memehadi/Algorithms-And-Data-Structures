/*Musab Musab
mmehadi@jacobs-university.de*/
#include <iostream>
#include <cstdlib>
#include<string>
#include"list"
#include<fstream>
using namespace std;
int main()
{
	list <int> A;
	list <int> B;
	int x;
	while(1)
	{
		cout<<"enter an integer"<<endl;
		cin>>x;
		if(x<=0)
			{
				cout<<"yor input must be greater than zero"<<endl;
				break;
			}
		else
			{
				A.push_back(x);
				B.push_front(x);
			}
		}
		ostream out;
		out.open("listB.txt");
		
	list<int>::iterator liter = A.begin(); 
    while (liter != A.end()) 
	{
	/*if (liter==((A.end())-1);
			cout << *liter;
		else*/
			cout << *liter << " , " ;
		liter++;
	}

	cout<<endl;
	/*for(int i=0;i<A.size();i++)
	{
		cout<<A[i]<<" ";
	}*/
	while(!B.empty())
	{
			cout << B.front() << " ";
		B.pop_front();
	}
		/*liter=A.begin();
		list<int>::iterator temp = A.begin();*/
		//A.swap(A[0],A[]
		
return 0;
}
