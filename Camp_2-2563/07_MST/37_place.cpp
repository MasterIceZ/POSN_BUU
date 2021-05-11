/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Place toi11
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
	int u, v, w;
	bool operator < (const Node&o) const{
		return w < o.w;
	}
};
priority_queue<Node>pq;
int parent[200200];

int root(int u){
	return u==parent[u]?u:parent[u]=root(parent[u]);
}

void solve(){
	cin >> n >> m;
	for(int i=0; i<=n; ++i){
		parent[i] = i;
	}
	int u, v, w;
	for(int i=0; i<m; ++i){
		cin >> u >> v >> w;
		pq.push({u, v, w});
	}
	int ans = 0;
	while(!pq.empty()){
		Node now = pq.top();
		pq.pop();
		int ru = root(now.u), rv = root(now.v);
		if(ru == rv){
			continue;
		}
		parent[ru] = rv;
		ans += now.w - 1;
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
