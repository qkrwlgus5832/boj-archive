#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	long long N, k;
	cin >> N >> k;


	long long tmp = 0;

	int count = 0;

	while (1) {
		if (k < tmp)
			break;
		tmp += 9 * pow(10, count);
		count++;
	}

	tmp -= 9 * pow(10, count - 1);

	int rest = k - tmp;


	long long standard = pow(10, count - 1);

	
	if (standard + (rest - 1) / count > N)
		cout << -1;
	else {
		string number = to_string(standard + (rest - 1)/ count);
		cout << number[(rest - 1) % count];
	}

	//system("Pause");

}