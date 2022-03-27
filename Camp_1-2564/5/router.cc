#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e5 + 10;
int n, m, a[MxN];

inline bool ok(int x){
	int sum = a[1] + x, uses = 1;
	for(int i=2; i<=m; ++i){
		if(sum + x < a[i]){
			uses++;
			sum = a[i] + x;
		}
	}
	return uses <= n;
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> a[i];
		a[i] = a[i] * 10;
	}
	sort(a + 1, a + m + 1);
	int l = 0, r = 1e9 + 100;
	while(l < r){
		int mid = (l + r) >> 1;
		if(ok(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << (l / 10) << "." << (l % 10) << "\n";
	return 0;
}
