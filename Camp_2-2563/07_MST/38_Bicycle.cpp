/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Bicycle
 * ALGO		: Minimum Spanning Tree
 * DATE		: 9 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

struct Node{
	int u, v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};
int p[51000];
int root(int u){
	return u==p[u]?u:p[u]=root(p[u]);
}

void solve(){
	vector<Node>g;
	cin >> n >> m;
	unordered_map<int, int>mp;
	for(int i=1, x; i<=n; ++i){
		cin >> x;
		mp[x] = i, p[i] = i;
	}
	int sum = 0;
	for(int i=0; i<m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({mp[u], mp[v], w});
		sum += w;
	}
	sort(all(g));
	for(auto x: g){
		int ru = root(x.u), rv = root(x.v);
		if(p[ru] != p[rv]){
			sum -= x.w;
			p[ru] = rv;
		}
	}
	cout << sum ;
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
