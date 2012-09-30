/*
ID: pckben11
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

struct Action {
	int time;
	int milking; // 1: milking, -1: not milking
}; 


bool cmp(Action i, Action j) { 
	if (i.time != j.time)
		return i.time < j.time; 
	else
		return i.milking > j.milking; // doing event before stopping event
}

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int N;
	fin >> N;

	vector<Action> m;
	for (int i=0; i<N; i++) {
		Action start, end;
		fin >> start.time >> end.time;
		start.milking = 1;
		end.milking = -1;
		m.push_back(start);
		m.push_back(end);
	}

	sort(m.begin(), m.end(), cmp);

	int count = 0; // how many cows being milked
	int max_yes = 0, max_no = 0;
	int last_time = -1;
	int accumulator = 0;
	bool idle = false;

	for (vector<Action>::iterator it = m.begin(); it!=m.end(); ++it) {
		count += it->milking;
		int delta = it->time - last_time;
		if (last_time < 0)
			delta = 0;
		accumulator += delta;

		//cerr << it->time << "\t" << it->milking << "\t" << count << "\t" << delta << "\t" << accumulator << endl;

		if (idle) {
			max_no = (max_no < accumulator) ? accumulator : max_no;
		} else {
			max_yes = (max_yes < accumulator)? accumulator : max_yes;
		}

		// update idling status
		bool newIdle = count == 0;
		if (idle != newIdle) {
			accumulator = 0;
			idle = newIdle;
		}

		last_time = it->time;
	}

	cerr << max_yes << " " << max_no << endl;
	fout << max_yes << " " << max_no << endl;

	return 0;
}
