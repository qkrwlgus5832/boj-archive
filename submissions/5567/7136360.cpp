#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int graph[1000][1000];

queue <int> q;
int n;

bool check[1001];


//Breadth First Search 
int BFS()
{

	queue<int> q;

	//Check that has passed 
	//Save path 
	int f = 0;
	int f2 = 0;

	int K = 0;

	q.push(1);
	check[1] = true;
	int level = 0;
	
	int count = 1;

	while (!q.empty())
	{
	
		if (level >= 2)
			break;
		int a2 = q.size();
		for (int j = 0; j < a2; j++) {
			int now = q.front(); //now : current node 
			q.pop(); //NOW has passed 

			for (int i = 1; i <= n; i++)
			{
				if (graph[now][i] == 1 && check[i] == false) //If connection & not passed 
				{
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


	return K;
}







int main() {
	
	int m;
	int a;
	int b;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;

	}
	
	cout << BFS();

}