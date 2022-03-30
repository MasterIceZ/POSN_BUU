#include <bits/stdc++.h>
using namespace std;

const int MxN = 450 * 100 + 10;

int dp[MxN], sum;

signed main(){
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	for(int i=1, x; i<=n; ++i){
		scanf("%d", &x);
		sum += x;
		for(int j=450*100; j>=x; --j){
			if(dp[j - x]){
				dp[j] = 1;
			}
		}
	}
	int answer_1, answer_2, minn = INT_MAX;
	for(int i=1; i<=sum; ++i){
		if(!dp[i] || abs(sum - 2 * i) >= minn){
			continue;
		}
		minn = abs(sum - 2 * i);
		answer_1 = i, answer_2 = sum - i;
		if(answer_1 > answer_2){
			answer_1 = answer_1 ^ answer_2;
			answer_2 = answer_1 ^ answer_2;
			answer_1 = answer_1 ^ answer_2;
		}
	}
	printf("%d %d\n", answer_1, answer_2);
	return 0;
}
