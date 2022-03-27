#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+1;
int a[mxN];
char c[mxN];
double d[mxN];
struct String {
	char a[105];
	bool operator < (const String& o) const {
		if(strcmp(a, o.a)<0) return true;
		return false;
	}
} s[mxN];
int main() {
	int opr,n;
	scanf("%d %d", &opr, &n);
	if(opr==1) {
		for(int i=0; i<n; ++i)
			scanf("%d", &a[i]);
		sort(a, a+n);
		for(int i=0; i<n; ++i)
			printf("%d ", a[i]);
		printf("\n");
		for(int i=n-1; i>=0; --i)
			printf("%d ", a[i]);
		printf("\n");
	}
	else if(opr==2) {
		for(int i=0; i<n; ++i)
			scanf("%lf", &d[i]);
		sort(d, d+n);
		for(int i=0; i<n; ++i)
			printf("%.0lf ", d[i]);
		printf("\n");
		for(int i=n-1; i>=0; --i)
			printf("%.0lf ", d[i]);
		printf("\n");
	}
	else if(opr==3) {
		for(int i=0; i<n; ++i)
			scanf(" %c", &c[i]);
		sort(c, c+n);
		for(int i=0; i<n; ++i)
			printf("%c ", c[i]);
		printf("\n");
		for(int i=n-1; i>=0; --i) {
			printf("%c ", c[i]);
		}
		printf("\n");
	}
	else {
		for(int i=0; i<n; ++i)
			scanf(" %s", s[i].a);
		sort(s, s+n);
		for(int i=0; i<n; ++i)
			printf("%s ", s[i].a);
		printf("\n");
		for(int i=n-1; i>=0; --i)
			printf("%s ", s[i].a);
		printf("\n");
	}
	return 0;
}
