#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e6+100;

long long a[mxN];
int main() {
	long long n,c;
	scanf("%lld %lld", &n, &c);
	for(int i=0; i<n; ++i)
		scanf("%lld", &a[i]);
	long long lb=0, rb=2e9+1;
	while(lb<rb) {
		long long mb = (lb+rb+1)/2, sum=0ll;
		for(int i=0; i<n; ++i) {
			if(a[i]>mb) sum+=a[i]-mb;
		}
		if(sum>=c) lb=mb;
		else rb=mb-1;
	}
	printf("%lld\n", lb);
	return 0;
}

