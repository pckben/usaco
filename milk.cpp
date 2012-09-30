/*
ID: pckben11
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct farmer {
	int price;
	int amount;
};

int min(int x, int y) { return x>y?y:x; }
int cmp(const void * a, const void* b) {
	return ((farmer*)a)->price - ((farmer*)b)->price;
}

int main() {
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int N, M;
	farmer F[5000];
	fin >> N >> M;
	for (int i=0; i< M; i++) {
		fin >> F[i].price >> F[i].amount;
	}
	qsort(F, M, sizeof(farmer), cmp);

	int P = 0;
	int i = 0;
	while(N>0) {
		int a = min(N, F[i].amount);
		P += F[i].price * a;
		N -= a;
		i++;
	}

	cerr << P << endl;
	fout << P << endl;

	return 0;
}
