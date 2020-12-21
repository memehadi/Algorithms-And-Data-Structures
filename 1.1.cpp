/*Musab Mehadi
mmehadi@jacobs-university.de
*/
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
//template <class t>
class complex{
	private:
		float real;
		float imag;
	public:
		complex(float a,float b)
			{
				real=a;
				imag=b;
			}
		~complex()
		{
			//cout<<"destructor implemented"<<endl;
		}
		/*bool operator==(const complex&c)
			{
			if(	this->real == c.real && this->imag == c.imag)
				return true;
			else	
				return false;
			}*/
		
};
template <class t>
int array_search(t elements[],int n,t x)
{
	 for(int i=0;i<n;i++)
	 	{
			 	if(elements[i]==x)
			 	return i;
	 	}
	 	return -1;
}
int main()
{
	int n;
	double* d;
	cout<<"enter the size of the array"<<endl;
	cin>>n;
	d=new double[n];
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
	}
	complex one(5,2);
	complex two(1,9);
	complex three(7,2);
	complex array_of_complexes[3]={one,two,three};
	cout<<array_search(d,n,3.5)<<endl;
	cout<<array_search(array_of_complexes,3,two)<<endl;
	return 0;
	
}
