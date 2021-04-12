#include<bits/stdc++.h>
using namespace std;
char a[110];
int main () {
	int q,i;
	int cou=0,cnt=0;
	int j;
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%c",a[i]);
	}
	for(i=0;i<q;i++){
		if(a[i]=='#'){
			for(j=0;j<q;j++){
				if(a[i+j]=='.'){
					cnt++;
					cou = cnt;
				}
			}
		}
		if(cou>cnt){
			cnt ==0;
		}
	}
	return 0;
}
