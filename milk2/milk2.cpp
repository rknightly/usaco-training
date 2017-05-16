/*
   PROB: milk2
   LANG: C++11
 */

#include <fstream>
#include <iostream>

using namespace std;
const int MAXT = 1000001;

void updateTimes(int times[], int start, int end) {
  for (int i = start; i < end; i++) {
    times[i] += 1;
  }
}

int countStreak(int times[], int minTarget, int maxTarget, int start, int end) {
  int maxStreak = 0;
  int streak = 0;
  // cout << times[start - 1] << ' ' << times[start] << endl;
  // cout << times[end] << ' ' << times[end + 1] << endl;
  for (int i = start; i <= end; i++) {
    int val = times[i];
    if (val >= minTarget && val <= maxTarget) {
      streak += 1;
      if (streak > maxStreak) {
        maxStreak = streak;
      }
    } else {
      streak = 0;
    }
  }
  return maxStreak;
}

int main() {
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");

  int farmerCount;
  int cowsAtTime[MAXT] = {};

  fin >> farmerCount;
  int startT, endT, earliestT, latestT;
  earliestT = MAXT;
  for (int i = 0; i < farmerCount; i++) {
    fin >> startT >> endT;
    if (startT < earliestT) {
      earliestT = startT;
    }
    if (endT > latestT) {
      latestT = endT;
    }
    updateTimes(cowsAtTime, startT, endT);
  }
  latestT -= 1;

  int longestACow = countStreak(cowsAtTime, 1, MAXT, earliestT, latestT);
  int longestNoCow = countStreak(cowsAtTime, 0, 0, earliestT, latestT);

  fout << longestACow << ' ' << longestNoCow << endl;

  return 0;
}

// Problem, time can be 0
// Subtracting 1 from each T causes problem at T=0
