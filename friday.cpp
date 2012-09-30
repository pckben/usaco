/*
ID: pckben11
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int DOM[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int N;
	fin >> N;

	int k[7];
	for (int i=0; i<7; i++) k[i] = 0;

	int d = 0; // 13/1/1990 = SATURDAY

	for (int i=0; i<N; i++) {
		bool leap = false;
		int year = 1900+i;
		if (year  % 4 ==0) {
			if (year % 100 !=0)
				leap = true;
			else if(year % 400 == 0)
				leap = true;
		}

		for (int j=0; j<12; j++) {
			k[d]++;
			if (j==1 && leap)
				d += 29;
			else
				d += DOM[j];
			d %= 7;
		}
	}

	for (int i=0; i<7; i++) {
		fout << k[i];
		if (i < 6) 
			fout << " ";
		else
			fout << endl;
	}
	return 0;
}
