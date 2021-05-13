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
	return par[u]==u?u:par[u]=root(par[u]);
}

void solve(){
	int l;
	cin >> n >> l;
	for(int i=1; i<=300000; ++i){
		par[i] = i;
	}
	for(int i=1, a, b; i<=n; ++i){
		cin >> a >> b;
		bool ch = false;
		int ra = root(a), rb = root(b);
		if(!visited[a]){
			visited[a] = true;
			par[ra] = rb;
			ch = true;
		}
		else if(!visited[b]){
			visited[b] = true;
			par[rb] = ra;
			ch = true;
		}
		else if(!visited[ra]){
			visited[ra] = true;
			par[ra] = rb;
			ch = true;
		}
		else if(!visited[rb]){
			visited[rb] = true;
			par[rb] = ra;
			ch = true;
		}
		cout << (ch?"Yes":"No") << endl;
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
