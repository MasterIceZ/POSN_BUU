#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MxN = 1e6 + 10;
ll n, b, a[MxN];

inline bool ok(ll x){
	ll sum = 0;
	for(ll i=1; i<=n; ++i){
		sum += max(0ll, a[i] - x);
		if(sum >= b){
			return true;
		}
	}
	return false;
}	

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> b;
	for(ll i=1; i<=n; ++i){
		cin >> a[i];
	}
	ll l = 0, r = 1e9 + 200;
	while(l < r){
		ll mid = (l + r + 1) >> 1;
		if(ok(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}
	cout << l << "\n";
	return 0;
}
