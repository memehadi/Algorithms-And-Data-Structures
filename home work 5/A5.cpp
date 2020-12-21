/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <fstream>
#include <time.h>
#include <algorithm>
using namespace std::chrono;
using namespace std;
int F1 (int n)
{
	if (n<2)
		return n;
	else
		return F1(n-1)+F1(n-2);
}
int F2 (int n)
{
	//int result;
	int A[100];
	A[0]=0;
	A[1]=1;
	if(n<2)
		return n;
	else	
	{
		for (int i=2;i<=n;i++)
		{
			A[i] =A[i-1]+A[i-2];
		}
	}
	return A[n];
	
	
	/*if (n<2)
		return n;
	else
		return (A[n-1]+A[n-2]);*/	
	
}
int F3 (int n)
{
	double result  =pow(((1+sqrt(5))/2.0),n)/sqrt(5);
	cout<<result<<endl;
	return round(result);	
}
int  F4 (int n)
{
int A[2][2];
A[0][0]=0;
A[0][1]=1;
A[1][0]=1; 
A[1][1]=1;
int temp[2][1];
temp[0][0]=0;
temp[1][0]=1;
/*if (n<2)
	return n;*/
int temp1;
int temp2;
for(int i=1;i<=n;i++)
{
temp1= temp[0][0];
temp2 = temp[1][0];
temp[0][0]=(A[0][0]*temp1)+(A[0][1]*temp2);
temp[1][0]=(A[1][0]*temp1)+(A[1][1]*temp2);
}
//cout<<temp[0][0]<<endl;
//cout<<temp[0][1]<<endl;
 int x=temp[0][0];
 return x;
//
//for(int i=0;i<2;i++ )
//{
//	for(int j=0;j<2;j++)
//	{
//		cout<< A[i][j];
//	}
//	cout<<endl;
//}
}

int main ()
{
 	time_t constant=10;
	ofstream O1;
	ofstream O2;
	ofstream O3;
	ofstream O4;
    O1.open("out1.txt");
    O2.open("out2.txt");
    O3.open("out3.txt");
    O4.open("out4.txt");
    int n=0;
	while(1)
	{
		auto start1 = steady_clock::now();
		F1(n);
    	auto finish1 = steady_clock::now();
    	double elapsed_seconds1 = duration_cast<nanoseconds>(finish1 - start1).count();
    	O1<<n<<" "<<elapsed_seconds1<<endl;
		//cout<<n<<" "<<elapsed_seconds1<<endl;
    	n++;
     	if (elapsed_seconds1 >= 500000) 
			break;
	}
	n=0;
	while (1)
	{
		auto start2 = steady_clock::now();
		F2(n);
    	auto finish2 = steady_clock::now();
    	double elapsed_seconds2 = duration_cast<nanoseconds>(finish2 - start2).count();
   
    	O2<<n<<" "<<elapsed_seconds2<<endl;
		//cout<<n<<" "<<elapsed_seconds2<<endl;
    	n++;
     	if (elapsed_seconds2 >= 500000) 
			break;
	}
	n=0;
	while(1)
	{
		auto start3 = steady_clock::now();
		F3(n);
		auto finish3 = steady_clock::now();
		double elapsed_seconds3 = duration_cast<nanoseconds>(finish3 - start3).count();
		O3<<n<<" "<<elapsed_seconds3<<endl;
		cout<<n<<" "<<elapsed_seconds3<<endl;
		n++;
		if (elapsed_seconds3 >= 500000) 
			break;
	}
	
	
	n=0;
	while(1)
	{
		auto start4 = steady_clock::now();
		F4(n);
   		auto finish4 = steady_clock::now();
    	double elapsed_seconds4 = duration_cast<nanoseconds>(finish4 - start4).count();
		O4<<n<<" "<<elapsed_seconds4<<endl;
		cout<<n<<" "<<elapsed_seconds4<<endl;
		n++;
		 
		if (elapsed_seconds4 >= 500000) 
			break;
		 
	}
	//O<<n<<" "<<elapsed_seconds1<<" "<<elapsed_seconds2<<" "<<elapsed_seconds3<<" "<<elapsed_seconds4<<endl;
	/*cout<<F1(n)<<"(using naive recurssion)"<<endl;
	cout<<F2(n)<<"(using bottom top)"<<endl;
	cout<<F3(n)<<"(using clopsed form)"<<endl;
	cout<<F4(n)<<"(using matrix)"<<endl;*/
	
	O1.close();
	O2.close();
	O3.close();
	O4.close();
	return 0;
}
