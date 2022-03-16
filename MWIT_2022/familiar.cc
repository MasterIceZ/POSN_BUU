#include <bits/stdc++.h>
using namespace std;

const int MxN = 101;
int deg[MxN];
vector<int> adj[MxN];
bitset<MxN> visited;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=2, u, v; i<=n; ++i){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=1; i<=n; ++i){
		if(deg[i] == 1){
			q.push(i);
			visited[i] = true;
			cout << i << " ";
		}
	}
	while(!q.empty()){
		int now = q.top();
		q.pop();
		for(auto x: adj[now]){
			if(visited[x]){
				continue;
			}
			if(--deg[x] == 1){
				cout << x << " ";
				q.emplace(x);
			}
		}
	}
	cout << "\n";
}
