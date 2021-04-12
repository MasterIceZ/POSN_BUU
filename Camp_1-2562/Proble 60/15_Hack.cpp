#include<bits/stdc++.h>
using namespace std;
string a[100100];
char c[100];
int main (){
	int n,m,k,i;
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<n;i++){
		scanf(" %s ",c);
		a[i]=c;
	}
	sort(a,a+n);
	while(m--){
		scanf(" %s ",c);
		i  = lower_bound(a,a+n,c)-a;
		if(a[i]==c) printf("Accepted");
		else		printf("Rejected");
	}
	return 0;
}
