#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    //Up
    for(i=0; i<n-1; i++)
    {
    	for(j=0;j<n-1-i;j++)
    	printf("+");
    	
    	for(j=0;j<i*2+1;j++)
    	printf("0");
    	
		for(j=0;j<n-1-i;j++)
    	printf("+");
        
		printf("\n");
    }
    //Mid
    for(i=0;i<2*n-1;i++){
    	printf("0");
	}
	printf("\n");
	//Bottom
	for(i=0;i<n-1;i++){
		for(j=0;j<i+1;j++)
		printf("+");
		
		for(j=0;j<2*(n-1)-2*i-1;j++)
		printf("0");
		
		for(j=0;j<i+1;j++)
		printf("+");
		
		printf("\n");
	}
}
        /*for(j=0; j<2*n-1; j++)
        {
            if(j==n-1)
            {
                printf("0");
            }
            else if(i==n-j-1)
            {
                printf("0");
            }
            else if(i==n+j-1)
            {
                printf("0");
            }
            else if(j==n+i-1){
                printf("0");
            }
            else if(j==n-i+n+n-3){
            	printf("0");
            }
            else if(i==n-1)
            {
                printf("0");
            }
            else
            {
                printf("+");
            }

        }*/
        //peattaep
