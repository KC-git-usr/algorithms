//dynamic array declaration- allocate new memory chunk, copy present array values to the new memory location and add new values to the newly allocated memory
//showing the use of heap
//redo using class
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
		std::cout<<"Enter element "<<i<<" : ";
		std::cin>>*(ptr+i);
	}

	std::cout<<"\nEntered array is : ";
	for (int i = 0; i < size; ++i)
		std::cout<<*(ptr+i)<<", ";
		
	char choice = 'y';

	while(choice == 'y')
	{
		std::cout<<"\nWould you like to add more element(s)? (y/n) ";
		std::cin>>choice;
		if (choice == 'y')
		{
				std::cout<<"\nEnter the new size of your array : ";
				std::cin>>size;

				delete []ptr;
				ptr = new int[size];

				for (int i = 0; i < size; ++i)
				{
					std::cout<<"Enter new element "<<i<<" : ";
					std::cin>>*(ptr+i);
				}

				std::cout<<"\nEntered new array is : ";
				for (int i = 0; i < size; ++i)
					std::cout<<*(ptr+i)<<", ";
		}
	}
	
	delete []ptr;
	ptr = nullptr;
    
	return 0;
}