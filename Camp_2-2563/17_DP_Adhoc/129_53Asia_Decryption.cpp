/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 53Asia_Decryption
 * ALGO		: Dynamic Programming
 * DATE		: 18 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;

char key[111], s[100100];
map<char, vector<int>>mp;

void solve(){
	scanf(" %s", key+1);	
	scanf(" %s", s+1);
	int len = strlen(s+1);
	for(int i=1; i<=len; ++i){
		mp[s[i]].push_back(i);
	}
	char start = key[1];
	
	return ;
}

int32_t main(){
//	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
//		cout << endl;
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
