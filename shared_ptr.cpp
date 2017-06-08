#include<iostream>
#include<boost/shared_ptr.hpp>

using namespace std;

class foobar
{
		int x;
	public:
		foobar()
		{
			x=0;
			cout<<"\ncreated a foobar object\n";
		}
		~foobar()
		{
			cout<<"\ndestructed a foobar object";
		}
		int increment_x()
		{
			return x++;
		}

};

int main()
{
	
	
	shared_ptr<foobar> f1(new foobar);				//created a shared_ptr pointing to an object of foobar
	cout<<"\nf1.get()	:"<<f1.get();
	cout<<"\nf1.use_count()	:"<<f1.use_count();

	cout<<"\n\ncreated : shared_ptr<foobar> f2(f1)\n";		//created another shared ptr:f2,f1->same foobar object
	shared_ptr<foobar> f2(f1);
	cout<<"\nf2.get()	:"<<f2.get();
	cout<<"\nf2.use_count()	:"<<f2.use_count();
									//f1.count=f2.count=2
	cout<<"\nf1.use_count()	:"<<f1.use_count();

	cout<<"\n\n"<<f1->increment_x();				//increment the same x of foobar
	cout<<"\n"<<f2->increment_x();

	cout<<"\n\nresetting pointers";

	cout<<"\nf1.reset()";						//f1=0 (NULL) now
	f1.reset();
	cout<<"\nf1.get()	:"<<f1.get();
	cout<<"\nf1.use_count()	:"<<f1.use_count();						
	cout<<"\nf2.use_count()	:"<<f2.use_count();			//since f1 resetted , f2's use_cout--

	cout<<"\nf2.reset()\n";						//no pointer pointing to the object now, destructor is called
	f2.reset();
	cout<<"\nf2.get()	:"<<f2.get();
	cout<<"\nf2.use_count()	:"<<f2.use_count()<<"\n";

	return 0;

}

