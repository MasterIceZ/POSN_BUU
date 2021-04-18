#include<bits/stdc++.h>
using namespace std;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int nax = INT_MIN;
	int st=1, n, x, sum = 0, ans1 = 1, ans2 = 0;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x;
		sum += x;
		if(sum > nax){
			nax = sum;
			ans1 = st;
			ans2 = i;
		}
		if(sum < 0){
			sum = 0;
			st = i+1;
		}
	}	
	cout << ans1 << " " << ans2 << endl << nax << endl;
	return 0;
}
