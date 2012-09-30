/*
ID: pckben11
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdlib>

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
	string s = "";
	while (x != 0) {
		int r = x % b;
		if (r<10) s.push_back('0' + r);
		else s.push_back('A' + r-10);
		x /= b;
	}
	s = reverse(s);
	//cerr << x << ", " << b << " -> " << s << endl;
	return s;
}

bool ispalindrome(string n) {
	for(int i=0; i<n.length(); i++) {
		if (n[i] != n[n.length() - i-1])
			return false;
	}
	return true;
}

int main() {
	assert(reverse("1234") == "4321");
	assert(reverse("123") == "321");
	assert(reverse("1") == "1");
	assert(convert(4, 2) == "100");
	assert(convert(15, 16) == "F");
	assert(ispalindrome("1234321") == true);
	assert(ispalindrome("123321") == true);
	assert(ispalindrome("2") == true);
	assert(ispalindrome("22") == true);
	assert(ispalindrome("132") == false);

	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	int B;
	fin >> B;
	int N = 300;
	for (int i=0; i<N; i++) {
		string n = convert((i+1)*(i+1), B);
		if (ispalindrome(n)) {
			fout << convert(i+1, B) << " " << n << endl;
		}
	}
	return 0;
}
