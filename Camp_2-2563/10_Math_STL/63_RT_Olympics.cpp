/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: RT_Olympics
 * ALGO		: Math
 * DATE		: 12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;

int n, m;

bool ch;
int a[33], mark[66], p;

void rec(int st, int fin){
	if(ch == 1){
		return ;
	}
	if(st == m + 1){
		ch = true;
		return ;
	}
	if(st == m){
		if(mark[n] == 1){
			return ;
		}
		a[st] = n;
		mark[a[st] + p] = 1;
		rec(st+1, n);
		mark[a[st] + p] = 0;
		return ;
	}
	for(int i = fin+1; i<=n-(m-st); ++i){
		if(mark[i] == 1){
			continue;
		}
		a[st] = i;
		mark[a[st] + p] = 1;
		rec(st+1, i);
		mark[a[st] + p] = 0;
		if(ch == 1){
			return ;
		}
	}

}

void solve(){
	cin >> n >> m >> p;
	memset(a, 0, sizeof a);
	memset(mark, 0, sizeof mark);
	mark[p] = 1;
	ch = 0;
	rec(1, 0);
	if(ch == 1){
		cout << "no";
	}	
	else{
		cout << "yes";
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
