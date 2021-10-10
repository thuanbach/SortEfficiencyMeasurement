/*
 * efficiency_measure.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: Thuan Bach
 */

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

using namespace std;

const unsigned int NUMBER_OF_ARRAYS_PER_SIZE = 10;
const unsigned int NUMBER_OF_ARRAY_ORDERING = 3;

const char PLUS_CHARACTER = '+';
const char TABLE_HORIZONTAL_BORDER_CHARACTER = '-';

const char TABLE_VERTICAL_BORDER_CHARACTER = '|';

const unsigned int ARRAY_HEADER_WIDTH = 10;
const unsigned int ARRAY_HEADER_PADDING = 2;

const string COLUMN_HEADER = "Array";

const char BLANK_CHARACTER = ' ';

const unsigned int FIRST_COLUMN_WIDTH = 20;

const unsigned int COLUMN_WIDTH_PER_ARRAY = 11;

const unsigned int TOTAL_TABLE_WIDTH = FIRST_COLUMN_WIDTH
		+ COLUMN_WIDTH_PER_ARRAY * NUMBER_OF_ARRAYS_PER_SIZE;

unsigned int measure_array_sorting(unsigned int *arr, unsigned int size) {

	auto t1 = chrono::high_resolution_clock::now();

	sort(arr, arr + size);

	auto t2 = chrono::high_resolution_clock::now();

	auto ms_int = duration_cast<milliseconds>(t2 - t1);

	return ms_int.count();
}

void print_execution_time(unsigned int n,
		unsigned int execution_time[NUMBER_OF_ARRAY_ORDERING][NUMBER_OF_ARRAYS_PER_SIZE]) {

	// Print a line to indicate size of arrays
	cout << "n=" << n << endl;


	// Print table header border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	// Print row header
	cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH)
			<< BLANK_CHARACTER;

	for (unsigned i = 0; i < NUMBER_OF_ARRAYS_PER_SIZE; i++) {
		cout << TABLE_VERTICAL_BORDER_CHARACTER << left
				<< setw(ARRAY_HEADER_PADDING) << BLANK_CHARACTER
				<< setw(ARRAY_HEADER_WIDTH - ARRAY_HEADER_PADDING)
				<< (COLUMN_HEADER + BLANK_CHARACTER + to_string(i + 1));

	}
	cout << TABLE_VERTICAL_BORDER_CHARACTER << endl;

	// Close table header with a border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;


	// Print execution time for each array ordering.
	for (unsigned i = 0; i < NUMBER_OF_ARRAY_ORDERING; i++) {
		cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH)
				<< left;

		if (i == 0) {
			cout << "Random time (ms)";
		} else if (i == 1) {
			cout << "Ordered time (ms)";
		} else {
			cout << "Reverse time (ms)";
		}

		for (unsigned int k = 0; k < NUMBER_OF_ARRAYS_PER_SIZE; k++) {
			cout << TABLE_VERTICAL_BORDER_CHARACTER << right
					<< setw(ARRAY_HEADER_WIDTH) << execution_time[i][k];
		}
		cout << TABLE_VERTICAL_BORDER_CHARACTER << endl;
	}

	// Close the table with a border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;
}

void measure_sorting(unsigned int n) {

	unsigned int arr[n];

	unsigned int execution_time[NUMBER_OF_ARRAY_ORDERING][NUMBER_OF_ARRAYS_PER_SIZE];

	for (unsigned j = 0; j < NUMBER_OF_ARRAYS_PER_SIZE; j++) {

		for (unsigned int k = 0; k < n; k++) {
			arr[j] = rand();
		}

		// Test sort random
		execution_time[0][j] = measure_array_sorting(arr, n);

		// Test ascend
		execution_time[1][j] = measure_array_sorting(arr, n);

		// 	Test reverse
		reverse(arr, arr + n);

		execution_time[2][j] = measure_array_sorting(arr, n);
	}

	print_execution_time(n, execution_time);

}

void measure_sorting_efficiency() {

	const unsigned int NUMBER_OF_ARRAY_SIZES = 3;

	unsigned int array_sizes[NUMBER_OF_ARRAY_SIZES];

	array_sizes[0] = 100 * 1000;
	array_sizes[1] = 1000 * 1000;
	array_sizes[2] = 10000 * 1000;

	for (unsigned i = 0; i < 3; i++) {
		measure_sorting(array_sizes[i]);
		cout << endl;
	}
}

