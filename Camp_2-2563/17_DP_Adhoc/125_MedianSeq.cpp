/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Median Sequence
 * ALGO		: Dynamic Programming ?
 * DATE		: 17 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;

int a[100100], dp[3][200200];

void solve(){
	int z, mid;
	cin >> n >> z;	
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		if(a[i] == z){
			mid = i;
		}
	}
	const int start = 100000;
	dp[0][start] = dp[1][start] = 1;
	// ->
	int state = 0;
	for(int i=mid+1; i<=n; ++i){
		if(a[i] < a[mid]){
			state -= 1;
		}
		else{
			state += 1;
		}
		++dp[0][start + state];
	}
	// <-
	state = 0;
	for(int i=mid-1; i>=1; --i){
		if(a[i] < a[mid]){
			state -= 1;
		}
		else{
			state += 1;
		}
		++dp[1][start + state];
	}
	int ans = 0;
	for(int i=0; i<=2*start; ++i){
		ans += dp[0][i] * dp[1][2*start - i];
	}
	cout << ans;
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
