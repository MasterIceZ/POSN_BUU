#include<bits/stdc++.h>
using namespace std;

int n;

void rec(int state){
	for(int i=1; i<=n; ++i){
		if(i == state){
			cout << "01";
		}
		else if(i < state){
			cout << "00"; 
		}
		else{
			cout << "11";
		}
		cout << " ";
	}
	cout << endl;
	for(int i=1; i<=n; ++i){
		if(i == state){
			cout << "10";
		}
		else if(i < state){
			cout << "00"; 
		}
		else{
			cout << "11";
		}
		cout << " ";
	}
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for(int i=n; i>=1; --i){
		rec(i);
		cout << endl;
	}

	return 0;
}
