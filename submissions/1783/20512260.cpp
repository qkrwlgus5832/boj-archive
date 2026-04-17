#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int N, M;

int main() {
	cin >> N >> M;

	if (N == 1) { // N=1 일때는 갈 수가 없으므로 1을리턴한다.
		cout << 1;
	}
	else if (N == 2) {  // 가로기준으로 +2만큼씩 이동 가능
		cout << (M - 1) / 2 + 1;
	}
	else {
		if (M<=4){ // 4번보다 적은 경우 이동 방법에 제한이 없으므로
			cout << M;
		}
		else if (M == 5) {
			cout << 4;
		}
		else { // 2,3번을 꼭 포함해야 하므로 처음에 포함시켜준다.
			M = M - 5;
			cout << M + 3;
		}
	}
	//system("Pause");
}