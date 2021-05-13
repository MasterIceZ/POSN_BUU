/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Latch EOIC#47
 * ALGO		: Stack
 * DATE		:  12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;
const int mxN = 1005;
#define ll long long
ll dp[mxN][mxN], a[mxN][mxN];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			dp[i][j]=dp[i][j-1]+1;
			cin >> a[i][j];
			if(a[i][j]!=a[i][j-1]) dp[i][j]=1;
		}
	}
	ll ans=0ll;
	for(int j=1; j<=m; ++j) {
		stack<ll> st;
		ll sum=0ll;
		for(int i=1; i<=n; ++i) {
			if(a[i][j]!=a[i-1][j]) {
				while(!st.empty())
					st.pop();
			   	sum=0ll;
			}
			if(st.empty() || (!st.empty()&&dp[i][j]>=st.top())) { 
				st.push(dp[i][j]), sum+=dp[i][j];
			}
			else {
				int cnt=1; 
				while(!st.empty()&&st.top()>dp[i][j])
					++cnt, sum-=st.top(), st.pop();
				while(cnt--) st.push(dp[i][j]), sum+=dp[i][j];
			}
			ans+=sum;
		}
	}
	cout << ans << "\n";
	return 0;
}
