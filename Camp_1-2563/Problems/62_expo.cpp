#include<bits/stdc++.h>
using namespace std;

int c[10010] = {1};

void solve(){
	int a, n;
	cin >> a >> n;
	if(n == 0){
		cout << 1 ;
		return ;
	}
	c[0] = 1; 
	int len = 1;
	for(int i=0; i<n; ++i){
		int tod = 0;
		for(int j=0; j<len; ++j){
			c[j] = c[j]*a + tod;
			if(c[j]>=10){
				tod = c[j] / 10;
				c[j] %= 10;
			}
			else{
				tod = 0;
			}
		}
		if(tod){
			c[len] = tod;
			len++;
		}
	}
	for(int i=len-1; i>=0; --i){
		cout << c[i];
	}
	memset(c, 0, sizeof c);
	return ;
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--){
		solve();
		cout << endl;	
	}

	return 0;
}
