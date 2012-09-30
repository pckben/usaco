/*
ID: pckben11
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check(int n, string a[], string b[]) {
	for (int i=0; i<n; i++) 
		if (a[i] != b[i])
			return false;
	return true;
}

void rotate90(int n, string s[]) {
	string s1[10];
	for (int i=0; i<n; i++)
		s1[i] = s[i];
	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			s[j][n-i-1] = s1[i][j];
}

void reflect(int n, string s[]) {
	string s1[10];
	for (int i=0; i<n; i++)
		s1[i] = s[i];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			s[i][n-j-1] = s1[i][j];
}



int main() {
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	int N;
	string A[10], B[10];
	fin >> N;
	for (int i=0; i<N; i++)
		fin >> A[i];
	for (int i=0; i<N; i++)
		fin >> B[i];

	// try tranform
	int move = 7;
	if (check(N, A, B))
		move = 6;

	rotate90(N, A);
	if (check(N, A, B))
		move = 1;
	else {
		rotate90(N, A);
		if (check(N, A, B))
			move = 2;
		else {
			rotate90(N, A);
			if (check(N, A, B))
				move = 3;
			else {
				rotate90(N, A);
				reflect(N, A);
				if (check(N, A, B))
					move = 4;
				else {
					rotate90(N, A);
					if (check(N, A, B))
						move = 5;
					else {
						rotate90(N, A);
						if (check(N, A, B))
							move = 5;
						else {
							rotate90(N, A);
							if (check(N, A, B))
								move = 5;
						}
					}
				}
			}
		}
	}

	cerr << move << endl;
	fout << move << endl;
	
	return 0;
}
