#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace BigNumbersLibrary {
	class BigNumber {
	public:
		BigNumber();

		static BigNumber Add(BigNumber &, BigNumber &);
		static BigNumber Subtract(BigNumber &, BigNumber &);
		static BigNumber Multiply(BigNumber &, BigNumber &);
		static BigNumber Divide(BigNumber &, BigNumber &);
		static BigNumber Mod(BigNumber &, BigNumber &);

		BigNumber operator + (BigNumber const &, BigNumber const &);
		BigNumber operator - (BigNumber const &, BigNumber const &);
		BigNumber operator * (BigNumber const &, BigNumber const &);
		BigNumber operator / (BigNumber const &, BigNumber const &);
		BigNumber operator % (BigNumber const &, BigNumber const &);

		void print();
	};
}