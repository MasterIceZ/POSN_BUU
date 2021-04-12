#include<bits/stdc++.h>
using namespace std;
int main () {
	int q,a,b,cnt=0;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&a,&b);
		if(a<=400&&b<=200&&b>=150)
				cnt++;
	}
	printf("%d",cnt);
	return 0;
}
