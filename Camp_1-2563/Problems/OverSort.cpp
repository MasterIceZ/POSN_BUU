#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int type, n;
	cin >> type >> n;
	if(type == 1){
		vector<int>v(n);
		for(auto& x: v){
			cin >> x;
		}
		sort(v.begin(), v.end());
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
		reverse(v.begin(), v.end());
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
	}
	else if(type == 2){
		vector<double>v(n);
		cout << setprecision(0) << fixed;
		for(auto &x: v){
			cin >> x;
		}	
		sort(v.begin(), v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
		reverse(v.begin(), v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
	}
	else if(type == 2){
		vector<char>v(n);
		for(auto &x: v){
			cin >> x;
		}	
		sort(v.begin(), v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
		reverse(v.begin(), v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
	}
	else{
		vector<string>v(n);
		for(auto &x: v){
			cin >> x;
		}	
		sort(v.begin(), v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
		reverse(v.begin(), v.end());
		for(auto x: v){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}
