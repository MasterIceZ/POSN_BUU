#include <stdio.h>
#include <string.h>

char a[100010], b[100010], t[100010], c[100010];

int main() {
	scanf(" %s %s", a + 1, b + 1);
	int lena = strlen(a + 1), lenb = strlen(b + 1);
	int i, j, r = 0;
	for(i=1, j=lena; i<=lena; ++i, --j) {
		t[i] = a[j];
	}
	for(i=1; i<=lena; ++i) {
		a[i] = t[i];
	}
	for(i=1, j=lenb; i<=lenb; ++i, --j) {
		t[i] = b[j];
	}
	for(i=1; i<=lenb; ++i) {
		b[i] = t[i];
	}
	i = 1, j = 1;
	for(; i<=lena && j<=lenb; ++i, ++j) {
		int s = a[i] + b[j] - 2 * '0' + r;
		r = s / 10;
		c[i] = '0' + (s % 10);
	}
	for(; i<=lena; ++i) {
		int s = a[i] + '0' + r;
		r = s / 10;
		c[i] = '0' + (s % 10);
	}
	for(; j<=lenb; ++j) {
		int s = b[j] + '0' + r;
		r = s / 10;
		c[j] = '0' + (s % 10);
	}
	if(r != 0) {
		int lenc = strlen(c + 1);
		c[lenc] = '1';
	}
	int lenc = strlen(c + 1);
	for(i=1, j=lenc; i<=lenc; ++i, --j) {
		t[i] = c[j];
	}
	for(i=1; i<=lenc; ++i) {
		c[i] = t[i];
	}
	printf("%s", c);
	return 0;
}
