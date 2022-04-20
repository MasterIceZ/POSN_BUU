/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: General
 * ALGO		: Disjoint Set Union
 * DATE		: 17 Apr 2022
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(x) (x).begin(), (x).end()

using ll = long long;

int a[100010], p[100010];

int root(int u){
	if(u == p[u]){
		return u;
	}
	return p[u] = root(p[u]);
}

void solve(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		p[i] = i;
	}
	while(m--){
		int u, v;
		cin >> u >> v;
		int ru = root(u), rv = root(v);
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

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q = 1;
//	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}
	return 0;
}
