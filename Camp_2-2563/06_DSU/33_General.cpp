/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		:
 * ALGO		:
 * DATE		:
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
const int MxN = 100100;
int p[MxN], a[MxN];
int root(int u){
	if(p[u] == u){
		return u;
	}
	return p[u] = root(p[u]);
}
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		p[i] = i;
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		int ru = root(u),rv = root(v);
		if(ru == rv){
			cout << -1;
		}
		else if(a[ru] == a[rv]){
			cout << min(ru, rv);
			a[min(ru, rv)] += a[max(ru, rv)] / 2;
			p[max(ru, rv)] = root(min(ru, rv));
		}
		else if(a[ru] > a[rv]){
			cout << ru;
			a[ru] += a[rv] / 2;
			p[rv] = root(ru);
		}
		else{
			cout << rv;
			a[rv] += a[ru] / 2;
			p[ru] = root(rv);
		}
		cout << endl;
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
