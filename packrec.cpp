/*
ID: pckben11
PROG: packrec
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int max(int x1, int x2, int x3) { return max(x1,max(x2,x3)); }
int max(int x1, int x2, int x3, int x4) { return max(x1,max(x2,x3,x4)); }

struct Rect {
	int w, h;

	void rotate() {
		int temp = w;
		w = h;
		h = temp;
	}

	void init() {
		if (w > h) {
			rotate();
		}
	}

	int area() { return w*h; }
};

bool compareRect(Rect a, Rect b) {
	return a.w < b.w;
}

Rect R[4];
int minarea = 99999999;

Rect pack_layout(int p[], int layout) {
	Rect s;
	switch(layout) {
		case 0:
			s.w = R[p[0]].w + R[p[1]].w + R[p[2]].w + R[p[3]].w;
			s.h = max(R[p[0]].h, R[p[1]].h, R[p[2]].h, R[p[3]].h);
			break;
		case 1:
			s.w = max(R[p[0]].w + R[p[1]].w + R[p[2]].w, R[p[3]].w);
			s.h = max(R[p[0]].h,  R[p[1]].h,  R[p[2]].h) + R[p[3]].h;
			break;
		case 2:
			s.w = max(R[p[0]].w + R[p[1]].w, R[p[2]].w) + R[p[3]].w;
			s.h = max(max(R[p[0]].h, R[p[1]].h) + R[p[2]].h, R[p[3]].h);
			break;
		case 3:
			s.w = R[p[0]].w + max(R[p[1]].w, R[p[2]].w) + R[p[3]].w;
			s.h = max(R[p[0]].h, R[p[1]].h + R[p[2]].h, R[p[3]].h);
			break;
		case 4:
			s.w = max(R[p[0]].w, R[p[1]].w) + R[p[2]].w + R[p[3]].w;
			s.h = max(R[p[0]].h + R[p[1]].h, R[p[2]].h, R[p[3]].h);
			break;
		case 5:
			s.w = max(R[p[0]].w + R[p[2]].w, R[p[0]].w + R[p[3]].w, R[p[1]].w + R[p[3]].w);
			s.h = max(R[p[0]].h + R[p[1]].h, R[p[1]].h + R[p[2]].h, R[p[2]].h + R[p[3]].h);
			break;
	};
	s.init();
	printf("layout %d: (%d %d), (%d %d), (%d %d), (%d %d) => (%d %d) = %d\n", layout, R[0].w, R[0].h, R[1].w, R[1].h, R[2].w, R[2].h, R[3].w, R[3].h, s.w, s.h, s.area());
	return s;
}

void pack(int i, int perm[], int layout, vector<Rect>& solutions) {
	if (i>=4) {
		Rect s = pack_layout(perm, layout);
		if (s.area() < minarea) {
			solutions.clear();
			minarea = s.area();
		}
		if (s.area() == minarea) {
			solutions.push_back(s);
		}
		return;
	}
	for (int pos=0; pos<4; pos++)
		if (perm[pos] == 0) {
			perm[pos] = i;
			pack(i+1, perm, layout, solutions);
			R[i].rotate();
			pack(i+1, perm, layout, solutions);
			R[i].rotate();
			perm[pos] = 0;
		}
}

int main() {
	ofstream fout("packrec.out");
	ifstream fin("packrec.in");
	for (int i=0; i<4; i++) {
		fin >> R[i].w >> R[i].h;
		R[i].init();
	}
	vector<Rect> solutions;
	for (int layout=0; layout<6; layout++) {
		int perm[] = {0, 0, 0, 0};
		pack(0, perm, layout, solutions);
	}
	sort(solutions.begin(), solutions.end(), compareRect);
	cerr << minarea << endl;
	fout << minarea << endl;
	Rect last; last.w = - 1; last.h = -1;
	for (vector<Rect>::iterator it = solutions.begin(); it!=solutions.end(); it++) {
		if (it->w != last.w && it->h != last.h) {
			cerr << it->w << " " << it->h << endl;
			fout << it->w << " " << it->h << endl;
			last = *it;
		}
	}
}
