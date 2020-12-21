/*Musab Mehadi
mmehadi@jacobs-university.de*/ 
#include <iostream>
#include<deque>
#include<string>
using namespace std;
class WindGuage{
	public: 
	void dump();	
	 WindGauge(int period = 12); 
	void currentWindSpeed(int speed); 
	int highest() const; 
	int lowest() const; 
	int average() const; 
	private:
		deque<int> d;
		
}; 
