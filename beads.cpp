/*
ID: pckben11
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int N;
	fin >> N;
	string S;
	fin >> S;

	S += S;
	cerr << S << endl;

	int K = 0;
	// try cut till second last bead, N-1
	for (int i=0; i<N-1; i++) {
		int prev = i;
		int next = i+1;
		int k = 2;

		char color = S[prev];
		// try collect backward till first bead, 0
		while (prev-1 >= 0) {
			prev--;
			if (color == 'w' || S[prev]==color || S[prev]=='w') {
				k++;
				if (color == 'w') 
					color = S[prev];
			} else {
				break;
			}
		}

		color = S[next];
		// try collect forward till not overlap with the previously collected
		while (next+1 < N+prev) {
			next++;
		   	if (color == 'w' || S[next]==color || S[next]=='w') {
				k++;
				if (color == 'w')
					color = S[next];
			} else {
				break;
			}
		}
		if (K<k) {
			K = k;
			cerr << i << ", " << K << endl;
		}
	}

	cerr << K << endl;

	fout << K << endl;

	return 0;
}
