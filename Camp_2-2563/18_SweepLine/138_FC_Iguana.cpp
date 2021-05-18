/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: FC_Iguana
 * ALGO		: Sweepline
 * DATE		: 17 May 2021
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

int dp[10100];

void sol50(){
	cin >> n >> m;
	for(int i=0; i<m; ++i){
		int a, b;
		cin >> a >> b;
		dp[a]++, dp[b+1]--;
	}
	char s;
	cin >> s;
	int opr = -1;
	if(s == 'R'){
		opr = 0;
	}
	else if(s == 'G'){
		opr = 1;
	}
	else{
		opr = 2;
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		dp[i] += dp[i-1];
		dp[i] = (dp[i]+3)%3;
		if(dp[i] != opr){
			cnt += (opr + 3 - dp[i]) % 3;
//			cout << "idx : " << i << endl << "cnt : " << cnt << endl; 
		}
	}
//	for(int i=1; i<=n+1; ++i){
//		cout << dp[i] << " " ;
//	}
//	cout << endl;
	cout << cnt;
	return ;
}

void sol70(){
	cin >> n >> m;
	vector<pair<int, int>>event;
	for(int i=0, a, b; i<m; ++i){
		cin >> a >> b;
		event.emplace_back(a, 1);
		event.emplace_back(b+1, -1);
	}
	event.emplace_back(1, 0);
	event.emplace_back(n+1, 0);
	sort(all(event));
	char s;
	int opr;
	cin >> s;
	if(s == 'R'){
		opr = 0;
	}
	else if(s == 'G'){
		opr = 1;
	}
	else if(s == 'B'){
		opr = 2;
	}
	int qs = 0, ans = 0;
	for(int i=0; i<event.size()-1; ++i){
		qs += event[i].second;
		int amt = event[i+1].first - event[i].first;
		int x = qs % 3;
		ans += ((opr + 3 - x)%3) * amt;
	}
	cout << ans;
	return ;
}

void solve(){
	cin >> n >> m;
	map<int, int> line;
	for(int i=0, a, b; i<m; ++i){
		cin >> a >> b;
		line[a]++, line[b]--;
	}
	char type;
	cin >> type;
	int exp;
	switch(type){
		case 'R' :
			exp = 0;
			break;
		case 'G' :
			exp = 1;
			break;
		case 'B' :
			exp = 2;
			break;
	}
	for(auto x: line){
		if((x.second + 3)%3){
			cout << "Hello";
		}
	}
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
//		solve();
//		sol50();
		sol70();
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
