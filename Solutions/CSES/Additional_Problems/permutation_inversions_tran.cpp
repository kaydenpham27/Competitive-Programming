#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 5e2 + 5;
const int N = O * O / 2;
const int mod = 1e9 + 7;
 
int n, k, f[O][N];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    f[0][0] = 1;
    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j <= min(k, i * (i - 1) / 2); ++ j){
            if (j) Add(f[i][j], f[i][j - 1]);
            if (f[i][j]){
                Add(f[i + 1][j], f[i][j]);
                Add(f[i + 1][min(k + 1, j + i + 1)], -f[i][j]);
            }
        }
    }
 
    cout << f[n][k];
}
/***
***/