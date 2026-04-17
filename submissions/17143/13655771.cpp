#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int dir[4][2] = { {-1,0}, {1,0}, {0,1}, {0, -1} };

int R, C, M;

vector <pair <pair <int ,int>, pair <int, int> >> shark;

vector <int> speed;

//vector <int> ocean[10001];

int ocean[101][101];

bool die[10001];

int oceansharkindex[101][101];

bool check[10001];

void sharkmove(int sharkindex) {
	queue <pair <int, int>> q;

	//memset(ocean, 0, sizeof(ocean));

	int i = shark[sharkindex].first.first;
	int j = shark[sharkindex].first.second;
	int direction = shark[sharkindex].second.first;
	int size = shark[sharkindex].second.second;

	if (speed[sharkindex] == 0) {
		ocean[i][j] = size;
		oceansharkindex[i][j] = sharkindex;
		return;
	}

	int count = 0;

	q.push(make_pair(i, j));

	while (!q.empty()) {
		int fronti = q.front().first;
		int frontj = q.front().second;

		fronti += dir[direction][0];
		frontj += dir[direction][1];

		if (fronti < 0 || frontj < 0 || fronti >= R || frontj >= C) {
			if (direction == 0) {
				direction = 1;
			}
			else if (direction == 1) {
				direction = 0;
			}
			else if (direction == 2) {
				direction = 3;
			}
			else if (direction == 3) {
				direction = 2;
			}
			continue;
		}
		q.pop();
		count++;
		q.push(make_pair(fronti, frontj));

		if (count == speed[sharkindex]) {
			if (ocean[fronti][frontj] < size) {
				shark[sharkindex].first.first = fronti; shark[sharkindex].first.second = frontj;
				shark[sharkindex].second.first = direction;
				if (ocean[fronti][frontj] != 0)
					die[oceansharkindex[fronti][frontj]] = true; 
				ocean[fronti][frontj] = size;
				oceansharkindex[fronti][frontj] = sharkindex;
			}
			else {
				die[sharkindex] = true;
			}
			return;
		}
		
	}
	
}

int fishing(int fishingcount){

	int minsharkindex = -1;
	int minsharkgroundindex = -1;

	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].first.second == fishingcount && die[i] == false) {
			if (minsharkindex == -1) {
				minsharkindex = i;
				minsharkgroundindex = shark[i].first.first;
			}
			else {
				if (minsharkgroundindex > shark[i].first.first) {
					minsharkgroundindex = shark[i].first.first;
					minsharkindex = i;
				}
			}
		}
	}
	if (minsharkindex != -1) {
		die[minsharkindex] = true;
		return shark[minsharkindex].second.second;
	}
	else
		return 0;

}
int main() {

	cin >> R >> C >> M;
	int r, c, s, d, z;

	for (int j = 0; j < M; j++) {
			scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
			
			shark.push_back(make_pair(make_pair(r - 1, c - 1), make_pair(d- 1,z)));
			speed.push_back(s);
	}

	int result = 0;

	for (int fishingcount = 0; fishingcount < C; fishingcount++) {
		
		result += fishing(fishingcount);

		memset(ocean, 0, sizeof(ocean));
		memset(check, false, sizeof(check));
		memset(oceansharkindex, 0, sizeof(oceansharkindex));

		for (int i = 0; i < shark.size(); i++) {
			if (die[i] == false) {
				sharkmove(i);
				//check[i] = true;a
			}
		}
		
	}

	cout << result;
	//system("Pause");

}