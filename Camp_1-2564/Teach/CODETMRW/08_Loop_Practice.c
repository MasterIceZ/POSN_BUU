#include<stdio.h>

int main() {
	int n,i;
	scanf("%d", &n);
	// 1 -> n
	for(i=1; i<=n; i++)
		printf("%d ", i);
	printf("\n");

	// n->1
	i=n;
	while(i>=1) {
		printf("%d ", i);
		i--;
	}
	printf("\n");

	// 1->n even
	i=1;
	do {
		if(i%2==0) printf("%d ", i);
		i++;
	} while(i<=n);
	printf("\n");

	// n->1 even
	for(i=n; i>=1; i--) {
		if(i%2==0)
			printf("%d ", i);
	}
	printf("\n");

	// 1->n odd
	i = 1;
	while(i<=n) {
		if(i%2==1)
			printf("%d ", i);
		i++;
	}
	printf("\n");

	// n->1 odd
	i = n;
	do {
		if(i%2==1)
			printf("%d ", i);
		i--;
	} while(i>=1);
	printf("\n");
	return 0;
}

