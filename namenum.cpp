/*
ID: pckben11
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string lookup[] = {
	"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"
};

int main() {
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	string D;
	fin >> D;

	ifstream fdict("dict.txt");

	bool atleastone = false;

	while(!fdict.eof()) {
		string name;
		fdict >> name;

		if (name.length() != D.length())
			continue;

		bool ok = true;
		// check if name can be generated from number sequence
		for (int i=0; i<name.length(); i++) {
			string chars = lookup[D[i]-'2'];
			if (name[i] != chars[0] && name[i] != chars[1] && name[i] != chars[2]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			fout << name << endl;
			atleastone = true;
		}
	}

	if (!atleastone)
		fout << "NONE" << endl;

	return 0;
}
