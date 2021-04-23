/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int dp[50050];

void solution(){
	dp[0] = 1;
	int c, n;
	cin >> c >> n;
	for(int i=0, x; i<n; ++i){
		cin >> x;
		for(int j=c; j>=x; --j){
			if(dp[j-x]){
				dp[j] = 1;
			}
		}
	}
	for(int i=c; i>=1; --i){
		if(dp[i]){
			cout << i << endl;
			return ;
		}
	}
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
