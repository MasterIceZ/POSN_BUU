#include<stdio.h>
int a[3000][3000];
int main (){
	int i,j,st,n,q;
	scanf("%d",&q);
	while(q--){
		i=j=0,st=1;
		scanf("%d",&n);
		if(n>1){
			while(1){
				if(st%4==1){
					a[i][j]=1;
					j++;
					if(j==4*n-4||a[i][j+2])
					{
						st++;
						if(a[i+2][j]==1){
							a[i][j] = 1;
							break;
						}
					}
				}
				else if(st%4==2){
					a[i][j]=1;
					i++;
					if(i==4*n-4||a[i+2][j])
						st++;
				}
				else if(st%4==3){
					a[i][j]=1;
					j--;
					if(j==0||a[i][j-2])
					st++;
				}
				else if(st%4==0){
					a[i][j]=1;
					i--;
					if(a[i-2][j])
					st++;
				}
				
				
			}
			for(i=0;i<=4*n-4;i++){
				for(j=0;j<=4*n-4;j++){
					if(a[i][j])printf("#");
					else printf(".");
				}
				printf("\n");
			}
		}	
	else if(n==1)
	printf("#");
	

	
	
	for(i=0;i<=4*n-4;i++){
		for(j=0;j<=4*n-4;j++){
			a[i][j]=0;
		}
	}
}
	return 0;
}
