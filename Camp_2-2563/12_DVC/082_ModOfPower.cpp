/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Mod of Power
 * ALGO		: Divide and Conquer
 * DATE		: 13 May 2021
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

LL modofpower(LL a, LL b, LL c){
	if(b==1){
		return a%c;
	}
	LL t = modofpower(a, b/2, c);
	if(b%2==0){
		return ((t%c)*(t%c))%c;
	}
	return ((t%c)*(t%c)*(a%c))%c;
}

void solve(){
	LL a, b, c;
	cin >> a >> b >> c;
	cout << modofpower(a, b, c);
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
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
