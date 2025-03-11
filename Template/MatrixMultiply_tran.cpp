#include <bits/stdc++.h>
#define int long long
#define Matrix vector <vector <int>>

using namespace std;

const int O = 2e5 + 5;
const int mod = 1e9 + 7;//998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, m, a[O], s[O], l[O];

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
    Matrix res = a;
    for (int i = 0; i < res.size(); ++ i){
        for (int j = 0; j < res.size(); ++ j){
            res[i][j] = (i == j);
        }
    }
    for (; x; x >>= 1){
        if (x & 1) res = res * a;
        a = a * a;
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i) cin >> s[i];
    for (int j = 1; j <= m; ++ j) cin >> l[j];

    Matrix B; Resize(B, m, 2);
    Matrix C; Resize(C, 2, m);
    Matrix V; Resize(V, 1, m);

    for (int i = 0; i < m; ++ i){
        B[i][0] = (s[i + 1] + l[i + 1]);
        B[i][1] = l[i + 1];

        C[0][i] = (s[i + 1] + l[i + 1]);
        C[1][i] = (mod - l[i + 1]) % mod;
    }

    /*cout << "B" << endl;
    for (int i = 0; i < m; ++ i){
        for (int j = 0; j < 2; ++ j) cout << B[i][j] << " "; cout << endl;
    }
    cout << "C" << endl;
    for (int i = 0; i < 2; ++ i){
        for (int j = 0; j < m; ++ j) cout << C[i][j] << " "; cout << endl;
    }*/

    V[0][0] = 1;

    Matrix A = exp(C * B, n - 1);
    V = V * B;
    V = V * A;
    V = V * C;

    //cout << V.size() << " " << V[0].size() << endl;
    int ans = 0;
    for (int i = 0; i < m; ++ i) Add(ans, V[0][i]);//, cout << i << " " << res[i][0] << endl;

    cout << ans;
}