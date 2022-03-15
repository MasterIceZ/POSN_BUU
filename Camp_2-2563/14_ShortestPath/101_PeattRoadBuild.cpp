/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Peatt Road Build
 * ALGO		: Dijkstra
 * DATE		: 18 May 2021
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

struct Node{
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<Node>adj[10010];
int dist[10010];

void solve(){
	cin >> n >> m;
	for(int i=0, u, v, w; i<m; ++i){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node>pq;
	pq.push({1, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: adj[now.v]){
			if(dist[x.v] >= dist[now.v ] + now.w){
				dist[x.v] = dist[now.v] + now.w;
				pq.push({x.v, dist[now.w] + now.w});
			}
		}
	}
	for(int i=0; i<=n; ++i){
		cout << dist[i] << " ";
	}
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
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
