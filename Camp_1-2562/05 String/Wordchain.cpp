#include<stdio.h>
#include<string.h>
char a[1010],b[1010],c[1010];
int main(){
	int i,n,j,cnt=0,ch=1,l;
	scanf("%d %d",&l,&n);
	for(i=0;i<l;i++){
		scanf(" %c",&a[i]);
	}
	if(n==1){
		for(j==0;j<l;j++){
			printf("%c",a[j]);
		}
	return 0;
	}
	for(i=0;i<n-1;i++){
		cnt=0;
		for(j=0;j<l;j++){
			scanf(" %c",&b[j]);
		}
		for(j=0;j<l;j++){
			if(a[j]!=b[j]){
				cnt++;
			}
		}
		if(cnt>2&&ch){
			for(j=0;j<l;j++){
				c[j]=a[j];
				ch=0;
			}
		}
		if(ch){
			for(j=0;j<l;j++)
				c[j]=b[j]; 
		}
		strcpy(a,b);
		
	}
	for(j=0;j<l;j++){
		printf("%c",c[j]);
	}
}
/*
4
12
HEAD
HEAP
LEAP
TEAR
REAR
BAER
BAET
BEEP
JEEP
JOIP
JEIP
AEIO
*/
