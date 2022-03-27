#include<stdio.h>

long long gcd(long long a, long long b) {
	if(a%b==0) return b;
	return gcd(b, a%b);
}
int main() {
	long long n, num, ans;
	scanf("%lld %lld", &n, &ans);
	for(int i=0; i<n-1; i++) {
		scanf("%lld", &num);
		ans = ans/gcd(ans, num)*num;
	}
	printf("%lld\n", ans);
	return 0;
}
