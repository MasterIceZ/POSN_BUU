#include <bits/stdc++.h>

using namespace std;

const int MxN = 100550;
const int MxM = 550;

bitset<MxN> mem, company[MxM];
int worker[MxN], parent[MxN + MxM];
int current_root[MxM], rev_root[MxN + MxM];

int find_root(int u) {
	if(u == parent[u]) {
		return u;
	}
	return parent[u] = find_root(parent[u]);
}

signed main(int argc, char *argv[]) {
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	int n, m, k, cnt = 0;
	cin >> n >> m >> k;
	int it = n;
	for(int i=1; i<=m; ++i) {
		++it;
		parent[it] = it;
		current_root[i] = it;
		rev_root[it] = i;
	}
	for(int i=1, x; i<=n; ++i) {
		cin >> x;
		company[x][i] = true;
		parent[i] = current_root[x];
		if(!mem[x]) {
			cnt++;
		}
		mem[x] = true;
	}	
	for(int i=1, a, b; i<=k; ++i) {
		char opr;
		cin >> opr >> a >> b;
		if(a == b) {
			continue;
		}
		if(opr == 'O') {
			int current_company = find_root(a);
			company[rev_root[current_company]][a] = false;
			parent[a] = current_root[b];
			company[b][a] = true;

			int cc = company[rev_root[current_company]].count(); 
			if(cc == 0) {
				cnt--;
			}
			cc = company[b].count();
			if(cc == 1) {
				cnt++;
			}
		}
		else {
			int current_company_id = find_root(a);
			int current_company = rev_root[current_company_id];
			company[b] |= company[current_company];	
			company[current_company] = 0;
			parent[current_company_id] = current_root[b];

			cnt--;

			// update workers
			++it;
			parent[it] = it;
			current_root[a] = it;
			rev_root[it] = a;
		}
	}
	return 0;
}
