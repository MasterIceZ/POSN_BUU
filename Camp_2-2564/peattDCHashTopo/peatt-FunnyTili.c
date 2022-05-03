/*
     TASK: Funny Tiling
     AUTHOR: PeaTT~
     LANG: CPP
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a, b, c;
    bool operator < (const A & o) const{
        if(a != o.a) return a < o.a;
        if(b != o.b) return b < o.b;
        return c < o.c;
    }
};
A ans[1000000];
int cnt;
void sol(int n, int si, int sj, int pi, int pj){
    if(n==1) return ;
    n /= 2;
    int st = (si + n <= pi) + (sj +n <= pj) * 2;
    for(int j = 0; j < 2; j++){
        for(int i = 0; i < 2; i++){
            if(j * 2 + i == st)
                sol(n, si + n * i, sj + n * j, pi, pj);

            else
                sol(n, si + n * i, sj + n * j, si + n - i, sj + n - j);

        }
    }
    ans[cnt++] = {st, si + n - 1, sj + n - 1};
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    cout << (n * n / 3) << "\n";
    sol(n, 0, 0 , a, b);
    sort(ans, ans + cnt);
    for(int i = 0; i < cnt; i++)
        cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << "\n";
}
