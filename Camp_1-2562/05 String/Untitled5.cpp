#include<stdio.h>
#include<string.h>
int main (){
	int u=0,l=0,n=0;
	char a[30];
	int i;
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(a[i]>='A'&&a[i]<='Z')
			u+=1;
		else if(a[i]>='a'&&a[i]<='z')
			l+=1;
		else if(a[i]>='0'&&a[i]<='9')
			n+=1;
	}
	float U = u*100/strlen(a);
	float L = l*100/strlen(a);
	float N = n*100/strlen(a);
	printf("%d %.2f\n",u,U);
	printf("%d %.2f\n",l,L);
	printf("%d %.2f\n",n,N);
	return 0;
}
