#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e5 + 10;
int types[MxN], w[MxN], c[MxN];
int n, k, it;

inline bool ok(int x){
	int sum = 0, box = 1;
	for(int i=1; i<=n; ++i){
		sum += w[i];
		if(sum > x || types[c[i]] == it){
			box++, it++;
			sum = w[i];
		}
		types[c[i]] = it;
	}
	return box <= k;
}


inline void solve(){
	memset(types, 0, sizeof types);
	cin >> n >> k;
	int maxx = -1;
	bool _ok = true;
	for(int i=1; i<=n; ++i){
		cin >> w[i] >> c[i];
		maxx = max(maxx, w[i]);
		types[c[i]]++;
		if(types[i] > k){
			_ok = false;
		}
	}
	if(!_ok){
		cout << "-1" ;
		return ;
	}
	int l = maxx, r = 1 + accumulate(w + 1, w + n + 1, 0);
	// binary search limit
	memset(types, 0, sizeof types);
	while(l < r){
		int mid = (l + r) >> 1;
		++it;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
//	cout << "D : " << l << "\n";
	cout << (l > accumulate(w + 1, w + n + 1, 0) ? -1: l) ;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}
	return 0;
}
