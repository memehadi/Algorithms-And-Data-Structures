/* Musab Mehadi  
mmehadi@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int size ;
int length;
 void MaxHeapify(int A[],int i)
 {
 	int largest;
 	int left =(2*i)+1;
 	int right=(2*i)+2;
 	if(left<size&&A[left]>A[i])
		largest=left;
 	else
		largest=i;
 	if(right<size &&A[right]>A[largest])
		largest=right;
		
	if(largest!=i)
	{ 	
		swap(A[i],A[largest]);
		MaxHeapify(A,largest);
	}
 }
 void BuildMaxHeap(int A[])
 {
 	int x=(size/2)-1;  //even if size is odd,the output is still approximated to the lower integer 
 	for (int i=x;i>=0;i--)     //which is what we want.
 	{
		MaxHeapify(A,i);
	}
 }
 void HeapSort(int A[])
 {
 	BuildMaxHeap(A);
 	int x=size;
 	for(int i=x-1;i>=1;i--)
	{
		swap(A[0],A[i]);
		size=size-1;
		MaxHeapify(A,0);
	}

 }
 void HeapSort2(int A[])
 {
 	BuildMaxHeap(A);
	size=4;
 	int x=size;
 	for(int i=x-1;i>=1;i--)
	{
		swap(A[0],A[i]);
		size=size-1;
		int counter=0;
		while (counter<(size-2))
		{
			swap(A[counter],A[counter+1]);
			counter++;
		}
		//size=size-1;
	}
}
 
 int main()
 {
 	int A[]={3,4,5,2};
 	length = 4;
 	size = 4;
	HeapSort(A);    //O(nlogn)
	cout<<"The result of the normal HeapSort is" <<endl;
 	for(int j=0;j<4;j++)
 	{
 		cout<<A[j]<<endl;
	}
	HeapSort2(A);   //O(n)
	cout<<"The result of  HeapSort2 function is" <<endl;
 	for(int j=3;j>=0;j--)
 	{
 		cout<<A[j]<<endl;
	}
	 return 0;
 }
