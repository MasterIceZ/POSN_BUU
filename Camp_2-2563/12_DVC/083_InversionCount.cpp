/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Inversion Count
 * ALGO		: Divide and Conquer
 * DATE		: 13 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#define dec(x,y) fixed << setprecision(y) << x   
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define int long long
using LL = long long;
void init();
int n, m;
int a[100100], b[100100];
int cnt = 0;

void mergesort(int l ,int r){
	if(l == r){
		return ;
	}
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);
	int i=l, j=mid+1, k=l;
	while(i<=mid && j <=r){
		if(a[i] <= a[j]){
			b[k++] = a[i++];
		}
		else{
			b[k++] = a[j++];
			cnt += mid + 1 - i;
		}
	}
	while(i<=mid){
		b[k++] = a[i++];
	}
	while(j<=r){
		b[k++] = a[j++];
	}
	for(int i=l; i<=r; ++i){
		a[i] = b[i];
	}
	return ;
}

void solve(){
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> a[i];
	}
	mergesort(0, n-1);
	cout << cnt;
	return ;
}

int32_t main(){
	init();
	int t=1;
//	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
