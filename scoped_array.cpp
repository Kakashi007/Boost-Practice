#include<iostream>
#include<boost/smart_ptr/scoped_array.hpp>

using namespace std;

int main()
{
	boost::scoped_array<int> a;
	a.reset(new int[10]);
	for(int i=0;i<10;i++)
		a[i]=i;
	
	cout<<"\n"<<*(a.get());				//get() returns pointer to element
	cout<<"\n"<<*(a.get()+5);
	
	boost::scoped_array<int> b;
	b.reset(new int[10]);
	for(int i=0;i<10;i++)
		b[i]=i*2;
	
	cout<<"\nbefore swap";
	
	cout<<"\n	contents of a \n	";
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<"\n	contents of b \n	";
	for(int i=0;i<10;i++)
		cout<<b[i]<<" ";
	
	swap(a,b);					//swaps the contents of the two arrays , could also use a.swap(b);
	
	cout<<"\nafter swap";
	
	cout<<"\n	contents of a \n	";
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<"\n	contents of b \n	";
	for(int i=0;i<10;i++)
		cout<<b[i]<<" ";
	cout<<"\n";
	return 0;

}
