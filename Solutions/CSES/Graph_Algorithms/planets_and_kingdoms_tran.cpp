#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, dd[O], res[O];
vector <int> g[O], gr[O], order, comp;
 
void init(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]) init(v);
    }
    order.push_back(u);
}
 
void rdfs(int u){
    dd[u] = 1;
    for (int v : gr[u]){
        if (!dd[v]){
            rdfs(v);
        }
    }
    comp.push_back(u);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++ i){
        if (!dd[i]) init(i);
    }
 
    reverse(order.begin(), order.end());
 
    int cnt = 0;
    memset(dd, 0, sizeof(dd));
    for (int i : order){
        if (!dd[i]){
            comp.clear();
            rdfs(i);
            cnt += 1;
 
            for (int j : comp) res[j] = cnt;
        }
    }
 
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++ i) cout << res[i] << " ";
}
/**
10
1 1 1 1 1 1 1 1 1 1
**/