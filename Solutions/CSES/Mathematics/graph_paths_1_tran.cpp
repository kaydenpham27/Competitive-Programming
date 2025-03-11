#include <bits/stdc++.h>
#define int long long
#define Matrix vector <vector <int>>
 
using namespace std;
 
const int O = 2e3 + 5;
const int mod = 1e9 + 7;//998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, m, k;
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
int lowbit(int x){
    for (int i = 0; i <= 20; ++ i)
        if (x >> i & 1) return 1 << i;
}
 
void Resize(Matrix &x, int n, int m){
    x.resize(n);
    for (int i = 0; i < n; ++ i) x[i].assign(m, 0);
}
 
Matrix operator *(Matrix &x, Matrix &y){
    Matrix z; Resize(z, x.size(), y[0].size());
    for (int i = 0; i < x.size(); ++ i){
        for (int j = 0; j < y[0].size(); ++ j){
            for (int l = 0; l < x[0].size(); ++ l) Add(z[i][j], 1ll * x[i][l] * y[l][j] % mod);
        }
    }
    return z;
}
 
Matrix exp(Matrix a, int x){
    Matrix res = a; x -= 1;
    for (; x; x >>= 1){
        if (x & 1) res = res * a;
        a = a * a;
    }
    return res;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
 
    Matrix f; Resize(f, n, n);
 
    for (int i = 0; i < m; ++ i){
        int u, v; cin >> u >> v;
        f[u - 1][v - 1] += 1;
    }
 
    f = exp(f, k);
 
    cout << f[0][n - 1];
}