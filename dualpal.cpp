/*
ID: pckben11
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string reverse(string s) {
	for (int i=0; i<s.length()/2; i++) {
		char c = s[i];
		s[i] = s[s.length()-1-i];
		s[s.length()-1-i] = c;
	}
	return s;
}

string convert(int x, int b) {
	//cerr << x << ", ";
	string s = "";
	while(x>0) {
		s.push_back('0' + x % b);
		x /= b;
	}
	s = reverse(s);
	//cerr << b << " : " << s << endl;
	return s;
}

bool check(string s) {
	for (int i=0; i<s.length(); i++) {
		if (s[i] != s[s.length()-1-i])
			return false;
	}
	return true;
}

int main() {
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	int N, S;
	fin >> N >> S;
	int n=0, x = S+1;
	while(n<N) {
		int count = 0;
		for (int b=2; b<= 10; b++) {
			if (check(convert(x,b))) {
				if (++count >= 2) {
					fout << x << endl;
					cerr << x << " " << b << endl;
					n++;
					break;
				}
			}
		}
		x++;
	}
	return 0;
}
