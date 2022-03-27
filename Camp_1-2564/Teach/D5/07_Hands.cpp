#include<bits/stdc++.h>
using namespace std;

const int mxN = 2050;
int a[mxN];

int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n, greater<int>());
	int sum=0;
	for(int i=0; i<n; i+=k)
		sum+=a[i];
	printf("%d\n", sum);
	return 0;
}
