/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * TASK		: Roman Con2
 * ALGO		: Hash
 * DATE		: 22 Mar 2022
 * */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
// @==== Libary ====@ //

// @================@ //

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

char a[55];
int conv[1010], pref[1010];

inline void solution(){
	cin >> (a + 1);
	int len = strlen(a + 1);
	int answer = 0;
	for(int i=1; i <= len; ++i){
		if(a[i + 1] != '\0' && pref[(a[i] - 'A') * 26 + (a[i + 1] - 'A')]){
			answer += pref[(a[i] - 'A') * 26 + (a[i + 1] - 'A')];
			i++;
		}
		else{
			answer += conv[a[i]];
		}
		dbg(answer);
	}
	cout << answer;
	return ;
}

signed main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);	
	
	// initial
	conv['M'] = 1000;
	conv['C'] = 100;
	conv['D'] = 500;
	conv['L'] = 50;
	conv['X'] = 10;
	conv['V'] = 5;
	conv['I'] = 1;
	
	// prefix
	pref[('C' - 'A') * 26 + ('M' - 'A')] = 900;
	pref[('C' - 'A') * 26 + ('D' - 'A')] = 400;
	pref[('X' - 'A') * 26 + ('C' - 'A')] = 90;
	pref[('X' - 'A') * 26 + ('L' - 'A')] = 40;
	pref[('I' - 'A') * 26 + ('X' - 'A')] = 9;
	pref[('I' - 'A') * 26 + ('V' - 'A')] = 4;
	
	int q = 1;
	cin >> q;
	while(q--){
		solution();
		cout << "\n";
	}
	return 0;
}
// https://github.com/MasterIceZ/archive/tree/main/cpp-template
