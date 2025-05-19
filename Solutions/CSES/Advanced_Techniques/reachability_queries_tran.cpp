#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
 
using namespace std;
 
const int O = 5e4 + 1;
const int inf = 1e9;
 
int n, m, q, cmp[O];
bool dd[O];
bitset <O> a[O];
vector <int> g[O], gr[O], adj[O], order, comp;
 
void init(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]) init(v);
    }
    order.push_back(u);
}
 
void rdfs(int u){
    dd[u] = 1;
    for (int v : gr[u]){
        if (!dd[v]){
            rdfs(v);
        }
    }
    comp.push_back(u);
}
 
void dfs(int u){
    dd[u] = 1;
    for (int v : adj[u]){
        if (!dd[v]){
            dfs(v);
        }
        a[u] |= a[v];
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        u -= 1; v -= 1;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
 
    for (int i = 0; i < n; ++ i){
        if (!dd[i]) init(i);
    }
 
    int cnt = -1;
 
    reverse(order.begin(), order.end());
    memset(dd, 0, sizeof(dd));
    for (int i : order){
        if (!dd[i]){
            cnt += 1;
            comp.clear();
            rdfs(i);
            for (int j : comp){
                cmp[j] = cnt;
            }
        }
    }
 
    memset(dd, 0, sizeof(dd));
    for (int i = 0; i < n; ++ i){
        for (int j : g[i]){
            if (cmp[i] != cmp[j]) adj[cmp[i]].push_back(cmp[j]);
        }
    }
 
    for (int i = 0; i <= cnt; ++ i) a[i].set(i);
 
    reverse(order.begin(), order.end());
    for (int i : order){
        if (!dd[cmp[i]]) dfs(cmp[i]);
    }
 
    while (q --){
        int u, v; cin >> u >> v;
        u -= 1; v -= 1;
        cout << (a[cmp[u]].test(cmp[v]) ? "YES\n" : "NO\n");
    }
}
/***
***/