#include <stdio.h>
#include <string.h>

// f(n) = n!
int f(int n) {
	if(n == 0 || n == 1) {
		return 1;
	}
	if(n < 0){
		return 0;
	}
	// return n!
	return n * f(n - 1);
}

int main() {
	printf("4! = %d\n", f(4));
}


