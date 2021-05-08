/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PN_Median
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define int long long
using LL = long long;

int n, m;

void solve(){
	int x;
	double med = 0;
	scanf("%lld", &n);
	priority_queue<int>more;
	priority_queue<int, vector<int>, greater<int>>small;
	scanf("%lld", &x);
	med = (double)x;
	printf("%.1lf\n", med);
	more.push(x);
	for(int i=1; i<n; ++i){
		scanf("%lld", &x);
		if(more.size() > small.size()){
			if(x > med){
				small.push(x);
			}
			else{
				small.push(more.top());
				more.pop();
				more.push(x);
			}
			med = (double)(more.top()+small.top())/2;
		}
		else if(more.size() == small.size()){
			if(x < med){
				more.push(x);
				med = (double) more.top();
			}
			else{
				small.push(x);
				med = (double) small.top();
			}
		}
		else{
			if(x > med){
				more.push(small.top());
				small.pop();
				small.push(x);
			}
			else{
				more.push(x);
			}
			med = (double)(more.top()+small.top())/2;
		}
		printf("%.1lf\n", med);
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
//		cout << endl;
	}
	return 0;
}
