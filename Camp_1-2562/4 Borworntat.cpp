#include<stdio.h>

int findMax (int , int );
int main () {
    int a,b;
    
    printf("Enter num1 : ");
    scanf("%d",&a);
    printf("Enter num2 : ");
    scanf("%d",&b);
    int max = findMax(a , b);
    
    printf("Max = %d",max);
    scanf(" ");
            }

int findMax(int x , int y ){
    if(x>y){
           return x;
           }
    else {
         return y;
         }
                            }
