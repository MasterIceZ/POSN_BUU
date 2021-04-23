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

void solution(){
	map<string, bool>mp;
	int n, m;
	cin >> n >> m;	
	for(int i=0; i<m; ++i){
		string s;
		cin >> s;
		mp[s] = true;
	}
	cout << (mp.size()==n?"yes":"no");
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
		cout << endl;
	}
	return 0;
}
