/*
   PROB: milk
   LANG: C++11
 */
#include <fstream>
#include <iostream>

#include <vector>

using namespace std;

struct Farmer {
	int units;
	int price;
};

int priceOfCheapest(int milkCount, vector<Farmer> farmers) {
	int totalPrice = 0;
	int leftToBuy = milkCount;
	while (leftToBuy > 0) {
		int minPrice = farmers.at(0).price;
		int minIndex = 0;
		for(int i=0; i<farmers.size(); i++) {
			Farmer f = farmers.at(i);
			if (f.price < minPrice) {
				minPrice = f.price;
				minIndex = i;
			}
		}
		Farmer cheapest = farmers.at(minIndex);
		if (cheapest.units <= leftToBuy) {
			totalPrice += cheapest.units * cheapest.price;
			leftToBuy -= cheapest.units;
		} else {
			totalPrice += leftToBuy * cheapest.price;
			leftToBuy = 0;
		}
		farmers.erase(farmers.begin() + minIndex);
	}
	return totalPrice;
}



int main() {
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int totalMilks, farmerCount;
	fin >> totalMilks >> farmerCount;

	vector<Farmer> farmers;

	for(int i=0; i<farmerCount; i++) {
		Farmer f;
		fin >> f.price >> f.units;
		farmers.push_back(f);
	}

	fout << priceOfCheapest(totalMilks, farmers) << endl;

	return 0;
}
