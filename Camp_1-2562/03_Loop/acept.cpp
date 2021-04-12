#include<stdio.h>
int main (){
	int a,acc=0,i=0;
	while(i<10){
		 scanf("%d",&a);
		 if(a%5!=0){
		 	printf("Accept\n");
		 	acc++;
		 }
		 i++;
	}
	printf("============================\n");
	printf("%d\n",acc);
	
	return 0;
}
