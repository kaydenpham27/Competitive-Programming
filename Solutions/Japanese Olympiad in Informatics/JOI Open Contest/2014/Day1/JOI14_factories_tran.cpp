#include <bits/stdc++.h>
#include "factories.h"

using namespace std;

const int O = 2e6 + 5;
const int mod = 1e9 + 7; //998244353;
const long long inf = 1e16;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, q, Time, p[O], h[O], rp[O], in[O], child[O], f[22][O];
long long d[O], val[20][O];
vector <pair <int, int>> g[O];
pair <long long, int> dp[2][O];
bool del[O];

void init(int u, int par = -1){
    in[u] = ++ Time; rp[Time] = u;
    for (auto &to : g[u]){
        int v = to.first;
        int w = to.second;
        if (v != par){
            h[v] = h[u] + 1;
            d[v] = d[u] + w;
            init(v, u);
            rp[++ Time] = u;
        }
    }
}

int Lca(int u, int v){
    int l = min(in[u], in[v]);
    int r = max(in[u], in[v]);
    if (l == r) return u;

    int len = log2(r - l + 1);
    return h[f[len][l]] < h[f[len][r - (1 << len) + 1]] ? f[len][l] : f[len][r - (1 << len) + 1];
}

long long dist(int u, int v){
    return d[u] + d[v] - 2 * d[Lca(u, v)];
}

void dfs_init(int u, int par = -1){
    child[u] = 1;
    for (auto &to : g[u]){
        int v = to.first;
        int w = to.second;
        if (v != par && !del[v]){
            dfs_init(v, u);
            child[u] += child[v];
        }
    }
}

int centroid(int u, int par, int Nchild){
    for (auto &to : g[u]){
        int v = to.first;
        if (v != par && !del[v] && child[v] * 2 > Nchild) return centroid(v, u, Nchild);
    }
    return u;
}

int dfs_centroid(int u){
    dfs_init(u);
    int root = centroid(u, -1, child[u]);

    del[root] = 1;
    for (auto &v : g[root]){
        if (!del[v.first]){
            int nxt = dfs_centroid(v.first);
            p[nxt] = root;
        }
    }

    return root;
}

void Init(int N, int A[], int B[], int D[]){
    n = N;
    for (int i = 0; i < n - 1; ++ i){
        int u, v, w;
        u = A[i]; v = B[i]; w = D[i];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    memset(p, -1, sizeof(p));

    init(0);

    for (int i = 1; i <= Time; ++ i){
        f[0][i] = rp[i];
    }

    for (int i = 1; i <= 21; ++ i){
        for (int j = 1; j - 1 + (1 << i) <= Time; ++ j){
            f[i][j] = h[f[i - 1][j]] < h[f[i - 1][j + (1 << (i - 1))]] ? f[i - 1][j] : f[i - 1][j + (1 << (i - 1))];
        }
    }

    dfs_centroid(0);

    for (int i = 0; i < n; ++ i){
        int u = i, cnt = 0;
        while (u != -1){
            val[cnt ++][i] = dist(i, u);
            u = p[u];
        }
    }

    for (int i = 0; i < n; ++ i) dp[0][i] = dp[1][i] = {inf, -1};
    return;
}

long long Query(int S, int X[], int T, int Y[]){
    long long res = inf;
    for (int i = 0; i < S; ++ i){
        int u = X[i], cnt = 0;
        pair <long long, int> cur = {0, -1};
        while (u != -1){
            cur.first = val[cnt ++][X[i]];
            if (dp[0][u].first > cur.first){
                pair <long long, int> x = dp[0][u];
                dp[0][u] = cur;
                if (cur.second != x.second) dp[1][u] = x;
            }
            else{
                if (dp[1][u].first > cur.first && cur.second != dp[0][u].second){
                    dp[1][u] = cur;
                }
            }
            cur.second = u;
            u = p[u];
        }
    }

    for (int i = 0; i < T; ++ i){
        int u = Y[i], cnt = 0;

        res = min(res, dp[0][u].first);
        while (u != -1){
            int par = p[u];
            if (par != -1){
                long long cur = val[++ cnt][Y[i]];
                res = min(res, cur + (dp[0][par].second == u ? dp[1][par].first : dp[0][par].first));
            }
            u = par;
        }
    }

    for (int i = 0; i < S; ++ i){
        int u = X[i];
        while (u != -1){
            dp[0][u] = dp[1][u] = {inf, -1};
            u = p[u];
        }
    }

    return res;
}