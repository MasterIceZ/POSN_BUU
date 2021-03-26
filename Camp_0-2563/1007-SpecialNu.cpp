#include<bits/stdc++.h>
using namespace std;

char a[111];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 5;
	while(t--){
		int s = 0;
		cin >> a;
		int len = strlen(a);
		for(int i=1;i<=len;++i){
			s += pow(a[i-1] - '0', i);
		}	
		cout << (s==atoi(a)?"Y":"N");
	}
	return 0;
}
