#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 5e5 + 5;
const int inf = 1e9;
 
int n, m, d[O], trace[O];
vector <int> g[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++ i) d[i] = inf;
 
    d[1] = 0;
    deque <int> q; q.push_back(1);
 
    while (q.size()){
        int u = q.front();
        q.pop_front();
 
        for (int v : g[u]){
            if (d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                trace[v] = u;
                q.push_back(v);
            }
        }
    }
 
    if (d[n] >= inf) return cout << "IMPOSSIBLE", 0;
    cout << d[n] + 1 << "\n";
 
    vector <int> ans;
    for (int i = n; i != 0; i = trace[i]) ans.push_back(i);
 
    while (ans.size()){
        cout << ans.back() << " ";
        ans.pop_back();
    }
 
}
/**
7 6
1 2 1
2 3 2
3 4 3
4 5 3
5 6 2
6 7 1
**/