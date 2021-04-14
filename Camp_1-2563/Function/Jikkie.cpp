#include<bits/stdc++.h>
using namespace std;

int A, B, C;
bool answer[33], mark[33][33][33];

void rec(int a, int b, int c){
	if(a<0 || b<0 || c<0 || a>A || b>B || c>C){
		return ;
	}
	if(a == 0){
		answer[c] = true;
	}
	if(mark[a][b][c]){
		return ;
	}
	mark[a][b][c] = true;
	rec(0, b+a, c);
	rec(a-B+b, B, c);
	rec(0, b, a+c);
	rec(a-C+c, b, C);
	rec(a+b, 0, c);
	rec(A, b-A+a, c);
	rec(a, 0, b+c);
	rec(a, b-C+c, C);
	rec(a+c, b, 0);
	rec(A, b, c-A+a);
	rec(a, b+c, 0);
	rec(a, B, c-B+b);

	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B >> C;
	rec(0, 0, C);
	for(int i=0; i<=C; ++i){
		if(answer[i] == 1){
			cout << i << " ";
		}
	}

	return 0;
}
