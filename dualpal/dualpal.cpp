/*
    PROB: dualpal
    LANG: C++11
*/


#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");

bool isDualPal(int num) {
    basePalCount = 0;
    for(int base = 2; base <= 10; base++) {
        if(isPalindrome(numBaseN(num, base))) {
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
        if(isDualPal(n)) {
            fout << n << endl;
            foundCount ++;
        }
    }

    return 0;
}
