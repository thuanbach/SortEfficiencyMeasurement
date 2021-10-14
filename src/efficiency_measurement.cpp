/*
 * efficiency_measure.cpp
 *
 *  Created on: Oct 9, 2021
 *      Author: Thuan Bach
 *
 *  This module is used to measure the efficiency of the sort method implemented in the library <algorithm>
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

/**
 * Number of arrays to be tested per the array size
 */
const unsigned int NUMBER_OF_ARRAYS_PER_SIZE = 10;

/**
 * Number of array orders to be tested per each array
 */
const unsigned int NUMBER_OF_ARRAY_ORDERING = 3;

/**
 * Declare a thousand separator
 */
const string THOUDSAND_SEPARATOR = ",";

/**
 * Measure the execution time of the sort method for one array
 *
 * @param arr[] The array of unsigned integer to be measured
 * @param size The size of the array
 *
 * @return The execution time of the sort method
 */
unsigned int measure_array_sorting(unsigned int arr[], unsigned int size) {

	auto t1 = chrono::high_resolution_clock::now();

	sort(arr, arr + size);

	auto t2 = chrono::high_resolution_clock::now();

	auto ms_int = duration_cast<milliseconds>(t2 - t1);

	return ms_int.count();
}

/**
 * Format a number with a thousand separator
 *
 * @param n	An unsigned integer
 * @return A string presents the number with a thousand separator
 */
string format_number(unsigned int n) {

	string s = to_string(n);

	int index = s.length() - 3;

	while (index > 0) {
		s.insert(index, THOUDSAND_SEPARATOR);
		index -= 3;
	}

	return s;
}

/**
 * Print the execution time to the console for one kind of array size
 *
 * @param n The array size
 * @param execution_time A two-dimensional array to store the execution time.
 * 	The row subscript is the kind of array orders.
 * 	The column subscript is the number of arrays to be tested.
 *
 * 	@return N/A
 */
void print_execution_time(unsigned int n,
		unsigned int execution_time[NUMBER_OF_ARRAY_ORDERING][NUMBER_OF_ARRAYS_PER_SIZE]) {

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

	// Print a line to indicate size of arrays
	cout << "n=" << format_number(n) << endl;

	// Print table header border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	// Print row header
	cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_WIDTH)
			<< BLANK_CHARACTER;

	for (unsigned int i = 0; i < NUMBER_OF_ARRAYS_PER_SIZE; i++) {
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
	for (unsigned int i = 0; i < NUMBER_OF_ARRAY_ORDERING; i++) {
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

/**
 * Measure the execution time for one kind of array size.
 *
 * @param The array size among 3 kinds of array length to be tested.
 *
 * @return N/A
 */
void measure_sorting(unsigned int n) {

	unsigned int arr[n];

	unsigned int execution_time[NUMBER_OF_ARRAY_ORDERING][NUMBER_OF_ARRAYS_PER_SIZE];

	for (unsigned int j = 0; j < NUMBER_OF_ARRAYS_PER_SIZE; j++) {

		for (unsigned int k = 0; k < n; k++) {
			arr[k] = rand();
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

/**
 * Measure the efficiency of the sort method implemented in the library <algorithm> mentioned in the efficiency_measure.h
 *
 * @param N/A
 *
 * @return N/A
 */
void measure_sorting_efficiency() {

	const unsigned int NUMBER_OF_ARRAY_SIZES = 3;

	unsigned int array_sizes[NUMBER_OF_ARRAY_SIZES];

	array_sizes[0] = 100 * 1000;
	array_sizes[1] = 1000 * 1000;
	array_sizes[2] = 10000 * 1000;

	for (unsigned i = 0; i < NUMBER_OF_ARRAY_SIZES; i++) {
		measure_sorting(array_sizes[i]);
		cout << endl;
	}
}

