#include<bits/stdc++.h>
using namespace std;
double a[5][5],mi=1e9;
int n,m,di[8]={1,-1,0,0,1,1,-1,-1},dj[8]={0,0,1,-1,1,-1,1,-1},mark[5][5];

void play(int i,int j,double sum,int st){
	sum+= a[i][j];
	if(st==n*m){
		if(sum<mi){
			mi = sum;
		}
		return;
	}
	int k,ii,jj;
	mark[i][j]=1;
	for(k=0;k<8;k++){
		ii = i+di[k];
		jj = j+dj[k];
		if(i+di[k]<0||i+di[k]>=n||j+dj[k]<0||j+dj[k]>=m) continue;
		a[ii][jj]+=a[i][j]*0.1;
	}
	for(ii=0;ii<n;ii++){
		for(jj=0;jj<m;jj++){
			if(mark[ii][jj]!=1){
				play(ii,jj,sum,st+1);
			}
		}
	}
	mark[i][j]=0;
	sum-=a[i][j];
	for(k=0;k<8;k++){
		ii = i+di[k];
		jj = j+dj[k];
		if(i+di[k]<0||i+di[k]>=n||j+dj[k]<0||j+dj[k]>=m) continue;
		a[ii][jj]-=a[i][j]*0.1;
	}
	
}

int main(){
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			play(i,j,0,1);
		}
	}
	printf("%.2lf",mi);
	return 0;
	
}
