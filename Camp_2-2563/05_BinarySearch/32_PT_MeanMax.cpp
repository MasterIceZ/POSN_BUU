/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: PT_Mean Max
 * ALGO		: Binary Search
 * DATE		: 12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
using LL = long long;

int n, m;
double a[300100], qs[300100], nin[300100];

void solve(){
	int k;
//	cin >> n >> k;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i){
//		cin >> a[i];
		scanf("%lf", &a[i]);
	}	
	double l=0, r=1e6, mid;
	bool ch;
	while((r-l) > 1e-6){
		ch = false;
		mid = (l + r + (1e-6))/2;
		for(int i=1; i<=n; ++i){
			qs[i] = a[i] - mid + qs[i-1];
			nin[i] = min(qs[i], nin[i-1]);
			if(i>=k && qs[i]-nin[i-k]>=0){
				ch = true;
				break;
			}
		}
		if(ch){
			l = mid;
		}
		else{
			r = mid-(1e-6);
		}
	}
	printf("%.1lf", r);
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
