#include<stdio.h>
#include<string>
#include<cstdlib>
using namespace std;
template <class T>
 class stack
 {
 	private:
 		int top=-1;
 		int num_of_elements;
 		T value[];
 	public:
 		stack()
 		{
 			num_of_elements=10;
		 }
		 stack(int size)
		 {
		 	num_of_elements=size;
		 }
		 stack(const stack&copy)
		 {
		 	top=copy.top;	
		 	num_of_elements=copy.num_of_elements;
		 //	value = new T[top];
			 for(int i=0;i<top;i++)
		 		{
			 value[i]=copy.value[i];
				}
		 }
		 ~stack()
		 {
		 cout<<"destructor succesfully  used"<<endl;	
		 }
 		bool pop()
 		{
		 	if (top!=-1)
		 	{
		 		cout<<"one element removed"<<endl;
			 	top=top-1;
 				return true;
 			}
 			else
 			{
 				cout<<"the stack is empty"<<endl;
			 return false;
			} 				
		 }
 		
 		bool push(T element)
 			{
 				top++;
				if(	top<num_of_elements)
					{
						value [top]=element;
						cout<<"element added"<<endl;
							return true;
					}
				
				else
				{
				cout<<"the stack is full"<<endl;
				top--;
					return false;
				}
			}
 		T back()
 		{
 			cout<<"the value on top is "<<value[top]<<endl;
		 }
 		int getNumEntries()
 			{
 				cout<<"the number of entries is "<<top+1<<endl;
			 }
 		
 };
