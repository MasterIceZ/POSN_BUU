#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100];
int main (){
	
	int i,len,num,sum=0,q=5,z;
	while(q--){
	sum = 0;
	scanf(" %s",a);
	sscanf(a,"%d",&num);
	len = strlen(a);
	for(i=1;i<=len;i++){
		sum+=pow(a[i-1]-'0',i);
	}	
	if(sum==num) printf("Y");
	else printf("N");
	
	}
	
	return 0;
}
