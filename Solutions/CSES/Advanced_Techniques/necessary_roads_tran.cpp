#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, Time, d[O], dd[O], tin[O], low[O], E[O], U[O];
vector <int> g[O];
 
void dfs(int u, int par = 0){
    dd[u] = 1;
    tin[u] = low[u] = ++ Time;
    for (int i : g[u]){
        int v = u ^ E[i];
        if (v == par) continue;
        if (dd[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
 
        if (low[v] > tin[u]) d[i] = 1;
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        U[i] = u; E[i] = u ^ v;
        g[u].push_back(i);
        g[v].push_back(i);
    }
 
    dfs(1);
 
    vector <int> res;
    for (int i = 1; i <= m; ++ i){
        if (d[i]) res.push_back(i);
    }
 
    cout << res.size() << "\n";
    for (int i : res){
        cout << U[i] << " " << (E[i] ^ U[i]) << "\n";
    }
}
/**
**/