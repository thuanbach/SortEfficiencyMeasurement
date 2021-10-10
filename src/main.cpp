//============================================================================
// Name        : CS700Assignment2.cpp
// Author      : Thuan Bach
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int sin(int x);
int cos(int x);


void verifySinMethod(int degree, int expected) {
	int actual = sin(degree);

	cout << "sin(" << degree << ")" << " is " << actual << ", expected "
			<< expected << ": ";

	if (actual == expected) {
		cout << "Pass";
	} else {
		cout << "Fail";
	}

	cout << endl;
}

void runTestSuiteForSinMethod() {
	cout << "******Start running test cases for sin method*****" << endl;

	cout << "1. **Test PATH Coverage**" << endl;

	verifySinMethod(-30, 4999);

	verifySinMethod(-60, 8660);

	verifySinMethod(-120, 8660);

	verifySinMethod(-160, 3419);

	verifySinMethod(-210, -4999);

	verifySinMethod(-240, -8660);

	verifySinMethod(30, 4999);

	verifySinMethod(60, 8660);

	verifySinMethod(120, 8660);

	verifySinMethod(160, 3419);

	verifySinMethod(210, -4999);

	verifySinMethod(240, -8660);

	// Test Boundaries
	cout << "2. **Test Boundaries**" << endl;

	verifySinMethod(0, 0);

	verifySinMethod(360, 0);

	verifySinMethod(45, 7071);

	verifySinMethod(-45, 7071);

	verifySinMethod(-90, 9999);

	verifySinMethod(90, 9999);

	verifySinMethod(180, 0);

	verifySinMethod(-180, 0);

	verifySinMethod(-405, 7071);
	verifySinMethod(405, 7071);

	verifySinMethod(-450, 9999);
	verifySinMethod(450, 9999);

	verifySinMethod(-540, 0);
	verifySinMethod(540, 0);

	verifySinMethod(-720, 0);
	verifySinMethod(720, 0);

	cout << "*****End test suite sin method****" << endl;
	cout << endl;

}

void verifyCosMethod(int degree, int expected) {
	int actual = sin(degree);

	cout << "cos(" << degree << ")" << " is " << actual << ", expected "
			<< expected << ": ";

	if (actual == expected) {
		cout << "Pass";
	} else {
		cout << "Fail";
	}

	cout << endl;
}

void runTestSuiteForCosMethod() {
	cout << "******Start running test cases for cos method*****" << endl;

	// Test Path Coverage
	cout << "1. Test PATH Coverage" << endl;

	verifyCosMethod(-120, 8660);
	verifyCosMethod(-150, 4999);
	verifyCosMethod(-210, -4999);
	verifyCosMethod(-250, -9395);
	verifyCosMethod(-300, -8660);
	verifyCosMethod(-330, -4999);
	verifyCosMethod(-60, 8660);
	verifyCosMethod(-30, 4999);
	verifyCosMethod(30, 4999);
	verifyCosMethod(70, 9395);
	verifyCosMethod(120, 8660);
	verifyCosMethod(150, 4999);

	cout << "2. **Test Boundaries**" << endl;
	// Test boundaries conditions
	verifyCosMethod(-90,9999);
	verifyCosMethod(270,9999);
	verifyCosMethod(-45,7071);
	verifyCosMethod(-135,7071);
	verifyCosMethod(-180,0);
	verifyCosMethod(0,0);
	verifyCosMethod(90,9999);
	verifyCosMethod(-270,-9999);
	verifyCosMethod(-495,7071);
	verifyCosMethod(315,7071);
	verifyCosMethod(-540,0);
	verifyCosMethod(360,0);
	verifyCosMethod(-630,-9999);
	verifyCosMethod(450,9999);
	verifyCosMethod(-810,9999);
	verifyCosMethod(630,-9999);




	cout << "*****End test suite cos method****" << endl;
}

int main() {

	runTestSuiteForSinMethod();

	runTestSuiteForCosMethod();

	return 0;
}
