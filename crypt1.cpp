/*
ID: pckben11
PROG: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

bool check(int D[], int N, int x) {
	do {
		int d = x%10;
		bool ok = false;
		for (int i=0; i<N; i++)
			if (D[i] == d) {
				ok = true;
				break;
			}
		if (!ok)
			return false;

		x /= 10;
	} while(x>0);
	return true;
}

int main() {
	int D1[] = {1, 2, 3};
	int N1 = 3;
	assert(check(D1, N1, 3) == true);
	assert(check(D1, N1, 123) == true);
	assert(check(D1, N1, 0) == false);
	assert(check(D1, N1, 1234) == false);

	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");

	int N; 
	int D[10];

	fin >> N;
	for (int i=0; i<N; i++) fin >> D[i];

	/*
	   a b c
	     d e
	   -----
	   l m n
	 o p r
	 -------
	 s t u v
	 */
	int count = 0;
	for (int a=0; a<N; a++)
		for (int b=0; b<N; b++)
			for (int c=0; c<N; c++)
				for (int d=0; d<N; d++)
					for (int e=0; e<N; e++) {
						int x = D[a]*100+D[b]*10+D[c];
						int prod1 = x * D[e]; if (prod1>999 || prod1 < 100) continue;
						int prod2 = x * D[d]; if (prod2>999 || prod2 < 100) continue;
						int prod = prod1 + prod2*10; if(prod > 9999 || prod<1000) continue;
						if (check(D, N, prod1) && check(D,N,prod2) && check(D,N,prod)) {
							//cerr << D[a]<<D[b]<<D[c] <<" * " <<D[d]<<D[e] <<" = "<<prod1<<" + "<<prod2<<"*10 = "<<prod <<endl;
							count++;
						}
					}

	cerr << count << endl;
	fout << count << endl;
	return 0;
}
