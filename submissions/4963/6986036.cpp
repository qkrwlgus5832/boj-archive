#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int graph[51][51];
int check[51][51];
queue <int> q;
int w = 1;
int h = 1;
int cango(int x, int y);
void bfs(int x)
{
	q.push(x);
	check[x/w][x%w] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cango(now/w, now%w);
	}

}

int cango(int x, int y) {
	int f = 0;
	if ( y<h-1 && graph[x][y + 1] == 1 && check[x][y + 1] == 0) {
		check[x][y + 1] = 1;
		f = 1;
		q.push(x*w + (y+1));
	}
	else if (y>=1 && graph[x][y - 1] == 1 && check[x][y - 1] == 0 ) {
		check[x][y - 1] = 1;
		f = 1;
		q.push(x*w + (y - 1));
	}
	else if (x>=1 && y>=1 && graph[x - 1][y - 1] == 1 && check[x - 1][y - 1] == 0 ) {
		check[x - 1][y - 1] = 1;
		f = 1;
		q.push((x - 1)*w + (y - 1));
	}
	else if (x>=1 && graph[x - 1][y] == 1 && check[x - 1][y] == 0) {
		check[x - 1][y] = 1;
		f = 1;
		q.push((x - 1)*w + (y));
	}
	else if (x>=1 && y<h-1 && graph[x - 1][y + 1] == 1 && check[x - 1][y + 1] == 0) {
		check[x - 1][y + 1] = 1;
		f = 1;
		q.push((x - 1)*w + (y+1));
	}
	else if (x<w-1 && y>=1 && graph[x + 1][y - 1] == 1 && check[x + 1][y - 1] == 0) {
		check[x + 1][y - 1] = 1;
		f = 1;
		q.push((x + 1)*w + (y-1));
	}
	else if (x<w-1 && graph[x + 1][y] == 1 && check[x + 1][y] == 0) {
		check[x + 1][y] = 1;
		f = 1;
		q.push((x + 1)*w + (y));
	}
	else if (x<w-1 && y<h-1 && graph[x + 1][y + 1] == 1 && check[x + 1][y + 1] == 0) {
		check[x + 1][y + 1] = 1;
		f = 1;
		q.push((x + 1)*w + (y+1));
	}
	else
		return 0;

	if (f == 1)
		return 1;


}



int main() {

	vector <int> v;
	vector<int> ::iterator vi;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> graph[i][j];
			}

		}
		int K = 0;
		for (int i = 0; i < w*h; i++) {
			if (graph[i / w][i%w] == 1) {
				if (check[i / w][i%w] == 0) {
					bfs(i);
					K = K + 1;
				}
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				graph[i][j] = 0;
				check[i][j] = 0;
			}
		}

		v.push_back(K);

	}
		for (vi = v.begin(); vi != v.end(); vi++)
			cout << *vi << endl;

}
