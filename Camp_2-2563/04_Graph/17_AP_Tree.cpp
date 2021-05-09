/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: AP Tree
 * ALGO		: Dynamic Programing on Tree
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
int a[100101], sum, mi;
vector<int>g[100100];

void dfs(int u, int p){
	for(auto x: g[u]){
		if(x == p){
			continue;
		}
		dfs(x, u);
		a[u] += a[x];
	}
	mi = min(mi, abs(sum - 2 * a[u]));
}

void solve(){
	int r, s;
	cin >> n;
	for(int i=0; i<n-1; ++i){
		cin >> r >> s;
		g[r].push_back(s), g[s].push_back(r);
	}
	sum = 0, mi = LLONG_MAX;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	dfs(1, 0);
	cout << mi;
	for(int i=1; i<=n; ++i){
		g[i].clear();
	}
	memset(a, 0, sizeof a);
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
