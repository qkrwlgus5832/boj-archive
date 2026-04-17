#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector <vector <pair<int, int>>> v;
vector <pair<int, int>> v2;
int depth1[40001];

queue <int> q;
void bfs(int x1 ,int depth) {
	q.push(x1);
	while (!q.empty()) {
	
		int a = q.size();
		for (int i = 0; i < a; i++) {
			int x = q.front();
			q.pop();
			depth1[x] = depth;
			for (int i = 0; i < v[x].size(); i++) {
				int tmp = v[x][i].first;
				if (depth1[tmp] == 0) {
					q.push(tmp);
					v2[tmp].first = x;
					v2[tmp].second = v[x][i].second;
				}


			}
		}
		depth++;

	}


}
//void dfs(int x, int depth) {
//
//	depth1[x] = depth;
//
//	for (int i = 0; i < v[x].size(); i++) {
//		int tmp = v[x][i].first;
//		if (depth1[tmp] == 0) {
//			dfs(tmp, depth + 1);
//			v2[tmp].first = x;
//			v2[tmp].second = v[x][i].second;
//		
//		}
//	}
//}



int main() {
	cin >> N;
	int x, y, dis;
	v.resize(40002);
	v2.resize(40002);
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d %d", &x, &y, &dis);
		v[x].push_back(make_pair(y, dis));
		v[y].push_back(make_pair(x, dis));
	}

	
	bfs(1, 1);


	int tmp,  tmp2;


	cin >> M;




	for (int i = 0; i < M; i++) {
		long long result = 0;
		scanf("%d %d", &tmp, &tmp2);
		if (depth1[tmp] < depth1[tmp2]) {
			for (int i = 0; i < depth1[tmp2] - depth1[tmp]; i++) {
				result = result + v2[tmp2].second;
				tmp2 = v2[tmp2].first;
			
			}
		}
		else if (depth1[tmp] > depth1[tmp2]) {
			for (int i = 0; i < depth1[tmp] - depth1[tmp2]; i++) {
				result = result + v2[tmp].second;
				tmp = v2[tmp].first;
		
			}
		}
		while (1) {
			if (tmp == tmp2) {
				cout << result << endl;
					break;
			}
			result = result + v2[tmp].second;
			tmp = v2[tmp].first;
			result = result + v2[tmp2].second;
			tmp2 = v2[tmp2].first;
		

		}

	}

}