#include<stdio.h>
int a[20][20],b[20][20],c[20][20];
int main (){
	int n1,m1,n2,m2;
	scanf("%d %d %d %d",&n1,&m1,&n2,&m2);
	int i,j,k;
	if(m1!=n2){
		printf("Can't Multiply.");
		return 0;
	}
	
	for(i=0;i<n1;i++){
		for(j=0;j<m1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n2;i++){
		for(j=0;j<m2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<m2;j++){
			for(k=0;k<m1;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<n1;i++){
		for(j=0;j<m2;j++){
			printf("%d ",c[i][j]);
			
		}
	printf("\n");
	}
	return 0;
}
