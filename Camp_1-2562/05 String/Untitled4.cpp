#include<stdio.h>
#include<string.h>
int main (){
	char a[20],b[20];
	int n,i;
	gets(a);
	scanf("%d",n);
	n -=1;
	for(i=0;i<n+1;i++){
		if(i=n){
		a[n] = "*";	
		}
	}
	printf("%s",a);
}
