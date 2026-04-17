#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;






int sum = 2;


void recursion(int N) {
	if (N == 0)
		return;

	recursion(N - 1);



	sum = sum + (sum - 1);


}



int n;
int main() {
	cin >> n;

	 recursion(n);
	 cout << sum * sum;

}
