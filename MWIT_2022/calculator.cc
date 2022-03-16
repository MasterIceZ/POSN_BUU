#include <bits/stdc++.h>
using namespace std;

inline int pri(string s){
	if(s == "/" || s== "*"){
		return 3;
	}
	if(s == "+" || s == "-"){
		return 2;
	}
	return 1;
}

inline vector<string> intopost(vector<string> s){
	vector<string> res;
	stack<string> st;
	for(auto x: s){
		if(isdigit(x[0])){
			res.push_back(x);
			continue;
		}
		if(x == "(" || st.empty()){
			st.push(x);
		}
		else if(x == ")"){
			while(!st.empty() && st.top() != "("){
				res.push_back(x);
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && st.top() != "(" && pri(st.top()) >= pri(x)){
				res.push_back(st.top());
				st.pop();
			}
			st.push(x);
		}
	}
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
	}
	return res;
}

inline double calc(vector<string> v){
	stack<double> st;
	for(auto x: v){
		if(isdigit(x[0])){
			st.push(stold(x));
			continue;
		}
		double a = st.top();
		st.pop();
		double b = st.top();
		st.pop();
		if(x == "+"){
			st.push(a + b);
		}
		else if(x == "-"){
			st.push(a - b);
		}
		else if(x == "*"){
			st.push(a * b);
		}
		else{
			st.push(a / b);
		}
	}
	return st.top();
}

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	string s, tmp = "";
	cin >> s;
	vector<string> v;
	for(auto x: s){
		if(isdigit(x) || x == '.'){
			tmp += string(1, x);
		}
		else{
			if(tmp.size()){
				v.push_back(tmp);
				tmp = "";
			}
			v.push_back(string(1, x));
		}
	}
	if(tmp.size()){
		v.push_back(tmp);
	}
	for(auto x: v){
		cout << "[x] : " << x << "\n";
	}
	vector<string> postfix = intopost(v);	
	for(auto x: postfix){
		cout << x << "\n";
	}
	cout << fixed << setprecision(3) << calc(postfix) << "\n";
	return 0;
}
