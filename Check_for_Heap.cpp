/*
 * problem5.cpp
 *
 *  Created on: 	Oct 6, 2021
 *  Author: 		Matt Facque
 *  Compilation: 	g++ problem5.cpp
 *			   : 	Compiled in Ubuntu with a GCC C++ compiler
 *  Description: 	Process heap with for loop, return true if MAX heap, false if not MAX heap
 */

#include <iostream>

/*****************************************************
 * FUNCTION: 	maxHeap
 * DESCRIPTION:	Cycle through array, checking if heap is in max configuration
 * RETURNS:		boolean
 * NOTES:		Handy way to access heap in array, 2*i + 1 (left child), 2*i + 2 (right child)
 */
bool maxHeap(int array[], int array_Size) {
	//  Check array bounds, if greater than bounds return true
	int count = 0;
	for (int i = 0; i < array_Size; i++) {
		count = 2 * i + 1;
		if (count > array_Size) {
			break;
		}
		if (array[i] < array[2*i + 1]) {
			//  If left child is greater, return false
			return false;
		}
		if (array[i] < array[2*i + 2]) {
			//  If right child is greater, return true
			return false;
		}
	}
	return true;
}

int main() {
	int array_A[] = {16,14,10,8,7,9,3,2,4,1};
	int array_B[] = {10,3,9,7,2,11,5,1,6};

	int size_A = sizeof(array_A) / sizeof(array_A[0]);
	int size_B = sizeof(array_B) / sizeof(array_B[0]);

	bool check_A = maxHeap(array_A, size_A);
	bool check_B = maxHeap(array_B, size_B);

	if (check_A) {
		std::cout << "YES, heap\n";
	}
	else {
		std::cout << "Not a heap";
	}

	if (check_B) {
		std::cout << "YES, heap\n";
	}
	else {
		std::cout << "Not a heap";
	}

	return 0;
}


