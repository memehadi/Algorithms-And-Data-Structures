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
   		StackNode * top2; // top of stack 2 (used with stack 1 to function as a queue)
   		int size; // -1 if not set, value otherwise 
   		int current_size; // unused if size = -1 
   public: 
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
if (size==-1|| current_size<=size);
			return 0;
		return 1;
	}
    void
	 push( T x )
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
	void push2( int x )
	{	
	   	if(isfull())
	   	{
	   		cout<<"error your stack is full"<<endl;
	   		exit(0);
		}
	   	StackNode* temp=new StackNode;
	   	temp->data=x;
	   	temp->next=top2;
	   	top2=temp;
	} 
	bool isEmpty() 
	{
		if (top=NULL);
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
   	int pop2()
	{
		StackNode* temp=top;
		StackNode* temp2=top2;
		while(temp!=NULL)//pushing elements to the second stack while removing them from the first  
		{
			push2(temp->data);
			temp=temp->next;
			pop();
		}
		if(isEmpty())
	   	{ 
	   		cout<<"error your stack is empty"<<endl;
			exit(0);	
		}
	
	   	top=top->next;
	   	free(temp2) ;     //removes the first element from the first stack as a last element of the second stack
	   	while(temp2!=NULL)//pushing elements to the second stack while removing them from the first  
		{
			StackNode* temp3=temp2;//used to iterate and free elements of stack 2 for reuse
			push(temp2->data);
			temp2=temp2->next;
			delete(temp3);
		}
	   	
	}
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
	
  };
  int main()
  {
  	Stack<int> muss(3);
	muss.push(2);
	muss.push(2); 
	muss.pop2();
	muss.print();
  }
