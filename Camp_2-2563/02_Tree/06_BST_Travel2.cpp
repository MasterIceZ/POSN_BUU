/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: BST Travel 2
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
int a[333], l[333], r[333];

void pr(int i){
	cout << a[i] << " ";
	if(l[i]){
		pr(l[i]);
	}
	if(r[i]){
		pr(r[i]);
	}
}

void po(int i){
	if(l[i]){
		po(l[i]);
	}
	if(r[i]){
		po(r[i]);
	}
	cout << a[i] << " ";
}

void in(int i){
	if(l[i]){
		in(l[i]);
	}
	cout << a[i] << " ";
	if(r[i]){
		in(r[i]);
	}
}

void solve(){
	cin >> n;
	cin >> a[1];
	for(int i=2; i<=n; ++i){
		cin >> a[i];
		int ptr = 1;
		while(1){
			if(a[i] < a[ptr]){
				if(l[ptr] == 0){
					l[ptr] = i;
					break;
				}
				ptr = l[ptr];
			}
			else{
				if(r[ptr] == 0){
					r[ptr] = i;
					break;
				}
				ptr = r[ptr];
			}
		}
	}
	pr(1);
	cout << endl;
	po(1);
	cout << endl;
	in(1);
	cout << endl;
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
