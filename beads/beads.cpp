/*
   PROB: beads
   LANG: C++11
 */

#include <fstream>
#include <iostream>

using namespace std;

int leftInd(int i, int n) {
  int newInd = i - 1;
  if (newInd < 0) {
    newInd = n - 1;
  }
  return newInd;
}

int rightInd(int i, int n) {
  int newInd = i + 1;
  if (newInd > n - 1) {
    newInd = 0;
  }
  return newInd;
}

int maxChain(int start, char colors[], int n) {
  int i = start;
  int j = rightInd(i, n); // Indices of the left and right pointers

  char colorA = colors[i];
  char colorB = colors[j]; // Chars of colors on each side

  int leftLen = 1;
  int rightLen = 1;

  while (colors[leftInd(i, n)] == colorA || colors[leftInd(i, n)] == 'w' ||
         colorA == 'w') {
    i = leftInd(i, n);
    if (colorA == 'w') {
      colorA = colors[i];
    }

    if (i == start) {
      return n; // Stop if full loop made
    }
    leftLen++;
  }

  while (colors[rightInd(j, n)] == colorB || colors[rightInd(j, n)] == 'w' ||
         colorB == 'w') {
    j = rightInd(j, n);
    if (colorB == 'w') {
      colorB = colors[j];
    }

    if (j == i || j == start) {
      return n; // stop if full loop made
    }
    rightLen++;
  }

  return leftLen + rightLen;
}

int main() {
  ofstream fout("beads.out");
  ifstream fin("beads.in");

  int n;
  fin >> n;
  char colors[n];
  fin >> colors;

  int maxes[n];
  for (int i = 0; i < n; i++) {
    maxes[i] = maxChain(i, colors, n);
  }
  int max = 0;
  for (const auto &eachMax : maxes) {
    if (eachMax > max) {
      max = eachMax;
    }
  }
  cout << "ANS: " << max << endl;
  fout << max << endl;

  return (0);
}
