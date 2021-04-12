#include<bits/stdc++.h>
using namespace std;

int main () {
	int n,i,st=1,ansst=1,ansen,Max = -1e9,num,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		sum+=num;
		if(sum> Max)
			Max = sum,ansst = st,ansen=i;
		if(sum<0)
			sum = 0,st = i+1;
	}
	printf("%d %d\n%d\n",ansst,ansen,Max);
	return 0;
}
