/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <math.h>
#include <iostream>
using namespace std;
/*void Merge(int A[],int a,int b,int c)
{
	int i,j;
	int n=b-a+1;
	int m=c-b;
	int A1[n+1];
	int A2[m+1];
	for(i=1;i<=n;i++)
		{
			A1[i]=A[a+i-1];
		}
	for(j=1;j<=m;j++)
		{
			A2[j]=A[b+j];
		}
	A1[n+1]=88786687;
	A2[m+1]=7897568;
	i=0;
	j=0;
	for(int k=a;k<=c;k++)
		{
			if(A1[i]<A2[j])
			{
				A[k]=A1[i];
				i++;
			}
			else
			{
				A[k]=A2[j];
				j++;
			}
					
		}
	for(int z=a;z<=c;z++)
	{
		cout<<A[z]<<" ";
	}	
}*/
void merge(int A[],int b,int m,int n)
{
	int i=0;
	int j=0;
	int k=0;
	int c[m+n];
	while(i<m &&j<n)
	{
		if(A[i]<A[i+1])
		{
			c[k]=A[i];
			i++;
			k++;
		}
		else
		{
		c[k]=A[j];
			j++;
			k++;	
		}
	}
	for(int z=0;z<k;z++)
	{
		cout<<c[z]<<" ";
	}
	
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
	for(int m=1;m<=z;m++)
	{
		cout<<A[m]<<" ";
	}
}
/*mergeSort(int A[],int a,int c,int k)

{
	int z = 0;
	if(z==k)
		insertionSort(A, z);
	if(a<c)
	{
		int b=(a+c)/2;
		mergeSort(A,a,b,k);
		mergeSort(A,b+1,c,k);
		merge(A,a,b,c);	
	}
	
}*/


int main()
{
	int V[]={4,8,2,9,6,3};

	/*int A[]={2,3,6};
	int B[]={5,7,9};
	merge(A,B,3,3);*/
	merge(V,0,2,5);
	/*insertionSort(A,6);
	int k=2;
	mergeSort(V,1,6,k);*/
	return 0;
}
