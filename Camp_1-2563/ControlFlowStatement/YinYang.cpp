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
	for(int i=1; i<=1+n; ++i){
		for(int j=1; j<=2+n; ++j){
			if(i+j<=n+2){
				cout << ".";
			}
			else{
				cout << "#";
			}
		}
		for(int j=1; j<=2+n; ++j){
			if(i==1 || j==1 || j==n+2){
				cout << "+";
			}
			else{
				cout << "#";
			}
		}
		cout << endl;
	}
	for(int i=1;i<=2+n;++i){
		cout << "#";
	}	
	for(int i=1;i<=2+n;++i){
		cout << "+";
	}	
	cout << endl;
	for(int i=1;i<=2+n;++i){
		cout << "#";
	}	
	for(int i=1;i<=2+n;++i){
		cout << "+";
	}
	cout << endl;	
	for(int i=1; i<=n+1; ++i){
		for(int j=1; j<=2+n; ++j){
			if(j==1 || j == 2+n || i == n+1){
				cout << "#";
			}
			else{
				cout << "+";
			}
		}
		for(int j=1; j<=2+n; ++j){
			if(i+j <= n+2){
				cout << "+";
			}
			else{
				cout << ".";
			}
		}
		cout << endl;
	}
	
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
