#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 1;
 
vector <int> g[O], gr[O], f[21], adj[O], iS, vis, t, order, components, h, sz, group, tt;
 
void dfs1(int u){
    vis[u] = 1;
    for (int v : g[u]){
        if (vis[v] == 0) dfs1(v);
    }
    order.push_back(u);
}
 
void dfs2(int u){
    vis[u] = 1;
    for (int v : gr[u]){
        if (vis[v] == 0) dfs2(v);
    }
    components.push_back(u);
}
 
void dfs(int u){
    vis[u] = 1;
    for (int v : gr[u]){
        if (vis[v] == 1) continue;
        h[v] = h[u] + 1;
        f[0][v] = u;
        dfs(v);
    }
}
 
int Lca(int u, int dept){
    for (int i = 0; i <= 20; ++ i){
        if (dept & (1 << i)) u = f[i][u];
        if (u == -1) return 0;
    }
    return u;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vis.resize(n + 1);
    t.resize(n + 1);
    iS.resize(n + 1);
    h.resize(n + 1);
    sz.resize(n + 1);
    tt.resize(n + 1);
    group.resize(n + 1);
    for (int i = 0; i <= 20; ++ i) f[i].assign(n + 1, -1);
    for (int i = 1; i <= n; ++ i){
        cin >> t[i];
        g[i].push_back(t[i]);
        gr[t[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        if (vis[i] == 0) dfs1(i);
    }
    reverse(order.begin(), order.end());
    vis.assign(n + 1, 0);
    int cnt = 0;
    for (int i : order){
        if (vis[i] == 0){
            components.clear();
            dfs2(i);
            cnt += 1;
            for (int z = 0; z < components.size(); ++ z){
                int j = components[z];
                if (t[j] == j || components.size() > 1) iS[j] = 1;
                group[j] = cnt;
                tt[j] = z + 1;
            }
            sz[cnt] = components.size();
        }
    }
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; ++ i){
        if (iS[i] && vis[i] == 0) dfs(i);
    }
    for (int i = 1; i < 21; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (f[i - 1][j] != -1) f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    for (int o = 1; o <= q; ++ o){
        int u, v; cin >> u >> v;
        int ans = 0;
        if (group[v] == group[u]){
            cout << (tt[v] - tt[u] + sz[group[v]]) % sz[group[v]] << '\n';
            continue;
        }
        if (iS[u] && iS[v] == 0){
            cout << -1 << '\n';
            continue;
        }
        if (!(iS[u] && iS[v])){
            if (iS[u]){
                int z = Lca(u, h[u]);
                ans = ((tt[u] - tt[z] + sz[group[u]]) % sz[group[u]]);
                u = Lca(u, h[u]);
            }
        }
        if (iS[v] && Lca(u, h[u]) == Lca(v, h[v])){
            if (Lca(u, h[u] - h[v]) == v){
                cout << h[u] - h[v] << '\n';
                continue;
            }
            int z = Lca(v, h[v]);
            cout << h[u] + ((tt[v] - tt[z] + sz[group[v]]) % sz[group[v]]) << '\n';
            continue;
        }
        if (Lca(u, h[u] - h[v]) == v) cout << ans + h[u] - h[v] << "\n";
        else cout << -1 << '\n';
    }
}