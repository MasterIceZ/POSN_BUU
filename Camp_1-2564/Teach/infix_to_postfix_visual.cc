#include <bits/stdc++.h>
using namespace std;

inline bool isOperator(char s){
	if(s == '+' || s == '-' || s == '*' || s == '/'){
		return true;
	}
	return false;
}

vector<string> read_string(string s){
	vector<string> res;
	for(auto x: s){
		if(isOperator(x)){
			tmp.push_back();
		}
	}
	return res;
}

int main(){
	string tmp;
	cin >> tmp;
	vector<string> v = read_string(tmp);
	for(auto x: v){
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}
