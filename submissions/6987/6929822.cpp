#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int a[18];
int a2[4];
int iseven = 0;
int chk();
int TT() {
	int fkfk = 0;
	int fkfk2 = 0;

		for (int i = 0; i <= 17; i++) {
			if (i % 3 == 0)
				fkfk = fkfk + a[i];
			if (i % 3 == 2)
				fkfk2 = fkfk2 + a[i];
		}
		
		
		if (fkfk == fkfk2) {
			if (fkfk + iseven / 2 == 15)
				return 1;
			else
				return 0;
		}
		else
			return 0;


}

int TT2() {
	iseven = 0;
	int isallone = 0;
	for (int i = 0; i <= 17; i++) {
		if (i % 3 == 1) {
			iseven = iseven + a[i];
			if (a[i] <= 1)
				isallone = isallone + 1;
		}
	}


	if (iseven % 2 == 0) {
		if (isallone == 6) {
			for (int i = 0; i <= 17; i = i + 3) {
				if (a[i] + a[i + 1] + a[i + 2] == 5)
					return 1;
			}
		}
		else {
			if (chk() == 1) {
				for (int i = 1; i <= 17; i = i + 3) {
					if (a[i] + a[i + 1] + a[i + 2] == 5)
						return 1;

				}
			}



			}
	
	}
	
	else
		return 0;

}


int chk() {
	for (int i = 1; i <= 17; i= i+3) {
		if (a[i] != 0) {
			iseven = iseven - a[i];
		}

		if (i != 16 && iseven == 0)
			return 0;

	}
	return 1;
}



int main() {
	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= 17; j++) {
			cin >> a[j];
		}
		a2[i] = TT2() && TT();
	}

	for (int i = 0; i <= 3; i++) {
		cout << a2[i] << " ";
	}
	

}