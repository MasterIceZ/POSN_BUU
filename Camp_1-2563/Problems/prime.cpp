#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int nax = 7500000;

bool mark[nax];

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	if(n == 1){
		cout << 2 << endl;
		return 0;
	}
	for(int i=3; i<nax; i+=2){
		mark[i] = true;
	}
	for(int i=3; i*i <= nax; i+=2){
		if(mark[i]){
			for(int j=i*i; j<nax; j+=i){
				mark[j] = false;
			}
		}
	}
	int cnt = 0;
	for(int i=3; i<nax; i+=2){
		if(mark[i]){
			cnt++;
			if(cnt+1 == n){
				cout << i << endl;
				return 0;
			}
		}
	}
	return 0;
}
