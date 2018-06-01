#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class BigNumber {
private:
	int digits;
	bool positive = true;
	vector<int> numberVector;

public:
	// Constructors
	BigNumber();
	BigNumber(int);
	BigNumber(string);
	BigNumber(vector<int>);

	// Addition
	BigNumber operator+(BigNumber const &);

	// Subtraction
	BigNumber operator-(BigNumber const &);

	// Multiplication
	BigNumber operator*(BigNumber const &);

	// Division
	BigNumber operator/(BigNumber const &);

	// Mod
	BigNumber operator%(BigNumber const &);

	BigNumber operator=(BigNumber const &);

	void print();
};