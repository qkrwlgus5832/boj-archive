#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int sumMoney = 0;
int sumTime = 0;
int result = 0;
int N, T;

vector <pair <int, int>> v;


void recursion(int index, int time, int money) {
	
	if (sumTime - time <= T) {
		result = max(result, sumMoney - money);
		return;
	}
	for (int i = index; i < v.size(); i++) {
		recursion(i + 1, time + v[i].first, money + v[i].second);
	}
}

int main() {

	cin >> N >> T;


	int walkTime, walkMoney, bicycleTime, bicycleMoney;


	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &walkTime, &walkMoney, &bicycleTime, &bicycleMoney);
		if (walkMoney > bicycleMoney) {
			sumMoney += walkMoney;
			sumTime += walkTime;

			if (walkTime > bicycleTime) {
				v.push_back({ walkTime - bicycleTime, walkMoney - bicycleMoney });
			}
		}
		else {
			sumMoney += bicycleMoney;
			sumTime += bicycleTime;

			if (bicycleTime > walkTime) {
				v.push_back({ bicycleTime - walkTime, bicycleMoney - walkMoney });
			}
		}
	}

	sort(v.begin(), v.end());

	recursion(0, 0, 0);

	cout << result;

	//system("Pause");
}
