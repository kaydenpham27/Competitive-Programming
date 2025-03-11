#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, child[O];
vector <int> g[O];
 
void dfs(int u, int par = 0){
    child[u] = 1;
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
            child[u] += child[v];
        }
    }
}
 
int Centroid(int u, int par = 0){
    for (int v : g[u]){
        if (v != par && child[v] * 2 >= n) return Centroid(v, u);
    }
    return u;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1);
    cout << Centroid(1);
}
/**
**/