/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_Node Sort
 * ALGO		: Topological Sort
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

vector<int>g[50500];
int in[50500];

void solve(){
	cin >> n >> m;
	for(int i=0, u, v; i<m; ++i){
		cin >> u >> v;
		g[v].push_back(v);
		in[v]++;
	}
	priority_queue<int, vector<int>, greater<int>>pq;
	for(int i=1; i<=n; ++i){
		if(!in[i]){
			pq.push(i);
		}
	}
	bool ch = false;
	vector<int>ans;
	while(!pq.empty()){
		if(pq.size() >= 2 && !ch){
			
		}
	}
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
		memset(in, 0, sizeof in);
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
