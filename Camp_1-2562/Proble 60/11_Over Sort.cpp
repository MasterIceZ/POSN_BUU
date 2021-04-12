#include<bits/stdc++.h>
using namespace std;
struct A{
	char a[203];
	bool operator < (const A&o)const{
		if(strcmp(a,o.a)<0) return true;
		else return false;
	}
};
A d[1000005];
int a[1000007];
double b[1000006];
char c[1000004];
int main (){
	int opr,n,i;
	scanf("%d %d",&opr,&n);
	if(opr==1){
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
			sort(a,a+n);
			for(i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
			for(i=n-1;i>=0;i--){
				printf("%d ",a[i]);
			}
		
	}
	if(opr==2){
		for(i=1;i<=n;i++) scanf("%lf",&b[i]);
		sort(b+1,b+n+1);
		for(i=1;i<=n;i++) printf("%.0lf ",b[i]);
		printf("\n");
		for(i=n;i>=1;i--) printf("%.0lf ",b[i]);
	}
	if(opr==3){
		for(i=2;i<=n+1;i++) scanf(" %c",&c[i]);
		sort(c+2,c+n+2);
		for(i=2;i<=n+1;i++) printf("%c ",c[i]);
		printf("\n");
		for(i=n+1;i>=2;i--) printf("%c ",c[i]);
	}
	if(opr==4){
		for(i=1;i<=n;i++) scanf(" %s",d[i].a);
		sort(d+1,d+n+1);
		for(i=1;i<=n;i++) printf("%s ",d[i].a);
		for(i=n;i>=1;i--) printf("%s ",d[i].a);
	}
	return 0;
}
