#include <bits/stdc++.h>
using namespace std;
// o > red | 1 > blue
int l[200020][2], r[200020][2];
char a[200020], temp[100100];

int main(){
    int n;
    scanf("%d %s", &n, temp);
    strcpy(a, temp);
    strcat(a, temp);
    for(int i=1; i<=2*n; i++){
        if(a[i-1] == 'r'){
            l[i][0] = l[i-1][0]+1;
            l[i][1] = 0;
        }
        else if(a[i-1] == 'b'){
            l[i][1] = l[i-1][1]+1;
            l[i][0] = 0;
        }
        else if(a[i-1] == 'w'){
            l[i][1] = l[i-1][1]+1;
            l[i][0] = l[i-1][0]+1;
        }
    }
    for(int i=2*n-1; i>=0; i--){
        if(a[i] == 'r'){
            r[i][0] = r[i+1][0]+1;
            r[i][1] = 0;
        }
        else if(a[i] == 'b'){
            r[i][1] = r[i+1][1]+1;
            r[i][0] = 0;
        }
        else{
            r[i][1] = r[i+1][1]+1;
            r[i][0] = r[i+1][0]+1;
        }
    }
    int ans = -1;
    for(int i=0; i<2*n; i++){
        ans = max(ans, max(l[i][0], l[i][1])+max(r[i][0], r[i][1]));
    }
    printf("%d\n", min(ans, n));
    return 0;
}
