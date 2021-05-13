/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Refuel
 * ALGO		: Dijkstra
 * DATE		: 13 May 2021
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
	int v, w, fuel;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<Node>g[11111];
priority_queue<Node>pq;
int dist[1111][111], a[1111];

void solve(){
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}	
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w, 0});
		g[v].push_back({u, w, 0});
	}
	int c, s, e;
	cin >> c >> s >> e;
	for(int i=0; i<=1000; ++i){
		for(int j=0; j<=100; ++j){
			dist[i][j] = INT_MAX;
		}
	}
	dist[s][0] = 0;
	pq.push({s, 0 , 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == e){
			break;
		}
		if(now.fuel+1<=c && now.w+a[now.v]<dist[now.v][now.fuel+1]){
			dist[now.v][now.fuel+1] = now.w + a[now.v];
			pq.push({now.v, dist[now.v][now.fuel+1], now.fuel+1});
		}
		for(auto x: g[now.v]){
			if(now.fuel>=x.w && now.w<dist[x.v][now.fuel-x.w]){
				dist[x.v][now.fuel-x.w] = now.w;
				pq.push({x.v, now.w, now.fuel-x.w});
			}
		}
	}
	int nin = INT_MAX;
	for(int i=0; i<=c; ++i){
		nin = min(nin, dist[e][i]);
	}
	if(nin == INT_MAX){
		cout << -99;
	}
	else{
		cout << nin;
	}
	for(int i=0; i<n; ++i){
		g[i].clear();
	}
	while(!pq.empty()){
		pq.pop();
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
