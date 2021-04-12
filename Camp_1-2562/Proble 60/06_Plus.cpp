#include<stdio.h>
#include<string.h>
char a[6000],b[6000];
int c[6000];
int main (){
	int i,j,lena,lenb,tod=0,k;
	scanf(" %s %s",a,b);
	if(a[0]=='0'&&b[0]=='0'){
		printf("0\n"); return 0;
	}
	if(a[0]=='-'&&b[0]=='-'){
		strcpy(a,&a[1]),strcpy(b,&b[1]);
		printf("-");
	}
	lena = strlen(a),lenb = strlen(b);
	for(i = lena-1,j = lenb-1,k=0;i>=0&&j>=0;i--,j--,k++){
		c[k] = a[i]-'0' + b[j]-'0'+tod;
		tod = c[k]/10;
		c[k] %= 10;
	}
	for(;i>=0;i--,k++){
		c[k] = a[i]-'0'+tod;
		tod = c[k]/10;
		c[k] %= 10;
	}
	for(;j>=0;j--,k++){
		c[k] = b[j]-'0'+tod;
		tod = c[k]/10;
		c[k] %= 10;
	}
	c[k] = tod,k++;
	for(;k>=0&&c[k]==0;k--);
	for(;k>=0;k--)
		printf("%d",c[k]);
	printf("\n");
	return 0;
}
