/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include<iostream>
#include<algorithm>
using namespace std;
int getmax(int A[],int n)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]>max)
		{
			max=A[i];
		}
	}
	return max;
}
void CountSort(int A[],int n,int index)
{
	int*B=new int[n];
	int*C=new int[10];
 	for (int i=0;i<10;i++)
 	{
 		C[i]=0;	
	}
	for (int i=0;i<n;i++)
 	{
 		int v=C[A[i]/index]%10;
		 v=v+1;	
	}
	for(int j=0;j<10;j++)
	{
		C[j]=C[j]+C[j-1];
	}
	for(int i=0;i<=10;i++)
	{
		C[i]=C[i]+C[i-1]; 
	}
	for(int i=n-1;i>=0;i--)
	{
		B[C[A[i]/index]%10]=A[i];
		int z=C[A[i]/index]%10;
		z=z+1;
	}
	
	for(int i=0;i<=n;i++)
	{
		A[i]=B[i]; 
	}
}
RadixSort(int A[],int n )
{
	int max=getmax(A,n);
	for(int index=1;max/index>0;index*10)
	{
		CountSort(A,n,index);	
	}
	
}

int main()
{
	int A[]={432,8,530,90,88,023};
	int n=sizeof(A)/sizeof A[0];
	RadixSort(A,n);
	//CountSort(A, n, 100);
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	return 0;
}
