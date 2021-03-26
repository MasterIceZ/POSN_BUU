#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

char a[111];

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,s,e,w,x,y;
	n = s = e = w = x = y = 0;
	cin >> a;
	for(int i=0;i<strlen(a);++i){
		if(a[i] == 'N'){
			n++;
			y++;
		}
		else if(a[i] == 'S'){
			s++;
			y--;
		}
		else if(a[i] == 'E'){
			e++;
			x++;
		}
		else{
			w++;
			x--;
		}
	}	
	int k;
	cin >> k;
	while(k--){
		if(n>0 && s>n){
            n--,y--;
        }
        else if(s>0 && n>s){
            s--,y++;
        }
        else if(e>0 && w>e){
            e--,x--;
        }
        else if(w>0 && e>w){
            w--,x++;
        }
         else if(s==0 && n>0){
            n--,y--;
        }
        else if(e==0 && w>0){
            w--,x++;
        }
        else if(w==0 && e>0){
            e--,x--;
        }
          else if(n==0&& s>0){
            s--,y++;
        }
	}
	cout << ((abs(y-0) + abs(x)) * 2) << '\n';
	return 0;
}
