#include<stdio.h>
#include<string.h>
char a[100][1100];
int r,c,cnt,ma=10000,di[4]={-1,1,0,0},dj[4]={0,0,-1,1},gi[4]={-1,-1,1,1},gj[4]={1,-1,-1,1};
void play(int i,int j){
	if(i<0||i>=r||j<0||j>=c){
		return;
	}
	if(a[i][j]=='.'){
		return;
	}
	cnt++;
	a[i][j]='.';
	int k ;
	for(k=0;k<4;k++){
		
	}
	for(k=0;k<4;k++){
		play(i+di[k],j+dj[k]);
	}
}
int main(){
	int i,j;
	scanf("%d %d",&c,&r);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			scanf(" %c",&a[i][j]);
		}
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]=='*'){
			cnt = 0;
			play(i,j);
			if(cnt<ma)
			ma=cnt;
			}
		}
	}
	printf("%d",ma);
	return 0;
}
/*
10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***
*/
