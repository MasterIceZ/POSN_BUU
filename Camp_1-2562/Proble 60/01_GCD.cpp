#include<stdio.h>
int gcd(int a,int b){
	if(a%b==0){
		return b;
	}
	return gcd(b,a%b);
}
int main (){
	int b,a,ans,num,n;
	scanf("%d %d",&n,&ans);
	for(int i=0;i<n-1;i++){
		scanf("%d",&num);
		ans = gcd(ans,num);
	}

	printf("%d",ans);
	return 0;
}
