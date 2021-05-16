/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW BUU
 * CENTER	: BUU RYW
 * TASK		: PN_Lucky (Unlucky)
 * ALGO		: Dijkstra algorithm :V
 * DATE		: 16 May 2021
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

int luck[50500];

struct Node{
	int v, w, l;
	bool operator < (const Node& o) const{
		return w > o.w;
	}
};

vector<pair<int, int>>g[50500];
int dist[111][50500];

void solve(){
	int l, s, t;
	cin >> n >> m >> l >> s >> t;
	for(int i=1; i<=n; ++i){
		cin >> luck[i];
	}
	for(int i=0, u, v, w; i<m; ++i){
		cin >> u >> v >> w;
		g[u].push_back({v, w});
	}
	memset(dist, 0x3f, sizeof dist);
	priority_queue<Node>pq;
	pq.push({s, 0, 0});
	dist[0][s] = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		for(auto x: g[now.v]){
			if(now.l+1 == luck[x.first] && dist[now.l+1][x.first] > now.w + x.second){
				dist[now.l+1][x.first] = now.w + x.second;
				pq.push({x.first, dist[now.l+1][x.first], now.l+1});
			}
			else if(dist[now.l][x.first] > now.w + x.second && dist[now.l][x.first] > now.w + x.second ){
				dist[now.l][x.first] = now.w + x.second;
				pq.push({x.first, dist[now.l][x.first], now.l});
			}
		}
	}
	cout << (dist[l][t]>=1e9?-1:dist[l][t]);

	for(int i=0;i<=50000; ++i){
		g[i].clear();
	}
	memset(luck, 0, sizeof luck);
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
