/*
 *  sin_cos_test.cpp
 *
 *  Created on: October 10, 2021
 *
 *	Author: Thuan Bach
 *
 *  The purpose of this module is to implement a white-box test for two functionalities defined sin_cos.cpp: sin(x), and cos(x)
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

// Declare the  method sin(x) to be tested and implemented in sin_cos.cpp
int sin(int x);

// Declare the  method sin(x) to be tested and implemented in sin_cos.cpp
int cos(int x);

// Define the maximum of test cases in a TestDataSet object
const unsigned int MAXIMUM_OF_TEST_CASES = 100;

// Define a constant string for the sine method's name
const string SIN_METHOD = "sin";

// Define a constant string for the cosine method's name
const string COS_METHOD = "cos";

// Number of tests for path coverage
const unsigned int NUBMER_OF_TESTS_FOR_PATH_COVERAGE = 12;

// Number of tests for boundary conditions
const unsigned int NUBMER_OF_TESTS_FOR_BOUDARY_CONDITION = 16;

/**
 * Define a object to store a test data set.
 * It includes three arrays defined below
 */
struct TestDataSet {
	/**
	 * An array to store degrees to be tested
	 */
	int degrees[MAXIMUM_OF_TEST_CASES];

	/**
	 * An array to store the expected results for each degree tested
	 */
	int expected_results[MAXIMUM_OF_TEST_CASES];

	/**
	 * An array to store the actual results for each degree tested
	 */
	int actual_results[MAXIMUM_OF_TEST_CASES];
};

/**
 * Verify the test result by comparing the expected result and the actual result, then print the result to the console in the table format
 *
 * @param methodName The method that is used to execute the test data: sin(x) or cos(x)
 * @param testData	 The TestDataSet object that holds the test data set and the result
 *
 * @return N/A
 */
void verifyResultAndPrintToConsole(string &methodName,
		const TestDataSet &testData, unsigned int nr_of_tests) {

	const unsigned int PADDING = 10;
	const unsigned int FIRST_COLUMN_PADDING = 8;
	const unsigned int SECOND_COLUMN_PADDING = 12;
	const unsigned int TOTAL_INNER_VERTICAL_BORDER_CHARACTER = 4;

	const char PLUS_CHARACTER = '+';
	const char TABLE_HORIZONTAL_BORDER_CHARACTER = '-';
	const char TABLE_VERTICAL_BORDER_CHARACTER = '|';
	const char BLANK_CHARACTER = ' ';

	const string NO_HEADER = "No.";
	const string TEST_CASE_NAME_HEADER = "Test case";
	const string ACTUAL_RESULT_HEADER = "Actual";
	const string EXPECTED_RESULT_HEADER = "Expected";
	const string PASS_FAIL_HEADER = "Expected";

	const string PASS = "Pass";
	const string FAIL = "Fail";

	unsigned int TOTAL_TABLE_WIDTH = FIRST_COLUMN_PADDING
			+ SECOND_COLUMN_PADDING + PADDING * 3
			+ TOTAL_INNER_VERTICAL_BORDER_CHARACTER;

	// Create the table header's border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	// Create headers
	cout << TABLE_VERTICAL_BORDER_CHARACTER << setw(FIRST_COLUMN_PADDING)
			<< left << NO_HEADER << TABLE_VERTICAL_BORDER_CHARACTER
			<< setw(SECOND_COLUMN_PADDING) << left << TEST_CASE_NAME_HEADER
			<< TABLE_VERTICAL_BORDER_CHARACTER << setw(PADDING) << left
			<< ACTUAL_RESULT_HEADER << TABLE_VERTICAL_BORDER_CHARACTER
			<< setw(PADDING) << left << EXPECTED_RESULT_HEADER
			<< TABLE_VERTICAL_BORDER_CHARACTER << setw(PADDING) << left
			<< PASS_FAIL_HEADER << TABLE_VERTICAL_BORDER_CHARACTER << endl;

	// Close table header with a border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;

	// Print result rows
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

	// Close the table with a border
	cout << PLUS_CHARACTER << setfill(TABLE_HORIZONTAL_BORDER_CHARACTER)
			<< setw(TOTAL_TABLE_WIDTH) << TABLE_HORIZONTAL_BORDER_CHARACTER
			<< PLUS_CHARACTER << setfill(BLANK_CHARACTER) << endl;
}

/**
 * Execute the test data defined in the TestDataSet object by the method defined in the parameter.
 * Then store the result in the property "actual_results" of the TestDataSet object
 *
 * @param method_name The method will be invoked for the test: cos(x) or sin(x)
 * @param testDataSet The object to store degrees to be tested and the result of execution.
 *
 * @return N/A
 */
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

/**
 *  Initiate the test data set for the sin method with path coverage
 *  @param N/A
 *  @return a TestDataSet object that contains a list of degrees to be tested and expected results
 */
TestDataSet initSinDataSetForPathCoverage() {
	TestDataSet sinTestDataSet;

	sinTestDataSet.degrees[0] = -30;
	sinTestDataSet.expected_results[0] = -4999;

	sinTestDataSet.degrees[1] = -60;
	sinTestDataSet.expected_results[1] = -8660;

	sinTestDataSet.degrees[2] = -120;
	sinTestDataSet.expected_results[2] = -8660;

	sinTestDataSet.degrees[3] = -160;
	sinTestDataSet.expected_results[3] = -3419;

	sinTestDataSet.degrees[4] = -210;
	sinTestDataSet.expected_results[4] = 4999;

	sinTestDataSet.degrees[5] = -240;
	sinTestDataSet.expected_results[5] = 8660;

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

/**
 * Initiate test data set for the sin method with path coverage
 *
 *  @param N/A
 *  @return a TestDataSet object that contains a list of degrees to be tested and expected results
 */

TestDataSet initSinDataSetForBoundaryConditions() {
	TestDataSet sinTestDataSet;

	sinTestDataSet.degrees[0] = 0;
	sinTestDataSet.expected_results[0] = 0;

	sinTestDataSet.degrees[1] = 360;
	sinTestDataSet.expected_results[1] = 0;

	sinTestDataSet.degrees[2] = 45;
	sinTestDataSet.expected_results[2] = 7071;

	sinTestDataSet.degrees[3] = -45;
	sinTestDataSet.expected_results[3] = -7071;

	sinTestDataSet.degrees[4] = -90;
	sinTestDataSet.expected_results[4] = -9999;

	sinTestDataSet.degrees[5] = 90;
	sinTestDataSet.expected_results[5] = 9999;

	sinTestDataSet.degrees[6] = 180;
	sinTestDataSet.expected_results[6] = 0;

	sinTestDataSet.degrees[7] = -180;
	sinTestDataSet.expected_results[7] = 0;

	sinTestDataSet.degrees[8] = -405;
	sinTestDataSet.expected_results[8] = -7071;

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

/**
 *	Test the sine method with boundary conditions
 *
 *	@param N/A
 *	@return N/A
 */
void testSinMethodWithBoundaryConditions() {
	cout << "Test sin(x) with boundary conditions" << endl;

	TestDataSet sinTestDataSet = initSinDataSetForBoundaryConditions();

	runTestSuite(SIN_METHOD, sinTestDataSet,
			NUBMER_OF_TESTS_FOR_BOUDARY_CONDITION);

	cout << endl;

}

/**
 *	Test the sine method with path coverage
 *
 *	@param N/A
 *	@return N/A
 */
void testSinMethodWithPathCoverage() {

	cout << "Test sin(x) with path coverage" << endl;

	TestDataSet sinTestDataSet = initSinDataSetForPathCoverage();

	runTestSuite(SIN_METHOD, sinTestDataSet, NUBMER_OF_TESTS_FOR_PATH_COVERAGE);

	cout << endl;
}

/**
 * Initiate the cosine's test data set from the sine's data set.
 *
 * cos(x) = sin(90+x). Thus, to initiate the test data set for cosine method,
 * We will use the test data set for sin method. For each sine test data, we minus 90.
 * That will ensure that all path coverage for the cosine method will be covered as the sine
 * method's.
 *
 * @param TestDataSet The sine's test data set
 * @param number_of_tests Number of tests
 *
 * @returns The cosine's data set
 */
TestDataSet initCosDataSetFromSinDataSet(const TestDataSet &sinDataSet,
		unsigned int number_of_tests) {

	TestDataSet cosDataSet;

	for (unsigned int i = 0; i < number_of_tests; i++) {
		cosDataSet.degrees[i] = sinDataSet.degrees[i] - 90;
		cosDataSet.expected_results[i] = sinDataSet.expected_results[i];
	}

	return cosDataSet;
}

/**
 * Test the cosine method with path coverage
 *
 *  @param N/A
 *  @return N/A
 *
 */
void testCosMethodWithPathCoverage() {

	cout << "Test cos(x) with path coverage" << endl;

	TestDataSet sinDataSet = initSinDataSetForPathCoverage();

	TestDataSet costDataSet = initCosDataSetFromSinDataSet(sinDataSet,
			NUBMER_OF_TESTS_FOR_PATH_COVERAGE);

	runTestSuite(COS_METHOD, costDataSet, NUBMER_OF_TESTS_FOR_PATH_COVERAGE);

	cout << endl;

}

/**
 * Test the cosine method with boundary conditions
 *
 *  @param N/A
 *  @return N/A
 *
 */
void testCosMethodWithBoudaryConditions() {

	cout << "Test cos(x) with boundary conditions" << endl;

	TestDataSet sinDataSet = initSinDataSetForBoundaryConditions();

	TestDataSet cosDataSet = initCosDataSetFromSinDataSet(sinDataSet,
			NUBMER_OF_TESTS_FOR_BOUDARY_CONDITION);

	runTestSuite(COS_METHOD, cosDataSet, NUBMER_OF_TESTS_FOR_BOUDARY_CONDITION);

	cout << endl;

}

/**
 *
 * Implement a white-box test for the method sin(x)
 * It includes 2 kinds of test cases: one for path coverage and one for boundary conditions
 *
 *  @param N/A
 *  @return N/A
 */
void runTestSuiteForSinMethod() {
	testSinMethodWithPathCoverage();

	testSinMethodWithBoundaryConditions();
}

/**
 *
 * Implement a white-box test for the method cos(x).
 * It includes 2 kinds of test cases: one for path coverage and one for boundary conditions
 *
 *  @param N/A
 *  @return N/A
 */
void runTestSuiteForCosMethod() {
	testCosMethodWithPathCoverage();

	testCosMethodWithBoudaryConditions();
}

