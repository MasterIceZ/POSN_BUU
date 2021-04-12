#include<bits/stdc++.h>
using namespace std;
char b[10],d[10];
struct A{
	char word[10];
	bool operator < (const A&o)const{
		if(strcmp(word,o.word)<0)	return true;
		else 						return false;
	}
};
A arr[41000],ans[41000];
int mark[10],n,m,coun;
void play(int state){
	
	
	if(state==n){
		d[state]='\0';
		strcpy(arr[coun].word,d);
		coun++;
		return;
	}
	int i;
	for(i=0;i<n;i++){
		if(mark[i]!=1){
			mark[i]=1;
			d[state]=b[i];
			play(state+1);
			mark[i] = 0;
		}
		
	}
}

int main () {
	char c;
	int i,j,cou=0;
	scanf("%d %d",&n,&m);
	while(m--){
		scanf(" %c %d",&c,&i);
		while(i--){
			b[cou++]=c;
		}
	}
	play(0);
	sort(arr,arr+coun);
	cou = 0;
	for(i=0;i<coun;){
		strcpy(ans[cou++].word,arr[i].word);
		for(j=i+1;j<coun;j++){
			if(strcmp(arr[i].word,arr[j].word)!=0)
			break;
			
		}
		i=j;
	}
	printf("%d",cou);
	for(i=0;i<cou;i++){
		printf("%s\n",ans[i].word);
	}
}
/*
4 3
S 1
O 2
L 1
*/
