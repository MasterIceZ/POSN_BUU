#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6+10;
long long a[mxN];

int main() {
	long long n,m;
	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%lld", &a[i]);
	long long lb=0, rb=1e18;
	while(lb<rb) {
		long long mb=(lb+rb)/2, sum=0;
		for(int i=0; i<n; ++i)
			sum+=mb/a[i];
		if(sum>=m) rb=mb;
		else lb=mb+1;
	}
	printf("%lld\n", lb);
	return 0;
}

