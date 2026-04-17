#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair <char, int >> v;

bool compare(pair <char, int> a, pair <char, int > b) {
	return a.second < b.second;
}

int cardgame1() {
	sort(v.begin(), v.end(), compare);
	char color = v[0].first;
	for (int i = 1; i < 5; i++) {
		if (v[i].first != color) {
			return 0;
		}
	   if (v[i].second != v[i - 1].second + 1) {
			return 0;
		}
	}
	return v[v.size() - 1].second + 900;
}
int cardgame2() {
	int card[10] = { 0, };

	for (int i = 0; i < 5; i++) {
		card[v[i].second]++;
	}
	for (int i = 1; i <=10 ; i++) {
		if (card[i] == 4)
			return 800 + i;
	}
	return 0;
}

int cardgame3() {
	int card[10] = { 0, };

	for (int i = 0; i < 5; i++) {
		card[v[i].second]++;
	}
	int card3 = -1;
	int card2 = -1;
	for (int i = 1; i <= 10; i++) {
		if (card[i] == 3) {
			card3 = i;
		}
		
		else if (card[i] == 2) {
			card2 = i;
		}
	}
	if (card3 != -1 && card2 != -1)
		return card3 * 10 + card2 + 700;

	return 0;
}

int cardgame4() {
	char color = v[0].first;
	for (int i = 1; i < 5; i++) {
		if (v[i].first != color) {
			return 0;
		}
	}
	return v[v.size() - 1].second + 600;
}

int cardgame5() {

	for (int i = 1; i < 5; i++) {
		if (v[i].second != v[i - 1].second + 1) {
			return 0;
		}
	}
	return v[v.size() - 1].second + 500;
}

int cardgame6() {

	int card[10] = { 0, };

	for (int i = 0; i < 5; i++) {
		card[v[i].second]++;
	}

	int card3 = -1;

	for (int i = 1; i <= 10; i++) {
		if (card[i] == 3) {
			card3 = i;
		}

	}
	if (card3 != -1)
		return card3 + 400;

	return 0;
}

int cardgame7() {
	int card[10] = { 0, };

	for (int i = 0; i < 5; i++) {
		card[v[i].second]++;
	}

	int card1 = -1;
	int card2 = -1;

	for (int i = 1; i <= 10; i++) {
		if (card[i] == 2) {
			if (card1 == -1)
				card1 = i;
			else
				card2 = i;
		}
	}
	if (card1 != -1 && card2 != -1) {
		return max(card1, card2) * 10 + min(card1, card2) + 300;
	}

	return 0;
}
int cardgame8() {

	int card[10] = { 0, };

	for (int i = 0; i < 5; i++) {
		card[v[i].second]++;
	}

	int card1 = -1;
	int card2 = -1;

	for (int i = 1; i <= 10; i++) {
		if (card[i] == 2) {
			if (card1 == -1)
				card1 = i;
			else
				card2 = i;
		}

	}
	if (card1 != -1 || card2 != -1)
		return max(card1, card2) + 200;

	return 0;
}

int cardgame9() {

	return v[v.size() - 1].second + 100;
}

int main() {
	char tmp1;
	int tmp2;

	for (int i = 0; i < 5; i++) {
		cin >> tmp1 >> tmp2;
		v.push_back(make_pair(tmp1, tmp2));
	}

	int result = 0;

	result = max(result, cardgame1());
	result = max(result, cardgame2());
	result = max(result, cardgame3()); 
	result = max(result, cardgame4()); 
	result = max(result, cardgame5());
	result = max(result, cardgame6());
	result = max(result, cardgame7());
	result = max(result, cardgame8());
	result = max(result, cardgame9());

	cout << result;
	//system("Pause");
}