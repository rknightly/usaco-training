/*
  PROB: transform
  LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream fin("transform.in");
ofstream fout("transform.out");

void showVector(vector<vector <char> > vect) {
	for(int i=0; i<vect.size(); i++) {
		for(int j=0; j<vect.size(); j++) {
			cout << vect.at(i).at(j);
		}
		cout << endl;
	}
	cout << '\n' << endl;
}

vector<vector<char> > matrixIn(int n) {
	vector< vector<char> > matrix(n);
	for(int i=0; i<n; i++) {
		matrix.at(i).resize(n);
		for(int j=0; j<n; j++) {
			fin >> matrix[i][j];
		}
	}
	return matrix;
}

vector<vector<char> > invert(vector<vector<char> > inMatrix) {
	vector<vector<char> > invertedMatrix(inMatrix.size(), vector<char>(inMatrix.size()));
	for(int i=0; i<inMatrix.size(); i++) {
		for(int j=0; j<inMatrix.size(); j++) {
			invertedMatrix[j][i] = inMatrix.at(i).at(j);
		}
	}
	return invertedMatrix;
}

vector<vector<char> > flip(vector<vector<char> > inMatrix) {
	vector<vector<char> > flippedMatrix(inMatrix.size());

	for (int i=0; i<inMatrix.size(); i++) {
		flippedMatrix.at(i).resize(inMatrix.size());
		for (int j=0; j<inMatrix.size(); j++) {
			flippedMatrix[i][(inMatrix.size()-1)-j] = inMatrix[i][j];
		}
	}
	return flippedMatrix;
}

vector< vector<char> > rotate(vector <vector<char> > inMatrix, int n) {
	cout << "Rotating" << endl;
	vector<vector<char> > rotatedMatrix(inMatrix.size(), vector<char>(inMatrix.size()));

	rotatedMatrix = flip(invert(inMatrix));

	for (int i=0; i<n-1; i++) {
		rotatedMatrix = flip(invert(rotatedMatrix));
	}
	showVector(rotatedMatrix);
	return rotatedMatrix;
}

bool combinationEquals(vector <vector<char> > original, vector <vector<char> > transformed) {
	bool works = false;
	original = flip(original);
	for (int i=0; i<3; i++) {
		original = rotate(original, 1);
		if (original == transformed) {
			works = true;
			break;
		}
	}
	return works;
}

int main() {
  	int n;

  	fin >> n;
  	cout << "N: " << n << endl;

  	vector< vector<char> > originalMatrix = matrixIn(n);
  	vector< vector<char> > transformedMatrix = matrixIn(n);

  	int result = 0;

  	if(rotate(originalMatrix, 1) == transformedMatrix) {
  		result = 1;
  	} else if(rotate(originalMatrix, 2) == transformedMatrix) {
  		result = 2;
  	} else if(rotate(originalMatrix, 3) == transformedMatrix) {
  		result = 3;
  	} else if(flip(originalMatrix) == transformedMatrix) {
  		result = 4;
  	} else if(combinationEquals(originalMatrix, transformedMatrix)) {
  		result = 5;
  	} else if(originalMatrix == transformedMatrix) {
  		result = 6;
  	} else {
  		result = 7;
  	}

  	fout << result << endl;
  	cout << result << endl;

	return 0;
}
