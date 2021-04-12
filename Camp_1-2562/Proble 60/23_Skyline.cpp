#include<bits/stdc++.h>
using namespace std;
int a[300];
int main (){
	int i,n,l,r,h,old = 0;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d",&l,&h,&r);
		for(i=l;i<r;i++){
			if(a[i]<h)
				a[i]=h;
		}
	}
	for(i=1;i<=300;i++){
		if(a[i]!=old){
			printf("%d %d ",i,a[i]);
			old = a[i];
		}
	}
	return 0;	
}
