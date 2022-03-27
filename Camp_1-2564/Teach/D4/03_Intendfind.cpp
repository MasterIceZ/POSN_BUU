#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+1;
int a[mxN];
int main() {
	int n,t;
	scanf("%d %d", &n, &t);
	for(int i=0; i<n; ++i)
		scanf("%d", &a[i]);
	sort(a, a+n);
	while(t--) {
		int x;
		scanf("%d", &x);
		int idx=upper_bound(a, a+n, x)-a;
		printf("%d\n", idx);
	}
	return 0;
}
