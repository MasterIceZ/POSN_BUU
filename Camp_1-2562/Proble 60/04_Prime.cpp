#include<stdio.h>
#include<math.h>
int a[7500000];
int main(){
	int n,i,j,k,cnt=1;
	scanf("%d",&n);
	if(n==1){
		printf("2\n"); return 0;
	}
	for(i=3;i<7500000;i+=2){
		a[i]=1;
	}
	k = sqrt(7500000);
	for(i=3;i<=k;i+=2){
		if(a[i])
			for(j=i*i;j<7500000;j+=i)
				a[j]=0;
	}
	for(i=3;i<7500000;i+=2){
		if(a[i]){
			cnt++;
			if(cnt==n){
				printf("%d\n",i);
				return 0;
			}
		}
	}
	return 0;
}
