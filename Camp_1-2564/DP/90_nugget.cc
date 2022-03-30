#include <bits/stdc++.h>
using namespace std;

const int MxN = 110;
int dp[MxN], printed = 0;

const int A[] = {6, 9, 20};

signed main(){
	int n;
	scanf("%d", &n);
	dp[0] = true;
	for(int i=6; i<=n; ++i){
		int ok = 0;
		for(int j=0; j<3; ++j){
			if(i - A[j] < 0){
				continue;
			}
			ok |= dp[i - A[j]];
		}
		dp[i] = ok;
		if(ok){
			printf("%d\n", i);
			printed = 1;
		}
	}
	if(!printed){
		printf("no\n");
	}
	return 0;
}
