/**
 * main.cpp
 *
 * Created on: Oct 11, 2021
 *
 * Author: Thuan Bach.
 *
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "sin_cos_test.h"

/**
 *
 * The main file of the application.
 * It runs 2 test suites that implements a white-box test for sin(x) and cos(x) method
 *
 * @param N/A
 * @return 0
 */
int main() {


	runTestSuiteForSinMethod();

	runTestSuiteForCosMethod();

	return 0;
}
