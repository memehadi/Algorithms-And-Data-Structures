#include<iostream>
using namespace std;
enum Color {RED, BLACK};
struct Node
{
       int key;
       Node *parent;
       Color color;
       Node *left;
       Node *right;
};
class RedBlackTree
{
	private:
      Node *root;
      Node *q;
    protected:
    	void leftrotate(Node *&);
    	void rightrotate(Node *&);
    public :
      RedBlackTree()
      {
              q=NULL;
              root=NULL;
      }
      void insert(int);
      void insertfix(Node *&);
      Node* search (int);
      Node* search2 (Node* , int);
      Node* successor(const Node *);
      Node* predecessor(const Node *);
      Node* getminimum();
      Node* getminimum2(Node *);
      Node* getmaximum();
      Node* getmaximum2(Node *);
      void disp();
      void display(Node *&);
};

void RedBlackTree::insert(int w)
{
	Node* y= NULL;
	Node* x= root;
	Node* z= new Node;
	z->key= w;
	z->left= NULL;
	z->right= NULL;
	z->color= RED;
	while (x!=NULL)
	{
		y=x;
		if (z->key<x->key)
			x= x->left;
		else
			x= x->right;
	}
	z->parent=y;
	if (y== NULL)
		root=z;
	else if (z->key < y->key)
		y->left=z;
	else
		y->right=z;
	z->left= NULL;
	z->right= NULL;
	z->color= RED;
	insertfix(z);
}

void RedBlackTree::insertfix(Node *&z)
{
	if(root==z)
    {
         z->color=BLACK;
         return;
    }
	while (z->parent!=NULL && z->parent->color == RED)
	{
		if (z->parent == z->parent->parent->left)
		{
			Node* y=z->parent->parent->right;
			if(y!=NULL)
            {
                if(y->color==RED)
                {
                    z->parent->color=BLACK;
                    y->color=BLACK;
                    z->parent->parent->color=BLACK;
                    z=z->parent->parent;
                }
            }
			else
			{
				if(z == z->parent->right)
				{
					z=z->parent;
					leftrotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightrotate(z->parent->parent);
			}	
		}
		else
		{
			Node* y=z->parent->parent->left;
			if(y!=NULL)
            {
                if(y->color==RED)
                {
                    z->parent->color=BLACK;
                    y->color=BLACK;
                    z->parent->parent->color=BLACK;
                    z=z->parent->parent;
                }
            }
			else
			{
				if(z == z->parent->left)
				{
					z=z->parent;
					rightrotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftrotate(z->parent->parent);
			}	
		}
		root->color=BLACK;
	}
}
void RedBlackTree::leftrotate(Node *&x)
{
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
     }
}
void RedBlackTree::rightrotate(Node *&x)
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
     }
}

Node* RedBlackTree::search(int x)
{
	return search2(root,x);
}
Node* RedBlackTree::search2(Node* x,int k)
{
	if(x== NULL || k== x->key)
		return x;
	if(k<x->key)
		return search2(x->left,k);
	else
		return search2(x->right,k);
}

Node* RedBlackTree::successor(const Node *x) 
{	
	if (x->right != NULL)
		return getminimum2(x->right);
	Node* y= x->parent;
	while (y != NULL && x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
Node* RedBlackTree::predecessor(const Node * x)
{
	if (x->left != NULL)   
		return getmaximum2(x->left);
	Node* y= x->parent;
	while (y != NULL && x==y->left)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
Node* RedBlackTree::getminimum()
{
	return getminimum2(root);
}
Node* RedBlackTree::getminimum2(Node* t)
{
	while (t->left != NULL)
		t=t->left;
	return t;
}
Node* RedBlackTree::getmaximum()
{
	return getmaximum2(root);
} 
Node* RedBlackTree::getmaximum2(Node* t)
{
	while (t->right != NULL)
		t=t->right;
	return t;
}
void RedBlackTree::disp()
{
     display(root);
}
void RedBlackTree::display (Node *&t)
{
	if(t == NULL)
            return;
        cout << t->key << " ";
        display (t->left);
        display (t->right);
}
int main()
{
    RedBlackTree obj;
    obj.insert (13);
    obj.insert (44);
    obj.insert (37);
    obj.insert (7);
    obj.insert (22);
    obj.insert (16); 
    cout<<"Minimum is "<<obj.getminimum()->key<<endl;
    cout<<"Maximum is "<<obj.getmaximum()->key<<endl;
    //assuming 22 is the number we are searching for;
    const Node* x=obj.search(22);
    cout<<"Search result is ";
	if (x == NULL)
		cout<<"not found"<<endl;
	else
	{
		cout<<x->key<<endl;
		cout<<"The successor is "<<obj.successor(x)->key<<endl;
		cout<<"The predecessor is "<<obj.predecessor(x)->key<<endl;
	}
    cout<<"The tree elements are: ";
	obj.disp();
    return 0;
}
