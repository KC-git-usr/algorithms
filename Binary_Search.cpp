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