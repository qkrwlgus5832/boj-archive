#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M, D;

int enemy[16][16];

vector <int> archer;

int result = 0;
class tmpenemy {
public:
	int x;
	int y;
	int distance;
};
int getdistance(int x, int y, int x2,  int y2) {
	return abs(x - x2) + abs(y - y2);
}
int game(int enemy[][16]) {
	int count = 0;
	for (int t = 0; t < N; t++) {
		for (int aindex = 0; aindex < archer.size(); aindex++) {
			tmpenemy attackenemy;
			bool flag = false;
			for (int j = 0; j < M; j++) {
				for (int i = 0; i < N - t; i++) {
					int distance = getdistance(i + t, j, N, archer[aindex]);
					if (enemy[i][j] == 1 && distance <= D) {
						if (flag == false) {
							attackenemy.x = i; attackenemy.y = j;
							attackenemy.distance = distance;
							flag = true;
						}
						else if (distance < attackenemy.distance) {
							attackenemy.x = i; attackenemy.y = j;
							attackenemy.distance = distance;
						}
					}

				}
			}
			if (flag == true) {
				enemy[attackenemy.x][attackenemy.y] = 0;
				count++;
			}

		}
	}
	return count;

}

void recursion(int i1) {
	if (archer.size() == 3) {
		int tmpenemy[16][16];
		memcpy(tmpenemy, enemy, sizeof(enemy));
		result = max(result,game(tmpenemy));
		archer.pop_back();
		return;
	}

	for (int i = i1; i < N; i++) {
		archer.push_back(i);
		recursion(i + 1);
	}

	if (archer.size() >= 1)
		archer.pop_back();
}
int main() {
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &enemy[i][j]);
		}
	}
	recursion(0);
	cout << result;
	//system("Pause");
}