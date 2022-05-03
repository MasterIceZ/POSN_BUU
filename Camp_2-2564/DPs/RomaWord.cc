/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Romaword
 * ALGO		:
 * DATE		:
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#ifndef _DEBUG
// @==== Libary ====@ //

// @================@ //
#endif

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

// @=== Debugger ===@ //
#ifdef _DEBUG
#include "debug.hpp"
#else
#define dbg(...) 0
#endif
// @================@ //

using ll = long long;

int dp[2021][2021], pth[2021][2021];

inline void solution(){
	string a, b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	a = " " + a, b = " " + b;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(a[i] == b[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				pth[i][j] = 1;
			}
			else if(dp[i - 1][j] >= dp[i][j - 1]){
				dp[i][j] = dp[i - 1][j];
				pth[i][j] = 2;
			}
			else{
				dp[i][j] = dp[i][j - 1];
				pth[i][j] = 3;
			}
		}
	}
	cout << dp[n][m] << "\n";
	int i = n, j = m;
	if(dp[i][j] == 0){
		cout << "No Roma word";
		return ;
	}
	vector<char> answer;
	while(i > 0 && j > 0){
		if(pth[i][j] == 1){
			answer.emplace_back(a[i]);
			i--, j--;
		}
		else if(pth[i][j] == 2){
			i--;
		}
		else{
			j--;
		}
	}
	reverse(answer.begin(), answer.end());
	for(auto x: answer){
		cout << x;
	}
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	int q = 1;
//	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
