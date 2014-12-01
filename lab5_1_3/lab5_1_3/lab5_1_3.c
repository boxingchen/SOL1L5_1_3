/* File: lab5_1_3.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 11.11.2014 */

#define _CRT_SECURE_NO_WARNINGS									// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>										
#include <stdlib.h>	

int Is_large_1D_array_inside_small_1D_array(int large_array_1D[], int small_array_1D[], int size_large, int size_small);

int main()
{
	int large_array_1D[] = {1, 8, 11, 4, 6, 9, 15, 4, 6, 9, 8};
	int small_array_1D[] = {4, 6, 9};
	int size_large, size_small;
	int result;
	
	size_large = sizeof(large_array_1D)/sizeof(int);
	size_small = sizeof(small_array_1D)/sizeof(int);
	result = Is_large_1D_array_inside_small_1D_array(large_array_1D, small_array_1D, size_large, size_small);
	printf("result = %d\n", result);
	
	system("pause");
	return 0;
}

int Is_large_1D_array_inside_small_1D_array(int large_array_1D[], int small_array_1D[], int size_large, int size_small)
{
	int sample = small_array_1D[0];	// 0 element of the smaller array
	int i = 0;						// large array index
	int j = 0;						// small array index
	int match = 0;					// the goal
	int matchIndex;					// for going back in case of partial match

	while(i < size_large && (size_large - i) > size_small && !match) // iterate large array until it is safe to say that the smaller array won't be found inside
	{																// or inclusion of the small array is found
		if(sample == large_array_1D[i])								// look for 0 element of the smaller array
		{
			matchIndex = i;											// remember where it was found
			i++;													// move to next element in both arrays
			j++;
			while(j < size_small)									// begin checking for full match 
			{
				match = 0;											// assume next element doesn't match
				if(small_array_1D[j] == large_array_1D[i])			// check if they match
				{
					match = 1;
				}
				else
				{
					i = matchIndex;									// if not, go back to the initial position in the large array
					j = 0;											// and in the small array
					break;											// terminate the cycle
				}
				i++;
				j++;
			}
		}
		i++;
	}
	if(match)
		return matchIndex;
	else
		return match;
}