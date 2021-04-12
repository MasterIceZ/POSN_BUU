#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=0; i<2*n-1; i++)
    {
        for(j=0; j<2*n-1; j++)
        {
            //if(j==n-1)
            //{
            //    printf("0");
            //}
             if(i==n-j-1)
            {
                printf("0");
            }
             if(i==n+j-1)
            {
              printf("0");
           }
             if(j==n+i-1){
                printf("0");
            }
            else if(j==n-i+n+n-3){
            	printf("0");
            }
            //else if(i==n-1)
            //{
            //    printf("0");
            //}
            else
            {
                printf("+");
            }
			
        }
printf("\n");
}
}

