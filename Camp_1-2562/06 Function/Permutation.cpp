#include<stdio.h>
#include<stdlib.h>
int n,r,k,a[14],mark[14],cnt;

void play(int st){
	int i;
	if(st==r){
		cnt++;
		if(cnt==k){
			for(i=0;i<st;i++){
				printf("%d ",a[i]);
			}
			exit(0);
		}
		return;
	}
	for(i=1;i<=n;i++){
		if(!mark[i]){
			mark[i]=1;
			a[st]=i;
			play(st+1);
			mark[i]=0;
		}
	}
}

int main (){
	
	scanf("%d %d %d",&n,&r,&k);
	play(0);
	return 0;
}
