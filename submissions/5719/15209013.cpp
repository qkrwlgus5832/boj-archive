#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int minlength = INT_MAX;
vector < pair <int, int>> v[501];

int minpathcheck[501][501];
//int tmpcheck[501];
//bool dfscheck[501];


void dikstra(int i, int end, vector <pair <int, int>> v[501]) {
	priority_queue <pair<int, int>, vector <pair< int, int>>, greater <pair<int, int>>> q;
	bool check[501] = { false, };
	int distance[501] = { INT_MAX, };
	memset(distance, 1, sizeof(distance));
	int course[501] = { 0, };
	check[i] = true;
	distance[i] = 0;
	q.push(make_pair(0, i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		check[v1] = true;
		for (int i1 = 0; i1 < v[v1].size(); i1++) {
			if (check[v[v1][i1].first] == false) {
				if (distance[v[v1][i1].first] > dis + v[v1][i1].second) {
					distance[v[v1][i1].first] = dis + v[v1][i1].second;
					course[v[v1][i1].first] = v1;
					q.push(make_pair(dis + v[v1][i1].second, v[v1][i1].first));

				}

			}
		}
	}

	while (1) {
		
		minpathcheck[course[end]][end] = true;
		if (course[end] == i)
			break;

		end = course[end];
	}
}

//void DFS(int start, int end, int length) {
//	if (start == end) {
//		if (length < minlength) {
//			memcpy(check, tmpcheck, sizeof(check));
//			minlength = length;
//		}
//		return;
//	}
//	for (int i = 0; i < v[start].size(); i++) {
//		if (dfscheck[start] == false) {
//			tmpcheck[start] = v[start][i].first;
//			dfscheck[start] = true;
//			DFS(v[start][i].first, end, length + v[start][i].second);
//			dfscheck[start] = false;
//			tmpcheck[start] = 0;
//
//		}
//	}
//}

//int BFS(int start, int end) {
//	queue <pair <int,int>> q;
//	bool bfscheck[501] = { false, };
//	q.push(make_pair(start, 0));
//	bfscheck[start] = true;
//	int returnvalue = INT_MAX;
//	while (!q.empty()) {
//		int front = q.front().first;
//		int length = q.front().second;
//		q.pop();
//		if (front == end) {
//			returnvalue = min(returnvalue, length);
//			continue;
//		}
//		for (int i = 0; i < v[front].size(); i++) {
//			if (minpathcheck[front][v[front][i].first] == false && bfscheck[v[front][i].first] == false) {
//				bfscheck[v[front][i].first] = true;
//				q.push(make_pair(v[front][i].first , length + v[front][i].second));
//			}
//		}
//	}
//	if (returnvalue == INT_MAX)
//		return -1;
//	else
//		return returnvalue;
//}

int almostdikstra(int i, int end, vector <pair <int, int>> v[501]) {
	priority_queue <pair<int, int>, vector <pair< int, int>>, greater <pair<int, int>>> q;
	bool check[501] = { false, };
	int distance[502] = { INT_MAX, };
	memset(distance, 1, sizeof(distance));
	int course[501] = { 0, };
	check[i] = true;
	distance[i] = 0;
	q.push(make_pair(0, i));

	while (!q.empty()) {
		int dis = q.top().first;
		int v1 = q.top().second;
		q.pop();
		check[v1] = true;
		for (int i1 = 0; i1 < v[v1].size(); i1++) {
			if (check[v[v1][i1].first] == false && minpathcheck[v1][v[v1][i1].first] == false) {
				if (distance[v[v1][i1].first] > dis + v[v1][i1].second) {
					distance[v[v1][i1].first] = dis + v[v1][i1].second;
					course[v[v1][i1].first] = v1;
					q.push(make_pair(dis + v[v1][i1].second, v[v1][i1].first));

				}

			}
		}
	}
	if (distance[end] == distance[501])
	{
		return -1;
	}
	else
		return distance[end];
}

void setchecksfalse() {
	memset(minpathcheck, false, sizeof(minpathcheck));
	/*memset(tmpcheck, false, sizeof(tmpcheck));
	memset(dfscheck, false, sizeof(dfscheck));*/

}
int main() {
	int place, road;

	while (1) {

		vector < pair <int, int>> v[501];
		/*for (int i = 0; i < 500; i++) {
			v[i].clear();
		}*/
		scanf("%d %d", &place, &road);
		//cin >> place >> road;
		if (place == 0 && road == 0)
			break;
	
		int start, end;
		scanf("%d %d", &start, &end);
		//cin >> start >> end;
		int U, V, P;
		for (int i = 0; i < road; i++) {
			scanf("%d %d %d", &U, &V, &P);
			v[U].push_back(make_pair(V, P));
		}
		minlength = INT_MAX;
		
		setchecksfalse();

		dikstra(start, end, v);

		cout << almostdikstra(start, end, v) << endl;
		//cout << BFS(start, end) << endl;
	}
}