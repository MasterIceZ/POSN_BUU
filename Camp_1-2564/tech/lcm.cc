#include <stdio.h>

using ll = long long;

ll gcd(int a, int b){
	if(a % b == 0){
		return b;
	}
	return gcd(b, a % b);
}

int main(){
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", a * b / gcd(a, b));
	return 0;
}
