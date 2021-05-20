/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Follow
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

int timer[1010][1010], a[1010];
int peatst[1010][1010], peated[1010][1010];
vector<int>adj[10010];
int dist[1010][1010], dist2[1010][1010];

void solve(){
	priority_queue<Node>pq;
	cin >> n >> m;
	int s, e, t, p;
	cin >> s >> e >> t >> p;
	cin >> a[0];
	for(int i=1; i<p; ++i){
		cin >> a[i];
		timer[a[i]][a[i-1]] = 1;
		timer[a[i-1]][a[i]] = 1;
	}
	memset(dist, 0x3f, sizeof dist);
	for(int i=0, u, v, w; i<m; ++i){
		cin >> u >> v >> w;
		dist[u][v] = w;
		dist[v][w] = w;
		adj[u].push_back(v);
		adj[v].push_back(w);
	}
	int path = 0;
	for(int i=0; i<p-1; ++i){
		peated[a[i]][a[i+1]] = path + dist[a[i]][a[i+1]];
		peated[a[i+1]][a[i]] = path + dist[a[i]][a[i+1]];
		path = dist[a[i]][a[i+1]];
	}
	for(int i=1; i<p-1; ++i){
		peatst[a[i]][a[i+1]] = peated[a[i]][a[i-1]];
		peatst[a[i+1]][a[i]] = peated[a[i]][a[i-1]];
	}
	pq.push({s, 0, 0});
	dist2[s][0] = 0;
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
