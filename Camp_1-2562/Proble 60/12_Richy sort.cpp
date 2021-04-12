#include<bits/stdc++.h>
using namespace std;

struct A{
	int x,y;
	bool operator < (const A&o)const{
		if(x!=o.x) return x<o.x;
		return y>o.y;
	}
};
A a[100100];
int  main(){
	int q,x,y;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&x,&y);
		a[i].x = x;
		a[i].y = y;
	}
	sort(a,a+q);
	for(int i=0;i<q;i++){
		printf("%d %d",a[i].x,a[i].y);
	}
	return 0;
}
