#include<bits/stdc++.h>
using namespace std;

struct Plant{
	int val, day, start;
};

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<Plant>pq;
	for(int i=1; i<=n; ++i){
		int opr;
		cin >> opr;
		if(opr == 4){
			auto now = pq.top();
			while(i - now.start > now.day){
				pq.pop();
				now = pq.top();
			}
			if(pq.empty()){
				cout << "GREAN" << endl;
			}
			else{
				cout << now.val << endl;
			}
		}
	}
		
	return 0;
}
