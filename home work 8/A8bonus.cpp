/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include <iostream> 
using namespace std; 
class LNode 
{  
public:
	int data; 
	LNode* next; 
}; 

class TNode 
{ 
public: 
	int data; 
	TNode* left; 
	TNode* right; 
}; 

TNode* newNode(int data); 
int countLNodes(LNode *start_ptr); 
TNode* sortedListToBSTRecur(LNode **head_ref, int n); 
TNode* sortedListToBST(LNode *start_ptr) 
{ 
	int n = countLNodes(start_ptr); 
	return sortedListToBSTRecur(&start_ptr, n); 
} 

TNode* sortedListToBSTRecur(LNode **start_ptr_ref, int n) 
{ 
	if (n <= 0) 
		return NULL; 
	TNode *left = sortedListToBSTRecur(start_ptr_ref, n/2); 
	TNode *root = newNode((*start_ptr_ref)->data); 
	root->left = left; 
	*start_ptr_ref = (*start_ptr_ref)->next;
	root->right = sortedListToBSTRecur(start_ptr_ref, n - n / 2 - 1); 
	return root; 
} 

int countLNodes(LNode *start_ptr) 
{ 
	int count = 0; 
	LNode *temp = start_ptr; 
	while(temp) 
	{ 
		temp = temp->next; 
		count++; 
	} 
	return count; 
} 

void push(LNode** start_ptr_ref, int new_data) 
{ 
	LNode* new_node = new LNode(); 
	new_node->data = new_data; 
	new_node->next = (*start_ptr_ref); 
	(*start_ptr_ref) = new_node; 
} 

void printList(LNode *temp) 
{ 
	while(temp!=NULL) 
	{ 
		cout << temp->data << " "; 
		temp = temp->next; 
	} 
} 

TNode* newNode(int data) 
{ 
	TNode* node = new TNode(); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return node; 
} 
  
void inOrder(TNode* node) 
{ 
    if (node == NULL) 
        return; 
    inOrder(node->left); 
    cout << node->data << " "; 
    inOrder(node->right); 
} 
int main() 
{ 
	LNode* start_ptr = NULL; 
	for (int i=10;i>=1;i--)
		push (&start_ptr, i);
	cout<<"for our linked list, "<<endl; 
	printList(start_ptr); 
	TNode *root = sortedListToBST(start_ptr); 
	cout<<endl;
	cout<<"the inorder form is  "; 
	inOrder(root);
	return 0; 
} 

