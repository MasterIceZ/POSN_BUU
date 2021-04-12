#include<stdio.h>
/*
		TASK: Yin-Yang
		AUTHOR: Ice
		SCHOOL: RYW
		LANG: C
*/
int main (){
	int i,j,k,n,a;
	scanf("%d",&a);
	while(a--){
	scanf("%d",&n);
	for(i = 1;i <= n+2;i++)//row
    {   
        for(j=n+1;j>=i;j--){//column
			printf(".");
		}
		for(j=1;j<=i;j++){
			printf("#");
		}
		for(j=1;j<=n+2;j++){
			if(i==1||i==n+2||j==1||j==n+2)
			printf("+");
			if(i==5)
			printf("+");
			else
			printf("#");
			
		}
		
		printf("\n");
    }
	for(i = 1;i <= n+2;i++)//row
    {   
        for(j=1;j<=n+2;j++){
			if(i==1||i==n+2||j==1||j==n+2)
			printf("#");
			else
			printf("+");
		}
		for(j=n+2;j>=i;j--){//column
			printf("+");
		}
		for(j=2;j<=i;j++){
			printf(".");
		}
		
		
		printf("\n");
    }
}
						
	
	return 0;
}
