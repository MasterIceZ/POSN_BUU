#include<bits/stdc++.h>
using namespace std;

int dp[55555];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	dp[0] = 1;	
	int x, sum = 0;
	for(int k=0; k<n; ++k){
		cin >> x;
		sum += x;
		for(int i=45000; i>=x; --i){
			if(dp[i - x]){
				dp[i] = 1;
			}
		}
	}
	int ans1, ans2, nin = INT_MAX;
	for(int i=1; i<=sum; ++i){
		if(dp[i]){
			if(abs(sum - 2*i) < nin){
				nin = abs(sum - 2*i);
				ans1 = i, ans2 = sum - i;
				if(ans1 > ans2){
					swap(ans1, ans2);
				}
			}
		}
	}
	cout << ans1 << " " << ans2;
	return 0;
}
