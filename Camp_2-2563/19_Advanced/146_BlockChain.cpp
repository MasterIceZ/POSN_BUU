/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Block Chain
 * ALGO		: Map
 * DATE		: 17 May 2021
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

map<vector<pair<int, int>>, int>mp;
vector<pair<int, int>>g;

void solve(){
	int q;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		int sz;
		cin >> sz;
		for(int j=1, u, v; j<sz; ++j){
			cin >> u >> v;
			g.emplace_back(min(u, v), max(u, v));
		}
		sort(all(g));
		++mp[g];
		g.clear();
	}
	while(q--){
		int sz;
		cin >> sz;
		for(int i=1; i<sz; ++i){
			int u, v;
			cin >> u >> v;
			g.emplace_back(min(u, v), max(u, v));
		}
		sort(all(g));
		cout << mp[g] << endl;
		g.clear();
	}
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
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
