//limbo3
#include<stdio.h>
char a[1000][1000];
int r,c,cnt=0,di[4]={-1,1,0,0},dj[4]={0,0,1,-1};

void play(int i,int j){
	if(a[i][j]=='.')
	return;
	a[i][j]='.';
	for(int k=0;k<4;k++){
		play((i+di[k]+r)%r,(j+dj[k]+c)%c);
	}
}

int main (){
	int i,j;
	scanf("%d %d",&c,&r);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf(" %c",&a[i][j]);
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(a[i][j]=='*'){
				cnt++;
				play(i,j);
			}
		}
	}
		
		printf("%d\n",cnt);
		return 0;
}
