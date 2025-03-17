#include <bits/stdc++.h>

using namespace std;

const int O = 2e5 + 5;
const int N = (1 << 10) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, m, Time, a[O], b[O], c[O], h[O], in[O], out[O], f[21][O], dp[2][O];
vector <int> g[O], q[O];
int tree[O * 4];

void Update(int id, int l, int r, int u, int val){
    if (l > u || r < u) return;
    if (l == r){
        tree[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u, val);
    Update(id << 1 | 1, mid + 1, r, u, val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}

void init(int u, int par = 0){
    in[u] = ++ Time;
    for (int v : g[u]){
        if (v != par){
            h[v] = h[u] + 1;
            f[0][v] = u;
            init(v, u);
        }
    }
    out[u] = ++ Time;
}

int Lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);

    for (int i = 20; i >= 0; -- i){
        if (h[u] - (1 << i) >= h[v]) u = f[i][u];
    }

    if (u == v) return u;

    for (int i = 20; i >= 0; -- i){
        if (f[i][u] != f[i][v]){
            u = f[i][u];
            v = f[i][v];
        }
    }

    return f[0][u];
}

int Jump(int u, int d){
    for (int i = 20; i >= 0; -- i){
        if (d >> i & 1) u = f[i][u];
    }
    return u;
}

void dfs(int u, int par = 0){
    dp[0][u] = dp[1][u] = 0;
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
            dp[0][u] +=  max(dp[1][v], dp[0][v]);
        }
    }

    for (int i : q[u]){
        int x = (a[i] == u) ? -1 : a[i];
        int y = (b[i] == u) ? -1 : b[i];

        int val = dp[0][u] + c[i];

        if (x != -1){
            val = val + Get(1, 1, Time, in[u], in[x]);
        }

        if (y != -1){
            val = val + Get(1, 1, Time, in[u], in[y]);
        }

        dp[1][u] = max(dp[1][u], val);
    }

    Update(1, 1, Time, in[u], dp[0][u] - max(dp[0][u], dp[1][u]));
    Update(1, 1, Time, out[u], max(dp[0][u], dp[1][u]) - dp[0][u]);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(f, -1, sizeof(f));
    init(1);

    for (int i = 1; i <= 20; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (f[i - 1][j] != -1) f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }

    cin >> m;
    for (int i = 1; i <= m; ++ i){
        cin >> a[i] >> b[i] >> c[i];
        int u = Lca(a[i], b[i]);
        q[u].push_back(i);
    }

    dfs(1);

    cout << max(dp[0][1], dp[1][1]);
}
/**
1
6 3
1 2 1 4 3 8
**/