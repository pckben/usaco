/*
ID: pckben11
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cctype>

using namespace std;

struct palindrome {
	string s; // full string
	int length; // actual length
};

palindrome find_palind(string s, int a, int b) {
	palindrome p;
	p.length = 0; 
	p.s = "";

	int a0 = a, b0 = b;
	while(true) {
		while (a>=0 && !isalpha(s[a])) a--;
		while (b<s.length() && !isalpha(s[b])) b++;

		if (a>=0 && b<s.length() 
				&& isalpha(s[a]) && isalpha(s[b])
				&& tolower(s[a])==tolower(s[b]) && b-a<2000) {
			p.length += 2;
			a0 = a;
			b0 = b;
		}
		else 
			break;

		a--;
		b++;
	}

	p.s = s.substr(a0, b0-a0+1);
	//cerr << p.s << " " << p.length << " " << a0 << "," << b0 << endl;
	return p;
}

palindrome find_odd(string s, int pos) {
	palindrome p;
	if (pos-1>=0 && pos+1<s.length()) {
		p = find_palind(s, pos-1, pos+1);
		p.length++;
	}
	else {
		p.s.push_back(s[pos]);
		p.length = 1;
	}
	return p;
}

palindrome find_even(string s, int pos) {
	palindrome p;
	if (pos>=0 && pos+1<s.length()) {
		p = find_palind(s, pos, pos+1);
	}
	return p;
}

void test() {
	assert(find_odd("a", 0).s == "a");
	assert(find_odd("a", 0).length == 1);

	assert(find_even("aa", 0).s == "aa");
	assert(find_even("aa", 0).length == 2);

	assert(find_even("a--a--", 0).s == "a--a");
	assert(find_even("a--a--", 0).length == 2);

	assert(find_odd("abcdcba", 3).s == "abcdcba");
	assert(find_odd("abcdcba", 3).length == 7);

	assert(find_odd("a123bc!#dc*ba,,", 8).s == "a123bc!#dc*ba");
	assert(find_odd("a123bc!#dc*ba,,", 8).length == 7);
}

int main() {

	test();
	ofstream fout("calfflac.out");
	ifstream fin("calfflac.in");

    string s((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
	//cerr << s << endl;

	palindrome p;
	p.length = 0;
	p.s = "";
	for (int i=0; i<s.length(); i++) 
		if (isalpha(s[i])) {
			// find odd
			palindrome odd_palind = find_odd(s, i);
			if (p.length < odd_palind.length) 
				p = odd_palind;

			palindrome even_palind = find_even(s, i);
			if (p.length < even_palind.length) 
				p = even_palind;
		}

	cerr << p.length << endl << p.s << endl;
	fout << p.length << endl << p.s << endl;

	return 0;
}
