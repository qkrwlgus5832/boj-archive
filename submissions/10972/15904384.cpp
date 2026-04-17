#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;
vector <int> v2;

bool check[10001];
int N;

int main() {
	
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		check[tmp] = true;
		v.push_back(tmp);
	}

	check[v[v.size() - 1]] = false;


	int index =  -1;
	for (int i = v.size() - 2; i >= 0; i--) {
		if (v[i] == N)
			check[v[i]] = false;
		for (int j = v[i] + 1; j <= N; j++) {
			if (j<= N && check[j] == false) {

				check[j] = true;
				check[v[i]] = false;
				v[i] = j;
				index = i;
				break;
			}
			else {
				check[v[i]] = false;
			}
		}
		if (index != -1)
			break;

	}

	if (index == -1) {
		cout << -1;
		return 0;

	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			v2.push_back(i);
		}
	}

	sort(v2.begin(), v2.end());

	for (int i = 0; i <= index; i++) {
		printf("%d ", v[i]);
	}
	for (int i = 0; i < v2.size(); i++) {
		printf("%d ", v2[i]);
	}

	//system("Pause");

}