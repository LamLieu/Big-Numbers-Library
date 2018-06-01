#include "BigNumbersLibrary.h"
#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

BigNumber::BigNumber() : digits(1), numberVector(vector<int>({ 0 })) {}
BigNumber::BigNumber(int num) {
	// Counts number of digits
	do {
		int temp = num;
		digits++;
		num /= 10;
	} while (num != 0);

	if (num < 0) {
		positive = false;
	}
}
BigNumber::BigNumber(string s) {
	digits = s.length();
	int index = 0;
	if (s[0] != '-') {
		positive = false;
		digits--;
		index = 1;
	}

	for (; index < digits; index++) {
		numberVector.push_back(s[index]);
	}
}

BigNumber::BigNumber(vector<int> numVector) {
	numberVector = numVector;
}

BigNumber BigNumber::operator+ (BigNumber const &num) {
	BigNumber result;
	int carry = 0;
	int firstNumberIndex = numberVector.size();
	int secondNumberIndex = num.numberVector.size();

	for (int index = 0; index < digits; index++) {
		int addedElements = numberVector.at(index) + num.numberVector.at(index) + carry;
		if (addedElements > 9) {
			carry = 1;
		}
		result.numberVector.at(index) %= 10;
	}
	return result;
}

BigNumber BigNumber::operator- (BigNumber const &num) {
	vector<int> numberSubtracted;
	// Default assignments
	vector<int> largeVector = num.numberVector,
		smallVector = numberVector;
	int largestNumberSize = num.numberVector.size(),
		smallestNumberSize = numberVector.size();
	// Assignments changed based on condition
	if (numberVector.size() > num.numberVector.size()) {
		largestNumberSize = numberVector.size();
		smallestNumberSize = num.numberVector.size();
		largeVector = numberVector;
		smallVector = num.numberVector;
	}

	for (int index = 0; index < largestNumberSize; index++)
	{
		int borrow = 0, subtractResult, smallVectorElement;
		// Sets small vector element at index based on the small vector's size
		if (index >= smallestNumberSize) {
			smallVectorElement = 0;
		}
		else {
			smallVectorElement = smallVector.at(index);
		}

		subtractResult = largeVector.at(index) - borrow - smallVectorElement;
		borrow = 0;
		if (subtractResult < 0)
		{
			subtractResult += 10;
			borrow = 1;
		}
		largeVector.at(index) = subtractResult;
	}
	numberSubtracted = largeVector;
	BigNumber result(numberSubtracted);
	return result;
}

BigNumber BigNumber::operator* (BigNumber const &num) {
	vector<int> product(numberVector.size() + num.numberVector.size());
	// Default assignments
	vector<int> largeVector = num.numberVector, 
				smallVector = numberVector;
	int	largestNumberSize = num.numberVector.size(),
		smallestNumberSize = numberVector.size();
	// Assignments changed based on condition
	if (numberVector.size() > num.numberVector.size()) {
		largestNumberSize = numberVector.size();
		smallestNumberSize = num.numberVector.size();
		largeVector = numberVector;
		smallVector = num.numberVector;
	}

	for (int i = 0; i < largestNumberSize; i++) {
		int carry = 0;
		for (int j = 0; j < smallestNumberSize; j++) {
			product.at(i + j) += carry + smallVector.at(j) * smallVector.at(i);
			carry = product[i + j] / 10;
			product.at(i + j) = product.at(i + j) % 10;
		}
		product.at(i + largestNumberSize) += carry;
	}
	BigNumber result(product);
	return result;
}

BigNumber BigNumber::operator/ (BigNumber const &num) {
	BigNumber result;
	int carry = 0, 
		temp,
		sizeNumOne = this->numberVector.size(), 
		sizeNumTwo = num.numberVector.size();
	// reverse order
	reverse(numberVector.begin(), numberVector.end());
	reverse(num.numberVector.begin(), num.numberVector.end());
	for (int i = 0; i < sizeNumTwo; i++) {
		temp = numberVector.at(i) - (num.numberVector.at(i) - carry);
		if (temp < 0) {
			temp += 10;
			carry = 1;
		}
		else
			carry = 0;
		result.numberVector.push_back(temp);
	}
	for (int i = sizeNumTwo; i < sizeNumOne; i++) {
		temp = this->numberVector.at(i) - carry;
		if (temp < 0) {
			temp += 10;
			carry = 1;
		}
		else
			carry = 0;
		result.numberVector.push_back(temp);
	}
	reverse(result.numberVector.begin(), result.numberVector.end());
	return result;
}

BigNumber BigNumber::operator% (BigNumber const &num) {
	int remainder = 0;
	BigNumber tempNum = num;
	while (true) {
		BigNumber subtractedNumber = *this - tempNum;
		remainder++;
		if (numberVector.size() > tempNum.numberVector.size()) {
			BigNumber result(remainder);
			return result;
		}
		tempNum = subtractedNumber;
	}
}

BigNumber BigNumber::operator=(BigNumber const & num) {
	this->numberVector = num.numberVector;
	return *this;
}

void BigNumber::print() {
	for (int index = 0; index < numberVector.size(); index++) {
		cout << numberVector.at(index);
	}
	cout << endl;
}