/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include<iostream>
#include<vector>
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
 void CountingSort(int A[],int n)
 {
 	int k=getmax(A,n);
 	int*B=new int[n];
 	int*C=new int[k];
 	/*int B[7];
 	int C[9];*/
 	for (int i=0;i<k;i++)
 	{
 		C[i]=0;
		 //cout <<"MM"<<endl;	
	}
	for(int j=0;j<n;j++) 
	{
		C[A[j]]=C[A[j]]+1;
		 //cout <<"nn"<<endl;	
	}
	for(int j=1;j<k;j++)
	{
		C[j]=	C[j]+C[j-1]; 
		//cout <<"oo"<<endl;	
		
	}
	for(int j=n-1;j>=0;j--)
	{
		B[C[A[j]]]=	A[j];
		C[A[j]]=C[A[j]]-1;
		 //cout <<"pp"<<endl;	
	}
	for(int j=0;j<n;j++)
	{
		A[j]=B[j];
		 //cout <<"qq"<<endl;	
	}
	

 }
 
void BucketSort(float A[],int n)
  {
		vector<float> Bucket[n];
		for (int i=0;i<n;i++) 
		{
			int element =n*A[i];
			Bucket[element].push_back(A[i]);
		}
		for (int i=0;i<n;i++) 
		{
			sort(Bucket[i].begin(),Bucket[i].end());		
		}
		int k=0;
		for (int i=0;i<n;i++) 
		{
			for (int j=0;j<Bucket[i].size();j++) 	
			{
				A[k++]=Bucket[i][j];
			}		
		}
	} 
int main() 
{
float C[]={0.9,0.1,0.6,0.7,0.6,0.3,0.1};
int A[]={9,1,6,7,6,2,1};
int n=sizeof(A)/sizeof(A[0]);
int m=sizeof(C)/sizeof(C[0]);
CountingSort(A,n);
BucketSort(C,m);
for(int j=0;j<n;j++)
{
	cout<<A[j]<<" ";
}
cout<<endl;
for(int j=0;j<m;j++)
{
	cout<<C[j]<<" ";
}
return 0;
}
