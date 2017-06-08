#include<iostream>
#include<boost/shared_ptr.hpp>
#include<boost/weak_ptr.hpp>

using namespace std;


int main()
{
	
	
	shared_ptr<int> f1(new int(9));				
	cout<<"\nf1.get()	:"<<f1.get();
	cout<<"\nf1.use_count()	:"<<f1.use_count();

	int* p=f1.get();
	cout<<"\n"<<*p<<"\n";

	weak_ptr<int> w(f1);
	shared_ptr<int> q=w.lock();				//now the object will stay alive until q goes out of scope or is reset
	cout<<*q;

	cout<<"\nf1.reset()";						
	f1.reset();
	cout<<"\n"<<*p;
	cout<<"\n"<<*q<<"\n";

	cout<<"q.reset";
	q.reset();
	cout<<"\n"<<*p;						//since the object doesn't exists now:output is segmentation fault 
	cout<<"\n"<<*q<<"\n";

						
	return 0;

}

