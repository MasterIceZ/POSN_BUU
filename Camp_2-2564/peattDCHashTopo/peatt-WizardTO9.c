/*
	TASK: Wizards TOI9
	LANG: C
	AUTHOR: PeaTT~
*/
#include<bits/stdc++.h>
using namespace std;
int const N = 1500 + 10;
int const sz = 5e6 + 11;
int sum[2][sz], hashtable[sz], x[4][N], y[4][N];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int xtt, ytt, n;
    cin >> xtt >> ytt >> n;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < n; j++)
            cin >> x[i][j] >> y[i][j];
    for(int i = 0; i< n; i++){
        for(int j = 0; j < n; j++){
            int xnow = x[0][i] + x[1][j];
            int ynow = y[0][i] + y[1][j];
            long long idx  = (((xnow + 3 * ynow) % sz) + sz) % sz;
            while(hashtable[idx]){
                idx++;
                idx %= sz;
            }
            hashtable[idx] = (1500 * i) + j + 1;
            sum[0][idx] = xnow, sum[1][idx] = ynow;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int xnow = xtt - (x[2][i] + x[3][j]);
            int ynow = ytt - (y[2][i] + y[3][j]);
            long long idx  = (((xnow + 3 * ynow) % sz) + sz) % sz;
            while(hashtable[idx]){
                if(sum[0][idx] == xnow && sum[1][idx] == ynow){
                    int k = hashtable[idx] - 1;
                    cout << x[0][k / 1500] << " " << y[0][k / 1500] << "\n";
                    cout << x[1][k % 1500] << " " << y[1][k % 1500] << "\n";
                    cout << x[2][i] << " " << y[2][i] << "\n";
                    cout << x[3][j] << " " << y[3][j] << "\n";
                    return 0;
                }
                idx++, idx %= sz;
            }
        }
    }
	return 0;
}
/*
-1 3
3
1 -10 16 3 -11 -10
-17 7 -15 -2 -7 9
-2 6 -18 -15 5 19
9 -18 -7 -17 19 4
*/
