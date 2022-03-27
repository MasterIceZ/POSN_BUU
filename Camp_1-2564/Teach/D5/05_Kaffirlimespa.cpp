#include<bits/stdc++.h>
using namespace std;

const int mxN = 810;

long long a[mxN], b[mxN];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%lld", &a[i]);
	for(int i=0; i<n; ++i)
		scanf("%lld", &b[i]);
	sort(a, a+n);
   	sort(b, b+n, greater<long long>());
	long long ans=0;
	for(int i=0; i<n; ++i)
		ans += a[i]*b[i];
	printf("%lld\n", ans);
	return 0;
}
