/*
   PROB: namenum
   LANG: C++11
 */
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_DICT = 5000;
const int ALPHA_START = 65;
const int ALPHA_END = 89;

int charToNum(char c) {
	int placeInAlpha = (int) c - ALPHA_START;

	// Note: Q is omitted
	if (placeInAlpha > (int) 'Q' - ALPHA_START) {
		placeInAlpha -= 1;
	}
	// sub 1 to account for Q
	// Add 2 b/c the numbering of A starts at 2
	int num = (placeInAlpha * 8 / (ALPHA_END-ALPHA_START - 1)) + 2;

	if (num > 9) {
		num = 9;
	}
	return num;
}

long long int strToNum(string s) {
	string mappedNumStr = "";
	for(int i=0; i < s.length(); i++) {
		mappedNumStr += to_string(charToNum(s.at(i)));
	}
	return stoll(mappedNumStr);
}

vector<long long int> numsOf(vector<string> strVect) {
	vector<long long int> numVect;
	for(int i=0; i<strVect.size(); i++) {
		numVect.push_back(strToNum(strVect.at(i)));
	}
	return numVect;
}

int main() {
	ifstream fin("namenum.in");
	ifstream dictIn("dict.txt");
	ofstream fout("namenum.out");

	vector<string> stringDict;
	stringDict.reserve(MAX_DICT);
	string newWord;
	while (dictIn >> newWord) {
		stringDict.push_back(newWord);
	}

	vector<long long int> intDict = numsOf(stringDict);
	long long int serialNum;
	fin >> serialNum;

	bool found = false;
	for (int i=0; i<intDict.size(); i++) {
		if (serialNum == intDict.at(i)) {
			found = true;
			fout << stringDict.at(i) << endl;
		}
	}

	if (!found) {
		fout << "NONE" << endl;
	}

	return 0;
}
