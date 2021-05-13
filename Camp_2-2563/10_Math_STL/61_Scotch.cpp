/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Scotch
 * ALGO		: Math
 * DATE		: 12 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(x) x*x
ll ca[2], cb[2], cab[2][2];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	ll n,a,b,aa,bb;
	cin >> n >> a >> b;
	aa=2*a, bb=2*b;
	for(int i=0; i<n; ++i) {
		if(i%aa<a) {
			if(i%bb<b) ++ca[0], ++cb[0], ++cab[0][0];
			else ++ca[0], ++cb[1], ++cab[0][1];
		}
		else {
			if(i%bb<b) ++ca[1], ++cb[0], ++cab[1][0];
			else ++ca[1], ++cb[1], ++cab[1][1];
		}
	}
	ll sum=0ll;
	for(int i=0; i<2; ++i)
		sum += f(ca[i])+f(cb[i]);
	for(int i=0; i<4; ++i)
		sum -= f(cab[i/2][i%2]);
	cout << sum << "\n";
	return 0;
}
