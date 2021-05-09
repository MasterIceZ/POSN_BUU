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
#define endl '\n'
using LL = long long;

int n, m;

void solve(){
//	cin >> n;
	scanf("%d", &n);
	double med = -1;
	priority_queue<double>pq1;
	priority_queue<double, vector<double>, greater<double>>pq2;
	for(int i=1; i<=n; ++i){
		double x;
//		cin >> x;
		scanf("%lf", &x);
		if(i == 1){
//			cout << dec(x, 1) << endl;
			printf("%.1lf\n", x);
			med = x;
			pq1.push(x);
		}
		else{
			if(pq1.size() > pq2.size()){
				if(x > med){
					pq2.push(x);
				}
				else{
					pq2.push(pq1.top());
					pq1.pop();
					pq1.push(x);
				}
				med = pq1.top() + pq2.top();
				med /= 2;
			}
			else if(pq1.size() == pq2.size()){
				if(x > med){
					pq2.push(x);
					med = pq2.top();
				}
				else{
					pq1.push(x);
					med = pq1.top();
				}
			}
			else{
				if(x > med){
					pq1.push(pq2.top());
					pq2.pop();
					pq2.push(x);
				}
				else{
					pq1.push(x);
				}
				med = pq1.top() + pq2.top();
				med /= 2;
			}
//			cout << dec(med, 1) << endl;
			printf("%.1lf\n", med);
		}
	}
	return ;
}

int32_t main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
