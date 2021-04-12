#include<stdio.h>

int main ()
{
	int d,m,y,q;
	scanf("%d",&q);
	while(q--){
		scanf("%2d/%2d/%d",&d,&m,&y);
		printf("%2d/%2d/%d",d,m,y);
	}
	
}
