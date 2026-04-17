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
vector <pair <int, int>> v2[501];

int minpathcheck[501][501];
//int tmpcheck[501];
//bool dfscheck[501];


void BFS(int start,int end, int distance[502] ,vector <pair <int, int>> v2[501]) {
	queue <int> q;
	q.push(end);
	
	while (!q.empty()) {
		int end = q.front();


		q.pop();

		if (end == start) {
			continue;
		}
		for (int i = 0; i < v2[end].size(); i++) {
			if (distance[end] == v2[end][i].second + distance[v2[end][i].first]) {
				minpathcheck[v2[end][i].first][end] = true;
				q.push(v2[end][i].first);
			}
		}
	}
}

int dikstra(int i, int end, vector <pair <int, int>> v[501], vector <pair <int, int>> v2[501]) {
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
			if (check[v[v1][i1].first] == false) {
				if (distance[v[v1][i1].first] > dis + v[v1][i1].second) {
					distance[v[v1][i1].first] = dis + v[v1][i1].second;
					course[v[v1][i1].first] = v1;
					q.push(make_pair(dis + v[v1][i1].second, v[v1][i1].first));
				}
			}
		}
	}

	if (distance[end] == distance[501])
		return -1;

	int dist = distance[end];


	BFS(i, end, distance, v2);

	return dist;
}

int almostdikstra(int i, int end, vector <pair <int, int>> v[501] , int dist) {
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
					if (v[v1][i1].first == end && dis + v[v1][i1].second == dist)
						continue;
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
}
int main() {
	int place, road;

	while (1) {

		vector < pair <int, int>> v[501];
		vector < pair <int, int>> v2[501];
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
			v2[V].push_back(make_pair(U, P));
		}
		minlength = INT_MAX;
		
		setchecksfalse();

		int dist;
		dist = dikstra(start, end, v, v2);
		if (dist == -1)
			printf("-1\n");
		else
			printf("%d\n", almostdikstra(start, end, v, dist));
		//cout << BFS(start, end) << endl;
	}
	//system("Pause");
}