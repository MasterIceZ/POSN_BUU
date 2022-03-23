#include<stdio.h>
#include<string.h>
int m,x,y;
int a[200][200],mx;
const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};
void play(int i,int j){
    if(i<0 || i>=m || j<0 || j>=m) return;
    if(a[i][j]==100) return;
    if(mx<a[i][j]) mx=a[i][j];
    int k;
    for(k=0;k<4;k++){
        if(a[i+di[k]][j+dj[k]] <= a[i][j]) continue;
        play(di[k]+i, dj[k]+j);
    }
}
int main(){
    int i,j,x,y;
	scanf("%d %d %d ",&m,&y,&x);
	for(i=0;i<m;i++){
    	for(j=0;j<m;j++){
    		scanf("%d",&a[i][j]);
		}
	}
    play(x-1, y-1);
    printf("\n%d",mx);
	return 0;
}

