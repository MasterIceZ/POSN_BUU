#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

bool isPrime(int n){
	if(n <= 1){
		return false;
	}
	if(n <= 3){
		return true;
	}
	if(n%2==0 || n%3==0){
		return false;
	}
	for(int i=5; i*i<=n; i+=6){
		if(n%i==0 || n%(i+2)==0){
			return false;
		}
	}
	return true;
}

int32_t main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int q;
	cin >> q;
	while(q--){
		int n;
		vector<int>v;
		cin >> n;
		if(n == 1 || isPrime(n)){
			cout << n << endl;
			continue;
		}
		while(n%2==0){
			v.push_back(2);
			n /= 2;
		}
		for(int i=3; i*i<=n; i+=2){
			while(n%i==0){
				v.push_back(i);
				n /= i;
			}
		}
		if(n>2){
			v.push_back(n);
		}
		for(int i=0; i<v.size(); ++i){
			if(i == 0){
				cout << v[i];
			}
			else{
				cout << " x " << v[i];
			}
		}
		cout << endl;
	}

	return 0;
}
