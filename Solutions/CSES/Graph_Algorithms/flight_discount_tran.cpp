#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e5 + 5;
const int inf = 1e18;
 
int n, m, d[2][O];
vector <pair <int, int>> g[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
        //g[v].push_back({u, c});
    }
 
    for (int i = 1; i <= n; ++ i) d[0][i] = d[1][i] = -inf;
 
    priority_queue <tuple <int, int, int>> q;
    q.push({0, 0, 1}); d[0][1] = 0;
 
    while (q.size()){
        auto [k, du, u] = q.top();
        q.pop();
 
        if (du != d[k][u]) continue;
 
        for (auto [v, c] : g[u]){
            if (k == 1){
                if (d[1][v] < du - c){
                    d[1][v] = du - c;
                    q.push(make_tuple(1, d[1][v], v));
                }
            }
            else{
                if (d[1][v] < du - c / 2){
                    d[1][v] = du - c / 2;
                    q.push(make_tuple(1, d[1][v], v));
                }
 
                if (d[0][v] < du - c){
                    d[0][v] = du - c;
                    q.push(make_tuple(0, d[0][v], v));
                }
            }
        }
    }
 
    cout << -d[1][n];
 
}
/**
**/