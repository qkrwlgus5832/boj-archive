#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a1[50];
int flag;
int lotto[7];
int cnt;
int visited[50];
void print() {
	for (int j = 1; j <= 6; j++) {
		printf("%d ", lotto[j]);

	}
	printf("\n");
}


void recursion(int k, int count) {
	if (k == 7) {
		print();
		return;
	}

	for (int i = count; i <= a1[0]; i++) {
		lotto[k] = a1[i];
		recursion(k + 1, i + 1);
	}
}
	







int main() {
	while(1) {
		scanf("%d", &a1[0]);
		if (a1[0] == 0)
			break;
		for (int i = 1; i <= a1[0]; i++) {
			scanf("%d", &a1[i]);			
		}
	
		
		
		recursion(1, 1);

		
		printf("\n");
	}
	

}


