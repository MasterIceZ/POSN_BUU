/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Budget TOI15
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

struct Node{
	int u, v, w;
	bool operator < (const  Node& o) const{
		return w > o.w;
	}
};
struct Cost{
	int u, v;
	bool operator < (const Cost& o) const{
		if(u != o.u){
			return u < o.u;
		}
		return v < o.v;
	}
};

priority_queue<Node>pq;
vector<Cost>cost;
int n, m;
int parent[3333];

// Find Parent
int root(int u){
	if(u == parent[u]){
		return u;
	}
	return parent[u] = root(parent[u]);
}

// Using Kruskal's Algorithm
void solve(){
//	int cnt = 0;
	for(int i=0; i<=3003; ++i){
		parent[i] = i;
	}
	cin >> n >> m;
	for(int i=0; i<m; ++i){
		int u, v, w, state;
		cin >> u >> v >> w >> state;
		// if had roof already -> change len to 0
		// Free \(OwO)/
		if(state == 1){
			w = 0;
		}
		pq.push({u, v, w});
	}
	int p;
	cin >> p;
	cost.push_back({0, 0});
	for(int i=0; i<p; ++i){
		int u, v;
		// u -> Length, v -> Cost
		cin >> u >> v;
		cost.push_back({u, v});
	}
	// Sort by Length -> Cost
	sort(all(cost));
	int ans = 0;
	// Greedy find minimum cost for best length 
	for(int i=p-1; i>=0; --i){
		cost[i].v = min(cost[i].v, cost[i+1].v);
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		// Find if node isn't on MST
		if(ru != rv){
			// Union
			parent[ru] = rv;
			// Ans -> minimum cost of creating roof (create MST)
			ans += cost[lower_bound(all(cost), Cost{now.w, INT_MIN}) - cost.begin()].v;
		}
	}
	cout << ans ;
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
