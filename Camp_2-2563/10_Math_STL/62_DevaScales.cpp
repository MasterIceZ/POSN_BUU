/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Deva Scales
 * ALGO		: Math
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
int a[33], b[33];

void solve(){
	int t = 0;
	a[0] = 1;
	for(int i=1; i<=20; ++i){
		a[i] = a[i-1] * 3;
	}
	b[0] = 1;
	for(int i=1; i<=20; ++i){
		b[i] = b[i-1] + a[i];
	}
	cin >> n;
	int sum = n;
	int i;
	while(1){
		for(i=0; i<20; ++i){
			if(b[i] + n < a[i+1]){
				break;
			}
		}
		n = abs(n-a[i]), ++t;
		sum += a[i];
		if(n == 0){
			break;
		}
	}
	cout << t << " " << sum/2;
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
