/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: 
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	if(a == 0){
		printf("%.2lf",sqrt(pow(c,2) - pow(b,2)));
	}
	else if(b == 0){
		printf("%.2lf",sqrt(pow(c,2) - pow(a,2)));
	}
	else{
		printf("%.2lf",sqrt(pow(a,2)+pow(b,2)));
		
	}
	return ;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
//	cin >> t;
	for(int i=1; i<=t; ++i){
//		cout << "Case #" << i << ": ";
		solution();
//		cout << endl;
	}
	return 0;
}
