#include<bits/stdc++.h>
using namespace std;

int pri(char s){
	if(s=='^'){
		return 3;
	}
	if(s=='*' || s=='/'){
		return 2;
	}
	return 1;
}

char s[1010];

// run
int main(){
	cin >> s;
	stack<char>opr;
	string ans;
	for(int i=0; i<strlen(s); ++i){
		char now = s[i];
		if(isalpha(now) || isdigit(now)){
			ans += now;
			continue;
		}
		if(now == '(' || opr.empty()){
			opr.push(now);
		}
		else if(now == ')'){
			while(!opr.empty() && opr.top() != '('){
				ans += opr.top();
				opr.pop();
			}
			opr.pop();
		}
		else{
			while(!opr.empty() && pri(opr.top()) >= pri(now) && opr.top() != '('){
				ans += opr.top();
				opr.pop();
			}
			opr.push(now);
		}
	}
	while(!opr.empty()){
		ans += opr.top();
		opr.pop();
	}
	cout << ans << endl;

	return 0;
}
