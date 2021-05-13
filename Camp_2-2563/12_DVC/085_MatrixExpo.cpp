/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Matrix Expo
 * ALGO		: Divide and Conquer
 * DATE		: 13 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m, c;

struct A{
	int a[5][5];
};

int mod;
A mul(A a, A b){
	A tmp;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			tmp.a[i][j] = 0;
			for(int k=0; k<n; ++k){
				tmp.a[i][j] += a.a[i][k]*b.a[k][j];
				tmp.a[i][j] %= mod;
			}
		}
	}
	return tmp;
}

A p[65], ans;

void solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin >> p[0].a[i][j];
		}
	}
	ans = p[0];
	cin >> m >> mod;
	if(m == 0){
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				if(i == j){
					cout << (1%mod) << " ";
				}
				else{
					cout << 0 << " " ;
				}
			}
			cout << endl;
		}
		return ;
	}
	m -= 1;
	for(int i=1; i<=63; ++i){
		p[i] = mul(p[i-1], p[i-1]);
	}
	for(int i=0 ;i<=63; ++i){
		if((1ll << i) & m){
			ans = mul(ans, p[i]);
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout << ans.a[i][j] << " ";
		}
		cout << endl;
	}
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
//	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
