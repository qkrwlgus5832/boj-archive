#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N;
int M;
vector <int> v;
int Queue[1000];


int Rear = 0;
int Head = 0;
int Rear2 = 0;
int Head2 = 0;
int Rear3 = 0;
int Head3 = 0;

void put(int num) {
	Queue[Rear] = num;
	Rear = Rear + 1;
	Rear = Rear % N;
}

int Get(int Head) {
	Head = Head + 1;

	Head = Head % N;


	return Head;

}

int min(int i, int Rear, int Head) {
	int count = 0;
	while (1) {
		if (Queue[Head] == v[i]) {
		
			Head = Get(Head);
			break;
		}
		else {
			if (Queue[Head] != 0)
				count++;
		
			Head = (Head + 1) % N;
			Rear = (Rear + 1) % N;
		}
	}
	Rear2 = Rear;
	Head2 = Head;

	return count;
}

int min2(int i, int Rear, int Head) {
	int count = 0;
	
	while (1) {
		if (Queue[Head] == v[i]) {
			
			Head = Get(Head);
			break;
		}
		else {
			if (Queue[Head] != 0)
				count++;
			
			Rear = Rear - 1;
			if (Rear < 0)
				Rear = Rear + N;
			Head = (Head - 1);
			if (Head < 0)
				Head = Head + N;
			
		}
	}
	Rear3 = Rear;
	Head3 = Head;

	return count;
}








int main() {
	cin >> N >> M;
	int tmp;



	for (int i = 1; i <= N; i++) {
		put(i);
	}

	int result = 0;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}


	Head = 0;
	Rear = N - 1;


	
	for (int i = 0; i < M; i++) {
		int a = min(i, Rear, Head);

		int b = min2(i, Rear, Head);
		
		if (a < b) {
			Rear = Rear2;
			Head = Head2;
			result = result + a;
			if (Head >= 1)
				Queue[Head - 1] = 0;
			else
				Queue[Head + N] = 0;

		}
		else {
			Rear = Rear3;
			Head = Head3;
			result = result + b;
			if (Head >= 1)
				Queue[Head - 1] = 0;
			else
				Queue[Head + N] = 0;
		}

	}

	cout << result;
	

}

