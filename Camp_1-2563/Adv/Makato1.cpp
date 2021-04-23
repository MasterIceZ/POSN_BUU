/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int a[100100];

void solution(){
	int n, q, x, r, c;
	cin >> n >> q;
	for(int i=1; i<=n; ++i){
		cin >> x;
		a[i] = a[i-1] ^ x;
	}
	for(int i=0; i<q; ++i){
		cin >> r >> c;
		cout << (a[c]^a[r-1]) << endl;
	}
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
