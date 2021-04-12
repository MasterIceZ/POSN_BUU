#include<stdio.h>
//wheel
int ch[110],w[110],s[25];
int main (){
	int n,k,i,j,roll,b,now=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&roll);
		for(j=0;j<roll;j++){
			while(ch[now%n]) now++;
			now+=1;
		}
		while(ch[now%n])now++;
		ch[now%n]=1;
		s[i%k]+=w[now%n];
	}
	for(i=0;i<k;i++)
		printf("%d ",s[i]);
	return 0;
}
