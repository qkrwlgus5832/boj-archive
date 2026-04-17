#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

bool rightdown[30];
bool rightup[30];
bool col[30];
bool row[30];
int answer = 0;
void recursion(int index, int count, int n) {
    if (count == n) {
		answer++;
		return;
	}
	for (int i = index; i < n*n; i++) {
		int starti = i / n;
		int startj = i % n;
		if (n - (starti +1) < n - (count+1))
			break;
		if (col[startj] == false && row[starti] == false && rightdown[starti + startj] == false && rightup[startj - starti + n] == false) {
			col[startj] = true;
			row[starti] = true;
			rightdown[starti + startj] = true;
			rightup[startj - starti + n] = true;

			recursion((starti + 1) * n, count + 1, n);
			col[startj] = false;
			row[starti] = false;
			rightdown[starti + startj] = false;
			rightup[startj - starti + n ] = false;
		}
	}

}


int solution(int n) {
	recursion(0, 0, n);
    return answer;
}

int main(){
	int N;
	cin >> N;
	solution(N);
	cout << answer;
}
