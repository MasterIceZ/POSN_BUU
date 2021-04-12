#include<stdio.h>
#include<string.h>
char a[6000],b[6000];
int c[6000],lena,lenb;

int compare(){
	int i;
	if(lena>lenb) return 2;
	if(lenb>lena) return 3;
	for(i=0;i<lena;i++){
		if(a[i]>b[i]) return 2;
		if(b[i]>a[i]) return 3;
	}
	return 1;
}

void pluss (){
	int i,j,k=0,tod=0;
	if(!strcmp(a,"0")){
		printf("%s\n",b);
		return;
	}
	if(!strcmp(b,"0")){
		printf("%s\n",a);
		return;
	}
	for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--,k++){
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
	for(;k>=0;k--)	printf("%d",c[k]);
	printf("\n");
	return;
}
void minuss(char* d,char* e){
	int i,j,k=0,l;
	lena = strlen(d);
	lenb = strlen(e);
	if(!strcmp(e,"0")){
		printf("%s\n",d);
		return;
	}
	if(!strcmp(d,"0")){
		printf("-%s\n",e);
		return;
	}
	for(i=lena-1,j=lenb-1;i>=0&&j>=0;i--,j--,k++){
		if(d[i]<e[j]){
			for(l=i-1;l>=0&&d[l]=='0';l--);
			d[l]--;
			for(l++;l<i;d[l]='9',l++);
			d[i]+=10;
		}
		c[k]+=((d[i]-'0')-(e[j]-'0'))%10;
	}
	for(;i>=0;i--,k++)
		c[k] += (d[i]-'0')%10;
	for(k--;k>=0&&c[k]==0;k--);
	for(;k>=0;k--)
		printf("%d",c[k]);
		printf("\n");
	return ;
}

int main (){
	int aminus=0,bminus=0;
	scanf(" %s %s",a,b);
	if(a[0]=='-')
		strcpy(a,&a[1]),aminus = 1;
	if(b[0]=='-')
		strcpy(b,&b[1]),bminus = 1;
	lena = strlen(a);
	lenb = strlen(b);
	if(compare()==2){//a>b
		if(aminus==0&&bminus==0)	pluss();
		if(aminus==1&&bminus==1)	printf("-"),pluss();
		if(aminus==0&&bminus==1)	minuss(a,b);
		if(aminus==1&&bminus==0)	printf("-"),minuss(a,b);
	}
	if(compare()==3){//b>a
		if(aminus==0&&bminus==0)	pluss();
		if(aminus==1&&bminus==1)	printf("-"),pluss();
		if(aminus==0&&bminus==1)	printf("-"),minuss(b,a);
		if(aminus==1&&bminus==0)	minuss(b,a);
	}
	if(compare()==1){//a==b
		if(aminus!=bminus)			printf("0\n");
		if(aminus==0&&bminus==0)	pluss();
		if(aminus==1&&bminus==1)	printf("-"),pluss();
	}
	return 0;
}
