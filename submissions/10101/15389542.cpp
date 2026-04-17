#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int angle1;
int angle2;
int angle3;

int main() {
	cin >> angle1;
	cin >> angle2;
	cin >> angle3;

	if (angle1 == 60 && angle2 == 60 && angle3 == 60)
		cout << "Equilateral";
	else if ((angle1 + angle2 + angle3) == 180) {
		if (angle1 == angle2 || angle2 == angle3 || angle1 == angle3) {
			cout << "Isosceles";
		}
		else
			cout << "Scalene";
	}
	else if ((angle1 + angle2 + angle3) != 180) {
		cout << "Error";
	}
	//system("Pause");
	
}