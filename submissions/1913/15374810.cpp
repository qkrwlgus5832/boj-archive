#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;
int query;
int snail[1000][1000];
int dir[4][2] = {{ 0, 1 }, { 1, 0 }, { 0, -1 },{ -1, 0 } };

pair <int, int> result;

void DFS(int i, int j, int range, int number, int index) {
	if (range == N / 2 + 1)
		return; 

	snail[i][j] = number;

	if (number == query) {
		result.first = i + 1; 
		result.second = j + 1;
	}

	int ni = i + dir[index][0];
	int nj = j + dir[index][1];
	if (ni  < N / 2 - range || nj < N / 2 - range || ni > N / 2 + range || nj> N / 2 + range) {
		if (index == 3) {
			DFS(i + dir[index][0], j + dir[index][1], range + 1, number + 1, 0);
			return;
		}
		else {
			index++;
		}
	}

	DFS(i + dir[index][0], j + dir[index][1] , range, number + 1, index);

}
int main() {
	cin >> N;	
	
	cin >> query;

	snail[N / 2][N / 2] = 1;
	result = make_pair(N / 2 + 1, N / 2 + 1);
	DFS(N / 2 - 1, N / 2, 1, 2, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << snail[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << result.first << " " << result.second;
	//system("Pause");
}