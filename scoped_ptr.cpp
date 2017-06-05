#include<iostream>
#include<boost/scoped_ptr.hpp>

using namespace std;

class foobar
{
	boost::scoped_ptr<int> ptr;
public:
	foobar():ptr(new int)  {*ptr=1;}
	int add_one() {return ++*ptr;}
	~foobar() {cout<<"destroyed\n";}
};

/*void send(boost::scoped_ptr<int> p)            		error,since scoped_ptr is non-copyable 
{
	//does something
}*/

int main()
{
	foobar f;
	cout<<f.add_one();
	cout<<"\n";
	cout<<f.add_one();
	cout<<"\n";
	boost::scoped_ptr<int> p(new int);						//initialize them right on declaration 
	*p=10;
//	send(p);
	cout<<*p<<"\n";
	return 0;
}
