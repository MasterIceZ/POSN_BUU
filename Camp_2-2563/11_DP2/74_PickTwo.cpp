/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Picktwo Sequence
 * ALGO		: Dyamic Programming
 * DATE		: 11 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int l[100100], r[100100], a[100100];

namespace ice{
	int max(int a, int b){
		return a>b?a:b;
	}
}

void solve(){
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	memset(a, 0, sizeof a);
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	int sum, nax, ans;
	nax = ans = INT_MIN;
	sum = 0;
	for(int i=1; i<=n; ++i){
		sum += a[i];
		sum = ice::max(sum, 0);
		nax = max(sum, nax);
		l[i] = nax;
	}
	nax = ans = INT_MIN;
	sum = 0;
	for(int i=n; i>=1; --i){
		sum += a[i];
		sum = ice::max(sum, 0);
		nax = max(sum, nax);
		r[i] = nax;
	}
	for(int i=1; i<=n; ++i){
		ans = max(ans, l[i] + r[i+1]);
	}
	cout << ans;
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
