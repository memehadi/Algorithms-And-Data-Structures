/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <ctime>
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
void selectsort(int A[],int n)
{
	//int count=0;
	for (int j=0;j<n-2;j++)
	{
		
		int imin,i;
		imin=j;
		for(i=j+1;i<n-1;i++)
		{
			if(A[i]<A[imin])
			{
				imin=i;	
			}
		}
		int temp=A[imin];
		A[imin]=A[i];
		A[i]=temp;
	 	//n++;
	}
	//cout << count << endl;
}
int main()
{	
	int n;
	cout<<"enter the number of entries and the elements themselves"<<endl;
	cin>>n;
 	int arr[n];
int A[n];
int B[n];

	
	for (int d=0;d<n;d++) //average case
	{
		cin>>arr[d];
	}
	selectsort(arr,n);//calling the function
		for (int d=0;d<n;d++)
	{
		cout<<arr[d]<<" ";
	}
	
	srand(time(NULL));
	for (int m=0;m<n;m++)//worst case
	{
				if(m==0)
		 	A[m]=200;
		
		if(m==1)
		 	A[m]=(rand()%100);
		else
		{
			A[m]=(rand() % A[m-1] );
		}
	}
		selectsort(A,n);//calling the function
	for (int d=0;d<n;d++)
	{
		cout<<A[d]<<" ";
	}
	cout<<endl;
	for (int  m=0;m<n;m++)//best case
	{	
		if(m==0)
		{
	 		B[m]=(rand()%10);
		}
		here:
		int r=rand();
		if (r<B[m])
		goto here;
		else
		B[m+1]=r;
	}
		selectsort(B,n);//calling the function
	for (int d=0;d<n;d++)
	{
		cout<<B[d]<<" ";
	}
	int a[10] = {10,9,8,7,6,5,1,2,3,4};
	selectsort(a,10);
		for (int d=0;d<10;d++)
	{
		cout<<a[d]<<" ";
	}
	return 0;
}
