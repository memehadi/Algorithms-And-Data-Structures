#include <iostream>
using namespace std;
void sort(int A[],int n)
{
	for (int j=0;j<n;j++)
	{
		//int min=A[j];
		int i=j+1;
		while(i<n)
		{
			if(A[i]<A[j])
			{
				int x=A[j];
				A[j]=A[i];
				A[i]=x;
				break;
			}
			i++;
		}		
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for (int d=0;d<n;d++)
	{
		cin>>arr[d];
	}
	sort(arr,n);
		for (int d=0;d<n;d++)
	{
		cout<<arr[d]<<" ";
	}
}
