#include<stdio.h>
#include<string.h>
char a[5000][2000];
int main (){
	int r=1,c=1,n,nr,nc,j,i;
	scanf("%d",&n);
	memset(a,'-',sizeof a);
	a[0][0]='*';
	while(--n){
		nr=r*2+1,nc=c*2;
		for(j=0;j<nc;j++)
			a[r][j]='*';
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				a[r+1+i][c+j]=a[i][j];
		r=nr,c=nc;
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
	return 0;
}
