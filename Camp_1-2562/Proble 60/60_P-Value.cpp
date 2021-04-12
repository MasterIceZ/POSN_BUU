#include<bits/stdc++.h>
using namespace std;
int ans[100100];
int main (){
	int n,i,j,cnt=0;
	scanf("%d",&n);
	if(n<0)	{printf("-1\n"); return 0;
	}
	if(n==0){printf("10\n"); return 0;
	}	
	if(n<10)	{printf("%d\n",n); return 0;
	}
	for(j=9;j>1&&n>1;j--){
		while(n%j==0)
			ans[cnt]=j,n/=j,cnt++;
	}
	if(n!=1){
		printf("-1\n"); return 0;
	}
	for(i=cnt-1;i>=0;i--)
		printf("%d",ans[i]);
	return 0;
}
