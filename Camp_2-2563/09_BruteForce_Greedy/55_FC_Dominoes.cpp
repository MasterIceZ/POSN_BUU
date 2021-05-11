/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: FC_Dominoes
 * ALGO		: Brute Force
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
int a[100100], b[100100];

void solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i] >> b[i];
	}
	int nax=0, now=0, cnt=0, ansst, st;
	char ans;
	for(int i=0; i<n; ++i){
		if(now <= a[i]){
			if(nax < cnt){
				nax = cnt, ansst = st, ans = 'R';
			}
			st = i, cnt=1, now = a[i] + b[i];
		}
		else{
			now = max(now, a[i]+b[i]);
			cnt++;
		}
	}
	if(nax < cnt){
		nax = cnt, ansst = st, ans = 'R';	
	}
	now = INT_MAX, cnt = 0;
	for(int i=n-1; i>=0; --i){
		if(now >= a[i]){
			if(nax < cnt){
				ansst = st, nax = cnt, ans = 'L';
			}
			else if((nax == cnt) && (ansst >= st)){
				ansst = st, nax = cnt, ans = 'L';
			}
			st = i, cnt = 1, now = a[i] - b[i];
		}
		else{
			now = min(now, a[i] - b[i]);
			cnt++;
		}
	}
	if(nax < cnt){
		ansst = st, nax = cnt, ans = 'L';
	}
	else if(nax == cnt && ansst >= st){
		ansst = st, nax = cnt, ans = 'L';
	}
	cout << ansst + 1 << " " << ans;
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
