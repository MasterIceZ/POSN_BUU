#include<bits/stdc++.h>
using namespace std;

char s[111];

void solve(){
	int sum;
	scanf(" %s", s);
	stack<int>st;
	for(int i=0; i<strlen(s); ++i){
		char now = s[i];
		if(now == '('){
			st.push(0);
		}
		else if(now == ')'){
			sum = 0;
			while(!st.empty() && st.top() != 0){
				sum += st.top();
				st.pop();
			}
			st.pop();
			st.push(sum);
		}
		else if(isalpha(now)){
			if(now == 'H'){
				st.push(1);
			}
			else if(now == 'C'){
				st.push(12);
			}
			else{
				st.push(16);
			}
		}
		else{
			sum = st.top();
			st.pop();
			st.push(sum*(now-'0'));
		}
	}
	sum = 0;
	while(!st.empty()){
		sum += st.top();
		st.pop();
	}
	printf("%d", sum);
	return ;
}

int main (){
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
		printf("\n");
		memset(s, '\0', sizeof s);
	}
	return 0;
}
