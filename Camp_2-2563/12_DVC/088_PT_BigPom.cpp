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
void init();
int n, m, r, c, s;
int a[100100];

int divide(int nowl, int nowr){
	int lb, ub;
	lb = lower_bound(a+1, a+c+1, nowl) - (a);
	ub = upper_bound(a+1, a+c+1, nowr) - (a);
	if(ub-lb==0){
		return r;
	}
	if(nowl == nowr){
		return (nowr - nowl + 1) * (ub - lb) * s;
	}
	int mid = (nowl+nowr)/2;
	int dl = divide(nowl, mid);
	int dr = divide(mid+1, nowr);
	int ret;
	if(ub - lb){
		ret = (nowr - nowl + 1) * (ub - lb) * s;
	}
	else{
		ret = r;
	}
	return min(ret, (dl + dr));
}

void solve(){
	cin >> n >> c >> r >> s;
	for(int i=1; i<=c; ++i){
		cin >> a[i];
	}	
	sort(a+1, a+c+1);
	cout << divide(1, (1 << n));
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
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
