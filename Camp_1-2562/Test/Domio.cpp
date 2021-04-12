#include<stdio.h>
int n;
char a[20];
void play(int state,int len){
	if(state>n) return;
	if(state == n){
		for(int i=0;i<len;i++){
			printf("%c%c\n",a[i],a[i]);
		}
		printf("E\n");
	}
	a[len]='-';
	play(state+1,len+1);
	a[len]='|';
	play(state+2,len+1);
}

int main (){
	scanf("%d",&n);
	play(0,0);
	return 0;
}
