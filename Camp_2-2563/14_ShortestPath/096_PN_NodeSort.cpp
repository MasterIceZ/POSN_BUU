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
		cin >> v >> u;
		g[u].push_back(v);
		in[v]++;
	}
	priority_queue<int, vector<int>, greater<int>>pq;
	for(int i=1; i<=n; ++i){
		if(!in[i]){
			pq.push(i);
		}
	}
	vector<int>ans;
	int tmp = -1;
	bool check = false;
	while(!pq.empty()){
		if(pq.size() >= 2){
			int a = pq.top();
			tmp = a;
			check =true;
		}
		int now = pq.top();
		pq.pop();
		ans.push_back(now);
		for(auto x: g[now]){
			in[x]--;
			if(!in[x]){
				pq.push(x);
			}
		}
	}	
	if(ans.size() != n){
		cout << "Never";
	}
	else if(check){
		cout << "Different";
		for(int i=0; i<ans.size(); ++i){
			if(ans[i] == tmp){
				swap(ans[i], ans[i+1]);
				break;
			}
		}
		for(auto x: ans){
			cout << " " << x;
		}
	}
	else{
		cout << "Same";
		for(auto x: ans){
			cout << " " << x;
		}
	}
	for(int i=0; i<=n; ++i){
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
