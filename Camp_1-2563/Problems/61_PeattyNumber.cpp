#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	string s;
	cin >> s;
	vector<int>v;
	bool ch = false;
	for(int i=s.size()-1; i-3>=0; i-=3){
		int num = s[i] - '0';
		num += (s[i-1] - '0')* 10;
		num += (s[i-2] - '0')* 100;
//		cout << num << " ";
		v.push_back(num);
	}
	int k = 0, tmp = s.size() % 3;
	if(tmp == 1){
		k = s[0] - '0';
	}
	else if(tmp == 2){
		k = (s[0] - '0') * 10 + s[1] - '0';
	}
	else if(tmp == 0){
		k = (s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');
	}
	if(k!=0){
		v.push_back(k);
	}
//	Check 7;
	for(int i=0;i <v.size(); ++i){
		if(i%2 == 1){
			v[i] *= -1;
		}
	}
	int sum = 0;
	for(auto x : v){
		sum += x;
//		cout << x << endl;
	}
	if(sum % 7 == 0){
		ch = true;
		cout << "7 * " << sum/7 << endl;
	}
	sum = 0;
	tmp = (s.size()-1)%2;
	for(int i=s.size()-1; i>=0; --i){
		if(tmp != i%2){
			sum -= s[i] - '0';
		}
		else{
			sum += s[i] - '0';
		}
	}
//	cout << sum;
	if(sum % 11 == 0){
		ch = true;
		cout << "11 * " << sum/11 << endl;
	}
	sum = 0;
	for(int i=s.size()-1; i-2>=0; i-=2){
		int num = (s[i-1]-'0')*10;
		num += s[i] - '0';
//		cout << num << endl;
		sum += num;
	}
	if(s.size()%2==1){
		sum += s[0] - '0';
	}
	else if(s.size()%2==0){
		sum += (s[0] - '0') * 10 + s[1] - '0';
	}
//	cout << sum << endl;
	if(sum % 99 == 0){
		ch = 1;
		cout << "99 * " << sum/99 << endl;
	}
	if(!ch){
		cout << s << endl;
	}
	return ;
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}
