#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, k, Time, h[O], in[O], out[O], f[21][O];
vector <int> g[O];
/// euler tour?
int tree[O * 4], lazy[O * 4];
 
void dfs(int u, int par = 0){
    in[u] = ++ Time;
    for (int v : g[u]){
        if (v != par){
            h[v] = h[u] + 1;
            dfs(v, u);
            f[0][v] = u;
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
 
void Push(int id){
    int &x = lazy[id];
    if (x == 0) return;
    tree[id << 1] += x;
    lazy[id << 1] += x;
    tree[id << 1 | 1] += x;
    lazy[id << 1 | 1] += x;
    x = 0;
    return;
}
 
void Update(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l + r) / 2; Push(id);
    Update(id << 1, l, mid, u, v, val);
    Update(id << 1 | 1, mid + 1, r, u, v, val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id);
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    memset(f, -1, sizeof(f));
 
    dfs(1);
 
    for (int i = 1; i <= 20; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (f[i - 1][j] != -1){
                f[i][j] = f[i - 1][f[i - 1][j]];
            }
        }
    }
 
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        int lca = Lca(u, v);
        Update(1, 1, Time, in[lca], in[u], 1);
        Update(1, 1, Time, in[lca] + 1, in[v], 1);
    }
 
    for (int i = 1; i <= n; ++ i){
        int u = i;
        int res = Get(1, 1, Time, in[u], in[u]);
        res -= Get(1, 1, Time, out[u], out[u]);
        cout << res << " ";
    }
}