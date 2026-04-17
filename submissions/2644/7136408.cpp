#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
int n;
int graph[1000][1000];
bool check[1001];
int BFS(int x,int y)
{

	queue<int> q;

	//Check that has passed 
	//Save path 
	int f = 0;
	int f2 = 0;

	int K = 0;

	q.push(x);
	check[x] = true;
	int level = 0;

	int count = 1;

	while (!q.empty())
	{
		int a2 = q.size();
		for (int j = 0; j < a2; j++) {
			int now = q.front(); //now : current node 
			q.pop(); //NOW has passed 

			for (int i = 1; i <= n; i++)
			{
				if (graph[now][i] == 1 && check[i] == false) //If connection & not passed 
				{
					if (i == y) {
						return level+1;
					}
					q.push(i); //push 	
					K = K + 1;
					f = 1;
					check[i] = true;
				}

			}
		}
		if (f == 1) {
			level++;
			f = 0;
		}
	}


	return -1;
}



int main() {
	int a;
	int b;
	int x;
	int y;
	int m;

	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;


	}
	cout << BFS(a, b);

}