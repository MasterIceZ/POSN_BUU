/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: disaster
 * ALGO		: Depth First Search
 * DATE		: 7 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
vector<pair<int, int>> g[33];
char a[10];
int deg[33], mark[33][33][333], ans[333];

void dfs(int u, int state){
	ans[state] = u;
	if(state == n){
		for(int i=0; i<=n; ++i){
			cout << (char)('A' + ans[i]) << " ";
		}
		exit(0);
	}
	for(auto x: g[u]){
		if(mark[u][x.first][x.second]){
			continue;
		}
		mark[u][x.first][x.second] = mark[x.first][u][x.second] = 1;
		dfs(x.first, state+1);
		mark[u][x.first][x.second] = mark[x.first][u][x.second] = 0;
	}
}

void solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a;
		g[a[0] - 'A'].emplace_back(a[1] - 'A', i);
		g[a[1] - 'A'].emplace_back(a[0] - 'A', i);
		deg[a[0] - 'A']++, deg[a[1] - 'A']++;
	}
	for(int i=0; i<=25; ++i){
		sort(all(g[i]));
	}
	int st = -1, mi = 30;
	for(int i=0; i<=25; ++i){
		if(deg[i]%2 == 0){
			st = i;
			break;
		}
		else if(deg[i] > 0){
			mi = min(mi, i);
		}
	}
	if(st == -1){
		st = mi;
	}
	dfs(st, 0);
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
