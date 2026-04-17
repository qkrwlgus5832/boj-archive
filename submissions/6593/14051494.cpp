#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

char sangbumbuilding[31][31][31];

bool check[31][31][31];

int L, R, C;

int dir[6][3] = {
   {-1, 0, 0} , {1, 0, 0}, {0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}
};

class location {
public:
	int L;
	int R;
	int C;
};

location startlocation;

int BFS() {
	queue <location> q;

	q.push(startlocation);
	check[startlocation.L][startlocation.R][startlocation.C] = true;

	int time = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			location frontlocation = q.front();
			q.pop();
			int l = frontlocation.L;
			int r = frontlocation.R;
			int c = frontlocation.C;

			for (int i1 = 0; i1 < 6; i1++) {
				int nl = l + dir[i1][0];
				int nr = r + dir[i1][1];
				int nc = c + dir[i1][2];
				if (nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C)
					continue;
				else if (sangbumbuilding[nl][nr][nc] == '.' && check[nl][nr][nc] == false) {
					frontlocation.L = nl;
					frontlocation.R = nr;
					frontlocation.C = nc;
					check[nl][nr][nc] = true;
					q.push(frontlocation);
				
				}
				else if (sangbumbuilding[nl][nr][nc] == 'E') {
					return time + 1;
				}
			}
		}
		time++;
	}
	return -1;
}


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	char tmp;
	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		memset(sangbumbuilding, 0, sizeof(sangbumbuilding));
		memset(check, false, sizeof(check));
		for (int t = 0; t < L; t++) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					scanf(" %c", &tmp);
					sangbumbuilding[t][i][j] = tmp;
					if (sangbumbuilding[t][i][j] == 'S') {
						startlocation.L = t;
						startlocation.R = i;
						startlocation.C = j;
					}

				}
			}
		}
		int result = BFS();
		if (result != -1) {
			cout << "Escaped in " << result << " minutes(s)." << endl;
		}
		else {
			cout << "Trapped!" << endl;
		}
	}
	//system("Pause");
}