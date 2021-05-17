/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Plantation TOI14
 * ALGO		: Divide and Conquer
 * DATE		: 17 May 2021
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

const int d4i[] = {-1, 0, 0, 1}, d4j[] = {0, -1, 1, 0};
const int d8i[] = {-1, -1, -1, 0, 0, 1, 1, 1}, d8j[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct A{
	int x, y;
};
A a[100100];

bool cmpx(A a, A b){
	return a.x < b.x;
}
bool cmpy(A a, A b){
	return a.y < b.y;
}
double dist(A a, A b){
	return sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y)); 
}

double closest(A b[], int n){
	double ans = 2e9;
	// Base Case
	if(n<=3){
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				ans = min(ans, dist(b[i], b[j]));
			}	
		}
		return ans;
	}
	// Divide
	int mid = n/2;
	double dl = closest(b, mid);
	double dr = closest(b+mid, n-mid);
	// Conquer
	double d = min(dl, dr);
//	A strip[n+10];
	vector<A>strip;
	int j = 0;
	for(int i=0; i<n; ++i){
		if(abs(b[i].x - b[mid].x) < d){
	//		strip[j++] = b[i];
			strip.push_back(b[i]);	
		}
	}
	sort(strip.begin(), strip.end(), cmpy);	
	//sort(strip, strip+j, cmpy);
	// Combine
	
	for(int i=0; i<strip.size(); ++i){
		for(int k=i+1; k<strip.size() && strip[k].y-strip[i].y<d; ++k){
			d = min(d, dist(strip[i], strip[k]));
		}
	}
	
	return d;
}

void solution(){
	int n;
	double r, d;
	cin >> n >> r >> d;
	for(int i=0; i<n; ++i){
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a+n, cmpx);
	double ans = closest(a, n);
	cout << ((ans >= 2*r+d)?"Y":"N");
	return ;
}

int32_t main(){
	init();
	int t=1;
	cin >> t;
	while(t--){
		solution();
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
