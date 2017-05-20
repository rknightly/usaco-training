/*
    PROB: dualpal
    LANG: C++11
 */

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

string numBaseN(int num, int base) {
  string numInBase = "";
  char digits[20] = "0123456789ABCDEFGHI";

  while (num > 0) {
    int remainder = num % base;
    numInBase = digits[remainder] + numInBase;
    num -= remainder;
    num /= base;
  }

  return numInBase;
}

bool isPalindrome(string possiblePalindrome) {
  string backwardsString = "";
  for (int i = possiblePalindrome.length() - 1; i >= 0; i--) {
    backwardsString += possiblePalindrome.at(i);
  }
  return possiblePalindrome == backwardsString;
}

bool isDualPal(int num) {
  int basePalCount = 0;
  for (int base = 2; base <= 10; base++) {
    if (isPalindrome(numBaseN(num, base))) {
      basePalCount += 1;
    }
  }
  return basePalCount >= 2;
}

int main() {
  int numCount;
  int minNum;
  fin >> numCount >> minNum;

  int foundCount = 0;

  for (int n = minNum + 1; foundCount < numCount; n++) {
    if (isDualPal(n)) {
      fout << n << endl;
      foundCount++;
    }
  }

  return 0;
}
