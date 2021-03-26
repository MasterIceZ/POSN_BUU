#include<bits/stdc++.h>
using namespace std;

char s[111];

struct PAIR{
	int x=0, y=0;
};

PAIR pos;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	int len = strlen(s);
	for(int i=0;i<len;++i){
		if(s[i] == 'Z'){
			pos.x = pos.y = 0;
		}
		else if(s[i] == 'N'){
			pos.y++;
		}
		else if(s[i] == 'S'){
			pos.y--;
		}
		else if(s[i] == 'E'){
			pos.x++;
		}
		else{
			pos.x--;
		}
	}
	cout << pos.x << " " << pos.y;

	return 0;
}
