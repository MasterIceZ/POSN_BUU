#include<bits/stdc++.h>
using namespace std;
int a[2100];
int main (){
	int i,n,k,sum=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	for(i=0;i<n;i+=k){
		sum+=a[i];
	}
	printf("%d",sum);
	return 0;
}
