#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e3 + 5;
const int N = (1 << 20) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, m, k, p[O], rp[O], G[O][O];

int bcc_cnt, Time, low[O], tin[O];
vector <int> g[O], bcc[O];

pair <int, int> S[O];
int top;

void dfs(int u, int par = 0){
    low[u] = tin[u] = ++ Time;

    for (int v : g[u]){
        if (v != par){
            if (!tin[v]){
                S[top ++] = make_pair(u, v);
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (tin[u] <= low[v]){
                    /// cut_vertex
                    do{
                        bcc[bcc_cnt].push_back(S[-- top].second);
                    } while (S[top] != make_pair(u, v));

                    bcc[bcc_cnt].push_back(u);
                    bcc_cnt += 1;
                }
            }
            else{
                low[u] = min(low[u], tin[v]);
            }
        }
    }
}

void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
    return;
}

int exp(int a, int x){
    int res = 1;
    for (; x; x >>= 1){
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int C(int k, int n){
    if (k > n) return 0;
    return p[n] * rp[n - k] % mod * rp[k] % mod;
}

int chiakeo(int k, int n){
    return C(n - 1, n + k - 1);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    p[0] = rp[0] = 1;
    for (int i = 1; i < O; ++ i){
        p[i] = p[i - 1] * i % mod;
        rp[i] = exp(p[i], mod - 2);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        G[u][v] = G[v][u] = 1;
    }

    for (int i = 1; i <= n; ++ i){
        if (!tin[i]) dfs(i);
    }

    //cout << bcc_cnt << endl;

    int res = 1;
    for (int i = 0; i < bcc_cnt; ++ i){
        //cout << "deba " << i << ":\n";
        //for (int j : bcc[i]) cout << j << " "; cout << endl;

        int sz = bcc[i].size(), dem = 0;
        for (int j = 0; j < sz; ++ j){
            for (int z = j + 1; z < sz; ++ z){
                dem += G[bcc[i][j]][bcc[i][z]];
            }
        }

        if (sz == dem + 1){
            res = res * exp(k, dem) % mod;
        }
        else if (sz == dem){
            int x = 0;
            for (int j = 0; j < sz; ++ j){
                Add(x, exp(k, __gcd(sz, j)));
            }
            res = res * x % mod * exp(sz, mod - 2) % mod;
        }
        else res = res * chiakeo(dem, k) % mod;
    }

    cout << res;
}
/**
11 12 48
3 1
8 2
4 9
5 4
1 6
2 9
8 3
10 8
4 10
8 6
11 7
1 8

**/
