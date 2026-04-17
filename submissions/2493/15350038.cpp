#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N;

vector <int> v;
vector <pair <int, int>> stack;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		bool flag = false;
		for (int j = stack.size() - 1; j >= 0; j--) {
			if (stack[j].first > v[i]) {
				flag = true;
				cout << stack[j].second + 1 << " ";
				break;
			}
		}
		if (flag == false) {
			cout << 0 << " ";
		}
		if (i == 0 || (i > 0 && v[i-1] > v[i])) {
			stack.push_back(make_pair(v[i], i));
		}
		else if (i > 0 && v[i - 1] < v[i] && i+1 < N && v[i] > v[i+1]) {
			stack.push_back(make_pair(v[i], i));
		}
	}	
	//system("Pause");
}