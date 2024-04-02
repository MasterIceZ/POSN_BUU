#include "testlib.h"
#include "aquagenlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;
const int MAX_K = 100000;

vector<int> adj[MxN];
int in[MxN], out[MxN], it = 0, rev[MxN << 1], tree_number[MxN], tree_num;
bitset<MxN> isLeaf, visited;

void dfs(int u, int p) {
	in[u] = ++it;
  rev[it] = u;
  tree_number[u] = tree_num;
	bool gone = false;
  visited[u] = true;
	for(auto x: adj[u]) {
		if(x == p) {
			continue;
		}
		dfs(x, u);
		gone = true;
	}
	isLeaf[u] = !gone;
	out[u] = ++it;
  rev[it] = u;
}

signed main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  int N = opt<int> ("n");
  int T = opt<int> ("t");
  int Q = opt<int> ("q");

  set<int> st;
  while((int) st.size() != T - 1) {
	  int x = rnd.next(1, N);
	  st.emplace(x);
  }
  st.emplace(N);
  vector<int> rt;
  vector<pair<int, int>> edges;
  int last = 0;
  for(auto x: st) {
    vector<pair<int, int>> current_tree_edges = gen_edge_tree(x - last, 1, x - last);
    for(auto edge: current_tree_edges) {
      edges.emplace_back(1 + last + edge.first, 1 + last + edge.second);
    }
    int r = rnd.next(last + 1, x);
    rt.emplace_back(r);
    last = x;
  }

  // for(int i=1; i<=N; ++i) {
  //   if(!visited[i]) {
  //     cerr << "NOT VISITED << " << i << "\n";
  //   }
  // }

  cout << N << " " << edges.size() << " " << T << "\n";
  for(auto x: edges) {
	  cout << x.first << " " << x.second << "\n";
    adj[x.first].emplace_back(x.second);
    adj[x.second].emplace_back(x.first);
  }
  for(int i=0; i<T; ++i) {
	  cout << rt[i] << " \n"[i == T - 1];
  }
  // cerr << "GENERATE TREE DONE!\n";
  for(auto x: rt) {
	  ++tree_num;
	  dfs(x, 0);
  }
  cout << Q << "\n";
  for(int i=1; i<=Q; ++i) {
	  int state = rnd.next(0, 1);
	  if(state == 0) {
		  // same tree
		  int u;
		  do {
				  u = rnd.next(1, N);
			} while(isLeaf[u]);
			int in_u = in[u], out_u = out[u];
      // cerr << "GONE? " << (visited[u] ? "YES": "NO") << " " << u << "\n";
      // cerr << "TEST: " << in_u + 1 << " " << out_u - 1 << "\n";
      int smth_v = rnd.next(in_u + 1, out_u - 1);
      int v = rev[smth_v];
		  int state = rnd.next(0, 2);
		  if(state == 0) {
			  // answer no
        cout << u << " " << v << "\n";
		  }
		  else {
			  // answer yes
        cout << v << " " << u << "\n";
		  }
	  }
	  else {
		  // different tree
      int u = rnd.next(1, N), v;
      do {
        v = rnd.next(1, N);
      } while(tree_number[v] == tree_number[u]);
      cout << u << " " << v << "\n";
	  }
  }
  return 0;
}
