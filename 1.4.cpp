/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include <vector>
#include <iostream>
#include<string>
//const int size = 50;

using namespace std;

int main()
{
	
	vector<string> vs;		// a vector of ints. Default size is accepted
	string s;
	while (1)
		{
			cin>>s;
			if(s=="END")
				{
					break;
				}
			
			vs.push_back(s);
			///	cout<<"size is "<<vs.size()<<endl;		 
		}
	for (int i = 0; i < vs.size(); i++)	// uses the overloaded [] operator 
										// to access data
    	cout << vs[i] << " ";
		cout<<endl;	
    	vector<string>::iterator viter = vs.begin(); 
    while (viter != vs.end()) 
	{
		if (viter==(vs.end())-1)
			cout << *viter;
		else
			cout << *viter << ",  " ;
		viter++;
	}
return 0;	 
}  
