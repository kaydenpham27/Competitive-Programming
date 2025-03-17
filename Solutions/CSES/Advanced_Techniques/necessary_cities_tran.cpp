#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, Time, d[O], dd[O], tin[O], low[O], E[O], U[O];
vector <int> g[O];
 
void dfs(int u, int par = 0){
    dd[u] = 1;
    tin[u] = low[u] = ++ Time;
 
    int dem = 0;
    for (int i : g[u]){
        int v = u ^ E[i];
        if (v == par) continue;
        if (dd[v]){
            low[u] = min(low[u], tin[v]);
        }
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            dem += 1;
            if (low[v] >= tin[u] && u != 1) d[u] = 1;
        }
    }
 
    if (u == 1) d[u] = (dem > 1);
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
    for (int i = 1; i <= n; ++ i){
        if (d[i]) res.push_back(i);
        //cout << "check vcl " << i << " : " << low[i] << " " << tin[i] << endl;
    }
 
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
}
/**
7 8
1 2
1 3
1 4
3 5
3 6
5 6
6 7
1 5
**/