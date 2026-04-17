#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;
vector <int> chu;

bool check[40001];

bool visit[31][40001];

void DFS(int index, int left, int right) {
	if (index == N)
		return;
	if (visit[index][right - left] == true)
		return;

	visit[index][right - left] = true;

	DFS(index + 1, left, right);
	
	if (right - left - chu[index] >=0)
		check[right - left - chu[index]] = true;
	DFS(index + 1, left + chu[index], right);

	if (right - left + chu[index] >= 0)
		check[right + chu[index] - left] = true;
	DFS(index + 1, left, right + chu[index]);
}



int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		chu.push_back(tmp);
	}

	DFS(0, 0, 0);

	int M;
	int input;
	cin >> M;


	for (int i = 0; i < M; i++) {
		cin >> input;
		if (check[input] == true) {
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	//system("Pause");
}