/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Bipartite
 * ALGO		: Depth First Search
 * DATE		: 8 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

vector<int>g[100100];
int color[100100];

bool dfs(int u, int c){
	if(color[u] != 0 && color[u] == c){
		return true;
	}
	if(color[u] != 0 && color[u] != c){
		return false;
	}
	color[u] = c;
	for(auto x: g[u]){
		if(!dfs(x, 3-c)){
			return false;
		}
	}
	return true;
}

void solve(){
	cin >> n >> m;
	for(int i=0; i<m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout << (dfs(1, 1)?"yes":"no");
	memset(color, 0, sizeof color);
	for(int i=0; i<=n; ++i){
		g[i].clear();
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
