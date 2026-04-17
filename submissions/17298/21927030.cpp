#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int N;


vector <int> input;

int check[1000001];

void getNGE() {
	
	stack <pair <int,int>> st;

	st.push({ 1, input[1] });

	for (int i = 2; i < input.size(); i++) {

		while (st.size()) {
			if (st.top().second < input[i]) {
				check[st.top().first] = input[i];
				st.pop();
			}
			else
				break;
		}

		st.push({ i, input[i] });
	}

}
int main() {
	cin >> N;

	input.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &input[i]);
	}

	getNGE();

	for (int i = 1; i <= N; i++) {
		if (check[i] == 0)
			printf("-1 ");
		else
			printf("%d ", check[i]);
	}

	//system("Pause");

}