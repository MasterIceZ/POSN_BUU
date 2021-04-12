#include<stdio.h>
#include<math.h>
int main (){
	int a,cnt=0,i,k;
	scanf("%d",&a);
	k = sqrt(a);
	for(i=1;i<=k;i++){
		if(a%i==0){
			cnt++;
		}
	}
	if(cnt==1&&a!=1) printf("Yes\n");
	else printf("No\n");
	return 0;
}
