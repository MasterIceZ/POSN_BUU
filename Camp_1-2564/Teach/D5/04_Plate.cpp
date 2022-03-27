#include<bits/stdc++.h>
using namespace std;

int a[10100],q[1010],fr,en;

int main(){
	int n,m,c,s,i,k;
	char opr;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d %d", &c, &s);
		a[s] = c;
	}
	while(1){
		scanf(" %c", &opr);
		if(opr == 'X'){
			printf("0\n");
			return 0;
		}
		if(opr == 'E'){
			scanf("%d", &n);
			k = en;
			for(i=en-1; i>=fr; i--){
				if(a[n] == a[q[i]]){
					k=i+1;
					break;
				}
			}
			for(i=en-1; i>=k; i--){
				q[i+1] = q[i];
			}
			q[k] = n;
			en++;
		}
		if(opr == 'D'){
			if(fr==en){
				printf("empty\n");
			}
			else{
				printf("%d\n", q[fr++]);
			}
		}
	}
    return 0;
}
