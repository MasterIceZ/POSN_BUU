/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PT_Town Center
 * ALGO		: Floyd Warshall
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

struct Edge{
	int u, v, w;
	bool operator < (const Edge& o) const{
		return w > o.w;
	}
};

int parent[1010], deg[1010];

int root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = root(parent[u]);
}

void solve(){
	priority_queue<Edge>pq;
	cin >> n;
	for(int i=1; i<=n; ++i){
		parent[i] = i;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			int u, v, w;
			cin >> w;
			if(i < j && w != 0){
				pq.push({i, j, w});
			}
		}
	}
	while(!pq.empty()){
		Edge now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru == rv){
			continue;
		}
		deg[now.u]++, deg[now.v]++;
		parent[ru] = rv;
	}
	int node, nax;
	nax = INT_MIN;
	for(int i=1; i<=n; ++i){
		if(deg[i] > nax){
			nax = deg[i];
			node = i;
		}
	}
	cout << node << " " << nax;
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
		memset(deg, 0, sizeof deg);
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
