#include<stdio.h>

int a[5][5];
int mark[5][5];
int main(){
	int q,i,j;
	scanf("%d",&q);
	while(q--){
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				scanf("%d ",&a[i][j]);
			}
		}
	}
}
