#include<iostream>
#include <vector>
#include <memory>
#include<iterator>


using namespace std;

int main()
{
	vector<unique_ptr<int>> v;
	vector<unique_ptr<int>>::iterator iter;
	unique_ptr<int> p1(new int(1));
	unique_ptr<int> p2(new int(2));
	v.push_back(move(p1));					//unique_ptr can't be copied,hence move is used
	v.push_back(move(p2));
	for (iter = v.begin(); iter != v.end(); iter++)`	
	  cout << (**iter) << endl;				//vector contains unique_ptr holding addresses of ints , hence ** is used
	return 0;
	
}
