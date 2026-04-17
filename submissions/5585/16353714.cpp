#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>


using namespace std;


vector <int> changesPoint;
int money;

int main() {
	changesPoint.push_back(500);
	changesPoint.push_back(100);
	changesPoint.push_back(50);
	changesPoint.push_back(10);
	changesPoint.push_back(5);
	changesPoint.push_back(1);
	cin >> money;
	money = 1000 - money;
	int result = 0;

	int index = 0;
	while (1) {
		if (money >= changesPoint[index]) {
			result += money / changesPoint[index];
		}
		money = money % changesPoint[index];
		if (money == 0)
			break;
		index++;
	}
	cout << result;
	//system("Pause");
}