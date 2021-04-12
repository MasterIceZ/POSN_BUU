#include<bits/stdc++.h>
using namespace std;
int a[100][100],room[100][100],sum,cou,w,h;
void play(int i,int j){
	room[i][j] = 1;
	if(i-1>=0 && !room[i-1][j] &&a[i][j]&2){
		sum++;
		play(i-1,j);
	}
	if(j-1>=0&&!room[i][j-1]&&a[i][j]&1){
		sum++;
		play(i,j-1);
	}
	if(i+1<h&&!room[i+1][j]&&a[i][j]&8){
		sum++;
		play(i+1,j);
	}
	if(j+1<w&&!room[i][j+1]&&a[i][j]&4){
		sum++;
		play(i,j+1);
	}
}
int main (){
	int i,j,mx=-1;
	scanf("%d %d",&w,&h);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%d",&a[i][j]);
		a[i][j] = 15-a[i][j];
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(!room[i][j]){
				room[i][j] = 1;
				sum = 1;
				play(i,j);
				cou++;
				if(sum>mx) mx = sum;
			}
		}
	}
	printf("%d \n%d",cou,mx);
	return 0;
}
