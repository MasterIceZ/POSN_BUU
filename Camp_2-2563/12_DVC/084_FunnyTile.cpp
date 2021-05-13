/*
 * AUTHOR	: Hydrolyzed~
 * SCHOOL	: RYW
 * CENTER	: BUU
 * TASK		: Funny Tile
 * ALGO		: Divide and Conquer
 * DATE		: 13 May 2021
 * */
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b,c;
    bool operator <(const A&o) const{
        if(a!=o.a) return a < o.a;
        if(b!=o.b) return b < o.b;
        return c < o.c;
    }
};
A ans[1000000];
int cou;
void tile(int n,int si,int sj,int pi,int pj){
    if(n==1){
        return ;
    }
    n/=2;
    int st = (si+n<=pi)+(sj+n<=pj)*2;
    for(int j=0;j<2;j++){
        for(int i=0;i<2;i++){
            if(j*2+i==st){
                tile(n,si+n*i,sj+n*j,pi,pj);
            }
            else{
                tile(n,si+n*i,sj+n*j,si+n-i,sj+n-j);
            }
        }
    }
    ans[cou++]={st,si+n-1,sj+n-1};
}
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    printf("%d\n",n*n/3);
    tile(n,0,0,a,b);
    sort(ans,ans+cou);
    for(int i=0;i<cou;i++) printf("%d %d %d\n",ans[i].a,ans[i].b,ans[i].c);
    return 0;
}
