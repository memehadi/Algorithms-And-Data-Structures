/*Musab Mehadi
mmehadi@jacobs-university.de*/
#include<iostream>
#include<stdlib.h>
using namespace std;
enum Color {RED, BLACK}; 
struct Node 
{ 
	int data;
 	Color color; 
	Node *left, *right, *parent; 
}; 
class RedBlackTree 
{ 
private:
	Node *root;
protected:
	void rotateLeft(Node *&x)
	{
		/*Node* y=x->right;
		x->right=y->left;
		if(y->left!=NULL)
			y->left->parent=x;
		y->parent=x->parent;
		if(x->parent==NULL)
			root=y;
		else if(x==x->parent->left)
			x->parent->left=y;
		else
			x->parent->right=y;
		y->left=x;
		x->parent=y;
		cout<<"DFDDED";*/
		if(x->right==NULL)
           return ;
     else
     {
           Node *y=x->right;
           if(y->left!=NULL)
           {
                  x->right=y->left;
                  y->left->parent=x;
           }
           else
                  x->right=NULL;
           if(x->parent!=NULL)
                y->parent=x->parent;
           if(x->parent==NULL)
                root=y;
           else
           {
               if(x==x->parent->left)
                       x->parent->left=y;
               else
                       x->parent->right=y;
           }
           y->left=x;
           x->parent=y;
         //  cout<<"TEATAAT";
     }
	}
 	void rotateRight(Node *&x)
	{
     if(x->left==NULL)
          return ;
     else
     {
         Node *y=x->left;
         if(y->right!=NULL)
         {
                  x->left=y->right;
                  y->right->parent=x;
         }
         else
                 x->left=NULL;
         if(x->parent!=NULL)
                 y->parent=x->parent;
         if(x->parent==NULL)
               root=y;
         else
         {
             if(x==x->parent->left)
                   x->parent->left=y;
             else
                   x->parent->right=y;
         }
         y->right=x;
         x->parent=y;
         cout<<"WHF";
 }
		
} 
public: 
	RedBlackTree()
	{
	root=NULL;
	}
 	void insert(int n)
	{ 
 		Node* add=new Node();
 		add->data =n;
 		add->left=NULL;
     	add->right=NULL;
     	add->color=RED;
 		Node*	y=NULL;
		Node*	x=root;
		if(root==NULL)
     	{
           root=add;
           add->parent=NULL;
     	}
     	else
     	{
		 	while(x!=NULL) 
			{
				y=x;  
				if(add->data<(x->data))
					x=x->left;
				else
					x=x->right;
			}
			add->parent=y;
		
			if(add->data<y->data)
			{
				y->left=add;
			}
			else
			{
				y->right=add;
			}
		}
		insertFix(add);
	}

	void insertFix(Node *&h)
	{
		Node*u;
		if(root==h)
    	{
        	 h->color=BLACK;
         	return;
    	}
    while (h->parent!=NULL && h->parent->color == RED)
	{
		if (h->parent == h->parent->parent->left)
		{
			Node* y=h->parent->parent->right;
			if(y!=NULL)
            {
                if(y->color==RED)
                {
                    h->parent->color=BLACK;
                    y->color=BLACK;
                    h->parent->parent->color=BLACK;
                    h=h->parent->parent;
                }
            }
			else
			{
				if(h == h->parent->right)
				{
					h=h->parent;
					rotateLeft(h);
				}
				h->parent->color = BLACK;
				h->parent->parent->color = RED;
				rotateRight(h->parent->parent);
			}	
		}
		else
		{
			Node* y=h->parent->parent->left;
			if(y!=NULL)
            {
                if(y->color==RED)
                {
                    h->parent->color=BLACK;
                    y->color=BLACK;
                    h->parent->parent->color=BLACK;
                    h=h->parent->parent;
                }
            }
			else
			{
				if(h == h->parent->left)
				{
					h=h->parent;
					rotateRight(h);
				}
				h->parent->color = BLACK;
				h->parent->parent->color = RED;
				rotateLeft(h->parent->parent);
			}	
		}
		root->color=BLACK;
	}
}
    
/*void delete(Node *&z)//
{
 		Node* x=NULL;
 		Node* y=z;
		Color orignal=y->color;//
		if(z->left==NULL)
		{
			x=z->right;
			RB-TRANSPLANT(, z,z->right);////////
		}	 
		else if(z->right==NULL)
		{
			x=z->left;
			RB-TRANSPLANT( ,z,z->left);//////////////
		}
		else 
		{
			y=getMinimum(z->right);
			orignal=y->color; 
			x=y->right;
			if(y->parent==z)
				x->parent=y;
			else
			{
					RB-TRANSPLANT( ,y,y->right);////////	
					y->right=z->right;
					y->right->parent=y;
			}	
			RB-TRANSPLANT( ,z,y);
			y->left=z->left;
			y->left->parent=y;
			y->color=z->color;
			if(original==1)//////
			//DELETE FIX_UP
			DELETE-FIXUP( ,Node* x)/////
			{
				while(x!=root && x->color==1)///
				Node* w=NULL;
				{
					if(x==x->parent->left)
					{
						w=x->parent->right;
						if(w->color==0)
						{
							w->color==1;
							x->parent->color=0;
							rotateLeft(  );////
							w=x->parent->right;
						}
						if(w->left->color==1 &&w->right->color==1)
						{
							w->color=0;
							x=x->parent;
						}
						else
						{
							if(w->right->color==1)
							{
								w->left->color=1;
								w->color=0;
								rotateRight(  );/////
								w=x->parent->right;
							}
							w->color=x->parent->color;
							x->parent->color=1;
							w->right->color=1;
							rotateLeft( );////
							x=root;///////
						}
					}
					else
					{
						w=x->parent->left;
						if(w->color==0)
						{
							w->color==1;
							x->parent->color=0;
							rotateRight(  );////
							w=x->parent->left;
						}
						if(w->right->color==1 &&w->left->color==1)
						{
							w->color=0;
							x=x->parent;
						}
						else
						{
							if(w->left->color==1)
							{
								w->right->color=1;
								w->color=0;
								rotateLeft(  );/////
								w=x->parent->left;
							}
							w->color=x->parent->color;
							x->parent->color=1;
							w->left->color=1;
							rotateRight( );////
							x=root;///////
						}	
					}
					x->color=1;
				}			
			}
		}
	}*/
 	Node * predecessor(const Node *x)
 	{
		if(x->left!=NULL)
			return Getmaximum(x->left);
		Node* y=x->parent;
		while(y!=NULL &&x==y->left)
		{
			x=y;
			y=y->parent;
		}
		return y; 
	}

	Node * successor(const Node *x )
	{
		if(x->right!=NULL)
			return Getminimum(x->right);
		Node* y=x->parent;
		while(y!=NULL &&x==y->right)
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
	Node* getminimum()
	{
		return Getminimum(root);
	}
	Node* Getminimum(Node* x)
	{
		while (x->left != NULL)
			x=x->left;
		return x;
	}
	
	Node* getmaximum()
	{
		return Getmaximum(root);
	}
	
	Node * Getmaximum(Node* x)//
	{
		while(x->right!=NULL)
			x=x->right;
		return x;
	}
	
	Node * Search(Node *x,int n)
	{
		while(x!=NULL && x->data!=n)
		{
			if(x->data>n)
				x=x->left;
			else
				x=x->right;
			return x;
		}
	}
	Node* search(int x)
	{
		return Search(root,x);
	}
};

int main()
{
	RedBlackTree M;
	M.insert(5);
	M.insert(2);
	M.insert(8);
	M.insert(4);
	M.insert(7);
	M.insert(1);
	const Node* m=M.search(2);
	cout<<m->data<<endl;
	cout<<"The minimum element in the tree is "<<M.getminimum()->data<<endl;
	cout<<"The maximum element in the tree is "<<M.getmaximum()->data<<endl;
	cout<<"the predecessor of 2 is"<<M. predecessor(m)->data<<endl;
	cout<<"the succecessor of 2 is"<< M.successor(m)->data<<endl;
	return 0;
 }
