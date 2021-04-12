/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * LANG		: C++
 * TASK		: Intro03
 * EDITOR	: VsCode
 * */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solution(){
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("Plus: %.2lf\n", a + b);
	printf("Minus: %.2lf\n", a - b);
	printf("Multiply: %.2lf\n", a * b);
	printf("Divide: %.2lf\n", a / b);
	printf("Modulo: %.2lf\n", fmod(a, b));
	printf("Power: %.2lf\n", pow(a, b));
	printf("Root: %.2lf\n", pow(a, 1 / b));
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
