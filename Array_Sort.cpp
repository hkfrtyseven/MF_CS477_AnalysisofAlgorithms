//============================================================================
// Name        : problem2.cpp
// Author      : Matt Facque
// Version     : 1.0
// Date		   : 9/27/2021
// Compilation : g++ problem2.cpp
//			   : Compiled in Ubuntu with a GCC C++ compiler
// Description : Sort array by negative/positive value
//============================================================================

#include <iostream>

int main() {
	int array[] = {4,3,-2,0,2,9,-1,10,0,5,23,-4};
	//int array[] = {1,2,3,2,3,2,2,1,3,4,4,45,5,5,4,3,32,2,3,3,4,3,3,3,-3,-3,-4,-5,0,0,0,0,0,-6,-7,-7,4,-3,-4,1};
	int n = sizeof(array)/sizeof(array[0]);
	int target_array[n] = {};

	//  Initialize variables for for loops
	int i = 0;
	int j = 0;
	int k = 0;
	//  Variables for negative number indices
	int neg_Counter = 0;
	int negative_Actual = 0;

	//  Determine the number of negative numbers in array
	for (i = 0;i<n;i++) {
		if (array[i]<0) {
			neg_Counter+=1;
		}
	}

	//  pos_Counter = index where positive numbers will start
	int pos_Counter = neg_Counter;

	for (j = 0;j<n;j++) {
		if (array[j]<0) {
			target_array[negative_Actual] = array[j];
			negative_Actual+=1;
		}
		else {
			target_array[pos_Counter] = array[j];
			pos_Counter+=1;
		}
	}

	std::cout << "Array: ";
	for (k = 0; k<n; k++) {
		std::cout << target_array[k] << " ";
	}

	return 0;
}
