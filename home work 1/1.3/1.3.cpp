/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include<iostream>
#include<cstdlib>
using namespace std;
template<class T>
class list
{
	private:
		struct node{
			struct node* next;
		 	T value;	
		};
	public:
			struct node* A=NULL;
		void add(T element)
		{
			struct node*temp=new node;
			if(A=NULL)
				{
					A=temp;
					temp->value=element;
					temp->next=NULL;
				}
			else
			{
				struct node*temp3=new node;
				struct node*temp2=A;
				while(temp2->next!=NULL)
					{
						temp2=temp2->next;
					}
					temp2->next=temp3;
					temp3->value=element;
					temp3->next=NULL;
					
					
			}
				
	
			
			
		}
		void print()
		{
			struct node*traverse=A;
			while(traverse!=NULL)
			{
				cout<<traverse->value<<endl;
				traverse=traverse->next;
			}
		}
};





int main()
{
	list <int>grades;
	grades.add(30);
	grades.print();
}
