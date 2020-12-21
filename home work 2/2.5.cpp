/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include <ctime>
#include <iostream>
#include<string>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
	set<int>s;
srand(time(NULL));
while(s.size()<6)
{
	s.insert( (rand() % 49 )+ 1);
}
set<int>::iterator it=s.begin();
while(it!=s.end())
{
	cout<<*it<<endl;
	it++;
}
	return 0;
}
