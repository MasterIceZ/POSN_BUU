#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, f, l, x;
	f = l = 0;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> x;
		f += (x&&i%2==0);
		l += (x&&i%2==1);
	}
	cout << (n%2==1||abs(f-l)<=1?"YES":"NO");
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--){
		solve();
		cout << endl;
	}	

	return 0;
}
