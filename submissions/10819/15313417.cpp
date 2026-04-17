#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <int> v;

bool check[9];
int result = 0;


int main() {
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	result += v[v.size() - 1] - v[0];
	check[v.size() - 1] = true;
	check[0] = true;
	int index = 0;

	while (1) {
		bool flag = false;
		if (v.size() - 1 - (index + 1) == index + 1) {
			result += max(abs(v[v.size() - 1 - (index + 1)] - v[index]), abs(v[index + 1] - v[v.size() - 1 - index]));
			check[index + 1] = true;
			flag = true;
			index++;
			continue;
		}
		 if (v.size() - 1 - (index + 1) >= 0 && check[v.size() - 1 - (index + 1)] == false) {
			result += abs(v[v.size() - 1 - (index + 1)] - v[index]);
			check[v.size() - 1 - (index + 1)] = true;
			flag = true;
		}

		
		 if (index+1 < N && check[index+1] == false) {
			result += abs(v[index+1] - v[v.size()-1 - index]);
			check[index+1] = true;
			flag = true;
		}

		if (flag == false)
			break;
		index++;
	}



	cout << result;
	//system("Pause");
}