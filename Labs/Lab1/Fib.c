#include <stdio.h>

int fibRec(int x, int x1, int x2) {
	if (x <= 1) {
		return x2;
	} else {
		return fibRec(x-1, x2, x1 + x2);
	}	
}

int fibWhile(int x) {
	int x1 = 0;
	int x2 = 1;

	while (x > 1) {
		int xtemp = x1 + x2;
		x1 = x2;
		x2 = xtemp;
		x = x -1;
	}
	return x2;
}

int fibFor(int x) {
	int x1 = 0;
	int x2 = 1;

	for (int i = 0; i < x -1; i++) {
		int xtemp = x1 + x2;
		x1 = x2;
		x2 = xtemp;
	}
	return x2;
}

int main() {
	int fib_r = fibRec(6, 0, 1);
	printf("Recursive:");
	printf("%d", fib_r);
	int fib_w = fibWhile(6);
	printf("While:");
	printf("%d", fib_w);
	int fib_f = fibFor(6);
	printf("For:");
	printf("%d", fib_f);
}
