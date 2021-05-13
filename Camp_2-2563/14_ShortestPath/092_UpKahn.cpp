/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Up Kahn
 * ALGO		: Topological Sort
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

vector<int>g[100100], ans;
int in[100100];

void solve(){
	priority_queue<int, vector<int>,  greater<int>>pq;
	cin >> n >> m;
	while(m--){
		int r, s;
		cin >> r >> s;
		in[s]++;
		g[r].push_back(s);
	}	
	for(int i=1; i<=n; ++i){
		if(in[i] == 0){
			pq.push(i);
		}
	}
	while(!pq.empty()){
		int u = pq.top();
		pq.pop();
		ans.push_back(u);
		for(auto x: g[u]){
			in[x]--;
			if(in[x] == 0){
				pq.push(x);
			}
		}
	}
	if(ans.size() == n){
		cout << "Yes";
		for(int i=0; i<n; ++i){
			cout << " " << ans[i];
		}
	}
	else{
		cout << "No";
	}
	memset(in, 0, sizeof in);
	ans.clear();
	for(int i=1; i<=n; ++i){
		g[i].clear();
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
