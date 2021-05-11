/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Stair
 * ALGO		: Dynamic Programming
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

int a[5555] = {1};

void solve(){
	int k;
	cin >> n >> k;
	for(int i=1; i<=n; ++i){
		for(int j=n; j>=i; --j){
			a[j] += a[j-i];
			a[j] %= k;
		}
	}
	cout << a[n]-1;
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
