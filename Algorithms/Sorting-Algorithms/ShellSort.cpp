#include "Sorting.h"

// #Insertion_Sort
template <typename T>
void Sorting<T>::ShellSort(DynamicArray<T> *arr, int _size)
{
    int gap, i,j;
    // Start with a big gap, then reduce the gap 
	for (gap = _size/2; gap > 0; gap /= 2) 
	{
        // Do a gapped insertion sort for this gap size. 
		// The first gap elements a[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted 
		for (i = gap; i < _size; i += 1) 
		{
            // add a[i] to the elements that have been gap sorted 
			// save a[i] in temp and make a hole at position i 
			T temp = (*arr)[i]; 

			// shift earlier gap-sorted elements up until the correct 
			// location for a[i] is found 
			for (j = i; j >= gap && (*arr)[j - gap] > temp; j -= gap) 
				(*arr)[j] = (*arr)[j - gap]; 
			
			// put temp (the original a[i]) in its correct location 
			(*arr)[j] = temp; 
        }
    }
}