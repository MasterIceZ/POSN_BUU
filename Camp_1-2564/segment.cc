/*
 * AUTHOR	: YuKi Onna~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: toi2_seqment
 * EDITOR	: neo-vim
 * */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int num(int n){
	string s[5];
	getline(cin, s[0]);
	getline(cin, s[1]);
	getline(cin, s[2]);
//	for(int i=0; i<s[0].size(); ++i){
//		cout << s[0][i];
//	}
//	cout << endl;	
//	for(int i=0; i<s[1].size(); ++i){
//		cout << s[1][i];
//	}
//	cout << endl;
//	for(int i=0; i<s[2].size(); ++i){
//		cout << s[2][i];
//	}
	int sum = 0;
	for(int i=0; i<n*4; i+=4){
		sum *= 10;
		if(s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
		&& s[1][i] == '|' && s[1][i+1] == ' ' && s[1][i+2] == '|'
		&& s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 0;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == ' ' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == ' ' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == ' ' && s[2][i+2] == '|'){
			sum += 1;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == ' '){
			sum += 2;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 3;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == ' ' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == ' ' && s[2][i+2] == '|'){
			sum += 4;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == ' '
				&&	s[2][i] == ' ' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 5;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == ' '
				&&	s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 6;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == ' ' && s[1][i+1] == ' ' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == ' ' && s[2][i+2] == '|'){
			sum += 7;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == '|' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 8;
		}
		else if(	s[0][i] == ' ' && s[0][i+1] == '_' && s[0][i+2] == ' '
				&&	s[1][i] == '|' && s[1][i+1] == '_' && s[1][i+2] == '|'
				&&	s[2][i] == ' ' && s[2][i+1] == '_' && s[2][i+2] == '|'){
			sum += 9;
		}
	}
	return sum;
}
void solution(){
	int n, m;
	string t;
	getline(cin, t);
	stringstream ss(t);
	ss >> n >> m;
	int x = num(n);
	int y = num(m);	
	cout << x+y << endl;
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

