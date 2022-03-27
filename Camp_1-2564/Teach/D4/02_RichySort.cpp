#include<bits/stdc++.h>
using namespace std;
const int mxN=1e5+1;
struct A {
	int x,y;
	bool operator < (const A& o) const {
		if(x!=o.x) return x<o.x;
		return y>o.y;
	}
} a[mxN];
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d %d", &a[i].x, &a[i].y);
	sort(a, a+n);
	for(int i=0; i<n; ++i)
		printf("%d %d\n", a[i].x, a[i].y);
	return 0;
}
