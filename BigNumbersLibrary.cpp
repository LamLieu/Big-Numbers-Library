#include "BigNumbersLibrary.h"
#include "stdafx.h"
#include <vector>
using namespace std;

namespace BigNumbersLibrary {
	BigNumber::BigNumber() {
		
	}
	BigNumber::BigNumber(long long num) {
		positive = true;
	}
	BigNumber::BigNumber(string s) {
		positive = true;
	}
	BigNumber::BigNumber(BigNumber& const) {
		positive = true;
	}

	BigNumber BigNumber::Add(BigNumber &) {}
	BigNumber BigNumber::Subtract(BigNumber &) {}
	BigNumber BigNumber::Multiply(BigNumber &) {}
	BigNumber BigNumber::Divide(BigNumber &) {}
	BigNumber BigNumber::Mod(BigNumber &) {}

	BigNumber BigNumber::operator + (BigNumber const & bigNum) {

	}
	BigNumber BigNumber::operator + (long long const & num) {}

	BigNumber BigNumber::operator - (BigNumber const &) {}
	BigNumber BigNumber::operator - (BigNumber const &) {}

	BigNumber BigNumber::operator * (BigNumber const &) {}
	BigNumber BigNumber::operator * (BigNumber const &) {}

	BigNumber BigNumber::operator / (BigNumber const &) {}
	BigNumber BigNumber::operator / (BigNumber const &) {}

	BigNumber BigNumber::operator % (BigNumber const &) {}
	BigNumber BigNumber::operator % (BigNumber const &) {}

	BigNumber BigNumber::operator = (long long const &) {}
}