#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, m, h[O], U[O], V[O], dd[O];
vector <int> g[O];
 
void dfs(int u, int p = 0){
    dd[u] = 1;
    //cout << u << endl;
    for (int i : g[u]){
        if (i != p){
            int v = u == U[i] ? V[i] : U[i];
            if (dd[v]){
                if (u == U[i] && h[u] > h[v]) swap(U[i], V[i]);
            }
            else{
                h[v] = h[u] + 1;
                dfs(v, i);
                if (u == V[i]) swap(U[i], V[i]);
            }
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        U[i] = u; V[i] = v;
        g[u].push_back(i);
        g[v].push_back(i);
    }
 
    for (int i = 1; i <= n; ++ i){
        if (!dd[i]) dfs(i);
    }
 
    for (int i = 1; i <= m; ++ i) cout << U[i] << " " << V[i] << "\n";
}
/**
**/