/*
 * sin_cos_test.h
 *
 * Created on: Oct 11, 2021
 *
 * Author: Thuan Bach
 *
 * The purpose of this module is to implement a white-box test for two functionalities defined sin_cos.cpp: sin(x), and cos(x)
 *
 * For each method, there is a test suite that includes two kinds of test cases: one for path coverage and the other for boundary conditions
 *
 * For each kind of test cases, the result will print to the console in a table format like below
 *
 *  +------------------------------------------------------+
 *	|No.     |Test case   |Actual    |Expected  |Pass/Fail |
 *	+------------------------------------------------------+
 *	|1       |sin(-30)    |4999      |-4999     |Fail      |
 *	|2       |sin(60)     |8660      | 8660     |Pass      |
 *	+------------------------------------------------------+
 */

#ifndef SIN_COS_TEST_H_
#define SIN_COS_TEST_H_

/**
 *
 * Implement a white-box test for the method sin(x).
 * It includes 2 kinds of test cases: one for path coverage and one for boundary conditions
 *
 *  @param N/A
 *  @return N/A
 *
 */
void runTestSuiteForSinMethod();


/**
 * Implement a white-box test for the method cos(x).
 * It includes 2 kinds of test cases: one for path coverage and one for boundary conditions
 *
 *  @param N/A
 *  @return N/A
 *
 */
void runTestSuiteForCosMethod();

#endif /* SIN_COS_TEST_H_ */
