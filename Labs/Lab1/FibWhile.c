#include <stdio.h>

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

int main() {
	int fib_6 = fibWhile(6);
	printf("%d", fib_6);	
}
