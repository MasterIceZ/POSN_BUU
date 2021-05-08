/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: AP_Magic Hat 
 * ALGO		: Heap
 * DATE		: 6 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
struct A{
    int w, v, d, id;
    bool operator<(const A& o)const{
        return w>o.w;
    }
};
struct B{
    int w, v, d, id;
    bool operator<(const B& o)const{
        return d>o.d;
    }
};
priority_queue< A > hat;
priority_queue< B > tim;
int mark[200100];
int main () {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m, i, opr, w, v, d, x, k, ch;
    cin>>n>>m;
    for (i=0;i<n+m;i++) {
        cin>>opr;
        if(opr==1) {
            cin>>k;
            if(k==1) {
                cin>>w>>v;
                hat.push({w,v,200001,i});
            }
            else if(k==2) {
                cin>>w>>v>>d;
                hat.push({w,v,d,i});
            }
            else if(k==3) {
                cin>>w>>v>>d>>x;
                hat.push({w,v,d,i});
                tim.push({x,v,d,i});
            }
        }
        else if (opr==2) {
            while(!tim.empty()&&tim.top().d<=i) {
                hat.push({tim.top().w,tim.top().v,200001,tim.top().id});
                tim.pop();
            }
            ch=1;
            while (!hat.empty()) {
                if (hat.top().d<=i){
                    hat.pop();
                    continue ;
                }
                if (mark[hat.top().id]) {
                    hat.pop();
                    continue ;
                }
                cout<<hat.top().v<<endl;
                mark[hat.top().id]=1;
                hat.pop();
                ch=0;
                break;
            }
            if(ch) {
                cout<<"0"<<endl;
            }
        }
    }
    return 0 ;
}
