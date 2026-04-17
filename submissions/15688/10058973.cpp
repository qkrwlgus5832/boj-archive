#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N1[5000001];

vector <int> merge(int i, int j, int i1, int j1) {
	vector <int> v;
	while (1) {
		if (i == j + 1 && i1 == j1 + 1)
			break;
		if (i <= j && i1 <= j1) {
			if (N1[i] < N1[i1]) {
				v.push_back(N1[i]);
				i++;

			}
			else {
				v.push_back(N1[i1]);
				i1++;
		
			}
		}
		else if (i <= j) {
			v.push_back(N1[i]);
			i++;
		
		}
		else if (i1 <= j1) {
			v.push_back(N1[i1]);
			i1++;
		
		}
	}

	return v;
}



void Quicksort(int l, int r) {

	if (r >l && r - l > 1) {
		int midium = (l + r) / 2;
		if (N1[l] > N1[r])
			swap(N1[l], N1[r]);
		if (N1[l] > N1[midium])
			swap(N1[l], N1[midium]);
		if (N1[midium] > N1[r])
			swap(N1[midium], N1[r]);

		swap(N1[midium], N1[r - 1]);

		int i = l;
		int j = r-1;
		while (1) {
			while (N1[++i] < N1[r-1]);
			while (N1[--j] > N1[r-1]);
			if (i >= j)
				break;
			swap(N1[i], N1[j]);

		
		}

		swap(N1[i], N1[r-1]);
		Quicksort(l,i-1);
		Quicksort(i+1, r);


	}
	else if (r-l ==1 ){
		if (N1[l] > N1[r])
			swap(N1[l], N1[r]);
	}

}


int main() {
	int N;
	cin >> N;


	for (int i = 1; i <= N; i++) {
		scanf("%d", &N1[i]);
	}

	N1[0] = -1;


	 Quicksort(1, N / 2);



	 Quicksort(N / 2 + 1, N);


	vector <int> v =  merge(1, N / 2, N / 2 + 1, N);

	for (int i = 0; i < v.size(); i++ ) {
		printf("%d\n", v[i]);
	}
}