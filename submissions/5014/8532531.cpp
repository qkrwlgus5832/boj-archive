#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int F;
int S;
int G;
int U;
int D;



int K = 0;


int N, M, V;

bool check[1000001];

//Breadth First Search 
int BFS(int x)
{

	queue<int> q;

	//Check that has passed 
	//Save path 
	int f = 0;
	int f2 = 0;
	q.push(x);
	check[x] = true;
	int level = 0;
	
	/*for (int i = 1; i <= N; i++) {
	if (graph[x][i] == 1)
	level = 1;

	}
	*/
	int count = 1;

	while (!q.empty())
	{

		int a2 = q.size();
		for (int j = 0; j < a2; j++) {
			int now = q.front(); //now : current node 
			if (now == G)
			{
				return level;
			}
			q.pop(); //NOW has passed 
			if (now + U <= F && check[now + U] == false) {
				q.push(now + U);
				check[now + U] = true;
				f = 1;
			}
			if (now - D >= 1 && check[now -D] == false) {
				q.push(now -D);
				check[now -D] = true;
				f = 1;
			}

			
		}
		if (f == 1) {
			level++;
			f = 0;
		}
	}
	K = K + 1;
	level = -1;

	return level;

}





int main()
{
	cin >> F >> S >> G >> U >> D;
	int i2 = 0;

	

	int result = BFS(S);
	if (result == -1)
		cout << "use the stairs";
	else
		cout << result;


	return 0;
}


