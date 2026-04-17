#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int maxA, maxB, maxC;

set <int> result;
bool check[201][201][201];

class water {
public:
	int A;
	int B;
	int C;
};

queue <water> q;

pair <int, int> givewater(int giver, int receiver, int amount) {
	if (giver >= amount) {
		receiver += amount;
		giver -= amount;
	}
	else {
		receiver += giver;
		giver = 0;
	}
	return make_pair(giver, receiver);
}
pair <int, int> givewaterAtoB(water& tmp) {
	int amount = maxB - tmp.B;
	return givewater(tmp.A, tmp.B, amount);
}

pair <int, int> givewaterAtoC(water& tmp) {
	int amount = maxC - tmp.C;
	return givewater(tmp.A, tmp.C, amount);

}

pair <int, int> givewaterBtoA(water& tmp) {
	int amount = maxA - tmp.A;
	return givewater(tmp.B, tmp.A, amount);
}

pair <int, int> givewaterBtoC(water& tmp) {
	int amount = maxC - tmp.C;
	return givewater(tmp.B, tmp.C, amount);
}

pair <int, int> givewaterCtoA(water& tmp) {
	int amount = maxA - tmp.A;
	return givewater(tmp.C, tmp.A, amount);

}

pair <int, int> givewaterCtoB(water& tmp) {
	int amount = maxB - tmp.B;
	return givewater(tmp.C, tmp.B, amount);
}

void queuepush(water tmp) {
	if (check[tmp.A][tmp.B][tmp.C] == false) {
		check[tmp.A][tmp.B][tmp.C] = true;
		q.push(tmp);
	}
}
void givewaterA(water tmp) {
	pair <int, int > result;
	water tmp2 = tmp;
	result = givewaterAtoB(tmp);
	tmp.A = result.first; tmp.B = result.second;
	queuepush(tmp);
	tmp = tmp2;
	result = givewaterAtoC(tmp);
	tmp.A = result.first; tmp.C = result.second;
	queuepush(tmp);
}

void givewaterB(water tmp) {
	pair <int, int> result;
	water tmp2 = tmp;
	result = givewaterBtoA(tmp);
	tmp.B = result.first; tmp.A = result.second;
	queuepush(tmp);
	tmp = tmp2;
	result = givewaterBtoC(tmp);
	tmp.B = result.first; tmp.C = result.second;
	queuepush(tmp);
}

void givewaterC(water tmp) {
	pair <int, int> result;
	water tmp2 = tmp;
	result = givewaterCtoA(tmp);
	tmp.C = result.first; tmp.A = result.second;
	queuepush(tmp);
	tmp = tmp2;
	result = givewaterCtoB(tmp);
	tmp.C = result.first; tmp.B = result.second;
	queuepush(tmp);
}

void BFS() {
	water init;
	init.A = 0;
	init.B = 0;
	init.C = maxC;
	check[init.A][init.B][init.C] = true;
	q.push(init);
	while (!q.empty()) {
		water front = q.front();
		int nA = front.A;
		int nC = front.C;
		if (nA == 0) {
			result.insert(nC);
		}
		q.pop();
		givewaterA(front);
		givewaterB(front);
		givewaterC(front);
	}
}

int main() {
	cin >> maxA >> maxB >> maxC;

	BFS();

	auto setiterator = result.begin();

	while (setiterator != result.end()) {
		printf("%d ", *setiterator);
		setiterator++;
	}
	//system("Pause");
}