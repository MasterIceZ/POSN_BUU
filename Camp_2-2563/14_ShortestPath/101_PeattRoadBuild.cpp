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
	int v, w, id, nax;
	bool operator < (const Node& o) const{
		if(w != o.w){
			return w > o.w;
		}
		return nax > o.nax;
	}
};

vector<Node>adj[1010];
int dist[1010][3];
priority_queue<Node>pq;

void solve(){
	cin >> n >> m;
	for(int i=1, u, v, w; i<=m; ++i){
		cin >> u >> v >> w;
		adj[u].push_back({v, w, i});
		adj[v].push_back({u, w, i});
	}
	memset(dist, 0x3f, sizeof dist);
	pq.push({1, 0, 1, 0});
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		if(now.v == n && now.id == 0){
			cout << now.nax << " " << now.w;
			return ;
		}
		for(auto x: adj[now.v]){
			if(dist[x.v][!now.id] >= x.w + now.w){
				dist[x.v][!now.id] = x.w + now.w;
				pq.push({x.v, x.w + now.w, !now.id, max(now.nax, x.id)});
			}
		}
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
//	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
