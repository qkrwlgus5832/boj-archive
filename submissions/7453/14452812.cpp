#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector <int> A;
vector <int> B;
vector <int> C;
vector <int> D;

int N1[4];
int n;

int result = 0;

bool checkIfAnswer() {
	int sum = 0;
	
	sum += A[N1[0]];
	sum += B[N1[1]];
	sum += C[N1[2]];
	sum += D[N1[3]];

	if (sum == 0)
		return true;
	else
		return false;
}
void recursion(int count) {
	if (count == 4) {
		if (checkIfAnswer() == true)
			result++;
		return;
	}

	for (int i = 0; i < n; i++) {
		N1[count] = i;
		recursion(count + 1);
		//N1[count] = 0;
	}

}
int main() {
	cin.tie(NULL);
	cin >> n;

	int a, b, c, d;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);

	}

	recursion(0);

	cout << result;
	//system("Pause");
}