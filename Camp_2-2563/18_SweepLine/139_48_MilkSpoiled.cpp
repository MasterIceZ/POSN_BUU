/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Milk Spoiled
 * ALGO		: Sweepline
 * DATE		: 18 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;
void init();
int n, m;

struct Time{
	int first, second;
	bool operator < (const Time& o) const{
		return first < o.first;
	}
};

void solve(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<Time>event;
	for(int i=0, a, b; i<n; ++i){
		cin >> a >> b;
		event.push_back({a, 1});
		event.push_back({b+1, -1});
	}
	event.push_back({0, 0});
	sort(all(event));
	int qs = 0, j, ans=-1;
	int cntx, cnty, cntz;
	cnty = cntz = 0;
	cntx = n;
	for(int i=1; i<(int)event.size(); i=j){
		for(j = i; j<event.size() && event[i].first==event[j].first; ++j){
			if(event[j].second == 1){
				cntx--, cnty++;
			}
			else{
				cnty--, cntz++;
			}
		}
		ans = max(ans, cntx * x + cnty * y + cntz * z);
	}
	cout << ans;
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
