/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <fstream>
using namespace std::chrono;
using namespace std;

void merge(int A[],int B[],int m,int n)
{
	int i=0;
	int j=0;
	
	int k=0;
	int c[m+n];
	while(i<m &&j<n)
	{
		if(A[i]<B[j])
		{
			c[k]=A[i];
			i++;
			k++;
		}
		else
		{
		c[k]=B[j];
			j++;
			k++;	
		}
	}
	for(;i<m;i++)
	{
		c[k]=A[i];
		k++;
	}
	for(;j<n;j++)
	{
		c[k]=B[j];
		k++;
	}
/*	for(int z=0;z<k;z++)
	{
		cout<<c[z]<<" ";
	}*/
	
}
void insertionSort(int A[],int z)
{
	for(int i=2;i<=z;i++)
	{
		int key=A[i];
		int j =i-1;
		while(j>0 && A[j]>key)
		{
			A[j+1]=A[j];
			j=j-1;
			A[j+1]=key;
		}
		
	}
	/*for(int m=1;m<=z;m++)
	{
		cout<<A[m]<<" ";
	}*/
}
void mergeSort(int A[], int B[], int a, int c, int k)
{
    if (a < c)
    {
        if ((c - a) <= k)
            insertionSort(A, a);
        else
        {
            int b = (a + c) / 2;
            mergeSort(A, B, a, b, c);
            mergeSort(A,B, b + 1, c, k);
            merge(A, B, b, c);
        }
    }
}
int main()
{
	 int k;
    cout<<"enter the integer"<<endl;
    cin>>k;
    int A[]={1,1,2,4,7,1,6,12,10};           //Average case  ....The best case is when they are already sorted
    int size=sizeof(A)/sizeof(A[0]);				//			worst case when they are in reverse order
    int * t1 = new int[size];
    auto start = std::chrono::steady_clock::now();
    mergeSort(A, t1, 0, size-1, k);
    auto finish = steady_clock::now();    
    double elapsed_seconds = duration_cast<nanoseconds>(finish - start).count();
    cout << elapsed_seconds << endl;
    delete[] t1;
    for (int i=0;i<size;i++)
        cout<<A[i]<<" ";
 
    ofstream O;
    O.open("avg.dat");
    for (int i=0;i<size;i++)
        O<<A[i]<<" ";
    O.close();
	return 0;
}
