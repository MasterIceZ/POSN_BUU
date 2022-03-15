#include <bits/stdc++.h>
using namespace std;

int a[5], b[5], c[5], visited[33][33][33];
bool answer[33];

const int HSH = 193;

inline int encrypt(int a, int b, int c){
	return a * HSH * HSH  + b * HSH + c;	
}

inline void decrypt(int v){
	b[0] = ((v / HSH) / HSH) % HSH;
	b[1] = ((v / HSH) % HSH) % HSH;
	b[2] = (v % HSH) % HSH;
	return ;
}

inline bool check(){
	for(int i=0; i<3; ++i){
		if(b[i] < 0 || b[i] > a[i]){
			return false;
		}
	}
	return true;
}

void rec(int cur){
	decrypt(cur);
	if(!check()){
		return ;
	}
	if(b[0] == 0){
		answer[b[2]] = true;
	}
	if(visited[b[0]][b[1]][b[2]]){
		return ;
	}
	visited[b[0]][b[1]][b[2]] = true;
//	cerr << "[X] : " << b[0] << " " << b[1] << " " << b[2] << "\n";
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(i == j){
				continue;
			}
			c[i] = 0;
			c[j] = b[i] + b[j];
			c[3 - i - j] = b[(3 - i - j)];
			cerr << "[A] : " << c[0] << " " << c[1] << " " << c[2] << "\n";
			cerr << "[I] : " << i << " " << j << "\n";
			rec(encrypt(c[0], c[1], c[2]));
			decrypt(cur);
			c[i] = b[i] - a[j] + b[j];
			c[j] = a[j];
			c[3 - i - j] = b[3 - i - j];
			cerr << "[A] : " << c[0] << " " << c[1] << " " << c[2] << "\n";
			cerr << "[I] : " << i << " " << j << "\n";
			rec(encrypt(c[0], c[1], c[2]));
		}
	}
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cin >> a[0] >> a[1] >> a[2];
	rec(encrypt(0, 0, a[2]));
	for(int i=0; i<=a[2]; ++i){
		if(answer[i]){
			cout << i << " ";
		}
	}
	return 0;
}
