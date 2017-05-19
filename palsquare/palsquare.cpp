/*
   PROB: palsquare
   LANG: C++11
 */

#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
const int MAX_N = 300;

string numBaseN(int num, int base) {
	string numInBase = "";
	char digits[20] = "0123456789ABCDEFGHI";

	while(num > 0) {
		int remainder = num % base;
		numInBase = digits[remainder] + numInBase;
		num -= remainder;
		num /= base;
	}

	return numInBase;
}

bool isPalindrome(string possiblePalindrome) {
	string backwardsString = "";
	for(int i=possiblePalindrome.length()-1; i>=0; i--) {
		backwardsString += possiblePalindrome.at(i);
	}
	return possiblePalindrome == backwardsString;
}

bool isSquarePalindrome(int num, int base) {
	return isPalindrome(numBaseN(pow(num, 2), base));
}

void outputPalindrome(int num, int base) {
	fout << numBaseN(num, base) << ' ' << numBaseN(pow(num, 2), base) << endl;
}

int main() {
	int base;
	fin >> base;

	for(int n=1; n<=MAX_N; n++) {
		if(isSquarePalindrome(n, base)) {
			outputPalindrome(n, base);
		}
	}

	return 0;
}
