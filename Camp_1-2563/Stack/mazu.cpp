#include<bits/stdc++.h>
using namespace std;

int main (){

	int n;
	scanf("%d", &n);
	stack<char>s;
	for(int i=0; i<n; ++i){
		char x;
		scanf(" %c", &x);
		if(s.empty()){
			s.push(x);
			continue;
		}
		if(s.top() == x){
			s.pop();
		}
		else{
			s.push(x);
		}
	}	
	printf("%d\n", s.size());
	if(s.size() == 0){
		printf("empty\n");
	}
	while(!s.empty()){
		printf("%c", s.top());
		s.pop();
	}
	return 0;
}
