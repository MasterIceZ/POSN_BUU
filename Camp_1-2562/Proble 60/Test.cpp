#include<bits/stdc++.h>
using namespace std;
long long a[200000] ;
long long b[200000];
int main () {
	int q;
	long long cnt,ch;
	long long h;
	int i;
	scanf("%d",&q);
	while(q--){
		cnt = 0;
		ch = 0;
		scanf("%lld",&h);
		for(i = 0;i<h;i++){
			scanf("%lld",&a[i]);
		}
		sort(a,a+h);
		for(i=0;i<h;i++){
			if(a[i]==a[i+1]){
				cnt++;
				i++;
			}
			else{
				ch++;
				b[ch++] = a[i]; 
			}
		}
		if(ch==0){
			printf("%lld\n",cnt);
			printf("Empty");
		}
		else{
			printf("%lld\n",cnt);
			sort(b,b+ch);
			for(i=0;i<ch;i++){
				if(b[i]!=0)
				printf("%d ",b[i]);
			}
		}
		
	}
	return 0;
}
