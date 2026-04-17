#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

char graph[5][5];
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0} ,{0, 1} };

bool check[5][5];
int result = 0;




//class sevenprin {
//public:
//	int i;
//	int j;
//	int count;
//	sevenprin(int i, int j, int count) {
//		this->i = i;
//		this->j = j;
//		this->count = count;
//	}
//};

bool BFS() {
	queue <pair <int, int>> q;
	bool bfscheck[5][5] = { false, };
	bool f = false;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (check[i][j] == true) {
				q.push(make_pair(i,j));
				bfscheck[i][j] = true;
				f = true;
				break;
			}
		}
		if (f == true)
			break;
	}

	int checkseven = 1;

	while (!q.empty()) {
		int s = q.size();
		for (int qcount = 0; qcount < s; qcount++) {
			pair <int, int> front = q.front();
			q.pop();
			for (int i1 = 0; i1 < 4; i1++) {
				int ni = front.first + dir[i1][0];
				int nj = front.second + dir[i1][1];
				if (ni < 0 || nj < 0 || ni >= 5 || nj >= 5)
					continue;
				if (check[ni][nj] == true && bfscheck[ni][nj] == false) {
					bfscheck[ni][nj] = true;
					checkseven++;
					q.push(make_pair(ni, nj));
				}

						
			}
		}
		
		if (checkseven == 7) {
			return true;
		}
	}

	return false;
}

vector <int> v;
	
void recursion(int count, int i1, int dasomcount) {

	if (count == 7) {
		if (dasomcount >= 4) {
			if (BFS() == true) {
				result++;
			}
		}
	
		return;
	}
	if (7 - count < 4 - dasomcount)
		return;

	for (int i = i1; i < 25; i++) {
		check[i / 5][i % 5] = true;
	
		if (graph[i / 5][i % 5] == 'S')
			recursion(count + 1 , i+1, dasomcount + 1);
		else
			recursion(count + 1, i+1, dasomcount);
		check[i / 5][i % 5] = false;
	
	}
	

}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	
	recursion(0, 0, 0);

	cout << result;
	//system("Pause");
}