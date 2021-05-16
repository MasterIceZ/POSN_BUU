/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_FindRoot
 * ALGO		: Divide and Conquer
 * DATE		: 15 May 2021
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

struct A{
	int one, two, three, six=0;
};
int k;
A mul(A a, A b){
	A tmp;
	tmp.one = ((6 * a.six * b.six)%k + (3 * a.three * b.three)%k + (2 * a.two * b.two)%k + (a.one * b.one)%k)%k;
	tmp.two = ((3 * a.three * b.six)%k + (3 * a.six * b.three)%k + (a.one * b.two)%k + (a.two * b.one))%k;
	tmp.three = ((2 * a.two * b.six)%k + (a.one * b.three)%k + (2 * a.six * b.two) +(a.three * b.one))%k;
	tmp.six = ((a.one * b.six)%k + (a.two * b.three)%k + (a.three * b.two)%k + (b.two * a.six)%k)%k;
	return tmp;
}

A divide(A a, int n){
	if(n == 0){
		return {1, 0, 0, 0};
	}
	A tmp = divide(a, n/2);
	A t = mul(tmp, tmp);
	if(n % 2 == 1){
		t = mul(t, a);
	}
	return t;
}

void solve(){
	A start;
	cin >> start.one >> start.two >> start.three >> n >> k;
	start.one %= k, start.two %= k, start.three %= k;
   	A ans = divide(start, n);
	cout << ans.one << " " << ans.two << " " << ans.three << " " << ans.six;
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
