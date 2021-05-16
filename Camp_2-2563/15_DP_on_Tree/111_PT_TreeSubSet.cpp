/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PT_Tree Subset
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

vector<int>g[100100];
int v[100100], dp[100100][2], mark[100100];

void dfs(int u){
	mark[u] = 1;
	dp[u][1] = v[u];
	for(auto x: g[u]){
		if(mark[x]){
			continue;
		}
		dfs(x);
		dp[u][0] += max(dp[x][0], dp[x][1]);
		dp[u][1] += dp[x][0];
	}
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	for(int i=1, st, ed; i<n; ++i){
		cin >> st >> ed;
		g[st].push_back(ed);
		g[ed].push_back(st);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
	memset(v, 0, sizeof v);
	memset(dp, 0, sizeof dp);
	memset(mark, 0, sizeof mark);
	for(int i=1; i<=n; ++i){
		g[i].clear();
	}
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
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
