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
           cout<<"TEATAAT";
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
		/*Node* y=x->left;
		x->left=y->right;
		if(y->right!=NULL)
			y->right->parent=x;
		y->parent=x->parent;
		if(x->parent==NULL)
			root=y;
		else if(x==x->parent->right)
			x->parent->right=y;
		else
			x->parent->left=y;
		y->right=x;
		x->parent=y;
		cout<<"DFDDED";*/
	 	
	} 
public: 
	RedBlackTree()
	{
	/*	root=new Node();
		root->parent=NULL;
		root->right=NULL;
		root->left=NULL;
		root->data=0;*/root=NULL;
		 
	}
 	void insert(int n)
	{ 
 		Node* add=new Node();
 		/*Node* x=new Node();
 		Node* y=new Node();*/
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
				/*y->color=x->color;
				y->left=x->left;
				y->right=x->right;
				y->data=x->data;
				y->parent=x->parent;*/
				y=x;  
				if(add->data<(x->data))
					x=x->left;
				else
					x=x->right;
			}
			add->parent=y;
			cout<<"yes";
		
			if(add->data<y->data)
			{
				cout<<"trye2"<<endl;
				y->left=add;
			}
			else
			{
				y->right=add;
				cout<<"trye3"<<endl;
			}
		}
		insertFix(add);
	}
	/*	z->left=NULL;		
		z->right=NULL;
		col=RED;
		z->color=col;*/
		//cout<<"yes";  
			//INSERT FIX-UP
		//Node* temp=z;//
	void insertFix(Node *&h)
	{
		Node*u;
		if(root==h)
    	{
        	 h->color=BLACK;
         	return;
    	}
    	 while(h->parent!=NULL && h->parent->color==RED)
     	{
           Node *w=h->parent->parent;
           if(w->left==h->parent)
           {
                        if(w->right!=NULL)
                        {
                              u=w->right;
                              if(u->color==RED)
                              {
                                   h->parent->color=BLACK;
                                   u->color=BLACK;
                                   w->color=BLACK;
                                   h=w;
                              }
                        }
                        else
                        {
                            if(h->parent->right==h)
                            {
                                 h=h->parent;
                                 rotateLeft(h);
                            }
                            h->parent->color=BLACK;
                            w->color=RED;
                            rotateRight(w);
                        }
           }
           else
           {
                        if(w->left!=NULL)
                        {
                             u=w->left;
                             if(u->color==RED)
                             {
                                  h->parent->color=BLACK;
                                  u->color=BLACK;
                                  w->color=RED;
                                  h=w;
                             }
                        }
                        else
                        {
                            if(h->parent->left==h)
                            {
                
                                   h=h->parent;
                                   rotateRight(h);
                            }
                            h->parent->color=BLACK;
                            w->color=RED;
                            rotateLeft(w);
                        }
           }
       
           	root->color=BLACK;
			cout<<"successfully inserted"<<endl;
		}
	}

																		

    	/*col=RED; 
		while ( add->parent!=NULL  && add->parent->color=col )
			{
			if(z->parent==z->parent->parent->left)
			{
				w=z->parent->parent->right;
				if(w->color==col)
				{
					col=BLACK;
					z->parent->color=col;
					w->color=col;
					col=RED;
					z->parent->parent->color=col;
					z=z->parent->parent;//
				}
			
				else
				{
					if(z=z->parent->right)
					{
						z=z->parent;///
						rotateLeft(z);///
					}
					col=BLACK;
				 	z->parent->color=col;
				 	col=RED;
					z->parent->parent->color=col;///
					rotateRight(z);///
					
				}
			}
			else
			{
				w=z->parent->parent->left;
				col=RED;
				if(w->color==col)
				{
					col=BLACK;
					z->parent->color=col;
					w->color=col;///////////////////////////////////////////
					col=RED;
					z->parent->parent->color=col;
					z=z->parent->parent;//
				}
				else
				{
					if(z=z->parent->left)
					{
						z=z->parent;///
						rotateRight(z);///
					}
					col=BLACK;
					z->parent->color=col;
					col=RED;
					z->parent->parent->color=col;///
					rotateLeft(z);///
				}
			}
		
		}*/
	

	
/*	
 	void delete(Node *&z)//
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
 	Node * predecessor(const Node *&x)
 	{
		if(x->left!=NULL)
			return getMaximum(x->left);
		Node* y=x->parent;
		while(y!=NULL &&x==y->left)
		{
			x=y;
			y=y->parent;
		}
		return y; 
	}
	
	Node * successor(const Node *&x )//
	{
		//Node* x=root;////
		if(x->right!=NULL)
			return getMinimum(x->right);
		Node* y=x->parent;
		while(y!=NULL &&x==y->right)
		{
			x=y;
			y=y->parent;
		}
		return y;
	}
	
	Node * getMinimum();//
	{
		Node*x=root;//////
		while(x->left!=NULL)
			x=x->left;
		return x;
	}
	
	Node * getMaximum()//
	{
		Node*x=root;//////
		while(x->right!=NULL)
			x=x->right;
		return x;
	}
	
	Node * search(int n)
	{
		//root=NULL;/////////////////////////////////
		Node*x=root;//
		while(x!=0 && x->data!=n)
		{
			if(x->data>n)
				x=x->left;
			else
				x=x->right;
			cout<<"searched";
			return x;
		}
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
	M.
	return 0;
}
