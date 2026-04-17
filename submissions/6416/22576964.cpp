#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


bool checkIfAnswer(map <int, int>& m) {
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second != 1)
			return false;
	}
	return true;
}

int main() {
	int u, v;

	int caseCount = 1;

	while (1) {
		map <int, int> m;
		while (1) {
			scanf("%d %d", &u, &v);

			m[v]++;

			if (u == 0 && v == 0)
				break;
			if (u == -1 && v == -1)
				return 0;
		}
	
		if (checkIfAnswer(m))
			printf("Case %d is a tree.\n", caseCount);
		else
			printf("Case %d is not a tree.\n", caseCount);

		caseCount++;
	}


//	system("Pause");
}
