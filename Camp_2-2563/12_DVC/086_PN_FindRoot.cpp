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

A start;
int k;

A divide(A now, int n){
	if(n == 1){
		return start;
	}
	A ans = divide(now, n/2);
	int one = ((ans.one * ans.one) % k +
				(ans.two * ans.two * 2) % k +
				(ans.three * ans.three * 3) % k)%k;
	int two = (2 * ans.one * ans.two)%k;
	int three = (2 * ans.one * ans.three)%k;
	int six = (2 * ans.two * ans.three)%k;
	if(n%2==0){
		return {one, two, three, six};
	}
	one = (one * now.one)%k;
	two = (two * now.two)%k;
	three = (three * now.three)%k;
	six = (six * now.six)%k;
	return {one, two, three, six};
}

void solve(){
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
