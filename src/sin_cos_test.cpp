/*
 * sin_cos_test.cpp
 *
 *  Created on: Oct 10, 2021
 *      Author: Thuan Bach
 */

#include <iostream>
#include <iomanip>

using namespace std;

int sin(int x);
int cos(int x);

const unsigned int MAXIUM_OF_TEST_CASES = 100;

const string SIN_METHOD = "sin";
const string COS_METHOD = "cos";

struct TestDataSet {
	int degrees[MAXIUM_OF_TEST_CASES];
	int expected_results[MAXIUM_OF_TEST_CASES];
	int actual_results[MAXIUM_OF_TEST_CASES];
};

void verifyResultAndPrintToConsole(string methodName,
		const TestDataSet &testData, unsigned int nr_of_tests) {
	unsigned int PADDING = 10;
	unsigned int FIRST_COLUMN_PADDING = 8;
	unsigned int SECOND_COLUMN_PADDING = 12;
	unsigned int TOTAL_INNER_VERTICAL_BORDER_CHARACTER = 4;

	const char PLUS_CHARACTER = '+';
	const char TABLE_HORIZONTAL_BORDER_CHARACTER = '-';
	const char TABLE_VERTICAL_BORDER_CHARACTER = '|';
	const char BLANK_CHARACTER = ' ';

	const string PASS = "Pass";
	const string FAIL = "Fail";

	unsigned int TOTAL_TABLE_WIDTH = FIRST_COLUMN_PADDING
			+ SECOND_COLUMN_PADDING + PADDING * 3
			+ TOTAL_INNER_VERTICAL_BORDER_CHARACTER;

	// Create the table header's horizontal line border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_PADDING)
			<< left << "No." << TABLE_VERTICAL_BORDER_CHARACTER
			<< setw(SECOND_COLUMN_PADDING) << left << "Test case"
			<< TABLE_VERTICAL_BORDER_CHARACTER << setw(PADDING) << left
			<< "Actual" << TABLE_VERTICAL_BORDER_CHARACTER << setw(PADDING)
			<< left << "Expected" << TABLE_VERTICAL_BORDER_CHARACTER
			<< setw(PADDING) << left << "Pass/Fail"
			<< TABLE_VERTICAL_BORDER_CHARACTER << endl;

	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	for (unsigned int i = 0; i < nr_of_tests; i++) {
		bool passed = testData.actual_results[i]
				== testData.expected_results[i];

		cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_PADDING)
				<< to_string(i + 1) << TABLE_VERTICAL_BORDER_CHARACTER
				<< setw(SECOND_COLUMN_PADDING) << left
				<< methodName + "(" + to_string(testData.degrees[i]) + ")"
				<< TABLE_VERTICAL_BORDER_CHARACTER << setw(PADDING) << left
				<< testData.actual_results[i] << TABLE_VERTICAL_BORDER_CHARACTER
				<< setw(PADDING) << left << testData.expected_results[i];

		cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(PADDING) << left
				<< (passed ? PASS : FAIL) << TABLE_VERTICAL_BORDER_CHARACTER
				<< endl;

	}

	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;
}

void runTestSuite(string method_name, TestDataSet &testDataSet,
		unsigned int nr_of_tests) {

	for (unsigned int i = 0; i < nr_of_tests; i++) {
		if (method_name == SIN_METHOD) {
			testDataSet.actual_results[i] = sin(testDataSet.degrees[i]);
		} else {
			testDataSet.actual_results[i] = cos(testDataSet.degrees[i]);
		}
	}

	verifyResultAndPrintToConsole(method_name, testDataSet, nr_of_tests);
}

TestDataSet initSinDataSetForPathCoverage() {
	TestDataSet sinTestDataSet;

	sinTestDataSet.degrees[0] = -30;
	sinTestDataSet.expected_results[0] = 4999;

	sinTestDataSet.degrees[1] = -60;
	sinTestDataSet.expected_results[1] = 8660;

	sinTestDataSet.degrees[2] = -120;
	sinTestDataSet.expected_results[2] = 8660;

	sinTestDataSet.degrees[3] = -160;
	sinTestDataSet.expected_results[3] = 3419;

	sinTestDataSet.degrees[4] = -210;
	sinTestDataSet.expected_results[4] = -4999;

	sinTestDataSet.degrees[5] = -240;
	sinTestDataSet.expected_results[5] = -8660;

	sinTestDataSet.degrees[6] = 30;
	sinTestDataSet.expected_results[6] = 4999;

	sinTestDataSet.degrees[7] = 60;
	sinTestDataSet.expected_results[7] = 8660;

	sinTestDataSet.degrees[8] = 120;
	sinTestDataSet.expected_results[8] = 8660;

	sinTestDataSet.degrees[9] = 160;
	sinTestDataSet.expected_results[9] = 3419;

	sinTestDataSet.degrees[10] = 210;
	sinTestDataSet.expected_results[10] = -4999;

	sinTestDataSet.degrees[11] = 240;
	sinTestDataSet.expected_results[11] = -8660;

	return sinTestDataSet;
}

TestDataSet initSinDataSetForBoundaryConditions() {
	TestDataSet sinTestDataSet;

	sinTestDataSet.degrees[0] = 0;
	sinTestDataSet.expected_results[0] = 0;

	sinTestDataSet.degrees[1] = 360;
	sinTestDataSet.expected_results[1] = 0;

	sinTestDataSet.degrees[2] = 45;
	sinTestDataSet.expected_results[2] = 7071;

	sinTestDataSet.degrees[3] = -45;
	sinTestDataSet.expected_results[3] = 7071;

	sinTestDataSet.degrees[4] = -90;
	sinTestDataSet.expected_results[4] = 9999;

	sinTestDataSet.degrees[5] = 90;
	sinTestDataSet.expected_results[5] = 9999;

	sinTestDataSet.degrees[6] = 180;
	sinTestDataSet.expected_results[6] = 0;

	sinTestDataSet.degrees[7] = -180;
	sinTestDataSet.expected_results[7] = 0;

	sinTestDataSet.degrees[8] = -405;
	sinTestDataSet.expected_results[8] = 7071;

	sinTestDataSet.degrees[9] = 405;
	sinTestDataSet.expected_results[9] = 7071;

	sinTestDataSet.degrees[10] = -450;
	sinTestDataSet.expected_results[10] = 9999;

	sinTestDataSet.degrees[11] = 450;
	sinTestDataSet.expected_results[11] = 9999;

	sinTestDataSet.degrees[12] = -540;
	sinTestDataSet.expected_results[12] = 0;

	sinTestDataSet.degrees[13] = 540;
	sinTestDataSet.expected_results[13] = 0;

	sinTestDataSet.degrees[14] = -720;
	sinTestDataSet.expected_results[14] = 0;

	sinTestDataSet.degrees[15] = 720;
	sinTestDataSet.expected_results[15] = 0;

	return sinTestDataSet;
}

void testSinMethodWithBoundaryCondition() {
	unsigned int number_of_tests = 15;

	TestDataSet sinTestDataSet = initSinDataSetForBoundaryConditions();

	runTestSuite(SIN_METHOD, sinTestDataSet, number_of_tests);

}

void testSinMethodWithPathCoverage() {
	unsigned int number_of_tests = 12;

	TestDataSet sinTestDataSet = initSinDataSetForPathCoverage();

	runTestSuite(SIN_METHOD, sinTestDataSet, number_of_tests);
}

TestDataSet initCosDataSetFromSinDataSet(const TestDataSet &sinDataSet,
		unsigned int number_of_tests) {

	TestDataSet cosDataSet;

	/**
	 * cos(x) = sin(90+x). Thus, to initiate the test data set for cosine method,
	 * we will use the path coverage data set for sin method, then for each data, we minus 90.
	 * That will ensure that all path coverage for the cosine method will be covered as the sin
	 * method's.
	 */
	for (unsigned int i = 0; i < number_of_tests; i++) {
		cosDataSet.degrees[i] = sinDataSet.degrees[i] - 90;
		cosDataSet.expected_results[i] = sinDataSet.expected_results[i];
	}

	return cosDataSet;
}

void testCosMethodWithPathCoverage() {
	const unsigned int NUBMER_OF_TESTS = 12;

	TestDataSet sinDataSet = initSinDataSetForPathCoverage();

	TestDataSet costDataSet = initCosDataSetFromSinDataSet(sinDataSet,
			NUBMER_OF_TESTS);

	runTestSuite(COS_METHOD, costDataSet, 12);

}

void testCosMethodWithBoudaryConditions() {
	const unsigned int NUBMER_OF_TESTS = 15;

	TestDataSet sinDataSet = initSinDataSetForBoundaryConditions();

	TestDataSet costDataSet = initCosDataSetFromSinDataSet(sinDataSet,
			NUBMER_OF_TESTS);

	runTestSuite(COS_METHOD, costDataSet, NUBMER_OF_TESTS);

}

void runTestSuiteForSinMethod() {
	testSinMethodWithPathCoverage();

	testSinMethodWithBoundaryCondition();
}

void runTestSuiteForCosMethod() {
	testCosMethodWithPathCoverage();

	testCosMethodWithBoudaryConditions();
}

