#include <stdio.h>

int fib(int x, int x1, int x2) {
	if (x <= 1) {
		return x2;
	} else {
		return fib(x-1, x2, x1 + x2);
	}	
}

int main() {
	int fib_6 = fib(6, 0, 1);
	printf("%d", fib_6);
}
