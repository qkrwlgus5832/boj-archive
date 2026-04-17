#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int N;
int M;
int Matrix[100][100];
int tmp[100][100];
int box[1000];
bool check[1000][1000];
queue <int> q;

int count2 = 0;
int tcount2; 
void disseminate(int x, int y);



void bfs(int x,int y) {
	
	q.push(x*M + y);
	while (!q.empty()) {
		int a2 = q.size();
		for (int i = 0; i < a2; i++) {
			int now = q.front();
			q.pop();

			int x2 = now / M;
			int y2 = now % M;

			disseminate(x2, y2);
			check[x2][y2] = true;

		}
	}




}




void disseminate(int x,int y) {
	if (y < N - 1 && Matrix[x][y + 1] == 0) {
		Matrix[x][y + 1] = 2;
		if (check[x][y+1] == false)
		q.push(x*M + (y + 1));
	}
	if (y >= 1 && Matrix[x][y - 1] == 0 ) {
		Matrix[x][y - 1] = 2;
		if (check[x][y-1] == false)
		q.push(x*M + (y - 1));
	}

	if (x >= 1 && Matrix[x - 1][y] == 0 ) {
		Matrix[x - 1][y] = 2;
		if (check[x-1][y] == false)
		q.push((x - 1)*M + (y));
	}

	if (x<M - 1 && Matrix[x + 1][y] == 0 ) {
		Matrix[x + 1][y] = 2;
		if (check[x+1][y] == false)
		q.push((x + 1)*M + (y));
	}




}



int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tmp[i][j];
			Matrix[i][j] = tmp[i][j];
		}
	}




	int count1 = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				box[count1] = i*M + j;
				count1 = count1 + 1;
			}
		}
	}



	
	for (int i = 0; i < count1; i++) {
		for (int j = i + 1; j < count1; j++) {
			for (int i1 = j + 1; i1 < count1; i1++) {
		
				Matrix[box[i] / M][box[i] % M] = 1;
				Matrix[box[j] / M][box[j] % M] = 1;
				Matrix[box[i1] / M][box[i1] % M] = 1;


				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < M; j2++) {
						if (Matrix[i2][j2] == 2) {
							if (check[i2][j2] == false)
								bfs(i2,j2);
						}
					}
				}
				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < M; j2++) {
						if (Matrix[i2][j2] == 0)
							count2 = count2 + 1;
					}
				}

				
				if (i == 0 && j == 1 && i1 == 2)
					tcount2 = count2;
				else if (tcount2 <= count2) {
					tcount2 = count2;
				}

				count2 = 0;



				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < M; j2++) {
						Matrix[i2][j2] = tmp[i2][j2];
					}

				}
				for (int i2 = 0; i2 < N; i2++) {
					for (int j2 = 0; j2 < M; j2++) {
						check[i2][j2] = false;
					}

				}

			}
		}
	}


	

	cout << tcount2;

	

}

