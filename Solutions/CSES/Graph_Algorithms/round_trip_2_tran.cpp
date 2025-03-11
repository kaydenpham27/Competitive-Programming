#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, m, h[O], dd[O], par[O];
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
            par[v] = u;
            h[v] = h[u] + 1;
        }
        else{
            cout << h[u] - h[v] + 2 << "\n";
            int p = u;
            vector <int> res;
            while (p != v){
                res.push_back(p);
                p = par[p];
            }
            res.push_back(v);
            res.push_back(u);
 
            reverse(res.begin(), res.end());
 
            for (int i : res) cout << i << " ";
            exit(0);
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
 
    for (int i = 1; i <= n; ++ i)
        if (!dd[i]) init(i);
 
    reverse(order.begin(), order.end());
 
    memset(dd, 0, sizeof(dd));
 
    for (int i : order){
        if (!dd[i]) dfs(i);
    }
 
    cout << "IMPOSSIBLE";
 
 
}