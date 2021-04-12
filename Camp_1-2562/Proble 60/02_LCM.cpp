#include<stdio.h>
long long gcd(int a,int b){
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
int main (){
	long long b,a,ans,num,n;
	scanf("%lld %lld",&n,&ans);
	for(int i=0;i<n-1;i++){
		scanf("%lld",&num);
		ans = ans * num / gcd(ans,num);
	}

	printf("%lld",ans);
	return 0;
}
