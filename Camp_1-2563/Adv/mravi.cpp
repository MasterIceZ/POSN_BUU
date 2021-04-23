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
	int n, m;
	cin >> n >> m;
	int q, x;
	cin >> q;
	char c;
	vector<int>v;
	for(int i=0; i<q; ++i){
		cin >> x >> c;
		if(c == 'D'){
			x += m;
			x %= 2*n;
		}
		else{
			x = m-x;
			x = (x%(2*n) + 2*n)%(2*n);
		}
		if(x >= n){
			x = 2*n - x;
		}
		v.push_back(x);
	}
	sort(v.begin(), v.end());
//	cout << v.size();	
	for(auto a: v){
		cout << a << " ";
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
