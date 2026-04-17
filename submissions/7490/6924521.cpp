#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
int number;
int N;
int N1[10];
void print() {
	for (int i = 1; i <= N; i++) {
		char a;
		if (N1[i] == 0)
			a = ' ';
		else if (N1[i] == 1)
			a = '+';
		else if (N1[i] == 2)
			a = '-';
		if (i == N)
			cout << i;
		else
		cout << i << a;
	
	}
	cout << endl;
}

int iszero() {
	int N2[10];
	int sum = 1;
	int num = 0;


	int i1 = 1;
	while (N1[i1] == 0) {
		if (i1 == 1)
			sum = i1 * 10 + (i1 + 1);
		else 
			sum = sum * 10 + (i1 + 1);
		i1++;

	}
	for (int i = 1; i <= N - 1; i++) {

		if (N1[i] == 1) {
			if (N1[i + 1] != 0 || i == N - 1)
				sum = sum + i + 1;

			else {
				int icc = i;
				while (N1[icc + 1] == 0) {
					if (icc == N-1)
						break;
					if (icc == i)
						num = (icc + 1) * 10 + (icc + 2);
					else
						num = num * 10 + (icc + 2);

					icc++;
				}
				sum = sum + num;


			}
		}




		if (N1[i] == 2) {
		
			if (N1[i + 1] != 0 || i == N - 1)
				sum = sum - (i + 1);
			else {
				int icc2 = i;
				while (N1[icc2 + 1] == 0) {			
					if (icc2 == N-1)
						break;
					if (icc2 == i)
						num = (icc2 + 1) * 10 + (icc2 + 2);
					else
						num = num * 10 + (icc2 + 2);
					icc2++;
				}
				sum = sum - num;
				
			}
		}
	}

	if (sum == 0)
		return 1;
	else
		return 0;
}





void recursion(int a) {

	if (a == N) {
		if (iszero()==1)
		print();
		return;
	}
	else {
		for (int i = 0; i <= 2; i++) {			
			N1[a] = i;
			recursion(a+1);
			}
			
		}	
	}



int main() {



	cin >> number;
	
	for (int i = 0; i < number; i++) {
		cin >> N;
		recursion(1);
		
		cout << endl;
	}
	

}