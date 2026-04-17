#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int N;

class shark {
public:
	int size;
	int speed;
	int smart;
	shark(int size, int speed, int smart) {
		this->size = size;
		this->speed = speed;
		this->smart = smart;
	}
};

vector <shark> sharks;

vector <int> graph[51];

int check[51];
bool binary_matching_check[51];

bool compare(shark a, shark b) {
	if (a.size == b.size) {
		if (a.speed == b.speed) {
			return a.smart < b.smart;
		}
		else
			return a.speed < b.speed;
	}
	else
		return a.size < b.size;
}

int binary_matching(int index, bool compete) {
	int count = 0;
	for (int i = 0; i < graph[index].size(); i++) {
		if (compete == false && count == 2)
			return true;
		else if (compete == true && count == 1)
			return true;

		if (check[graph[index][i]] == -1) {
			check[graph[index][i]] = index;
			count++;
		}
		else {
			if (check[graph[index][i]] == index)
				continue;

			if (binary_matching_check[index] == true)
				continue;

			if (binary_matching(check[graph[index][i]], true) == true) {
				check[graph[index][i]] = index;
			}
			binary_matching_check[index] = true;
		}
	}

	return false;
}

int main() {
	cin >> N;
	int size; int speed; int smart;

	memset(check, -1, sizeof(check));

	for (int i = 0; i < N; i++) {
		cin >> size >> speed >> smart;
		sharks.push_back(shark(size, speed, smart));
	}
	sort(sharks.begin(), sharks.end(), compare);


	for (int i = 0; i < sharks.size(); i++) {
		for (int j = 0; j <= i - 1; j++) {
			if (sharks[i].size >= sharks[j].size && sharks[i].speed >= sharks[j].speed && sharks[i].smart >= sharks[j].smart) {
				graph[i].push_back(j);
			}
		}
	}


	for (int i = 0; i < N; i++) {
		binary_matching(i, false);
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		if (check[i] == -1) {
			result++;
		}
	}
	cout << result;
	//system("Pause");
}
