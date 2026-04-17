#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check[51];

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

vector <shark> v;

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


int main() {
	int N;
	cin >> N;

	int size, speed, smart;

	for (int i = 0; i < N; i++) {
		cin >> size >> speed >> smart;
		v.push_back(shark(size, speed, smart));
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (check[j] == false) {
				if (v[i].size >= v[j].size && v[i].speed >= v[j].speed && v[i].smart >= v[j].smart) {
					check[j] = true;
					count++;
					if (count == 2)
						break;
				}
			}
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			result++;
		}
	}
	cout << result;
	//system("Pause");
}

