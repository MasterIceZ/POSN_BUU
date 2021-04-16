#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, l;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x;
		if(i == 1){
			l = x; 
		}
		else{
			l = l * x / __gcd(l, x);
		}
	}
	cout << l << endl;
	return 0;
}
