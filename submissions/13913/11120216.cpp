#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int check[1000001];

queue <int> q;
vector <int> v;

int N, K; int result;


void ch(int x) {
	if (check[x] == false) {
		q.push(x);
		check[x] = true;
	}
}
int BFS(int x) {
	q.push(x);
	check[x] = true;
	int level = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int x1 = q.front();

			q.pop();
			if (x1 == K)
				return level;
			if (x1 + 1 <= 100000)
				ch(x1 + 1);
			if (x1 - 1 >= 0)
				ch(x1 - 1);
			if (2 * x1 <= 100000)
				ch(2 * x1);
		}

		level++;

	}

}

int recursion(int x, int count) {

	if (x == K) {
		for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}
		return true;
	}
	if (count >= result)
		return false;

	if (x - 1 >= 0 && (check[x-1] == false || check[x-1]> v.size())) {
		check[x - 1] = v.size();
		v.push_back(x - 1);
	
		if (recursion(x - 1, count + 1))
			return true;
	
		v.pop_back();
	}


	if (x + 1 <= 100000 &&( check[x+1] == false|| check[x+1] > v.size())) {
		check[x + 1] = v.size();
		v.push_back(x + 1);
		
		if (recursion(x + 1, count + 1))
			return true;
	
		v.pop_back();
	}

	if (2 * x <= 100000 && (check[2*x] == false|| check[2*x] > count)) {
		check[2 * x] = v.size();
		v.push_back(2 * x); 
		if (recursion(2 * x, count + 1))
			return true;

		v.pop_back();
	}

	return false;
}

int main() {

	cin >> N >> K;
	 result = BFS(N);
	 cout << result << endl;
	 memset(check, 0, sizeof(check));
	v.push_back(N);
	check[N] = true;



	recursion(N, 0);
	


}

