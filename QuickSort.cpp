//Quick sort
//Pivot
//eleFromLeft and eleFromRight
//Recursion

//Worst case O(n^2)
//Avg case O(nlog(n))

// 2 6 5 3 8 7 1 0


/*

pick a pivot
push to last
if eleFromLeft>pivot and eleFromRight<pivot
if index of eleFromLeft>eleFromRight
replace pivot with eleFromLeft
else
swap eleFromRight and eleFromLeft

*/

#include <iostream>

using namespace std;


void Display(int* v)
{
	for (int i=0;i<8;i++)
		std::cout << v[i] << " ";
	cout<<endl;
}


void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


int Partition(int* v, int l, int h)
{

	int pivot = v[h];
	int i=l, j=h;

	while(i<j)
	{
		if(v[i]<pivot)
			{
				i++;
				continue;
			}
		if(v[j]>=pivot)
			{
				--j;
				continue;
			}
		if(v[i]>pivot && v[j]<pivot)
		    Swap(&v[i], &v[j]);
	}

	Swap(&v[h], &v[j]);

	return j;
}


void QuickSort(int* v, int l, int h)
{
    Display(v);

    int j;
    
	if(l<h)
	{
		j = Partition(v, l, h);
		if (l<(j-1))
			QuickSort(v, l, (j-1));
		if ((j+1)<h)
			QuickSort(v, (j+1), h);
	}
}


int main()
{

    int v[8] = {2, 6, 5, 3, 8, 7, 1, 0} ;
    
    QuickSort(v, 0, 7);
    
    Display(v);

    return 0;
}