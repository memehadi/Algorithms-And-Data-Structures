/*Musab Musab
mmehadi@jacobs-university.de*/
#include <iostream>
#include <cstdlib>
#include<string>
#include "stack.h"
using namespace std;
int main()
{

	stack <int> ages(2);
stack <int>	ages_copy(ages);
	ages.push(2);
	ages.push(1);
//	ages.pop();
	ages.back();
		ages.getNumEntries();
	ages_copy.back();
	ages_copy.push(3);
	ages_copy.push(9);
	ages_copy.push(6);
	ages_copy.pop();
	ages_copy.back();
	ages_copy .getNumEntries();
	return 0;
	
}
