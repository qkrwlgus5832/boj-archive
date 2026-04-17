#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	int N;
	cin >> N;
	int tmp;
	vector <int> v;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int M;
	cin >> M;
	vector <int> v2;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		v2.push_back(tmp);
	}

	for (int i = 0; i < M; i++) {
		cout << binary_search(v.begin(), v.end(), v2[i]) << " ";

	}
	//system("Pause");
}