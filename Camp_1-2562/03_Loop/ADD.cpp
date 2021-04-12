#include<stdio.h>
int main (){
	int a,add=0,sum=0;
	for(int i=0;i>=0;i++){
		scanf("%d",&a);
		if(a<1){
			break;
		}
		else{
			add++;
			sum=sum+a;
			continue;	
		}
	}
	printf("======================\n");
	printf("%d\n",add);
	printf("%d\n",sum);
	return 0;
}
