#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int N, K, K1;
int love[501];
vector <int> v;


double buwnsvusck(int x, int K) {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += love[x + i];
	}
	double m = (double)sum / (double)K;

	double V = 0;
	for (int i = 0; i < K; i++)
	{
		V += pow(love[x + i] - m, 2);
	}
	V = V / (double)K;
	return abs((sqrt(V)));




}
int main() {

	cin >> N >> K1;
	for (int i = 0; i < N; i++) {
		cin >> love[i];
	}




	double min1 = 0;



	for (int K = K1; K <= N; K++) {
		double min = 0;
		for (int i = 0; i < N; i++) {
			double result = 0;
			int f = 0;
			if (i + K - 1 < N) {
				result = buwnsvusck(i, K);
				f = 1;
			}

			if (i == 0)
				min = result;
			else if (min >= result && f == 1) {
				min = result;
			}

		}


		if (K == K1)
			min1 = min;
		else
			if (min1 >= min)
				min1 = min;
	}


	printf("%.11f", min1);

	


}