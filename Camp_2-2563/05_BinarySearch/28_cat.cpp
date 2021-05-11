/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Cat TOI13
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
	cin >> n;
	vector<int>a(n);
	for(auto &x: a){
		cin >> x;
	}	
	int l = 0, r = 1e18;
	while(l < r){
		int mid = (l + r) / 2;
		stack<int>st;
		bool ch = false;
		for(int i=0; i<n; ++i){
			if(a[i] > mid){
				if(st.empty()){
					st.push(a[i]);
				}
				else if(st.top() == a[i]){
					st.pop();
				}
				else{
					ch = true;
				}
			}
		}
		if(st.empty() && !ch){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << l ;
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
