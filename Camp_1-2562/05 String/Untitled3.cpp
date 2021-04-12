#include<stdio.h>
#include<string.h>
int main (){
	char f[100];
	gets(f);
	int a = strlen(f),i,b=0;
	for(i=0;i<a;i++){
		if(f[i]<='9'&&f[i]>='0'){
			b++;
		}
	}
	float per;
	per = b*100/a;
	printf("%.2f",per);
	return 0;
}
