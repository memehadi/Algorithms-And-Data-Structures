/*Musab Mehadi
mmehadi@jacobs-university.de
*/

#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;
//const int size = 50;
int main()
{
  vector<int>vi;
for(int i=0;i<30;i++)
{
	vi.push_back(i+1);
	//cout<<"Q"<<endl;
}	
	vi.push_back(5);
	reverse(vi.begin(),vi.end());
  	vector<int>::iterator viter = vi.begin(); 
    while (viter != vi.end()) 
	{
		if (viter==(vi.end())-1)
			cout << *viter;
		else
			cout << *viter << ",  " ;
		viter++;
	}
	cout<<endl;
replace(vi.begin(),vi.end(),5,129);
 viter = vi.begin();
while (viter != vi.end()) 
	{
		if (viter==(vi.end())-1)
			cout << *viter;
		else
			cout << *viter << ",  " ;
		viter++;
	}	

}
