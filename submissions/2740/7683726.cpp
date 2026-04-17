#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int A[1000][1000];
int B[1000][1000];
int C[1000][1000];

int N;
int M;
int K;

void multiply() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int i1 = 0; i1 < M; i1++) {
				C[i][j] = C[i][j]+A[i][i1] * B[i1][j];
			}
		}
	}



}






int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cin >> M >> K;


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}


	multiply();
	for (int i = 0; i <N ; i++) {
		for (int j = 0; j < K; j++) {
			cout<<  C[i][j] << " ";
		}
		cout << endl;
	}
}