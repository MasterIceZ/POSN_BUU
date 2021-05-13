/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Logistic
 * ALGO		: Dijkstra
 * DATE		: 13 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

void init();

const int mxN=105;
struct Node {
	int u,w,f,q;
	bool operator < (const Node& o) const {
		return w>o.w;
	}
};

priority_queue<Node> pq;
vector<pair<int,int>> adj[mxN];
int d[2][mxN][mxN], f[mxN];

int main() {
	init();
	int n,c,s,e,m;
	cin >> n;
	for(int i=1; i<=n; ++i)
		cin >> f[i];
	cin >> s >> e >> c >> m;
	while(m--) {
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	memset(d, 0x3f, sizeof(d));
	d[0][0][s] = 0;
	pq.push({s, 0, 0, 0});
	while(!pq.empty()) {
		Node t = pq.top();
		int u = t.u, w = t.w, nowf = t.f, q = t.q;
		pq.pop();
		if(nowf+1<=c && d[q][nowf+1][u]>w+f[u]) {
			d[q][nowf+1][u] = w+f[u];
			pq.push({u, d[q][nowf+1][u], nowf+1, q});
		}
		if(!q && d[1][c][u]>w) {
			d[1][c][u]=w;
			pq.push({u, w, c, 1});
		}
		for(auto& x : adj[u]) {
			if(nowf-x.second>=0 && d[q][nowf-x.second][x.first]>w) {
				d[q][nowf-x.second][x.first]=w;
				pq.push({x.first, w, nowf-x.second, q});
			}
		}
	}
	cout << d[1][c][e] << "\n";
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
