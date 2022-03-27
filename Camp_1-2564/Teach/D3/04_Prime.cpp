#include<stdio.h>
#include<math.h>

int not_prime[8000000], prime[600000];
void prime_gen() {
	int MXN = 7500000;
	int sq = sqrt(MXN);
	for(int i=2; i<=sq; i++) {
		if(not_prime[i]) continue;
		for(int j=i*i; j<=MXN; j+=i)
			not_prime[j] = 1;
	}
	int sz = 0;
	for(int i=2; i<=MXN; i++) {
		if(not_prime[i] == 0) prime[++sz] = i;
	}
}
int main() {
	prime_gen();
	int n;
	scanf("%d", &n);
	printf("%d\n", prime[n]);
	return 0;
}
