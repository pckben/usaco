/*
ID: pckben11
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int NP;
string P[10];
int sum[10];

int indexOf(string name) {
	for (int i=0; i<NP; i++) {
		if (P[i] == name) {
			return i;
		}
	}
}

int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	fin >> NP;
	for (int i=0; i<NP; i++) {
		fin >> P[i];
		sum[i] = 0;
	}

	for (int i=0; i<NP; i++) {
		string giver;
		int money, NG;
		fin >> giver;
		fin >> money >> NG;

		cerr << giver << " " << money << " " << NG << endl;

		int ii = indexOf(giver);
		sum[ii] -= money;

		if (NG > 0) {
			int giving = money / NG;
			money %= NG;

			for (int j=0; j<NG; j++) {
				string receiver;
				fin >> receiver;

				int jj = indexOf(receiver);
				sum[jj] += giving;
			}
		}

		// money left after giving
		sum[ii] += money;

	}


	// output
	for (int i=0; i<NP; i++) {
		fout << P[i] << " " << sum[i] << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
