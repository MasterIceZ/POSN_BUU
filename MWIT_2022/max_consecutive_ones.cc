#include <bits/stdc++.h>
using namespace std;

int cnt, answer, k;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	string s;
	cin >> s >> k;
	int n = (int) s.size();
	s = " " + s;
	int l = 1;
	for(int i=1; i<=n; ++i){
		if(s[i] == '0'){
			cnt++;
		}
		while(cnt > k){
			if(s[l] == '0'){
				cnt--;
			}
			l++;
		}
		answer = max(answer, i - l + 1);
	}
	cout << answer << "\n";
	return 0;
}
