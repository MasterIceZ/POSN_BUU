#include<bits/stdc++.h>
using namespace std;

int a[100100];

int main (){
	int n,q,i,idx,num;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	while(q--){
		scanf("%d",&num);
		idx =upper_bound(a,a+n,num)-a;
		printf("%d",idx);
	}
	return 0;
}
