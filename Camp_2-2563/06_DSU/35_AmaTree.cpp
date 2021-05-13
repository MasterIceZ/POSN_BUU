/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Ama-Tree
 * ALGO		: Disjoined Set Union
 * DATE		: 12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define sz(x) (x).size()
using ll = long long;
const int mxN = 1e5+10;
struct A {
	int u,v;
} a[mxN];
int qs[mxN], query[mxN], p[mxN];
vector<pair<int,int>> adj[mxN];
map<int, ll> mp[mxN];
void dfs(int u, int pa, int x) {
	qs[u] = x;
	for(auto& v : adj[u])
		if(v.first!=pa) dfs(v.first, u, v.second^x);
}
int fr(int i) {
	if(p[i]==i) return i;
	return p[i] = fr(p[i]);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i=1,u,v,w; i<n; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		a[i] = {u, v};
	}
	dfs(1, 0, 0);
	for(int i=1; i<=n; ++i) {
		p[i] = i;
		mp[i][qs[i]]=1;
	}
	for(int i=1; i<n; ++i)
		cin >> query[i];
	vector<ll> ans{0ll};
	ll sum=0;
	for(int i=n-1; i>=1; --i) { 
		int u = fr(a[query[i]].u), v = fr(a[query[i]].v);
		if(sz(mp[u])>=sz(mp[v])) {
			for(auto& x : mp[v])
				sum += x.second*mp[u][x.first], mp[u][x.first]+=x.second;
			p[v]=u;
		}
		else {
			for(auto& x : mp[u])
				sum += x.second*mp[v][x.first], mp[v][x.first]+=x.second;
			p[u]=v;
		}
		ans.push_back(sum);
	}
	reverse(ans.begin(), ans.end());
	for(auto& x : ans)
		cout << x << "\n";
	return 0;
}
