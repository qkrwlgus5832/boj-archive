#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int graph[101][101];

bool check[101][101][5];

int M, N;

int dir[5][2] = { {0,0}, {0, 1}, {0,-1} ,{1, 0}, {-1, 0} };

class robot {
public:
	int x;
	int y;
	int direction;
	robot(int x, int y, int direction) {
		this->x = x;
		this->y = y;
		this->direction = direction;
	}
};

int BFS(robot start, robot end) {
	queue <robot> q;
	q.push(start);
	check[start.x][start.y][start.direction] = true;
	int count = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			robot front = q.front();
			q.pop();
			if (front.x == end.x && front.y == end.y && front.direction == end.direction) {
				return count;
			}
			for (int i1 = 1; i1 <= 3; i1++) {
				int nx = front.x + dir[front.direction][0] * i1;
				int ny = front.y + dir[front.direction][1] * i1;
				if (nx < 0 || ny < 0 || nx >= M || ny >= N)
					break;
				if (check[nx][ny][front.direction] == false) {
					if (graph[nx][ny] == 0) {
						check[nx][ny][front.direction] = true;
						q.push(robot(nx, ny, front.direction));
					}
					else
						break;
				}

			}

			if (front.direction == 1 || front.direction == 2) {
				if (check[front.x][front.y][3] == false) {
					check[front.x][front.y][3] = true;
					q.push(robot(front.x, front.y, 3));
				}
				if (check[front.x][front.y][4] == false) {
					check[front.x][front.y][4] = true;
					q.push(robot(front.x, front.y, 4));
				}
			}
			else if (front.direction == 3 || front.direction == 4) {
				if (check[front.x][front.y][1] == false) {
					check[front.x][front.y][1] = true;
					q.push(robot(front.x, front.y, 1));
				}
				if (check[front.x][front.y][2] == false) {
					check[front.x][front.y][2] = true;
					q.push(robot(front.x, front.y, 2));
				}
			}
			
		}
		count++;
	}
}


int main() {
	
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	int x; int y; int direction;
	

	cin >> x >> y >> direction;
	robot start = robot(x - 1, y- 1, direction);
	cin >> x >> y >> direction;
	robot end = robot(x- 1, y- 1, direction);

	cout << BFS(start, end);
	//system("Pause");
}