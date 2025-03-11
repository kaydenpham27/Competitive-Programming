#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
struct Edge {
    int a, b, cost;
};
 
int n, m;
vector<Edge> edges;
const int INF = 1e18;
 
void solve(){
    vector<int> d(n + 5);
    vector<int> p(n + 5, -1);
    int x;
    for (int i = 0; i < n; ++i){
        x = -1;
        for (Edge e : edges){
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = max(-INF, d[e.a] + e.cost);
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }
 
    if (x == -1){
        cout << "NO";
    }
    else{
        for (int i = 0; i < n; ++i)
            x = p[x];
 
        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
 
        cout << "YES\n";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v, c; cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
 
    solve();
}
/**
**/