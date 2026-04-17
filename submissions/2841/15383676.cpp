#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>	

using namespace std;


int N, P;

deque <int> st[7];

int stackpush(int line, int plat) {
	if (st[line].size() == 0) {
		st[line].push_back(plat);
		return 1;
	}
	if (st[line].back() == plat)
		return 0;
	else if (st[line].back() < plat) {
		st[line].push_back(plat);
		return 1;
	}
	else if (st[line].back() > plat) {
		int count = 0;

		while (st[line].size()) {
			 if (st[line].back() > plat) {
				count++;
				st[line].pop_back();
			}
			else if (st[line].back() < plat) {
				st[line].push_back(plat);
				return count + 1;
			}
			else {
				//st[line].push_back(plat);
				return count;
			}
		}
		st[line].push_back(plat);
		return count + 1;
	}
}

int main() {
	cin >> N >> P;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp1, tmp2;
	int result = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		result += stackpush(tmp1, tmp2);
	}
	cout << result;
	//system("Pause");
}
