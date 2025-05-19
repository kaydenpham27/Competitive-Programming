#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e5 + 50;
 
int n, m, in[O], out[O];
vector <int> g[O], path;
 
void dfs(int u){
    while (g[u].size()){
        int v = g[u].back();
        g[u].pop_back();
        dfs(v);
    }
    path.push_back(u);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        in[v] += 1;
        out[u] += 1;
    }
 
    for (int i = 2; i < n; ++ i){
        if (in[i] != out[i]) return cout << "IMPOSSIBLE", 0;
    }
 
    if (in[1] + 1 != out[1] || in[n] != out[n] + 1) return cout << "IMPOSSIBLE", 0;
 
    dfs(1);
 
    reverse(path.begin(), path.end());
    if (path.back() != n || path.size() != m + 1) return cout << "IMPOSSIBLE", 0;
 
    for (int i : path) cout << i << " ";
}