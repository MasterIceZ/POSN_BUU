#include<bits/stdc++.h>
using namespace std;

char s[33];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	stack<int>opr;
	for(int i=0; i<n; ++i){
		cin >> s;
		char tmp = s[0];
		if(isdigit(tmp) || isdigit(s[1])){
			opr.push(atol(s));
		}
		else{
			if(opr.size() <= 1){
				cout << "No Solution" << endl;
				return 0;
			}
			int a, b;
			b = opr.top();
			opr.pop();
			a = opr.top();
			opr.pop();
			if(tmp == '*'){
				opr.push(a*b);
			}
			else if(tmp == '+'){
				opr.push(a+b);
			}
			else{
				opr.push(a-b);
			}
		}
	}
	if(opr.size() != 1){
		cout << "No Solution" << endl;
	}
	else{
		cout << opr.top() << endl;
	}
	return 0;
}
