/* Musab Mehadi
mmehadi@jacobs-university.de*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
class Node {
   public:
      int key;
      int value;
      Node(int x, int y) 
	  {
         key= x;
         value = y;
      }
};
class HashTable {
   private:
       Node **arr;
       int maxsize;
       int currentsize;
   public:
       HashTable()
	   {
	   	currentsize=0;
	   	 maxsize=11;
         arr= new Node * [11];
         for (int i = 0; i<11; i++) 
		 {
            arr[i] = NULL;
         }
      }
      int HashCode(int k) 
	  {
	  		int i=0;
	  		int slot= ((k%11)+i*(k%9))%11;
	  		while (arr[slot] != NULL && arr[slot]->key != k) 
			{
				i++;
	  		 	slot = HashCode(k);
         	}
	  		
         	return slot;
      }
      void Insert(int k, int v) 
	  {
         int h = HashCode(k);
        
         if (arr[h] != NULL)
            delete arr[h];
         arr[h] = new Node(k, v);
         currentsize++;
      }
      int get(int k) 
	  {
         int h = HashCode(k);
         while (arr[h] != NULL && arr[h]->key != k) 
		 {
            h = HashCode(h + 1);
         }
         if (arr[h] == NULL)
            return -1;
         else 
            return arr[h]->value;
      }
     ~HashTable() 
	 {
        for (int i = 0; i < 200; i++)
		{
            if (arr[i] != NULL)
               delete arr[i];
            delete[] arr;
        }
    }
};
int main() {
   HashTable Muss;
   int k, v;
   int n;
   while (1) 
   {
      	cout<<"1.adds element into the table"<<endl;
      	cout<<"2.Searches element from the key"<<endl;
      	cout<<"3.Exits the programme"<<endl;
      	cout<<"Enter your choice: ";
      	cin>>n;
    	if(n==1) 
	  	{
            cout<<"Enter the value you want to insert: ";
            cin>>v;
            cout<<"Enter the key you want to insert: ";
            cin>>k;
            Muss.Insert(k, v);
       //  break;
        }
        else if(n==2)
        {
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (Muss.get(k) == -1) 
			{
               cout<<"No element found  "<<k<<endl;
               //continue;
            } 
			else 
			{
               cout<<"Element at key "<<k<<" : ";
               cout<<Muss.get(k)<<endl;
            }
         //break;
     	}
        
        else if (n==3) 
            exit(1);
        else
            cout<<"\n error enter your number again please \n";
      }
   
   return 0;
}
