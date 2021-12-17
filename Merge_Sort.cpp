/*
 * problem3.cpp
 *
 *  Created on: Sep 21, 2021
 *      Author: Matt Facque
 *
 *  Compilation:  g++ problem2.cpp
 *  Compiled in Ubuntu with GCC C++ Compiler
 *
 *  NOTE:  Not getting proper output but will submit to avoid late penalty.
 *  NOTE:  At some point, the arrays aren't copying to each other properly.
 */

#include <iostream>

/*
 * FUNCTION:		merge
 * DESCRIPTION:		Merge array elements into temp_array and then copy back into test_array
 * NOTE:			Every iteration of merge uses larger and larger array pieces in powers of 2
 */
void merge(int test_array[], int temp_array[], int start, int mid, int end) {
	//  Indices
	int a = start;
	int b = mid+1;
	int c = end;
	int temp = start;

	//  loop through test_array and sort into temp_array
	while (a <= mid && b <= c) {
		if (test_array[a] < test_array[b]) {
			temp_array[temp++] = test_array[a++];
			//temp++;	Not incrementing properly
			//a++;
		}
		else {
			temp_array[temp++] = test_array[b++];
			//temp++;	Not incrementing properly
			//b++;
		}
	}
	/*
	//  get remaining elements from left and right sub array
	while (a < mid) {
		temp_array[temp++] = test_array[a++];
		//a++;		Not incrementing properly
		//temp++;
	}
	/*
	while (b < end) {
		temp_array[temp++] = test_array[b++];
		//b++;		Not incrementing properly
		//temp++;
	}
	*/
	//  Put back into test_array
	for (int x = start; x <= end; x++) {
		test_array[x] = temp_array[x];
	}
}

/*
 * FUNCTION:		iterative_Merge
 * DESCRIPTION:		Use merge sort "bottom up" without recursion
 * NOTE:			Uses a temporary array to hold sorted bits
 * NOTE:			Uses adjacent elements, then the next adjacent elements, so on
 */
void iterative_Merge(int test_array[], int temp_array[], int start, int end) {
	//  For loop to pass through array in sizes of 2^i
	//  i = 1
	//  i = 2
	//  i = 4 ......
	for (int i = 1; i <= end - start; i = 2*i) {
		//  For loop to combine array pieces (j = values of 2^i)
		//  j = 0 -> 2
		//  j = 2 -> 4
		//  j = 4 -> 6
		//  j = 6 -> 8 ......
		for (int j = start; j < end; j = j + 2*i) {
			int sort_start = j;
			int sort_mid = j + i - 1;    //  end of left sub array
			int sort_end = 0;
			if ((j+2*i-1) < end) {
				sort_end = j+2*i-1;
			}
			else {
				sort_end = end;
			}
			//  int sort_end = j + 2*i - 1;  //  Have to check for end of array
			merge(test_array, temp_array, sort_start, sort_mid, sort_end);
		}
	}
}

int main() {
	int test_array[] = {1,4,9,3,4,9,5,6,9,3,7,2};
	int array_size = sizeof(test_array) / sizeof(test_array[0]);

	//  Hold sorted bits before copying back to test_array
	int temp_array[] = {array_size};

	iterative_Merge(test_array, temp_array, 0, array_size-1);

	//  Print sort array
	for (int y = 0; y <= array_size; y++) {
		std::cout << test_array[y] << " ";
	}

	return 0;
}


