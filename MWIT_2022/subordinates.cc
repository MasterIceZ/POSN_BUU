#include <bits/stdc++.h>
using namespace std;

const int MxN = 200200;
vector<int> adj[MxN];
int dp[MxN];

void dfs(int u){
	for(auto x: adj[u]){
		dfs(x);
		dp[u] += dp[x] + 1;
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=2, x; i<=n; ++i){
		cin >> x;
		adj[x].push_back(i);
	}
	dfs(1);
	for(int i=1; i<=n; ++i){
		cout << dp[i] << " ";
	}
	cout << "\n";
	return 0;
}
