/*Musab Mehadi
mmehadi@jacobs-university.de*/ 
#include <iostream>
#include<deque>
#include<string>
#include"WindGuage.h"
using namespace std;
 void WindGuage::currentWindSpeed(int speed)
 {
 	d.push_back(speed);
 	if (d.size()>12)
 	{
	 	d.pop_front();
 		cout<<"one element popped "<<endl;
 	}	
 }
 int WindGuage::highest() const
 {
 	
 	int max=d[0];
 	for(int i=0;i<d.size();i++)
 	{
 		if (d[i]>max)
 		max=d[i];
	 }
 	return max;
 }
  int WindGuage::lowest() const
 {
 	
 	 int min=d[0];
 	for(int i=0;i<d.size();i++)
 	{
 		if (d[i]<min)
 		min=d[i];
	 }
 	return min;
 }
  int WindGuage::average() const
 {
 	 int sum=0;
 	 for(int i=0;i<d.size();i++)
 	 	{
			sum=sum+d[i];	 	 	
	 	}
 	int avg=sum/d.size();
 	return avg;
 }
 void WindGuage::dump()
 {
 		cout<<"the maximum value is "<<highest()<<endl;
		cout<<"the minimum value is "<<lowest()<<endl;
		cout<<"the average value is (rounded to the lowest intiger) "<<average()<<endl;
 }
