#include<bits/stdc++.h>
using namespace std;
long long a[808],b[808];
int main () {
	long long n,i,sum=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)	scanf("%lld",&a[i]);
	for(i=0;i<n;i++)	scanf("%lld",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++){
		sum+=a[i]*b[i];
	}
	printf("%lld",sum);
	return 0;
}
/*
3
1 3 -5
-2 4 1


*/

