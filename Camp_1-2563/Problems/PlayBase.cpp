#include<bits/stdc++.h>
using namespace std;

int32_t main (){
	string b, c, a;
	int x, numb, numc;
	numb = numc = 0;
	cin >> x >> b >> c;
	int len = b.size();
	for(int i=0; i<len; ++i){
		numb *= x;
		if(isdigit(b[i])){
			numb += b[i] - '0';
		}
		else{
			numb += b[i]-'A'+10;
		}
	}
	len = c.size();
	for(int i=0; i<len; ++i){
		numc *= x;
		if(isdigit(c[i])){
			numc += c[i] - '0';
		}
		else{
			numc += c[i]-'A'+10;
		}
	}
	cout << numb + numc << endl;
	int sum = numb + numc;
	int i = 0, now;
	while(sum != 0){
		now = sum%x;
		if(now < 10){
			a.push_back(now+'0');
		}
		else{
			a.push_back(now-10+'A');
		}
		sum /= x;
		i+=1;
	}
	reverse(a.begin(), a.end());
	cout << a << endl;
	return 0;
}
