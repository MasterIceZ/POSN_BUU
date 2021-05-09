/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_ComeHome
 * ALGO		: Disjoined Set Union
 * DATE		: 9 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

bool visited[300100];
int par[300100];

int root(int u){
	return par[u]==u?u:par[u]=fr(par[u]);
}

void solve(){
	int l;
	cin >> n >> l;
	for(int i=1; i<=300000; ++i){
		par[i] = i;
	}
	for(int i=1, a, b; i<=n; ++i){
		cin >> a >> b;
		int ra = root(a), rb = root(b);
		if(!visited[ra]){
			visited[ra] = true;
			par[ra] = a;

		}
	}
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
