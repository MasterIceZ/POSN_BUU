#include <bits/stdc++.h>
using namespace std;

int u[1010][1010];
int d[1010][1010];
int l[1010][1010];
int R[1010][1010];
char a[1010][1010];

int main(){
    int q, r, c, ans = -1, i, j;
    scanf("%d", &q);
    while(q--){
        ans = -1;
        scanf("%d %d", &r, &c);
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                scanf(" %c", &a[i][j]);
            }
        }

        for(i=1; i<=r; i++){
            for(j=1; j<=c; j++){
                if(a[i][j] == '1'){
                    l[i][j] = l[i][j-1]+1;
                }
            }
            for(j=c; j>=1; j--){
                if(a[i][j] == '1')
                    R[i][j] = R[i][j+1]+1;
            }
        }
        for(j=1; j<=c; j++){
            for(i=1; i<=r; i++){
                if(a[i][j] == '1')
                    u[i][j] = u[i-1][j]+1;
            }
            for(i=r; i>=1; i--){
                if(a[i][j] == '1')
                    d[i][j] = d[i+1][j]+1;
            }
        }
        for(i=1; i<=r; i++){
            for(j=1; j<=c; j++){
                ans = max({u[i][j]+l[i][j]-1, u[i][j]+R[i][j]-1, d[i][j]+l[i][j]-1, d[i][j]+R[i][j]-1, ans});
            }
        }
        printf("%d\n",ans);
        memset(l, 0, sizeof l);
        memset(R, 0, sizeof R);
        memset(u, 0, sizeof u);
        memset(d, 0, sizeof d);
    }
    return 0;
}
