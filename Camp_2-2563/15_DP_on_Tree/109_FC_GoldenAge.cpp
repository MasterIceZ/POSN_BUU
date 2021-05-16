/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: FC_Golden Age
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 16 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;

int tree[5555], dp[5555][111];

int memoi(int u, int k){
	if(u >  n|| k == 0){
		return 0;
	}
	if(dp[u][k] != -1){
		return dp[u][k];
	}
	for(int i=0; k-i-1>=0; ++i){
		dp[u][k] = max(dp[u][k], tree[u] + memoi(2*u, i) + memoi(2*u+1, k-i-1));
	}
	return dp[u][k];
}

void solve(){
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		cin >> tree[i];
	}
	memset(dp, -1, sizeof dp);
	int ans = -1;
	for(int i=1; i<=n; ++i){
		ans = max(ans, memoi(i, k));
	}
	cout << ans;
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
