#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int cctvdirectionnumber[6] = { 0, 4,2,4,4,1 };

int N, M;

int NM[9][9];

vector <pair <int, int>> v;

pair <int, int> currentcctv;

int result = -1;

void bfs(int direction) {
	int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	queue <pair<int, int>> q;
	q.push(currentcctv);

	while (!q.empty()) {
		int frontx = q.front().first;
		int fronty = q.front().second;
		q.pop();
		frontx += dir[direction][0];
		fronty += dir[direction][1];
		if (frontx < 0 || fronty < 0 || frontx >= N || fronty >= M || NM[frontx][fronty] == 6)
			return;
		else {
			if (NM[frontx][fronty] == 0) {
				NM[frontx][fronty] = '#';
			}
			q.push(make_pair(frontx, fronty));
		}
	}
}

void goleft() {

	bfs(0);

}
void goright() {
	bfs(1);
}
void goup() {
	bfs(2);

}
void godown() {
	bfs(3);
}

void go(int cctvnumber, int direction) {
	if (cctvnumber == 1) {
		if (direction == 0)
			goright();
		else if (direction == 1)
			goup();
		else if (direction == 2)
			goleft();
		else if (direction == 3)
			godown();
	}
	else if (cctvnumber == 2) {
		if (direction == 0) {
			goleft(); goright();
		}
		else if (direction = 1) {
			goup(); godown();
		}
	}
	else if (cctvnumber == 3) {
		if (direction == 0) {
			goup(); goright();
		}
		else if (direction == 1) {
			goleft(); goup();

		}
		else if (direction == 2) {
			goleft(); godown();
		}
		else if (direction == 3) {
			goright(); godown();
		}
	}
	else if (cctvnumber == 4) {
		if (direction == 0) {
			goleft(); goup(); goright();
			goleft(); godown(); goright();
			goleft(); goup(); godown();
			goup(); goright(); godown();
		}
	}
	else if (cctvnumber == 5) {
		if (direction == 0) {
			goleft();
			goright();
			goup();
			godown();
		}
	}
}

void setbackup(int backup[][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			backup[i][j] = NM[i][j];
		}
	}
}

void setNM(int backup[][9]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			NM[i][j] = backup[i][j];
		}
	}
}


void recursion(int count) {
	if (count == v.size()) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (NM[i][j] == 0)
					count++;
			}
		}
		if (result == -1)
			result = count;
		else
			result = min(result, count);
		return;
	}

	int Nindex = v[count].first;
	int Mindex = v[count].second;
	
	currentcctv = v[count];

	int backup[9][9];

	setbackup(backup);

	for (int i = 0; i < cctvdirectionnumber[NM[Nindex][Mindex]]; i++) {
		currentcctv = v[count];
		go(NM[Nindex][Mindex], i);
		recursion(count + 1);
		setNM(backup);
	}


}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &NM[i][j]);
			if (1 <= NM[i][j] && NM[i][j] <= 5) {
				v.push_back(make_pair(i,j));
			}
		}
	}
	recursion(0);
	cout << result;
	//system("Pause");
}