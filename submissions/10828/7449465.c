#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <cstdio>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10002
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return (top == -1);

}

int size() {
	return top + 1;
}



void push(element item) {

	if (top == MAX_STACK_SIZE - 1)
		return;
	else
		stack[++top] = item;

}

element pop() {
	if (is_empty())
		return -1;
	else
		return stack[top--];

}

element peek() {
	if (is_empty())
		return -1;
	else
		return stack[top];
}
int main() {
	int N;


	char s[100];
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		gets(s);
		char *p = strtok(s, " ");
		if (strcmp(p, "push") == 0) {
			p = strtok(NULL, " ");
			push(atoi(p));

		}
		else if (strcmp(s, "top") == 0) {
			printf("%d\n", peek());
		}

		else if (strcmp(s, "size") == 0) {
			printf("%d\n", size());
		}

		else if (strcmp(s, "empty") == 0) {
			printf("%d\n", is_empty());
		}
		else if (strcmp(s, "pop") == 0) {
			printf("%d\n", pop());
		}

	}

}