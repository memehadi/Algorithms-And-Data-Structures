/*Musab Mehadi 
mmehadi@jacobs-university.de*/
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
struct node
{
	node* left;
	node* right;
	int data;
};
void insert(node* A,int n)
{
 node*P=new struct node;
 P->right=A;
 A->left=P;
 P->left=NULL;
 P->data=n;
 cout<<"NJKM";
}
void in_order(struct node* P,struct node* head)
{
	if(P==NULL)
		return;
	static node* temp=NULL;
	in_order(P->left,head);
	
	if(temp==NULL)
		head=P;
	else
	{
		P->left=temp;
		temp->right=P;
	}
	temp=P;
	in_order(P->right,head);
cout<<"muaaa";
}
int main()
{
	node*head=NULL;
	node*P=new struct node ;
	P->left=NULL;
	P->data=5;
 	P->right=NULL;
	insert(P,3);
	insert(P,7);
	insert(P,2);
	insert(P,4);
	insert(P,6);
	insert(P,8);
	 	
	//cout <<P->left;
	/*int size = 7;
	list<int> A;
	A.push_front(9);
	A.push_front(6);
 	A.push_front(4);
	A.push_front(2);
	A.push_front(8);
	A.push_front(3);
	A.push_front(5);*/
/*	for(int i=0;i<size;i++)
	{
		cout<<A.front()<<" ";
		A.pop_front();
	}*/

	in_order(P,head);
	node*t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->right;
	}	
	return 0;
}
