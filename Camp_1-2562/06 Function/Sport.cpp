#include<stdio.h>
char a[30000011];
int k;

void play(int state,int w,int l){
	int i;
	if(w==k||l==k){
		for(i=0;i<state;i++){
			printf("%c ",a[i]);
		}
		printf("\n");
		return;
	}
	a[state]='W';
	play(state+1,w+1,l);
	a[state]='L';
	play(state+1,w,l+1);
}

int main (){
	int w,l;
	scanf("%d %d %d",&k,&w,&l);
	play(0,w,l);
	return 0;
}
