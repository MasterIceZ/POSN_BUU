#include<stdio.h>
int s,cnt=0,n;
int a[25],ch;
void play(int sum,int len){
	if(ch)return;
	if(sum>s) return;
	if(sum==s){
		cnt++;
		if(cnt==n){
			for(int i=0;i<len;i++){
				printf("%d",a[i]);
			}
			ch=1;
		}
		return;
	}
	for(int i=1;i<=9;i++){
		sum+=i;
		a[len]=i;
		play(sum,len+1);
		sum-=i;
	}
}

int main (){
	int q;
	scanf("%d",&q);
	while(q--){
		cnt=0;
		ch=0;
		scanf("%d %d",&s,&n);
		play (0,0);
	}
	return 0;
}
