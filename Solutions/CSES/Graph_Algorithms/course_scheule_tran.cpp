#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
const int inf = 1e9;
 
vector <int> gr[O];
int n, m, comp, dd[O];
vector <int> order, g[O];
 
void init(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]) init(v);
    }
    order.push_back(u);
}
 
void dfs(int u){
    dd[u] = 1;
    comp += 1;
 
    for (int v : gr[u]){
        if (!dd[v]) dfs(v);
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        if (u == v) return cout << "IMPOSSIBLE", 0;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
 
    order.clear();
    for (int i = 1; i <= n; ++ i){
        if (!dd[i]) init(i);
    }
 
    reverse(order.begin(), order.end());
 
    memset(dd, 0, sizeof(dd));
 
    for (int i : order){
        if (!dd[i]){
            comp = 0;
            dfs(i);
 
            if (comp > 1) return cout << "IMPOSSIBLE", 0;
        }
    }
 
    for (int i : order) cout << i << " ";
}
/**
**/