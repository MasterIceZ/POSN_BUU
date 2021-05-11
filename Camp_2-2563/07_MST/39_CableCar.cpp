/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Cable Car TOI12
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
	int v, w;
	bool operator < (const Node&o) const{
		return w < o.w;
	}
};

priority_queue<Node>pq;
vector<Node> g[2555];
int dist[2555];

void solve(){
	cin >> n >> m;
	for(int i=0; i<m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	int u, v, w;
	cin >> u >> v >> w;
	dist[u] = INT_MAX;
	pq.push({u, INT_MAX});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == v){
			cout << (int)ceil((double)w / (now.w-1));
			break;
		}
		for(auto x: g[now.v]){
			if(dist[x.v] >= min(now.w, x.w)){
				continue;
			}
			dist[x.v] = min(now.w, x.w);
			pq.push({x.v, dist[x.v]});
		}
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
