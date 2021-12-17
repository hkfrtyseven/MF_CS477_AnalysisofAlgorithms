/*
 *  problem2.cpp
 *
 *  Created on: Sep 20, 2021
 *      Author: Matt Facque
 *
 *  Compilation:  g++ problem2.cpp
 *  Compiled in Ubuntu with GCC C++ Compiler
 */

#include <iostream>

/*
 * FUNCTION:		minmax_Elements
 * DESCRIPTION:		Return the smallest and the largest values in array recursively
 * NOTE:			Divide and Conquer method
 */

void minmax_Elements(int test_array[], int start, int end, int &min, int &max) {
	//  Base case, one element in array
	if (start - end == 0) {
		if (min > test_array[start]) {
			min = test_array[start];
		}
		if (max < test_array[end]) {
			max = test_array[end];
		}

		return;
	}

	//  Base case, two elements in array
	if (start - end == 2) {
		if (test_array[start] < test_array[end]) {
			if (min > test_array[start]) {
				min = test_array[start];
			}
			if (max < test_array[end]) {
				max = test_array[end];
			}
		}
		else {
			if (min > test_array[end]) {
				min = test_array[end];
			}
			if (max < test_array[start]) {
				max = test_array[start];
			}
		}

		return;
	}

	int midpoint = (start + end) / 2;

	minmax_Elements(test_array, start, midpoint, min, max);
	minmax_Elements(test_array, midpoint + 1, end, min, max);
}

int main() {
	//  Array from problem2
	int test_array[] = {1,4,9,3,4,9,5,6,9,3,7};
	int array_size = sizeof(test_array) / sizeof(test_array[0]);

	//  Values guaranteed to be smaller then max or larger then min
	int min = 999999;
	int max = -999999;

	minmax_Elements(test_array, 0, array_size - 1, min, max);

	std::cout << "Max value = " << max << "\n";
	std::cout << "Min value = " << min << "\n";

	return 0;
}



