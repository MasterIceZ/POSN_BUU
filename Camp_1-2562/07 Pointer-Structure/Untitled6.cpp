#include<stdio.h>

int main (){
	FILE *fp;
	fp = fopen("D:\\file\\num.txt","r");
	char c;
	int count = 0;
	while(!feof(fp))
	{
		c = fgetc(fp);
		if(c=='6')
		count++;
	}
	printf("%d",count);
}
