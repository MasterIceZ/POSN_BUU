/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_Stupid
 * ALGO		: Binary Search
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

void solve(){
//	int s, p;
	LL s, p;
	cin >> s >> p;
//	int l, r;
	LL l, r;
//	l = 1;
//	r = (s+1)/2;
	l = 0, r = s/2;
	bool mark = false;
	while(l <= r){
//		int mid = (l + r) / 2;
		LL mid = (l+r)/2;
		if(mid * (s - mid) > p || mid * (s-mid)/(s-mid) != mid){
			r = mid - 1;
		}
		else if(mid * (s - mid) < p){
			l = mid + 1;
		}
		else{
			cout << min(mid, s-mid) << " " << max(mid, s-mid);
			return ;
			break;
		}
	}
	cout << "No answer";
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
