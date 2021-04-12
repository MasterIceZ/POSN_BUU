#include<stdio.h>
int answer[23],mark[23][23][23];
int A,B,C,i;
void play(int a,int b,int c){
	if(a<0||b<0||c<0||a>A||b>B||c>C) return;
	if(a==0) answer[c]=1;
		if(mark[a][b][c]==1)
		return;
	mark[a][b][c]=1;
	//A->B
	play(0,b+a,c);
	play(a-B+b,B,c);
	//A->C
	play(0,b,a+c);
	play(a-C+c,b,C);
	//B->A
	play(a+b,0,c);
	play(A,b-A+a,c);
	//B->C
	play(a,0,b+c);
	play(a,b-C+c,C);
	//C->A
	play(a+c,b,0);
	play(A,b,c-A+a);
	//C->B
	play(a,b+c,0);
	play(a,B,c-B+b);

}
int main(){
	
	scanf("%d %d %d",&A,&B,&C);
	play(0,0,C);
	for(i=0;i<=C;i++)
		if(answer[i]==1)
			printf("%d ",i);
	return 0;
}
