#include <stdio.h>

unsigned int heap_size = 0;
int heap_data[300030];

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int max(int a, int b) {
	return a > b ? a: b;
}

void heap_up() {
	unsigned int cur = heap_size;
	while(cur > 1) {
		unsigned int up = cur / 2;
		if(heap_data[up] >= heap_data[cur]) {
			break;
		}
		swap(&heap_data[cur], &heap_data[up]);
		cur = up;
	}
}

void heap_down() {
	unsigned int cur = 1;
	while(cur <= heap_size) {
		unsigned left_child = cur * 2, right_child = cur * 2 + 1;
		int max_child = max(heap_data[left_child], heap_data[right_child]);
		if(heap_data[cur] > max_child) {
			break;
		}
		if(heap_data[left_child] > heap_data[right_child]) {
			swap(&heap_data[cur], &heap_data[left_child]);
			cur = left_child;
		}
		else {
			swap(&heap_data[cur], &heap_data[right_child]);
			cur = right_child;
		}
	}
}

void heap_insert(int v) {
	heap_data[++heap_size] = v;
	heap_up();
}

void heap_pop() {
	swap(&heap_data[1], &heap_data[heap_size--]);
	heap_down();
}

int heap_top() {
	return heap_data[1];
}

signed main(int argc, char *argv[]) {
	int n;
	scanf("%d", &n);
	for(int i=1, val; i<=n; ++i) {
		char opr;
		scanf(" %c", &opr);
		if(opr == 'P') {
			scanf("%d", &val);
			heap_insert(val);
		}
		else {
			if(heap_size == 0) {
				printf("-1");
			}
			else {
				printf("%d", heap_top());
				heap_pop();
			}
			printf("\n");
		}
	}
	return 0;
}
