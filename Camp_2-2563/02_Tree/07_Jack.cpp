/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Jack
 * ALGO		: Depth First Search
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;
int a[100100], l[100100], r[100100];

void solve(){
	cin >> n >> a[1];
	cout << "*" << endl;
	for(int i=2; i<=n; ++i){
		cin >> a[i];
		int ptr = 1;
		while(1){
			if(a[i] < a[ptr]){
				cout << "L";
				if(l[ptr] == 0){
					l[ptr] = i;
					break;
				}
				ptr = l[ptr];
			}
			else if(a[i] > a[ptr]){
				cout << "R";
				if(r[ptr] == 0){
					r[ptr] = i;
					break;
				}
				ptr = r[ptr];
			}
		}
		cout << "*" << endl;
	}
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
