#include "BigNumbersLibrary.h"
#include "stdafx.h"
#include <vector>
using namespace std;

namespace BigNumbersLibrary {
	class BigNumber {
	public:
		int sign;
		vector<int> bigNum;
		
		BigNumber() : sign(1) {}
		BigNumber(long long num) {
			*this = num;
		}

		static BigNumber Add(BigNumber a, BigNumber b) {
			return a + b;
		}
		static BigNumber Subtract(BigNumber a, BigNumber b) {
			return a - b;
		}
		static BigNumber Multiply(BigNumber a, BigNumber b) {
			return a * b;
		}
		static BigNumber Divide(BigNumber a, BigNumber b) {
			return a / b;
		}
		static BigNumber Mod(BigNumber a, BigNumber b) {
			return a % b;
		}

		friend BigNumber operator + (BigNumber const &, BigNumber const &) {
		
		}
		friend BigNumber operator - (BigNumber const &, BigNumber const &) {
			
		}
		friend BigNumber operator * (BigNumber const &, BigNumber const &) {
			
		}
		friend BigNumber operator / (BigNumber const &, BigNumber const &) {
			
		}
		friend BigNumber operator % (BigNumber const &, BigNumber const &) {
			
		}
		friend void operator = (long long num) {
		
		}

	};
}