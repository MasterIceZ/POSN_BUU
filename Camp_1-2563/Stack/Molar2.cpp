#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	stack<int>st;
	for(int i=0; i<s.size(); ++i){
		char now = s[i];
		if(now == '('){
			st.push(0);
		}
		else if(now == ')'){
			int sum = 0;
			while(!st.empty() && st.top() != 0){
				sum += st.top();
				st.pop();
			}
			st.pop();
			st.push(sum);
		}
		else if(isdigit(now)){
			int sum = st.top();
			st.pop();
			sum *= now - '0';
			st.push(sum);
		}
		else{
			if(now == 'C'){
				st.push(12);
			}
			else if(now == 'O'){
				st.push(16);
			}
			else{
				st.push(1);
			}
		}
	}
	int sum = 0;
	while(!st.empty()){
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return ;
}

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while(q--){
		solve();
		cout << "\n";
	}	

	return 0;
}
