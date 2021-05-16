/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Pair
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

pair<int, int> x[100100];
int a[100100], b[100100];
double ans, dp[100100];

//void merge(int l, int mid, int r){
//	int ll = mid - l + 1;
//	int rr = r - mid;
//	for(int i=0; i<ll; ++i){
//		L[i] = a[i+l];
//	}
//	for(int i=0; i<rr; ++i){
//		R[i] = a[mid+i+1];
//	}
//	memset(dp, 0, sizeof dp);
//	for(int i=l; i<=r; ++i){
//		dp[i] = dp[i-1] + a[i];
//	}
//	int i = 0, j = 0, k = l;
//	while(i < ll && j < rr){
//		if(L[i] <= R[j]){
//			a[k++] = L[i++];
//		}
//		else{
//			int aa = l + i;
//			ans += (mid + 1  - aa) * a[mid + j + 1] + dp[mid] - dp[aa - 1];
//			a[k++] = R[j++];
//		}
//	}
//	while(i<ll){
//		a[k++] = L[i++];
//	}
//	while(j<rr){
//		a[k++] = R[j++];
//	}
//	return ;
//}

double qs[100100];

void merge(int l, int mid, int r){
	int i = l, j = mid+1, k = l;
//	memset(qs, 0, sizeof qs);
	qs[l-1] = 0;
	for(int i=l; i<=r; ++i){
		qs[i] = qs[i-1] + a[i]; 
	}
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			b[k++] = a[i++];
		}
		else{
			ans += (mid + 1 - i) * a[j] + qs[mid] - qs[i - 1];
			b[k++] = a[j++];
		}
	}
	while(i <= mid){
		b[k++] = a[i++];
	}
	while(j <= r){
		b[k++] = a[j++];
	}
	for(int i=l; i<=r; ++i){
		a[i] = b[i];
	}
	return ;
}

void mergesort(int l, int r){
	if(l >= r){
		return ;
	}
	int mid = l + (r-l)/2;
	mergesort(l ,mid);
	mergesort(mid+1, r);
	merge(l, mid, r);
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> x[i].second >> x[i].first;
	}
	sort(x+1, x+n+1);
	for(int i=1; i<=n; ++i){
		a[i] = x[i].second;
	}
	mergesort(1, n);
	cout << fixed << setprecision(0) << ans;
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
