
//Basic 1
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	cout<<"Hello nigga";
	return 0;
}


//Basic2
#include <iostream>

int main(int argc, char const *argv[])
{
	string name;
	std::cout<<"Enter your name : ";
	getline(cin,name);
	std::cout<<"Name = "<<name;	
	return 0;
}


//enum example
//enum used to substitute names with const integers/codes for readability
#include <iostream>

int main(int argc, char const *argv[])
{
	enum day{mon=1, tue, wed, thurs, fri, sat, sun};
	day d = mon;
	if (d==mon)
		std::cout<<"It's Monday";
	return 0;
}


//typedef example
//typedef is used to substitute a lesser convenient name for a more convenient name
#include <iostream>
typedef int marks;

int main(int argc, char const *argv[])
{
	marks m1 = 100;
	std::cout<<m1;
	return 0;
}

//Basic 3
//Max of 3 numbers
#include <iostream>

int main(int argc, char const *argv[])
{
	int a, b, c;
	std::cout<<"Enter value of a, b and c\n";
	std::cin>>a>>b>>c;
	if (a>b && a>c)
		std::cout<<a<<" is the largest number";
	else
		if(c>b)
			std::cout<<c<<" is the largest number";
		else
			std::cout<<b<<" is the largest number";
	return 0;
}



//simple for loop
#include <iostream>

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout<<i<<endl;
	}
	return 0;
}



//array basics
#include <iostream>

int main(int argc, char const *argv[])
{
	int A[10]={1,2,3,4,5,6,7,8,9,10}; //array can be float, char, double, etc
	float B[5]={1.1,1.2,1.3}; //rest of the ele are initialized to 0
	char C[]={'A','b',67};
	std::cout<<A[5]<<'\n';
	std::cout<<C[2]<<'\n';
	for(int x:A)  //foreach
		std::cout<<x<<std::endl;
	for(auto x:B)																			//Note: x is of type float OR auto, else it'll be truncated
		std::cout<<x<<std::endl;  //value of B is copied into x
	for(auto &x:A)	//call by reference, both A and x wil be changed together  || foreach cant be used on pointers
	{
		x+=2;		
		std::cout<<x<<'\n';
	}
	return 0;
}



//binary search
#include <iostream>

const int size = 5;

int main(int argc, char const *argv[])
{

	int A[size], key;
	int l=0, h=(size-1), mid;
	mid = (l+h)/2;

	std::cout<<"Enter array of size "<<size<<" :\n";
	for(int &x:A)
		std::cin>>x;

	std::cout<<"\nEnter key : \n";
	std::cin>>key;

	while(A[mid]!=key && (l<=h) )
	{
		if (A[mid]<key)
			l = mid+1;
		else
			h = mid-1;
		mid = (l+h)/2;
	}

	if (A[mid]==key)
		std::cout<<"Key found in array at : "<<mid;
	else
		std::cout<<"Key not found";

	return 0;
}



//pointers
#include <iostream>

int main(int argc, char const *argv[])
{
	int A[3]={1,2,3};
	int *ptr = A;
	std::cout<<*(ptr+3)<<'\n';
	std::cout<<A<<'\n';
	std::cout<<ptr[0]<<'\n';
	return 0;
}



//heap
#include <iostream>

int main(int argc, char const *argv[])
{
	int *p = new int[3];
	p[0]=2;
	p[1]=4;
	p[2]=6;

    std::cout<<p[1]<<'\n';
    std::cout<<p<<'\n';
    std::cout<<*p<<'\n';

	delete []p;
	
	std::cout<<"After deleting"<<'\n';
	std::cout<<p[1]<<'\n';  //should give garbage
	std::cout<<*p<<'\n';
	std::cout<<p<<'\n';
	
	p = nullptr;
	std::cout<<"After assigning to nullptr"<<'\n';
	std::cout<<p<<'\n';
	std::cout<<p[1]<<'\n';
	
	return 0;
}

//dynamic array declaration
//showing the use of heap
#include <iostream>

int main(int argc, char const *argv[])
{
	int size = 1;
	int *ptr = new int[size];

	std::cout<<"\nEnter the size of your array : ";
	std::cin>>size;

	delete []ptr;
	ptr = new int[size];

	for (int i = 0; i < size; ++i)
	{
		std::cout<<"\nEnter element "<<i<<" : ";
		std::cin>>*(ptr+i);
	}

	std::cout<<"\nEntered array is : ";
	for (int i = 0; i < size; ++i)
		std::cout<<*(ptr+i)<<", ";
	
	std::cout<<"\nEnter the new size of your array : ";
	std::cin>>size;

	delete []ptr;
	ptr = new int[size];

	for (int i = 0; i < size; ++i)
	{
		std::cout<<"\nEnter new element "<<i<<" : ";
		std::cin>>*(ptr+i);
	}

	std::cout<<"\nEntered new array is : ";
	for (int i = 0; i < size; ++i)
		std::cout<<*(ptr+i)<<", ";

	return 0;
}


//function returning address
//you can return address of heap mem, not local variable address
#include <iostream>
using namespace std;
  
int *func(int size)
{
    int *p = new int[size];
    for (int i = 0; i < size; i++) {
        p[i]=i+1;
    }    
    cout<<'\n'<<p;
    return p;
}
  
// Driver Code
int main() 
{
    int *p;
    p=func(5);
    cout<<'\n'<<p<<'\n';
    for (int i = 0; i < 5; i++) {
        cout<<p[i]<<", ";
    }
    
    delete []p;
    p=nullptr;
    
    cout<<'\n';
    
    for (int i = 0; i < 5; i++) {
        cout<<p[i]<<", ";
    }
    return 0;
}


//operator overloading
#include <iostream>

using namespace std;

class Complex
{
    private:
         int real;
         int img;
    public:
     Complex(int r=0,int i=0)
     {
         real=r;
         img=i;
     } 
     void display() 
     { 
        cout<<real<<"+i"<<img<<endl; 
     } 
    friend Complex operator+(Complex c1,Complex c2);
 };
 
Complex operator+(Complex c1,Complex c2)
{ 
     Complex temp;
     temp.real=c1.real+c2.real; 
     temp.img=c1.img+c2.img;
     return temp;
}

int main()
{
     Complex c1(5,3),c2(10,5),c3(1,2),c4;
     
     c4=c1+c2+c3;
     
     c4.display();
     
     return 0;
}