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
	for(;n>=1000;n-=1000){
		cout << "M";
	}	
	for(;n>=900;n-=900){
		cout << "CM";
	}
	for(;n>=500;n-=500){
		cout << "D";
	}
	for(;n>=400;n-=400){
		cout << "CD";
	}
	for(;n>=100;n-=100){
		cout << "C";
	}
	for(;n>=90;n-=90){
		cout << "XC";
	}
	for(;n>=50;n-=50){
		cout << "L";
	}
	for(;n>=40;n-=40){
		cout << "XL";
	}
	for(;n>=10;n-=10){
		cout << "X";
	}
	for(;n>=9;n-=9){
		cout << "IX";
	}
	for(;n>=5;n-=5){
		cout << "V";
	}
	for(;n>=4;n-=4){
		cout << "IV";
	}
	for(;n>=1;n--){
		cout << "I";
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
		cout << endl;
	}
	return 0;
}
