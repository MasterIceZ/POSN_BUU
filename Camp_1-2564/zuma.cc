#include <iostream>

using namespace std;

const int MxN = 333;
int dp[MxN][MxN];
char a[MxN];

int divide(int l, int r){
	if(l == r + 1 && a[l] == a[r]){
		return dp[l][r] = 2;
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	int answer = 0;
	for(int x=l+1; x<=r; ++x){
		answer = max(answer, divide(l, x) + divide(x + 1, r));
	}
	return dp[l][r] = answer;
}

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	cout << divide(1, n);
	return 0;
}
