#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;



int length, width, hegiht;
int N;
priority_queue <pair <int, int>> pq;




int main() {
	cin >> length >> width >> hegiht;


	cin >> N;
	int mokpyo = length * width * hegiht;
	int tmp1, tmp2;


	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);
		tmp1 = pow(2, tmp1);
		tmp1 = pow(tmp1, 3);
		pq.push(make_pair(tmp1, tmp1*tmp2));

	}


	long long result = 0;
	for (int i = 0; i < pq.size(); i++)
	{
		if (mokpyo == 0) {
			break;
		}

		if (pq.top().second > mokpyo) {
			if (mokpyo > pq.top().first) {
				result += mokpyo / pq.top().first;
				mokpyo = mokpyo % pq.top().first;

			}
			else {
				continue;
			}
		}
		else {
			mokpyo = mokpyo - pq.top().second;
			result = result + pq.top().second / pq.top().first;
		}
		pq.pop();
	}

	if (mokpyo == 0)
		cout << result;
	else
		cout << -1;

}