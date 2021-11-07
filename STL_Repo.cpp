//C++ STL Demo

//Vectors

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

void vectorOperations()
{
	std::vector<int> v = {17, 2, 9, 24, 4, 10};
	
	cout<<v[1]<<endl;

	sort(v.begin(), v.end());  //O(nlog(n))

	bool present = binary_search(v.begin(), v.end(), 9);  //true
    cout<<"Boolean "<<present<<endl;

	v.push_back(100);
	v.push_back(100);
	v.push_back(100);
	v.push_back(123);

	std::vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), 100);	// >=, O(log(n)
	std::vector<int>::iterator it2 = upper_bound(v.begin(), v.end(), 100);  // >, O(log(n)
	//OR
	// auto it = lower_bound(v.begin(), v.end(), 100);

	cout<<*it1<<" "<<*it2<<endl;
	cout<<(it2-it1)<<endl; //3 = no of occurences of 100

	sort(v.begin(), v.end());

	//looping through the vector
	//method 1
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		cout<<*i<<' ';
	cout<<endl;

	//method 2
	for( int x:v )
		cout<<x<<' ';
	cout<<endl;

	//method 3
	for( int &x:v)		//iterating by reference
		cout<<++x<<' ';
	cout<<endl;

}


//sets are inherently sorted
//deleting and seraching are O(log(n))
void setOperations()
{
	std::set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(-1);
	s.insert(-20);

	for(int x:s)
		cout<<x<<' ';
	cout<<endl;

	auto it = s.find(-1);
	if(it==s.end())
		cout<<"Element not found\n";
	else
		cout<<"Element present "<<endl; //returns address of position

	auto it2 = s.upper_bound(-1); //note here s is associated to the function upper_bound since it's always sorted abd the class has the function exposed to the user

	auto it3 = s.upper_bound(2);
	if(it3==s.end())
		cout<<"Element greater than 2 not found"<<endl;

}


//holds key value pairs
//finding and deleting happens in O(log(n))
void mapOperations()
{
	std::map<int, int> m;
	m[1] = 100;
	m[100246] = -1;

	std::map<char, int> count;
	string name = "kumar ramesh";

	for( auto c:name) //loops through the keys which are the characters in name
		count[c]++; //increment count when you come across the same key

	cout<<"k : "<<count['k']<<"\nr : "<<count['r']<<endl;

}


void powerOfSTL()
{
	set< pair<int, int> > s;

	s.insert({30,40});
	s.insert({10,20});
	s.insert({300,400});

	for(auto x:s)
		cout<<x.first<<' '<<x.second<<endl;

	int key = 3;

	pair <int, int> k = {key, INT_MAX};

	auto it = s.upper_bound(k);
	
	if(it==s.begin())
	    cout<<"Element not present\n";
	else
	{
    	it--;
    	if( (*it).first<key && (*it).second>key )
    	    cout<<"Element found in range : ["<<(*it).first<<','<<(*it).second<<']'<<endl;
    	else
    	    cout<<"Element not present\n";
	}

}


int main(int argc, char const *argv[])
{
	//vectorOperations();
	//setOperations();
	//mapOperations();
	powerOfSTL();

	return 0;
}