/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: RO
 * ALGO		: Dynamic Programming
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
char s[1000100];

void solve(){
	int k, qs=0 ,ans=0;
	map<int, int>mp;
	scanf("%lld %lld %s", &n, &k, s+1);
	for(int i=1; i<=n; ++i){
		if(s[i] == 'O'){
			qs++;
		}
		else{
			qs-=k;
		}
		if(mp[qs]){
			ans = max(ans, (i)-mp[qs]);
		}
		else{
			mp[qs] = i;
		}
	}
	printf("%lld\n", ans);
	return ;
}

int32_t main(){
	int t=1;
//	cin >> t;
	while(t--){
		solve();
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
