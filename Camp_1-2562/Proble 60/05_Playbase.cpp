#include<stdio.h>
#include<string.h>
#include<ctype.h>

char a[50],b[50],c[50];
int main (){
	int x,numa=0,numb=0,now,i,num,len;
	scanf("%d %s %s",&x,a,b);
	len = strlen(a);
	for(i=0;i<len;i++){
		numa *= x;
		if(isdigit(a[i]))	numa += a[i]-'0';
		else				numa += a[i]-'A'+10;
	}
	len = strlen(b);
	for(i=0;i<len;i++){
		numb *= x;
		if(isdigit(b[i]))	numb += b[i]-'0';
		else 				numb += b[i]-'A'+10;
	}
	num = numa+numb;
	printf("%d\n",num);
	i=0;
	while(num!=0){
		now = num%x;
		if(now<10)	c[i] = now+'0';
		else		c[i] = now-10+'A';
		num /= x,i++;
	}
	for(i--;i>=0;i--)
		printf("%c",c[i]);
	printf("\n");
	return 0;
	
}
