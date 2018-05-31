#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace BigNumbersLibrary {
	class BigNumber {
	public:
		bool positive;

		BigNumber();
		BigNumber(long long);
		BigNumber(string);
		BigNumber(BigNumber& const);

		static BigNumber Add(BigNumber &);
		static BigNumber Subtract(BigNumber &);
		static BigNumber Multiply(BigNumber &);
		static BigNumber Divide(BigNumber &);
		static BigNumber Mod(BigNumber &);

		BigNumber operator + (BigNumber const &);
		BigNumber operator + (long long const &);

		BigNumber operator - (BigNumber const &);
		BigNumber operator - (BigNumber const &);

		BigNumber operator * (BigNumber const &);
		BigNumber operator * (BigNumber const &);
		
		BigNumber operator / (BigNumber const &);
		BigNumber operator / (BigNumber const &);
		
		BigNumber operator % (BigNumber const &);
		BigNumber operator % (BigNumber const &);
		
		BigNumber operator = (long long const &);

		void print();
	};
}