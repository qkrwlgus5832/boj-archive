#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>

using namespace std;



char graph[11][11];
int dir[4][2] = { {0,-1},{0, 1}, {-1,0}, {1,0} };

int result = -1;
int N, M;

class beed_ {
public:
	int x;
	int y;
	int success;

	beed_(int x, int y, int success) {
		this->x = x;
		this->y = y;
		this->success = success;
	}
	beed_() {}
};

beed_ hole;
beed_ red;
beed_ blue;

char checkFirst(int dirIndex) {
	if (dirIndex == 0) {
		if (red.y < blue.y)
			return 'R';
	}
	else if (dirIndex == 1) {
		if (red.y > blue.y)
			return 'R';
	}
	else if (dirIndex == 2) {
		if (red.x < blue.x)
			return 'R';
	}
	else if (dirIndex == 3) {
		if (red.x > blue.x)
			return 'R';
	}
	return 'B';
}

int checkIfAnswer(pair <int, int> beed, char color) {
	if (beed.first == hole.x && beed.second == hole.y) {
		if (color == 'r')
			return 1;
		else
			return -1;
	}
	return 0;
}
beed_ dfs(int dirIndex, pair <beed_, beed_> beeds, char color) {
	bool flag = false;
	beed_ beed = beeds.first;
	int ni = beed.x+ dir[dirIndex][0];
	int nj = beed.y + dir[dirIndex][1];
	if (!(ni < 0 || nj < 0 || ni >= N || nj >= M || graph[ni][nj] == '#')) {
		beed_ anotherbeed = beeds.second;


		int result = checkIfAnswer(make_pair(ni, nj), color);

		if (result == 0) {
			if (ni == anotherbeed.x && nj == anotherbeed.y)
				return beed_(beed.x, beed.y, 0);
			beed.x = ni;
			beed.y = nj;
			beeds.first = beed;
			return dfs(dirIndex, beeds, color);
		}


		return beed_(ni, nj, result);
	}
	
	return beed_(beed.x, beed.y, 0);
		
}
pair <bool, int> escape(vector <int> v, beed_ red, beed_ blue) {
	for (int i = 0; i < v.size(); i++) {
		int dirIndex = v[i];
		char firstbeed = checkFirst(dirIndex);
		if (firstbeed == 'R') {
			red = dfs(dirIndex, make_pair(red, blue), 'r');
			blue = dfs(dirIndex, make_pair(blue, red), 'b');
		}

		else {
			blue = dfs(dirIndex, make_pair(blue, red), 'b');
			red = dfs(dirIndex, make_pair(red, blue), 'r');
		}
		if (red.success == 1 && blue.success != -1) {
			return make_pair(true, i + 1);
		}
		else if (blue.success == -1) {
			return make_pair(false, i + 1);
		}

	}
	return make_pair(false, -1);
}

void order(vector <int> v) {
	if (v.size() == 10) {

		pair <bool, int> tmp = escape(v, red, blue);
		if (tmp.first == true) {
			if (result == -1) {
				result = tmp.second;
			}
			else {
				result = min(result, tmp.second);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		order(v);
		v.pop_back();
	}
}

int main() {

	char tmp;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 'R') {
				red.x = i; red.y = j;
			}
			else if (graph[i][j] == 'B') {
				blue.x = i; blue.y = j;
			}
			else if (graph[i][j] == 'O') {
				hole.x = i; hole.y = j;
			}
		}
	}
	vector <int> v;
	order(v);
	cout << result;
	//system("Pause");
}