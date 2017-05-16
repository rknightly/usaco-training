/*
PROB: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    string answer = "";

    int cometProduct = 1;
    for (int i = 0; i<comet.length(); i++) {
      cometProduct *= (int)comet[i] - 64;
    }

    int groupProduct = 1;
    for (int i = 0; i<group.length(); i++) {
      groupProduct *= (int)group[i] - 64;
    }

    if (cometProduct % 47 == groupProduct % 47) {
      answer = "GO";
    } else {
      answer = "STAY";
    }
    cout << answer << endl;
    fout << answer << endl;
    return 0;
}
