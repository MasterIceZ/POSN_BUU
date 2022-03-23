#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> horizontal, vertical;
int n, a[10][10];

class Reader{
public:
	void read(vector<vector<int>>& res){
		vector<int> v;
		for(int i=1, x; i<=n; ++i){
			v.clear();
			while(1){
				cin >> x;
				if(!x){
					break;
				}
				v.push_back(x);
			}
			res.emplace_back(v);
		}
		return ;
	}
};
Reader input;

class Solver{
private:
	vector<int> rows, cols;
	Solver(){
		memset(a, -1, sizeof a);	
	}
public:
	bool row(int idx){
		vector<int> cur;
		vector<vector<int>> lines;
		int val;
		bool go;
		for(int i=0; i<(1 << n); ++i){
			go = true;
			cur.clear();
			for(int j=0; j<n; ++j){
				if((i & (1 << j))){
					val = 1;
				}
				else{
					val = 0;
				}
				if(a[idx][j] != -1 && a[idx][j] != val){
					go = false;
				}
				cur.push_back(val);
			}
			if(go){
				lines.emplace_back(cur);
			}
		}
		int pos;
		for(int i=lines.size()-1; i>=0; --i){
			lines.clear();
			val = pos = 0;
			while(pos < n){
				if(!lines[i][pos]){
					if(!val){
						cur.push_back(val);
						val = 0;
					}
				}
				else{
					val++;
				}
				pos++;
			}
			if(val != 0){
				cur.push_back(val);
			}
			if(!equal(cur, rows[idx])){
				lines.erase(lines.begin() + i);
			}
		}
		bool changed = false;
		if(lines.size()){
			for(int j=0; j<n; ++j){
				if(a[i][j] != -1){
					continue;
				}
				go = true;
				val = lines[0][j];
				for(int i=1; i<=lines.size(); ++i){
					if(val != liens[i][j]){
						go = false;
					}
				}
				if(go){
					a[idx][j] = val;
					changed = true;
				}
			}
		}
		return changed;
	}
};
Solver solver;

int main(){
	cin.tie(nullptr)->ios::sync_with_stdio(false);

	cin >> n;
	input.read(horizontal);
	input.read(vertical);

	bool finished = false;
	while(!finished){
		finsihed = true;
		for(int i=0; i<n; ++i){
			if(solver.row(i)){
				finished = false;
			}
			if(solver.col(i)){
				finsihed = false;
			}
		}
	}
	return 0;
}
