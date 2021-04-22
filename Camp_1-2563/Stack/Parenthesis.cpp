#include<bits/stdc++.h>
using namespace std;

char s[200];

void solve(){
	stack<char>st;
	scanf(" %s", s);
	bool check = true;
	for(int i=0; i<strlen(s); ++i){
		char now = s[i];
		if(now == '(' || now == '[' || st.empty()){
			st.push(now);
		}
		else if(now == ')' && st.top() == '('){
		}
		else if(now == ']'){
			while(!st.empty() && st.top() != '['){
				st.pop();
			}
			if(st.empty()){
				printf("No");
				return ;
			}
			st.pop();
		}
	}
	if(st.empty()){
		printf("Yes");
	}
	else{
		printf("No");
	}
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
