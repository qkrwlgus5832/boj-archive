#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>



using namespace std;

vector <int> v;

int result = 0;

int N, C, W;
class tree {
public:
	int value;
	int cuttedcount;
	int sellcount;
	tree(int cuttedcount, int sellcount) {
		 this->cuttedcount = cuttedcount;
		this->sellcount = sellcount;
	}
};
int BFS(int x) {

	queue <tree> q;

	q.push(tree(0,0));

	int depth = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int cuttedcount = q.front().cuttedcount;
			int sellcount = q.front().sellcount;

			q.pop();

			tree tmp(cuttedcount, sellcount);
			q.push(tmp);

			int treelength = v[depth];
			int count = 0;
			while (1) {
			
				 if (treelength == x) {
					treelength -= x;
					q.push(tree( cuttedcount + count, sellcount + count + 1));
				}
				 else if (treelength > x) {
					 treelength -= x;
					 count++;
					 q.push(tree( cuttedcount + count, sellcount + count));
					 
				 }
				else
					break;
			}
		}
		depth++;
		
		if (depth == v.size()) {
			int result = 0;
			while (!q.empty()) {
				result = max(result, x * q.front().sellcount * W - C * q.front().cuttedcount);
				q.pop();
			}
			return result;
		}
	}
}
int main() {
	
	cin >> N >> C >> W;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= v[v.size() - 1]; i++) {
		result= max(result, BFS(i));
	}

	cout << result;
	//system("Pause");
}