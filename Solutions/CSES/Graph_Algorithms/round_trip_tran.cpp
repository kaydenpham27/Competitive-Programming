#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, m, dd[O], par[O];
vector <int> g[O];
 
void dfs(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (v == par[u]) continue;
        if (dd[v]){
            vector <int> res;
            res.push_back(v);
            for (int i = u; i != v; i = par[i]) res.push_back(i);
            res.push_back(v);
            cout << res.size() << "\n";
            for (int i : res) cout << i << " ";
            exit(0);
        }
        else{
            par[v] = u;
            dfs(v);
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++ i){
        if (!dd[i]) dfs(i);
    }
 
    cout << "IMPOSSIBLE";
 
}