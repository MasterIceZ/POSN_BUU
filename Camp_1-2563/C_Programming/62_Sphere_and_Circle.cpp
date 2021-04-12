/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: Template
 * EDITOR	: gVim
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	double r;
	scanf("%lf", &r);
	printf("%.3lf\n", acos(-1)*r*r*4);
	printf("%.3lf\n", acos(-1)*r*r*r*4/3);
	printf("%.3lf\n", acos(-1)*r*r);
	printf("%.3lf", acos(-1)*2*r);
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
