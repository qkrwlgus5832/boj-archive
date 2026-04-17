#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>

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
int unionFind[101];


int find(int a) {
	if (unionFind[a] == -1) {
		return a;
	}
	return find(unionFind[a]);
}


void merge(int a, int b) {
	int parentA = find(a);
	int parentB = find(b);

	if (parentA < parentB) {
		unionFind[parentB] = parentA;
	}
	else {
		unionFind[parentA] = parentB;
	}
}


double spanningTree() {
	int edgeCount = 0;
	double result = 0;

	for (edge& edge_ : edges) {
		if (edgeCount == stars.size() - 1)
			break;
		
		int parentStar1 = find(edge_.star1);
		int parentStar2 = find(edge_.star2);

		if (parentStar1 != parentStar2) {
			result += edge_.cost;
			edgeCount++;
		}

	
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
	memset(unionFind, -1, sizeof(unionFind));

	cout.precision(3);
	cout << spanningTree();
	//system("Pause");
}