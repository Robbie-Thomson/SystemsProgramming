#include <stdio.h>

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
	int fib_6 = fibFor(6);
	printf("%d", fib_6);	
}
