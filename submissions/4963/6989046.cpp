#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[51][51];
int check[51][51];
queue <int> q;
int w = 1;
int h = 1;
void cango(int x, int y);

void bfs(int x, int y)
{
	q.push(x*w+y);
	check[x][y] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int x2 = now / w;
		int y2 = now%w;
		cango(x2, y2);
	}

}

void cango(int x, int y) {
	int f = 0;
	if (y < w-1 && graph[x][y + 1] == 1 && check[x][y + 1] == 0) {
		check[x][y + 1] = 1;
		f = 1;
		q.push(x*w+(y+1));
	}
	 if (y>=1 && graph[x][y - 1] == 1 && check[x][y - 1] == 0 ) {
		check[x][y - 1] = 1;
		f = 1;
		q.push(x*w + (y - 1));
	}
	 if (x>=1 && y>=1 && graph[x - 1][y - 1] == 1 && check[x - 1][y - 1] == 0 ) {
		check[x - 1][y - 1] = 1;
		f = 1;
		q.push((x - 1)*w + (y - 1));
	}
	 if (x>=1 && graph[x - 1][y] == 1 && check[x - 1][y] == 0) {
		check[x - 1][y] = 1;
		f = 1;
		q.push((x - 1)*w + (y));
	}
	 if (x>=1 && y<w-1 && graph[x - 1][y + 1] == 1 && check[x - 1][y + 1] == 0) {
		check[x - 1][y + 1] = 1;
		f = 1;
		q.push((x - 1)*w + (y+1));
	}
	 if ( y>=1 && x<h-1 && graph[x + 1][y - 1] == 1 && check[x + 1][y - 1] == 0) {
		check[x + 1][y - 1] = 1;
		f = 1;
		q.push((x + 1)*w + (y-1));
	}
	 if (x<h-1 && graph[x + 1][y] == 1 && check[x + 1][y] == 0) {
		check[x + 1][y] = 1;
		f = 1;
		q.push((x + 1)*w + (y));
	}
	 if (x<h-1 && y<w-1&& graph[x + 1][y + 1] == 1 && check[x + 1][y + 1] == 0) {
		check[x + 1][y + 1] = 1;
		f = 1;
		q.push((x + 1)*w + (y+1));
	}	

}



int main() {

	vector <int> v;
	vector<int> ::iterator vi;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> graph[i][j];
			}

		}
		int K = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (graph[i][j] == 1) {
					if (check[i][j] == 0) {
						bfs(i, j);
						K = K + 1;
					}
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				graph[i][j] = 0;
				check[i][j] = 0;
			}
		}
		

		v.push_back(K);

	}
		for (vi = v.begin(); vi != v.end(); vi++)
			cout << *vi << endl;

}
