#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e5 + 5;
const int inf = 1e9;
 
int n, m, f[O], dd[O], trace[O];
vector <int> order, g[O];
 
void dfs(int u){
    dd[u] = 1;
    f[u] = (u == n);
 
    int Max = 0;
    for (int v : g[u]){
        if (!dd[v]){
            dfs(v);
        }
        Max = (f[v] > f[Max]) ? v : Max;
 
        if (f[u] < f[Max] + (f[Max] > 0)){
            f[u] = f[Max] + (f[Max] > 0);
            trace[u] = Max;
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
 
    dfs(1);
 
    if (!f[1]) return cout << "IMPOSSIBLE", 0;
 
    cout << f[1] << "\n";
 
    for (int i = 1; i; i = trace[i]) cout << i << " ";
}
/**
**/