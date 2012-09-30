/*
ID: pckben11
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int convert(string s) {
	int prod = 1;
	for (int i=0; i<s.length(); i++) {
		prod *= s[i]-'A'+1;
	}
	return prod;
}

int main() {
	cerr << convert("A") << endl;
	cerr << convert("Z") << endl;
	cerr << convert("USACO") << endl;

	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string s1, s2;
	fin >> s1 >> s2;
	int x1 = convert(s1);
	int x2 = convert(s2);

	if (x1 % 47 == x2 % 47)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;

	fin.close();
	fout.close();
	return 0;
}
