#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int N, M;

int map[21][21];

int dice[7];

int top_ = 1;
int bottom_ = 6;
int front_ = 5;
int back_ = 2;

int right_ = 3;
int left_ = 4;


//int dicedirection[7][5] = {
//	{0,},
//	{6,3,4,2,5},
//	{5,3,4,6,1},
//	{4,6,1,2,5},
//	{3,1,6,2,5},
//	{2,3,4,1,6},
//	{1,3,4,2,5}
//};

void set(int top, int bottom,int front, int back, int right, int left) {
	top_ = top;
	bottom_ = bottom;
	front_ = front;
	back_ = back;
	right_ = right;
	left_ = left;
}
void godong() {
	int tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft;

	tmptop = left_;
	tmpbottom = right_;
	tmpfront = front_;
	tmpback = back_;

	tmpright = top_;
	tmpleft = bottom_;

	set(tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft);
}

void goseo() {
	int tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft;

	tmptop = right_;
	tmpbottom = left_;
	tmpfront = front_;
	tmpback = back_;
	tmpright = bottom_;
	tmpleft = top_;
	
	set(tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft);

}
void gonam() {
	int tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft;

	tmptop = back_;
	tmpbottom = front_;

	tmpfront = top_;
	tmpback = bottom_;

	tmpright = right_;
	tmpleft = left_;

	set(tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft);

}
void gobuk() {
	int tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft;

	tmptop = front_;
	tmpbottom = back_;

	tmpfront = bottom_;
	tmpback = top_;

	tmpright = right_;
	tmpleft = left_;

	set(tmptop, tmpbottom, tmpfront, tmpback, tmpright, tmpleft);

}

int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

int main() {
	int x, y;
	int K;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int tmp;

	for (int i = 0; i < K; i++) {
		scanf("%d", &tmp);
		if (x + dir[tmp - 1][0] <0 || y + dir[tmp - 1][1] <0 || x + dir[tmp - 1][0] >= N || y + dir[tmp - 1][1] >= M)
			continue;
		x += dir[tmp - 1][0];
		y += dir[tmp - 1][1];
	/*	if (x  <0 || y < 0 || x > N || y  > M)
			continue;
*/
		if (tmp == 1) {
			godong();
		}
		else if (tmp == 2) {
			goseo();
		}
		else if (tmp == 3) {
			gobuk();
		}
		else if (tmp == 4) {
			gonam();
		}
		if (map[x][y] == 0) {
			map[x][y] = dice[bottom_];
		}
		else {
			dice[bottom_] = map[x][y];
			map[x][y] = 0;
		}
		printf("%d\n", dice[top_]);
	}
	
	system("Pause");
}