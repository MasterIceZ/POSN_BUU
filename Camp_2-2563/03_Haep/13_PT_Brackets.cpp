/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PT_Brackets
 * ALGO		: Heap
 * DATE		: 7 May 2021
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
	string s;
	cin >> s;
	vector<int> a(s.size()), b(s.size());
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '?'){
			cin >> a[i] >> b[i];
		}
	}
	int ans = 0;
	for(int i=1; i<s.size(); ++i){

	}
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
