#include<bits/stdc++.h>
using namespace std;

#define int long long

char b[1001];

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cout << fixed << setprecision(0);
	cin >> n >> k;
	sprintf(b, "%.0lf", n/pow(10, k));
	cout << atoi(b)*pow(10, k);	

	return 0;
}
