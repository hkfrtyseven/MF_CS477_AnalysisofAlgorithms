//============================================================================
// Name        : cost_pd.cpp
// Author      : Matt Facque
// Version     :
// Copyright   : 
// Description : Dynamic Programming
// 				 Minimum shipping cost computed with two companies (A and B)
//============================================================================

#include <iostream>
#include <fstream>

// PROTOTYPES
int optimize(int[], int, int&, char[], int[]);

int min(int x, int y) {
	return (x < y) ? x : y;
}

int main() {
	//  Shipping weights
	int min_Value = 0;
	//  Shipping weight schedule
	int si[10] = {11,9,9,12,12,12,12,9,9,11};
	//  Company choice per week
	char comp_Choice[10] = {0};
	//  Aggregate Shipping Cost
	int optimal_Val[10] = {0};

	std::ofstream outputFile;
	outputFile.open("cost_pd_out.txt");

	min_Value = optimize(si, 9, min_Value, comp_Choice, optimal_Val);
	std::cout << "Minimum shipping cost is: " << min_Value << "\n";
	outputFile << "Minimum shipping cost is: " << min_Value << "\n";

	std::cout << "\nCompany (either A or B) used per week: \n";
	outputFile << "\nCompany (either A or B) used per week: \n";
	for (int i = 0; i < 10; i++) {
		std::cout << "Week " << i + 1 << "		" << comp_Choice[i] << " \n";
		outputFile << "Week " << i + 1 << "		" << comp_Choice[i] << " \n";
	}
	std::cout << "\nAggregate shipping costs per week: \n";
	outputFile << "\nAggregate shipping costs per week: \n";
	for (int j = 0; j < 10; j++) {
		std::cout << "Week " << j + 1 << "		" << optimal_Val[j] << " \n";
		outputFile << "Week " << j + 1 << "		" << optimal_Val[j] << " \n";
	}

	return 0;
}

int optimize(int arr[], int index, int &total, char comp_Choice[], int optimal_Val[]) {
	//  Shipping costs
	int r = 1;
	int c = 10;
	//  Shipping companies
	int comp_A = 0;
	int comp_B = 0;

	//  Base Case
	//  Implies last week
	if (index == 0) {
		comp_Choice[index] = 'A';
		total = r * arr[index];
		optimal_Val[index] = total;
		return total;
	}

	//  Index < 3
	//  There are up to 4 weeks left in shipping schedule
	//  Shipping can be done with A or B
	if (index < 4) {
		if (index == 3) {
			comp_A = optimize(arr, index - 1, total, comp_Choice, optimal_Val) + r * arr[index];
			comp_B = 4 * c;
			if (comp_A < comp_B) {
				comp_Choice[index] = 'A';
			}
			else {
				comp_Choice[index] = 'B';
			}
			total = min(comp_A, comp_B);
			optimal_Val[index] = total;
			return total;
		}

		//  If less than 4 weeks, Company B cannot be chosen
		comp_Choice[index] = 'A';
		total = optimize(arr, index - 1, total, comp_Choice, optimal_Val) + r * arr[index];
		optimal_Val[index] = total;
		return total;
	}

	//  Shipping costs recursion
	comp_A = optimize(arr, index - 1, total, comp_Choice, optimal_Val) + r * arr[index];
	comp_B = optimize(arr, index - 4, total, comp_Choice, optimal_Val) + 4 * c;
	if (comp_A < comp_B) {
		comp_Choice[index] = 'A';
	}
	else {
		comp_Choice[index] = 'B';
	}
	total = min(comp_A, comp_B);
	optimal_Val[index] = total;

	return total;
}
