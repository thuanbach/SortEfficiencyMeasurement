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


void verifySinMethod(int degree, int expected){
	int actual = sin(degree);

	cout << "sin(" <<  degree  << ")" << " is " << actual <<", expected " << expected << ": ";

	if (actual == expected) {
		cout << "Pass";
	} else {
		cout << "Fail";
	}

	cout << endl;
}


void verifyCosMethod(int degree, int expected){
	int actual = sin(degree);

	cout << "cos(" <<  degree  << ")" << " is " << actual <<", expected " << expected << ": ";

	if (actual == expected) {
		cout << "Pass";
	} else {
		cout << "Fail";
	}

	cout << endl;
}

void ruTestSuiteForSinMethod() {
	cout << "******Start running test cases for sin method*****" << endl;

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

	cout << "*****End test suite sin method****" << endl;

}


void ruTestSuiteForCosMethod() {
	cout << "******Start running test cases for cos method*****" << endl;
	verifyCosMethod(-30, 4999);

	verifyCosMethod(-60, 8660);

	verifyCosMethod(-120, 8660);

	verifyCosMethod(-160, 3419);

	verifyCosMethod(-210, -4999);

	verifyCosMethod(-240, -8660);


	verifyCosMethod(30, 4999);

	verifyCosMethod(60, 8660);

	verifyCosMethod(120, 8660);

	verifyCosMethod(160, 3419);

	verifyCosMethod(210, -4999);

	verifyCosMethod(240, -8660);

	cout << "*****End test suite cos method****" << endl;
}



int main() {

	ruTestSuiteForSinMethod();

	ruTestSuiteForCosMethod();


	return 0;
}
