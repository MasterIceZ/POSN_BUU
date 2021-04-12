/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	int n;
	cin >> n;
	for(int i=1; i<=n-1; ++i){
		for(int j=1; j<=n; ++j){
			if(j<=i){
				cout << "*";
			}
			else{
				cout << "-";
			}
		}
		for(int j=1; j<n; ++j){
			if(i+j>=n){
				cout<< "*";
			}
			else{
				cout << "-";
			}
		}
		cout << endl;
	}
	for(int i=1; i<2*n; ++i){
		cout << "*";
	}
	cout << endl;
	for(int i=1; i<=n-1; ++i){
		for(int j=1; j<=n; ++j){
			if(i+j>=n+1){
				cout << "-";
			}
			else{
				cout << "*";
			}
		}
		for(int j=1; j<n; ++j){
			if(i<=j){
				cout << "*";
			}
			else{
				cout << "-";
			}
		}
		cout << endl;
	}	
	cout << endl;
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
