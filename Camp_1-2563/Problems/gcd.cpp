#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, g;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x;
		if(x == 1){
			g = x;
		}
		else{
			g = __gcd(g, x);
		}
	}	
	cout << g << endl;
	return 0;
}
