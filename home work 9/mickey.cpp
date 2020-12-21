#include<iostream>
using namespace std;
enum Color {RED, BLACK}; 
struct node
{
    int data;
    bool color;
    node* left;
    node* right;
    node* parent;
};
class BST
{
private:
    node* root;
    node* tra;
    /*
    node* insert(node x, node* root)
    {
        if(root == NULL)
        {
            root = new node;
            root->data = x.data;
            root->left = root->right = NULL;
        }
        else if(x.data < root->data)
            root->left = insert(x, root->left);
        else if(x.data > root->data)
            root->right = insert(x, root->right);
        cout<<root->data<<endl;
        return root;
    }
    */
    void insert (node *z, node* root)
    {
    	node* y= NULL;
    	node* x= root;
    	while  (x != NULL)
    	{
    		y=x;
    		if (z->data<x->data)
    			x=x->left;
    		else
    			x=x->right;
    	}
    	z->parent = y;
    	if (y == NULL)
    		root=z;
    	else if (z->data<y->data)
			y->left=z;
		else
			y->right=z;	
	}

    bool isEmpty(node *t)
    {
    	if (t==NULL)
    		return 1;
    	else
    		return 0;
	}
    int findMin(node* t)  
	{  
		tra=t;
		while (tra->left != NULL)    
    		tra = tra->left;   
		return(tra->data);  
	}  
    
	void preorder (node *t)
	{
		if(t == NULL)
            return;
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
	}
    void inorder(node* t)
	{
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
	void postorder (node *t)
	{
		if(t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
	}


public:
    BST()
	{
        root = NULL;
    }
    void insert(int x)
	{
		node *input= new node;
		input->data=x;
		input->left= NULL;
		input->right= NULL;
        insert(input, root);
    }
	
	bool isEmpty()
	{
		bool x=isEmpty(root);
		return x;
	}
	
	int findMin()
	{
		int y= findMin(root);
		return y;
	}
	
    void display()
	{
        cout<<"Preorder: ";
		preorder(root);
		cout<<endl;
        cout<<"Inorder: ";
		inorder(root);
		cout<<endl;
        cout<<"Postorder: ";
		postorder(root);
		cout<<endl;
    }  
};

int main()
{
    BST t;
    int x[6];
    x[0]= 13;
    x[1] = 44;
    x[2] = 37;
    x[3] = 7;
    x[4] = 22;
    x[5] = 16;
    //x.left= NULL;
    //x.right= NULL;
    for (int i=0;i<6;i++)
    	t.insert(x[i]);
	t.display();
    return 0; 
}
