#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e5 + 5;
const int inf = 1e18;
 
int n, m, d[O];
vector <pair <int, int>> g[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
    }
 
    for (int i = 1; i <= n; ++ i) d[i] = -inf;
 
    priority_queue <pair <int, int>> q;
    q.push({0, 1}); d[1] = 0;
 
    while (q.size()){
        auto [du, u] = q.top();
        q.pop();
 
        if (du != d[u]) continue;
 
        for (auto [v, c] : g[u]){
            if (d[v] < du - c){
                d[v] = du - c;
                q.push({d[v], v});
            }
        }
    }
 
    for (int i = 1; i <= n; ++ i) cout << -d[i] << " ";
 
}
/**
**/