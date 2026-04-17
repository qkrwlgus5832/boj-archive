#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector <string> magicstar;

vector <pair <int, int>> xposition;

bool check[13];

int result = 0;


vector <int> v[5][9];



bool leftdown(pair <int, int> standardposition) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += magicstar[standardposition.first + i][standardposition.second - i] - 'A' + 1;
	}

	if (sum == 26)
		return true;
	else
		return false;
}


bool rightdown(pair <int, int> standardposition) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += magicstar[standardposition.first + i][standardposition.second + i] - 'A' + 1;
	}

	if (sum == 26)
		return true;
	else
		return false;
}


bool right(pair <int, int> standardposition) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += magicstar[standardposition.first][standardposition.second + i * 2] - 'A' + 1;
	}

	if (sum == 26)
		return true;
	else
		return false;
}

int checkIfMagicStar() {
	if (leftdown(make_pair(0, 4)) && rightdown(make_pair(0, 4)) && right(make_pair(3, 1)) && rightdown(make_pair(1, 1)) && right(make_pair(1, 1)) && leftdown(make_pair(1, 7)))
		return 1;
	else
		return 0;
}

int count1 = 0;

void recursion(int index) {
	if (result == 1)
		return;

	if (index == xposition.size()) {
		if (checkIfMagicStar()) {
		
			for (int i = 0; i < magicstar.size(); i++) {
				for (int j = 0; j < magicstar[i].size(); j++) {
					cout << magicstar[i][j];
				}
				cout << endl;
			}
		
			result = 1;
		}
		return;
	}

	for (int i = 1; i <= 12; i++) {
		if (check[i] == false) {
			magicstar[xposition[index].first][xposition[index].second] = (i-1) + 'A';
			check[i] = true;
			recursion(index + 1);
			check[i] = false;
			magicstar[xposition[index].first][xposition[index].second] = 'x';
		}
	}

}


int main() {
	cin.tie(NULL);
	string input;
	for (int i = 0; i < 5; i++) {
		cin >> input;
		for (int i1 = 0; i1 < input.size(); i1++) {
			if (input[i1] >= 'A' && input[i1] <= 'L')
				check[input[i1] - 'A' + 1] = true;
			else if (input[i1] == 'x') 
				xposition.push_back(make_pair(i, i1));
		}
		magicstar.push_back(input);

	}
	

	recursion(0);

	//magicstar[0][4] = 'F';
	//magicstar[1][7] = 'L';
	//magicstar[2][2] = 'H';
	//magicstar[2][6] = 'E';

	//magicstar[3][1] = 'C';
	//magicstar[3][3] = 'J';
	//magicstar[3][5] = 'B';
	//magicstar[3][7] = 'K';
	//magicstar[4][4] = 'G';

	//cout << endl;
	//cout << checkIfMagicStar();

	//system("Pause");

}