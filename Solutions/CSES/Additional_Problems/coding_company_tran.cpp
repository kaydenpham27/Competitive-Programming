#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e2 + 5;
const int O = 5e3 + 50;
const int mod = 1e9 + 7;
const int inf = 1e9;
 
int n, x, a[O], f[N][N / 2][O];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++ i){
        cin >> a[i];
    }
 
    int lim = n / 2 + 1;
    sort(a, a + n); a[n] = a[n - 1];
 
    f[0][0][0] = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= lim; ++ j){
            for (int z = 0; z <= x; ++ z){
                if (f[i][j][z]){
                    int add = f[i][j][z];
                    /// close 1
                    if (j && z + (j - 1) * (a[i + 1] - a[i]) <= x){
                        Add(f[i + 1][j - 1][z + (j - 1) * (a[i + 1] - a[i])], 1ll * j * add % mod);
                    }
 
                    /// open 1
                    if (j + 1 <= lim && z + (j + 1) * (a[i + 1] - a[i]) <= x){
                        Add(f[i + 1][j + 1][z + (j + 1) * (a[i + 1] - a[i])], add);
                    }
 
                    /// open then close
                    if (z + j * (a[i + 1] - a[i]) <= x){
                        Add(f[i + 1][j][z + j * (a[i + 1] - a[i])], add);
                    }
 
                    /// append to some group
                    if (z + j * (a[i + 1] - a[i]) <= x){
                        Add(f[i + 1][j][z + j * (a[i + 1] - a[i])], 1ll * j * add % mod);
                    }
                }
            }
        }
    }
 
    /*for (int i = 1; i <= n; ++ i){
        for (int j = 0; j <= lim; ++ j){
            for (int z = 0; z <= x; ++ z){
                cout << i << " " << j << " " << z << " : " << f[i][j][z] << endl;
            }
        }
    }*/
 
    int res = 0;
    for (int i = 0; i <= x; ++ i) Add(res, f[n][0][i]);
    cout << res;
}
/***
***/