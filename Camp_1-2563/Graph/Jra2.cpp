#include<bits/stdc++.h>
using namespace std;

int n, ans[1111];
vector<int>g[111], a;
bool visited[111];

void dfs(int u, int state=0){
	if(u == 2 && visited[2]){
		int num = 0;
		for(int i=0; i<state; ++i){
			num *= 10;
			num += ans[i];
		}
		a.push_back(num);
		return ;
	}
	ans[state] = u;
	if(visited[u]){
		return ;
	}
	visited[u] = true;
	for(auto x: g[u]){
		dfs(x, state+1);
	}
	visited[u] = false;
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

//	cin >> n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		int u, v;
//		cin >> u >> w;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(2);
	sort(a.begin(), a.end());
	for(auto x : a){
		printf("%d2\n", x);
	}
	return 0;
}
