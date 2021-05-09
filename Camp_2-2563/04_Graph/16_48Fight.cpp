/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48 Fight
 * ALGO		: Bipartite Graph
 * DATE		: 8 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

vector<pair<int, int>>g[100100];
int color[100100], tim[300300];

bool check(int u, int c, int round){
	if(color[u]){
		if(color[u] == c){
			return true;
		}
		return false;
	}
	color[u] = c;
	for(auto x: g[u]){
		if(x.second > round){
			continue;
		}
		if(!check(x.first, 3 - c, round)){
			return false;
		}
	}
	return true;
}

void solve(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
		tim[i] = u;
	}
	int l = 1, r = m;
	while(l < r){
		memset(color, 0, sizeof color);
		int mid = l + (r - l + 1) / 2;
		if(check(tim[mid], 1, mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l + 1;
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
