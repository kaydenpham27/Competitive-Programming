#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
bool flag = false;
int n, m, h[O], U[O], V[O], dd[O];
vector <int> g[O], gr[O], adj[O], order;
 
void dfs(int u, int p = 0){
    dd[u] = 1;
    //cout << u << endl;
    for (int i : g[u]){
        if (i != p){
            int v = u == U[i] ? V[i] : U[i];
            if (dd[v]){
                if (u == V[i] && h[u] > h[v]) swap(U[i], V[i]);
            }
            else{
                h[v] = h[u] + 1;
                dfs(v, i);
                if (u == V[i]) swap(U[i], V[i]);
            }
        }
    }
}
 
void test(int u){
    dd[u] = 1;
    for (int v : adj[u]){
        if (!dd[v]) test(v);
        else{
            if (v == 1) flag = true;
        }
    }
    order.push_back(u);
}
 
void test2(int u){
    dd[u] = 1;
    for (int v : gr[u]){
        if (!dd[v]) test2(v);
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
 
    for (int i = 1; i <= m; ++ i){
        adj[U[i]].push_back(V[i]);
        gr[V[i]].push_back(U[i]);
        //cout << U[i] << " " << V[i] << "\n";
    }
 
    memset(dd, 0, sizeof(dd)); test(1);
    memset(dd, 0, sizeof(dd)); test2(order.back());
 
    int x = accumulate(dd + 1, dd + n + 1, 0);
    if (x != n || !flag) return cout << "IMPOSSIBLE", 0;
 
    for (int i = 1; i <= m; ++ i) cout << U[i] << " " << V[i] << "\n";
}
/**
**/