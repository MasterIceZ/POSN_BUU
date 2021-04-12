#include<stdio.h>
#include<string.h>
int a[10][10],di[4]={1,-1,0,0},dj[4]={0,0,-1,1},ans[10],mark[1000000],cnt=0,sum;

void play (int nowi,int nowj,int m){
	ans[m] = a[nowi][nowj];
	if(m==5){
		sum=ans[0]*100000+ans[1]*10000+ans[2]*1000+ans[3]*100+ans[4]*10+ans[5];
		if(!mark[sum]){
			cnt++;
			mark[sum]=1;
		}
		return;
	}
	for(int k =0;k<4;k++){
		int nexti = nowi+di[k],nextj=nowj+dj[k];
		if(nexti<0||nexti>4||nextj<0||nextj>4) continue;
		play(nexti,nextj,m+1);
	}
}

int main (){
	int q,i,j;
	scanf("%d",&q);
	while(q--){
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				play(i,j,0);
	printf("%d",cnt);
	cnt=0;
	memset(mark,0,sizeof mark); 
	}
	return 0;
}
/*
	1
	1 1 1 1 1
	1 1 1 1 1
	1 1 1 1 1
	1 1 1 2 1
	1 1 1 1 1
*/
