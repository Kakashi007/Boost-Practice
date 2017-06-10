#include<iostream>
#include<boost/ptr_container/ptr_vector.hpp>
#include <boost/foreach.hpp>

using namespace std;

int main()
{
	boost::ptr_vector<int> v;
	v.push_back(new int{1});
	v.push_back(new int{2});
	BOOST_FOREACH(int i,v)
		cout<<i<<"\n";
	cout<<*v.begin()<<"\n";		//because boost::ptr_vector knows that it stores dynamically allocated objects, 
	return 0;			//monly one *(dereferencing) is required to obtain the int stored 
					//(returns a reference to a dynamically allocated object and not a pointer. )
}
