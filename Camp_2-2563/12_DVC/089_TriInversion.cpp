/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: 48_Tri Inversion
 * ALGO		: Divide and Conquer
 * DATE		: 16 May 2021
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

int a[100100], b[100100], idx[100100];
int ll[100100], rr[100100], id[100100];

void mergesort(int l, int r){
	if(l >=r){
		return ;
	}
	int mid = (l+r)/2;
	mergesort(l, mid);
	mergesort(mid+1, r);
	int i = l, j = mid+1, k = l;
	while(i <= mid && j <= r){
		if(a[i] < a[j]){
			id[i] = idx[i];
			b[k] = a[i];
			rr[id[i]] += mid - j + 1;			
			++k, ++i;
		}
		else{
			id[j] = idx[j];
			b[k] = a[j];
			ll[id[j]] += mid - i + 1;
			++j, ++k;
		}
	}
	while(i <= mid){
		id[i] = idx[i];
		b[k] = a[i];
		rr[id[i]] = r - mid;
		++k, ++i ;
	}
	while(j <= r){
		id[j] = idx[j];
		b[k++] = a[j++];
	}
	for(int x=l; x<=r; ++x){
		a[x] = b[x];
		idx[x] = id[x];
	}
	return ;
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; ++i){
		cin >> a[i];
		idx[i] = i;
	}
	mergesort(1, n);
	int ans = 0;
	for(int i=0; i<=n; ++i){
		ans += ll[i] * rr[i];
	}
	cout << ans;
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
		memset(b, 0, sizeof b);
		memset(a, 0, sizeof a);
		memset(rr, 0, sizeof rr);
		memset(ll, 0, sizeof ll);
		memset(id, 0, sizeof id);
		memset(idx, 0, sizeof idx);
	}
	return 0;
}
void init(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	#ifdef ONLINE_JUDGE
	freopen("input2.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	#endif
	return ;
}
