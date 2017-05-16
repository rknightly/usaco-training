/*
PROB: gift1
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

struct Friend {
  string name = "";
  int account = 0;
};

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int studentCount;
    fin >> studentCount;

    // Get friend names
    Friend friends[10];
    for(int i=0; i<studentCount; i++) {
      fin >> friends[i].name;
    }
    string name;
    int giver, giving, friendCount;
    for(int i=0; i<studentCount; i++) {
      fin >> name;
      // Find giving student
      for(int i=0; i<studentCount; i++) {
        if (friends[i].name == name) {
          fin >> giving >> friendCount;
          giver = i;
        }
      }
      if (friendCount == 0) {
        continue;
      }
      int giftAmount = giving / friendCount;
      string friendName;
      for(int i=0; i<friendCount; i++) {
        fin >> friendName;
        for(int i=0; i<studentCount; i++) {
          if (friendName == friends[i].name) {
            friends[i].account += giftAmount;
            friends[giver].account -= giftAmount;
          }
        }
      }
    }
    // print results
    for(int i=0; i<studentCount; i++) {
      fout << friends[i].name << ' ' << friends[i].account << endl;
    }
    return 0;
}
