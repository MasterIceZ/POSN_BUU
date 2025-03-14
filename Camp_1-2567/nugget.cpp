#include <cstdio>

int a[] = {6, 9, 12, 15, 18, 20, 21, 24, 26, 27, 29, 30, 32, 33, 35, 36, 38, 39, 40, 41, 42};

signed main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for(int i=1, it = 0; i<=n; ++i) {
		if(i <= 43) {
			if(i != 43 && i == a[it]) {
				printf("%d\n", i);
				it++;
			}
		}
		else {
			printf("%d\n", i);
		}
	}
	if(n <= 5) {
		printf("no\n");
	}
	return 0;
}
