#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e2 + 50;
const int mod = 1e9 + 7;
 
int n, m, d[O][O], f[21][(1 << 20) + 5];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        -- u; -- v;
        d[u][v] += 1;
    }
 
    f[0][1] = 1;
    for (int i = 1; i < 1 << n; ++ i){
        vector <int> non;
        for (int j = 0; j < n; ++ j){
            if (!(i >> j & 1)) non.push_back(j);
        }
 
        for (int j = 0; j < n; ++ j){
            if ((i >> j & 1) && f[j][i]){
                for (int z : non) Add(f[z][i | (1 << z)], 1ll * f[j][i] * d[j][z] % mod);
            }
        }
    }
 
    cout << f[n - 1][(1 << n) - 1];
}