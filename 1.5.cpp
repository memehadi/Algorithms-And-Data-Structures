/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include <vector>
#include <iostream>
#include<string>
//const int size = 50;

using namespace std;

int main()
{
	
	vector<string> vs;		// a vector of ints. Default size is accepted
	string s;
	int counter=0;
	cout<<"enter oyur strings";
	while (1)
		{
			
			getline(cin,s);
			if(s=="END")
				{
					break;
				}
			
			vs.push_back(s);
			counter++;
		}
		
		while(1)
		{
		
			if (counter>=5)
				{
				string temp=vs[1];
				vs[1]=vs[4];
				 vs[4]=temp;
				 break;
			}
			else
			{
				cout<<"we could not swap the elements as they do not exist"<<endl;
				break;
			}
		}
				
//	cout<<"size is "<<vs.size()<<endl;		 
		
	for (int i = 0; i < vs.size(); i++)	// uses the overloaded [] operator 
										// to access data
  //  cout<<"frghj";
  if(i==(vs.size())-1)
  {
  		vs[i]="???";
  		cout << vs[i]<<endl; ;
  }
  else
  {
  
		cout << vs[i] << ",";
		//cout<<endl;	
	}
    
    
     
    
   	vector<string>::iterator viter = vs.begin(); 
    while (viter != vs.end()) 
	{
		if (viter==(vs.end())-1)
			{	
				*viter="???";
				cout << *viter;
			}
		else
			cout << *viter << ";  " ;
		viter++;
	}

 	vector<string>::iterator vreverse = vs.end(); 
    while (vreverse != vs.begin()) 
 	{
		/*if (viter==(vs.end())-1)
			{	
				*viter="???";
				cout << *viter;
			}
		else*/
			cout << *vreverse << " " ;
		vreverse=vreverse-1;
	}	
	
return 0;	
 }  
