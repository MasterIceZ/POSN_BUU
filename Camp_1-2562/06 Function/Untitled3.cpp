#include<stdio.h>

int main (){
	int i,j,n;
	scanf("d",&n);
	for(i=0;i<2*n-1;i++)
	{
		for(j=0;j<2*n-1;j++)
		{
			if(j==n) printf("0");
			else printf("+");
		}
	}
	return 0;
}
