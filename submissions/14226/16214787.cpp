#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>
using namespace std;

map <pair <int, int>, int> check;

int BFS(int S) {
	queue <pair <int, int>> q;
	check[{1, 0}] = 1;
	q.push(make_pair(1, 0));
	int t = 0;
	while (!q.empty()) {
		int qs = q.size();
		for (int s = 0; s < qs; s++) {
			pair <int, int> front = q.front();
			q.pop();
			if (front.first == S)
				return t;
			if (check.count({ front.first, front.first }) == 0) {
				q.push(make_pair(front.first, front.first));
				check[{front.first, front.first}] = true;
			}
			
			if (check.count({front.first + front.second, front.second}) == 0) {
				q.push(make_pair(front.first + front.second, front.second));
				check[{front.first + front.second, front.second}] = true;
			}
			if (front.first - 1 >= 0 && check.count({front.first - 1, front.second}) == 0) {
				q.push(make_pair(front.first - 1, front.second));
				check[{front.first - 1, front.second}] = true;
			}
		}
		t++;
	}

}

int main() {
	int S;
	cin >> S;

	cout << BFS(S) << endl;
	
	//system("Pause");
}