#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int graph[101][101];
int check[101][101];
queue <int> q;

int a;
vector <int> v;
void cango(int x, int y);

void bfs(int x, int y)
{
	q.push(x*a + y);
	check[x][y] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int x2 = now / a;
		int y2 = now%a;
		cango(x2, y2);
	}

}

void cango(int x, int y) {	
	if (y < a - 1 && graph[x][y + 1] == 1 && check[x][y + 1] == 0) {
		check[x][y + 1] = 1;	
		q.push(x*a + (y + 1));
	}
	if (y >= 1 && graph[x][y - 1] == 1 && check[x][y - 1] == 0) {
		check[x][y - 1] = 1;		
		q.push(x*a + (y - 1));
	}

	if (x >= 1 && graph[x - 1][y] == 1 && check[x - 1][y] == 0) {
		check[x - 1][y] = 1;
		q.push((x - 1)*a + (y));
	}
	
	if (x<a - 1 && graph[x + 1][y ] == 1 && check[x + 1][y ] == 0) {
		check[x + 1][y ] = 1;	
		q.push((x + 1)*a + (y ));
	}
	
	
}



int main() {
	int original[101][101];
	int tmp;

	cin >> a;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cin >> tmp;
			original[i][j] = tmp;
		}
		

	}




	int criteria = original[0][0];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (criteria <= original[i][j])
				criteria = original[i][j];
		}
	}


	
	

	for (int i1 = 1; i1 <= criteria; i1++) {

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				if (i1 < original[i][j])
					graph[i][j] = 1;
			}
		}

		int K = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				if (graph[i][j] == 1) {
					if (check[i][j] == 0) {
						bfs(i, j);
						K = K + 1;
					}
				}
			}
		}
		v.push_back(K);
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				graph[i][j] = 0;
			}
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				check[i][j] = false;
			}
		}
	}
	sort(v.begin(), v.end());

	cout << v[criteria - 1];


}


