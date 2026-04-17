#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;


vector <string> b;

int binary_search(int x, int y, string x1) {
	if (x == y) {
		if (b[x] == x1)
			return 1;
		else
			return 0;

	}
	 else if (b[(x + y) / 2] == x1)
		return 1;

	else if (b[(x + y) / 2] < x1)
		return binary_search(x, (x + y) / 2, x1);

	else if (b[(x + y) / 2 ]> x1)
		return binary_search((x + y) / 2 + 1, y, x1);

}



string rotation(string a) {
	string tmp = a;

	for (int i = 1; i <= a.size() / 2; i++) {
		swap(tmp[tmp.size() / 2 - i], tmp[tmp.size() / 2 + i]);
	}

	return tmp;
}




int main() {
	cin >> N;
	string result;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		b.push_back(tmp);
	}
	
	sort(b.begin(), b.end());
	for (int i = 0; i < N; i++) {
		if (binary_search(0, N - 1, rotation(b[i]))==1)
			result = b[i];
	}

	cout << result.size() << " " << result[result.size() / 2];
}