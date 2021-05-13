/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: AP_Shark
 * ALGO		: Depth First Search
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

vector<int>g[1010];
int w[1010], mark[1010], j;
int sum = 0, nax = INT_MIN;

void dfs(int u){
	if(mark[u] == j){
		return ;
	}
	mark[u] = j;
	sum += w[u];
	for(auto x: g[u]){
		dfs(x);
	}
}

void solve(){
	int ans = 1;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> w[i];
	}
	for(int i=0, r, s; i<m; ++i){
		cin >> r >> s;
		g[r].push_back(s);
	}
	for(j=0; j<=n; ++j){
		sum = 0;
		dfs(j);
		if(sum > nax){
			nax = sum;
			ans = j;
		}
	}
	cout << ans << " " << nax;
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
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
