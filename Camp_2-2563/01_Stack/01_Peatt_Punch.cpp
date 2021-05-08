/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Peatt Punch
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;

int n, m;
int a[100100];

void solve(){
	stack<pair<int, int>>st;
	int l, q, i, h, power;
	scanf("%d %d", &l, &q);
	for(int i=0; i<l; ++i){
		scanf("%d", &h);
		while(!st.empty() && st.top().first >= h){
			st.pop();
		}
		if(st.empty()){
			power = 0;
		}
		else{
			power = max(st.top().second, h-st.top().first);
		}
		a[i] = power;
		st.push(make_pair(h, power));
	}
	sort(a, a+l);
	while(q--){
		scanf("%d", &h);
		printf("%d\n", l - (upper_bound(a, a+l, h)-a));
	}
	return ;
}

int32_t main(){
//	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
//		cout << endl;
	}
	return 0;
}
