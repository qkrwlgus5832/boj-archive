#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a[3][10][10];
int a2[9][9];
int count = 1;
int i1[81];
int j1[81];
int f = 0;
int flag = 0;
int b[9][9] = {
	{ 0,0,0,1,1,1,2,2,2 },
	{ 0,0,0,1,1,1,2,2,2 },
	{ 0,0,0,1,1,1,2,2,2 },
	{ 3,3,3,4,4,4,5,5,5 },
	{ 3,3,3,4,4,4,5,5,5 },
	{ 3,3,3,4,4,4,5,5,5 },
	{ 6,6,6,7,7,7,8,8,8 },
	{ 6,6,6,7,7,7,8,8,8 },
	{ 6,6,6,7,7,7,8,8,8 } };
void chk(int i, int j,int count1);
int main() {

	int i, j;
	int x;
	int f = 0;
	int i3 = 1;

	
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			scanf("%1d", &x);
			if (x != 0) {
				a[0][i][x] = a[1][j][x] = a[2][b[i][j]][x] = 1;
				a2[i][j] = x;
			}
		}
	}


	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			if (a2[i][j] == 0) {
				i1[count] = i;
				j1[count] = j;
				count++;			
			}
		}
	}
	chk(i1[1], j1[1], 1);
	printf("\n");
	for (int q = 0; q <= 8; q++) {
		for (int q1 = 0; q1 <= 8; q1++) {
			printf("%d", a2[q][q1]);
		}
		printf("\n");

	}

}

int i3;
void chk(int i, int j, int count1) {
	if (count1 == count) {
		flag = 1;
		return;
	}
	else if (flag == 0) {
		for (int c =  1; c <= 9; c++)
		{
			if (a[0][i][c] == 0 && a[1][j][c] == 0 && a[2][b[i][j]][c] == 0) {		
				a[0][i][c] = a[1][j][c] = a[2][b[i][j]][c] = 1;
				a2[i][j] = c;
				chk(i1[count1 + 1], j1[count1 + 1], count1 + 1);
				if (flag == 1)
					return;
				a[0][i][c] = a[1][j][c] = a[2][b[i][j]][c] = 0;
				a2[i][j] = 0;
			}
				
			
			}
			
				
		}

	}

