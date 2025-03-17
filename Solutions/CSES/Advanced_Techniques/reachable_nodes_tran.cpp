#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
 
using namespace std;
 
const int O = 5e4 + 1;
const int inf = 1e9;
 
int n, m;
bool dd[O];
bitset <O> a[O];
vector <int> g[O], order;
 
void init(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]) init(v);
    }
    order.push_back(u);
}
 
void dfs(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]){
            dfs(v);
        }
        a[u] |= a[v];
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        u -= 1; v -= 1;
        g[u].push_back(v);
    }
 
    for (int i = 0; i < n; ++ i){
        if (!dd[i]) init(i);
        a[i].set(i);
    }
 
    memset(dd, 0, sizeof(dd));
    for (int i : order){
        if (!dd[i]) dfs(i);
    }
 
    for (int i = 0; i < n; ++ i){
        cout << a[i].count() << " ";
    }
}
/***
***/