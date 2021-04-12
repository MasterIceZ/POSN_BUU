#include<stdio.h>
char a[1010][100];
int mi=999999,cnt,c,r,di[8]={-1,-1,-1,0,1,1,1,0},dj[8]={-1,0,1,1,1,0,-1,-1};

void play(int i,int j){
	if(i<0||i>=r||j<0||j>=c) return;
	if(a[i][j]=='.') return;
	cnt++;
	a[i][j] = '.';
	int k;
	for(k=0;k<8;k++)
		play(i+di[k],j+dj[k]);
}

int main(){
	int i,j;
	scanf("%d %d",&c,&r);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf(" %c",&a[i][j]);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]=='*'){
				cnt=0;
				play(i,j);
				if(cnt<mi)
				mi=cnt;
			}
		}
	}
	printf("%d",mi);
	return 0;
}
