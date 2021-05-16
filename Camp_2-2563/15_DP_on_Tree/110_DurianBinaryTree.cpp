/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Durian Binary Tree
 * ALGO		: Dynamic Programming on Tree
 * DATE		: 16 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
//#define int long long
using LL = long long;
void init();
int n, m;
int p[111], dp[111][111];
vector<int>child[111];
vector<pair<int, int>> v[111];

void dfs(int u){
	for(auto x: v[u]){
		if(p[x.first] == -1){
			p[x.first] = x.second;
			child[u].push_back(x.first);
			dfs(x.first);
		}
	}
}

int memoi(int u, int k){
	if(dp[u][k] != -1){
		return dp[u][k];
	}
	if(k == 0){
		return 0;
	}
	if(child[u].size() == 0){
		return p[u];
	}
	if(child[u].size() == 1){
		return dp[u][k] = memoi(child[u][0], k-1) + p[u];
	}
	dp[u][k] = -1;
	for(int i=0; i<=k-1; ++i){
		dp[u][k] = max(dp[u][k], memoi(child[u][0], i) + memoi(child[u][1], k-i-1) + p[u]);
	}
	return dp[u][k];
}

void solve(){
	int k;
	cin >> n >> k;
	memset(p, -1, sizeof p);
	memset(dp, -1, sizeof dp);
	for(int i=1; i<n; ++i){
		int s, e, val;
		cin >> s >> e >> val;
		v[s].push_back({e, val});
		v[e].push_back({s, val});
	}
	p[1] = 0;
	dfs(1);
	cout << memoi(1, k+1);
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
