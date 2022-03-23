#include<stdio.h>
int a[1010][1010];
int x,y,max=-10,cnt,m,c,d;
void play(int i,int j){
	if(i<1 || j<1 || i>m || j>m){ //out of range check && 4 directions
//	    max = a[i][j];
	    return;
	}
	if(a[i][j] == 100){
	    return;
	}
	if(max < a[i][j]){
	    max = a[i][j];
	}
//	if(i==1 && j==1){
//	    max = a[i][j];
//	}
	if(a[i][j] < a[i-1][j]){
	    if(a[i-1][j] != 100){
//	        max = a[i-1][j];
	        play(i-1,j);
	    }
	}
	if(a[i][j] < a[i][j-1]){
	    if(a[i][j-1] != 100){
	        play(i,j-1);
	    }
	}
	if(a[i][j] < a[i+1][j]){
	    if(a[i+1][j] != 100){
	        play(i+1,j);
	    }
	}
	if(a[i][j] < a[i][j+1]){
	    if(a[i][j+1] != 100){
	        play(i,j+1);
	    }
	}
}
int main(){
	int i,j;
	scanf("%d",&m);
	scanf("%d",&x);
	scanf("%d",&y);
	for(i=1;i<=m;i++){
	    for(j=1;j<=m;j++){
	        scanf("%d",&a[i][j]);
	    }
	}
	play(y,x);
	printf("%d\n",max);
	return 0;
}
