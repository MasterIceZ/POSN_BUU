/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Turbo Programming
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
	int v, w;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

const int MxN = 1010;
vector<Node>g[MxN];
int dist[MxN];
priority_queue<Node>pq;
bool visited[MxN];

void solve(){
	int q;
	cin >> n >> m >> q;
	for(int i=0; i<m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	memset(dist, -1, sizeof dist);
	pq.push({1, 0});
	dist[1] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(visited[now.v]){
			continue;
		}
		visited[now.v] = true;
		dist[now.v] = now.w;
		for(auto x: g[now.v]){
			pq.push({x.v, now.w + x.w});
		}
	}
	while(q--){
		int x;
		cin >> x;
		cout << dist[x] << endl;
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
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
