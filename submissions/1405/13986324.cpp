#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;

double e;
double w;
double s;
double n;

vector <char> v;

bool check[30][30];

double result = 0;

pair <int, int> getRealCoordinate(int x, int y) {
	return make_pair(x + N, y + N);
}

bool checkIf(int x, int y) {
	pair <int, int> tmp = getRealCoordinate(x, y);
	if (check[tmp.first][tmp.second] == true) {
		return false;
	}
	else {
		check[tmp.first][tmp.second] = true;
		return true;
	}
}

void checkfalse(int x, int y) {
	pair <int, int> tmp = getRealCoordinate(x, y);
	check[tmp.first][tmp.second] = false;
}

double calculate() {
	double result = 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 'e') {
			result *= e;
		}
		else if (v[i] == 'w') {
			result *= w;
		}
		else if (v[i] == 's') {
			result *= s;
		}
		else if (v[i] == 'n') {
			result *= n;
		}
	}
	return result;
}

void recursion(int x, int y) {
	if (v.size() == N) {
		result += calculate();
		checkfalse(x, y);
		v.pop_back();
		return;

	}

	if (checkIf(x + 1, y)) {
		v.push_back('e');
		recursion(x + 1, y);
	}

	if (checkIf(x - 1, y)) {
		v.push_back('w');
		recursion(x - 1, y);
	}

	
	if (checkIf(x, y + 1)) {
		v.push_back('s');
		recursion(x, y + 1);
	}

	
	if (checkIf(x, y - 1)) {
		v.push_back('n');
		recursion(x , y - 1);
	}

	if (v.size() >=1)
		v.pop_back();

	checkfalse(x, y);

}

int main() {
	cin >> N >> e >> w >> s >> n;
	e = e * 0.01;
	w = w * 0.01;
	s = s * 0.01;
	n = n * 0.01;

	pair <int, int> dd= getRealCoordinate(0, 0);
	check[dd.first][dd.second] = true;
	recursion(0, 0);
	cout << result;
	//system("Pause");
}