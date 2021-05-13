/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Tarn Sequence
 * ALGO		: Dynamic Programming
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
int dp[100100];
vector<int> v[100100], ans;

void solve(){
	cin >> n;
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		int num;
		cin >> num;
		int idx = upper_bound(dp, dp+cnt, num) - dp;
		if(idx-1 >= 0 && dp[idx-1] == num){
			continue;
		}
		if(idx == cnt){
			cnt++;
		}
		dp[idx] = num;
		v[idx].push_back(num);
	}
	cout << cnt << endl;
	int num = v[cnt-1][0];
	ans.push_back(num);
	for(int i=cnt-2; i>=0; --i){
		for(auto x: v[i]){
			if(x < num){
				num = x;
				ans.push_back(num);
				break;
			}
		}
	}
	for(int i=cnt-1; i>=0; --i){
		cout << ans[i] << " ";
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
