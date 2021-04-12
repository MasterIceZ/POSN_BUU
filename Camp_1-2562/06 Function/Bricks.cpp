#include<stdio.h>

char a[100][100];

int main()
{
	int r,c,i,j,f,k;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++)
		scanf(" %s",a[i]);
	for(j=0;j<c;j++){
		scanf("%d",&f);
		k=r-1;
		for(i=0;i<r;i++){
			if(a[i][j]=='O'){
				k=i-1;
				break;
			}
		}
		for(; k>=0&&f>0;k--,f--)
			a[k][j]='#';
	}
	for(i=0;i<r;i++){
		printf("%s\n",a[i]);
	}
	return 0;
}
