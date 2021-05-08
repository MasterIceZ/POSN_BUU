/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_Parenthesis
 * ALGO		: Stack
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

void solve(){
	cin >> n;
	int ans = 0, ans2 = 0;
	map<int, int>cnt;
	stack<pair<char, int>>st;
	for(int i=1; i<=n; ++i){
		char x;
		cin >> x;
		if(x == '('){
			st.emplace(x, 0);
		}
		else{
			int nax = 0;
			while(!st.empty()){
				auto now = st.top();
				st.pop();
				if(now.first == '('){
					break;
				}
				nax = max(nax, now.second);
			}
			cnt[nax+1]++;
			ans++;
			ans2 = max(ans2, nax+1);
			st.emplace('A', nax+1);
		}
	}
	cout << ans << " " << ans2 << endl;
	for(int i=1; i<=ans2; ++i){
		cout << cnt[i] << " ";
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
