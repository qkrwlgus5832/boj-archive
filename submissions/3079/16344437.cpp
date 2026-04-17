#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

bool getCustomerCount(long long x, vector <int> times, int n) {
	unsigned long long count = 0;
	for (int i = 0; i < times.size(); i++) {
		count += x / times[i];
		if (count >= n)
			return true;
	}
	return false;
}

long long binary_search_(long long start, long long end, long long n, vector <int> times) {
	if (start == end) {
		return start;
	}
	else if (start + 1 == end) {
		if (getCustomerCount(start, times, n) == true)
			return start;
		else
			return end;
	}
	bool customcount = getCustomerCount((start + end) / 2, times, n);
	if (customcount) {
		return binary_search_(start, (start + end) / 2, n, times);
	}
	else  {
		return binary_search_((start + end) / 2 + 1, end, n, times);
	}


}
long long solution(int n, vector<int> times) {
	long long answer = 0;
	return binary_search_(0, (long long) times[0] * n, n, times);

}

int main() {
	int N, M;
	cin >> N >> M;
	int tmp;
	vector <int> times;

	
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		times.push_back(tmp);
	}
	sort(times.begin(), times.end());
	cout << solution(M, times);
	//system("Pause");
}