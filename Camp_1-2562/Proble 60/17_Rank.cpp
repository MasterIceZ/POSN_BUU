#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main (){
	int n,m,num,idx,i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	while(m--){
		scanf("%d",&num);
		idx = upper_bound(a,a+n,num)-a;
		printf("%d",n-idx+1);
	}
	return 0;
}
