#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


class star {
public:

	double x;
	double y;
	star(double x, double y) {
		this->x = x;
		this->y = y;
	}
	star() {}
};

struct edge {
	int star1;
	int star2;
	double cost;
	
};

vector <edge> edges;
vector <star> stars;
bool check[101];


double spanningTree() {
	int edgeCount = 0;
	double result = 0;

	for (edge& edge_ : edges) {
		if (edgeCount == stars.size() - 1)
			break;
		if (check[edge_.star1] && check[edge_.star2]) {
			continue;
		}
		check[edge_.star1] = true;
		check[edge_.star2] = true;
		result += edge_.cost;
		edgeCount++;

	
	}
	return result;
}

double getDistance(int i, int j) {
	star first = stars[i];
	star second = stars[j];

	return sqrt(pow(first.x - second.x, 2) + pow(first.y - second.y, 2));
}

int main() {
	int n;
	cin >> n;

	stars.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> stars[i].x >> stars[i].y;

	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edges.push_back({ i, j, getDistance(i, j) });
		}
	}
	sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
		return a.cost < b.cost;
	});

	cout.precision(3);
	cout << spanningTree();
	//system("Pause");
}