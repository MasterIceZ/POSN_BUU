#include<bits/stdc++.h>
using namespace std;

int n, m;

vector<int>graph[1010];
bool visited[1010];

void dfs(int u){
	if(visited[u]){
		return ;
	}
	visited[u] = true;
	for(auto x: graph[u]){
		dfs(x);
	}
	return ;
}

int main (){

	int q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i=0; i<m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
	}
	while(q--){
		int u, v;
		scanf("%d %d", &u, &v);
		dfs(u);
		printf("%s\n", visited[v]?"Yes":"No");
		memset(visited, false, sizeof visited);
	}

	return 0;
}
