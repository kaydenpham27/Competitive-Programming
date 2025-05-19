#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 1e5 + 5;
const int mod = 1e9 + 7;
 
int n, m, f[O], dd[O], trace[O];
vector <int> order, g[O];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
}
 
void dfs(int u){
    f[u] = (u == 1);
    dd[u] = 1;
 
    int Max = 0;
    for (int v : g[u]){
        if (!dd[v]){
            dfs(v);
        }
        Add(f[u], f[v]);
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[v].push_back(u);
    }
 
    dfs(n);
 
    cout << f[n];
}
/**
**/