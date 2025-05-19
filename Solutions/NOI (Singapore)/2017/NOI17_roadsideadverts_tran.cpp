#include <bits/stdc++.h>

using namespace std;

const int O = 5e5 + 5;
const int inf = 1e9;

int n, q, c[O], h[O], E[O], W[O], deg[O], p[18][O], f[18][O];
vector <int> g[O];

bool sub2 = true;

void init(int u, int par = 0){
    for (int i : g[u]){
        int v = u ^ E[i];
        int w = W[i];

        if (v != par){
            h[v] = h[u] + 1;
            c[h[u]] += w;
            c[h[v]] += c[h[u]];
            init(v, u);
        }
    }
}

void dfs(int u, int par = 0){
    for (int i : g[u]){
        int v = u ^ E[i];
        int w = W[i];

        if (v != par){
            h[v] = h[u] + 1;
            p[0][v] = u;
            f[0][v] = w;
            dfs(v, u);
        }
    }
}

void BuildLca(){
    memset(p, -1, sizeof(p));

    dfs(1);
    for (int i = 1; i <= 17; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (p[i - 1][j] != -1){
                p[i][j] = p[i - 1][p[i - 1][j]];
                f[i][j] = f[i - 1][j] + f[i - 1][p[i - 1][j]];
            }
        }
    }
}

int Lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);

    for (int i = 17; i >= 0; -- i){
        if (h[u] - (1 << i) >= h[v]) u = p[i][u];
    }

    if (u == v) return u;

    for (int i = 17; i >= 0; -- i){
        if (p[i][u] != p[i][v]){
            u = p[i][u];
            v = p[i][v];
        }
    }

    return p[0][u];
}

int Jump(int u, int d){
    int res = 0;
    for (int i = 17; i >= 0; -- i){
        if (d >> i & 1){
            res += f[i][u];
            u = p[i][u];
        }
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++ i){
        int u, v, w; cin >> u >> v >> w;
        u += 1; v += 1;
        g[u].push_back(i);
        g[v].push_back(i);

        E[i] = u ^ v;
        W[i] = w;

        deg[u] += 1;
        deg[v] += 1;

        sub2 &= deg[u] <= 2;
        sub2 &= deg[v] <= 2;
    }

    if (sub2){
        int sta;
        for (int i = 1; i <= n; ++ i)
            if (deg[i] == 1) sta = i;

        h[sta] = 1;
        init(sta);

        cin >> q;
        for (int i = 1; i <= q; ++ i){
            int node[5];
            for (int j = 0; j < 5; ++ j) cin >> node[j], node[j] += 1;

            int Min = inf, Max = -inf;
            for (int j = 0; j < 5; ++ j){
                Min = min(Min, h[node[j]]);
                Max = max(Max, h[node[j]]);
            }

            cout << c[Max - 1] - c[Min - 1] << "\n";
        }

        return 0;
    }

    BuildLca();

    cin >> q;
    for (int i = 1; i <= q; ++ i){
        int node[5];
        for (int j = 0; j < 5; ++ j) cin >> node[j], node[j] += 1;

        int lca = node[0];
        for (int j = 1; j < 5; ++ j) lca = Lca(lca, node[j]);

        int res = 0;
        for (int j = 1; j < 32; ++ j){
            int par, cnt = 0;
            for (int z = 0; z < 5; ++ z)
                if (j >> z & 1) par = node[z], cnt += 1;

            for (int z = 0; z < 5; ++ z)
                if (j >> z & 1) par = Lca(node[z], par);

            if (cnt & 1) res += Jump(par, h[par] - h[lca]);
            if (!(cnt & 1)) res -= Jump(par, h[par] - h[lca]);
        }

        cout << res << "\n";
    }
}