/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: FC_Road Wonder
 * ALGO		: Bellman-Ford
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

struct Node{
	int u, v, w;
};

vector<Node>a;
int dist[2222], tmp[2222];

void solve(){
	int k, t;
	cin >> n >> m >> k >> t;
	for(int i=0, u, v, w; i<m; ++i){
		cin >> u >> v >> w;
		a.push_back({u, v, w});
	}
	for(int i=0, u, v, w; i<k; ++i){
		cin >> u >> v >> w;
		a.push_back({u, v, w*-1});
	}
	int s;
	while(t--){
		cin >> s;
		for(int i=1; i<=n; ++i){
			dist[i] = INT_MAX;
		}
		dist[s] = 0;
		for(int i=0; i<n-1; ++i){
			for(int j=0; j<a.size(); ++j){
				if(dist[a[j].u] != INT_MAX && dist[a[j].u] + a[j].w < dist[a[j].v]){
					dist[a[j].v] = dist[a[j].u] + a[j].w;
				}
			}
		}
		for(int i=1; i<=n; ++i){
			tmp[i] = dist[i];
		}
		for(int j=0; j<a.size(); ++j){
			if(dist[a[j].u] != INT_MAX && dist[a[j].u] + a[j].w < dist[a[j].v]){
				dist[a[j].v] = dist[a[j].u] + a[j].w;
			}
		}
		for(int i=1; i<=n; ++i){
			if(dist[i] != tmp[i] || dist[i] == INT_MAX){
				cout << -1;
			}
			else{
				cout << dist[i];
			}
			cout << " ";
		}
		cout << endl;
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
