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

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<char>opr;
	for(int i=0; i<n; ++i){
		string a;
		cin >> a;
		char tmp = a[0];
		if(isdigit(a[0])){
			cout << a << " ";
		}
		else{
			if(tmp == '(' || opr.empty()){
				opr.push(a[0]);
			}
			else if(tmp == ')'){
				while(opr.top()!='('){
					cout << opr.top() << " ";
					opr.pop();
				}
				opr.pop();
			}
			else{
				while(!opr.empty() && opr.top() != '(' && pri(opr.top()) >= pri(tmp)){
					cout << opr.top() << " ";
					opr.pop();
				}
				opr.push(tmp);
			}
		}
	}
	while(!opr.empty()){
		cout << opr.top() << " ";
		opr.pop();
	}
	cout << endl;
	return 0;
}
