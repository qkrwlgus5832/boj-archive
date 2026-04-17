#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B;

vector <int> tile1;
vector <int> tile2;

void tile1Pop(int &N, int &result) {
	N = N -2;
	result += tile1.back();
	tile1.pop_back();
	result += tile1.back();
	tile1.pop_back();
}


void tile2Pop(int &N, int &result) {
	N = N - 2;
	result += tile2.back();
	tile2.pop_back();
}
int main() {
	cin >> N >> A >> B;
	int tmp;

	for (int i = 0; i < A; i++) {
		cin >> tmp;
		tile1.push_back(tmp);
	}
	for (int i = 0; i < B; i++) {
		cin >> tmp;
		tile2.push_back(tmp);
	}

	sort(tile1.begin(), tile1.end());
	sort(tile2.begin(), tile2.end());

	int result = 0;
	while (1) {
		if (N == 0) {
			break;
		}
		if (N == 1) {
			result += tile1.back();
			tile1.pop_back();
			break;
		}
		if ((tile1.size() == 1 || tile1.size() == 2) && N % 2 == 1) {
			tile2Pop(N, result);
		}
		else if (tile1.size() > 1 && tile2.size() >0) {
			if (tile1.back() + tile1[tile1.size()-2] <= tile2.back()) {
				tile2Pop(N, result);
			}
			else {
				tile1Pop(N, result);
			}
		}
		else if (tile1.size() > 1) {
			tile1Pop(N, result);
		}
		else if (tile2.size() > 0) {
			tile2Pop(N, result);
		}
		
	}
	cout << result;
	//system("Pause");
}