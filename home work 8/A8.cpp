/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class Stack{
	private:
  		struct StackNode
		{ // linked list 
 			T data; 
  			StackNode * next; 
  		};
   		StackNode * top; // top of stack 1
		int size; // -1 if not set, value otherwise 
   		int current_size; // unused if size = -1 
   public:
   Stack(int new_size)
	{
		current_size=0;
		size=new_size;
		top=NULL; 
	}
	Stack()
	{
		current_size=0;
		top=NULL;
		size=-1;
	} 
   void print()
   {
		StackNode* temp=new StackNode;
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
   	}
	bool isfull()
	{	
	
		if (size==-1|| current_size<size)
		{
			return 0;
		}
		
		return 1;
		
	}
    void push( T x )
	{	
	   	if(isfull())
	   	{
	   		cout<<"error your stack is full"<<endl;
	   		exit(0);
		}
	   	StackNode* temp=new StackNode;
	   	temp->data=x;
	   	temp->next=top;
	   	top=temp;
	   	current_size++;
	}// if size set, check for overflow
	
	bool isEmpty() 
	{
		if (top=NULL)
		 	return 1;
		return 0;   
	} // true if empty, false otherwise   	
	void pop()
	{
		if(isEmpty())
	   	{
	   		cout<<"error your stack is empty"<<endl;
			exit(0);	
		}
		StackNode* temp=top;
	   	top=top->next;
	   	delete(temp) ;
	}
	     // return element if not in underflow
};
  int main()
  {
  	Stack<int> muss(3);
	muss.push(2); 
	muss.push(4);
	muss.print();
	muss.push(4);
	muss.push(4); 
	muss.print();
  	
  }
