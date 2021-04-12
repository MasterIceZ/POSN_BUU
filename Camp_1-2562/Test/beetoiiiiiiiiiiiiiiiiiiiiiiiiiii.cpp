#include<bits/stdc++.h>
using namespace std;
int a[25][3];
int main(){
	int n;
	a[0][0]=1;
	a[0][1]=2;
	for(int i=1;i<=24;i++){
		a[i][0]=a[i-1][1];
		a[i][1]=a[i][0]+a[i-1][0]+1;
	}
	while(1){
		scanf("%d",&n);
		if(n==-1) return 0;
		printf("%d %d",a[n][0],a[n][1]);
	}
	return 0;
}
