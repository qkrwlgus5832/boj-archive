#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;


bool checkIfAnswer(map <int, int>& m, map <int, int>& m2) {
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second != 1)
			return false;
	}
	int count = 0;

	for (auto iter = m2.begin(); iter != m2.end(); iter++) {
		if (m[iter->first] == 0)
			count++;
		else if (m[iter->first] != 1)
			return false;
	
	}
	if (count == 1)
		return true;
	return false;
}

int main() {
	int u, v;

	int caseCount = 1;

	while (1) {
		map <int, int> m;
		map <int, int> m2;

		while (1) {
			scanf("%d %d", &u, &v);

			m[v]++;
			m2[u]++;

			if (u == 0 && v == 0)
				break;
			if (u == -1 && v == -1)
				return 0;
		}
	
		if (checkIfAnswer(m, m2))
			printf("Case %d is a tree.\n", caseCount);
		else
			printf("Case %d is not a tree.\n", caseCount);

		caseCount++;
	}


//	system("Pause");
}
