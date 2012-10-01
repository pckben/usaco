/*
ID: pckben11
PROG: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int count_boards(int* c, int S) {
	int n= 0;
	if (c[0] == 1) n++;

	for (int i=0; i<S-1; i++)
		if (c[i]==0 && c[i+1]==1)
			n++;
	return n;
}

int find_merge_pos(int* c, int S) {
	// find first 1
	int i= 0;
	for (; i<S; i++) if(c[i]==1) break;

	// find shortest sequence of 0
	int min = 1000000, min_pos = -1;
	for (; i<S; i++) {
		int len = 0;
		int pos = i;
		while(c[i]==0) {
			len++;
			i++;
		}
		if (min > len && len > 0) {
			min = len;
			min_pos = pos;
		}
	}
	//cerr << "min_pos = " << min_pos << endl;
	return min_pos;
}

void merge_boards(int* c, int S, int pos) {
	while(pos < S && c[pos] == 0) 
		c[pos++] = 1;
}

int main() {
	/*
	int c1[7] = {0,1,0,0,1,1,0};
	assert(count_boards(c1, 7) == 2);
	assert(find_merge_pos(c1, 7) == 2);

	int c2[7] = {1,1,1,1,1,1,1};
	assert(count_boards(c2, 7) == 1);
	assert(find_merge_pos(c2, 7) == -1);

	int c3[7] = {0,0,0,0,0,0,0};
	assert(count_boards(c3, 7) == 0);
	assert(find_merge_pos(c3, 7) == -1);
	*/

	ofstream fout("barn1.out");
	ifstream fin("barn1.in");

	int M, S, C;
	int c[200];

	for (int i=0; i<200; i++) c[i] = 0;

	fin >> M >> S >> C;
	for (int i=0; i< C; i++) {
		int s;
		fin >> s;
		c[s-1] = 1;
	}

	/*
	for (int i=0; i<S; i++) cerr << c[i] << " ";
	cerr << endl;
	cerr << "n = " << count_boards(c, S) << endl;
	*/

	while(count_boards(c, S) > M) {
		int pos = find_merge_pos(c, S);
		merge_boards(c, S, pos);

		/*
		for (int i=0; i<S; i++) cerr << c[i] << " ";
		cerr << endl;
		cerr << "n = " << count_boards(c, S) << endl;
		*/

	}

	int count = 0;
	for (int i=0; i<S; i++)
		if (c[i] == 1)
			count++;

	cerr << count << endl;
	fout << count << endl;

	return 0;
}
