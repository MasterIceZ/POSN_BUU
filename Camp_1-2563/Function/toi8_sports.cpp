#include<bits/stdc++.h>
using namespace std;

int con;

void rec(int len, int win, int lose, char ans[]){
	if(lose == con || win == con){
		for(int i=0; i<len; ++i){
			cout << ans[i] << " ";
		}
		cout << endl;
		return ;
	}
	ans[len] = 'W';
	rec(len+1, win+1, lose, ans);
	ans[len] = 'L';
	rec(len+1, win, lose+1, ans);
	return ;
}

int main (){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char ans[1111];
	memset(ans, '\0', sizeof ans);
	int win, lose;
	cin >> con >> win >> lose;
	rec(0, win, lose, ans);

	return 0;
}
