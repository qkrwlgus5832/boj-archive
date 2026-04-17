#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n;
int N[100001];
char N2[100001];
char N3[100001];
int i3 = 0;
int i4 = 0;
stack <int> st;
int sequence() {
	int i2 = 0;
	
	for (int i = 1; i <= n; i++) {
		if (N[i2] != i) {
			N3[i4++] = i;
			N2[i3] = '+';
			i3 = i3 + 1;
		}
		else {
			N2[i3] = '+';
			i3 = i3 + 1;
			N2[i3] = '-';
			i3 = i3 + 1;
			i2 = i2 + 1;
		
			int q2 = i4;
			for (int j = 0; j <q2; j++) {
				if (N[i2] == N3[i4-1]) {
					N3[i4 - 1] = 0;
					i4--;
					N2[i3] = '-';
					i3 = i3 + 1;
					i2 = i2 + 1;
				}
			}
		
		}
	}
	if (st.empty() == 1 && i2 == n)
		return 1;
	else
		return 0;
	
}





int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}

	cout << endl;

	if (sequence() == 1)
	{
		for (int i = 0; i < i3; i++)
			cout << N2[i] << endl;
	}
	else {
		cout << "NO" << endl;
	}
	

}