#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

int N, P, E;

vector <pair <int, int>> v;

vector <int> rec;

bool flag = false;

int dollcount[21];

pair <bool, long long> calculate() {
	long long mincount = 0;
	long long maxcount = 0;

	for (int i = 0; i < rec.size(); i++) {
		mincount += v[rec[i]].first;
		maxcount += v[rec[i]].second;
	}
	if (mincount <= E && E <= maxcount) {
		return make_pair(true, mincount);
	}
	return make_pair(false, mincount);
}

void setDollCount(long long restCount) {
	for (int i = 0; i < rec.size(); i++) {
		dollcount[rec[i]] += v[rec[i]].first;
	}

	for (int i = 0; i < rec.size(); i++) {
		long long tmp = v[rec[i]].second - v[rec[i]].first;
		if (tmp <= restCount) {
			dollcount[rec[i]] += tmp;
			restCount -= tmp;
		}
		else if (restCount == 0) {
			break;
		}
		else {
			dollcount[rec[i]] += restCount;
			restCount = 0;
		}
	}

}
void recursion(int index) {
	if (flag == true)
		return;

	if (rec.size() ==  P) {
		pair <bool, long long> calresult = calculate();
		if (calresult.first) {
			setDollCount(E - calresult.second);
			for (int i = 0; i < N; i++) {
				printf("%d ", dollcount[i]);
			}
			flag = true;
		}
		return;
	}
	for (int i = index + 1; i < v.size(); i++) {
		rec.push_back(i);
		recursion(i);
		rec.pop_back();
	}

}
int main() {
	cin >> N >> P >> E;
	int minvalue, maxvalue;

	for (int i = 0; i < N; i++) {
		cin >> minvalue >> maxvalue;
		v.push_back(make_pair(minvalue, maxvalue));
	}

	recursion(-1);
	
	if (flag == false) {
		cout << -1;
	}
	//system("Pause");
}