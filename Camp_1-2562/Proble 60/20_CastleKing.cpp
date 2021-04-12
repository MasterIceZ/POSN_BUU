#include<bits/stdc++.h>
using namespace std;
long long a[500100];
int main (){
	long long n,i,sum=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		sum+=(a[i]*2)+(a[i]-a[i-1]);
	}
	sum+=n+a[n];
	printf("%lld",sum);
	return 0;
}
