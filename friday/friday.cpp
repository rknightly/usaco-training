/*
   PROB: friday
   LANG: C++11
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ofstream fout("friday.out");
  ifstream fin("friday.in");

  int n;
  fin >> n;

  int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int freqCount[7] = {0, 0, 0, 0, 0, 0, 0};

  int weekDay = 1; // monday = 1
  bool leap;

  for (int year = 1900; year < 1900 + n; year++) {
    leap =
        (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? true : false;
    if (leap) {
      months[1] = 29;
    }

    for (const auto &month : months) {
      freqCount[(weekDay + 13) % 7] += 1;
      weekDay = (weekDay + month) % 7;
    }

    months[1] = 28;
  }
  bool first = true;
  for (const auto &freq : freqCount) {
    if (!first) {
      fout << " ";
    }
    fout << freq;
    first = false;
  }
  fout << endl;
  return (0);
}
