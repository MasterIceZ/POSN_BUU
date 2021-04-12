#include<stdio.h>

int main (){
	int k,q,i,a=0,d;
	scanf("%d",&q);
	int n[1004];
	for(i=0;i<q;i++){
		scanf("%d",&n[i]);
	}
	for(i=q-1;i>=0;i--){
		printf("%d ",n[i]);
	}
	scanf("%d",&d);
	for(i=0;i<q;i++){
		if(d==n[i]){
			a++;
		}
	}
	printf("%d",a);
	return 0;
}
